#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct PaddingStruct {
    char a; // 1 byte
    // 3 bytes de padding
    int b;  // 4 bytes
};

union Union {
    char c; // 1 byte
    int i; // 4 bytes
    double d; // 8 bytes
};

int main(void) {

    char x = 1; // 1 Byte %c / %d
    unsigned char ux = 1; // 1 Byte %u
    short s = 2; // 2 Bytes %hd
    signed short int ssi = 2; // 2 Bytes %hd
    unsigned short us = 2; // 2 Bytes %hu
    int y = 4; // 4 Bytes %d / %i
    signed int si = 4; // 4 Bytes %d / %i
    unsigned int ui = 4; // 4 Bytes %u
    long l = 8; // 8 Bytes %ld
    signed long int sli = 8; // 8 Bytes %ld
    unsigned long ul = 8; // 8 Bytes %lu
    long long ll = 8; // 8 Bytes %lld
    signed long long int slli = 8; // 8 Bytes %lld
    unsigned long long ull = 8; // 8 Bytes %llu
    _Bool bb = 1; // 1 Byte %d. Este se mantiene por compatibilidad pero ya no es usado, se prefiere stdbool.h. 0 es false y 1 es true
    bool b = true; // Incluyendo <stdbool.h> de 1 Byte %d

    float z = 4; // 4 Bytes %f
    double w = 8; // 8 Bytes %lf
    long double ld = 16; // 16 Bytes %Lf

    // size_T es un tipo de dato sin signo y entero diseñado para representar tamaños de memoria en C, siendo %2zu la instrucción para imprimir con printf
    // este tipo de dato. Es una variable unsigned puesto que el tamaño de la memoria nunca es negativa, por lo que size t solo almacena números >= 0.
    // Su tamaño es dependiente de la arquitectura, ocupando con 32-bit 4 bytes, y con 64-bit 8 bytes. Garantiza ser lo suficientemente grande como para contener
    // el tamaño del objeto, array o bloque de memoria más grande que tu sistema pueda almacenar.
    size_t a = 1;

    // Estos tipos de stdint.h fueron introducidos en C99 para evitar la incertidumbre entre arquitecturas (32-bit vs 64-bit).
    // Garantizan el tamaño exacto sin importar la CPU.
    int8_t int8 = 1; // 1 byte. PRId8
    uint8_t uint8 = 1; // 1 byte. PRIu8
    int16_t int16 = 2; // 2 bytes. PRId16
    uint16_t uint16 = 2; // 2 bytes. PRIu16
    int32_t int32 = 4; // 4 bytes. PRId32
    uint32_t uint32 = 4; // 4 bytes. PRIu32
    int64_t int64 = 8; // 8 bytes. PRId64
    uint64_t uint64 = 8; // 8 bytes. PRIu64
    intptr_t intptr = 8; // 8 bytes en memoria, tamaño de puntero. PRIdPTR
    uintptr_t uintptr = 8; // 8 bytes en 64bit, guarda una dirección de memoria como un entero. Printf: PRIdPTR / PRIuPTR (unsigned)

    // Los punteros ocupan 8 bytes en sistemas de 64 bits y 4 bytes en sistemas de 32 bits
    // Todos los punteros ocupan lo mismo, ya que guardan una dirección física de memoria de la CPU

    // Un arreglo ocupa en memoria sizeof(tipo) * elementos. Por ejemplo, un int arr[10] es 4 * 10 = 40 bytes.
    // Esto sucede ya que un arreglo es un bloque contiguo de memoria reservado en el stack

    // Una struct ocupa la suma del tamaño de sus miembros más los bytes de su padding.
    // Un union ocupa el tamaño igual al de su miembro más grande
    // Un enum ocupa típicamente 4 bytes puesto que internamente el compilador lo gestiona como un int.

    printf("=== 1. ENTEROS PRIMITIVOS ===\n");
    printf("char               : %2zu byte(s)\n", sizeof(char));
    printf("short              : %2zu byte(s)\n", sizeof(short));
    printf("int                : %2zu byte(s)\n", sizeof(int));
    printf("long               : %2zu byte(s)\n", sizeof(long));
    printf("long long          : %2zu byte(s)\n", sizeof(long long));
    printf("bool (_Bool)       : %2zu byte(s)\n\n", sizeof(bool));

    printf("=== 2. COMA FLOTANTE ===\n");
    printf("float              : %2zu byte(s)\n", sizeof(float));
    printf("double             : %2zu byte(s)\n", sizeof(double));
    printf("long double        : %2zu byte(s)\n\n", sizeof(long double));

    printf("=== 3. ANCHO FIJO (<stdint.h>) ===\n");
    printf("int8_t  / uint8_t  : %2zu byte(s)\n", sizeof(int8_t));
    printf("int16_t / uint16_t : %2zu byte(s)\n", sizeof(int16_t));
    printf("int32_t / uint32_t : %2zu byte(s)\n", sizeof(int32_t));
    printf("int64_t / uint64_t : %2zu byte(s)\n\n", sizeof(int64_t));

    printf("=== 4. PUNTEROS Y DERIVADOS ===\n");
    printf("int* (Puntero)     : %2zu byte(s)\n", sizeof(int *));
    printf("void* (Puntero)    : %2zu byte(s)\n", sizeof(void *));
    printf("int[10] (Array)    : %2zu byte(s)\n", sizeof(int[10]));
    printf("struct con padding : %2zu byte(s)\n", sizeof(struct PaddingStruct));
    printf("union (max double) : %2zu byte(s)\n", sizeof(union Union));
    return 0;
}
