#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <iostream>
#include "quazip.h"

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    MainFrame();

private slots:
    void generateCode();
    void generateCodeIa();
    void generateCodeGlace();
    void About();

public slots:
    void newProgram();
    void Program();
    void newGlace();
    void Glace();
    void config();
    void newIa();
    void Ia();
    void updater();
    void uGlaceCm(int etat);
    void uGlaceIa(int etat);


protected :
    QNetworkReply *reply;
    QString version;
    QString versionNew;
    QLabel label;
    void closeEvent(QCloseEvent* event);


    //Attributs newProgram

    QLineEdit *GB_Main_Name_Line;
    QLineEdit *GB_Main_Desc_Line;

    QLineEdit *GB_Desc_Img_Line;
    QTextEdit *GB_Desc_Desc_Line;

    QLineEdit *GB_Tech_Aute_Line;
    QLineEdit *GB_Tech_Desc_Line;
    QLineEdit *GB_Tech_Auto_Line;
    QLineEdit *GB_Tech_Inte_Line;
    QLineEdit *GB_Tech_Vers_Line;
    QLineEdit *GB_Tech_Acti_Line;
    QLineEdit *GB_Tech_Util_Line;
    QLineEdit *GB_Tech_Mate_Line;
    QLineEdit *GB_Tech_Dure_Line;
    QComboBox *GB_Tech_Type_Comb;

    QPushButton *generate;

    //Fin Attributs newProgram

    //DEBUT_Attributs newGlace

        QLineEdit *PR_Name_Line;
        QLineEdit *PR_Img_Line;
        QLineEdit *PR_Vers_Line;
        QComboBox *PR_Niveau_Line;
        QCheckBox *PR_Glace_Check;
        QCheckBox *PR_IA_Check;
        QWidget *G;
        QWidget *I;

        //Page IA

        QPushButton *PR_Importer_IA;

    //FIN_Attributs newGlace

    //DEBUT_Attributs IA

        QLineEdit *IA_Name_Line;
        QLineEdit *IA_Img_Line;
        QTextEdit *IA_Tach_Line;
        QTextEdit *IA_Phys_Line;
        QLineEdit *IA_Phys_Img_Line;
        QTextEdit *IA_Comp_Line;
        QTextEdit *IA_Comb_Line;
        QTextEdit *IA_Desa_Line;

        //Détails Technique
        QComboBox *IA_Natu_line;
        QLineEdit *IA_Home_Line;
        QLineEdit *IA_HomeP_Line;
        QLineEdit *IA_HomeM_Line;
        QTextEdit *IA_Fonc_Line;
        QTextEdit *IA_Hier_Line;
        QTextEdit *IA_Port_Line;
        QTextEdit *IA_Ress_Line;
        QTextEdit *IA_Meth_Line;

    //FIN_Attributs IA

        QString pname;
        QString pmdesc;
        QString purlimg;
        QString pdesc;
        QString pmdescb;
        QString pauto;
        QString pinte;
        QString pvers;
        QString pacti;
        QString putil;
        QString pdutil;

        QString i_p;
        QString i_g;
        QString i_i;
};

#endif // MAINFRAME_H
