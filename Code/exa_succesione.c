#include <stdio.h>
#define P 48
int i, elementi, n;

int main() {
    elementi = 0;
    printf("Quale n vuoi calcolare? ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){

        elementi += i;
    }
    printf("con n = %d servono %d elementi\ne %d cm di striscia led",n , elementi, elementi*48);
    return 0;
}
