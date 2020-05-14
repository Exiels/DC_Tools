#ifndef UPDATERFRAME_H
#define UPDATERFRAME_H

#include <QWidget>
#include <QProgressBar>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QMessageBox>
#include <QIcon>

class UpdaterFrame: public QWidget
{
    Q_OBJECT
    public:
        UpdaterFrame();
    private:
        QProgressBar *progression;
    public slots:
};

#endif // UPDATERFRAME_H
