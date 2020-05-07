#include <QApplication>
#include <QtWidgets>
#include "mainframe.h"
#include "authenticator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Authenticator authenticate;
    authenticate.setWindowFlags(Qt::Tool);
    authenticate.show();

    return app.exec();
}
