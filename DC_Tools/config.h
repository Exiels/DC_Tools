#ifndef CONFIG_H
#define CONFIG_H

#include <QtWidgets>

class Config : public QDialog
{
    Q_OBJECT

public:
    Config();

private slots :
    void saveS();

protected :
    void closeEvent(QCloseEvent* event);

private:
    QLineEdit *CFG_Name_Line;
    QLineEdit *CFG_Mate_Line;
    QLineEdit *CFG_Prot_Line;
    QLineEdit *CFG_PUrl_Line;

    QLineEdit *GB_Prot_Name_Line;
    QLineEdit *GB_Prot_Vers_Line;
    QLineEdit *GB_Prot_NaPr_Line;
    QLineEdit *GB_Prot_UrlP_Line;
    QLineEdit *GB_Prot_Read_Line;
    QLineEdit *GB_Prot_Writ_Line;
    QLineEdit *GB_Prot_Mode_Line;
    QLineEdit *GB_Prot_Admi_Line;

    QLabel *templateL;
    QLabel *templatePL;
    QLabel *templateIaL;
    QPushButton *save;
    QComboBox *templateC;
    QComboBox *templatePC;
    QComboBox *templateIaC;
};

#endif // CONFIG_H
