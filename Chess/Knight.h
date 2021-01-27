#pragma once
#include<iostream>
#include "Figure.h"

class Knight : public Figure
{
public:
	Knight();
	Knight(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr) override;
};

