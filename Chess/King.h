#pragma once
#include<iostream>
#include "Figure.h"

class King : public Figure
{
private:
public:
	King();
	King(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr) override;
	//std::vector<std::vector<int>> all_possible_movements_for_figure(bool color);
};

