#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>

/// <summary>
/// DatabaseCommands contains following commands:
///		create {example : create entity: person age: 19 name: ani id: 112ds  .....}
///		read   {example : read entity: person , OR read entity: person where age: 18}
///		update {example : update entity: person from age: 19 to 32}
///		delete {example : delete entity: person where age: 18}
///		insert {insert entity: person age: 22}
///		drop   {drop entity: person}
/// </summary>

class DatabaseCommands {
public:
	void run_database();
	virtual void implement_command(const std::vector<std::string>& );
	virtual ~DatabaseCommands ();
	std::vector<std::string> stringToVector(std::string&);
	std::string get_entity_command();
	std::string get_where_clause();
	std::string get_separator();
	bool check_if_entity_exist(const std::vector<std::string>&);
	bool check_if_valid_where_clause(const std::vector<std::string>&);
	bool first_analyze(const std::vector<std::string>&);
	int get_length_of_lines(const std::string&);
private:
	const std::string EXIT_COMMAND = "exit";
	const std::string CREATE_COMMAND = "create";
	const std::string READ_COMMAND = "read";
	const std::string UPDATE_COMMAND = "update";
	const std::string DELETE_COMMAND = "delete";
	const std::string INSERT_COMMAND = "insert";
	const std::string DROP_COMMAND = "drop";
	const std::string SEPARATOR = "----";
	const std::string ENTITY_COMMAND = "entity:";
	const std::string WHERE_CLAUSE = "where";
};
