/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD15-pierre.jeannin
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

#include <iostream>

template<typename T>
class array {
    public:
        array(unsigned int n) {
            _size = n;
            _array = new T[n];
        }
        array() {
            _size = 0;
            _array = nullptr;
        }
        array(const array<T> &otherArray) {
            _size = otherArray._size;
            for (int i = 0; i < _size; ++i)
                _array[i] = otherArray._array[i];
        }
        ~array() {
            if (_array)
                delete [] _array;
        }
        void dump() const {
            unsigned int index = 0;
            std::cout << "[";
            while (index < _size) {
                std::cout << _array[index++];
                if (index < _size)
                    std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
        int size() const { return (_size); }
        template<typename U>
        array<U> convertTo(U(*convertionFunction)(const T &)) const {
            array<U> newTab(_size);
            for (int i = 0; i < _size; ++i)
                newTab[i] = _array[i];
            return (newTab);
        }
        const T &operator[](size_t index) const {
            if (index >= _size)
                throw (std::exception());
            return (_array[index]);
        }
        T &operator[](size_t index) {
            if (index >= _size) {
                T *largerTab = new T[index + 1];
                for (int i = 0; i < _size; ++i)
                    largerTab[i] = _array[i];
                _size = index + 1;
                delete [] _array;
                _array = largerTab;
            }
            return (_array[index]);
        }
        array<T> &operator=(const array<T> &otherArray) {
            _size = otherArray._size;
            if (_array != nullptr)
                delete [] _array;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = otherArray._array[i];
            return (*this);
        }
    protected:
    private:
        unsigned int _size;
        T *_array;
};

template<>
void array<bool>::dump() const {
    unsigned int index = 0;
    std::cout << "[";
    while (index < _size) {
        std::cout << (_array[index++] == true ? "true" : "false");
        if (index < _size)
            std::cout << ", ";
    }
}

#endif /* !EX05_HPP_ */
