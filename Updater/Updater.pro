QUAZIPCODEDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/include/quazip"
QUAZIPLIBDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/lib"
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += \
    mainframe.h \
    mainframe.h \
    updaterframe.h
    $${QUAZIPCODEDIR}/*.h
    C:/Users/Samin/Projets/ThirdPartLibrary/unzip/unzip.h

SOURCES += \
    main.cpp \
    main.cpp \
    mainframe.cpp \
    mainframe.cpp \
    updaterframe.cpp
    $${QUAZIPCODEDIR}/*.cpp
    $${QUAZIPCODEDIR}/*.c
    C:/Users/Samin/Projets/ThirdPartLibrary/unzip/unzip.c
QT += widgets
QT += network

LIBS += -lz
LIBS += -L$${QUAZIPLIBDIR} -lquazip
