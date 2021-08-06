#include <stdio.h>

char i;

int main() {
    printf("\tMENU DI PROVA\na) Per immettere dati\nb) Per determinare il maggiore\nc) Per determinare il minore\nd) Per ordinare\ne) Per visualizzare\n");
    printf("\t\tScelta: _");
    i = getchar();

    switch (i) {
        case 'a':
            printf("In esecuzione l'opzione a");
            break;
        case 'b':
            printf("In esecuzione l'opzione b");
            break;
        case 'c':
            printf("In esecuzione l'opzione c");
            break;
        case 'd':
            printf("In esecuzione l'opzione d");
            break;
        case 'e':
            printf("In esecuzione l'opzione e");
            break;
        default:
            printf("Opzione inesistente");
    }
    return 0;
}
