#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>
#include "DatabaseCommands.h"

///		delete {example : delete entity: person where age: 18}

class Delete : public DatabaseCommands {
public:
	Delete(const std::vector<std::string>& );
	void implement_command(const std::vector<std::string>& );
	int get_command_length();
	std::vector<int>  check_if_parameter_and_value_exist(const std::vector<std::string>&);
	void delete_parameter_and_etc(const std::vector<std::string>& );
private:
	const int correct_command_size = 6;
};
