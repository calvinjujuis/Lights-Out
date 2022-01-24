#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
  for (int row = 0; row < gridSize; ++row) {
    vector<char> oneRow;
    theDisplay.push_back(oneRow);
    for (int col = 0; col < n; ++col) {
      char oneCell = '.';
      theDisplay[row].push_back(oneCell);
    }
  }
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

void TextDisplay::notify(Cell &whoNotified) {
  int row = whoNotified.getRow();
  int col = whoNotified.getCol();
  char & target = theDisplay[row][col];
  bool state = whoNotified.getState();
  if (state) {
    target = 'X';
  } else {
    target = '.';
  }
}

TextDisplay::~TextDisplay() {}

std::string TextDisplay::getName() const {
  string obsName = "TD";
  return obsName;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int row = 0; row < td.gridSize; ++row) {
    for (int col = 0; col < td.gridSize; ++col) {
      out << td.theDisplay[row][col];
    }
    out << endl;
  }
  return out;
}