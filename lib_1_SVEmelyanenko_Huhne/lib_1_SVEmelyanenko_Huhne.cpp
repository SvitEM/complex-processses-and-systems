#include "lib_1_SVEmelyanenko_Huhne.h"
#include <iostream>

using namespace std;

double temp_f(double g, double current_temp, double T1){
    return -g * (current_temp - T1);
}

void method(double T0, double T1, double end_time, double h, double g,
            map<double, double> *results) {
    double currentTime = 0.0;
    double currentTemp = T0;
    double temp = 0.0;
    double nextTemp = 0.0;
    results->clear();
    while (currentTime < end_time) {
        double functionTemp = ((temp_f)(g, currentTemp, T1));
        temp = currentTemp + h * functionTemp;
        nextTemp = currentTemp + (h / 2.)*(functionTemp + ((temp_f)(g, temp, T1)));
        results->insert(pair<double, double>(currentTime, nextTemp));
        currentTemp = nextTemp;
        currentTime += h;
    }
}