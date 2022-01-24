#include <iostream>
#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
using namespace std;

class Observer;

void Subject::attach(Observer *o) {
    observers.push_back(o);
}

string Subject::getObserverNames() const {
    string obsNames;
    for (size_t i = 0; i < observers.size(); ++i) {
        obsNames += observers[i]->getName();
        if (i + 1 != observers.size()) {
            obsNames += ", ";
        }
    }
    return obsNames;
}