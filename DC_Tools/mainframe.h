#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QtWidgets>
#include <QtNetwork>

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:

    MainFrame();

private slots:

    void program();
    void glace();
    void ai();
    void updater();
    void config();
    void showMinimized();
    void uniqueIdShow();

    void uGlaceCm(int state);
    void addCm();
    void addLvl();
    void stateChanged(QString stateLvl);

    void generateCodeProgram();
    void generateCodeGlace();
    void generateCodeIa();

private:

    //Var Mainframe()
        QWidget *centralArea;
        QString version;

    //Var Program()
        QLabel *PRG_WindowName;
        //Main Group
            QLineEdit *PRG_Main_Name;
            QLineEdit *PRG_Main_Desc;
        //Description Group
            QLineEdit *PRG_Desc_Img;
            QTextEdit *PRG_Desc_Desc;
        //Technical_Sheet Group
            QLineEdit *PRG_Tech_Auth;
            QLineEdit *PRG_Tech_Desc;
            QLineEdit *PRG_Tech_Auto;
            QLineEdit *PRG_Tech_Inte;
            QLineEdit *PRG_Tech_Vers;
            QLineEdit *PRG_Tech_Acti;
            QLineEdit *PRG_Tech_Util;
            QLineEdit *PRG_Tech_Mate;
            QLineEdit *PRG_Tech_Dure;
            QComboBox *PRG_Tech_Type;
        //Generate Button
            QPushButton *PRG_Generate;

    //Var Glace()
        QLabel *GL_WindowName;
        QTabWidget *GL_Main_Tab;
        QWidget *GL_Main_Page;
        QWidget *GL_Cm_Page;
        QWidget *GL_Alarm_Page;
        QWidget *GL_Lvl_Page;
        //Main Page
            QLineEdit *GL_Main_Name;
            QLineEdit *GL_Main_Img;
            QLineEdit *GL_Main_Vers;
            QTextEdit *GL_Main_Desc;
            QLineEdit *GL_Main_Plan;
            QCheckBox *GL_Main_GlaceCheck;
        //Cm Page
            QTabWidget *GL_Cm_Tab;
            QComboBox *GL_Cm_GLType;
            QPushButton *GL_Cm_AddCM;
            QWidget *Gl_Cm_CM1;
            QWidget *Gl_Cm_CM2;
            QWidget *Gl_Cm_CM3;
            QWidget *Gl_Cm_CM4;
            QWidget *Gl_Cm_CM5;
            QWidget *Gl_Cm_CM6;
            QWidget *Gl_Cm_CM7;
            QWidget *Gl_Cm_CM8;
            QWidget *Gl_Cm_CM9;
            QWidget *Gl_Cm_CM10;
            int GL_Cm_CmCount = 1;
            //CM1
                QLineEdit *GL_Cm_CM1_Name;
                QLineEdit *GL_Cm_CM1_Img;
                QComboBox *GL_Cm_CM1_Cat;
                QLineEdit *GL_Cm_CM1_Comp1;
                QLineEdit *GL_Cm_CM1_Comp2;
                QLineEdit *GL_Cm_CM1_Comp3;
                QLineEdit *GL_Cm_CM1_Alg1;
                QLineEdit *GL_Cm_CM1_Alg2;
                QLineEdit *GL_Cm_CM1_Alg3;
                QTextEdit *GL_Cm_CM1_Desc;

                QLineEdit *GL_Cm_CM2_Name;
                QLineEdit *GL_Cm_CM2_Img;
                QComboBox *GL_Cm_CM2_Cat;
                QLineEdit *GL_Cm_CM2_Comp1;
                QLineEdit *GL_Cm_CM2_Comp2;
                QLineEdit *GL_Cm_CM2_Comp3;
                QLineEdit *GL_Cm_CM2_Alg1;
                QLineEdit *GL_Cm_CM2_Alg2;
                QLineEdit *GL_Cm_CM2_Alg3;
                QTextEdit *GL_Cm_CM2_Desc;

                QLineEdit *GL_Cm_CM3_Name;
                QLineEdit *GL_Cm_CM3_Img;
                QComboBox *GL_Cm_CM3_Cat;
                QLineEdit *GL_Cm_CM3_Comp1;
                QLineEdit *GL_Cm_CM3_Comp2;
                QLineEdit *GL_Cm_CM3_Comp3;
                QLineEdit *GL_Cm_CM3_Alg1;
                QLineEdit *GL_Cm_CM3_Alg2;
                QLineEdit *GL_Cm_CM3_Alg3;
                QTextEdit *GL_Cm_CM3_Desc;

                QLineEdit *GL_Cm_CM4_Name;
                QLineEdit *GL_Cm_CM4_Img;
                QComboBox *GL_Cm_CM4_Cat;
                QLineEdit *GL_Cm_CM4_Comp1;
                QLineEdit *GL_Cm_CM4_Comp2;
                QLineEdit *GL_Cm_CM4_Comp3;
                QLineEdit *GL_Cm_CM4_Alg1;
                QLineEdit *GL_Cm_CM4_Alg2;
                QLineEdit *GL_Cm_CM4_Alg3;
                QTextEdit *GL_Cm_CM4_Desc;

                QLineEdit *GL_Cm_CM5_Name;
                QLineEdit *GL_Cm_CM5_Img;
                QComboBox *GL_Cm_CM5_Cat;
                QLineEdit *GL_Cm_CM5_Comp1;
                QLineEdit *GL_Cm_CM5_Comp2;
                QLineEdit *GL_Cm_CM5_Comp3;
                QLineEdit *GL_Cm_CM5_Alg1;
                QLineEdit *GL_Cm_CM5_Alg2;
                QLineEdit *GL_Cm_CM5_Alg3;
                QTextEdit *GL_Cm_CM5_Desc;

                QLineEdit *GL_Cm_CM6_Name;
                QLineEdit *GL_Cm_CM6_Img;
                QComboBox *GL_Cm_CM6_Cat;
                QLineEdit *GL_Cm_CM6_Comp1;
                QLineEdit *GL_Cm_CM6_Comp2;
                QLineEdit *GL_Cm_CM6_Comp3;
                QLineEdit *GL_Cm_CM6_Alg1;
                QLineEdit *GL_Cm_CM6_Alg2;
                QLineEdit *GL_Cm_CM6_Alg3;
                QTextEdit *GL_Cm_CM6_Desc;

                QLineEdit *GL_Cm_CM7_Name;
                QLineEdit *GL_Cm_CM7_Img;
                QComboBox *GL_Cm_CM7_Cat;
                QLineEdit *GL_Cm_CM7_Comp1;
                QLineEdit *GL_Cm_CM7_Comp2;
                QLineEdit *GL_Cm_CM7_Comp3;
                QLineEdit *GL_Cm_CM7_Alg1;
                QLineEdit *GL_Cm_CM7_Alg2;
                QLineEdit *GL_Cm_CM7_Alg3;
                QTextEdit *GL_Cm_CM7_Desc;

                QLineEdit *GL_Cm_CM8_Name;
                QLineEdit *GL_Cm_CM8_Img;
                QComboBox *GL_Cm_CM8_Cat;
                QLineEdit *GL_Cm_CM8_Comp1;
                QLineEdit *GL_Cm_CM8_Comp2;
                QLineEdit *GL_Cm_CM8_Comp3;
                QLineEdit *GL_Cm_CM8_Alg1;
                QLineEdit *GL_Cm_CM8_Alg2;
                QLineEdit *GL_Cm_CM8_Alg3;
                QTextEdit *GL_Cm_CM8_Desc;

                QLineEdit *GL_Cm_CM9_Name;
                QLineEdit *GL_Cm_CM9_Img;
                QComboBox *GL_Cm_CM9_Cat;
                QLineEdit *GL_Cm_CM9_Comp1;
                QLineEdit *GL_Cm_CM9_Comp2;
                QLineEdit *GL_Cm_CM9_Comp3;
                QLineEdit *GL_Cm_CM9_Alg1;
                QLineEdit *GL_Cm_CM9_Alg2;
                QLineEdit *GL_Cm_CM9_Alg3;
                QTextEdit *GL_Cm_CM9_Desc;

                QLineEdit *GL_Cm_CM10_Name;
                QLineEdit *GL_Cm_CM10_Img;
                QComboBox *GL_Cm_CM10_Cat;
                QLineEdit *GL_Cm_CM10_Comp1;
                QLineEdit *GL_Cm_CM10_Comp2;
                QLineEdit *GL_Cm_CM10_Comp3;
                QLineEdit *GL_Cm_CM10_Alg1;
                QLineEdit *GL_Cm_CM10_Alg2;
                QLineEdit *GL_Cm_CM10_Alg3;
                QTextEdit *GL_Cm_CM10_Desc;
        //Alarm Page
            QLabel *GL_Alarm_Label1;
            QLabel *GL_Alarm_Label2;
            QLabel *GL_Alarm_Label3;
            QLineEdit *GL_Alarm_NoAlarm1;
            QLineEdit *GL_Alarm_NoAlarm2;
            QLineEdit *GL_Alarm_NoAlarm3;
            QLineEdit *GL_Alarm_LowAlarm1;
            QLineEdit *GL_Alarm_LowAlarm2;
            QLineEdit *GL_Alarm_LowAlarm3;
            QLineEdit *GL_Alarm_HighAlarm1;
            QLineEdit *GL_Alarm_HighAlarm2;
            QLineEdit *GL_Alarm_HighAlarm3;
        //Lvl Page
            QTabWidget *GL_Lvl_Tab;
            QWidget *GL_Lvl_Lvl1;
            QWidget *GL_Lvl_Lvl2;
            QWidget *GL_Lvl_Lvl3;
            QWidget *GL_Lvl_Lvl4;
            QWidget *GL_Lvl_Lvl5;
            QPushButton *GL_Lvl_AddLvl;
            int GL_Lvl_LvlCount = 1;
            //Lvl1
                QLineEdit *GL_Lvl_Lvl1_Img;
                QWidget *GL_Lvl_Lvl1_WCM;
                QLineEdit *GL_Lvl_Lvl1_CM1;
                QLineEdit *GL_Lvl_Lvl1_CM2;
                QLineEdit *GL_Lvl_Lvl1_CM3;
                QLineEdit *GL_Lvl_Lvl1_CM4;
                QLineEdit *GL_Lvl_Lvl1_CM5;
                QWidget *GL_Lvl_Lvl1_WNbrCM;
                QWidget *GL_Lvl_Lvl1_Spacer1;
                QWidget *GL_Lvl_Lvl1_Spacer2;
                QLabel *GL_Lvl_Lvl1_LNbrCM1;
                QLabel *GL_Lvl_Lvl1_LNbrCM2;
                QLabel *GL_Lvl_Lvl1_LNbrCM3;
                QLabel *GL_Lvl_Lvl1_LNbrCM4;
                QLabel *GL_Lvl_Lvl1_LNbrCM5;
                QSpinBox *GL_Lvl_Lvl1_NbrCM1;
                QSpinBox *GL_Lvl_Lvl1_NbrCM2;
                QSpinBox *GL_Lvl_Lvl1_NbrCM3;
                QSpinBox *GL_Lvl_Lvl1_NbrCM4;
                QSpinBox *GL_Lvl_Lvl1_NbrCM5;
                QTextEdit *GL_Lvl_Lvl1_Desc;
                QLineEdit *GL_Lvl_Lvl1_PlanImg;
            //Lvl2
                QLineEdit *GL_Lvl_Lvl2_Img;
                QWidget *GL_Lvl_Lvl2_WCM;
                QLineEdit *GL_Lvl_Lvl2_CM1;
                QLineEdit *GL_Lvl_Lvl2_CM2;
                QLineEdit *GL_Lvl_Lvl2_CM3;
                QLineEdit *GL_Lvl_Lvl2_CM4;
                QLineEdit *GL_Lvl_Lvl2_CM5;
                QWidget *GL_Lvl_Lvl2_WNbrCM;
                QWidget *GL_Lvl_Lvl2_Spacer1;
                QWidget *GL_Lvl_Lvl2_Spacer2;
                QLabel *GL_Lvl_Lvl2_LNbrCM1;
                QLabel *GL_Lvl_Lvl2_LNbrCM2;
                QLabel *GL_Lvl_Lvl2_LNbrCM3;
                QLabel *GL_Lvl_Lvl2_LNbrCM4;
                QLabel *GL_Lvl_Lvl2_LNbrCM5;
                QSpinBox *GL_Lvl_Lvl2_NbrCM1;
                QSpinBox *GL_Lvl_Lvl2_NbrCM2;
                QSpinBox *GL_Lvl_Lvl2_NbrCM3;
                QSpinBox *GL_Lvl_Lvl2_NbrCM4;
                QSpinBox *GL_Lvl_Lvl2_NbrCM5;
                QTextEdit *GL_Lvl_Lvl2_Desc;
                QLineEdit *GL_Lvl_Lvl2_PlanImg;
            //Lvl3
                QLineEdit *GL_Lvl_Lvl3_Img;
                QWidget *GL_Lvl_Lvl3_WCM;
                QLineEdit *GL_Lvl_Lvl3_CM1;
                QLineEdit *GL_Lvl_Lvl3_CM2;
                QLineEdit *GL_Lvl_Lvl3_CM3;
                QLineEdit *GL_Lvl_Lvl3_CM4;
                QLineEdit *GL_Lvl_Lvl3_CM5;
                QWidget *GL_Lvl_Lvl3_WNbrCM;
                QWidget *GL_Lvl_Lvl3_Spacer1;
                QWidget *GL_Lvl_Lvl3_Spacer2;
                QLabel *GL_Lvl_Lvl3_LNbrCM1;
                QLabel *GL_Lvl_Lvl3_LNbrCM2;
                QLabel *GL_Lvl_Lvl3_LNbrCM3;
                QLabel *GL_Lvl_Lvl3_LNbrCM4;
                QLabel *GL_Lvl_Lvl3_LNbrCM5;
                QSpinBox *GL_Lvl_Lvl3_NbrCM1;
                QSpinBox *GL_Lvl_Lvl3_NbrCM2;
                QSpinBox *GL_Lvl_Lvl3_NbrCM3;
                QSpinBox *GL_Lvl_Lvl3_NbrCM4;
                QSpinBox *GL_Lvl_Lvl3_NbrCM5;
                QTextEdit *GL_Lvl_Lvl3_Desc;
                QLineEdit *GL_Lvl_Lvl3_PlanImg;
            //Lvl4
                QLineEdit *GL_Lvl_Lvl4_Img;
                QWidget *GL_Lvl_Lvl4_WCM;
                QLineEdit *GL_Lvl_Lvl4_CM1;
                QLineEdit *GL_Lvl_Lvl4_CM2;
                QLineEdit *GL_Lvl_Lvl4_CM3;
                QLineEdit *GL_Lvl_Lvl4_CM4;
                QLineEdit *GL_Lvl_Lvl4_CM5;
                QWidget *GL_Lvl_Lvl4_WNbrCM;
                QWidget *GL_Lvl_Lvl4_Spacer1;
                QWidget *GL_Lvl_Lvl4_Spacer2;
                QLabel *GL_Lvl_Lvl4_LNbrCM1;
                QLabel *GL_Lvl_Lvl4_LNbrCM2;
                QLabel *GL_Lvl_Lvl4_LNbrCM3;
                QLabel *GL_Lvl_Lvl4_LNbrCM4;
                QLabel *GL_Lvl_Lvl4_LNbrCM5;
                QSpinBox *GL_Lvl_Lvl4_NbrCM1;
                QSpinBox *GL_Lvl_Lvl4_NbrCM2;
                QSpinBox *GL_Lvl_Lvl4_NbrCM3;
                QSpinBox *GL_Lvl_Lvl4_NbrCM4;
                QSpinBox *GL_Lvl_Lvl4_NbrCM5;
                QTextEdit *GL_Lvl_Lvl4_Desc;
                QLineEdit *GL_Lvl_Lvl4_PlanImg;
           //Lvl5
                QLineEdit *GL_Lvl_Lvl5_Img;
                QWidget *GL_Lvl_Lvl5_WCM;
                QLineEdit *GL_Lvl_Lvl5_CM1;
                QLineEdit *GL_Lvl_Lvl5_CM2;
                QLineEdit *GL_Lvl_Lvl5_CM3;
                QLineEdit *GL_Lvl_Lvl5_CM4;
                QLineEdit *GL_Lvl_Lvl5_CM5;
                QWidget *GL_Lvl_Lvl5_WNbrCM;
                QWidget *GL_Lvl_Lvl5_Spacer1;
                QWidget *GL_Lvl_Lvl5_Spacer2;
                QLabel *GL_Lvl_Lvl5_LNbrCM1;
                QLabel *GL_Lvl_Lvl5_LNbrCM2;
                QLabel *GL_Lvl_Lvl5_LNbrCM3;
                QLabel *GL_Lvl_Lvl5_LNbrCM4;
                QLabel *GL_Lvl_Lvl5_LNbrCM5;
                QSpinBox *GL_Lvl_Lvl5_NbrCM1;
                QSpinBox *GL_Lvl_Lvl5_NbrCM2;
                QSpinBox *GL_Lvl_Lvl5_NbrCM3;
                QSpinBox *GL_Lvl_Lvl5_NbrCM4;
                QSpinBox *GL_Lvl_Lvl5_NbrCM5;
                QTextEdit *GL_Lvl_Lvl5_Desc;
                QLineEdit *GL_Lvl_Lvl5_PlanImg;

    //Var Ai()
        QLabel *AI_WindowName;
        QTabWidget *AI_Main_Tab;
        QWidget *AI_Main_Page;
        QWidget *AI_Desc_Page;
        QWidget *AI_Tech_Page;
        //Main Page
            QLineEdit *AI_Main_Name;
            QLineEdit *AI_Main_Img;
        //Desc Page
            QTextEdit *AI_Desc_Task;
            QTextEdit *AI_Desc_Phys;
            QLineEdit *AI_Desc_Phys_Img;
            QTextEdit *AI_Desc_Beha;
            QTextEdit *AI_Desc_Fight;
            QTextEdit *AI_Desc_Disa;
        //Tech Page
            QComboBox *AI_Tech_Nature1;
            QComboBox *AI_Tech_Nature2;
            QComboBox *AI_Tech_Nature3;
            QLineEdit *AI_Tech_Home;
            QLineEdit *AI_Tech_HomeP;
            QLineEdit *AI_Tech_HomeM;
            QTextEdit *AI_Tech_Func;
            QTextEdit *AI_Tech_Hier;
            QTextEdit *AI_Tech_Scope;
            QTextEdit *AI_Tech_Ress;
            QTextEdit *AI_Tech_Meth;

    //Var Updater()
        QNetworkReply *Updater_Reply;
        QString Updater_Server_Version;

    //Var uGlaceCM(int etat)
        int Glace_State = 0;

    //Var generateCodeProgram()

};

#endif // MAINFRAME_H
