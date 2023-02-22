#pragma once
#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T* array, size_t size, F func) {
    for (size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

template<typename T>
void print(const T& val) {
    std::cout << val << " ";
}