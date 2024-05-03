#include <stdio.h>

typedef unsigned long long ull;

ull fib(ull n);

int main(void)
{
    printf("%llu\n", fib(20));

    return 0;
}


ull fib(ull n)
{
    ull fib_arr[2];

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (ull i = 1; i < n; i++)
    {
        if (i % 2)
        {
            fib_arr[0] += fib_arr[1];
        }
        else
        {
            fib_arr[1] += fib_arr[0];
        }
    }

    return fib_arr[n % 2];
}