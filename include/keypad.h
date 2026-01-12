#ifndef KEYPAD_H
#define KEYPAD_H

#include <wchar.h>
#include <stddef.h>

// Функция преобразования числовой последовательности в буквы.
size_t keypadConvertation(const char* input, wchar_t* outputBuffer, size_t outputBufferSize);

#endif