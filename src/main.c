#include "../include/keypad.h"
#include "../include/tests.h"

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define MAX_BUFFER_SIZE 1001

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    char input[MAX_BUFFER_SIZE];
    wchar_t output[MAX_BUFFER_SIZE];

    // Блок ручного ввода последовательности
    wprintf(L"Введите последовательность: ");
    if (!fgets(input, sizeof(input), stdin))
        return 1;
    input[strcspn(input, "\n")] = '\0';
    keypadConvertation(input, output, MAX_BUFFER_SIZE);
    wprintf(L"Результат: %ls\n\n", output);

    // Блок с функцией тестирования, примеры взяты из ТЗ
    test("55556422333666", L"привет");
    test("55556422233666", L"привет");

    return 0;
}