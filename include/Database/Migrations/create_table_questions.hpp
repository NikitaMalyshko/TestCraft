#pragma once

#include <brazier/DB>

using namespace brazier;

class createTableQuestions : public BaseMigration<createTableQuestions> {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("questions");
		std::vector<std::string> queries;

		queries.push_back(builder
			.AddColumn("id SERIAL PRIMARY KEY")
			.AddColumn("text VARCHAR(255) NULL")
			.AddColumn("type ENUM NOT NULL")
			.AddColumn("priority INTEGER NOT NULL")
			.AddForeignKey("test_id", "tests", "id")
			.CreateTable());

		return queries;
	}

	static std::string down() {
		SQLSchemaBuilder builder("questions");
		return builder.DropTable();
	}
};