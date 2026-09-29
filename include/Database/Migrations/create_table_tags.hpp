#pragma once

#include <brazier/DB>

using namespace brazier;

class createTableTags :: public BaseMigration(createTableTags) {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("tags");
		std::vector<std::string> queries;

		queries.push_back(builder
			.AddColumn("id SERIAL PRIMARY KEY"))
			.AddColumn("")
			.AddColumn("")
			.CreateTable());

		return queries;
	}

	static std::string down() {
		SQLSchemaBuilder builder 
	}

}