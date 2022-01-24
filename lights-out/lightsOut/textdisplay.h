#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"

class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  const int gridSize;

 public:
  TextDisplay(int n);

  void notify(Cell &whoNotified) override;
  SubscriptionType subType() const override;
  virtual std::string getName() const override;

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif