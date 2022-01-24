#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n);
      }
      else if (cmd == "init") {
        int row, col;
        while (true) {
          cin >> row;
          cin >> col;
          if (row == -1 && col == -1) break;
          g.turnOn(row, col);
        }
        cout << g;
      }
      else if ( cmd == "neighbours" ) {
        g.printCells();
      }
      else if (cmd == "game") {
        cin >> moves;
        if (moves == 1) {
          cout << moves << " move left" << endl;
        } else {
          cout << moves << " moves left" << endl;
        }
      }
      else if (cmd == "switch") {
        --moves;
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r, c);
        cout << g;
        if (moves == 1) {
          cout << moves << " move left" << endl;
        } else {
          cout << moves << " moves left" << endl;
        }
        if (g.isWon()) {
          cout << "Won" << endl;
          break;
        }
        if (moves == 0) {
          cout << "Lost" << endl;
          break;
        }
      }
    }
  } catch (ios::failure &) {}
}