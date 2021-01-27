#pragma once
#include<vector>
class Figure
{
private:
	std::string _color;
public:
	virtual  ~Figure() = default;
	virtual char get_view() = 0;
	std::string get_color();
	void set_color(std::string color);
	virtual bool can_do_such_movement(std::vector<int> command, Figure*** arr) = 0;
};


