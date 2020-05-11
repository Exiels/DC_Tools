#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QtWidgets>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mainframe.h"



class Authenticator : public QDialog
{
    Q_OBJECT
public:
    Authenticator();

public slots:
    void login();

protected:
    QNetworkReply *replyA;
    QString passwrdV;

private:

    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *Connection;
    MainFrame *fenetre;
};

#endif // AUTHENTICATOR_H
