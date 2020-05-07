QUAZIPCODEDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/include/quazip"
QUAZIPLIBDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/lib"
INCLUDEPATH += $${QUAZIPCODEDIR}
SOURCES += \
    authenticator.cpp \
    authenticator.cpp \
    config.cpp \
    config.cpp \
    framecodegenerator.cpp \
    framecodegenerator.cpp \
    main.cpp \
    main.cpp \
    mainframe.cpp \
    mainframe.cpp
    $${QUAZIPCODEDIR}/*.cpp
    $${QUAZIPCODEDIR}/*.c


HEADERS += \
    authenticator.h \
    authenticator.h \
    config.h \
    config.h \
    framecodegenerator.h \
    framecodegenerator.h \
    mainframe.h \
    mainframe.h
    $${QUAZIPCODEDIR}/*.h

QT += widgets
QT += network
LIBS += -lz
LIBS += -L$${QUAZIPLIBDIR} -lquazip
