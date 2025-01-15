#include <iostream>
#include <cstring>
#include "operations.h"

// Увеличение емкости динамического массива
void ResizeArray(int*& number, int& capacity) {
    int new_capacity = capacity * 2; // Увеличиваем в 2 раза
    int* new_number = new int[new_capacity];
    std::memcpy(new_number, number, capacity * sizeof(int));
    delete[] number;
    number = new_number;
    capacity = new_capacity;
}

// Умножение большого числа, представленного массивом цифр, на 2
void MultiplyByTwo(int*& number, int& size, int& capacity) {
    int carry = 0;
    for (int i = 0; i < size; ++i) {
        int product = number[i] * 2 + carry;
        number[i] = product % 10;
        carry = product / 10;
    }
    if (carry > 0) {
        if (size == capacity) {
            ResizeArray(number, capacity); // Увеличение емкости массива
        }
        number[size] = carry;
        ++size;
    }
}

// Вычитание 1 из большого числа, представленного массивом цифр
void SubtractOne(int* number, int& size) {
    int i = 0;
    while (number[i] == 0) {
        number[i] = 9;
        ++i;
    }
    number[i] -= 1;
    // Уменьшение размера, если старшая цифра стала 0
    if (number[size - 1] == 0) {
        --size;
    }
}

// Вывод числа, представленного массивом цифр, в правильном порядке
void PrintNumber(const int* number, int size) {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << number[i];
    }
    std::cout << std::endl;
}
