#include "pch.h"
#include "MyClass.h"

int MyClass::max_of_three_numbers(int x, int y, int z)
{
    if (x > y && x > z)
    {
        return x;
    }
    else if (y > z)
    {
        return y;
    }
    else
    {
        return z;
    }
}

int MyClass::max_index(int a)
{
    int b = 0;

    while (0 != a)
    {
        if (0 == ((a % 10) % 2))
        {
            b *= 10;
            b += (a % 10);
        }
        a /= 10;
    }

    return b;
}

int MyClass::min_index(int a)
{
    int r = 9;

    while (0 != a)
    {
        if ((a % 10) < r)
        {
            r = a % 10;
        }
        a /= 10;
    }

    return r;
}

int MyClass::diag(int** a, int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((j < i) && (1 == (a[i][j] % 2)))
            {
                sum += a[i][j];
            }
        }
    }

    return sum;
}

