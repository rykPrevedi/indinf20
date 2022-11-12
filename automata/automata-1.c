#include <stdio.h>
#include <setjmp.h>

//
// Created by Utente on 08/10/2022.
//


static jmp_buf JmpEnv;

char inputs[] = {'a', 'a', 'b', 'c'};
static int status = 0;

static int i = 0;

char next() {
    return inputs[i++];
}


int main() {

    if (setjmp(JmpEnv) == 0) {

        while (1) {

            if (status == 1) {
                if (inputs[i] == 'b') {
                    printf("actual status : 1\ninput received : \'b\'\nbehaviour automata -> Status Not Changed!\n");
                    printf("\nready for new transactions...\n\n");
                } else if (inputs[i] == 'c') {
                    printf("actual status : 1\ninput received : \'c\'\nbehaviour automata "
                           "-> Status Changed !\nthe machine has reached its final status correctly !");
                    break;
                } else {
                    printf("actual status : 1\ninput received : \'%c\'\nbehaviour automata ->", inputs[i]);
                    longjmp(JmpEnv, 1);
                }

            } else if (status == 2) {
                if (inputs[i] == 'a') {
                    printf("actual status : 2\ninput received : \'a\'\nbehaviour automata -> Status Changed!\n");
                    status = 0;
                    printf("\nready for new transactions...\n\n");
                } else {
                    printf("actual status : 2\ninput received : \'%c\'\nbehaviour automata ->", inputs[i]);
                    longjmp(JmpEnv, 1);
                }

            } else if (status == 0) {
                if (inputs[i] == 'a') {
                    printf("actual status : 0\ninput received : \'a\'\nbehaviour automata -> Status Changed!\n");
                    status = 2;
                    printf("\nready for new transactions...\n\n");
                } else if (inputs[i] == 'b') {
                    printf("actual status : 0\ninput received : \'b\'\nbehaviour automata -> Status Changed!\n");
                    status = 1;
                    printf("\nready for new transactions...\n\n");
                } else if (inputs[i] == 'c') {
                    printf("actual status : 0\ninput received : \'c\'\nbehaviour automata "
                           "-> Status Changed !\nthe machine has reached its final status correctly !");
                    break;
                } else {
                    printf("actual status : 2\ninput received : \'%c\'\nbehaviour automata ->", inputs[i]);
                    longjmp(JmpEnv, 1);
                }

            } else {
                printf("actual status : %d\ninput received : \'%c\'\nbehaviour automata ->", status, inputs[i]);
                longjmp(JmpEnv, 1);
            }

            next();
        }

    } else {
        printf(" Error! transaction not allowed !");
    }

    return (0);
}



