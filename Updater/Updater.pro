QUAZIPCODEDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/include/quazip"
QUAZIPLIBDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/lib"
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += \
    mainframe.h
    $${QUAZIPCODEDIR}/*.h
    C:/Users/Samin/Projets/ThirdPartLibrary/unzip/unzip.h

SOURCES += \
    main.cpp \
    mainframe.cpp
    $${QUAZIPCODEDIR}/*.cpp
    $${QUAZIPCODEDIR}/*.c
    C:/Users/Samin/Projets/ThirdPartLibrary/unzip/unzip.c
QT += widgets
QT += network

LIBS += -lz
LIBS += -L$${QUAZIPLIBDIR} -lquazip

RC_ICONS = icone.ico

RESOURCES += \
    resources.qrc
