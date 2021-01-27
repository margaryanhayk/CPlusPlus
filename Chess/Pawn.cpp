#include <iostream>
#include "Pawn.h"
#include "Deck.h"

Pawn::Pawn() {
	get_view();
}

Pawn::Pawn(std::string color) {
	set_color(color);
	get_view();
}

char Pawn::get_view() {
	if (get_color() == "white") {
		return 'P';
	}
	else {
		return 'p';
	}
}

bool Pawn::can_do_such_movement(std::vector<int> command, Figure*** arr) {
	if (this->get_color() == "white") {
		if ((command[1] == command[3]) && (command[0] - command[2] == 1)) {
			return(arr[command[2]][command[3]] == NULL);
		}
		if ((command[1] == command[3]) && (command[0] ==6) && (command[0] - command[2] == 2)) {
			return((arr[command[0]-1][command[1]] == NULL) && (arr[command[0]-2][command[1]] == NULL)) ;
		}
		if (((command[0] - command[2]) == 1) && ((command[1] - command[3]) == 1) && arr[command[2]][command[3]] != NULL) {
			return(arr[command[2]][command[3]]->get_color() != "white");
		}
		if (((command[0] - command[2]) == 1) && ((command[3] - command[1]) == 1) && arr[command[2]][command[3]] != NULL) {
			return(arr[command[2]][command[3]]->get_color() != "white");
		}
	}
	else {
		if ((command[1] == command[3]) && (command[2] - command[0] == 1)) {
			return(arr[command[2]][command[3]] == NULL);
		}
		if ((command[1] == command[3]) && (command[0] == 1) && (command[2] - command[0] == 2)) {
			return((arr[command[0] + 1][command[1]] == NULL) && (arr[command[0] + 2][command[1]] == NULL));
		}
		if (((command[2] - command[0]) == 1) && ((command[3] - command[2]) == 1) && arr[command[2]][command[3]] != NULL) {
			return(arr[command[2]][command[3]]->get_color() == "white");
		}
		if (((command[2] - command[0]) == 1) && ((command[1] - command[3]) == 1) && arr[command[2]][command[3]] != NULL) {
			return(arr[command[2]][command[3]]->get_color() == "white");
		}
	}
	return 0;
}