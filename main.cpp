#include <iostream>
#include <chrono>
#include "Activity.h"
int main() {

    auto a = new Activity("Campeggio", "diocane", "merda");


    std::cout << "Hello world" << a->getDescription() << std::endl;
    return 0;
}
