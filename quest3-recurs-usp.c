#include <stdio.h>

int pot(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    return pot(x, n-1) * x;
}

int main()
{
    int x, n;

    scanf("%d%d", &x, &n);

    printf("%d", pot(x, n));

    return 0;
}
