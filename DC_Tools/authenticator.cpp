#include "authenticator.h"
#include "mainframe.h"

Authenticator::Authenticator() : QDialog()
{
    //DEBUT_Authenticator
    setWindowTitle("DC_Tools Login");
    setWindowIcon(QIcon("resources/icone.png"));

        Username = new QLineEdit;
        Password = new QLineEdit;
        Password->setEchoMode(QLineEdit::Password);
        Connection = new QPushButton("Se Connecter");

        QFormLayout *LayoutA = new QFormLayout;
        LayoutA->addRow("Username :", Username);
        LayoutA->addRow("Password :", Password);
        LayoutA->addRow(Connection);

        setLayout(LayoutA);

        connect(Connection, SIGNAL(clicked()), this, SLOT(login()));

    //FIN_Authenticator
}

void Authenticator::login()
{
    QString User;
    User += Username->text();
    QString Pass;
    Pass += Password->text();

    QNetworkAccessManager managerA;

    replyA = managerA.get(QNetworkRequest(QUrl("http://dctools.xyz/DC_Tools/users/" + User + ".txt")));
    QEventLoop loopA;
    QObject::connect(replyA, SIGNAL(finished()), &loopA, SLOT(quit()));
    loopA.exec();
    passwrdV = replyA->readAll();
    std::string str = passwrdV.toStdString();
    int passwrdVI = std::stoi(str);
    std::string str1 = Pass.toStdString();
    int passwrdUI = std::stoi(str1);
    if (passwrdVI/5 == passwrdUI/9)
    {
        fenetre = new MainFrame();
        fenetre->show();
        close();
    }
    else
    {
        QMessageBox::warning(this, "ERREUR","Nom d'Utilisateur ou Mot de Passe Invalide");
    }
}
