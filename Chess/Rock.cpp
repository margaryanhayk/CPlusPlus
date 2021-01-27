#include <iostream>
#include "Figure.h"
#include "Rock.h"

Rock::Rock() {
	get_view();
}
Rock::Rock(std::string color) {
	set_color(color);
	get_view();
}
char Rock::get_view() {
	if (get_color() == "white") {
		return 'R';
	}
	else {
		return 'r';
	}
}
bool Rock::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	return is_straight(command, arr);
}

