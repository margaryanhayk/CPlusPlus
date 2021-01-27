#pragma once
#include <iostream>
#include "Figure.h"
#include "DiagonallyMoveable.h"


class Bishop : public Figure, public DiagonalyMoveable
{
public:
	Bishop();
	Bishop(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr) override;
};



