#include "hilos.h"
#include <stdio.h>
int main() {
    printf("=== Lectores-Escritores | %d lectores, %d escritores ===\n\n", NUM_LECTORES, NUM_ESCRITORES);
    ejecutar_hilos();
    printf("Base de datos final: %d\n", database);
    return 0;
}
