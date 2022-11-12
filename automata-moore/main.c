#include <stdio.h>
#include <setjmp.h>


const int table[][4] =
        {
                {2,  1,  3,  -1}, // State 0
                {-1, 1,  3,  -1}, // State 1
                {0,  -1, -1, -1}, // State 2
                {-1, -1, -1, -1}  // State 3
        };
//Input Symbols: 'a' 'b' 'c' 'x'

const char *outmfn[] = {"You are in state: 0", "You are in state: 1", "You are in state: 2", "You are in state: 3"};

int sfn(int currentState, int in) {
    return table[currentState][in];
}

void mfn(int currentState) {
    printf("%s\n", outmfn[currentState]);
}

static jmp_buf JmpEnv;


int main(int argc, char **argv) {

    static int state = 0;
    static char letter = ' ';

    if (setjmp(JmpEnv) == 0) {

        while(1){

            printf("Insert a symbol\n");
            scanf("%s", &letter);
            int numLetter = (int) letter - 'a';
            state = sfn(state, numLetter);

            if (state < 0) {
                longjmp(JmpEnv, 1);
            } else if (state == 3) {
                mfn(state);
                printf("Input is legal :)\n");
                break;
            } else {
                mfn(state);
            }
        }
    } else {
        printf("Error!!\nInput not legal !");
    }

    return 0;

}
