#include "framecodegenerator.h"

FrameCodeGenerator::FrameCodeGenerator(QString &prg, QString &pro, QWidget *parent = 0) : QDialog(parent)
{
    codeProtection = new QTextEdit();
    codeProtection->setPlainText(pro);
    codeProtection->setReadOnly(true);
    codeProtection->setFont(QFont("Courier"));
    codeProtection->setLineWrapMode(QTextEdit::NoWrap);

    codeProgramme = new QTextEdit();
    codeProgramme->setPlainText(prg);
    codeProgramme->setReadOnly(true);
    codeProgramme->setFont(QFont("Courier"));
    codeProgramme->setLineWrapMode(QTextEdit::NoWrap);

    saveB = new QPushButton("Enregistrer Sous..");
    close = new QPushButton("Fermer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeProtection);
    layoutPrincipal->addWidget(codeProgramme);
    layoutPrincipal->addWidget(saveB);
    layoutPrincipal->addWidget(close);

    resize(1000, 1000);
    setLayout(layoutPrincipal);

    connect(saveB, SIGNAL(clicked()), this, SLOT(save()));
    connect(close, SIGNAL(clicked()), this, SLOT(accept()));
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
                    stream << codeProtection->toPlainText();
                    stream << codeProgramme->toPlainText();
                    stream.flush();
                    file.close();
                }
            }
}
