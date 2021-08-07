#include <stdio.h>

int i, somma, numero;

int main() {
    somma = 0;
    for(i=1; i<=5; i++){
        printf("%d. inserisci numero : ", i);
        scanf("%d", &numero);
        somma += numero;
    }
    printf("%d", somma);
    return 0;
}