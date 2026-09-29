# Calqlator

A modern, cross-platform calculator application built with **C++17** and **Qt 6.8.3**.

This project features a highly modular architecture that completely separates the core mathematical logic from the user interface. This ensures the application is highly testable, maintainable, and ready to be deployed across Desktop (Windows, Linux) and Mobile (Android) environments.

## 🏗️ Architecture

The project strictly follows a decoupled design pattern:

* **`MathEngine` (The Brain):** A pure C++ class responsible exclusively for mathematical operations (`Add`, `Subtract`, `Multiply`, `Divide`) and state management. It has zero dependencies on the Qt GUI modules, making it completely reusable for future UI rewrites (e.g., QML/Qt Quick for mobile).


* **`MainWindow` (The Face):** The Qt Widgets interface manages user interaction and styling. It utilizes a `mainwindow.ui` file designed in Qt Designer, strictly separating visual layout from C++ application logic rather than generating grids dynamically in code.

## ✨ Features

* **Modern UI & Styling:** Features a sleek, dark-mode interface styled with Qt Style Sheets (QSS) for a premium look with rounded corners, interactive hover states, and a dedicated Clear (C) button.
* **Clean Encapsulation:** UI components use modern Qt `connect` syntax and the `sender()` function to send raw inputs to the engine without tracking internal math states.
* **Safe Calculations:** Built-in safeguards against common mathematical errors, such as division by zero.


* **Cross-Platform Ready:** Configured via CMake for native builds on Windows and Linux, with pre-configured packaging properties for Android APK/AAB deployment.



## 🛠️ Prerequisites

* **C++ Compiler:** Supporting C++17 (GCC, Clang, or MSVC).


* **Build System:** CMake 3.22 or higher.


* **Framework:** Qt 6.8.3 (Requires the `Core`, `Gui`, and `Widgets` components).



## 🚀 How to Build and Run

### Option 1: Using Qt Creator (Recommended)

1. Clone the repository to your local machine.


2. Open **Qt Creator**, go to **File > Open File or Project...**, and select the `CMakeLists.txt` file from the cloned folder.


3. In the "Configure Project" screen, select your **Desktop Qt 6.8.3** kit and click **Configure Project**.


4. Click the green **Run** button (Play icon) in the bottom-left corner to compile and launch the calculator.



### Option 2: Using the Terminal (Linux / macOS)

1. Clone the repository:


```bash
git clone https://github.com/Diaoko9/calqlator.git
cd calqlator
mkdir build && cd build
cmake ..
cmake --build .
./CalqlatorPro

```
