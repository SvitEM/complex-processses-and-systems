//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <filesystem>
#include<vector>
#include <cmath>
#include <map>
#include <fstream>

#include "Host.h"

namespace fs = std::filesystem;
using namespace std;

Host::Host() {
    Host::load_method();
}

Host::~Host() {
    dlclose(dylib);
}

void Host::input_values() {
    std::cout << "T0 T1 h g end_time" << std::endl;
//    T0 = 40;
//    T1 = 15;
//    h = 10;
//    g = 0.1;
//    endTime = 120;
    std::cin >> T0 >> T1 >> h >> g >> endTime;
}

void Host::write(map<double, double> results, char *filename) {
    ofstream outFile;
    outFile.open(filename);
    for (auto & result : results) {
        outFile << result.first << "\t" << result.second << endl;
    }
    outFile.close();
}

void Host::run_method() {
    if ( endTime <= 0){
        input_values();
    }
    map<double, double> results;

    method(T0, T1, endTime, h, g, &results);

    map<double, double> analytics;
    map<double, double> infelicity;

    for (auto & result : results) {
        double anRes = T1 + ((T0 - T1) * exp(-g * result.first));
        double err = fabs(anRes - result.second);

        analytics.insert(pair<double, double>(result.first, anRes));
        infelicity.insert(pair<double, double>(result.first, err));
    }

    if (!fs::is_directory("results") || !fs::exists("results")) { // Check if src folder exists
        fs::create_directory("results"); // create src folder
    }

    write(results, "results/results.txt");
    write(analytics, "results/analytics.txt");
    write(infelicity, "results/infelicity.txt");
}

void Host::load_method() {

    cout << "Select method " << endl;
    vector<string> libs;
    string path = "./lib";
    int i = 0;
    for (const auto &entry : fs::directory_iterator(path)) {
        i++;
        libs.push_back(entry.path());
        string str = entry.path().filename();
        size_t pos = str.find('.');
        cout << i << " for " << str.substr(0, pos) << endl;
    }
    cout << "default Euler" << endl;

    string method_num;
    cin >> method_num;
    i = stoi(method_num.c_str());
//    sscanf(method_num.c_str(), "%d", &i);

    const char *filename = libs[i - 1].c_str();
    cout << filename << endl;

    // read lib from folder
    dylib = dlopen(filename, RTLD_LAZY);
    if (dylib == nullptr) {
        cout << "unable to load " << filename << " Library!" << endl;
        throw std::runtime_error(std::string("unable to load ") + filename + std::string(" Library!"));
    }

    // get function from dylib
    method = (void (*)(double, double, double, double, double, map<double, double>*)) dlsym(dylib, "method");

    if (method == nullptr) {
        dlclose(dylib);
        throw std::runtime_error(std::string("unable to load ") + filename + std::string(" function!"));
    }

}
