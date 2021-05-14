#pragma once
#include "DatabaseCommands.h"
#include "Create.h"
#include "Read.h"
#include "Update.h"
#include "Delete.h"
#include "Insert.h"
#include "Drop.h"

 DatabaseCommands::~DatabaseCommands(){}

 std::string DatabaseCommands::get_separator() {
	 return SEPARATOR;
 }

 std::string DatabaseCommands::get_entity_command() {
	 return ENTITY_COMMAND;
 }

 std::string DatabaseCommands::get_where_clause() {
	 return WHERE_CLAUSE;
 }

 bool DatabaseCommands::check_if_valid_where_clause(const std::vector<std::string>& vec_to_analyze) {
	 if (vec_to_analyze.size() == 6) {
		 return (vec_to_analyze[3] == get_where_clause());
	 }
	 return false;
 }

 bool DatabaseCommands::check_if_entity_exist(const std::vector<std::string>& vec_to_analyze) {
	 const std::string entity_name = vec_to_analyze[2] + ".txt";
	 std::ifstream myFile(entity_name);
	 return (myFile.is_open());
 }

void DatabaseCommands::run_database() {
	std::cout << " create {example : create entity: person age: 19 name: ani id: 112ds  .....}" << std::endl;
	std::cout<< " read {example: read entity : person , OR read entity : person where age : 18 }" << std::endl;
	std::cout << " update {example: update entity : person from age : 19 to 32 }" << std::endl;
	std::cout << " delete {example: delete entity : person where age : 18}" << std::endl;
	std::cout << " insert {example: insert entity : person age : 22 }" << std::endl;
	std::cout << " drop {example: drop entity : person }" << std::endl;
	std::cout << " exit -- for closing cmd" << std::endl;

	std::string command;
	while (command != EXIT_COMMAND) {
		std::getline(std::cin, command);
		std::vector<std::string> vec_to_analyze = stringToVector(command);
		if(command != EXIT_COMMAND && (first_analyze(vec_to_analyze) == 0)){
			std::cout << "Your command is not available !" << std::endl;
		}
	}
}

std::vector<std::string> DatabaseCommands::stringToVector(std::string& line) {
	std::vector<std::string> vec;
	const std::string divide_by = " ";
	int pos = 0;
	std::string token;
	while ((pos = line.find(divide_by)) != std::string::npos) {
		token = line.substr(0, pos);
		vec.push_back(token);
		line.erase(0, pos + divide_by.length());
	}
	vec.push_back(line);
	return vec;
}

bool DatabaseCommands::first_analyze(const std::vector<std::string>& vec_to_analyze) {
	DatabaseCommands* obj;
	if (vec_to_analyze[0] == CREATE_COMMAND) {
		obj = new Create(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else if (vec_to_analyze[0] == READ_COMMAND) {
		obj = new Read(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else if (vec_to_analyze[0] == UPDATE_COMMAND) {
		obj = new Update(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else if (vec_to_analyze[0] == DELETE_COMMAND) {
		obj = new Delete(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else if (vec_to_analyze[0] == INSERT_COMMAND) {
		obj = new Insert(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else if (vec_to_analyze[0] == DROP_COMMAND) {
		obj = new Drop(vec_to_analyze);
		obj->implement_command(vec_to_analyze);
		delete obj;
		return true;
	}
	else {
		return false;
	}
}

void DatabaseCommands::implement_command(const std::vector<std::string>& vec_to_analyze) {
	std::cout << "If you see this, then something went wrong!" << std::endl;
}

int DatabaseCommands::get_length_of_lines(const std::string& entity) {
	std::string line;
	std::ifstream myFile(entity + ".txt");
	int count = 0;
	bool found_one = false;
	if (myFile.is_open()) {
		while (std::getline(myFile, line)) {
			if ((line == get_separator()) && (found_one == 1)) {
				break;
			}
			else if ((line == get_separator()) && (found_one == 0)) {
				found_one = true;
				++count;
			}
			else {
				++count;
			}
		}
		return count;
	}
	else {
		std::cout << " entity does not exist!!!>" << std::endl;
		return 0;
	}
}

