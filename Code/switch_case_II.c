#include <stdio.h>

int i;

int main() {
    printf("Digita una cifra : ");
    scanf("%d", &i);
    switch (i) {
        case 0:
        case 2:
        case 4:
            printf("pari\n");
            break;
        case 1:
        case 3:
        case 5:
            printf("dispari\n");
            break;
        default:
            printf("non compreso\n");
    }

    return 0;
}
