#ifndef FRAMECODEGENERATOR_H
#define FRAMECODEGENERATOR_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class FrameCodeGenerator : public QDialog
{

    Q_OBJECT

public:
    FrameCodeGenerator(QString &prg, QString &pro, QWidget *parent);

private slots :
    void save();

private:
    QTextEdit *codeProtection;
    QTextEdit *codeProgramme;
    QPushButton *close;
    QPushButton *saveB;
};

#endif // FRAMECODEGENERATOR_H
