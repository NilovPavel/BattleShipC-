#TEMPLATE = app
CONFIG += console
CONFIG += c++11
#CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += \
        Cui.cpp \
        UserConsole.cpp \
        main.cpp

HEADERS += \
    Cui.h \
    UserConsole.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BattleShipRelease/release -lBattleShip
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BattleShipDebug/debug -lBattleShip

INCLUDEPATH += $$PWD/../BattleShip
DEPENDPATH += $$PWD/../BattleShip
