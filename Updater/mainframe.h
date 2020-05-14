#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDesktopServices>
#include <QProcess>
#include "JlCompress.h"




class MainFrame : public QWidget
{

    Q_OBJECT
        public:
            MainFrame();
        private:
            QNetworkReply *reply;
            QNetworkAccessManager manager;
        public slots:
           void enregistrer();
};

#endif // MAINFRAME_H
