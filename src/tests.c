#include "../include/tests.h"
#include "../include/keypad.h"

#include <wchar.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 1001

// Вспомогательная safe-функция для определения длины w-строки
static size_t wcsLength(const wchar_t* string) {
    return string ? wcslen(string) : 0;
}

void test(const char* input, const wchar_t* expectedOutput) {
    wchar_t output[MAX_BUFFER_SIZE];

    keypadConvertation(input, output, MAX_BUFFER_SIZE);

    size_t expectedLength = wcsLength(expectedOutput);
    size_t outputLength = wcsLength(output);
    size_t maxLength = (expectedLength > outputLength) ? expectedLength : outputLength;
    int result = 1; // 1 - пройден, 0 - не пройден

    wprintf(L"Последовательность: %hs\n", input);
    wprintf(L"Ожидаемый результат: «%ls»\n", expectedOutput);
    wprintf(L"Результат выполнения: «");

    for (size_t i = 0; i < maxLength; ++i) {
        wchar_t expectedSymbol = (i < expectedLength) ? expectedOutput[i] : L'\0';
        wchar_t outputSymbol = (i < outputLength) ? output[i] : L'\0';

        if (expectedSymbol == outputSymbol && expectedSymbol != L'\0') { // Сходство символов
            wprintf(L"%lc", outputSymbol);
        } else if (expectedSymbol == L'\0' && outputSymbol != L'\0') { // Избыток символов
            wprintf(L"[%lc]", outputSymbol);
            result = 0;
        } else if (expectedSymbol != L'\0' && outputSymbol == L'\0') { // Недостаток символов
            wprintf(L"[ ]");
            result = 0;
        } else { // Несовпадение символов
            wprintf(L"[%lc]", outputSymbol);
            result = 0;
        }
    }
    
    wprintf(L"»\n");
    wprintf(L"Результат теста: %ls\n\n", result ? L"ПРОЙДЕН" : L"НЕ ПРОЙДЕН");
    return;
}