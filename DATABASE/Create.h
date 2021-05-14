#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>
#include "DatabaseCommands.h"

class Create : public DatabaseCommands {
public:
	Create(const std::vector<std::string>& vec_to_analyze);
	void implement_command(const std::vector<std::string>& vec_to_analyze);
	bool check_if_valid_input(const std::vector<std::string>& vec_to_analyze);
private:
	const std::string WHERE_CLAUSE = "where";
};
