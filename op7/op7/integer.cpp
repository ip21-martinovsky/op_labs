#include "integer.h"
using namespace System;
using namespace lab7;

Integer::Integer(int value)
{

    Value = value;

}

int Integer::FindGCD(Integer^ other)
{
    int a = Value;
    int b = other->Value;

    if (a <= 0 || b <= 0)
    {
        throw gcnew ArgumentException("����� ������ ���� ����� 0");
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}



