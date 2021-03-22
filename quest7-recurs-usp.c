#include <stdio.h>

int soma(int n, int* array)
{
    if (n == 0)
        return 0;
    
    return (array[n-1] + soma(n-1, array));
}

int main()
{
    int n = 4;
    int array[4]= {1, 2, 3, 4};
    int total = 0;

    printf("%d", soma(n, array));

    return 0;
}