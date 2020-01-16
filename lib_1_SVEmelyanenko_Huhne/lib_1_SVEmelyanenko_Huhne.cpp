#include "lib_1_SVEmelyanenko_Huhne.h"
#include <iostream>

using namespace std;

void method(double T0, double T1, double end_time, double h, double g,
            map<double, double> *results) {
    double currentTime = 0.0;
    double current_temp = T0;
    double temp = 0.0;
    double nextTemp = 0.0;
    results->clear();
    while (currentTime < end_time) {
        double functionTemp = (-g * (current_temp - T1));
        temp = current_temp + h * functionTemp;
        nextTemp = current_temp + (h / 2.) * (functionTemp + (-g * (temp - T1)));
        results->insert(pair<double, double>(currentTime, nextTemp));
        current_temp = nextTemp;
        currentTime += h;
    }
}