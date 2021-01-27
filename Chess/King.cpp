#include <iostream>
#include "Figure.h"
#include "King.h"



King::King() {
	get_view();
}

King::King(std::string color) {
	set_color(color);
	get_view();
}

char King::get_view() {
	return get_color() == "white" ? 'K' : 'k';
}

bool King::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	bool is_valid_condition = (arr[command[2]][command[3]] == NULL) || (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color());
	if ((abs(command[0] - command[2]) == 1) && (command[1] == command[3])) {
		return is_valid_condition;
	}
	else if ((abs(command[1] - command[3]) == 1) && (command[0] == command[2])) {
		return is_valid_condition;
	}
	else if ((abs(command[1] - command[3]) == 1) && (abs(command[0] - command[2]) == 1)) {
		return is_valid_condition;
	}
	else { 
		return false;
	}

}

//std::vector<std::vector<int>> King::all_possible_movements_for_figure(bool color) {
	
//}



