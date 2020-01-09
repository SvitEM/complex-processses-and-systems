//
// Created by Svyatoslav Emelyanenko on 08.01.2020.
//

#ifndef LAB1__HOST_H
#define LAB1__HOST_H


class Host {
public:
    Host();

    ~Host();

    void say();

private:
    void *dylib;

    void (*say_hello)();

    void load_method();
};


#endif //LAB1__HOST_H
