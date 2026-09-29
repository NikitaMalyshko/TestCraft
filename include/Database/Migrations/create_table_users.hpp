#pragma once

#include <brazier/DB>;

using namespace brazier;

class createTableUsers : public BaseMigration<createTableUsers> {
public:
	static std::vector<std::string> up() {
		SQLSchemaBuilder builder("users");
		std::vector<std::string> queries;

		queries.push_back(builder)
	}
}