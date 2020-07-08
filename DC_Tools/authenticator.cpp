#include "authenticator.h"
#include "mainframe.h"

Authenticator::Authenticator() : QDialog()
{
    version = "1.0";

    QNetworkAccessManager Updater_Manager;
    QUrl Updater_Url = QUrl("http://dctools.xyz/DC_Tools/version.txt");
    QTcpSocket Updater_Socket;

    //Connect to the server
    Updater_Socket.connectToHost(Updater_Url.host(), 80);
    if(Updater_Socket.waitForConnected()){
        Updater_Socket.write("HEAD " + Updater_Url.path().toUtf8() + " HTTP/1.1\r\n"
                             "Host: " + Updater_Url.host().toUtf8() + "\r\n\r\n");
        if(Updater_Socket.waitForReadyRead()){
            QByteArray Updater_Bytes = Updater_Socket.readAll();
            //Check if the server is online
            if(Updater_Bytes.contains("200 OK")){
                Updater_Reply = Updater_Manager.get(QNetworkRequest(Updater_Url));
                QEventLoop Updater_Loop;
                QObject::connect(Updater_Reply, SIGNAL(finished()), &Updater_Loop, SLOT(quit()));
                Updater_Loop.exec();
                Updater_Server_Version = Updater_Reply->readAll();
                //Check the server version
                if(version != Updater_Server_Version){
                    QProcess *Updater_Launch = new QProcess(this);
                    Updater_Launch->setProgram("bin/updater.exe");
                    Updater_Launch->startDetached();
                    close();
                }
            }else {
                QMessageBox::information(this, "ERROR", "Le serveur de Mise à Jours/Login est actuellement Hors-Ligne."
                                                        "Mise à Jour/Connection Impossible.");
            }
        }
    }
    Username = new QLineEdit;
    Username->setPlaceholderText("Nom d'Utilisateur");
    Password = new QLineEdit;
    Password->setPlaceholderText("Mot de Passe");
    Password->setEchoMode(QLineEdit::Password);
    QPushButton *Connect = new QPushButton("Se Connecter");
    Logo = new QLabel;
    Logo->setPixmap(QPixmap(":/images/login"));

        QHBoxLayout *Authenticator_LayoutA = new QHBoxLayout;
        Authenticator_LayoutA->setAlignment(Qt::AlignCenter);
        Authenticator_LayoutA->addWidget(Logo);

        QHBoxLayout *Authenticator_LayoutB = new QHBoxLayout;
        Authenticator_LayoutB->addWidget(Username);
        Authenticator_LayoutB->addWidget(Password);

        QVBoxLayout *Authenticator_MainLayout = new QVBoxLayout;
        Authenticator_MainLayout->addLayout(Authenticator_LayoutA);
        Authenticator_MainLayout->addLayout(Authenticator_LayoutB);
        Authenticator_MainLayout->addWidget(Connect);

    connect(Connect, SIGNAL(clicked()), this, SLOT(Login()));

    setLayout(Authenticator_MainLayout);
}

void Authenticator::Login()
{
    UsernameLogin = Username->text();
    PasswordLogin = Password->text();

    QNetworkAccessManager loginManager;

    QUrl loginUrl = QUrl("http://dctools.xyz/DC_Tools/users/" + UsernameLogin + ".txt");

    QTcpSocket loginSocket;
    loginSocket.connectToHost(loginUrl.host(), 80);
    if(loginSocket.waitForConnected()){
        loginSocket.write("HEAD " + loginUrl.path().toUtf8() + " HTTP/1.1\r\n"
                     "Host: " + loginUrl.host().toUtf8() + "\r\n\r\n");
        if(loginSocket.waitForReadyRead()){
            QByteArray bytes = loginSocket.readAll();
            if(bytes.contains("200 OK")){
                Updater_Reply = loginManager.get(QNetworkRequest(loginUrl));
                QEventLoop loopL;
                QObject::connect(Updater_Reply, SIGNAL(finished()), &loopL, SLOT(quit()));
                loopL.exec();
                QString PasswordServer = Updater_Reply->readAll();
                int PasswordServerInt = PasswordServer.toInt();
                int PasswordLoginInt = PasswordLogin.toInt();

                if (PasswordServerInt/5 == PasswordLoginInt/9){
                    MainFrame *fenetre = new MainFrame();
                    fenetre->show();
                    close();
                }else {
                    QMessageBox::information(this, "ERREUR : Connection", "Nom d'Utilisateur ou Mot de passe Invalide.");
                }
            }else {
                QMessageBox::information(this, "ERREUR : Connection", "Nom d'Utilisateur ou Mot de passe Invalide.");
            }
        }
    }else {
        QMessageBox::information(this, "ERREUR : Connection", "Le serveur de Mise à Jours/Login est actuellement Hors-Ligne."
                                                              "Mise à Jour/Connection Impossible.");
    }
}
