#include <iostream>
#include "Figure.h"
#include "Knight.h"



Knight::Knight() {
	get_view();
}
Knight::Knight(std::string color) {
	set_color(color);
	get_view();
}
char Knight::get_view() {
	if (get_color() == "white") {
		return 'N';
	}
	else {
		return 'n';
	}
}
bool Knight::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	if ((abs((command[0]) - command[2]) == 2) && (abs((command[1]) - command[3]) == 1)) {
		if (arr[command[2]][command[3]] == NULL) { return 1; }
		if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1;}
		return 0;
	}
	if ((abs((command[0]) - command[2]) == 1) && (abs((command[1]) - command[3]) == 2)) {
		if (arr[command[2]][command[3]] == NULL) { return 1; }
		if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1; }
		return 0;
	}
	return 0;
}
