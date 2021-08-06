#include <stdio.h>

#define COSTO 35
char i;

int main() {

    printf("SCONTI :\nPer pensionati, scegli P\nPer studenti, scegli S\nPer disoccupati, scegli D\n");
    printf("\tScegli");
    i = getchar();

        switch (i) {
            case 'P':
                printf("Da pagare : %f", COSTO - COSTO * 0.1);
                break;
            case 'S':
                printf("Da pagare : %f", COSTO - COSTO * 0.15);
                break;
            case 'D':
                printf("Da pagare : %f", COSTO - COSTO * 0.25);
                break;
            default:
                printf("Utente ordinario");
        }
    return 0;
}
