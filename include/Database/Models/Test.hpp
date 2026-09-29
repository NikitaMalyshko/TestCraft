#include <brazier/DB>

using namespace brazier

class Test : public Model<Test> {
public:
	Test() = default;
    Test(const std::shared_ptr<Database>& db) : Model<Test>(db) {}

    static inline std::string table_name = "tests";
    static inline std::vector<std::string> fillable = {
        "name", "description", "level", "time", "lower_score"
    };
    static inline std::vector<std::string> fields = {
        "id", "name_id", "description_id", "level_id", "time_id", "lower_score_id"
    };
    static inline std::string primary_key = "id";

    std::map<std::string, std::string> attributes;
};
