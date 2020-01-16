#ifndef LAB1_SHARED_LIBRARY_H
#define LAB1_SHARED_LIBRARY_H

#include <map>

using namespace std;

extern "C" void method(double , double, double, double, double, map<double, double>*);

#endif //LAB1_SHARED_LIBRARY_H