#include <stdbool.h>
#include <stdio.h>

int main(void) {
    // Existen múltiples tipos de operadores en C, entre ellos estan los aritméticos, relacionales,
    // lógicos, bitwise, los operadores de asignación compuesta, incrementales, decrementales, ternario,
    // sizeof como operador, precedencia y asociatividad.

    // Entre los operadores aritméticos encontramos:
    // Suma: a + b (5+3 -> 8)
    // Resta: a - b (3-1 -> 2)
    // Multiplicación: a * b (3 * 2 -> 6)
    // División: a / b (6 / 2 -> 3)
    // Módulo (resto de la división): a %% b (17 %% 5 -> 2)
    // Para determinar el módulo algebraicamente se hace la operación (a %% n) => a - n * (a / n)
    printf("=== 1. OPERADORES ARITMETICOS ===\n");
    int a = 17, b = 5;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d   (division entera: trunca hacia 0, no redondea)\n", a / b);
    printf("a %% b = %d   (modulo: resto de la division entera)\n\n", a % b);

    // OJO: division entre enteros SIEMPRE trunca. Si quieres decimales,
    // al menos uno de los operandos debe ser float/double.
    double division_real = (double)a / b;
    printf("(double)a / b = %f  <- casteo necesario para precision\n\n", division_real);

    // En C originalmente no existía un tipo bool nativo, por lo que los operadores relacionales devuelven
    // 0 (falso) o 1 (verdadero). Entre estos encontramos:
    // Igualdad a == b
    // Desigualdad a != b
    // Mayor que a > b
    // Menor que a < b
    // Mayor o igual que a >= b
    // Menor o igual que a <= b
    printf("=== 2. OPERADORES RELACIONALES ===\n");
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n\n", a <= b);

    // Es importantísimo entender la diferencia entre = y ==. = es un operador de asignación, guarda un valor en
    // una variable, i.d. modifica la memoria, mientras que == compara dos valores sin modificar nada devolviendo
    // o bien 1 (true) o bien 0 (false). Si escribes = dentro de un if, C no te dará un error de compilación, pero
    // el programa se comportará mal, a no ser que uses las flags de advertencia -Wall. Si escribes if (x = 1) y tienes
    // estas flags activadas, GCC/Clang lanzarán inmediatamente "suggest parentheses around assignment used as truth value"
    // Para evitar esto se usa el estilo yoda, práctica clásica en C antiguo, en vez de poner if (x = 1), pones if (1 = x)
    // que no compila, por lo que te advierte que debes poner if (1 == x). Sin embargo gracias a los warning flags, esto
    // ya no es necesario y no se usa ni se recomienda

    // Los operadores lógicos son los siguientes:
    // AND && /// x != 0 && (10 / x) > 1
    // OR || /// x != 0 || (10 / x) > 1
    // NOT ! /// !true
    printf("=== 3. OPERADORES LOGICOS Y CORTOCIRCUITO ===\n");
    // && y || evaluan de izquierda a derecha y SE DETIENEN en cuanto
    // ya conocen el resultado final. Esto es clave para evitar crashes,
    // por ejemplo: puntero != NULL && *puntero == algo
    int x = 0;
    if (x != 0 && (10 / x) > 1) {
        printf("nunca se imprime esto\n");
    } else {
        printf("cortocircuito evito la division entre 0\n");
    }
    printf("!true = %d\n\n", !true);

    return 0;
}
