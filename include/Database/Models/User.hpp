#include <brazier/DB>

using namespace brazier

class User : public Model<User> {
public:
    User() = default;
    User(const std::shared_ptr<Database>& db) : Model<User>(db) {}

    static inline std::string table_name = "tests";
    static inline std::vector<std::string> fillable = {
        "cached_data_id", "report_id", "pattern_name", "time", "confidence"
    };
    static inline std::vector<std::string> fields = {
        "id", "cached_data_id", "report_id", "pattern_name", "time", "confidence", "created_at"
    };
    static inline std::string primary_key = "id";

    std::map<std::string, std::string> attributes;
};
