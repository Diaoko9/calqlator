cmake_minimum_required(VERSION 3.22)
project(CalqlatorPro VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Require exactly 6.8.3 or newer
find_package(Qt6 6.8.3 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(CalqlatorPro
    main.cpp
    MathEngine.cpp MathEngine.h
    MainWindow.cpp MainWindow.h
)

target_link_libraries(CalqlatorPro PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

# Android deployment packaging
if(ANDROID)
    set_property(TARGET CalqlatorPro APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
endif()

