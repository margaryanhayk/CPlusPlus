#include <iostream>
#include "DiagonallyMoveable.h"

bool DiagonalyMoveable::is_diagonal(std::vector<int> command, Figure*** arr) {
	if (abs(command[0] - command[2]) == abs(command[1] - command[3]) != 0) {
		int delta = abs(command[0] - command[2]);
		if (delta == 1) {
			if ((arr[command[2]][command[3]] == NULL)) {
				return 1;
			}
			else if ((arr[command[0]][command[1]]->get_color()) != (arr[command[2]][command[3]]->get_color())) {
				return 1;
			}
			else {
				return 0;
			}
		}
		if ((command[0] > command[2]) && (command[1] > command[3])) {
			for (int i = 1; i < delta; ++i) {
				if (arr[command[0] - i][command[1] - i] != NULL) {
					return 0;
				}
			}
			return 1;
		}
		if ((command[0] > command[2]) && (command[1] < command[3])) {
			for (int i = 1; i < delta; ++i) {
				if (arr[command[0] - i][command[1] + i] != NULL) {
					return 0;
				}
			}
			return 1;
		}
		if ((command[0] < command[2]) && (command[1] < command[3])) {
			for (int i = 1; i < delta; ++i) {
				if (arr[command[0] + i][command[1] + i] != NULL) {
					return 0;
		 		}
			}
			return 1;
		}
		if ((command[0] < command[2]) && (command[1] > command[3])) {
			for (int i = 1; i < delta; ++i) {
				if (arr[command[0] + i][command[1] - i] != NULL) {
					return 0;
				}
			}
			return 1;
		}
		/// <summary>
		/// /
		/// </summary>
		/// <param name="command"></param>
		/// <param name="arr"></param>
		/// <returns></returns>
		if (arr[command[2]][command[3]] != NULL) {
			if ((arr[command[0]][command[1]]->get_color()) != (arr[command[2]][command[3]]->get_color())) {
				return 1;
			}
			else {
				return 0;
			}
		}

	}
	else {
		return 0;
	}
}