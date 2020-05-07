#include "mainframe.h"
#include "framecodegenerator.h"
#include "config.h"
#include "authenticator.h"

using namespace std;

MainFrame::MainFrame()
{
    //DEBUT_Informations
        version = "2.5";
    //FIN_Informations

    //DEBUT_Titre et Icone
        setWindowTitle("DC_Tools V" + version);
        setWindowIcon(QIcon("resources/icone.png"));
    //FIN_Titre et Icone

    QWidget *zoneCentrale = new QWidget;

    resize(500, 500);

        //DEBUT_Création des Menus
            QMenu *menuFichier = menuBar()->addMenu("&Fichier");
            QMenu *menuOptions = menuBar()->addMenu("&Options");
            QMenu *menuAbout = menuBar()->addMenu("&Autres");

            //Menu Fichier : Actions
                QAction *actionNewPrg = menuFichier->addAction("&Nouveau Programme");
                QAction *actionNewGlace = menuFichier->addAction("&Nouvelle GLACE");
                QAction *actionNewIa = menuFichier->addAction("&Nouvelle IA");
                QAction *actionQuit = menuFichier->addAction("&Quitter");
            //Menu Options : Actions
                QAction *actionCfg = menuOptions->addAction("&Config");
                QAction *actionMaj = menuOptions->addAction("Rechercher Mise à Jour");
            //Menu About   : Actions
                QAction *actionAbout = menuAbout->addAction("&À propos");
            //Menu Fichier : Raccourcis
                actionQuit->setShortcut(QKeySequence("Ctrl+Q"));

            //Menu Fichier : Ressources
                actionQuit->setIcon(QIcon("resources/quitter.png"));
                actionNewPrg->setIcon(QIcon("resources/nouveau_prg.png"));
                actionNewGlace->setIcon(QIcon("resources/nouveau_glace.png"));
                actionNewIa->setIcon(QIcon("resources/nouveau_ia.png"));
            //Menu Options : Ressources
                actionCfg->setIcon(QIcon("resources/cfg.png"));
                actionMaj->setIcon(QIcon("resources/maj.png"));
            //Menu About   : Ressources
                actionAbout->setIcon(QIcon("resources/about.png"));
        //FIN_Création des Menus


        //DEBUT_Création de la barre d'outils

            //Espacement
                QWidget *spacer = new QWidget();
                spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            //Ajout de la barre d'outils
                QToolBar *toolBarMain = addToolBar("Main");
                toolBarMain->setMovable(false);
                toolBarMain->setIconSize(QSize(40, 40));

            //Actions à Gauche
                QAction *actionPrg = toolBarMain->addAction("&Programme");
                QAction *actionGlace = toolBarMain->addAction("&GLACE");
                QAction *actionIa = toolBarMain->addAction("&IA");
            //Actions à Droite
                toolBarMain->addWidget(spacer);
                toolBarMain->addAction(actionMaj);
                toolBarMain->addAction(actionCfg);
                toolBarMain->addSeparator();
                toolBarMain->addAction(actionQuit);

            //Ajout des Icones des actions
                actionPrg->setIcon(QIcon("resources/prg.png"));
                actionGlace->setIcon(QIcon("resources/glace.png"));
                actionIa->setIcon(QIcon("resources/ia.png"));
        //FIN_Création de la barre d'outils

        //DEBUT_Signaux
            connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
            connect(actionAbout, SIGNAL(triggered()), this, SLOT(About()));
            connect(actionNewPrg, SIGNAL(triggered()), this, SLOT(newProgram()));
            connect(actionPrg, SIGNAL(triggered()), this, SLOT(Program()));
            connect(actionCfg, SIGNAL(triggered()), this, SLOT(config()));
            connect(actionNewIa, SIGNAL(triggered()), this, SLOT(newIa()));
            connect(actionIa, SIGNAL(triggered()), this, SLOT(Ia()));
            connect(actionNewGlace, SIGNAL(triggered()), this, SLOT(newGlace()));
            connect(actionGlace, SIGNAL(triggered()), this, SLOT(Glace()));
            connect(actionMaj, SIGNAL(triggered()), this, SLOT(updater()));
        //FIN_Signaux

    setCentralWidget(zoneCentrale);

}

void MainFrame::About()
{
    QMessageBox::information(this, tr("A propos..."), tr("DC_Tools est un Logiciel créé par Exiel en 2019."));
}

void MainFrame::Program()
{
    i_p = "i";
    //Importation des Paramètres stocké dans le registre
        QSettings settings("Exiel", "DC_Tools");

    //DEBUT_Groupe Main

        GB_Main_Name_Line = new QLineEdit;
        GB_Main_Name_Line->setText(settings.value("Programme/Nom").toString());
        GB_Main_Desc_Line = new QLineEdit;
        GB_Main_Desc_Line->setText(settings.value("Programme/MiniDescription").toString());

        //Layout Main
            QFormLayout *mainLayout = new QFormLayout;
            mainLayout->addRow("&Nom :", GB_Main_Name_Line);
            mainLayout->addRow("&Description  :", GB_Main_Desc_Line);

        //GroupBox Main
            QGroupBox *GB_Main = new QGroupBox("Principal");
            GB_Main->setLayout(mainLayout);
    //FIN_Groupe Main

    //DEBUT_Groupe Description
        GB_Desc_Img_Line = new QLineEdit;
        GB_Desc_Img_Line->setText(settings.value("Programme/UrlImage").toString());
        GB_Desc_Desc_Line = new QTextEdit;
        GB_Desc_Desc_Line->setText(settings.value("Programme/Description").toString());

        //Layout Description
            QFormLayout *descLayout = new QFormLayout;
            descLayout->addRow("&URL Image :", GB_Desc_Img_Line);
            descLayout->addRow("&Description Complète :", GB_Desc_Desc_Line);

        //GroupBox Description
            QGroupBox *GB_Desc = new QGroupBox("Description");
            GB_Desc->setLayout(descLayout);
    //FIN_Groupe Description

    //DEBUT_Groupe Fiche_Technique
        GB_Tech_Aute_Line = new QLineEdit;
        GB_Tech_Aute_Line->setText(settings.value("Configuration/Auteur").toString());
        GB_Tech_Desc_Line = new QLineEdit;
        GB_Tech_Desc_Line->setText(settings.value("Programme/MiniDescriptionB").toString());
        GB_Tech_Auto_Line = new QLineEdit;
        GB_Tech_Auto_Line->setText(settings.value("Programme/Autorisations").toString());
        GB_Tech_Inte_Line = new QLineEdit;
        GB_Tech_Inte_Line->setText(settings.value("Programme/Interdictions").toString());
        GB_Tech_Vers_Line = new QLineEdit;
        GB_Tech_Vers_Line->setText(settings.value("Programme/Version").toString());
        GB_Tech_Acti_Line = new QLineEdit;
        GB_Tech_Acti_Line->setText(settings.value("Programme/Activation").toString());
        GB_Tech_Util_Line = new QLineEdit;
        GB_Tech_Util_Line->setText(settings.value("Programme/Utilisation").toString());
        GB_Tech_Mate_Line = new QLineEdit;
        GB_Tech_Mate_Line->setText(settings.value("Configuration/Materiel").toString());
        GB_Tech_Dure_Line = new QLineEdit;
        GB_Tech_Dure_Line->setText(settings.value("Programme/DureeUtilisation").toString());

        //ComboBox Fiche_Technique
            GB_Tech_Type_Comb = new QComboBox;
            GB_Tech_Type_Comb->addItem("Pavlov");
            GB_Tech_Type_Comb->addItem("Databomb");
            GB_Tech_Type_Comb->addItem("Killer");
            GB_Tech_Type_Comb->addItem("Crippler");
            GB_Tech_Type_Comb->addItem("Shield");
            GB_Tech_Type_Comb->addItem("Mirror");
            GB_Tech_Type_Comb->addItem("Leurre");
            GB_Tech_Type_Comb->addItem("Cloak");
            GB_Tech_Type_Comb->addItem("Sonde");
            GB_Tech_Type_Comb->addItem("Sniffer");
            GB_Tech_Type_Comb->addItem("Analyseur");
            GB_Tech_Type_Comb->addItem("Booster");
            GB_Tech_Type_Comb->addItem("Assist");
            GB_Tech_Type_Comb->addItem("Overide");
            GB_Tech_Type_Comb->addItem("Purge");

        //Layout Fiche_Technique
            QFormLayout *techLayout = new QFormLayout;
            techLayout->addRow("&Auteur :", GB_Tech_Aute_Line);
            techLayout->addRow("&Type :", GB_Tech_Type_Comb);
            techLayout->addRow("&Description :", GB_Tech_Desc_Line);
            techLayout->addRow("&Autorisations :", GB_Tech_Auto_Line);
            techLayout->addRow("&Interdictions :", GB_Tech_Inte_Line);
            techLayout->addRow("&Version :", GB_Tech_Vers_Line);
            techLayout->addRow("&Activation :", GB_Tech_Acti_Line);
            techLayout->addRow("&Utilisation :", GB_Tech_Util_Line);
            techLayout->addRow("&Matériel Hôte :", GB_Tech_Mate_Line);
            techLayout->addRow("&Durée d'Effet :", GB_Tech_Dure_Line);
        //GroupBox Fiche_Technique
            QGroupBox *GB_Tech = new QGroupBox("Fiche Technique");
            GB_Tech->setLayout(techLayout);
    //FIN_Groupe Fiche_Technique

    //DEBUT_Bouton Générer
        generate = new QPushButton("&Générer !");

        //Layout Bouton Générer
            QHBoxLayout *buttonsLayout = new QHBoxLayout;
            buttonsLayout->setAlignment(Qt::AlignRight);

            buttonsLayout->addWidget(generate);
    //FIN_Bouton Générer


    //DEBUT_Main Layout
        QVBoxLayout *layoutMainL = new QVBoxLayout;
        layoutMainL->addWidget(GB_Main);
        layoutMainL->addWidget(GB_Desc);
        layoutMainL->addWidget(GB_Tech);
        layoutMainL->addLayout(buttonsLayout);

        QWidget *layout = new QWidget();
        layout->setLayout(layoutMainL);
    //FIN_Main Layout

    //DEBUT_Signaux
        connect(generate, SIGNAL(clicked()), this, SLOT(generateCode()));
    //FIN_Signaux

    setCentralWidget(layout);
}

void MainFrame::generateCode()
{
    if (GB_Main_Name_Line->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de programme");
        return; // Arrêt de la méthode
    }
    QSettings settings("Exiel", "DC_Tools");

    QString protection;
    QString programme;

    //DEBUT_Protection
        //Importation du Template Protection
        QString fileNamePr = settings.value("Configuration/TemplatePr").toString();
        QFile fichierPr(fileNamePr);
        fichierPr.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxPr(&fichierPr);
        fluxPr.setCodec("UTF-8");

        //Lecture du Template Protection
        protection = fluxPr.readAll();

        //Remplacement des Variables par les valeurs stocké dans le registre
            protection.replace("PR_Name", settings.value("Protection/Name").toString());
            protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            protection.replace("PR_Read", settings.value("Protection/Read").toString());
            protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());
    //FIN_Protection

    //DEBUT_Programme
        //Importation du Template Programme
        QString fileNameP = settings.value("Configuration/TemplateP").toString();
        QFile fichierP(fileNameP);
        fichierP.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxP(&fichierP);
        fluxP.setCodec("UTF-8");

            //Lecture du Template Programme
            programme = fluxP.readAll();

            //Remplacement des Variables par les valeurs stocké dans le registre
            programme.replace("GB_Desc_Img_Line", GB_Desc_Img_Line->text());
            programme.replace("GB_Main_Name_Line", GB_Main_Name_Line->text());
            programme.replace("GB_Main_Desc_Line", GB_Main_Desc_Line->text());
            programme.replace("GB_Desc_Desc_Line", GB_Desc_Desc_Line->toPlainText());
            programme.replace("GB_Main_Name_Line", GB_Main_Name_Line->text());
            programme.replace("GB_Tech_Aute_Line", GB_Tech_Aute_Line->text());
            programme.replace("GB_Tech_Type_Comb", GB_Tech_Type_Comb->currentText());
            programme.replace("GB_Tech_Desc_Line", GB_Tech_Desc_Line->text());
            programme.replace("GB_Tech_Auto_Line", GB_Tech_Auto_Line->text());
            programme.replace("GB_Tech_Inte_Line", GB_Tech_Inte_Line->text());
            programme.replace("GB_Tech_Vers_Line", GB_Tech_Vers_Line->text());
            programme.replace("GB_Tech_Acti_Line", GB_Tech_Acti_Line->text());
            programme.replace("GB_Tech_Util_Line", GB_Tech_Util_Line->text());
            programme.replace("GB_Tech_Mate_Line", GB_Tech_Mate_Line->text());
            programme.replace("GB_Tech_Dure_Line", GB_Tech_Dure_Line->text());
    //FIN_Programme

    //Envoi des codes à la classe FrameCodeGenerator
    FrameCodeGenerator *fenetreCode = new FrameCodeGenerator(programme, protection, this);
    fenetreCode->exec();
}

void MainFrame::Glace()
{
    //DEBUT_Système de sauvegarde
    QSettings settings("Exiel", "DC_Tools");
        //DEBUT_Save Programme
    if (i_p == "i")
    {
            settings.setValue("Programme/Nom", QString(pname = GB_Main_Name_Line->text()));
            settings.setValue("Programme/MiniDescription", QString(pmdesc = GB_Main_Desc_Line->text()));
            settings.setValue("Programme/UrlImage", QString(purlimg = GB_Desc_Img_Line->text()));
            settings.setValue("Programme/Description", QString(pdesc = GB_Desc_Desc_Line->toPlainText()));
            settings.setValue("Programme/MiniDescriptionB", QString(pmdescb = GB_Tech_Desc_Line->text()));
            settings.setValue("Programme/Autorisations", QString(pauto = GB_Tech_Auto_Line->text()));
            settings.setValue("Programme/Interdictions", QString(pinte = GB_Tech_Inte_Line->text()));
            settings.setValue("Programme/Version", QString(pvers = GB_Tech_Vers_Line->text()));
            settings.setValue("Programme/Activation", QString(pacti = GB_Tech_Acti_Line->text()));
            settings.setValue("Programme/Utilisation", QString(putil = GB_Tech_Util_Line->text()));
            settings.setValue("Programme/DureeUtilisation", QString(pdutil = GB_Tech_Dure_Line->text()));
    }
        //FIN_Save Programme

        //DEBUT_Save IA

        //FIN_Save IA
    //FIN_Système de sauvegarde

    QVBoxLayout *MainLayout = new QVBoxLayout;
    //DEBUT_Onglet Main
        //Création du TabWidget
            QTabWidget *main = new QTabWidget(this);
        //Création des pages
            QWidget *principal = new QWidget;
            QWidget *cm = new QWidget;
            QWidget *alerte = new QWidget;
            QWidget *niveau = new QWidget;
            QWidget *ia = new QWidget;

        //DEBUT_Page Principal
            PR_Name_Line = new QLineEdit;
            PR_Img_Line = new QLineEdit;
            PR_Niveau_Line = new QComboBox;
            PR_Glace_Check = new QCheckBox;
            PR_IA_Check = new QCheckBox;
            PR_Vers_Line = new QLineEdit;

            //Edition de la QComboBox
            PR_Niveau_Line->addItem("Blanche");
            PR_Niveau_Line->addItem("Gris");
            PR_Niveau_Line->addItem("Noire");
            //Layout Page Principal
                QFormLayout *P_main = new QFormLayout;

                P_main->addRow("Nom :", PR_Name_Line);
                P_main->addRow("Url Image :", PR_Img_Line);
                P_main->addRow("Version :", PR_Vers_Line);
                P_main->addRow("GLACE ?", PR_Glace_Check);
                P_main->addRow("IA ?", PR_IA_Check);

            //GroupBox Page Principal
                QGroupBox *GB_Prin = new QGroupBox;
                GB_Prin->setLayout(P_main);

            //Layout Main Page Principal
                QVBoxLayout *PVB_main = new QVBoxLayout;
                PVB_main->addWidget(GB_Prin);

            //Définition du Layout de la Page Principal
                principal->setLayout(PVB_main);
        //FIN_Page Principal

        //DEBUT_Page CM
            PR_Niveau_Line = new QComboBox;

            //Edition de la QComboBox
                    PR_Niveau_Line->addItem("Blanche");
                    PR_Niveau_Line->addItem("Grise");
                    PR_Niveau_Line->addItem("Noire");
            //Layout Page CM

                    QFormLayout *P_CM = new QFormLayout;
                    P_CM->addRow("GLACE :", PR_Niveau_Line);

            //GroupBox Page CM
                    QGroupBox *GB_CM = new QGroupBox;
                    GB_CM->setLayout(P_CM);
                    G = new QWidget;
                    G->setLayout(P_CM);
                    G->hide();
            //Layout Main Page CM
                    QVBoxLayout *PVB_CM = new QVBoxLayout;
                    PVB_CM->addWidget(G);

            //Définition du Layout de la Page Principal
                    cm->setLayout(PVB_CM);
        //FIN_Page CM

        //DEBUT_Page CM
            PR_Importer_IA = new QPushButton;
            //Layout Page CM

                QFormLayout *P_IA = new QFormLayout;
                P_IA->addRow("Importer", PR_Importer_IA);

            //GroupBox Page CM
                QGroupBox *GB_IA = new QGroupBox;
                GB_IA->setLayout(P_IA);
                I = new QWidget;
                I->setLayout(P_IA);
                I->hide();
            //Layout Main Page CM
                QVBoxLayout *PVB_IA = new QVBoxLayout;
                PVB_IA->addWidget(I);

            //Définition du Layout de la Page Principal
                ia->setLayout(PVB_IA);
        //FIN_Page CM

        //Ajout des onglets au TabWidget
            main->addTab(principal, "Principal");
            main->addTab(cm, "Contres-Mesures");
            main->addTab(alerte, "Alertes");
            main->addTab(niveau, "Niveaux");
            main->addTab(ia, "IA");
    //FIN_Onglet Main
    MainLayout->addWidget(main);
    QWidget *layout = new QWidget();
    layout->setLayout(MainLayout);

    //DEBUT_Signaux
        connect(PR_Glace_Check, SIGNAL(stateChanged(int)), this, SLOT(uGlaceCm(int)));
        connect(PR_IA_Check, SIGNAL(stateChanged(int)), this, SLOT(uGlaceIa(int)));
    //FIN_Signaux

    setCentralWidget(layout);

}

void MainFrame::config()
{
    //Execution de la classe Config
    Config *cfg = new Config();
    cfg->exec();
}

void MainFrame::  Ia()
{
    QVBoxLayout *MainLayoutI = new QVBoxLayout;
    //DEBUT_Onglet Main
        QLabel *nameL = new QLabel;
        nameL->setText("IA. Creator");
        //Création du TabWidget
            QTabWidget *mainI = new QTabWidget(this);
        //Création des pages
            QWidget *principal = new QWidget;
            QWidget *description = new QWidget;
            QWidget *detailTech = new QWidget;

        //DEBUT_Page Principal
            //Variables
                IA_Name_Line = new QLineEdit;
                IA_Img_Line = new QLineEdit;
                IA_Tach_Line = new QTextEdit;
                IA_Phys_Line = new QTextEdit;
                IA_Phys_Img_Line = new QLineEdit;
                IA_Comp_Line = new QTextEdit;
                IA_Comb_Line = new QTextEdit;
                IA_Desa_Line = new QTextEdit;
                IA_Home_Line = new QLineEdit;
                IA_HomeP_Line = new QLineEdit;
                IA_HomeM_Line = new QLineEdit;
                IA_Fonc_Line = new QTextEdit;
                IA_Hier_Line = new QTextEdit;
                IA_Port_Line = new QTextEdit;
                IA_Ress_Line = new QTextEdit;
                IA_Meth_Line = new QTextEdit;

                IA_Natu_line = new QComboBox;
                IA_Natu_line->addItem("Faible");
                IA_Natu_line->addItem("Forte");
            //Layout Page IA Principal
                QFormLayout *P_IA_M = new QFormLayout;
                P_IA_M->addRow("Nom :", IA_Name_Line);
                P_IA_M->addRow("Url Image :", IA_Img_Line);
            //GroupBox Page IA Principal
                QGroupBox *GB_IA_M = new QGroupBox("Principal");
                GB_IA_M->setLayout(P_IA_M);
            //Main Layout Page IA Principal
                QVBoxLayout *PVB_IA = new QVBoxLayout;
                PVB_IA->addWidget(GB_IA_M);

            //Layout Page IA Description
                QFormLayout *P_IA_D = new QFormLayout;
                P_IA_D->addRow("Tâche :", IA_Tach_Line);
                P_IA_D->addRow("Physique :", IA_Phys_Line);
                P_IA_D->addRow("Url Apparence :", IA_Phys_Img_Line);
                P_IA_D->addRow("Comportement Général :", IA_Comp_Line);
                P_IA_D->addRow("Combat :", IA_Comb_Line);
                P_IA_D->addRow("Situation de Désavantage :", IA_Desa_Line);

            //GroupBox Page IA Description
                QGroupBox *GB_IA_D = new QGroupBox("Principal");
                GB_IA_D->setLayout(P_IA_D);
            //Main Layout Page IA Description
                QVBoxLayout *PVB_IA_D = new QVBoxLayout;
                PVB_IA_D->addWidget(GB_IA_D);

            //Layout Page IA Détails Techniques
                QFormLayout *P_IA_F = new QFormLayout;
                P_IA_F->addRow("Nature :", IA_Natu_line);
                P_IA_F->addRow("Hébergement :", IA_Home_Line);
                P_IA_F->addRow("Localisation Physique du Coeur :", IA_HomeP_Line);
                P_IA_F->addRow("Localisation Matricielle du Coeur :", IA_HomeM_Line);
                P_IA_F->addRow("Fonctions/Lois :", IA_Fonc_Line);
                P_IA_F->addRow("Hiérarchie des Utilisateurs :", IA_Hier_Line);
                P_IA_F->addRow("Portée d'action de l'IA :", IA_Port_Line);
                P_IA_F->addRow("Ressources :", IA_Ress_Line);
                P_IA_F->addRow("Méthode utilisée pour la conception de l'IA :", IA_Meth_Line);

            //GroupBox Page IA Description
                QGroupBox *GB_IA_F = new QGroupBox("Principal");
                GB_IA_F->setLayout(P_IA_F);
            //Main Layout Page IA Description
                QVBoxLayout *PVB_IA_F = new QVBoxLayout;
                PVB_IA_F->addWidget(GB_IA_F);

            //Définition du Layout de la Page Principal
                principal->setLayout(PVB_IA);
                description->setLayout(PVB_IA_D);
                detailTech->setLayout(PVB_IA_F);

        //FIN_Page IA

        //DEBUT_Bouton Générer
            generate = new QPushButton("&Générer !");

            //Layout Bouton Générer
                QHBoxLayout *buttonsLayout = new QHBoxLayout;
                buttonsLayout->setAlignment(Qt::AlignRight);

                buttonsLayout->addWidget(generate);
        //FIN_Bouton Générer

        //Ajout des onglets au TabWidget
                mainI->addTab(principal, "Principal");
                mainI->addTab(description, "Description");
                mainI->addTab(detailTech, "Détails Techniques");

        MainLayoutI->addWidget(nameL);
        MainLayoutI->addWidget(mainI);
        MainLayoutI->addLayout(buttonsLayout);
        QWidget *layout = new QWidget();
        layout->setLayout(MainLayoutI);

        //DEBUT_Signaux
            connect(generate, SIGNAL(clicked()), this, SLOT(generateCodeIa()));
        //FIN_Signaux

        setCentralWidget(layout);
}

void MainFrame::updater()
{
    //Initialisation du Manager
    QNetworkAccessManager manager;
    //Vérification de la version du serveur
    reply = manager.get(QNetworkRequest(QUrl("http://34.89.127.139/version.txt")));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    versionNew = reply->readAll();
    if (version != versionNew)
    {
        //Lancement de l'updater

        QProcess *qUpdater = new QProcess(this);
        qUpdater->startDetached("bin/updater.exe");
        close();
    }
    else
    {
        QMessageBox::information(this, "Logiciel à jour", "Aucune mise à jours trouvée.");
    }
}

void MainFrame::uGlaceCm(int etat)
{
    if (etat != 0)
    {
        G->show();
    } else if(etat != 2)
    {
        G->hide();
    }
}

void MainFrame::uGlaceIa(int etat)
{
    if (etat != 0)
    {
        I->show();
    } else if(etat != 2)
    {
        I->hide();
    }
}

void MainFrame::newProgram()
{
    MainFrame::Program();
    GB_Main_Name_Line->setText("");
    GB_Main_Desc_Line->setText("");
    GB_Desc_Img_Line->setText("");
    GB_Desc_Desc_Line->setText("");
    GB_Tech_Aute_Line->setText("");
    GB_Tech_Desc_Line->setText("");
    GB_Tech_Auto_Line->setText("");
    GB_Tech_Inte_Line->setText("");
    GB_Tech_Vers_Line->setText("");
    GB_Tech_Acti_Line->setText("");
    GB_Tech_Util_Line->setText("");
    GB_Tech_Mate_Line->setText("");
    GB_Tech_Dure_Line->setText("");
}

void MainFrame::newIa()
{

}

void MainFrame::newGlace()
{

}

void MainFrame::closeEvent(QCloseEvent* event) {
    //DEBUT_Système de sauvegarde
    QSettings settings("Exiel", "DC_Tools");
        //DEBUT_Save Programme
    if (i_p == "i")
    {
            settings.setValue("Programme/Nom", QString(pname = GB_Main_Name_Line->text()));
            settings.setValue("Programme/MiniDescription", QString(pmdesc = GB_Main_Desc_Line->text()));
            settings.setValue("Programme/UrlImage", QString(purlimg = GB_Desc_Img_Line->text()));
            settings.setValue("Programme/Description", QString(pdesc = GB_Desc_Desc_Line->toPlainText()));
            settings.setValue("Programme/MiniDescriptionB", QString(pmdescb = GB_Tech_Desc_Line->text()));
            settings.setValue("Programme/Autorisations", QString(pauto = GB_Tech_Auto_Line->text()));
            settings.setValue("Programme/Interdictions", QString(pinte = GB_Tech_Inte_Line->text()));
            settings.setValue("Programme/Version", QString(pvers = GB_Tech_Vers_Line->text()));
            settings.setValue("Programme/Activation", QString(pacti = GB_Tech_Acti_Line->text()));
            settings.setValue("Programme/Utilisation", QString(putil = GB_Tech_Util_Line->text()));
            settings.setValue("Programme/DureeUtilisation", QString(pdutil = GB_Tech_Dure_Line->text()));
    }   //FIN_Save Programme
    else if (i_g == "i")
    {

    }
    else if (i_i == "i")
    {

    }
    event->accept();
}

void MainFrame::generateCodeIa()
{
    if (IA_Name_Line->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom d'IA");
        return; // Arrêt de la méthode
    }
    QSettings settings("Exiel", "DC_Tools");

    QString protection;
    QString programme;

    //DEBUT_Protection
        //Importation du Template Protection
        QString fileNamePr = settings.value("Configuration/TemplatePr").toString();
        QFile fichierPr(fileNamePr);
        fichierPr.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxPr(&fichierPr);
        fluxPr.setCodec("UTF-8");

        //Lecture du Template Protection
        protection = fluxPr.readAll();

        //Remplacement des Variables par les valeurs stocké dans le registre
            protection.replace("PR_Name", settings.value("Protection/Name").toString());
            protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            protection.replace("PR_Read", settings.value("Protection/Read").toString());
            protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());
    //FIN_Protection

    //DEBUT_Programme
        //Importation du Template Programme
        QString fileNameP = settings.value("Configuration/TemplateIa").toString();
        QFile fichierP(fileNameP);
        fichierP.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxP(&fichierP);
        fluxP.setCodec("UTF-8");

            //Lecture du Template Programme
            programme = fluxP.readAll();

            //Remplacement des Variables par les valeurs stocké dans le registre
            programme.replace("IA_Img_Line", IA_Img_Line->text());
            programme.replace("IA_Name_Line", IA_Name_Line->text());
            programme.replace("IA_Tach_Line", IA_Tach_Line->toPlainText());
            programme.replace("IA_Phys_Line", IA_Phys_Line->toPlainText());
            programme.replace("IA_Phys_Img_Line", IA_Phys_Img_Line->text());
            programme.replace("IA_Comp_Line", IA_Comp_Line->toPlainText());
            programme.replace("IA_Comb_Line", IA_Comb_Line->toPlainText());
            programme.replace("IA_Desa_Line", IA_Desa_Line->toPlainText());
            programme.replace("IA_Natu_line", IA_Natu_line->currentText());
            programme.replace("IA_Home_Line", IA_Home_Line->text());
            programme.replace("IA_HomeP_Line", IA_HomeP_Line->text());
            programme.replace("IA_HomeM_Line", IA_HomeM_Line->text());
            programme.replace("IA_Fonc_Line", IA_Fonc_Line->toPlainText());
            programme.replace("IA_Hier_Line", IA_Hier_Line->toPlainText());
            programme.replace("IA_Port_Line", IA_Port_Line->toPlainText());
            programme.replace("IA_Ress_Line", IA_Ress_Line->toPlainText());
            programme.replace("IA_Meth_Line", IA_Meth_Line->toPlainText());
    //FIN_Programme

    //Envoi des codes à la classe FrameCodeGenerator
    FrameCodeGenerator *fenetreCode = new FrameCodeGenerator(programme, protection, this);
    fenetreCode->exec();
}

void MainFrame::generateCodeGlace()
{
    if (GB_Main_Name_Line->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de programme");
        return; // Arrêt de la méthode
    }
    QSettings settings("Exiel", "DC_Tools");

    QString protection;
    QString programme;

    //DEBUT_Protection
        //Importation du Template Protection
        QString fileNamePr = settings.value("Configuration/TemplatePr").toString();
        QFile fichierPr(fileNamePr);
        fichierPr.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxPr(&fichierPr);
        fluxPr.setCodec("UTF-8");

        //Lecture du Template Protection
        protection = fluxPr.readAll();

        //Remplacement des Variables par les valeurs stocké dans le registre
            protection.replace("PR_Name", settings.value("Protection/Name").toString());
            protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            protection.replace("PR_Read", settings.value("Protection/Read").toString());
            protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());
    //FIN_Protection

    //DEBUT_Programme
        //Importation du Template Programme
        QString fileNameP = settings.value("Configuration/TemplateP").toString();
        QFile fichierP(fileNameP);
        fichierP.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxP(&fichierP);
        fluxP.setCodec("UTF-8");

            //Lecture du Template Programme
            programme = fluxP.readAll();

            //Remplacement des Variables par les valeurs stocké dans le registre
            programme.replace("GB_Desc_Img_Line", GB_Desc_Img_Line->text());
            programme.replace("GB_Main_Name_Line", GB_Main_Name_Line->text());
            programme.replace("GB_Main_Desc_Line", GB_Main_Desc_Line->text());
            programme.replace("GB_Desc_Desc_Line", GB_Desc_Desc_Line->toPlainText());
            programme.replace("GB_Main_Name_Line", GB_Main_Name_Line->text());
            programme.replace("GB_Tech_Aute_Line", GB_Tech_Aute_Line->text());
            programme.replace("GB_Tech_Type_Comb", GB_Tech_Type_Comb->currentText());
            programme.replace("GB_Tech_Desc_Line", GB_Tech_Desc_Line->text());
            programme.replace("GB_Tech_Auto_Line", GB_Tech_Auto_Line->text());
            programme.replace("GB_Tech_Inte_Line", GB_Tech_Inte_Line->text());
            programme.replace("GB_Tech_Vers_Line", GB_Tech_Vers_Line->text());
            programme.replace("GB_Tech_Acti_Line", GB_Tech_Acti_Line->text());
            programme.replace("GB_Tech_Util_Line", GB_Tech_Util_Line->text());
            programme.replace("GB_Tech_Mate_Line", GB_Tech_Mate_Line->text());
            programme.replace("GB_Tech_Dure_Line", GB_Tech_Dure_Line->text());
    //FIN_Programme

    //Envoi des codes à la classe FrameCodeGenerator
    FrameCodeGenerator *fenetreCode = new FrameCodeGenerator(programme, protection, this);
    fenetreCode->exec();
}
