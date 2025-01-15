#ifndef OPERATIONS_H
#define OPERATIONS_H

// Умножение большого числа, представленного массивом цифр, на 2
void MultiplyByTwo(int*& number, int& size, int& capacity);

// Вычитание 1 из большого числа, представленного массивом цифр
void SubtractOne(int* number, int& size);

// Вывод числа, представленного массивом цифр, в правильном порядке
void PrintNumber(const int* number, int size);

#endif // OPERATIONS_H
