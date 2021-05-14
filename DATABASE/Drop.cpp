#include "Drop.h"

Drop::Drop(const std::vector<std::string>& vec_to_analyze) {}

void Drop::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if (vec_to_analyze.size() == 3) {
		if (vec_to_analyze[1] == get_entity_command()) {
			if (check_if_entity_exist(vec_to_analyze)) {
				std::string name = vec_to_analyze[2] + ".txt";
				if (remove(name.c_str()) == 0) {
					std::cout << vec_to_analyze[2] << " suceesfully deleted!" << std::endl;
					return;
				}
				else{
					std::cout << " something went wrong!!!" << std::endl;
					return;
				}
			}
			else {
				std::cout << vec_to_analyze[2] <<" entity does not exist!" << std::endl;
				return;
			}
		}
		else {
			std::cout << "Your input for drop command is invalid, please us <drop entity: person> .." << std::endl;
			return;
		}
	}
	else {
		std::cout << "Your input for drop command is invalid, please us <drop entity: person> .." << std::endl;
		return;
	}
}

