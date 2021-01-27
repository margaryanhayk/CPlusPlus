#pragma once
#include<iostream>
#include "Figure.h"
#include "vector"

class Deck {
public:
	Deck();
	~Deck();
	std::vector<int> check_from;
	Figure*** arr = new Figure * *[8];
	void draw_board();
	bool get_priority();
	void set_priority(bool priority);
	std::vector<int> get_correct_King_coordes(bool priority);
	std::vector<std::string> from_str_to_vec(std::string str);
	bool syntax_check(std::vector<std::string> command);
	std::vector<int> get_valid_coordinates(std::vector<std::string> command);
	bool is_deck_empty(std::vector<int> two_coordes);
	bool priority_check(std::vector<int> two_coordes);
	bool is_there_figure_can_eat_crossing(bool check_alligned_with_priority);
	bool is_there_figure_can_eat_straight(bool check_alligned_with_priority);
	bool is_there_figure_can_eat_diagonally(bool check_alligned_with_priority);
	bool is_there_pawn_can_eat(bool check_alligned_with_priority);
	bool is_check_for(bool color);
	bool check_if_mate_after_all_possible_movements_for_king();
	bool check_if_mate_after_all_possible_movements_for_other_figures();
	std::vector<std::vector<int>> all_possible_positions_for_protecting_king();
	void deleting_arr_members();
	void play();
private:
	bool _priority = 1;
};