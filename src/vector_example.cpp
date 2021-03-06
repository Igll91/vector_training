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
        if(this != &other)
        {
            this->swap(other);
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

    void vector::swap(const vector& other) throw()
    {
        int* tmpElements = new (std::nothrow) int[other.size()];

        if(tmpElements)
        {
            std::memcpy(tmpElements, _elements, other.size() * sizeof(int));
            delete[] _elements;

            _elements       = tmpElements;
            _capacity       = other.capacity();
            _numOfElements  = other.size();
        }
    }

    bool vector::resize()
    {
        int newSize         = _capacity * 2;
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

        delete[] _elements;
        _capacity = newSize;
        _elements = newElements;

        return true;
    }

}
