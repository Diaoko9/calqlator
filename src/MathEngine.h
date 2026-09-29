#ifndef MATHENGINE_H
#define MATHENGINE_H

#include <QString>

class MathEngine {
public:
    // Define the supported operations
    enum Operator {
        NoOp,
        Add,
        Subtract,
        Multiply,
        Divide
    };

    MathEngine();

    // Inputs received from the UI (MainWindow slots)
    void appendDigit(int digit);
    void setOperator(Operator op);
    void calculateResult();
    void clear();

    // Output returned to the UI display screen
    QString getDisplayText() const;

private:
    // All internal state is now safely locked inside the backend
    double currentOperand;
    QString currentDisplay;
    Operator pendingOperator;
    bool waitingForNewOperand;
};

#endif // MATHENGINE_H
