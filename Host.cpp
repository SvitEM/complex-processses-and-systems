//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#include <iostream>
#include <string>
#include <dlfcn.h>

#include "library.h"

#include "Host.h"

using namespace std;

Host::Host() {
    const char *filename = "./liblab1_shared.dylib";

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

Host::~Host() {
    dlclose(dylib);
}

void Host::say() {
    say_hello();
}
