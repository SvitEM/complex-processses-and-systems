//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <filesystem>
#include<vector>

#include "Host.h"

namespace fs = std::filesystem;
using namespace std;

Host::Host() {
    Host::load_method();
}

Host::~Host() {
    dlclose(dylib);
}

void Host::say() {
    say_hello();
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

    string method;
    cin >> method;
    sscanf(method.c_str(), "%d", &i);

    const char *filename = libs[i - 1].c_str();
    cout << filename << endl;

    // read lib from folder
    dylib = dlopen(filename, RTLD_LAZY);
    if (dylib == nullptr) {
        cout << "unable to load " << filename << " Library!" << endl;
        throw std::runtime_error(std::string("unable to load ") + filename + std::string(" Library!"));
    }

    // get function from dylib
    say_hello = (void (*)()) dlsym(dylib, "say_hello");

    if (say_hello == nullptr) {
        dlclose(dylib);
        throw std::runtime_error(std::string("unable to load ") + filename + std::string(" function!"));
    }

}
