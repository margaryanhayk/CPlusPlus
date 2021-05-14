#include "Delete.h"

///		delete {example : delete entity: person where age: 18}

Delete::Delete(const std::vector<std::string>& vec_to_analyze) {}

int Delete::get_command_length() {
	return correct_command_size;
}

std::vector<int> Delete::check_if_parameter_and_value_exist(const std::vector<std::string>& vec_to_analyze) {
	const std::string entity_name = vec_to_analyze[2] + ".txt";
	std::string line;
	std::ifstream myFile(entity_name);
	std::vector<int> return_value;
	if (myFile.is_open()) {
		int line_index = 0;
		while (std::getline(myFile, line)) {
			std::vector<std::string> tokens = stringToVector(line);
			if ((tokens[0] == vec_to_analyze[4]) && (tokens[1] == vec_to_analyze[5])) {
				return_value.push_back(line_index);
			}
			++line_index;
		}
		return return_value;
	}
	else {
		std::cout << " entity does not exist!!!>" << std::endl;
		return return_value;
	}
}

void Delete::delete_parameter_and_etc(const std::vector<std::string>& vec_to_analyze) {
	
	int count_of_lines = get_length_of_lines(vec_to_analyze[2]);
	auto indexes = check_if_parameter_and_value_exist(vec_to_analyze);
	std::vector<int> lines_do_be_deleted;
	for (int ix = 0; ix < indexes.size(); ++ix) {
		for (int i = 0; i < count_of_lines; ++i) {
			lines_do_be_deleted.push_back(((indexes[ix] / count_of_lines) * count_of_lines) + i);
		}
	}
	std::ifstream filein(vec_to_analyze[2] + ".txt");
	std::string temp_name = "temp.txt";
	std::ofstream fileout(temp_name);
	if (!filein || !fileout) {
		std::cout << "Something went wrong!!!" << std::endl;
		return;
	}
	std::string line;
	int line_index = 0;
	while (std::getline(filein, line))
	{
		bool checker = false;
		for (auto i : lines_do_be_deleted) {
			if (i == line_index) {
				checker = true;
			}
		}
		if (checker) {
			++line_index;
		}
		else {
			line += "\n";
			fileout << line;
			++line_index;
		}
	}
	fileout.close();
	filein.close();
	std::string name = vec_to_analyze[2] + ".txt";
	remove(name.c_str());
	std::string temporary_name = "temp.txt";
	rename(temporary_name.c_str(), name.c_str());
	remove(temp_name.c_str());
	std::cout << " Deleted!" << std::endl;
	return;
}

void Delete::implement_command(const std::vector<std::string>& vec_to_analyze) {
	if( (vec_to_analyze.size() == get_command_length())
		&& (vec_to_analyze[1] == get_entity_command())
		&& (check_if_entity_exist(vec_to_analyze))
		&& (check_if_valid_where_clause(vec_to_analyze))
		&& (check_if_parameter_and_value_exist(vec_to_analyze).size() != 0)) {
		delete_parameter_and_etc(vec_to_analyze);
	}
	else {
		std::cout << "Invalid command! Please use this : <delete entity: person where age: 18>" << std::endl;
		return;
	}

}
