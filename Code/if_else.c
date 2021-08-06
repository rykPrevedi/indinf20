#include <stdio.h>

int main() {
int i, a;
i = 110;

/* i<100 conditional control, return zero or everything else except zero */
a = i<100;

if(a)
    printf("il valore è minore di 100");
else 
  printf("il valore è maggiore di 100");

    return 0;
}
