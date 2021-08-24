#include <stdio.h>
#include "Calculator.h"

Number ReadNumber(char numType)
{
    Number operand;

    switch (numType)
    {
    case 'r':
        operand.real = ReadDouble();
        break;

    case 'c':
        printf_s("enter the real value: ");
        operand.complex.real = ReadFloat();
        printf_s("enter the imaginary value: ");
        operand.complex.imaginary = ReadFloat();
        break;

    default:
        operand.real = 0;
        break;
    }

    return operand;
}

double ReadDouble(void)
{
    double realNum;
    printf_s("enter a real number: ");
    scanf_s(" %lf", &realNum);
    return realNum;
}

float ReadFloat(void)
{
    float num;
    scanf_s(" %f", &num);
    return num;
}

Operation ReadOperation(void)
{
    Operation op;
    char opType;
    printf_s("Choose an operation: add (a), subtract (s), multiply (m), divide (d), exit (e) ");
    scanf_s(" %c", &opType, 1);
    
    switch (opType)
    {
    case 'a':
        op = add;
        break;

    case 's':
        op = subtract;
        break;

    case 'm':
        op = multiply;
        break;

    case 'd':
        op = divide;
        break;

    case 'e':
        op = exit;
        break;

    default:
        op = exit;
        break;
    }

    return op;
}

void Calculator(void)
{
    char number1Type, number2Type;

    printf_s("Choose a number type: real (r) or complex (c) ");
    scanf_s(" %c", &number1Type, 1);
    Number operand1 = ReadNumber(number1Type);

    Operation operation = ReadOperation();

    while (operation != exit)
    {
        printf_s("Choose a number type: real (r) or complex (c) ");
        scanf_s(" %c", &number2Type, 1);
        Number operand2 = ReadNumber(number2Type);


        Number result;
        result.real = 0;
        if (number1Type == 'r' && number2Type == 'r')
        {
            result = CalculateTwoReals(operation, operand1, operand2);
        }
        else if (number1Type == 'r' && number2Type == 'c')
        {
            result = CalculateRealAndComplex(operation, operand1, operand2);
            number1Type = 'c';
        }
        else if (number1Type == 'c' && number2Type == 'r')
        {
            result = CalculateComplexAndReal(operation, operand1, operand2);
        }
        else if (number1Type == 'c' && number2Type == 'c')
        {
            result = CalculateTwoComplexes(operation, operand1, operand2);
        }
        operand1 = result;
        operation = ReadOperation();
    }
}

Number CalculateTwoReals(Operation operation, Number operand1, Number operand2)
{
    Number result;
    result.real = 0;
    switch (operation)
    {
    case add:
        result.real = operand1.real + operand2.real;
        break;

    case subtract:
        result.real = operand1.real - operand2.real;
        break;

    case multiply:
        result.real = operand1.real * operand2.real;
        break;

    case divide:
        result.real = operand1.real / operand2.real;
        break;

    default:
        result.real = 0;
        break;
    }
    printf_s("result: %lf\n", result.real);
    return result;
}

Number CalculateRealAndComplex(Operation operation, Number operand1, Number operand2)
{
    Number result;
    result.real = 0;
    switch (operation)
    {
    case add:
        result.complex.real = (float)operand1.real + operand2.complex.real;
        result.complex.imaginary = operand2.complex.imaginary;
        break;

    case subtract:
        result.complex.real = (float)operand1.real - operand2.complex.real;
        result.complex.imaginary = -(operand2.complex.imaginary);
        break;

    case multiply:
        result.complex.real = (float)operand1.real * operand2.complex.real;
        result.complex.imaginary = (float)operand1.real * operand2.complex.imaginary;
        break;

    case divide:
        result.complex.real = ((float)operand1.real * operand2.complex.real) /
                              (operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary);
        result.complex.imaginary = ((float)operand1.real * operand2.complex.imaginary) /
                                   (operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary);
        break;

    default:
        result.complex.real = 0;
        result.complex.imaginary = 0;
        break;
    }
    printf_s("result: %f + %fi\n", result.complex.real, result.complex.imaginary);
    return result;
}

Number CalculateComplexAndReal(Operation operation, Number operand1, Number operand2)
{
    Number result;
    result.real = 0;
    switch (operation)
    {
    case add:
        result.complex.real = operand1.complex.real + (float)operand2.real;
        result.complex.imaginary = operand1.complex.imaginary;
        break;

    case subtract:
        result.complex.real = operand1.complex.real - (float)operand2.real;
        result.complex.imaginary = operand1.complex.imaginary;
        break;

    case multiply:
        result.complex.real = operand1.complex.real * (float)operand2.real;
        result.complex.imaginary = operand1.complex.imaginary * (float)operand2.real;
        break;

    case divide:
        result.complex.real = operand1.complex.real / (float)operand2.real;
        result.complex.imaginary = operand1.complex.imaginary / (float)operand2.real;
        break;

    default:
        result.complex.real = 0;
        result.complex.imaginary = 0;
        break;
    }
    printf_s("result: %f + %fi\n", result.complex.real, result.complex.imaginary);
    return result;
}

Number CalculateTwoComplexes(Operation operation, Number operand1, Number operand2)
{
    Number result;
    result.real = 0;
    switch (operation)
    {
    case add:
        result.complex.real = operand1.complex.real + operand2.complex.real;
        result.complex.imaginary = operand1.complex.imaginary + operand2.complex.imaginary;
        break;

    case subtract:
        result.complex.real = operand1.complex.real - operand2.complex.real;
        result.complex.imaginary = operand1.complex.imaginary - operand2.complex.imaginary;
        break;

    case multiply:
        result.complex.real = (operand1.complex.real * operand2.complex.real) + -(operand1.complex.imaginary * operand2.complex.imaginary);
        result.complex.imaginary = (operand1.complex.real * operand2.complex.imaginary) + (operand1.complex.imaginary * operand2.complex.real);
        break;

    case divide:
        result.complex.real = ((operand1.complex.real * operand2.complex.real) + (operand1.complex.imaginary * operand2.complex.imaginary)) /
                              ((operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary));
        result.complex.imaginary = ((operand1.complex.imaginary * operand2.complex.real) - (operand1.complex.real * operand2.complex.imaginary)) /
                                   ((operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary));
        break;

    default:
        result.real = 0;
        break;
    }
    printf_s("result: %f + %fi\n", result.complex.real, result.complex.imaginary);
    return result;
}