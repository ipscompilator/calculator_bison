#pragma once

namespace calc 
{

    enum class Operation
    {
        ADD, // +
        SUB, // -
        MUL, // *
        DIV, // /
    };

    class CalcNode
    {
    public:
        CalcNode();
        virtual ~CalcNode() = default;
        virtual double Evaluate() const = 0;
    };

}