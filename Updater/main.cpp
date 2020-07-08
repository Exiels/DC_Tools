/*
 * Project under Apache-2.0 License
 *
 * Apache License
 *
 * Version 2.0, January 2004
 *
 * http://www.apache.org/licenses/
 *
 *    Copyright 2020 Exiel
 *
 * Project DC_Tools created by Exiel
*/

#include <QApplication>

#include "mainframe.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainFrame window;

    //Generating the Window
    window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint );
    window.show();

    return app.exec();
}
