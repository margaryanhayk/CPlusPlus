#include "Insert.h"

Insert::Insert(const std::vector<std::string>& vec_to_analyze) {}

void Insert::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if (check_if_valid_input(vec_to_analyze)) {
		if (check_if_entity_exist(vec_to_analyze)) {
			int length = get_length_of_lines(vec_to_analyze[2]) -1 ;
			if (length == -1) {
				std::string line;
				std::fstream outFile;
				outFile.open(vec_to_analyze[2] + ".txt", std::ios::app);
				outFile << get_separator() << std::endl;
				for (int i = 3; i < vec_to_analyze.size(); ++i) {
					if (vec_to_analyze[i][vec_to_analyze[i].length() - 1] == ':') {
						outFile << vec_to_analyze[i] << " ";
					}
					else {
						outFile << vec_to_analyze[i] << " " << std::endl;
					}
				}
				std::cout << "Succesfully inserted!>" << std::endl;
				outFile.close();
			}
			else if (length == ((vec_to_analyze.size()-3)/2)) {
				std::string line;
				std::fstream outFile;
				outFile.open(vec_to_analyze[2] + ".txt", std::ios::app);
				outFile << get_separator() << std::endl;
				for (int i = 3; i < vec_to_analyze.size(); ++i) {
					if (vec_to_analyze[i][vec_to_analyze[i].length() - 1] == ':') {
						outFile << vec_to_analyze[i] << " ";
					}
					else {
						outFile << vec_to_analyze[i] << " " << std::endl;
					}
				}
				std::cout << "Succesfully inserted!>" << std::endl;
				outFile.close();
			}
			else {
				std::cout << " Your input must contain " << length << " parameter "<<std::endl;
				return;
			}
		}
		else {
			std::cout << vec_to_analyze[2] << " entity does not exist!" << std::endl;
			return;
		}
	}
	else {
		std::cout << vec_to_analyze[2] << " entity does not exist!>" << std::endl;
		return;
	}
}

bool Insert::check_if_valid_input(const std::vector<std::string>& vec_to_analyze) {
	if (vec_to_analyze.size() == 1) {
		return false;
	}
	return (vec_to_analyze[1] == get_entity_command());
}

int Insert::get_length_of_lines(const std::string& entity) {
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
