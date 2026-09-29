#include <brazier/DB>

using namespace brazier

class Tag : public Model<Tag> {
public:
    Tag() = default;
    Tag(const std::shared_ptr<Database>& db) : Model<Tag>(db) {}

    static inline std::string table_name = "tests";
    static inline std::vector<std::string> fillable = {
        "name", "description"
    };
    static inline std::vector<std::string> fields = {
        "id", "name_id", "description_id"
    };
    static inline std::string primary_key = "id";

    std::map<std::string, std::string> attributes;
};
