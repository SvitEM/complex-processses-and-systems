//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#ifndef LAB1__HOST_H
#define LAB1__HOST_H

#include <map>

using namespace std;

class Host {
public:
    Host();

    ~Host();

    void load_method();

    void run_method();

private:
    double T0, T1, h, g, endTime = -1;

    void *dylib;

    void (*method)(double, double, double, double, double, map<double, double>*);

    void input_values();

    void write(map<double, double>, char*);

};


#endif //LAB1__HOST_H
