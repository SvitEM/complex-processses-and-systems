//#include <iostream>

#include "lib_1_SVEmelyanenko_Euler.h"

using namespace std;

double temp_f(double g, double current_temp, double T1){
    return -g * (current_temp - T1);
}

void method(double T0, double T1, double end_time, double h, double g,
            map<double, double> *results) {
    double current_time = 0.0;
    double current_temp = T0;
    double temp = 0.0;
    double next_temp = 0.0;
    results->clear();
    while (current_time < end_time) {
        double functionTemp = (temp_f(g, current_temp, T1));
        temp = current_temp + h * functionTemp;
        next_temp = current_temp + (h / 2.) * (functionTemp + ((temp_f)(g, temp, T1)));
        results->insert(pair<double, double>(current_time, next_temp));
        current_temp = next_temp;
        current_time += h;
    }
}