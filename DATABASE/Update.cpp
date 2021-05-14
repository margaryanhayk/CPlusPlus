#include "Update.h"
#include <cstdio>

///		update {example : update entity: person from age: 19 to 32}

Update::Update(const std::vector<std::string>& vec_to_analyze) {}

std::string Update::get_from_clause() {
	return FROM_CLAUSE;
}

std::string Update::get_to_clause() {
	return TO_CLAUSE;
}

int Update::get_command_length() {
	return correct_command_size;
}

int Update::get_index_from() {
	return index_from;
}

int Update::get_index_to() {
	return index_to;
}

bool Update::check_if_parameter_exist(const std::vector<std::string>& vec_to_analyze) {
	const std::string entity_name = vec_to_analyze[2] + ".txt";
	std::string line;
	std::ifstream myFile(entity_name);
	if (myFile.is_open()) {
		while (std::getline(myFile, line)) {
			std::vector<std::string> tokens = stringToVector(line);
			if (tokens[0] == vec_to_analyze[4]) {
					return true;
			}
		}
		return false;
	}
	else {
		std::cout << " entity does not exist!!!>" << std::endl;
		return 0;
	}
}

void Update::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if (vec_to_analyze.size() == get_command_length() 
		&&  (vec_to_analyze[get_index_from()] == get_from_clause()) && (vec_to_analyze[get_index_to()] == get_to_clause()) 
		&&  (vec_to_analyze[1] == get_entity_command())) {
		if (check_if_entity_exist(vec_to_analyze)) {
			if (check_if_parameter_exist(vec_to_analyze)) {
				std::string strNew = vec_to_analyze[4] + " " +  vec_to_analyze[7];
				std::ifstream filein(vec_to_analyze[2] + ".txt"); 
				std::string temp_name = "temp.txt";
				std::ofstream fileout(temp_name);
				if (!filein || !fileout)
				{
					std::cout << "Something went wrong!!!" << std::endl;
					return;
				}
				std::string line;
				while (std::getline (filein, line))
				{
					std::string line_copy = line;
					auto line_vec = stringToVector(line_copy);
					if (    (line_vec.size() == 3)
						 && (line_vec[0] == vec_to_analyze[4])
					     && (line_vec[1] == vec_to_analyze[5]))
					{
						line = strNew;
					}
					line += "\n";
					fileout << line;
				}
				fileout.close();
				filein.close();
				std::string name = vec_to_analyze[2] + ".txt";
				remove(name.c_str());
				std::string temporary_name = "temp.txt";
				rename(temporary_name.c_str(), name.c_str());
				remove(temp_name.c_str());
				std::cout << " Updated!" << std::endl;
				return;
			}
			else {
				std::cout << vec_to_analyze[4] << " parameter is absent!" << std::endl;
				return;
			}
		}
		else {
			std::cout << vec_to_analyze[2] <<" entity is absent!" << std::endl;
			return;
		}
	}
	else {
		std::cout << "Not valid input for update command! EXAMPLE: update entity: person from age: 19 to 32 " << std::endl;
		return;
	}
}
