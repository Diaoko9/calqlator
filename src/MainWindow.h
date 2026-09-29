#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MathEngine.h"

// 1. Forward declare the auto-generated UI class
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // 2. Add a destructor to clean up the UI pointer

private slots:
    // Keep your slots to catch the button clicks
    void digitPressed();
    void operatorPressed();
    void equalPressed();
    void clearPressed();

private:
    // 3. Replace the manual QLineEdit with the Qt Designer UI pointer
    Ui::MainWindow *ui;

    // 4. Keep your engine instance
    MathEngine engine;

    // (Math state variables have been removed so they can be moved to MathEngine.h)
};

#endif
