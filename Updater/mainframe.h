#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QApplication>
#include <QtWidgets>
#include <QIcon>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDesktopServices>
#include <QProcess>
#include "JlCompress.h"




class MainFrame : public QDialog
{

    Q_OBJECT
public:
        MainFrame();
private:
        QNetworkReply *reply;
        QNetworkAccessManager manager;
public slots:
        void enregistrer();
        void downloadProgress(qint64 ist, qint64 max);
protected:
        QProgressBar *pBar;
};

#endif // MAINFRAME_H
