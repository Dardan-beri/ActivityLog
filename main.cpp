#include <iostream>
#include <vector>
int main() {

    std::vector<int> v = {1,2,3,4,5};
    v.insert(v.begin(), 2);
    std::cout << v[0] << std::endl;

    std::cout << "Hello world" << std::endl;

    return 0;
}
