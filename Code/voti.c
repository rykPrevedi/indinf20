#include <stdio.h>

int main() {
    int v[6], i, max, min, somma;
    float media;

    v[0] = 5;
    v[1] = 7;
    v[2] = 8;
    v[3] = 9;
    v[4] = 2;
    v[5] = 4;

    max = v[0];
    min = v[0];
    somma = v[0];
    for (i = 1; i <= 5; i++) {
        if (v[i] > max)
            max = v[i];
        if (v[i] < min)
            min = v[i];
        somma = somma + v[i];
    }
    media = somma/6;
    printf("il massimo: %d\nil minimo: %d\nla media: %f", max, min, media);
    return 0;
}