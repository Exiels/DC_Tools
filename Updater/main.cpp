/* Code Par Exiel, 2019 */

#include <QApplication>

#include "mainframe.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainFrame window;

    //Generating the Window
    window.hide();

    return app.exec();
}
