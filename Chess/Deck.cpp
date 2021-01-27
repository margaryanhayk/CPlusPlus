#include <iostream>
#include <string>
#include "Figure.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Deck.h"
#include "Deck.h"
#include <vector>

Deck::~Deck() {}

void Deck::draw_board() {
	for (int i = 0; i < 8; ++i) {
		std::cout << 8 - i << "|";
		for (int j = 0; j < 8; ++j) {
			if (arr[i][j] != nullptr) {
				std::cout << " " << arr[i][j]->get_view() << " ";
			}
			else {
				std::cout << " " << '.' << " ";
			}
		}
		std::cout << "" << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
}

Deck::Deck() {
	for (int ix = 0; ix < 8; ++ix) {
		arr[ix] = new Figure * [8];
	}
	arr[0][0] = new Rock;
	arr[0][1] = new Knight;
	arr[0][2] = new Bishop;
	arr[0][3] = new Queen;
	arr[0][4] = new King();
	arr[0][5] = new Bishop;
	arr[0][6] = new Knight;
	arr[0][7] = new Rock;
	arr[7][0] = new Rock("white");
	arr[7][1] = new Knight("white");
	arr[7][2] = new Bishop("white");
	arr[7][3] = new Queen("white");
	arr[7][4] = new King("white");
	arr[7][5] = new Bishop("white");
	arr[7][6] = new Knight("white");
	arr[7][7] = new Rock("white");
	for (int i = 0; i < 8; ++i) {
		arr[1][i] = new Pawn;
		arr[6][i] = new Pawn("white");
	}
	for (int i = 2; i < 6; ++i) {
		for (int ix = 0; ix < 8; ++ix) {
			arr[i][ix] = nullptr;
		}
	}
	draw_board();
}

std::vector<int> Deck::get_correct_King_coordes(bool priority) {
	std::vector<int> king_coordes;
	//white section
	if (priority == 1) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (const auto current = (arr[i][j])) {
					if (current->get_view() == 'K') {
						king_coordes.push_back(i);
						king_coordes.push_back(j);
						return king_coordes;
					}
				}
			}
		}
	}
	//black section
	else {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (const auto current = (arr[i][j])) {
					if (current->get_view() == 'k') {
						king_coordes.push_back(i);
						king_coordes.push_back(j);
						return king_coordes;
					}
				}
			}
		}
	}
}

std::vector<std::string> Deck:: from_str_to_vec(std::string str) {
	std::vector<std::string> command_words;
	while (str.find(' ') != std::string::npos) {
		std::string str1;
		for (int ix = 0; ix < str.find(' '); ++ix) {
			str1 += str[ix];
		}
		command_words.push_back(str1);
		std::string str2;
		for (int ix = str.find(' ') + 1; ix < str.size(); ++ix) {
			str2 += str[ix];
		}
		str = str2;
	}
	command_words.push_back(str);
	return command_words;
}

bool Deck:: syntax_check(std::vector<std::string> command) {
	if ((command.size() != 3) || (command[0] != "move")) {
		return 0;
	}
	if ((command[1].size() != 2) || (command[2].size() != 2)) {
		return 0;
	}
	if ((command[1][0] > 104) || (command[1][0] < 97)) {
		return 0;
	}
	if ((command[2][0] > 104) || (command[2][0] < 97)) {
		return 0;
	}
	if ((command[1][1] > 56) || (command[1][1] < 49)) {
		return 0;
	}
	if ((command[2][1] > 56) || (command[2][1] < 49)) {
		return 0;
	}
	return 1;
}

std::vector<int>Deck:: get_valid_coordinates(std::vector<std::string> command) {
	std::vector<int> two_coordes;
	two_coordes.push_back(-int(command[1][1]) + 56);
	two_coordes.push_back(int(command[1][0] - 49 - 48));
	two_coordes.push_back(-int(command[2][1]) + 56);
	two_coordes.push_back(int(command[2][0] - 49 - 48));
	return two_coordes;
}

bool Deck::get_priority() {
	return _priority;
}

void Deck::set_priority(bool setter) {
	_priority = setter;
}

bool Deck::is_deck_empty(std::vector<int> two_coordes) {
	if ( arr [two_coordes[0]][two_coordes[1]] == NULL) {
		return 1;
	}
	else { return 0; }
}

bool Deck::priority_check(std::vector<int> two_coordes) {
	if (arr[two_coordes[0]][two_coordes[1]] != NULL) {
		if (arr[two_coordes[0]][two_coordes[1]]->get_color() == "white")
		{
			if (get_priority()) {
				return 1;
			}
			else { return 0; }
		}
		else if (!get_priority()) {
			return 1;
		}
	}
	return 0;
}

bool Deck::is_there_figure_can_eat_crossing(bool check_alligned_with_priority) {
	/// <summary>
	/// If check_alligned_with_priority is '1', it means you want to check check your self...
	/// </summary>
	/// <param name="check_alligned_with_priority"></param>
	/// <returns></returns>
	std::vector<int> commandos;
	if (!check_alligned_with_priority) {
		commandos = get_correct_King_coordes(!get_priority());
	}
	else {
		commandos = get_correct_King_coordes(get_priority());
	}
	int x = commandos[0];
	int y = commandos[1];
	int result = 0;
	if ((x - 2 > 0) && (y + 1 < 8) && arr[x - 2][y + 1] != NULL && (arr[x - 2][y + 1]->get_view() == 'n' || arr[x - 2][y + 1]->get_view() == 'N') && arr[x - 2][y + 1]->get_color() != arr[x][y]->get_color()) {
		++result;
		check_from.push_back(x - 2);
		check_from.push_back(y + 1);
	}
	if ((x - 2 > 0) && (y - 1 > 0) && arr[x - 2][y - 1] != NULL && (arr[x - 2][y - 1]->get_view() == 'n' || arr[x - 2][y - 1]->get_view() == 'N') && arr[x - 2][y - 1]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x - 2);
		check_from.push_back(y - 1);
	}
	if ((x + 1 < 8) && (y + 2 < 8) && arr[x + 1][y + 2] != NULL && (arr[x + 1][y + 2]->get_view() == 'n' || arr[x + 1][y + 2]->get_view() == 'N') && arr[x + 1][y + 2]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x + 1);
		check_from.push_back(y + 2);
	}
	if ((x + 1 < 8) && (y - 2 > 0) && arr[x + 1][y - 2] != NULL && (arr[x + 1][y - 2]->get_view() == 'n' || arr[x + 1][y - 2]->get_view() == 'N') && arr[x + 1][y - 2]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x + 1);
		check_from.push_back(y - 2);
	}
	if ((x - 1 > 0) && (y + 2 < 8) && arr[x - 1][y + 2] != NULL && (arr[x - 1][y + 2]->get_view() == 'n' || arr[x - 1][y + 2]->get_view() == 'N') && arr[x - 1][y + 2]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x - 1);
		check_from.push_back(y + 2);
	}
	if ((x - 1 > 0) && (y - 2 > 0) && arr[x - 1][y - 2] != NULL && (arr[x - 1][y - 2]->get_view() == 'n' || arr[x - 1][y - 2]->get_view() == 'N') && arr[x - 1][y - 2]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x - 1);
		check_from.push_back(y - 2);
	}
	if ((x + 2 < 8) && (y - 1 > 0) && arr[x + 2][y - 1] != NULL && (arr[x + 2][y - 1]->get_view() == 'n' || arr[x + 2][y - 1]->get_view() == 'N') && arr[x + 2][y - 1]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x + 2);
		check_from.push_back(y - 1);
	}
	if ((x + 2 < 8) && (y + 1 < 8) && arr[x + 2][y + 1] != NULL && (arr[x + 2][y + 1]->get_view() == 'n' || arr[x + 2][y + 1]->get_view() == 'N') && arr[x + 2][y + 1]->get_color() != arr[x][y]->get_color()) { 
		++result;
		check_from.push_back(x + 2);
		check_from.push_back(y + 1);
	}
	return result;
}

bool Deck::is_there_figure_can_eat_straight(bool check_alligned_with_priority) {
	std::vector<int> commandos;
	if (!check_alligned_with_priority) {
		commandos = get_correct_King_coordes(!get_priority());
	}
	else {
		commandos = get_correct_King_coordes(get_priority());
	}
	int x = commandos[0];
	int y = commandos[1];
	int result = 0;
	
	for (int i = x+1; i < 8; ++i) {
		if (arr[i][y] != NULL) {
			if (arr[i][y]->get_color() == arr[x][y]->get_color()) {
				break;
			}
			else if ((arr[i][y]->get_view() == 'r') || (arr[i][y]->get_view() == 'R') || (arr[i][y]->get_view() == 'Q') || (arr[i][y]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(y);
			}
		}
	}
	for (int i = x - 1; i >= 0; --i) {
		if (arr[i][y] != NULL) {
			if (arr[i][y]->get_color() == arr[x][y]->get_color()) {
				break;
			}
			else if ((arr[i][y]->get_view() == 'r') || (arr[i][y]->get_view() == 'R') || (arr[i][y]->get_view() == 'Q') || (arr[i][y]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(y);
			}
		}
	}
	for (int i = y + 1; i < 8; ++i) {
		if (arr[x][i] != NULL) {
			if (arr[x][i]->get_color() == arr[x][y]->get_color()) {
				break;
			}
			else if ((arr[x][i]->get_view() == 'r') || (arr[x][i]->get_view() == 'R') || (arr[x][i]->get_view() == 'Q') || (arr[x][i]->get_view() == 'q')) {
				++result;
				check_from.push_back(x);
				check_from.push_back(i);
			}
		}
	}
	for (int i = y - 1; i >= 0; --i) {
		if (arr[x][i] != NULL) {
			if (arr[x][i]->get_color() == arr[x][y]->get_color()) {
				break;
			}
			else if ((arr[x][i]->get_view() == 'r') || (arr[x][i]->get_view() == 'R') || (arr[x][i]->get_view() == 'Q') || (arr[x][i]->get_view() == 'q')) {
				++result;
				check_from.push_back(x);
				check_from.push_back(i);
			}
		}
	}
	return result;
}

bool Deck::is_there_figure_can_eat_diagonally(bool check_alligned_with_priority) {
	std::vector<int> commandos;
	if (!check_alligned_with_priority) {
		commandos = get_correct_King_coordes(!get_priority());
	}
	else {
		commandos = get_correct_King_coordes(get_priority());
	}
	int x = commandos[0];
	int y = commandos[1];	
	int result = 0;

	for (int i = x + 1, j = y + 1; (i < 8 && j < 8); ++i, ++j) {
		if (arr[i][j] != NULL) {
			if (arr[x][y]->get_color() == arr[i][j]->get_color()) {
				break;
			}
			else if ((arr[i][j]->get_view() == 'B') || (arr[i][j]->get_view() == 'b') || (arr[i][j]->get_view() == 'Q') || (arr[i][j]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(j);
			}
		}
	}
	for (int i = x - 1, j = y - 1; (i >= 0  && j >= 0); --i, --j) {////////
		if (arr[i][j] != NULL) {
			if (arr[x][y]->get_color() == arr[i][j]->get_color()) {
				break;
			}
			else if ((arr[i][j]->get_view() == 'B') || (arr[i][j]->get_view() == 'b') || (arr[i][j]->get_view() == 'Q') || (arr[i][j]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(j);
			}
		}
	}
	for (int i = x - 1, j = y + 1; (i >= 0 && j < 8); --i, ++j) {////////
		if (arr[i][j] != NULL) {
			if (arr[x][y]->get_color() == arr[i][j]->get_color()) {
				break;
			}
			else if ((arr[i][j]->get_view() == 'B') || (arr[i][j]->get_view() == 'b') || (arr[i][j]->get_view() == 'Q') || (arr[i][j]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(j);
			}
		}
	}
	for (int i = x + 1, j = y - 1; (i < 8 && j >= 0); ++i, --j) {////////
		if (arr[i][j] != NULL) {
			if (arr[x][y]->get_color() == arr[i][j]->get_color()) {
				break;
			}
			else if ((arr[i][j]->get_view() == 'B') || (arr[i][j]->get_view() == 'b') || (arr[i][j]->get_view() == 'Q') || (arr[i][j]->get_view() == 'q')) {
				++result;
				check_from.push_back(i);
				check_from.push_back(j);
			}
		}
	}
	return result;
}

bool Deck::is_there_pawn_can_eat(bool check_alligned_with_priority) {
	std::vector<int> commandos;
	if (!check_alligned_with_priority) {
		commandos = get_correct_King_coordes(!get_priority());
	}
	else {
		commandos = get_correct_King_coordes(get_priority());
	}
	int result = 0;
	int x = commandos[0];
	int y = commandos[1];
	if (arr[x][y]->get_color() == "white") {
		if ((x == 0) || (x==1)) {
			return 0;
		}
		else if (y == 0  && arr[x - 1][y + 1]!=NULL) {
			if (arr[x - 1][y + 1]->get_view() == 'p') {
				++result;
				check_from.push_back(x - 1);
				check_from.push_back(y + 1);
			}
		}
		else if (y == 7 && arr[x - 1][y - 1] != NULL) {
			if (arr[x - 1][y - 1]->get_view() == 'p') {
				++result;
				check_from.push_back(x - 1);
				check_from.push_back(y - 1);
			}
		}
		else if(arr[x - 1][y - 1] != NULL) {
			if (arr[x - 1][y - 1]->get_view() == 'p') {
				++result;
				check_from.push_back(x - 1);
				check_from.push_back(y - 1);
			}
		}
		else if (arr[x - 1][y + 1] != NULL) {
			if (arr[x - 1][y + 1]->get_view() == 'p') {
				++result;
				check_from.push_back(x - 1);
				check_from.push_back(y + 1);
			}
		}
	}
	else {
		if ((x == 6) || (x == 7)) {
			return 0;
		}
		else if (y == 0 && arr[x + 1][y + 1] != NULL) {
			if (arr[x + 1][y + 1]->get_view() == 'P') {
				++result;
				check_from.push_back(x + 1);
				check_from.push_back(y + 1);
			}
		}
		else if (y == 7 && arr[x + 1][y - 1] != NULL) {
			if (arr[x + 1][y - 1]->get_view() == 'P') {
				++result;
				check_from.push_back(x + 1);
				check_from.push_back(y - 1);
			}
		}
		else if (arr[x + 1][y - 1] != NULL) {
			if (arr[x + 1][y - 1]->get_view() == 'P') {
				++result;
				check_from.push_back(x + 1);
				check_from.push_back(y - 1);
			}
		}
		else if (arr[x + 1][y + 1] != NULL) {
			if (arr[x + 1][y + 1]->get_view() == 'P') {
				++result;
				check_from.push_back(x + 1);
				check_from.push_back(y + 1);
			}
		}
	}
	return result;
}

bool Deck::is_check_for(bool color) {
	    is_there_figure_can_eat_crossing(color);
		is_there_figure_can_eat_straight(color);
		is_there_figure_can_eat_diagonally(color);
		is_there_pawn_can_eat(color);

	if (is_there_figure_can_eat_crossing(color) ||
		is_there_figure_can_eat_straight(color) ||
		is_there_figure_can_eat_diagonally(color) ||
		is_there_pawn_can_eat(color)) {
		return 1;
	}
	else{
		return 0;
	}
}

bool Deck::check_if_mate_after_all_possible_movements_for_king(){
	std::vector<int> commandos = get_correct_King_coordes(get_priority());
	int x = commandos[0];
	int y = commandos[1];
	if ((x + 1 < 8) && (y + 1 < 8) && arr[x + 1][y + 1] != NULL && arr[x + 1][y + 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x+1][y+1];
		arr[x + 1][y + 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x+1][y+1] == temp2;
			delete temp1;
			delete temp2;
		}
	}
	if ((x + 1 < 8)  && arr[x + 1][y] != NULL && arr[x + 1][y]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x + 1][y];
		arr[x + 1][y] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x + 1][y] == temp2;
			delete temp1;
			delete temp2;
		}
	}	
	if ((x + 1 < 8) && (y - 1 >=0) && arr[x + 1][y - 1] != NULL && arr[x + 1][y - 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x + 1][y - 1];
		arr[x + 1][y - 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x + 1][y - 1] == temp2;
			delete temp1;
			delete temp2;
		}
	}	
	if ((y + 1 < 8) && arr[x][y + 1] != NULL && arr[x][y + 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x][y + 1];
		arr[x][y + 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x][y + 1] == temp2;
			delete temp1;
			delete temp2;
		}
	}	
	if ((y - 1 > 0) && arr[x][y - 1] != NULL && arr[x][y - 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x][y - 1];
		arr[x][y - 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x][y - 1] == temp2;
			delete temp1;
			delete temp2;
		}
	}	
	if ((x -1 >=0) && (y + 1 < 8) && arr[x - 1][y + 1] != NULL && arr[x - 1][y + 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x - 1][y + 1];
		arr[x - 1][y + 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x - 1][y + 1] == temp2;
			delete temp1;
			delete temp2;
		}
	}	
	if ((x - 1 >= 0) && arr[x - 1][y] != NULL && arr[x - 1][y]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x - 1][y];
		arr[x - 1][y] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x - 1][y] == temp2;
			delete temp1;
			delete temp2;
		}
	}
	if ((x - 1 >= 0) && arr[x - 1][y - 1] != NULL && arr[x - 1][y - 1]->get_color() != arr[x][y]->get_color()) {
		Figure* temp1 = arr[x][y];
		Figure* temp2 = arr[x - 1][y -1];
		arr[x - 1][y - 1] = arr[x][y];
		arr[x][y] = NULL;
		if (!is_check_for(1)) {
			return 0;
		}
		else {
			arr[x][y] == temp1;
			arr[x - 1][y - 1] == temp2;
			delete temp1;
			delete temp2;
		}
	}
	return 1;
}

std::vector<std::vector<int>> Deck::all_possible_positions_for_protecting_king() {

	std::vector<std::vector<int>> all_variants;
	std::vector<int> commandos = get_correct_King_coordes(!get_priority());
	int x1 = commandos[0];
	int y1 = commandos[1];
	int x2 = check_from[0];
	int y2 = check_from[1];
	//diagonally
	if (abs(x1 - x2) == abs(y1 - y2)) {
		if ((x1 < x2) && (y1 < y2)) {
			for (int i = x1 + 1, j = y1 + 1; i <= x2; ++i, ++j) {
				std::vector<int> variant;
				variant.push_back(i);
				variant.push_back(j);
				all_variants.push_back(variant);
			}

		}
		if ((x1 < x2) && (y1 > y2)) {
			for (int i = x1 + 1, j = y1 - 1; i <= x2; ++i, --j) {
				std::vector<int> variant;
				variant.push_back(i);
				variant.push_back(j);
				all_variants.push_back(variant);
			}

		}
		if ((x1 > x2) && (y1 < y2)) {
			for (int i = x1 - 1, j = y1 + 1; i >= x2; --i, ++j) {
				std::vector<int> variant;
				variant.push_back(i);
				variant.push_back(j);
				all_variants.push_back(variant);
			}

		}
		if ((x1 > x2) && (y1 > y2)) {
			for (int i = x1 - 1, j = y1 - 1; i >= x2; --i, --j) {
				std::vector<int> variant;
				variant.push_back(i);
				variant.push_back(j);
				all_variants.push_back(variant);
			}

		}

		//straightly
		if ((x1 == x2) && (y1 != y2)) {
			if (y1 > y2) {
				for (int i = y1 - 1; i >= 2; --i) {
					std::vector<int> variant;
					variant.push_back(x1);
					variant.push_back(i);
					all_variants.push_back(variant);
				}
			}
			if (y1 < y2) {
				for (int i = y1 + 1; i <= y2; ++i) {
					std::vector<int> variant;
					variant.push_back(x1);
					variant.push_back(i);
					all_variants.push_back(variant);
				}
			}
		}
		if ((x1 != x2) && (y1 == y2)) {
			if (x1 > x2) {
				for (int i = x1 - 1; i >= x2; --i) {
					std::vector<int> variant;
					variant.push_back(i);
					variant.push_back(y1);
					all_variants.push_back(variant);
				}
			}
			if (x1 < x2) {
				for (int i = x1 + 1; i <= x2; ++i) {
					std::vector<int> variant;
					variant.push_back(i);
					variant.push_back(y1);
					all_variants.push_back(variant);
				}
			}
		}
		return all_variants;
	}
}

bool Deck::check_if_mate_after_all_possible_movements_for_other_figures() {
 
	std::vector<std::vector<int>> all_protected_places = all_possible_positions_for_protecting_king();	
	int size = all_protected_places.size();
	std::vector<int> commandos;
	commandos = get_correct_King_coordes(!get_priority());
	int x = commandos[0];
	int y = commandos[1];
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (!((x == i) && (y == j))) {
				if ((arr[i][j] != NULL) && (arr[i][j]->get_color() == arr[x][y]->get_color())) {
					for (int k = 0; k < size; ++k) {
						std::vector<int> tmp;
						tmp.push_back(i);
						tmp.push_back(j);
						tmp.push_back(all_protected_places[k][0]);
						tmp.push_back(all_protected_places[k][1]);
						if (arr[i][j]->can_do_such_movement(tmp, arr)) {
							return 0;
						}

					}
				}
			}
		
		}
	}
	return 1;
}

void Deck::deleting_arr_members() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
}

void Deck::play() {
	while (1) {
		std::string line;
		getline(std::cin, line);
		std::vector<std::string> parsed_string = from_str_to_vec(line);
		if (!syntax_check(parsed_string)) {
			std::cout << "Please type correct command  (Ex move a2 a4...)" << std::endl;
			continue;
		}
		std::vector<int> vec_line = get_valid_coordinates(parsed_string);
		if (is_deck_empty(vec_line)) {
			std::cout << "First coordinate is empty" << std::endl;
			continue;
		}
		if (!priority_check(vec_line)) {
			std::cout << "False collor..." << std::endl;
			continue;
		}
		if (!arr[vec_line[0]][vec_line[1]]->can_do_such_movement(vec_line, arr)) {
			std::cout << "False movement" << std::endl;
			continue;
		}
		Figure* temp1 = arr[vec_line[0]][vec_line[1]];
		Figure* temp2 = arr[vec_line[2]][vec_line[3]];
		arr[vec_line[2]][vec_line[3]] = arr[vec_line[0]][vec_line[1]];
		arr[vec_line[0]][vec_line[1]] = NULL;
// Check if after such movement you are in check or not..
		if (is_check_for(1)) {
			if (get_priority()) {
				std::cout << "White is under check! Please do another move" << std::endl;
			}
			else {
				std::cout << "Black is under check! Please do another move" << std::endl;
			}
			arr[vec_line[2]][vec_line[3]] = temp2;
			arr[vec_line[0]][vec_line[1]] = temp1;
			continue;
		}
/// Check if after such movement opposite team is mate or not..
		if (is_check_for(0)) {	
			if (check_if_mate_after_all_possible_movements_for_king() && check_if_mate_after_all_possible_movements_for_other_figures()) {
				if (get_priority()) {
						std::cout << "Mate for black" << std::endl;
				}
				else {
					std::cout << "Mate for white" << std::endl;
				}
				draw_board();
				deleting_arr_members();
				return;
			}
		}
		set_priority(!get_priority());
		draw_board();
		for (int i : check_from) {
			check_from.pop_back();
		}
	}
}