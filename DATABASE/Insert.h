#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <istream>
#include <string>
#include "DatabaseCommands.h"

class Insert : public DatabaseCommands {
public:
	Insert(const std::vector<std::string>& vec_to_analyze);
	void implement_command(const std::vector<std::string>& vec_to_analyze);
	bool check_if_valid_input(const std::vector<std::string>& vec_to_analyze);
	int get_length_of_lines(const std::string& entity);
};
