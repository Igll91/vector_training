#include <iostream>
#include "vector_example.h"

void printVec(etk::vector& vec)
{
    std::cout << "printing vec elements: " << std::endl;
    for(unsigned int el = 0; el < vec.size(); ++el)
    {
        std::cout << "el: " << vec.at(el) << std::endl;
    }
}

void printSize(etk::vector& vec, const int expectedSize)
{
    std::cout << "Size should be: " << expectedSize <<  " == " << vec.size() << std::endl;
}

int main()
{
    std::cout << "Starting..." << std::endl;

    etk::vector a(5);
    etk::vector b(7);
    etk::vector c;
    etk::vector d({5,10,15,20,25,30});

    printSize(a, 0);
    printSize(b, 0);
    printSize(c, 0);
    printSize(d, 6);

    a.push_back(1);
    a.push_back(2);

    etk::vector e(a);
    printSize(a, 2);
    printSize(e, 2);

    std::cout << "expecting resize call here..." << std::endl;

    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    printSize(a, 7);

    printVec(a);
    printVec(d);
    printVec(e);

    etk::vector f = e;

    printVec(f);

    return 0;
}
