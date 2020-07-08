#ifndef FRAMECODEGENERATOR_H
#define FRAMECODEGENERATOR_H

#include <QtWidgets>

class FrameCodeGenerator : public QDialog
{

    Q_OBJECT

public:
    FrameCodeGenerator(QString &data, QString &protection, QWidget *parent);

private slots :
    void save();

private:
    QTextEdit *ProtectionData;
    QTextEdit *Data;
};

#endif // FRAMECODEGENERATOR_H
