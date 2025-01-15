#include <iostream>
#include <cstring>
#include "operations.h"

int main() {
    setlocale(LC_ALL, "rus");
    // Приветствие
    std::cout << "Программа для вычисления числа 2^n - 1." << std::endl;

    unsigned int n;

    while (true) {
        std::cout << "Введите значение n (n > 40): ";
        std::cin >> n;

        // Защита от "дурака"
        if (std::cin.fail() || n <= 40) {
            // Проверка на вещественное число
            if (std::cin.peek() != '\n') {
                std::cin.clear(); // Сбрасываем флаг ошибки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
                std::cout << "Ошибка: n должно быть целым числом  строго больше 40." << std::endl;
            }
            else {
                std::cout << "Ошибка: n должно быть целым числом" << std::endl;
            }
        }
        else {
            break; // Ввод корректен, выходим из цикла
        }
    }
    // Начальная емкость массива
    int capacity = 10; // Начальный размер
    int* number = new int[capacity];
    memset(number, 0, capacity * sizeof(int));
    int size = 1; // Начальный размер числа
    number[0] = 1; // Инициализация числа 2^0 = 1

    // Вычисляем 2^n
    for (unsigned int i = 0; i < n; ++i) {
        MultiplyByTwo(number, size, capacity);
    }

    // Вычитаем 1, чтобы получить 2^n - 1
    SubtractOne(number, size);

    // Выводим результат
    std::cout << "Результат 2^" << n << " - 1 равен: ";
    PrintNumber(number, size);

    // Освобождаем память
    delete[] number;

    return 0;
}
