#pragma once
#include <iostream>
#include "Figure.h"
#include <vector>
#include "Deck.h"

class Pawn : public Figure
{
public:
	Pawn();
	Pawn(std::string color);
	char get_view() override;
	bool can_do_such_movement(std::vector<int> command, Figure*** arr) override;

};


