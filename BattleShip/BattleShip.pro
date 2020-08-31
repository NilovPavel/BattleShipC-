QT -= gui

TEMPLATE = lib

CONFIG += c++11

SOURCES += \
        Cell.cpp \
        Field.cpp \
        GUI.cpp \
        HumanPlayer.cpp \
        MachinePlayer.cpp \
        Player.cpp \
        Ship.cpp \
        session.cpp

HEADERS += \
    Cell.h \
    ECellType.h \
    Field.h \
    GUI.h \
    HumanPlayer.h \
    IPlayer.h \
    IUserManipulator.h \
    MachinePlayer.h \
    Player.h \
    Ship.h \
    session.h
