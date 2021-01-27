#pragma once
#include <iostream>
#include "Deck.h"
#include <vector>

class DiagonalyMoveable {
public:
	bool is_diagonal(std::vector<int> command, Figure*** arr);
};