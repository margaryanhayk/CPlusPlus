#include <iostream>
#include "Figure.h"
#include "Queen.h"
#include "Rock.h"
#include "Bishop.h"


Queen::Queen() {
	get_view();
}
Queen::Queen(std::string color) {
	set_color(color);
	get_view();
}
char Queen::get_view() {
	if (get_color() == "white") {
		return 'Q';
	}
	else {
		return 'q';
	}
}
bool Queen::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	return(is_straight(command, arr) || is_diagonal(command, arr));
}

