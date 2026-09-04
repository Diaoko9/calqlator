#include "MathEngine.h"

double MathEngine::calculate(double operand1, double operand2, Operator op) const {
    switch (op) {
    case Operator::Add: return operand1 + operand2;
    case Operator::Subtract: return operand1 - operand2;
    case Operator::Multiply: return operand1 * operand2;
    case Operator::Divide:
        return (operand2 != 0.0) ? (operand1 / operand2) : 0.0;
    default: return operand2;
    }
}
