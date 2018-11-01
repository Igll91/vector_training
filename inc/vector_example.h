#pragma once
#include <initializer_list>

namespace etk {
    class vector {
    public:
        /*!
        * Constructs an empty vector.
        *
        * For some allocation strategies this preallocates
        * a fixed size buffer. However some implementations may
        * postpone the allocation for later.
        */
        vector();

        /*!
        * Constructs a vector with specified number of elements.
        *
        * This constructor allocates heap memory as soon as the vector
        * object is created. This should be more performant for situations
        * where the size of the vector is more or less known at instantiation.
        * This constructor should initialize the memory, for integers set it to 0.
        * On non-built in types we would call default constructors here.
        * @param size Number of integers to be allocated in the vector.
        */
        explicit vector(const unsigned int size);

        /*!
        * Constructs the vector from an initializer list.
        *
        * This one should allocate enough memory to contain all of the elements of the
        * initializer list. We can delegate the allocation to the integer vector.
        */
        vector(std::initializer_list<int> list);

        /*!
        * Destructor.
        */
        ~vector();
        /*!
        * Copy constructor.
        */
        vector(const vector& other);

        /*!
        * Copy assignment operator.
        */
        vector& operator=(const vector& other);

        /*!
        * Adds an element to the vector.
        * This method should reallocate memory for the vector when there's not
        * enough space for a new element.
        */
        void push_back(const int &value);

        /*!
        * Returns a reference to a vector element.
        * This operator does not perform bounds checking, passing an index
        * which is out of range results in undefined behaviour.
        *
        * @param index The index of the element to return.
        * @return A reference to the element at index
        */
        int& operator[](const unsigned int index);

        /*!
        * Returns a reference to a vector element.
        * The index is checked against vector bounds.
        *
        * @param index The index of the element to return.
        * @return A reference to the element at index
        */
        int& at(const unsigned int index) const;

        /*!
        * Returns the current number of elements in the vector.
        * Note: This number (in most allocation strategies) does not
        * match the actual vector memory size. Malloc is expensive!
        *
        * @return int The number of elements in the vector.
        */
        unsigned int size() const;

        unsigned int capacity() const;

    private:
        // insert implementation specific members here

        static const unsigned int DEFAULT_CAPACITY = 2;

        bool resize();

        bool init(const unsigned int size);

        int* _elements;
        unsigned int _numOfElements;
        unsigned int _capacity;
    };
}
