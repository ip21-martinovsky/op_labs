#pragma once

using namespace System;
namespace lab7 {
    ref class Integer
    {
    private:
        int Value;
    public:
        Integer(int value1);
        int FindGCD(Integer^ other);
    };
}

