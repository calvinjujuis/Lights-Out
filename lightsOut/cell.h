#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include "subject.h"
#include "observer.h"

class Cell : public Observer, public Subject {
  bool isOn = false;
  int r, c;

 public:
  Cell();  // Default constructor

  bool getState() const; // Returns the value of isOn.
  void setOn();          // Explicitly sets me to on.
  void toggle();         // Toggles me between on and off.
  void setCoords(int r, int c);  // Tells me my row and column number.
  int getRow() const;
  int getCol() const;

  SubscriptionType subType() const override;
  void notify(Cell &whoNotified) override;  // My neighbours will call this,
                                               // to let me know they've been
                                               // switched.
  void notifyObservers(SubscriptionType t) override;
  std::string getName() const override;
};

#endif