#include <stdio.h>

int main() {
    int n;
    int man, chun, baek, sip, il;

    printf("정수를 입력하세요: ");
    scanf("%d", &n);

    man = n / 10000;
    chun = (n % 10000) / 1000;
    baek = (n % 1000) / 100;
    sip = (n % 100) / 10;
    il = n % 10;

    if (man != 0) {
        if (man == 1)
            printf("만 ");
        else
            printf("%d만 ", man);
    }

    if (chun != 0) {
        if (chun == 1)
            printf("천 ");
        else
            printf("%d천 ", chun);
    }

    if (baek != 0) {
        if (baek == 1)
            printf("백 ");
        else
            printf("%d백 ", baek);
    }

    if (sip != 0) {
        if (sip == 1)
            printf("십 ");
        else
            printf("%d십 ", sip);
    }

    if (il != 0) {
        printf("%d", il);
    }

    printf("\n");

    return 0;
}