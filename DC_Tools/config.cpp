#include "config.h"

Config::Config() : QDialog()
{

    QDirIterator dirIteratorP("template/programme", QStringList() << "*.cfg", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    QStringList fileListP;
    while(dirIteratorP.hasNext())
    {
        // ...on va au prochain fichier correspondant à notre filtre
        fileListP << dirIteratorP.next();
    }
    QDirIterator dirIteratorPr("template/protection", QStringList() << "*.cfg", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    QStringList fileListPr;
    while(dirIteratorPr.hasNext())
    {
        // ...on va au prochain fichier correspondant à notre filtre
        fileListPr << dirIteratorPr.next();
    }
    QDirIterator dirIteratorIa("template/ia", QStringList() << "*.cfg", QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    QStringList fileListIa;
    while(dirIteratorIa.hasNext())
    {
        // ...on va au prochain fichier correspondant à notre filtre
        fileListIa << dirIteratorIa.next();
    }

    QSettings settings("Exiel", "DC_Tools");
    resize(600, 500);

    CFG_Name_Line = new QLineEdit;
    CFG_Name_Line->setText(settings.value("Configuration/Auteur").toString());
    CFG_Mate_Line = new QLineEdit;
    CFG_Mate_Line->setText(settings.value("Configuration/Materiel").toString());
    templateL = new QLabel;
    templateL->setText(" " + settings.value("Configuration/TemplateP").toString());
    templateC = new QComboBox;
    templateC->addItems(fileListP);
    templatePL = new QLabel;
    templatePL->setText(" " + settings.value("Configuration/TemplatePr").toString());
    templatePC = new QComboBox;
    templatePC->addItems(fileListPr);
    templateIaL = new QLabel;
    templateIaL->setText(" " + settings.value("Configuration/TemplateIa").toString());
    templateIaC = new QComboBox;
    templateIaC->addItems(fileListIa);

    GB_Prot_Name_Line = new QLineEdit;
    GB_Prot_Name_Line->setText(settings.value("Protection/Name").toString());
    GB_Prot_Vers_Line = new QLineEdit;
    GB_Prot_Vers_Line->setText(settings.value("Protection/Version").toString());
    GB_Prot_NaPr_Line = new QLineEdit;
    GB_Prot_NaPr_Line->setText(settings.value("Protection/NameGlace").toString());
    GB_Prot_UrlP_Line = new QLineEdit;
    GB_Prot_UrlP_Line->setText(settings.value("Protection/UrlGlace").toString());
    GB_Prot_Read_Line = new QLineEdit;
    GB_Prot_Read_Line->setText(settings.value("Protection/Read").toString());
    GB_Prot_Writ_Line = new QLineEdit;
    GB_Prot_Writ_Line->setText(settings.value("Protection/Write").toString());
    GB_Prot_Mode_Line = new QLineEdit;
    GB_Prot_Mode_Line->setText(settings.value("Protection/Moderator").toString());
    GB_Prot_Admi_Line = new QLineEdit;
    GB_Prot_Admi_Line->setText(settings.value("Protection/Administrator").toString());


    QFormLayout *protLayout = new QFormLayout;
    protLayout->addRow("&Nom :", GB_Prot_Name_Line);
    protLayout->addRow("&Version :", GB_Prot_Vers_Line);
    protLayout->addRow("&Nom GLACE Protection :", GB_Prot_NaPr_Line);
    protLayout->addRow("&Lien GLACE Protection :", GB_Prot_UrlP_Line);
    protLayout->addRow("&Lecture :", GB_Prot_Read_Line);
    protLayout->addRow("&Ecriture :", GB_Prot_Writ_Line);
    protLayout->addRow("&Modération :", GB_Prot_Mode_Line);
    protLayout->addRow("&Administration :", GB_Prot_Admi_Line);
    protLayout->addRow("Template Protection Actuel :", templatePL);
    protLayout->addRow("Template Protection :",templatePC);

    QGroupBox *GB_Prot = new QGroupBox("Protection EM");
    GB_Prot->setLayout(protLayout);

    save = new QPushButton("Enregistrer");

    QFormLayout *cfgLayout = new QFormLayout;
    cfgLayout->addRow("&Auteur + ID :", CFG_Name_Line);
    cfgLayout->addRow("&Matériel Hôte :", CFG_Mate_Line);
    cfgLayout->addRow("Template Programme Actuel :", templateL);
    cfgLayout->addRow("Template Programme :",templateC);
    cfgLayout->addRow("Template IA Actuel :", templateIaL);
    cfgLayout->addRow("Template Ia :", templateIaC);

    QGroupBox *GB_Cfg = new QGroupBox("Configuration");
    GB_Cfg->setLayout(cfgLayout);

    QVBoxLayout *layoutMainL = new QVBoxLayout;
    layoutMainL->addWidget(GB_Cfg);
    layoutMainL->addWidget(GB_Prot);
    layoutMainL->addWidget(save);

    setLayout(layoutMainL);

    connect(save, SIGNAL(clicked()), this, SLOT(saveS()));
}

void Config::saveS()
{
    QSettings settings("Exiel", "DC_Tools");
    QString name;
    name += CFG_Name_Line->text();
    QString mate;
    mate += CFG_Mate_Line->text();
    QString type;
    type += templateC->currentText();

    QString PName;
    PName += GB_Prot_Name_Line->text();
    QString PVers;
    PVers += GB_Prot_Vers_Line->text();
    QString PNGP;
    PNGP += GB_Prot_NaPr_Line->text();
    QString PLGP;
    PLGP += GB_Prot_UrlP_Line->text();
    QString read;
    read += GB_Prot_Read_Line->text();
    QString writ;
    writ += GB_Prot_Writ_Line->text();
    QString mode;
    mode += GB_Prot_Mode_Line->text();
    QString admi;
    admi += GB_Prot_Admi_Line->text();
    QString typePr;
    typePr += templatePC->currentText();
    QString typeIa;
    typeIa += templateIaC->currentText();

    settings.setValue("Configuration/Auteur", name);
    settings.setValue("Configuration/Materiel", mate);
    settings.setValue("Configuration/TemplateP", type);

    settings.setValue("Protection/Name", PName);
    settings.setValue("Protection/Version", PVers);
    settings.setValue("Protection/NameGlace", PNGP);
    settings.setValue("Protection/UrlGlace", PLGP);
    settings.setValue("Protection/Read", read);
    settings.setValue("Protection/Write", writ);
    settings.setValue("Protection/Moderator", mode);
    settings.setValue("Protection/Administrator", admi);
    settings.setValue("Configuration/TemplatePr", typePr);
    settings.setValue("Configuration/TemplateIa", typeIa);

    QProcess *restart = new QProcess(this);
    restart->startDetached("DC_Tools.exe");
    close();
}

void Config::closeEvent(QCloseEvent* event) {
    //DEBUT_Système de sauvegarde
    QSettings settings("Exiel", "DC_Tools");
        //DEBUT_Save Programme
    QString name;
    name += CFG_Name_Line->text();
    QString mate;
    mate += CFG_Mate_Line->text();
    QString type;
    type += templateC->currentText();

    QString PName;
    PName += GB_Prot_Name_Line->text();
    QString PVers;
    PVers += GB_Prot_Vers_Line->text();
    QString PNGP;
    PNGP += GB_Prot_NaPr_Line->text();
    QString PLGP;
    PLGP += GB_Prot_UrlP_Line->text();
    QString read;
    read += GB_Prot_Read_Line->text();
    QString writ;
    writ += GB_Prot_Writ_Line->text();
    QString mode;
    mode += GB_Prot_Mode_Line->text();
    QString admi;
    admi += GB_Prot_Admi_Line->text();
    QString typePr;
    typePr += templatePC->currentText();
    QString typeIa;
    typeIa += templateIaC->currentText();

    settings.setValue("Configuration/Auteur", name);
    settings.setValue("Configuration/Materiel", mate);
    settings.setValue("Configuration/TemplateP", type);

    settings.setValue("Protection/Name", PName);
    settings.setValue("Protection/Version", PVers);
    settings.setValue("Protection/NameGlace", PNGP);
    settings.setValue("Protection/UrlGlace", PLGP);
    settings.setValue("Protection/Read", read);
    settings.setValue("Protection/Write", writ);
    settings.setValue("Protection/Moderator", mode);
    settings.setValue("Protection/Administrator", admi);
    settings.setValue("Configuration/TemplatePr", typePr);
    settings.setValue("Configuration/TemplateIa", typeIa);

    QProcess *restart = new QProcess(this);
    restart->startDetached("DC_Tools.exe");
    event->accept();
}
