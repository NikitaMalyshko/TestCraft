#include <brazier/DB>

using namespace brazier

class Answer : public Model<Answer> {
public:
    Answer() = default;
    Answer(const std::shared_ptr<Database>& db) : Model<Answer>(db) {}

    static inline std::string table_name = "answers";
    static inline std::vector<std::string> fillable = {
        "test", "is_correct", "question_id"
    };
    static inline std::vector<std::string> fields = {
        "id", "test_id", "is_correct_id", "question_id"
    };
    static inline std::string primary_key = "id";

    std::map<std::string, std::string> attributes;
};
