#ifndef _DOGS_H_
#define _DOGS_H_

/*
 * @file Sort Dogs
*/

/**
 * @brief A dog is represented by it's name and size in kilograms.
*/
typedef struct Dog_t
{
    char *name;
    double kg;
} Dog;

/**
 * @brief Sorts an array of dogs by name.
 * 
 * @param dogs an array of dogs
 * @param size size of the array
*/
void SortByName(Dog *dogs, size_t size);

/**
 * @brief Sorts an array of dogs by size.
 * 
 * @param dogs an array of dogs
 * @param size size of the array
*/
void SortBySize(Dog *dogs, size_t size);

/**
 * @brief Compares two dogs by name.
 * 
 * @param dog1 the first dog
 * @param dog2 the second dog
 * 
 * @return an integer reflecting which dog's name has lexicographical precedence ( <0 : dog1 is less, >0 : dog2 is less, 0 : they're equal) 
*/
int NameComparator(Dog *dog1, Dog *dog2);

/**
 * @brief Compares two dogs by size.
 *
 * @param dog1 the first dog
 * @param dog2 the second dog
 *
 * @return a double reflecting which dog weighs more ( <0 : dog1 is less, >0 : dog2 is less, 0 : they're equal) 
*/
double SizeComparator(Dog *dog1, Dog *dog2);

/**
 * @brief Prints the array of dogs, each in the form [name, kg].
 * 
 * @param dogs an array of dogs
 * @param size size of the array
*/
void PrintArray(Dog *dogs, size_t size);

#endif
