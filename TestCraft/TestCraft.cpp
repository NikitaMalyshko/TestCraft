// TestCraft.cpp: определяет точку входа для приложения.
//

#include "TestCraft.h"
#include <brazier/DB>

using namespace brazier;

int main()
{
    try {
        Logger::log("Application recovery!");
        ConfigManager::initGlobal();
        Logger::log("Test #1");

        Logger::log("Test #2");
        std::string host = global_config->get("server.host", "127.0.0.1");
        Logger::log("Test #3");
        int port = global_config->get("server.port", 3501);
        Logger::log("Test #4");


        brazier::Server server(host, port);
        Logger::log("Test #5");
        server.initialize();

        Database db;
        auto manager = std::make_shared<MigrationManager>(db);

        manager->migrateAll<
            createTableTests, 
            createTableQuestions,
            createTableAnswers
        >();


        Logger::log("Test #6");
        server.run();

    }
    catch (std::exception e)
    {
        Logger::log(e.what());
    }

    return 0;
}
