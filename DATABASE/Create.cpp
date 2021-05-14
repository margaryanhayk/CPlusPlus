#include "Create.h"

Create::Create(const std::vector<std::string>& vec_to_analyze) {}

bool Create::check_if_valid_input(const std::vector<std::string>& vec_to_analyze) {
	if (vec_to_analyze.size() == 1) {
		return false;
	}
	return ((vec_to_analyze[1] == get_entity_command()) && (vec_to_analyze.size() != 2));
}

void Create::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if (check_if_valid_input(vec_to_analyze)) {
		if (check_if_entity_exist(vec_to_analyze)) {
			std::cout << "Entity with name " << vec_to_analyze[2] << " is alreadey created!" << std::endl;
			return;
		}
		else {
			const std::string file_name = vec_to_analyze[2] + ".txt";
			std::ofstream outfile(file_name);
			if (vec_to_analyze.size() == 3) {
				outfile.close();
				std::cout << "Succesfully created!>" << std::endl;
			}
			else {
				outfile << get_separator() << std::endl;
				for (int i = 3; i < vec_to_analyze.size(); ++i) {
					if (vec_to_analyze[i][vec_to_analyze[i].length() - 1] == ':') {
						outfile << vec_to_analyze[i] << " ";
					}
					else {
						outfile << vec_to_analyze[i] << " " << std::endl;
					}
				}
				std::cout << "Succesfully created!>" << std::endl;
				outfile.close();
			}

		}
	}
	else {
		std::cout << "Please use this syntax <create entity: Example ...>" << std::endl;
		return;
	}
}

