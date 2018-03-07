#include "AStar.h"

AStar::AStar(){

}

AStar::~AStar(){
}

// Resets the algorithm to the selected Gearball

void AStar::setRoot(Gearball root) {
	fringe.clear();
	first = root;
	fringe.push_back(root);
}

// Places the Gearball into the fringe and then does one iteration of bubble sort to sort it.

void AStar::insert(Gearball add) {
	fringe.push_back(add);
	for (int i = fringe.size() - 1; i > 0; i -= 1) {
		if (fringe[i-1].getF() < fringe[i].getF() || fringe[i-1].getDepth() < fringe[i].getDepth()) {
			Gearball temp = fringe[i - 1];
			fringe[i - 1] = fringe[i];
			fringe[i] = temp;
		}
		else {
			break;
		}
	}
}

std::vector<int> AStar::solve() {
	std::vector<int> path;
	std::vector<Gearball> oldBalls;
	std::cout << "solving..." << std::endl;
	while (!fringe.empty()) {
		if (fringe.back().getHeuristic() == 0) {	// solved state
			path = fringe.back().getMoves();
			std::cout << fringe.size() << std::endl;
			break;
		}
		oldBalls.push_back(fringe.back());
		fringe.pop_back();												// removes the lowest f() gearball
		std::vector<Gearball> options = oldBalls.back().getOptions();	// makes more Gearballs from it
		for (int i = 0; i < options.size(); i += 1)
			insert(options[i]);											// places them in the fringe
	}
	std::cout << "Solved" << std::endl;
	for (int i = 0; i < path.size(); i += 1) {
		switch (path[i]) {
		case 0:
			std::cout << "Front clockwise" << std::endl;
			break;
		case 1:
			std::cout << "Top clockwise" << std::endl;
			break;
		case 2:
			std::cout << "Right clockwise" << std::endl;
			break;
		case 3:
			std::cout << "Front counter-clockwise" << std::endl;
			break;
		case 4:
			std::cout << "Top counter-clockwise" << std::endl;
			break;
		case 5:
			std::cout << "Right counter-clockwise" << std::endl;
			break;
		}
		std::cout << "Yellow or Purple is Front" << std::endl << "Red or Orange is Top" << std::endl << "Blue or Green is Right" << std::endl;
	}
	return path;
}

std::vector<Gearball> AStar::getFringe() {
	return fringe;
}