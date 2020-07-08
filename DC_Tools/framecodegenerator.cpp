#include "framecodegenerator.h"

FrameCodeGenerator::FrameCodeGenerator(QString &data, QString &protection, QWidget *parent = 0) : QDialog(parent)
{
    QSettings settings("Exiel", "DC_Tools");

    resize(1000, 1000);

    bool ProtectionCheck = settings.value("Protection/ProtectionCheck").toBool();

    Data = new QTextEdit;
    ProtectionData = new QTextEdit;
    QPushButton *saveButton = new QPushButton("Enregistrer Sous...");
    QPushButton *exit = new QPushButton("Fermer");
    QVBoxLayout *mainLayout = new QVBoxLayout;

    Data->setPlainText(data);
    Data->setReadOnly(true);
    Data->setFont(QFont("Courier"));
    Data->setLineWrapMode(QTextEdit::NoWrap);

    //Check if Protection is Active
        if(ProtectionCheck){
            ProtectionData->setPlainText(protection);
            ProtectionData->setReadOnly(true);
            ProtectionData->setFont(QFont("Courier"));
            ProtectionData->setLineWrapMode(QTextEdit::NoWrap);

            mainLayout->addWidget(ProtectionData);
        }

    mainLayout->addWidget(Data);
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(exit);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(exit, SIGNAL(clicked()), this, SLOT(accept()));

    setLayout(mainLayout);
}

void FrameCodeGenerator::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                tr("Text Files (*.txt)"));

            if (fileName != "") {
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)) {
                    QMessageBox::critical(this, tr("Error"),
                                        tr("Impossible d'enregistrer le fichier."));
                                    return;
                } else {
                    QTextStream stream(&file);
                    stream.setCodec("UTF-8");
                    stream << ProtectionData->toPlainText();
                    stream << Data->toPlainText();
                    stream.flush();
                    file.close();
                }
            }
}
