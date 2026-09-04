#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MathEngine.h"

class QLineEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void digitPressed();
    void operatorPressed();
    void equalPressed();

private:
    QLineEdit *display;
    MathEngine engine;
    double currentOperand;
    MathEngine::Operator pendingOperator;
    bool waitingForNewOperand;
};

#endif
