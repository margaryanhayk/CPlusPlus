#pragma once
#include<iostream>
#include "StraightMoveable.h"

class Rock : public Figure, public StraightMoveable
{
public:
	Rock();
	Rock(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr) override;
};
