#include <stdio.h>

int reverse(int x)
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

int main()
{
    int x;

    scanf("%d", &x);              // 입력
    printf("%d\n", reverse(x));   // 출력

    return 0;
    
}
