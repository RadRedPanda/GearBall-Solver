#pragma once
#include "Gearball.h"
#include <iostream>

class AStar
{
public:
	AStar();
	~AStar();
	void setRoot(Gearball root);
	void insert(Gearball add);
	std::vector<int> solve();
	std::vector<Gearball> getFringe();
private:
	std::vector<Gearball> fringe;
	Gearball first;
};

