//#include <iostream>

#include "lib_1_SVEmelyanenko_Euler.h"

using namespace std;

void method(double T0, double T1, double end_time, double h, double g,
            map<double, double> *results) {
    double current_time = 0.0;
    double current_temp = T0;
    double temp = 0.0;
    double next_temp = 0.0;
    results->clear();
    while (current_time < end_time) {
        temp = current_temp + h * (-g * (current_temp - T1));
        current_temp = temp;
        results->insert(pair<double, double>(current_time, current_temp));
        current_time += h;

    }
}