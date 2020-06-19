QUAZIPCODEDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/include/quazip"
QUAZIPLIBDIR = "C:/Users/Samin/Projets/ThirdPartLibrary/quazip/lib"
INCLUDEPATH += $${QUAZIPCODEDIR}
SOURCES += \
    authenticator.cpp \
    config.cpp \
    framecodegenerator.cpp \
    main.cpp \
    mainframe.cpp
    $${QUAZIPCODEDIR}/*.cpp
    $${QUAZIPCODEDIR}/*.c


HEADERS += \
    authenticator.h \
    config.h \
    framecodegenerator.h \
    mainframe.h
    $${QUAZIPCODEDIR}/*.h

QT += widgets
QT += network
QT += xml

RC_ICONS = icone.ico

LIBS += -lz
LIBS += -L$${QUAZIPLIBDIR} -lquazip
