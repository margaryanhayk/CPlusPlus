#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>
#include "DatabaseCommands.h"
///		update {example : update entity: person from age: 19 to 32}

class Update : public DatabaseCommands {
public:
	Update(const std::vector<std::string>& );
	void implement_command(const std::vector<std::string>& );
	std::string get_from_clause();
	std::string get_to_clause();
	int get_command_length();
	int get_index_from();
	int get_index_to();
	bool check_if_parameter_exist(const std::vector<std::string>&);
private:
	const std::string FROM_CLAUSE = "from";
	const std::string TO_CLAUSE = "to";
	const int correct_command_size = 8;
	const int index_from = 3;
	const int index_to = 6;
};
