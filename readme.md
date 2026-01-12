# Тестовое задание - кнопочный телефон на C
## Окружение
Язык: C11  
Комплилятор: gcc 15.2.0  
IDE: VSCode  
CMake 4.2.1  
Ninja 1.13.2  
## Запуск проекта
### CMake (Ninja)
```
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release  
cmake --build build  
.\build\testcase-itelma.exe  
```
### Компиляция через GCC
```
mkdir build  
cd src  
gcc main.c tests.c keypad.c  -o ../build/testcase-itelma  
../build/testcase-itelma.exe  
```