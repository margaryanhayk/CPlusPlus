#include <iostream>
#include "Bishop.h"
#include "Figure.h"

Bishop::Bishop() {
	get_view();
}
Bishop::Bishop(std::string color) {
	set_color(color);
	get_view();
}
char Bishop::get_view() {
	if (get_color() == "white"){
		return 'B';
	}
	else {
		return 'b';
	}
}
bool Bishop::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	return is_diagonal(command, arr);
}