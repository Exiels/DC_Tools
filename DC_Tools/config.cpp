#include "config.h"

Config::Config() : QDialog()
{
    QSettings settings("Exiel", "DC_Tools");

    resize(600, 500);

    QVBoxLayout *Config_MainLayout = new QVBoxLayout;

    Config_Tab = new QTabWidget(this);
    Config_Protection_Page = new QWidget;
    Config_Template_Page = new QWidget;
    Config_Other_Page = new QWidget;
    Config_About_Page = new QWidget;

    //Template DIR's
        QDirIterator Protection_Dir("template/protection", QStringList() << "*.pouik", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        QStringList Protection_FileList;
        while(Protection_Dir.hasNext())
        {
            Protection_FileList << Protection_Dir.next();
        }

        QDirIterator Program_Dir("template/programme", QStringList() << "*.pouik", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        QStringList Program_FileList;
        while(Program_Dir.hasNext())
        {
            Program_FileList << Program_Dir.next();
        }

        QDirIterator Glace_Dir("template/glace", QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        QStringList Glace_FileList;
        while(Glace_Dir.hasNext())
        {
            Glace_FileList << Glace_Dir.next();
        }

        QDirIterator Ai_Dir("template/ia", QStringList() << "*.pouik", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        QStringList Ai_FileList;
        while(Ai_Dir.hasNext())
        {
            Ai_FileList << Ai_Dir.next();
        }

    //Protection Page
        Config_Prot_Name = new QLineEdit;
        Config_Prot_Name->setText(settings.value("Protection/Name").toString());
        Config_Prot_Vers = new QLineEdit;
        Config_Prot_Vers->setText(settings.value("Protection/Version").toString());
        Config_Prot_GlaceName = new QLineEdit;
        Config_Prot_GlaceName->setText(settings.value("Protection/NameGlace").toString());
        Config_Prot_GlaceLink = new QLineEdit;
        Config_Prot_GlaceLink->setText(settings.value("Protection/UrlGlace").toString());
        Config_Prot_Read = new QLineEdit;
        Config_Prot_Read->setText(settings.value("Protection/Read").toString());
        Config_Prot_Write = new QLineEdit;
        Config_Prot_Write->setText(settings.value("Protection/Write").toString());
        Config_Prot_Mod = new QLineEdit;
        Config_Prot_Mod->setText(settings.value("Protection/Moderator").toString());
        Config_Prot_Admin = new QLineEdit;
        Config_Prot_Admin->setText(settings.value("Protection/Administrator").toString());
        Config_Prot_Template = new QLabel;
        Config_Prot_Template->setText(" " + settings.value("Protection/TemplateProtection").toString());
        Config_Prot_NewTemplate = new QComboBox;
        Config_Prot_NewTemplate->addItems(Protection_FileList);
        Config_Prot_ProtectionCheck = new QCheckBox;
        Config_Prot_ProtectionCheck->setChecked(settings.value("Protection/ProtectionCheck").toBool());

        //Protection Page Layout
            QFormLayout *Config_Prot_Layout = new QFormLayout;
            Config_Prot_Layout->addRow("&Nom :", Config_Prot_Name);
            Config_Prot_Layout->addRow("&Version :", Config_Prot_Vers);
            Config_Prot_Layout->addRow("&Nom GLACE Protection :", Config_Prot_GlaceName);
            Config_Prot_Layout->addRow("&Lien GLACE Protection :", Config_Prot_GlaceLink);
            Config_Prot_Layout->addRow("&Lecture :", Config_Prot_Read);
            Config_Prot_Layout->addRow("&Ecriture :", Config_Prot_Write);
            Config_Prot_Layout->addRow("&Modération :", Config_Prot_Mod);
            Config_Prot_Layout->addRow("&Administration :", Config_Prot_Admin);
            Config_Prot_Layout->addRow("Template Protection Actuel :", Config_Prot_Template);
            Config_Prot_Layout->addRow("Template Protection :",Config_Prot_NewTemplate);
            Config_Prot_Layout->addRow("Activer Protection ?", Config_Prot_ProtectionCheck);

        QGroupBox *Config_Prot_GroupBox = new QGroupBox;
        Config_Prot_GroupBox->setLayout(Config_Prot_Layout);

        QVBoxLayout *Config_Prot_VLayout = new QVBoxLayout;
        Config_Prot_VLayout->addWidget(Config_Prot_GroupBox);

        Config_Protection_Page->setLayout(Config_Prot_VLayout);

    //Template Page
        Config_Template_Program = new QLabel;
        Config_Template_Program->setText(" " + settings.value("Configuration/TemplateProgram").toString());
        Config_Template_Glace = new QLabel;
        Config_Template_Glace->setText(" " + settings.value("Configuration/TemplateGlace").toString());
        Config_Template_Ai = new QLabel;
        Config_Template_Ai->setText(" " + settings.value("Configuration/TemplateAi").toString());
        Config_Template_NewProgram = new QComboBox;
        Config_Template_NewProgram->addItems(Program_FileList);
        Config_Template_NewGlace = new QComboBox;
        Config_Template_NewGlace->addItems(Glace_FileList);
        Config_Template_NewAi = new QComboBox;
        Config_Template_NewAi->addItems(Ai_FileList);

        //Template Page Layout
            QFormLayout *Config_Template_Layout = new QFormLayout;
            Config_Template_Layout->addRow("Template Programme Actuel :", Config_Template_Program);
            Config_Template_Layout->addRow("Template Programme :",Config_Template_NewProgram);
            Config_Template_Layout->addRow("Template Glace Actuel :", Config_Template_Glace);
            Config_Template_Layout->addRow("Template Glace :", Config_Template_NewGlace);
            Config_Template_Layout->addRow("Template IA Actuel :", Config_Template_Ai);
            Config_Template_Layout->addRow("Template Ia :", Config_Template_NewAi);

        QGroupBox *Config_Template_GroupBox = new QGroupBox;
        Config_Template_GroupBox->setLayout(Config_Template_Layout);

        QVBoxLayout *Config_Template_VLayout = new QVBoxLayout;
        Config_Template_VLayout->addWidget(Config_Template_GroupBox);

        Config_Template_Page->setLayout(Config_Template_VLayout);

    //Other Page
        Config_Other_Name = new QLineEdit;
        Config_Other_Name->setText(settings.value("Configuration/Auteur").toString());
        Config_Other_Mate = new QLineEdit;
        Config_Other_Mate->setText(settings.value("Configuration/Materiel").toString());

        //Other Page Layout
            QFormLayout *Config_Other_Layout = new QFormLayout;
            Config_Other_Layout->addRow("&Auteur + ID :", Config_Other_Name);
            Config_Other_Layout->addRow("&Matériel Hôte :", Config_Other_Mate);

        QGroupBox *Config_Other_GroupBox = new QGroupBox;
        Config_Other_GroupBox->setLayout(Config_Other_Layout);

        QVBoxLayout *Config_OtherVLayout = new QVBoxLayout;
        Config_OtherVLayout->addWidget(Config_Other_GroupBox);

        Config_Other_Page->setLayout(Config_OtherVLayout);

    //About Page
        Config_About_Logo = new QLabel;
        Config_About_Logo->setPixmap(QPixmap(":/images/logo"));

        //About Page Layout

        QVBoxLayout *Config_About_VLayout = new QVBoxLayout;
        Config_About_VLayout->setAlignment(Qt::AlignCenter);
        Config_About_VLayout->addWidget(Config_About_Logo);

        Config_About_Page->setLayout(Config_About_VLayout);

    QPushButton *saveButton = new QPushButton("Enregistrer");

    Config_Tab->addTab(Config_Protection_Page, "Protection");
    Config_Tab->addTab(Config_Template_Page, "Template");
    Config_Tab->addTab(Config_Other_Page, "Autres");
    Config_Tab->addTab(Config_About_Page, "A Propos");

    Config_MainLayout->addWidget(Config_Tab);
    Config_MainLayout->addWidget(saveButton);

    setLayout(Config_MainLayout);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
}

void Config::save()
{
    QSettings settings("Exiel", "DC_Tools");

    //Protection Page Save
        settings.setValue("Protection/Name", Config_Prot_Name->text());
        settings.setValue("Protection/Version", Config_Prot_Vers->text());
        settings.setValue("Protection/NameGlace", Config_Prot_GlaceName->text());
        settings.setValue("Protection/UrlGlace", Config_Prot_GlaceLink->text());
        settings.setValue("Protection/Read", Config_Prot_Read->text());
        settings.setValue("Protection/Write", Config_Prot_Write->text());
        settings.setValue("Protection/Moderator", Config_Prot_Mod->text());
        settings.setValue("Protection/Administrator", Config_Prot_Admin->text());
        settings.setValue("Protection/TemplateProtection", Config_Prot_NewTemplate->currentText());
        settings.setValue("Protection/ProtectionCheck", Config_Prot_ProtectionCheck->isChecked());

    //Template Page Save
        settings.setValue("Configuration/TemplateProgram", Config_Template_NewProgram->currentText());
        settings.setValue("Configuration/TemplateGlace", Config_Template_NewGlace->currentText());
        settings.setValue("Configuration/TemplateAi", Config_Template_NewAi->currentText());

    //Other Page Save
        settings.setValue("Configuration/Auteur", Config_Other_Name->text());
        settings.setValue("Configuration/Materiel", Config_Other_Mate->text());

    close();
}
