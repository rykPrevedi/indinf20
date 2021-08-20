#include <stdio.h>

int main() {
    printf("SOMMA NUMERI\n");
    printf("zero per terminare\n");
    int somma = 0;
    int numero = 1;

    while (numero != 0) {
        printf("Inser. intero: ");
        scanf("%d", &numero);
        somma += numero;
    }
    printf("Somma: %d", somma);
    return 0;
}