#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <string>
#include "subscriptions.h"

class Observer;

class Subject {
 protected:
  std::vector<Observer*> observers;

 public:
  void attach(Observer *o);
  virtual void notifyObservers(SubscriptionType t) = 0;
  std::string getObserverNames() const;
};

#endif