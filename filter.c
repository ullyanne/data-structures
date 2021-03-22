#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void filter(bool(*function)(int), int* array, int* newarray, int len, int counter)
{
    if(len > 0)
    {
        if(function(*array))
        {
            *newarray = *array;
            counter++;
            printf("%d ", *newarray);
        }

        return(filter(function, array+1, newarray+1, len-1, counter));
    }
}

bool even(int num)
{
    return num%2 == 0;
}

bool odd(int num)
{
    return num%2 != 0;
}

void scan(int* array, int size)
{
    if (size > 0)
    {
        scanf("%d", array);
        scan(array+1, size-1);
    }
}

int main()
{
    int len;
    int countereven = 0;
    int counterodd = 0;

    printf("Insira o tamanho do array.\n");
    scanf("%d", &len);

    int *array = (int*) malloc(len * sizeof(int));
    int *newarray = (int*) malloc(len * sizeof(int));
    
    printf("Digite os elementos do array.\n");
    scan(array, len);
    
    printf("EVEN:\n");
    filter(even, array, newarray, len, countereven);

    printf("\nODD:\n");
    filter(odd, array, newarray, len, counterodd);
    printf("\n");

    free(array);
    free(newarray);
    return 0;
}