#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QtWidgets>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtXml>
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
    void addCM();
    void addLvl();
    void stateChanged(QString Slvl);


protected :
    QNetworkReply *reply;
    QString version;
    QString versionNew;
    QLabel label;
    void closeEvent(QCloseEvent* event);


    //START_Var_Programs

        QLineEdit *PRG_Main_Name_Line;
        QLineEdit *PRG_Main_Desc_Line;

        QLineEdit *PRG_Desc_Img_Line;
        QTextEdit *PRG_Desc_Desc_Line;

        QLineEdit *PRG_Tech_Aute_Line;
        QLineEdit *PRG_Tech_Desc_Line;
        QLineEdit *PRG_Tech_Auto_Line;
        QLineEdit *PRG_Tech_Inte_Line;
        QLineEdit *PRG_Tech_Vers_Line;
        QLineEdit *PRG_Tech_Acti_Line;
        QLineEdit *PRG_Tech_Util_Line;
        QLineEdit *PRG_Tech_Mate_Line;
        QLineEdit *PRG_Tech_Dure_Line;
        QComboBox *PRG_Tech_Type_Comb;

        QPushButton *PRG_Generate;

    //END_Var_Programs

    //START_Var_Glace

        //START_Var_Glace_Menu
            QTabWidget *mainGL;
            QWidget *principal;
            QWidget *cm;
            QWidget *alerte;
            QWidget *niveau;
        //END_Var_Menu

        //START_Var_Glace_Main
            QLineEdit *GL_Main_Name_Line;
            QLineEdit *GL_Main_Img_Line;
            QLineEdit *GL_Main_Vers_Line;
            QComboBox *GL_Main_Lvl_Line;
            QTextEdit *GL_Main_Desc_Line;
            QLineEdit *GL_Main_Plan_Line;
            QCheckBox *GL_Glace_Check;
        //END_Var_Glace_Main

        //START_Var_Glace_Cm
            //START_Var_Glace_Cm_Main
                QTabWidget *mainCM;
                QWidget *CM1;
                QWidget *CM2;
                QWidget *CM3;
                QWidget *CM4;
                QWidget *CM5;
                QWidget *CM6;
                QWidget *CM7;
                QWidget *CM8;
                QWidget *CM9;
                QWidget *CM10;
                QPushButton *GL_CM_Add_CM;
                int count = 1;
                int glace = 0;
                int glaceon = 0;
            //END_Var_Glace_Cm_Main

            //START_Var_Glace_Cm_Cm1
                QLineEdit *GL_CM1_Name_Line;
                QLineEdit *GL_CM1_Img_Line;
                QComboBox *GL_CM1_Cat_Line;
                QLineEdit *GL_CM1_Comp1_Line;
                QLineEdit *GL_CM1_Comp2_Line;
                QLineEdit *GL_CM1_Comp3_Line;
                QLineEdit *GL_CM1_Alg1_Line;
                QLineEdit *GL_CM1_Alg2_Line;
                QLineEdit *GL_CM1_Alg3_Line;
                QTextEdit *GL_CM1_Desc_Line;
            //END_Var_Glace_Cm_Cm1

            //START_Var_Glace_Cm_Cm2
                QLineEdit *GL_CM2_Name_Line;
                QLineEdit *GL_CM2_Img_Line;
                QComboBox *GL_CM2_Cat_Line;
                QLineEdit *GL_CM2_Comp1_Line;
                QLineEdit *GL_CM2_Comp2_Line;
                QLineEdit *GL_CM2_Comp3_Line;
                QLineEdit *GL_CM2_Alg1_Line;
                QLineEdit *GL_CM2_Alg2_Line;
                QLineEdit *GL_CM2_Alg3_Line;
                QTextEdit *GL_CM2_Desc_Line;
            //END_Var_Glace_Cm_Cm2

            //START_Var_Glace_Cm_Cm3
                QLineEdit *GL_CM3_Name_Line;
                QLineEdit *GL_CM3_Img_Line;
                QComboBox *GL_CM3_Cat_Line;
                QLineEdit *GL_CM3_Comp1_Line;
                QLineEdit *GL_CM3_Comp2_Line;
                QLineEdit *GL_CM3_Comp3_Line;
                QLineEdit *GL_CM3_Alg1_Line;
                QLineEdit *GL_CM3_Alg2_Line;
                QLineEdit *GL_CM3_Alg3_Line;
                QTextEdit *GL_CM3_Desc_Line;
            //END_Var_Glace_Cm_Cm3

            //START_Var_Glace_Cm_Cm4
                QLineEdit *GL_CM4_Name_Line;
                QLineEdit *GL_CM4_Img_Line;
                QComboBox *GL_CM4_Cat_Line;
                QLineEdit *GL_CM4_Comp1_Line;
                QLineEdit *GL_CM4_Comp2_Line;
                QLineEdit *GL_CM4_Comp3_Line;
                QLineEdit *GL_CM4_Alg1_Line;
                QLineEdit *GL_CM4_Alg2_Line;
                QLineEdit *GL_CM4_Alg3_Line;
                QTextEdit *GL_CM4_Desc_Line;
            //END_Var_Glace_Cm_Cm4

            //START_Var_Glace_Cm_Cm5
                QLineEdit *GL_CM5_Name_Line;
                QLineEdit *GL_CM5_Img_Line;
                QComboBox *GL_CM5_Cat_Line;
                QLineEdit *GL_CM5_Comp1_Line;
                QLineEdit *GL_CM5_Comp2_Line;
                QLineEdit *GL_CM5_Comp3_Line;
                QLineEdit *GL_CM5_Alg1_Line;
                QLineEdit *GL_CM5_Alg2_Line;
                QLineEdit *GL_CM5_Alg3_Line;
                QTextEdit *GL_CM5_Desc_Line;
            //END_Var_Glace_Cm_Cm5

            //START_Var_Glace_Cm_Cm6
                QLineEdit *GL_CM6_Name_Line;
                QLineEdit *GL_CM6_Img_Line;
                QComboBox *GL_CM6_Cat_Line;
                QLineEdit *GL_CM6_Comp1_Line;
                QLineEdit *GL_CM6_Comp2_Line;
                QLineEdit *GL_CM6_Comp3_Line;
                QLineEdit *GL_CM6_Alg1_Line;
                QLineEdit *GL_CM6_Alg2_Line;
                QLineEdit *GL_CM6_Alg3_Line;
                QTextEdit *GL_CM6_Desc_Line;
            //END_Var_Glace_Cm_Cm6

            //START_Var_Glace_Cm_Cm7
                QLineEdit *GL_CM7_Name_Line;
                QLineEdit *GL_CM7_Img_Line;
                QComboBox *GL_CM7_Cat_Line;
                QLineEdit *GL_CM7_Comp1_Line;
                QLineEdit *GL_CM7_Comp2_Line;
                QLineEdit *GL_CM7_Comp3_Line;
                QLineEdit *GL_CM7_Alg1_Line;
                QLineEdit *GL_CM7_Alg2_Line;
                QLineEdit *GL_CM7_Alg3_Line;
                QTextEdit *GL_CM7_Desc_Line;
            //END_Var_Glace_Cm_Cm7

            //START_Var_Glace_Cm_Cm8
                QLineEdit *GL_CM8_Name_Line;
                QLineEdit *GL_CM8_Img_Line;
                QComboBox *GL_CM8_Cat_Line;
                QLineEdit *GL_CM8_Comp1_Line;
                QLineEdit *GL_CM8_Comp2_Line;
                QLineEdit *GL_CM8_Comp3_Line;
                QLineEdit *GL_CM8_Alg1_Line;
                QLineEdit *GL_CM8_Alg2_Line;
                QLineEdit *GL_CM8_Alg3_Line;
                QTextEdit *GL_CM8_Desc_Line;
            //END_Var_Glace_Cm_Cm8

            //START_Var_Glace_Cm_Cm9
                QLineEdit *GL_CM9_Name_Line;
                QLineEdit *GL_CM9_Img_Line;
                QComboBox *GL_CM9_Cat_Line;
                QLineEdit *GL_CM9_Comp1_Line;
                QLineEdit *GL_CM9_Comp2_Line;
                QLineEdit *GL_CM9_Comp3_Line;
                QLineEdit *GL_CM9_Alg1_Line;
                QLineEdit *GL_CM9_Alg2_Line;
                QLineEdit *GL_CM9_Alg3_Line;
                QTextEdit *GL_CM9_Desc_Line;
            //END_Var_Glace_Cm_Cm9

            //START_Var_Glace_Cm_Cm10
                QLineEdit *GL_CM10_Name_Line;
                QLineEdit *GL_CM10_Img_Line;
                QComboBox *GL_CM10_Cat_Line;
                QLineEdit *GL_CM10_Comp1_Line;
                QLineEdit *GL_CM10_Comp2_Line;
                QLineEdit *GL_CM10_Comp3_Line;
                QLineEdit *GL_CM10_Alg1_Line;
                QLineEdit *GL_CM10_Alg2_Line;
                QLineEdit *GL_CM10_Alg3_Line;
                QTextEdit *GL_CM10_Desc_Line;
            //END_Var_Glace_Cm_Cm10
        //END_Var_Glace_Cm

        //START_Var_Glace_Alerte
                QLabel *GL_CM_Lab1_Line;
                QLabel *GL_CM_Lab2_Line;
                QLabel *GL_CM_Lab3_Line;
                QLineEdit *GL_CM_NAlrt1_Line;
                QLineEdit *GL_CM_NAlrt2_Line;
                QLineEdit *GL_CM_NAlrt3_Line;
                QLineEdit *GL_CM_FAlrt1_Line;
                QLineEdit *GL_CM_FAlrt2_Line;
                QLineEdit *GL_CM_FAlrt3_Line;
                QLineEdit *GL_CM_HAlrt1_Line;
                QLineEdit *GL_CM_HAlrt2_Line;
                QLineEdit *GL_CM_HAlrt3_Line;
        //END_Var_Glace_Alerte

        //START_Var_Glace_Level
            //START_Var_Glace_Level_Main
                QTabWidget *mainLvl;
                QWidget *Lvl1;
                QWidget *Lvl2;
                QWidget *Lvl3;
                QWidget *Lvl4;
                QWidget *Lvl5;
                QFormLayout *L_Lvl1;
                QPushButton *GL_Lvl_Add_Lvl;
                int countL = 1;
            //END_Var_Glace_Level_Main

            //START_Var_Glace_Level_Lvl1
                QGridLayout *GL_Lvl1;
                QLabel *GL_LVl1_LImg1_Line;
                QLabel *GL_LVl1_LSpacer1_Line;
                QLabel *GL_LVl1_LSpacer2_Line;
                QLabel *GL_LVl1_LSpacer3_Line;
                QLabel *GL_LVl1_LCM1_Line;
                QLabel *GL_LVl1_LCM2_Line;
                QLabel *GL_LVl1_LCM3_Line;
                QLabel *GL_LVl1_LCM4_Line;
                QLabel *GL_LVl1_LCM5_Line;
                QLabel *GL_LVl1_LDesc_Line;
                QLabel *GL_LVl1_LImg2_Line;
                QLineEdit *GL_Lvl1_CM1_Line;
                QLineEdit *GL_Lvl1_CM2_Line;
                QLineEdit *GL_Lvl1_CM3_Line;
                QLineEdit *GL_Lvl1_CM4_Line;
                QLineEdit *GL_Lvl1_CM5_Line;
                QLineEdit *GL_LVl1_Nbr1_Line;
                QLineEdit *GL_LVl1_Img1_Line;
                QTextEdit *GL_LVl1_Desc1_Line;
                QLineEdit *GL_LVl1_PImg1_Line;
            //END_Var_Glace_Level_Lvl1

            //START_Var_Glace_Level_Lvl2
                QLabel *GL_LVl2_LImg1_Line;
                QLabel *GL_LVl2_LSpacer1_Line;
                QLabel *GL_LVl2_LSpacer2_Line;
                QLabel *GL_LVl2_LSpacer3_Line;
                QLabel *GL_LVl2_LCM1_Line;
                QLabel *GL_LVl2_LCM2_Line;
                QLabel *GL_LVl2_LCM3_Line;
                QLabel *GL_LVl2_LCM4_Line;
                QLabel *GL_LVl2_LCM5_Line;
                QLabel *GL_LVl2_LDesc_Line;
                QLabel *GL_LVl2_LImg2_Line;
                QLineEdit *GL_Lvl2_CM1_Line;
                QLineEdit *GL_Lvl2_CM2_Line;
                QLineEdit *GL_Lvl2_CM3_Line;
                QLineEdit *GL_Lvl2_CM4_Line;
                QLineEdit *GL_Lvl2_CM5_Line;
                QLineEdit *GL_LVl2_Nbr1_Line;
                QLineEdit *GL_LVl2_Img1_Line;
                QTextEdit *GL_LVl2_Desc1_Line;
                QLineEdit *GL_LVl2_PImg1_Line;
            //END_Var_Glace_Level_Lvl2

            //START_Var_Glace_Level_Lvl3
                QLabel *GL_LVl3_LImg1_Line;
                QLabel *GL_LVl3_LSpacer1_Line;
                QLabel *GL_LVl3_LSpacer2_Line;
                QLabel *GL_LVl3_LSpacer3_Line;
                QLabel *GL_LVl3_LCM1_Line;
                QLabel *GL_LVl3_LCM2_Line;
                QLabel *GL_LVl3_LCM3_Line;
                QLabel *GL_LVl3_LCM4_Line;
                QLabel *GL_LVl3_LCM5_Line;
                QLabel *GL_LVl3_LDesc_Line;
                QLabel *GL_LVl3_LImg2_Line;
                QLineEdit *GL_Lvl3_CM1_Line;
                QLineEdit *GL_Lvl3_CM2_Line;
                QLineEdit *GL_Lvl3_CM3_Line;
                QLineEdit *GL_Lvl3_CM4_Line;
                QLineEdit *GL_Lvl3_CM5_Line;
                QLineEdit *GL_LVl3_Nbr1_Line;
                QLineEdit *GL_LVl3_Img1_Line;
                QTextEdit *GL_LVl3_Desc1_Line;
                QLineEdit *GL_LVl3_PImg1_Line;
            //END_Var_Glace_Level_Lvl3

            //START_Var_Glace_Level_Lvl4
                QLabel *GL_LVl4_LImg1_Line;
                QLabel *GL_LVl4_LSpacer1_Line;
                QLabel *GL_LVl4_LSpacer2_Line;
                QLabel *GL_LVl4_LSpacer3_Line;
                QLabel *GL_LVl4_LCM1_Line;
                QLabel *GL_LVl4_LCM2_Line;
                QLabel *GL_LVl4_LCM3_Line;
                QLabel *GL_LVl4_LCM4_Line;
                QLabel *GL_LVl4_LCM5_Line;
                QLabel *GL_LVl4_LDesc_Line;
                QLabel *GL_LVl4_LImg2_Line;
                QLineEdit *GL_Lvl4_CM1_Line;
                QLineEdit *GL_Lvl4_CM2_Line;
                QLineEdit *GL_Lvl4_CM3_Line;
                QLineEdit *GL_Lvl4_CM4_Line;
                QLineEdit *GL_Lvl4_CM5_Line;
                QLineEdit *GL_LVl4_Nbr1_Line;
                QLineEdit *GL_LVl4_Img1_Line;
                QTextEdit *GL_LVl4_Desc1_Line;
                QLineEdit *GL_LVl4_PImg1_Line;
            //END_Var_Glace_Level_Lvl4

            //START_Var_Glace_Level_Lvl5
                QLabel *GL_LVl5_LImg1_Line;
                QLabel *GL_LVl5_LSpacer1_Line;
                QLabel *GL_LVl5_LSpacer2_Line;
                QLabel *GL_LVl5_LSpacer3_Line;
                QLabel *GL_LVl5_LCM1_Line;
                QLabel *GL_LVl5_LCM2_Line;
                QLabel *GL_LVl5_LCM3_Line;
                QLabel *GL_LVl5_LCM4_Line;
                QLabel *GL_LVl5_LCM5_Line;
                QLabel *GL_LVl5_LDesc_Line;
                QLabel *GL_LVl5_LImg2_Line;
                QLineEdit *GL_Lvl5_CM1_Line;
                QLineEdit *GL_Lvl5_CM2_Line;
                QLineEdit *GL_Lvl5_CM3_Line;
                QLineEdit *GL_Lvl5_CM4_Line;
                QLineEdit *GL_Lvl5_CM5_Line;
                QLineEdit *GL_LVl5_Nbr1_Line;
                QLineEdit *GL_LVl5_Img1_Line;
                QTextEdit *GL_LVl5_Desc1_Line;
                QLineEdit *GL_LVl5_PImg1_Line;
            //END_Var_Glace_Level_Lvl5

        //Page IA

        QLabel *PR_Importer_IA;

    //FIN_Attributs Glace

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

        QPushButton *IA_Generate;
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
