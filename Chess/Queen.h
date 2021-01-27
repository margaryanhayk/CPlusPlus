#pragma once
#include<iostream>
#include "Figure.h"
#include "StraightMoveable.h"
#include "DiagonallyMoveable.h"

class Queen : public Figure, public StraightMoveable, public DiagonalyMoveable
{
public:
	Queen();
	Queen(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr);
}; 
