//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#include <iostream>
#include <string>
#include <dlfcn.h>

#include "library.h"

#include "Host.h"

using namespace std;


int main(int argc, const char *argv[]) {
//    const char *filename = "./liblab1_shared.dylib";
//
//    void *dylib = dlopen(filename, RTLD_LAZY);
//
//    if (dylib == nullptr) {
//        cout << "unable to load " << filename << " Library!" << endl;
//        return 1;
//    }
//
//    // get print function from libtest.dylib
//    auto say_hello = (void (*)()) dlsym(dylib, "say_hello");
//
//    if (say_hello == nullptr) {
//        cout << "unable to load " << filename << " function!" << endl;
//        dlclose(dylib);
//        return 2;
//    }

    // test the print function
//    say_hello();

//    dlclose(dylib);

    Host A;
    A.say();
    return 0;
}