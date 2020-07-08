#ifndef CONFIG_H
#define CONFIG_H

#include <QtWidgets>

class Config : public QDialog
{
    Q_OBJECT

public :
    Config();

private slots :
    void save();

protected :

private:

    //Var Config()
        QTabWidget *Config_Tab;
        QWidget *Config_Protection_Page;
        QWidget *Config_Template_Page;
        QWidget *Config_Other_Page;
        QWidget *Config_About_Page;
        //Protection Page
            QLineEdit *Config_Prot_Name;
            QLineEdit *Config_Prot_Vers;
            QLineEdit *Config_Prot_GlaceName;
            QLineEdit *Config_Prot_GlaceLink;
            QLineEdit *Config_Prot_Read;
            QLineEdit *Config_Prot_Write;
            QLineEdit *Config_Prot_Mod;
            QLineEdit *Config_Prot_Admin;
            QLabel *Config_Prot_Template;
            QComboBox *Config_Prot_NewTemplate;
            QCheckBox *Config_Prot_ProtectionCheck;

        //Template Page
            QLabel *Config_Template_Program;
            QLabel *Config_Template_Glace;
            QLabel *Config_Template_Ai;
            QComboBox *Config_Template_NewProgram;
            QComboBox *Config_Template_NewGlace;
            QComboBox *Config_Template_NewAi;
        //Other Page
            QLineEdit *Config_Other_Name;
            QLineEdit *Config_Other_Mate;
        //About Page
            QLabel *Config_About_Logo;
};

#endif // CONFIG_H
