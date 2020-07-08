#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QtWidgets>
#include <QtNetwork>
#include "mainframe.h"



class Authenticator : public QDialog
{
    Q_OBJECT
public:
    Authenticator();

public slots:
    void Login();

private:

    //Var Authenticator()
        QString version;

        QNetworkReply *Updater_Reply;
        QString Updater_Server_Version;

        QLineEdit *Username;
        QLineEdit *Password;
        QLabel *Logo;

    //Var Login()
        QString UsernameLogin;
        QString PasswordLogin;
};

#endif // AUTHENTICATOR_H
