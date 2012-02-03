QT += core gui

TARGET = eurobot_simulator_2012
CONFIG += qt
TEMPLATE = app

HEADERS += \
    simulator.h \
    board.h \
    robot.h

SOURCES += \
    main.cpp \
    simulator.cpp \
    board.cpp \
    robot.cpp
