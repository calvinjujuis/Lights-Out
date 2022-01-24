#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"
#include "subject.h"
#include <string>

class Cell;

class Observer {
 public:
  virtual void notify(Cell &s) = 0;  // s is the Subject that called the notify method
  virtual SubscriptionType subType() const = 0;
  virtual ~Observer() = default;

  virtual std::string getName() const = 0; 
};

#endif