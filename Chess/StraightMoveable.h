#pragma once
#include <iostream>
#include "Deck.h"
#include <vector>

class StraightMoveable {
public:
	bool is_straight(std::vector<int> command, Figure*** arr);
};