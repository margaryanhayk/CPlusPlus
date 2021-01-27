#include <iostream>
#include "StraightMoveable.h"

bool StraightMoveable::is_straight(std::vector<int> command, Figure*** arr) {
	if (((command[0] - command[2]) == 0) && (command[1] - command[3]) != 0) {
		int delta = command[1] - command[3];
		if (abs(delta) == 1) {
			if (arr[command[2]][command[3]] == NULL) { return 1; }
			if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1; }
			return 0;
		}
		if (delta > 0) {
			for (int ix = 1; ix < delta; ++ix) {
				if (arr[command[0]][command[1] - ix] != NULL) { return 0; }
			}
		}
		if (delta < 0) {
			for (int ix = 1; ix < abs(delta); ++ix) {
				if (arr[command[0]][command[1] + ix] != NULL) { return 0; }
			}
		}
		if (arr[command[2]][command[3]] == NULL) {
			return 1;
		}
		else if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1; }
	}
	if (((command[0] - command[2]) != 0) && (command[1] - command[3]) == 0) {
		int delta = command[0] - command[2];
		if (abs(delta) == 1) {
			if (arr[command[2]][command[3]] == NULL) { return 1; }
			if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1; }
			return 0;
		}
		if (delta > 0) {
			for (int ix = 1; ix < delta; ++ix) {
				if (arr[command[0] - ix][command[1]] != NULL) { return 0; }
			}
		}
		if (delta < 0) {
			for (int ix = 1; ix < abs(delta); ++ix) {
				if (arr[command[0] + ix][command[1]] != NULL) { return 0; }
			}
		}
		if (arr[command[2]][command[3]] == NULL) {
			return 1;
		}
		else if (arr[command[2]][command[3]]->get_color() != arr[command[0]][command[1]]->get_color()) { return 1; }
	}
	return 0;
}
