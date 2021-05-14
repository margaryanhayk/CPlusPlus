#include "Read.h"

Read::Read(const std::vector<std::string>& vec_to_analyze) {}

void Read::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if (check_if_valid_input(vec_to_analyze)) {
		if (check_if_entity_exist(vec_to_analyze)) {
			std::string line;
			std::ifstream myFile(vec_to_analyze[2] + ".txt");
			if (check_if_valid_where_clause(vec_to_analyze)) {
				if (myFile.is_open()) {
					bool checker = false;
					int line_index = 0;
					std::vector<int> indexes;
					while (std::getline(myFile, line)) {
						std::vector<std::string> get_line = stringToVector(line);
						if (check_if_have_some_parameter(vec_to_analyze, get_line)) {
							if (vec_to_analyze[5] == get_line[1]) {
								indexes.push_back(line_index);
								checker = true;
							}
						}
						++line_index;
					}
					if (checker) {
						if (indexes.size() != 0) {
							int length = get_length_of_lines(vec_to_analyze[2]);
							for (auto i : indexes) {
								get_correct_lines(vec_to_analyze[2], length, i );
							}
							return;
						}
						else {
							std::cout << "For "<< vec_to_analyze[4] << " parameter can't find " << vec_to_analyze[5] << " value" <<std::endl;
							return;
						}
					}
					else {
						std::cout << "For " << vec_to_analyze[2] << " entitiy, not declared " << vec_to_analyze[4] << " parameter " <<std::endl;
						return;
					}
					return;
				}
				else {
					std::cout << vec_to_analyze[2] << " entity does not exist!>" << std::endl;
				}
			}
			else {
				if (myFile.is_open()){
					while (std::getline(myFile, line)){
						std::cout << line << std::endl;
					}
				}
				else {
					std::cout << vec_to_analyze[2] << " entity does not exist!!!>" << std::endl;
				}
			}
		}
		else {
			std::cout << vec_to_analyze[2] << " entity does not exist!>" << std::endl;
			return;
		}
	}
	else {
		std::cout << "Please use this syntax : <read entity: Example ...>" << std::endl;
		std::cout << "<read entity: Example> "  << "OR "<< "<read entity: Example where param: xyz>"<<std::endl;
		return;
	}
}

bool Read::check_if_valid_input(const std::vector<std::string>& vec_to_analyze) {
	if (vec_to_analyze.size() == 1) {
		return false;
	}
	return (vec_to_analyze[1] == get_entity_command());
}

bool Read::check_if_have_some_parameter(const std::vector<std::string>& vec_to_analyze, const std::vector<std::string>& get_line) {
	return (vec_to_analyze[4] == get_line[0]);
}

void Read::get_correct_lines(std::string entity, int length, int index) {
	std::string line;
	std::ifstream myFile(entity + ".txt");
	int rest = index / length;
	int unnesesary = rest * length;
	if (myFile.is_open()) {	
		while (std::getline(myFile, line)) {
			if (unnesesary > 0) {
				--unnesesary;
			}
			else if (length > 0) {
					std::cout << line << std::endl;
					--length;
			}
		}
	}
	else {
		std::cout << " entity does not exist!!!>" << std::endl;
		return ;
	}
}


