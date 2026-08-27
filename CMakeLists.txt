cmake_minimum_required(VERSION 3.20)
project(c_systems_labs C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Banderas estrictas del compilador para evitar errores de memoria y tipos
add_compile_options(-Wall -Wextra -Wpedantic -g)

# Programa de ejemplo inicial
add_executable(c_systems_labs main.c
        radix-converter/base_converter.c)
