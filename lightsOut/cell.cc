#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
  isOn = true;
}

void Cell::toggle() {
  isOn = ! isOn;
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Cell & whoNotified) {
  this->toggle();
  this->notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::notifyObservers(SubscriptionType t) {
  if (t == SubscriptionType::All) {
    for (size_t i = 0; i < observers.size(); ++i) {
      observers[i]->notify(*this);
    }
  } else {
    Observer *obstd = observers.back();
    obstd->notify(*this);
  }
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

std::string Cell::getName() const {
  std::string cellName = "(" + std::to_string(this->getRow()) + "," + std::to_string(this->getCol()) + ")";
  return cellName;
}