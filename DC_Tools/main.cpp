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
#include <QtWidgets>
#include "mainframe.h"
#include "authenticator.h"

int main(int argc, char *argv[])
{
    QSettings settings("Exiel", "DC_Tools");
    QString ID = settings.value("Configuration/ID").toString();
    QString IDC = settings.value("Protection/IDC").toString();

    if(ID.isEmpty() or IDC != ID){
        QString IDN;
        const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

        for(int i=0; i<12; ++i){

            quint32 NombreAleatoire = QRandomGenerator::global()->bounded(62);
            IDN += possibleCharacters[NombreAleatoire];
        }

        settings.setValue("Configuration/ID", IDN);
        settings.setValue("Protection/IDC", IDN);
    }

    QApplication app(argc, argv);

    Authenticator authenticate;
    authenticate.setWindowFlags(Qt::Window | Qt::FramelessWindowHint );
    authenticate.show();

    //MainFrame fenetre;
    //fenetre.show();

    return app.exec();
}
