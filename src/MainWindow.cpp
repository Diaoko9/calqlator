#include "MainWindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    currentOperand(0.0), pendingOperator(MathEngine::Operator::None), waitingForNewOperand(true)
{
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);

    // 1. Setup the Display
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);

    // Make the display larger and span all 4 columns
    QFont font = display->font();
    font.setPointSize(24);
    display->setFont(font);
    layout->addWidget(display, 0, 0, 1, 4);

    // 2. Generate Number Buttons (1-9)
    for (int i = 1; i <= 9; ++i) {
        QPushButton *btn = new QPushButton(QString::number(i));

        // Calculate grid position (Row 1-3, Col 0-2)
        int row = ((9 - i) / 3) + 1;
        int col = (i - 1) % 3;

        layout->addWidget(btn, row, col);
        connect(btn, &QPushButton::clicked, this, &MainWindow::digitPressed);
    }

    // 3. Add Zero Button
    QPushButton *btn0 = new QPushButton("0");
    layout->addWidget(btn0, 4, 1);
    connect(btn0, &QPushButton::clicked, this, &MainWindow::digitPressed);

    // 4. Generate Operator Buttons
    const QString operators[] = {"/", "*", "-", "+"};
    for (int i = 0; i < 4; ++i) {
        QPushButton *btnOp = new QPushButton(operators[i]);
        layout->addWidget(btnOp, i + 1, 3); // Place in column 3
        connect(btnOp, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    }

    // 5. Add Clear and Equals Buttons
    QPushButton *btnClear = new QPushButton("C");
    QPushButton *btnEq = new QPushButton("=");

    layout->addWidget(btnClear, 4, 0);
    layout->addWidget(btnEq, 4, 2);

    connect(btnClear, &QPushButton::clicked, this, [this]() {
        display->setText("0");
        currentOperand = 0.0;
        pendingOperator = MathEngine::Operator::None;
        waitingForNewOperand = true;
    });
    connect(btnEq, &QPushButton::clicked, this, &MainWindow::equalPressed);

    setCentralWidget(centralWidget);
}

void MainWindow::digitPressed() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    if (waitingForNewOperand) {
        display->clear();
        waitingForNewOperand = false;
    }
    display->setText(display->text() + btn->text());
}

void MainWindow::operatorPressed() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString opText = btn->text();
    currentOperand = display->text().toDouble();
    waitingForNewOperand = true;

    if (opText == "+") pendingOperator = MathEngine::Operator::Add;
    else if (opText == "-") pendingOperator = MathEngine::Operator::Subtract;
    else if (opText == "*") pendingOperator = MathEngine::Operator::Multiply;
    else if (opText == "/") pendingOperator = MathEngine::Operator::Divide;
}

void MainWindow::equalPressed() {
    if (pendingOperator == MathEngine::Operator::None) return;

    double operand2 = display->text().toDouble();
    double result = engine.calculate(currentOperand, operand2, pendingOperator);

    display->setText(QString::number(result, 'g', 12));
    pendingOperator = MathEngine::Operator::None;
    waitingForNewOperand = true;
}
