#include <stdio.h>

int main() {
    int area, base, altezza;
    printf("inserisci base : \n");
    scanf("%d", &base);
    printf("inserisci altezza : \n");
    scanf("%d", &altezza);

    printf("AREA RETTANGOLO\n\n");
    printf(" base : %d\n altezza : %d\n area : %d\n", base, altezza, base*altezza);
    return 0;
}
