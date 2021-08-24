#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

/**
 * @file Calculator
*/

/**
 * @brief Contains the two values that compose a complex number.
*/
typedef struct Complex_t
{
    float real;
    float imaginary;
} Complex;

/**
 * @brief Number is either a real number or a complex number.
*/
typedef union Number_t
{
    double real;
    Complex complex;
} Number;

/**
 * @brief Enumeration of the available operations.
*/
typedef enum Operation_t
{
    exit,
    add,
    subtract,
    multiply,
    divide
} Operation;

/**
 * @brief Reads a number from the user.
 * 
 * @param numType character reparesenting if the number is real or complex
 *
 * @return the user's number 
*/
Number ReadNumber(char numType);

/**
 * @brief Reads a double from the user.
 *
 * @return the user's number
*/
double ReadDouble(void);

/**
 * @brief Reads a float from the user.
 *
 * @return the user's number
*/
float ReadFloat(void);

/**
 * @brief Reads an operation from the user.
 *  
 * @return the user's operation
*/
Operation ReadOperation(void);

/**
 *  @brief Runs a basic calculator.
*/
void Calculator(void);

/**
 * @brief Calculates an operation between two real numbers.
 * 
 * @param operation the operation being performed
 * @param operand1 the first operand
 * @param operand2 the second operand
 * 
 * @return the result
*/
Number CalculateTwoReals(Operation operation, Number operand1, Number operand2);

/**
 * @brief Calculates an operation between a real and complex number.
 *
 * @param operation the operation being performed
 * @param operand1 the first operand
 * @param operand2 the second operand
 *
 * @return the result
*/
Number CalculateRealAndComplex(Operation operation, Number operand1, Number operand2);

/**
 * @brief Calculates an operation between a complex and real number.
 *
 * @param operation the operation being performed
 * @param operand1 the first operand
 * @param operand2 the second operand
 *
 * @return the result
*/
Number CalculateComplexAndReal(Operation operation, Number operand1, Number operand2);

/**
 * @brief Calculates an operation between two complex numbers.
 *
 * @param operation the operation being performed
 * @param operand1 the first operand
 * @param operand2 the second operand
 *
 * @return the result
*/
Number CalculateTwoComplexes(Operation operation, Number operand1, Number operand2);

#endif
