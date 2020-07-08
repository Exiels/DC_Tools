#include "mainframe.h"

MainFrame::MainFrame() : QDialog()
{
    QLabel *logo = new QLabel;
    logo->setPixmap(QPixmap(":/images/update"));
    pBar = new QProgressBar;
    pBar->setTextVisible(true);
    pBar->setAlignment(Qt::AlignCenter);

    QVBoxLayout *MainLayout = new QVBoxLayout;
    MainLayout->setAlignment(Qt::AlignCenter);
    MainLayout->addWidget(logo);
    MainLayout->addWidget(pBar);

    setLayout(MainLayout);

    reply = manager.get(QNetworkRequest(QUrl("https://dctools.xyz/DC_Tools/update.zip")));
    connect(reply, &QNetworkReply::downloadProgress,this, &MainFrame::downloadProgress);
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(enregistrer()));
}

void MainFrame::downloadProgress(qint64 ist, qint64 max)
{
    pBar->setRange(0,max);
    pBar->setValue(ist);
    if(max < 0){

        pBar->hide();
    }
}

void MainFrame::enregistrer()
{
    reply->deleteLater();
    QFile lastversion("update.zip");

    if(lastversion.open(QIODevice::WriteOnly))
    {
        lastversion.write(reply->readAll());
        lastversion.close();
    }
    JlCompress::extractDir("update.zip", "../");
    lastversion.remove();
    QProcess *qUpdater = new QProcess(this);
    qUpdater->setProgram("../DC_Tools.exe");
    qUpdater->startDetached();
    close();
}
