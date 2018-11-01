#include <iostream>
#include <cstring>
#include "vector_example.h"

namespace etk {

    /**
     *
     * CONSTRUCTORS
     *
     */
    vector::vector()
    {
        _elements = new int[_capacity];
        //add no throw... gather into signle function
    }

    vector::vector(const unsigned int size) : vector()
    {
        _capacity = size;
    }

    vector::vector(std::initializer_list<int> list)
    {
        _capacity = list.size();
        _elements = new int[_capacity];
        for(int element: list)
        {
            push_back(element);
        }
    }

    vector::vector(const vector& other)
    {
        _capacity = other.size();
        _elements = new int[_capacity];
        for(int index = 0; index < _capacity; ++index)
        {
            push_back(other.at(index));
        }
    }

    vector& vector::operator=(const vector& other)
    {
        if(this != &other)
        {
            *this = vector(other);
        }

        return *this;
    }

    vector::~vector()
    {
        delete[] _elements;
    }

    void vector::push_back(const int &value)
    {
        if(_numOfElements < _capacity || resize())
        {
            _elements[_numOfElements++] = value;
        }
    }

    bool vector::resize()
    {
        std::cout << "resize()" << std::endl;

        const int newSize = _capacity + 1;      // TODO: rework resize
        int* resizedArray = new int[newSize];   // TODO: handle memory limit...

        std::memcpy(resizedArray, _elements, _capacity * sizeof(int));

        _capacity = newSize;
        delete[] _elements;
        _elements = resizedArray;

        return true;
    }

    int& vector::at(const unsigned int index) const
    {
        if(index > _numOfElements)
        {
            throw std::invalid_argument("received invalid index value.");
        }

        return _elements[index];
    }

    int& vector::operator[](const unsigned int index)
    {
        return _elements[index];
    }

    unsigned int vector::capacity() const
    {
        return _capacity;
    }

    unsigned int vector::size() const
    {
        return _numOfElements;
    }
}
