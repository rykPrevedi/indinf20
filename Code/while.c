#include <stdio.h>

int i, n, somma;

int main() {

    somma = 0;
    i = 1;
    while (i++ <= 5) {
        printf("inserisci numero :");
        scanf("%d", &n);
        somma += n;
    }
    printf("la somma è : %d ", somma);
    return 0;
}