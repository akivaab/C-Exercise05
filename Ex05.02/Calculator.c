#include <stdio.h>
#include "Calculator.h"

#define REAL 'r'
#define COMPLEX 'c'
#define ADD 'a'
#define SUB 's'
#define MULT 'm'
#define DIV 'd'
#define EXIT 'e'

Number ReadNumber(char numType)
{
    Number operand;

    switch (numType)
    {
    case REAL:
        operand.real = ReadDouble();
        break;

    case COMPLEX:
        printf_s("enter the real value: ");
        operand.complex.real = ReadFloat();
        printf_s("enter the imaginary value: ");
        operand.complex.imaginary = ReadFloat();
        break;

    default:
        printf_s("Fine, be difficult. We'll just make it zero and call it a day.\n");
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
    case ADD:
        op = add;
        break;

    case SUB:
        op = subtract;
        break;

    case MULT:
        op = multiply;
        break;

    case DIV:
        op = divide;
        break;

    case EXIT:
        op = exit;
        break;

    default:
        printf_s("Fine, be difficult. We'll just go then.\n");
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
        if (number1Type == REAL && number2Type == REAL)
        {
            result = CalculateTwoReals(operation, operand1, operand2);
        }
        else if (number1Type == REAL && number2Type == COMPLEX)
        {
            result = CalculateRealAndComplex(operation, operand1, operand2);
            number1Type = 'c';
        }
        else if (number1Type == COMPLEX && number2Type == REAL)
        {
            result = CalculateComplexAndReal(operation, operand1, operand2);
        }
        else if (number1Type == COMPLEX && number2Type == COMPLEX)
        {
            result = CalculateTwoComplexes(operation, operand1, operand2);
        }
        else
        {
            printf_s("Well you sure made a mess of things.\n");
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
        printf_s("Fine, be difficult. We'll just make it zero and call it a day.\n");
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
                              ((operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary));
        result.complex.imaginary = ((float)operand1.real * operand2.complex.imaginary) /
                                   ((operand2.complex.real * operand2.complex.real) + (operand2.complex.imaginary * operand2.complex.imaginary));
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