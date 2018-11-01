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
        init(DEFAULT_CAPACITY);
    }

    vector::vector(const unsigned int size)
    {
        init(size);
    }

    vector::vector(std::initializer_list<int> list)
    {
        init(list.size());

        // check if memory is allocated successfully
        if(_elements)
        {
            for(int element: list)
            {
                push_back(element);
            }
        }
    }

    vector::vector(const vector& other)
    {
        // TODO: reuse initializer list constructor?

        init(other.size());

        // check if memory is allocated successfully
        if(_elements)
        {
            for(unsigned int index = 0; index < _capacity; ++index)
            {
                push_back(other.at(index));
            }
        }
    }

    vector& vector::operator=(const vector& other)
    {
        std::cout << this << std::endl;
        std::cout << &other << std::endl;

        if(this != &other)
        {
            std::cout << "copy assignment operator called" << std::endl;
            *this = vector(other);
        }

        return *this;
    }

    /**
     *
     * DESTRUCTOR
     *
     */
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

    /**
     *
     * PRIVATE METHODS
     *
     */
    bool vector::init(const unsigned int size)
    {
        _elements       = new (std::nothrow) int[size];
        _numOfElements  = 0;
        _capacity       = _elements ? size : 0;

        return _capacity;
    }

    bool vector::resize()
    {
        std::cout << "resize()" << std::endl; // debug printout

        int newSize         = _capacity * 2;      // TODO: rework resize
        int* newElements    = new (std::nothrow) int[newSize];

        // memory allocation failed, trying to increase by minimal value
        if(!newElements)
        {
            newSize = _capacity + 1;
            newElements = new (std::nothrow) int[newSize];
        }

        // memory allocation failed
        if(!newElements)
        {
            return false;
        }

        std::memcpy(newElements, _elements, _capacity * sizeof(int));

        _capacity = newSize;
        delete[] _elements;
        _elements = newElements;

        return true;
    }

}
