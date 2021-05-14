#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>
#include "DatabaseCommands.h"

class Read : public DatabaseCommands {
public:
	Read(const std::vector<std::string>& );
	void implement_command(const std::vector<std::string>& );
	bool check_if_valid_input(const std::vector<std::string>& );
	bool check_if_have_some_parameter(const std::vector<std::string>&, const std::vector<std::string>&);
	void get_correct_lines(std::string entity, int, int);
};
