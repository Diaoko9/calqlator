#include "MathEngine.h"

MathEngine::MathEngine() {
    clear(); // Initialize to default state
}

void MathEngine::appendDigit(int digit) {
    if (waitingForNewOperand) {
        currentDisplay = QString::number(digit);
        waitingForNewOperand = false;
    } else {
        // Prevent multiple leading zeros
        if (currentDisplay == "0") {
            currentDisplay = QString::number(digit);
        } else {
            currentDisplay += QString::number(digit);
        }
    }
}

void MathEngine::setOperator(Operator op) {
    // If the user chains operators (e.g., 5 + 5 + ...), calculate the intermediate result
    if (!waitingForNewOperand && pendingOperator != NoOp) {
        calculateResult();
    }

    currentOperand = currentDisplay.toDouble();
    pendingOperator = op;
    waitingForNewOperand = true;
}

void MathEngine::calculateResult() {
    if (pendingOperator == NoOp) {
        return;
    }

    double operand2 = currentDisplay.toDouble();
    double result = 0.0;

    switch (pendingOperator) {
    case Add:
        result = currentOperand + operand2;
        break;
    case Subtract:
        result = currentOperand - operand2;
        break;
    case Multiply:
        result = currentOperand * operand2;
        break;
    case Divide:
        if (operand2 != 0.0) {
            result = currentOperand / operand2;
        } else {
            currentDisplay = "Error";
            waitingForNewOperand = true;
            pendingOperator = NoOp;
            return;
        }
        break;
    default:
        return;
    }

    // Format the result nicely (up to 10 significant digits)
    currentDisplay = QString::number(result, 'g', 10);
    pendingOperator = NoOp;
    waitingForNewOperand = true;
}

void MathEngine::clear() {
    currentOperand = 0.0;
    currentDisplay = "0";
    pendingOperator = NoOp;
    waitingForNewOperand = true;
}

QString MathEngine::getDisplayText() const {
    return currentDisplay;
}
