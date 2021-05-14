#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <string>
#include "DatabaseCommands.h"

class Drop : public DatabaseCommands {
public:
	Drop(const std::vector<std::string>& vec_to_analyze);
	void implement_command(const std::vector<std::string>& vec_to_analyze);
};
