#include "ConnectedComponents.h"
#include "UnionFind.h"
#include <vector>

using namespace std;
ConnectedComponents::ConnectedComponents() {}

ConnectedComponents::ConnectedComponents(int n)
{
	openSites = 0;
	size = n * n;
	side = n;

	// initializes the grid. Can change later.
	
	for (int i = 0; i < n; i++) {
		std::vector<int> input;
		for (int j = 0; j < n; j++){
			input.push_back(0);
		}
		grid.push_back(input);
	}


}


ConnectedComponents::~ConnectedComponents()
{
}

// Uncovers tile of it hasn't been uncovered already
void ConnectedComponents::uncover(int row, int col)
{
	if (isUncovered(row, col)) return;
	openSites++;


	// Checks on all sides of the square to perform a union with adjacent squares
	// Deals with edge cases as well
	int positioner = -1;
	while (positioner != 1) {
		if (col + positioner > 0 && col + positioner <= side && isUncovered(row, col + positioner)) {
			finder.unionF(((row - 1) * side + col + positioner - 1), (row - 1) * side + col - 1);
		}
		if (row + positioner > 0 && row + positioner <= side && isUncovered(row + positioner, col)) {
			finder.unionF((row - 1) * side + positioner * side + col - 1, (row - 1) * side + col - 1);
		}
		positioner += 2;
	}
	grid[col-1][row-1] = 1;
}
bool ConnectedComponents::isUncovered(int row, int col)
{
	return grid[col - 1][row - 1] == 1 || grid[col - 1][row - 1] == 2 || grid[col - 1][row - 1] == 3 || grid[col - 1][row - 1] == 4 || grid[col - 1][row - 1] == 5;
}
// Returns true if position has bomb
bool ConnectedComponents::hasBomb(int row, int col)
{
	return grid[col - 1][row - 1] == -1;
}

void ConnectedComponents::addBomb(int row, int col) {
	grid[col - 1][row - 1] = -1;
}

void ConnectedComponents::setThreatLevel(int row, int col, int level) {
	grid[col - 1][row - 1] = level;
}


// Returs number of uncovered sites
int ConnectedComponents::numberOfUncoveredSites()
{
	return openSites;
}