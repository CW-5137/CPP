#include <stdio.h>

int reverse(int x);   // 함수 선언

int main()
{
    int x;

    scanf("%d", &x);
    printf("%d\n", reverse(x));

    return 0;
}

int reverse(int x)    // 함수 정의
{
    int reverse_Number = 0;

    while (x != 0)
    {
        int digit = x % 10;
        reverse_Number = reverse_Number * 10 + digit;
        x /= 10;
    }

    return reverse_Number;
}