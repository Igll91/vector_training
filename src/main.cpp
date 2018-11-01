#include <iostream>
#include "vector_example.h"

void printVec(etk::vector& vec)
{
    std::cout << "printing vec elements: " << std::endl;
    for(int el = 0; el < vec.size(); ++el)
    {
        std::cout << "el: " << vec.at(el) << std::endl;
    }
}

int main()
{
    std::cout << "Starting..." << std::endl;

    etk::vector a(5);
    std::cout << a.size() << std::endl;

    etk::vector b(7);
    std::cout << b.size() << std::endl;

    etk::vector c;
    std::cout << c.size() << std::endl;

    etk::vector d({5,10,15,20,25,30});
    std::cout << d.size() << std::endl;

    a.push_back(1);
    a.push_back(2);

    etk::vector e(a);
    std::cout << e.size() << std::endl;

    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    std::cout << a.size() << std::endl;

    printVec(a);
    printVec(d);
    printVec(e);

    etk::vector f = e;

    printVec(f);

    return 0;
}
