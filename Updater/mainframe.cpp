#include "mainframe.h"

MainFrame::MainFrame()
{
    reply = manager.get(QNetworkRequest(QUrl("http://34.89.127.139/temp.zip")));
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(enregistrer()));
}

void MainFrame::enregistrer()
{
    reply->deleteLater();
    QFile lastversion("temp.zip");

    if ( lastversion.open(QIODevice::WriteOnly) )
    {
        lastversion.write(reply->readAll());
        lastversion.close();
    }
    JlCompress::extractDir("temp.zip", "../");
    lastversion.remove();
    QProcess *qUpdater = new QProcess(this);
    qUpdater->startDetached("../DC_Tools.exe");
    close();
}
