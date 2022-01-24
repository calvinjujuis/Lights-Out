#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

Grid::Grid() { 
    td = nullptr; 
}

Grid::~Grid() { delete td; }

void Grid::clearGrid() {
    for (auto cells : theGrid) {
        cells.clear();
    }
    theGrid.clear();
}

void Grid::determineWin() {
    bool winstate = true;
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            if (theGrid[row][col].getState() == true) {
                winstate = false;
            }
        }
    }
    won = winstate;
}

bool Grid::isWon() const {
    return won;
}

void Grid::init(int n) {
    clearGrid();
    gridSize = n;
    for (int row = 0; row < n; ++row) {
        vector<Cell> oneRow;
        theGrid.push_back(oneRow);
        for (int col = 0; col < n; ++col) {
            Cell oneCell;
            oneCell.setCoords(row, col);
            theGrid[row].push_back(oneCell); // put new cell into grid
        }
    }
    // set up Text Display
    delete td;
    td = new TextDisplay{n};
    // set up new cell's neighbours
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            // find and sort neighbours
            vector<pair<int, int>> neighbours = findNeighbours(row, col);
            // attach valid neighbours to cell
            for (auto nbr : neighbours) {
                if ((nbr.first >= 0 && nbr.first <= n - 1) && 
                    (nbr.second >= 0 && nbr.second <= n - 1)) {
                    theGrid[row][col].attach(&theGrid[nbr.first][nbr.second]);
                }
            }
            // attach td (text display)
            theGrid[row][col].attach(td);
        }
    }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);
  determineWin();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::All);
  determineWin();
}

vector<pair<int, int>> Grid::findNeighbours(int row, int col) {
    vector<pair<int, int>> nbrs;
    nbrs.push_back(make_pair(row - 1, col));
    nbrs.push_back(make_pair(row, col - 1));
    nbrs.push_back(make_pair(row, col + 1));
    nbrs.push_back(make_pair(row + 1, col));
    int len = nbrs.size();
    // using bubble sort
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmpCoord(nbrs[j], nbrs[j+1])) {
                nbrs[j].swap(nbrs[j+1]);
            }
        }
    }
    return nbrs;
}

bool Grid::cmpCoord(pair<int, int> coord1, pair<int, int> coord2) {
    string str1 = to_string(coord1.first) + to_string(coord1.second);
    string str2 = to_string(coord2.first) + to_string(coord2.second);
    return str1 > str2;
}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *g.td;
    return out;
}

void Grid::printCells() const {
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            cout << theGrid[row][col].getName() << ": " << theGrid[row][col].getObserverNames() << endl;
        }
    }
}