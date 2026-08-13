// TestCraft.cpp: определяет точку входа для приложения.
//

#include "TestCraft.h"

using namespace lightlib;

int main()
{
    Logger::log("Application recovery!");
    ConfigManager::initGlobal();

    std::string host = global_config->get("server.host", "127.0.0.1");
    int port = global_config->get("server.port", 3501);

    lightlib::Server server(host, port);
    server.initialize();
    server.run();

    return 0;
}
