#include <malloc.h>
#include <stdio.h>
#include "Dogs.h"

#define NUM_DOGS 4

int main(void)
{    
    Dog *dogs = (Dog *)malloc(NUM_DOGS * sizeof(Dog));
    if (dogs)
    {
        Dog dog1;
        dog1.name = "one";
        dog1.kg = 10;
        dogs[0] = dog1;

        Dog dog2;
        dog2.name = "two";
        dog2.kg = 20;
        dogs[1] = dog2;

        Dog dog3;
        dog3.name = "three";
        dog3.kg = 30;
        dogs[2] = dog3;

        Dog dog4;
        dog4.name = "four";
        dog4.kg = 40;
        dogs[3] = dog4;

        SortByName(dogs, NUM_DOGS);
        printf_s("\n");
        SortBySize(dogs, NUM_DOGS);
    }

    return 0;
}