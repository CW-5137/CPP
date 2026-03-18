#include <stdio.h>

int main() {
    int n, i;
    double pi = 0.0;

    printf("정수 n을 입력하세요: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        if (i % 2 == 0)
            pi += 1.0 / (2 * i + 1);
        else
            pi -= 1.0 / (2 * i + 1);
    }

    pi = pi * 4;

    printf("pi의 근사값: %.10f\n", pi);

    return 0;
}