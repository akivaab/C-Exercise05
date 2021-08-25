#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dogs.h"

void SortByName(Dog *dogs, size_t size)
{
    if (dogs)
    {
        PrintArray(dogs, size);
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < (size - 1 - i); j++)
            {
                if (NameComparator(&dogs[j], &dogs[j + 1]) > 0)
                {
                    Dog temp = dogs[j];
                    dogs[j] = dogs[j + 1];
                    dogs[j + 1] = temp;
                    PrintArray(dogs, size);
                }
            }
        }
    }
}

void SortBySize(Dog *dogs, size_t size)
{
    if (dogs)
    {
        PrintArray(dogs, size);
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < (size - 1 - i); j++)
            {
                if (SizeComparator(&dogs[j], &dogs[j + 1]) > 0)
                {
                    Dog temp = dogs[j];
                    dogs[j] = dogs[j + 1];
                    dogs[j + 1] = temp;
                    PrintArray(dogs, size);
                }
            }
        }
    }
}

int NameComparator(Dog *dog1, Dog *dog2)
{
    return strcmp(dog1->name, dog2->name);
}

double SizeComparator(Dog *dog1, Dog *dog2)
{
    return dog1->kg - dog2->kg;
}

void PrintArray(Dog *dogs, size_t size)
{
    printf_s("{");
    for (size_t i = 0; i < size; ++i)
    {
        printf_s(" [%s, %lf], ", dogs[i].name, dogs[i].kg);
    }
    printf_s("}\n");
}