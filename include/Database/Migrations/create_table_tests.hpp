#pragma once

#include <brazier/DB>

using namespace brazier;

class createTableTests : public BaseMigration<createTableTests> {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("tests");
		std::vector<std::string> queries;

		queries.push_back(builder
			.AddColumn("id_test SERIAL PRIMARY KEY")
			.AddColumn("name VARCHAR(255) NOT NULL")
			.AddColumn("description TEXT NULL")
			.CreateTable());

		return queries;
	}

	static std::string down() {
		SQLSchemaBuilder builder("tests");
		return builder.DropTable();
	}
};