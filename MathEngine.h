#ifndef MATHENGINE_H
#define MATHENGINE_H

class MathEngine {
public:
    enum class Operator { Add, Subtract, Multiply, Divide, None };
    double calculate(double operand1, double operand2, Operator op) const;
};

#endif