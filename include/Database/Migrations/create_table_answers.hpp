#pragma once

#include <brazier/DB>

using namespace brazier;

class createTableAnswers : public BaseMigration<createTableAnswers> {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("answers");
		std::vector<std::string> queries;

		queries.push_back(builder
			.AddColumn("id SERIAL PRIMARY KEY")
			.AddForeignKey("question_id", "tests", "id")
			.AddColumn("question_id")
			.AddColumn("text VARCHAR(255) NOT NULL")
			.AddColumn("is_correct BOOLEAN NOT NULL")
			.CreateTable());

		return queries;
	}

	static std::string down() {
		SQLSchemaBuilder builder("answers");
		return builder.DropTable();
	}
};