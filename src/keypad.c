#include "../include/keypad.h"

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <ctype.h>

#define KEYS_COUNT 10

static const wchar_t* symbolsMap[KEYS_COUNT] = {
    L" ",       // 0
    L"@",       // 1
    L"абвг",    // 2
    L"дежз",    // 3
    L"ийкл",    // 4
    L"мноп",    // 5
    L"рсту",    // 6
    L"фхцч",    // 7
    L"шщъы",    // 8
    L"ьэюя",    // 9
};

// Вспомогательная функция, определяющая результирующую букву по введеной последовательности цифр
static wchar_t keyRecognize(char key, int count) {
    int index = key - '0';
    const wchar_t *symbols = symbolsMap[index];
    size_t length = wcslen(symbols);

    if (length == 0) {
        fprintf(stderr, "Предупреждение: клавиша '%c' не распознана!\n", key);
        return L' ';
    }
    
    return symbols[(size_t)(count - 1) % length];
}

size_t keypadConvertation(const char* input, wchar_t* outputBuffer, size_t outputBufferSize) {
    size_t outputSize = 0;
    char previousSymbol = '\0';
    int countRepeats = 0;
    
    if (!input || !outputBuffer || outputBufferSize == 0) {
        fprintf(stderr, "Ошибка ввода: проверьте правильность введенных данных!\n");
        return 0;
    }

    for (size_t i = 0;; ++i) {
        char currentSymbol = input[i];
        int isEnd = (currentSymbol == '\0');
        int isSeparator = isEnd || isspace((unsigned char)currentSymbol);

        if (!isSeparator && (currentSymbol < '0' || currentSymbol > '9')) // Пропуск мусора
            continue;

        if (!isSeparator) { // Логика обработки при символе
            if (previousSymbol == currentSymbol) {
                ++countRepeats;
            } else {
                if (previousSymbol >= '0' && previousSymbol <= '9' && countRepeats > 0) {
                    if (outputSize + 1 < outputBufferSize) {
                        outputBuffer[outputSize++] = keyRecognize(previousSymbol, countRepeats);
                    } else break;
                }
                previousSymbol = currentSymbol;
                countRepeats = 1;
            }
        } else { // Логика обработки при пробеле
            if (previousSymbol >= '0' && previousSymbol <= '9' && countRepeats > 0) {
                if (outputSize + 1 < outputBufferSize) {
                    outputBuffer[outputSize++] = keyRecognize(previousSymbol, countRepeats);
                } else break;
            }
            previousSymbol = '\0';
            countRepeats = 0;

            if (isEnd) break;
        }
    }
    outputBuffer[outputSize] = L'\0';
    return outputSize;
}