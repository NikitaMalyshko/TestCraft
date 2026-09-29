#pragma once

#include <brazier/DB>

using namespace brazier;

class createTableTagTests :: public BaseMigration(createTableTagTests) {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("tagtests");
		std::vector<std::string> queries;

		queries.push_back(builder .AddColumn);
	}
}