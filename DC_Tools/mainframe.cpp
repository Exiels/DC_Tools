#include "mainframe.h"
#include "framecodegenerator.h"
#include "config.h"
#include "authenticator.h"

using namespace std;

MainFrame::MainFrame()
{
    //DEBUT_Informations
        version = "0.8";
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
                QAction *actionNewGlace = menuFichier->addAction("&Nouvelle GLACE/RV");
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
                QAction *actionGlace = toolBarMain->addAction("&GLACE/RV");
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
            new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_U), this, SLOT(uniqIDShow()));

        //FIN_Signaux

    setCentralWidget(zoneCentrale);

}

void MainFrame::About()
{
    QMessageBox::information(this, tr("A propos..."), tr("DC_Tools est un Logiciel créé par Exiel en 2020."));
}

void MainFrame::Program()
{
    i_p = "i";
    //Importation des Paramètres stocké dans le registre
        QSettings settings("Exiel", "DC_Tools");

        QLabel *nameL = new QLabel;
        nameL->setText("Programs Creator");

    //DEBUT_Groupe Main

        PRG_Main_Name_Line = new QLineEdit;
        PRG_Main_Name_Line->setText(settings.value("Programme/Nom").toString());
        PRG_Main_Desc_Line = new QLineEdit;
        PRG_Main_Desc_Line->setText(settings.value("Programme/MiniDescription").toString());

        //Layout Main
            QFormLayout *mainLayout = new QFormLayout;
            mainLayout->addRow("&Nom :", PRG_Main_Name_Line);
            mainLayout->addRow("&Description  :", PRG_Main_Desc_Line);

        //GroupBox Main
            QGroupBox *GB_Main = new QGroupBox("Principal");
            GB_Main->setLayout(mainLayout);
    //FIN_Groupe Main

    //DEBUT_Groupe Description
        PRG_Desc_Img_Line = new QLineEdit;
        PRG_Desc_Img_Line->setText(settings.value("Programme/UrlImage").toString());
        PRG_Desc_Desc_Line = new QTextEdit;
        PRG_Desc_Desc_Line->setText(settings.value("Programme/Description").toString());

        //Layout Description
            QFormLayout *descLayout = new QFormLayout;
            descLayout->addRow("&URL Image :", PRG_Desc_Img_Line);
            descLayout->addRow("&Description Complète :", PRG_Desc_Desc_Line);

        //GroupBox Description
            QGroupBox *GB_Desc = new QGroupBox("Description");
            GB_Desc->setLayout(descLayout);
    //FIN_Groupe Description

    //DEBUT_Groupe Fiche_Technique
        PRG_Tech_Aute_Line = new QLineEdit;
        PRG_Tech_Aute_Line->setText(settings.value("Configuration/Auteur").toString());
        PRG_Tech_Desc_Line = new QLineEdit;
        PRG_Tech_Desc_Line->setText(settings.value("Programme/MiniDescriptionB").toString());
        PRG_Tech_Auto_Line = new QLineEdit;
        PRG_Tech_Auto_Line->setText(settings.value("Programme/Autorisations").toString());
        PRG_Tech_Inte_Line = new QLineEdit;
        PRG_Tech_Inte_Line->setText(settings.value("Programme/Interdictions").toString());
        PRG_Tech_Vers_Line = new QLineEdit;
        PRG_Tech_Vers_Line->setText(settings.value("Programme/Version").toString());
        PRG_Tech_Acti_Line = new QLineEdit;
        PRG_Tech_Acti_Line->setText(settings.value("Programme/Activation").toString());
        PRG_Tech_Util_Line = new QLineEdit;
        PRG_Tech_Util_Line->setText(settings.value("Programme/Utilisation").toString());
        PRG_Tech_Mate_Line = new QLineEdit;
        PRG_Tech_Mate_Line->setText(settings.value("Configuration/Materiel").toString());
        PRG_Tech_Dure_Line = new QLineEdit;
        PRG_Tech_Dure_Line->setText(settings.value("Programme/DureeUtilisation").toString());

        //ComboBox Fiche_Technique
            PRG_Tech_Type_Comb = new QComboBox;
            PRG_Tech_Type_Comb->addItem("Pavlov");
            PRG_Tech_Type_Comb->addItem("Databomb");
            PRG_Tech_Type_Comb->addItem("Killer");
            PRG_Tech_Type_Comb->addItem("Crippler");
            PRG_Tech_Type_Comb->addItem("Shield");
            PRG_Tech_Type_Comb->addItem("Mirror");
            PRG_Tech_Type_Comb->addItem("Leurre");
            PRG_Tech_Type_Comb->addItem("Cloak");
            PRG_Tech_Type_Comb->addItem("Sonde");
            PRG_Tech_Type_Comb->addItem("Sniffer");
            PRG_Tech_Type_Comb->addItem("Analyseur");
            PRG_Tech_Type_Comb->addItem("Booster");
            PRG_Tech_Type_Comb->addItem("Assist");
            PRG_Tech_Type_Comb->addItem("Overide");
            PRG_Tech_Type_Comb->addItem("Purge");

        //Layout Fiche_Technique
            QFormLayout *techLayout = new QFormLayout;
            techLayout->addRow("&Auteur :", PRG_Tech_Aute_Line);
            techLayout->addRow("&Type :", PRG_Tech_Type_Comb);
            techLayout->addRow("&Description :", PRG_Tech_Desc_Line);
            techLayout->addRow("&Autorisations :", PRG_Tech_Auto_Line);
            techLayout->addRow("&Interdictions :", PRG_Tech_Inte_Line);
            techLayout->addRow("&Version :", PRG_Tech_Vers_Line);
            techLayout->addRow("&Activation :", PRG_Tech_Acti_Line);
            techLayout->addRow("&Utilisation :", PRG_Tech_Util_Line);
            techLayout->addRow("&Matériel Hôte :", PRG_Tech_Mate_Line);
            techLayout->addRow("&Durée d'Effet :", PRG_Tech_Dure_Line);
        //GroupBox Fiche_Technique
            QGroupBox *GB_Tech = new QGroupBox("Fiche Technique");
            GB_Tech->setLayout(techLayout);
    //FIN_Groupe Fiche_Technique

    //DEBUT_Bouton Générer
        PRG_Generate = new QPushButton("&Générer !");

        //Layout Bouton Générer
            QHBoxLayout *buttonsLayout = new QHBoxLayout;
            buttonsLayout->setAlignment(Qt::AlignRight);

            buttonsLayout->addWidget(PRG_Generate);
    //FIN_Bouton Générer


    //DEBUT_Main Layout
        QVBoxLayout *layoutMainL = new QVBoxLayout;
        layoutMainL->addWidget(nameL);
        layoutMainL->addWidget(GB_Main);
        layoutMainL->addWidget(GB_Desc);
        layoutMainL->addWidget(GB_Tech);
        layoutMainL->addLayout(buttonsLayout);

        QWidget *layout = new QWidget();
        layout->setLayout(layoutMainL);
    //FIN_Main Layout

    //DEBUT_Signaux
        connect(PRG_Generate, SIGNAL(clicked()), this, SLOT(generateCode()));
    //FIN_Signaux

    setCentralWidget(layout);
}

void MainFrame::generateCode()
{
    if (PRG_Main_Name_Line->text().isEmpty())
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
        protection += fluxPr.readAll();

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
            programme = fluxP.readAll() % fluxPr.readAll();

            //Remplacement des Variables par les valeurs stocké dans le registre
            programme.replace("GB_Desc_Img_Line", PRG_Desc_Img_Line->text());
            programme.replace("GB_Main_Name_Line", PRG_Main_Name_Line->text());
            programme.replace("GB_Main_Desc_Line", PRG_Main_Desc_Line->text());
            programme.replace("GB_Desc_Desc_Line", PRG_Desc_Desc_Line->toPlainText());
            programme.replace("GB_Main_Name_Line", PRG_Main_Name_Line->text());
            programme.replace("GB_Tech_Aute_Line", PRG_Tech_Aute_Line->text());
            programme.replace("GB_Tech_Type_Comb", PRG_Tech_Type_Comb->currentText());
            programme.replace("GB_Tech_Desc_Line", PRG_Tech_Desc_Line->text());
            programme.replace("GB_Tech_Auto_Line", PRG_Tech_Auto_Line->text());
            programme.replace("GB_Tech_Inte_Line", PRG_Tech_Inte_Line->text());
            programme.replace("GB_Tech_Vers_Line", PRG_Tech_Vers_Line->text());
            programme.replace("GB_Tech_Acti_Line", PRG_Tech_Acti_Line->text());
            programme.replace("GB_Tech_Util_Line", PRG_Tech_Util_Line->text());
            programme.replace("GB_Tech_Mate_Line", PRG_Tech_Mate_Line->text());
            programme.replace("GB_Tech_Dure_Line", PRG_Tech_Dure_Line->text());
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
            settings.setValue("Programme/Nom", QString(pname = PRG_Main_Name_Line->text()));
            settings.setValue("Programme/MiniDescription", QString(pmdesc = PRG_Main_Desc_Line->text()));
            settings.setValue("Programme/UrlImage", QString(purlimg = PRG_Desc_Img_Line->text()));
            settings.setValue("Programme/Description", QString(pdesc = PRG_Desc_Desc_Line->toPlainText()));
            settings.setValue("Programme/MiniDescriptionB", QString(pmdescb = PRG_Tech_Desc_Line->text()));
            settings.setValue("Programme/Autorisations", QString(pauto = PRG_Tech_Auto_Line->text()));
            settings.setValue("Programme/Interdictions", QString(pinte = PRG_Tech_Inte_Line->text()));
            settings.setValue("Programme/Version", QString(pvers = PRG_Tech_Vers_Line->text()));
            settings.setValue("Programme/Activation", QString(pacti = PRG_Tech_Acti_Line->text()));
            settings.setValue("Programme/Utilisation", QString(putil = PRG_Tech_Util_Line->text()));
            settings.setValue("Programme/DureeUtilisation", QString(pdutil = PRG_Tech_Dure_Line->text()));
    }
        //FIN_Save Programme

        //DEBUT_Save IA

        //FIN_Save IA
    //FIN_Système de sauvegarde

    QVBoxLayout *MainLayout = new QVBoxLayout;
    //DEBUT_Onglet Main
        //Création du TabWidget
            mainGL = new QTabWidget(this);
        //Création des pages
            principal = new QWidget;
            cm = new QWidget;
            alerte = new QWidget;
            niveau = new QWidget;

        //DEBUT_Page Principal
            GL_Main_Name_Line = new QLineEdit;
            GL_Main_Img_Line = new QLineEdit;
            GL_Main_Vers_Line = new QLineEdit;
            GL_Main_Desc_Line = new QTextEdit;
            GL_Main_Plan_Line = new QLineEdit;
            GL_Glace_Check = new QCheckBox;

            //Layout Page Principal
                QFormLayout *P_main = new QFormLayout;

                P_main->addRow("Nom :", GL_Main_Name_Line);
                P_main->addRow("Url Image :", GL_Main_Img_Line);
                P_main->addRow("Version :", GL_Main_Vers_Line);
                P_main->addRow("Description :", GL_Main_Desc_Line);
                P_main->addRow("URL Plan Général d'Intéraction :", GL_Main_Plan_Line);
                P_main->addRow("GLACE ?", GL_Glace_Check);

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
            mainCM = new QTabWidget();
            GL_Main_Lvl_Line = new QComboBox;
            GL_CM_Add_CM = new QPushButton("Nouvelle Contre-Mesures");

            CM1 = new QWidget;
            CM2 = new QWidget;
            CM3 = new QWidget;
            CM4 = new QWidget;
            CM5 = new QWidget;
            CM6 = new QWidget;
            CM7 = new QWidget;
            CM8 = new QWidget;
            CM9 = new QWidget;
            CM10 = new QWidget;

            GL_CM1_Name_Line = new QLineEdit;
            GL_CM1_Img_Line = new QLineEdit;
            GL_CM1_Cat_Line = new QComboBox;
            GL_CM1_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_CM1_Comp1_Line = new QLineEdit;
            GL_CM1_Comp2_Line = new QLineEdit;
            GL_CM1_Comp3_Line = new QLineEdit;
            GL_CM1_Alg1_Line = new QLineEdit;
            GL_CM1_Alg2_Line = new QLineEdit;
            GL_CM1_Alg3_Line = new QLineEdit;
            GL_CM1_Desc_Line = new QTextEdit;

            QHBoxLayout *buttonsLayout = new QHBoxLayout;
            buttonsLayout->setAlignment(Qt::AlignRight);

            buttonsLayout->addWidget(GL_CM_Add_CM);

            //Edition de la QComboBox
                    GL_Main_Lvl_Line->addItem("Blanche");
                    GL_Main_Lvl_Line->addItem("Grise");
            //Layout Page CM

                    QFormLayout *P_CM = new QFormLayout;
                    P_CM->addRow("GLACE :", GL_Main_Lvl_Line);

            //GroupBox Page CM
                    QGroupBox *GB_CM = new QGroupBox;
                    GB_CM->setLayout(P_CM);

                    QFormLayout *L_CM1 = new QFormLayout;
                    L_CM1->addRow("&Nom :", GL_CM1_Name_Line);
                    L_CM1->addRow("&Url Image :", GL_CM1_Img_Line);
                    L_CM1->addRow("&Catégorie :", GL_CM1_Cat_Line);
                    L_CM1->addRow("&Composition 1 :", GL_CM1_Comp1_Line);
                    L_CM1->addRow("&Composition 2 :", GL_CM1_Comp2_Line);
                    L_CM1->addRow("&Composition 3 :", GL_CM1_Comp3_Line);
                    L_CM1->addRow("&Algorithme 1 :", GL_CM1_Alg1_Line);
                    L_CM1->addRow("&Algorithme 2 :", GL_CM1_Alg2_Line);
                    L_CM1->addRow("&Algorithme 3 :", GL_CM1_Alg3_Line);
                    L_CM1->addRow("&Description :", GL_CM1_Desc_Line);

                    QVBoxLayout *PVB_CM1 = new QVBoxLayout;
                    PVB_CM1->addLayout(L_CM1);

                    CM1->setLayout(PVB_CM1);
                    mainCM->addTab(CM1, "CM1");

            //Layout Main Page CM
                    QVBoxLayout *PVB_CM = new QVBoxLayout;
                    PVB_CM->addWidget(mainCM);
                    PVB_CM->addWidget(GB_CM);
                    PVB_CM->addLayout(buttonsLayout);

            //Définition du Layout de la Page Principal
                    cm->setLayout(PVB_CM);
        //FIN_Page CM

        //DEBUT_Page Alerte
                    GL_CM_Lab1_Line = new QLabel;
                    GL_CM_Lab1_Line->setText("Aucune Alerte : Etat passif.");
                    GL_CM_Lab2_Line = new QLabel;
                    GL_CM_Lab2_Line->setText("Alerte faible : Légère perturbation dans la RV (absence de cloak, programmes visibles).");
                    GL_CM_Lab3_Line = new QLabel;
                    GL_CM_Lab3_Line->setText("Alerte élevée : Plongeurs combatifs, Intrusion réseau détecté, CMs engagées.");

                    GL_CM_NAlrt1_Line = new QLineEdit;
                    GL_CM_NAlrt2_Line = new QLineEdit;
                    GL_CM_NAlrt3_Line = new QLineEdit;

                    GL_CM_FAlrt1_Line = new QLineEdit;
                    GL_CM_FAlrt2_Line = new QLineEdit;
                    GL_CM_FAlrt3_Line = new QLineEdit;

                    GL_CM_HAlrt1_Line = new QLineEdit;
                    GL_CM_HAlrt2_Line = new QLineEdit;
                    GL_CM_HAlrt3_Line = new QLineEdit;

                    QFormLayout *P_Alrt = new QFormLayout;
                    P_Alrt->addWidget(GL_CM_Lab1_Line);
                    P_Alrt->addRow("► ", GL_CM_NAlrt1_Line);
                    P_Alrt->addRow("► ", GL_CM_NAlrt2_Line);
                    P_Alrt->addRow("► ", GL_CM_NAlrt3_Line);
                    P_Alrt->addWidget(GL_CM_Lab2_Line);
                    P_Alrt->addRow("► ", GL_CM_FAlrt1_Line);
                    P_Alrt->addRow("► ", GL_CM_FAlrt2_Line);
                    P_Alrt->addRow("► ", GL_CM_FAlrt3_Line);
                    P_Alrt->addWidget(GL_CM_Lab3_Line);
                    P_Alrt->addRow("► ", GL_CM_HAlrt1_Line);
                    P_Alrt->addRow("► ", GL_CM_HAlrt2_Line);
                    P_Alrt->addRow("► ", GL_CM_HAlrt3_Line);

                    QGroupBox *GB_Alrt = new QGroupBox;
                    GB_Alrt->setLayout(P_Alrt);

                    QVBoxLayout *PVB_Alrt = new QVBoxLayout;
                    PVB_Alrt->addWidget(GB_Alrt);

                    alerte->setLayout(PVB_Alrt);

        //FIN_Page Alerte

        //DEBUT_Page Niveau
                    mainLvl = new QTabWidget();

                    Lvl1 = new QWidget;
                    Lvl2 = new QWidget;
                    Lvl3 = new QWidget;
                    Lvl4 = new QWidget;
                    Lvl5 = new QWidget;

                    GL_LVl1_LImg1_Line = new QLabel;
                    GL_LVl1_LImg1_Line->setText("Image niveau (URL) :");
                    GL_LVl1_LSpacer1_Line = new QLabel;
                    GL_LVl1_LSpacer1_Line->setText("---------------------------------------------------------------------------");
                    GL_LVl1_LSpacer2_Line = new QLabel;
                    GL_LVl1_LSpacer2_Line->setText("---------------------------------------------------------------------------");
                    GL_LVl1_LSpacer3_Line = new QLabel;
                    GL_LVl1_LSpacer3_Line->setText("---------------------------------------------------------------------------");
                    GL_LVl1_LCM1_Line = new QLabel;
                    GL_LVl1_LCM1_Line->setText("Nom CM1 :");
                    GL_LVl1_LCM2_Line = new QLabel;
                    GL_LVl1_LCM2_Line->setText("Nom CM2 :");
                    GL_LVl1_LCM3_Line = new QLabel;
                    GL_LVl1_LCM3_Line->setText("Nom CM3 :");
                    GL_LVl1_LCM4_Line = new QLabel;
                    GL_LVl1_LCM4_Line->setText("Nom CM4 :");
                    GL_LVl1_LCM5_Line = new QLabel;
                    GL_LVl1_LCM5_Line->setText("Nom CM5 :");
                    GL_LVl1_LDesc_Line = new QLabel;
                    GL_LVl1_LDesc_Line->setText("Description du Niveau :");
                    GL_LVl1_LImg2_Line = new QLabel;
                    GL_LVl1_LImg2_Line->setText("Plan du Niveau (Url Image):");
                    GL_Lvl1_CM1_Line = new QLineEdit;
                    GL_Lvl1_CM1_Nbr_Line = new QSpinBox;
                    GL_Lvl1_CM1_Nbr_Line->setMaximumWidth(50);
                    GL_LVL1_LCM1NBR_Line = new QLabel;
                    GL_LVL1_LCM1NBR_Line->setText("Nbr CM1 :");
                    GL_Lvl1_CM2_Line = new QLineEdit;
                    GL_Lvl1_CM2_Nbr_Line = new QSpinBox;
                    GL_Lvl1_CM2_Nbr_Line->setMaximumWidth(50);
                    GL_LVL1_LCM2NBR_Line = new QLabel;
                    GL_LVL1_LCM2NBR_Line->setText("Nbr CM2 :");
                    GL_Lvl1_CM3_Line = new QLineEdit;
                    GL_Lvl1_CM3_Nbr_Line = new QSpinBox;
                    GL_Lvl1_CM3_Nbr_Line->setMaximumWidth(50);
                    GL_LVL1_LCM3NBR_Line = new QLabel;
                    GL_LVL1_LCM3NBR_Line->setText("Nbr CM3 :");
                    GL_Lvl1_CM4_Line = new QLineEdit;
                    GL_Lvl1_CM4_Nbr_Line = new QSpinBox;
                    GL_Lvl1_CM4_Nbr_Line->setMaximumWidth(50);
                    GL_LVL1_LCM4NBR_Line = new QLabel;
                    GL_LVL1_LCM4NBR_Line->setText("Nbr CM4 :");
                    GL_Lvl1_CM5_Line = new QLineEdit;
                    GL_Lvl1_CM5_Nbr_Line = new QSpinBox;
                    GL_Lvl1_CM5_Nbr_Line->setMaximumWidth(50);
                    GL_LVL1_LCM5NBR_Line = new QLabel;
                    GL_LVL1_LCM5NBR_Line->setText("Nbr CM5 :");
                    GL_LVl1_Img1_Line = new QLineEdit;
                    GL_LVl1_Desc1_Line = new QTextEdit;
                    GL_LVl1_PImg1_Line = new QLineEdit;
                    GL_Lvl_Add_Lvl = new QPushButton("Nouveau Niveau");

                    QHBoxLayout *buttonsLayoutLvl = new QHBoxLayout;
                    buttonsLayoutLvl->setAlignment(Qt::AlignRight);

                    GL_Lvl1_WCmNbr = new QWidget();
                    QHBoxLayout *GL_Lvl1_CmNbr = new QHBoxLayout(GL_Lvl1_WCmNbr);
                    GL_Lvl1_CmNbr->addWidget(GL_LVL1_LCM1NBR_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_Lvl1_CM1_Nbr_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_LVL1_LCM2NBR_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_Lvl1_CM2_Nbr_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_LVL1_LCM3NBR_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_Lvl1_CM3_Nbr_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_LVL1_LCM4NBR_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_Lvl1_CM4_Nbr_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_LVL1_LCM5NBR_Line);
                    GL_Lvl1_CmNbr->addWidget(GL_Lvl1_CM5_Nbr_Line);


                    GL_Lvl1 = new QGridLayout;
                    GL_Lvl1->addWidget(GL_LVl1_LImg1_Line, 0, 0);
                    GL_Lvl1->addWidget(GL_LVl1_Img1_Line, 0, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LSpacer1_Line, 1, 1, Qt::AlignCenter);
                    GL_Lvl1->addWidget(GL_LVl1_LCM1_Line, 2, 0);
                    GL_Lvl1->addWidget(GL_Lvl1_CM1_Line, 2, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LCM2_Line, 3, 0);
                    GL_Lvl1->addWidget(GL_Lvl1_CM2_Line, 3, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LCM3_Line, 4, 0);
                    GL_Lvl1->addWidget(GL_Lvl1_CM3_Line, 4, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LCM4_Line, 5, 0);
                    GL_Lvl1->addWidget(GL_Lvl1_CM4_Line, 5, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LCM5_Line, 6, 0);
                    GL_Lvl1->addWidget(GL_Lvl1_CM5_Line, 6, 1);
                    GL_Lvl1->addWidget(GL_Lvl1_WCmNbr, 7, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LSpacer2_Line, 8, 1, Qt::AlignCenter);
                    GL_Lvl1->addWidget(GL_LVl1_LDesc_Line, 9, 0);
                    GL_Lvl1->addWidget(GL_LVl1_Desc1_Line, 9, 1);
                    GL_Lvl1->addWidget(GL_LVl1_LSpacer3_Line, 10, 1, Qt::AlignCenter);
                    GL_Lvl1->addWidget(GL_LVl1_LImg2_Line, 11, 0);
                    GL_Lvl1->addWidget(GL_LVl1_PImg1_Line, 11, 1);

                    GL_LVl1_LSpacer1_Line->setVisible(false);
                    GL_LVl1_LCM1_Line->setVisible(false);
                    GL_Lvl1_CM1_Line->setVisible(false);
                    GL_LVl1_LCM2_Line->setVisible(false);
                    GL_Lvl1_CM2_Line->setVisible(false);
                    GL_LVl1_LCM3_Line->setVisible(false);
                    GL_Lvl1_CM3_Line->setVisible(false);
                    GL_LVl1_LCM4_Line->setVisible(false);
                    GL_Lvl1_CM4_Line->setVisible(false);
                    GL_LVl1_LCM5_Line->setVisible(false);
                    GL_Lvl1_CM5_Line->setVisible(false);
                    GL_Lvl1_WCmNbr->setVisible(false);

                    buttonsLayoutLvl->addWidget(GL_Lvl_Add_Lvl);

                    QVBoxLayout *PVB_Lvl1 = new QVBoxLayout;
                    PVB_Lvl1->addLayout(GL_Lvl1);

                    Lvl1->setLayout(PVB_Lvl1);
                    mainLvl->addTab(Lvl1, "Niveau 1");

                    QVBoxLayout *PVB_Lvl = new QVBoxLayout;
                    PVB_Lvl->addWidget(mainLvl);
                    PVB_Lvl->addLayout(buttonsLayoutLvl);

                    niveau->setLayout(PVB_Lvl);

        //FIN_Page Niveau

            QPushButton *PRG_Generate = new QPushButton("&Générer !");

        //Ajout des onglets au TabWidget
            mainGL->insertTab(0, principal, "Principal");
            mainGL->insertTab(3, niveau, "Niveaux");
    //FIN_Onglet Main
    MainLayout->addWidget(mainGL);
    MainLayout->addWidget(PRG_Generate);
    QWidget *layout = new QWidget();
    layout->setLayout(MainLayout);

    //DEBUT_Signaux
        connect(GL_Glace_Check, SIGNAL(stateChanged(int)), this, SLOT(uGlaceCm(int)));
        connect(GL_CM_Add_CM, SIGNAL(clicked()), this, SLOT(addCM()));
        connect(GL_Main_Lvl_Line, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(stateChanged(QString)));
        connect(GL_Lvl_Add_Lvl, SIGNAL(clicked()), this, SLOT(addLvl()));
        connect(PRG_Generate, SIGNAL(clicked()), this, SLOT(generateCodeGlace()));
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
            IA_Generate = new QPushButton("&Générer !");

            //Layout Bouton Générer
                QHBoxLayout *buttonsLayout = new QHBoxLayout;
                buttonsLayout->setAlignment(Qt::AlignRight);

                buttonsLayout->addWidget(IA_Generate);
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
            connect(IA_Generate, SIGNAL(clicked()), this, SLOT(generateCodeIa()));
        //FIN_Signaux

        setCentralWidget(layout);
}

void MainFrame::updater()
{
    //Initialisation du Manager
    QNetworkAccessManager manager;
    //Vérification de la version du serveur
    reply = manager.get(QNetworkRequest(QUrl("http://31.38.22.246/DC_Tools/version.txt")));
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
        glaceon = 1;
        mainGL->insertTab(1, cm, "Contres-Mesures");
        mainGL->insertTab(2, alerte, "Alertes");

        GL_LVl1_LSpacer1_Line->setVisible(true);
        GL_LVl1_LCM1_Line->setVisible(true);
        GL_Lvl1_CM1_Line->setVisible(true);
        GL_LVl1_LCM2_Line->setVisible(true);
        GL_Lvl1_CM2_Line->setVisible(true);
        GL_LVl1_LCM3_Line->setVisible(true);
        GL_Lvl1_CM3_Line->setVisible(true);
        GL_LVl1_LCM4_Line->setVisible(true);
        GL_Lvl1_CM4_Line->setVisible(true);
        GL_LVl1_LCM5_Line->setVisible(true);
        GL_Lvl1_CM5_Line->setVisible(true);
        GL_Lvl1_WCmNbr->setVisible(true);


        if(countL >=2){
        GL_LVl2_LSpacer1_Line->setVisible(true);
        GL_LVl2_LCM1_Line->setVisible(true);
        GL_Lvl2_CM1_Line->setVisible(true);
        GL_LVl2_LCM2_Line->setVisible(true);
        GL_Lvl2_CM2_Line->setVisible(true);
        GL_LVl2_LCM3_Line->setVisible(true);
        GL_Lvl2_CM3_Line->setVisible(true);
        GL_LVl2_LCM4_Line->setVisible(true);
        GL_Lvl2_CM4_Line->setVisible(true);
        GL_LVl2_LCM5_Line->setVisible(true);
        GL_Lvl2_CM5_Line->setVisible(true);
        GL_Lvl2_WCmNbr->setVisible(true);
        }
        if(countL >=3){
        GL_LVl3_LSpacer1_Line->setVisible(true);
        GL_LVl3_LCM1_Line->setVisible(true);
        GL_Lvl3_CM1_Line->setVisible(true);
        GL_LVl3_LCM2_Line->setVisible(true);
        GL_Lvl3_CM2_Line->setVisible(true);
        GL_LVl3_LCM3_Line->setVisible(true);
        GL_Lvl3_CM3_Line->setVisible(true);
        GL_LVl3_LCM4_Line->setVisible(true);
        GL_Lvl3_CM4_Line->setVisible(true);
        GL_LVl3_LCM5_Line->setVisible(true);
        GL_Lvl3_CM5_Line->setVisible(true);
        GL_Lvl3_WCmNbr->setVisible(true);
        }
        if(countL >=4){
        GL_LVl4_LSpacer1_Line->setVisible(true);
        GL_LVl4_LCM1_Line->setVisible(true);
        GL_Lvl4_CM1_Line->setVisible(true);
        GL_LVl4_LCM2_Line->setVisible(true);
        GL_Lvl4_CM2_Line->setVisible(true);
        GL_LVl4_LCM3_Line->setVisible(true);
        GL_Lvl4_CM3_Line->setVisible(true);
        GL_LVl4_LCM4_Line->setVisible(true);
        GL_Lvl4_CM4_Line->setVisible(true);
        GL_LVl4_LCM5_Line->setVisible(true);
        GL_Lvl4_CM5_Line->setVisible(true);
        GL_Lvl4_WCmNbr->setVisible(true);
        }
        if(countL >=5){
        GL_LVl5_LSpacer1_Line->setVisible(true);
        GL_LVl5_LCM1_Line->setVisible(true);
        GL_Lvl5_CM1_Line->setVisible(true);
        GL_LVl5_LCM2_Line->setVisible(true);
        GL_Lvl5_CM2_Line->setVisible(true);
        GL_LVl5_LCM3_Line->setVisible(true);
        GL_Lvl5_CM3_Line->setVisible(true);
        GL_LVl5_LCM4_Line->setVisible(true);
        GL_Lvl5_CM4_Line->setVisible(true);
        GL_LVl5_LCM5_Line->setVisible(true);
        GL_Lvl5_CM5_Line->setVisible(true);
        GL_Lvl5_WCmNbr->setVisible(true);
        }

    } else if(etat != 2)
    {
        glaceon = 0;
        mainGL->removeTab(2);
        mainGL->removeTab(1);
        GL_LVl1_LSpacer1_Line->setVisible(false);
        GL_LVl1_LCM1_Line->setVisible(false);
        GL_Lvl1_CM1_Line->setVisible(false);
        GL_LVl1_LCM2_Line->setVisible(false);
        GL_Lvl1_CM2_Line->setVisible(false);
        GL_LVl1_LCM3_Line->setVisible(false);
        GL_Lvl1_CM3_Line->setVisible(false);
        GL_LVl1_LCM4_Line->setVisible(false);
        GL_Lvl1_CM4_Line->setVisible(false);
        GL_LVl1_LCM5_Line->setVisible(false);
        GL_Lvl1_CM5_Line->setVisible(false);
        GL_Lvl1_WCmNbr->setVisible(false);

        if(countL >= 2){
        GL_LVl2_LSpacer1_Line->setVisible(false);
        GL_LVl2_LCM1_Line->setVisible(false);
        GL_Lvl2_CM1_Line->setVisible(false);
        GL_LVl2_LCM2_Line->setVisible(false);
        GL_Lvl2_CM2_Line->setVisible(false);
        GL_LVl2_LCM3_Line->setVisible(false);
        GL_Lvl2_CM3_Line->setVisible(false);
        GL_LVl2_LCM4_Line->setVisible(false);
        GL_Lvl2_CM4_Line->setVisible(false);
        GL_LVl2_LCM5_Line->setVisible(false);
        GL_Lvl2_CM5_Line->setVisible(false);
        GL_Lvl2_WCmNbr->setVisible(false);
        }
        if(countL >=3){
        GL_LVl3_LSpacer1_Line->setVisible(false);
        GL_LVl3_LCM1_Line->setVisible(false);
        GL_Lvl3_CM1_Line->setVisible(false);
        GL_LVl3_LCM2_Line->setVisible(false);
        GL_Lvl3_CM2_Line->setVisible(false);
        GL_LVl3_LCM3_Line->setVisible(false);
        GL_Lvl3_CM3_Line->setVisible(false);
        GL_LVl3_LCM4_Line->setVisible(false);
        GL_Lvl3_CM4_Line->setVisible(false);
        GL_LVl3_LCM5_Line->setVisible(false);
        GL_Lvl3_CM5_Line->setVisible(false);
        GL_Lvl3_WCmNbr->setVisible(false);
        }
        if(countL >=4){
        GL_LVl4_LSpacer1_Line->setVisible(false);
        GL_LVl4_LCM1_Line->setVisible(false);
        GL_Lvl4_CM1_Line->setVisible(false);
        GL_LVl4_LCM2_Line->setVisible(false);
        GL_Lvl4_CM2_Line->setVisible(false);
        GL_LVl4_LCM3_Line->setVisible(false);
        GL_Lvl4_CM3_Line->setVisible(false);
        GL_LVl4_LCM4_Line->setVisible(false);
        GL_Lvl4_CM4_Line->setVisible(false);
        GL_LVl4_LCM5_Line->setVisible(false);
        GL_Lvl4_CM5_Line->setVisible(false);
        GL_Lvl4_WCmNbr->setVisible(false);
        }
        if(countL >=5){
        GL_LVl5_LSpacer1_Line->setVisible(false);
        GL_LVl5_LCM1_Line->setVisible(false);
        GL_Lvl5_CM1_Line->setVisible(false);
        GL_LVl5_LCM2_Line->setVisible(false);
        GL_Lvl5_CM2_Line->setVisible(false);
        GL_LVl5_LCM3_Line->setVisible(false);
        GL_Lvl5_CM3_Line->setVisible(false);
        GL_LVl5_LCM4_Line->setVisible(false);
        GL_Lvl5_CM4_Line->setVisible(false);
        GL_LVl5_LCM5_Line->setVisible(false);
        GL_Lvl5_CM5_Line->setVisible(false);
        GL_Lvl5_WCmNbr->setVisible(false);
        }
    }
}

void MainFrame::newProgram()
{
    MainFrame::Program();
    PRG_Main_Name_Line->setText("");
    PRG_Main_Desc_Line->setText("");
    PRG_Desc_Img_Line->setText("");
    PRG_Desc_Desc_Line->setText("");
    PRG_Tech_Aute_Line->setText("");
    PRG_Tech_Desc_Line->setText("");
    PRG_Tech_Auto_Line->setText("");
    PRG_Tech_Inte_Line->setText("");
    PRG_Tech_Vers_Line->setText("");
    PRG_Tech_Acti_Line->setText("");
    PRG_Tech_Util_Line->setText("");
    PRG_Tech_Mate_Line->setText("");
    PRG_Tech_Dure_Line->setText("");
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
            settings.setValue("Programme/Nom", QString(pname = PRG_Main_Name_Line->text()));
            settings.setValue("Programme/MiniDescription", QString(pmdesc = PRG_Main_Desc_Line->text()));
            settings.setValue("Programme/UrlImage", QString(purlimg = PRG_Desc_Img_Line->text()));
            settings.setValue("Programme/Description", QString(pdesc = PRG_Desc_Desc_Line->toPlainText()));
            settings.setValue("Programme/MiniDescriptionB", QString(pmdescb = PRG_Tech_Desc_Line->text()));
            settings.setValue("Programme/Autorisations", QString(pauto = PRG_Tech_Auto_Line->text()));
            settings.setValue("Programme/Interdictions", QString(pinte = PRG_Tech_Inte_Line->text()));
            settings.setValue("Programme/Version", QString(pvers = PRG_Tech_Vers_Line->text()));
            settings.setValue("Programme/Activation", QString(pacti = PRG_Tech_Acti_Line->text()));
            settings.setValue("Programme/Utilisation", QString(putil = PRG_Tech_Util_Line->text()));
            settings.setValue("Programme/DureeUtilisation", QString(pdutil = PRG_Tech_Dure_Line->text()));
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
    if (GL_Main_Name_Line->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de GLACE/RV");
        return; // Arrêt de la méthode
    }
    QSettings settings("Exiel", "DC_Tools");

    QString GCG_Protection;

    QString GCG_GL_Main;

    QString GCG_GL_CmTop;

    QString GCG_GL_CM1;
    QString GCG_GL_CM2;
    QString GCG_GL_CM3;
    QString GCG_GL_CM4;
    QString GCG_GL_CM5;
    QString GCG_GL_CM6;
    QString GCG_GL_CM7;
    QString GCG_GL_CM8;
    QString GCG_GL_CM9;
    QString GCG_GL_CM10;

    QString GCG_GL_Alrt;
    QString GCG_GL_Plan;

    QString GCG_GL_Lvl1;
    QString GCG_GL_Lvl2;
    QString GCG_GL_Lvl3;
    QString GCG_GL_Lvl4;
    QString GCG_GL_Lvl5;

    QString GCG_GL_End;

    QString glace;

    //DEBUT_Protection
        //Importation du Template Protection
        QString fileNamePr = settings.value("Configuration/TemplatePr").toString();
        QFile filePr(fileNamePr);
        filePr.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream fluxPr(&filePr);
        fluxPr.setCodec("UTF-8");

        //Lecture du Template Protection
        GCG_Protection = fluxPr.readAll();

        //Remplacement des Variables par les valeurs stocké dans le registre
            GCG_Protection.replace("PR_Name", settings.value("Protection/Name").toString());
            GCG_Protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            GCG_Protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            GCG_Protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            GCG_Protection.replace("PR_Read", settings.value("Protection/Read").toString());
            GCG_Protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            GCG_Protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            GCG_Protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());
    //FIN_Protection

    //DEBUT_Glace

        //START_GL_Main
            //Importation du Template Glace_Main
                QString fileNameGlMain = settings.value("Configuration/TemplateGL").toString() + "\\main.cfg";
                QFile fileGlMain(fileNameGlMain);
                fileGlMain.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream fluxGlMain(&fileGlMain);
                fluxGlMain.setCodec("UTF-8");

                    //Lecture du Template Glace_Main
                        GCG_GL_Main = fluxGlMain.readAll();

                    //Remplacement des Variables par les valeurs stocké dans le registre
                        GCG_GL_Main.replace("GL_Main_Img_Line", GL_Main_Img_Line->text());
                        GCG_GL_Main.replace("GL_Main_Name_Line", GL_Main_Name_Line->text());
                        if(glaceon == 1){
                            GCG_GL_Main.replace("GL_Main_Lvl_Line", GL_Main_Lvl_Line->currentText());
                        }else{
                            GCG_GL_Main.replace("GL_Main_Lvl_Line", "");
                        }
                        GCG_GL_Main.replace("GL_Main_Vers_Line", GL_Main_Vers_Line->text());
                        GCG_GL_Main.replace("Gl_Main_Desc_Line", GL_Main_Desc_Line->toPlainText());
        //END_GL_Main

        //START_GL_CM
            if(glaceon == 1){
            //Importation du Template Glace_CM
                QString fileNameGlCm = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                QFile fileGlCM(fileNameGlCm);
                fileGlCM.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream fluxGlCM(&fileGlCM);
                fluxGlCM.setCodec("UTF-8");

                    //Lecture du Template Glace_CM
                        GCG_GL_CM1 = fluxGlCM.readAll();
                    //Remplacement des Variables par les valeurs stockés dans le registre
                        GCG_GL_CM1.replace("GL_CM_Name_Line", GL_CM1_Name_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Img_Line", GL_CM1_Img_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Cat_Line", GL_CM1_Cat_Line->currentText());
                        GCG_GL_CM1.replace("GL_CM_Comp1_Line", GL_CM1_Comp1_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Comp2_Line", GL_CM1_Comp2_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Comp3_Line", GL_CM1_Comp3_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Alg1_Line", GL_CM1_Alg1_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Alg2_Line", GL_CM1_Alg2_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Alg3_Line", GL_CM1_Alg3_Line->text());
                        GCG_GL_CM1.replace("GL_CM_Desc_Line", GL_CM1_Desc_Line->toPlainText());

                       if(count >= 2){
                           QString fileNameGlCm2 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM2(fileNameGlCm2);
                           fileGlCM2.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM2(&fileGlCM2);
                           fluxGlCM2.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM2 = fluxGlCM2.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM2.replace("GL_CM_Name_Line", GL_CM2_Name_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Img_Line", GL_CM2_Img_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Cat_Line", GL_CM2_Cat_Line->currentText());
                               GCG_GL_CM2.replace("GL_CM_Comp1_Line", GL_CM2_Comp1_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Comp2_Line", GL_CM2_Comp2_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Comp3_Line", GL_CM2_Comp3_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Alg1_Line", GL_CM2_Alg1_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Alg2_Line", GL_CM2_Alg2_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Alg3_Line", GL_CM2_Alg3_Line->text());
                               GCG_GL_CM2.replace("GL_CM_Desc_Line", GL_CM2_Desc_Line->toPlainText());
                       }
                       if(count >= 3){
                           QString fileNameGlCm3 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM3(fileNameGlCm3);
                           fileGlCM3.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM3(&fileGlCM3);
                           fluxGlCM3.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM3 = fluxGlCM3.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM3.replace("GL_CM_Name_Line", GL_CM3_Name_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Img_Line", GL_CM3_Img_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Cat_Line", GL_CM3_Cat_Line->currentText());
                               GCG_GL_CM3.replace("GL_CM_Comp1_Line", GL_CM3_Comp1_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Comp2_Line", GL_CM3_Comp2_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Comp3_Line", GL_CM3_Comp3_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Alg1_Line", GL_CM3_Alg1_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Alg2_Line", GL_CM3_Alg2_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Alg3_Line", GL_CM3_Alg3_Line->text());
                               GCG_GL_CM3.replace("GL_CM_Desc_Line", GL_CM3_Desc_Line->toPlainText());
                       }
                       if(count >= 4){
                           QString fileNameGlCm4 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM4(fileNameGlCm4);
                           fileGlCM4.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM4(&fileGlCM4);
                           fluxGlCM4.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM4 = fluxGlCM4.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM4.replace("GL_CM_Name_Line", GL_CM4_Name_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Img_Line", GL_CM4_Img_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Cat_Line", GL_CM4_Cat_Line->currentText());
                               GCG_GL_CM4.replace("GL_CM_Comp1_Line", GL_CM4_Comp1_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Comp2_Line", GL_CM4_Comp2_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Comp3_Line", GL_CM4_Comp3_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Alg1_Line", GL_CM4_Alg1_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Alg2_Line", GL_CM4_Alg2_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Alg3_Line", GL_CM4_Alg3_Line->text());
                               GCG_GL_CM4.replace("GL_CM_Desc_Line", GL_CM4_Desc_Line->toPlainText());
                       }
                       if(count >= 5){
                           QString fileNameGlCm5 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM5(fileNameGlCm5);
                           fileGlCM5.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM5(&fileGlCM5);
                           fluxGlCM5.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM5 = fluxGlCM5.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM5.replace("GL_CM_Name_Line", GL_CM5_Name_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Img_Line", GL_CM5_Img_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Cat_Line", GL_CM5_Cat_Line->currentText());
                               GCG_GL_CM5.replace("GL_CM_Comp1_Line", GL_CM5_Comp1_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Comp2_Line", GL_CM5_Comp2_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Comp3_Line", GL_CM5_Comp3_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Alg1_Line", GL_CM5_Alg1_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Alg2_Line", GL_CM5_Alg2_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Alg3_Line", GL_CM5_Alg3_Line->text());
                               GCG_GL_CM5.replace("GL_CM_Desc_Line", GL_CM5_Desc_Line->toPlainText());
                       }
                       if(count >= 6){
                           QString fileNameGlCm6 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM6(fileNameGlCm6);
                           fileGlCM6.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM6(&fileGlCM6);
                           fluxGlCM6.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM6 = fluxGlCM6.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM6.replace("GL_CM_Name_Line", GL_CM6_Name_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Img_Line", GL_CM6_Img_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Cat_Line", GL_CM6_Cat_Line->currentText());
                               GCG_GL_CM6.replace("GL_CM_Comp1_Line", GL_CM6_Comp1_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Comp2_Line", GL_CM6_Comp2_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Comp3_Line", GL_CM6_Comp3_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Alg1_Line", GL_CM6_Alg1_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Alg2_Line", GL_CM6_Alg2_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Alg3_Line", GL_CM6_Alg3_Line->text());
                               GCG_GL_CM6.replace("GL_CM_Desc_Line", GL_CM6_Desc_Line->toPlainText());
                       }
                       if(count >= 7){
                           QString fileNameGlCm7 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM7(fileNameGlCm7);
                           fileGlCM7.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM7(&fileGlCM7);
                           fluxGlCM7.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM7 = fluxGlCM7.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM7.replace("GL_CM_Name_Line", GL_CM7_Name_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Img_Line", GL_CM7_Img_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Cat_Line", GL_CM7_Cat_Line->currentText());
                               GCG_GL_CM7.replace("GL_CM_Comp1_Line", GL_CM7_Comp1_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Comp2_Line", GL_CM7_Comp2_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Comp3_Line", GL_CM7_Comp3_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Alg1_Line", GL_CM7_Alg1_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Alg2_Line", GL_CM7_Alg2_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Alg3_Line", GL_CM7_Alg3_Line->text());
                               GCG_GL_CM7.replace("GL_CM_Desc_Line", GL_CM7_Desc_Line->toPlainText());
                       }
                       if(count >= 8){
                           QString fileNameGlCm8 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM8(fileNameGlCm8);
                           fileGlCM8.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM8(&fileGlCM8);
                           fluxGlCM8.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM8 = fluxGlCM8.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM8.replace("GL_CM_Name_Line", GL_CM8_Name_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Img_Line", GL_CM8_Img_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Cat_Line", GL_CM8_Cat_Line->currentText());
                               GCG_GL_CM8.replace("GL_CM_Comp1_Line", GL_CM8_Comp1_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Comp2_Line", GL_CM8_Comp2_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Comp3_Line", GL_CM8_Comp3_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Alg1_Line", GL_CM8_Alg1_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Alg2_Line", GL_CM8_Alg2_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Alg3_Line", GL_CM8_Alg3_Line->text());
                               GCG_GL_CM8.replace("GL_CM_Desc_Line", GL_CM8_Desc_Line->toPlainText());
                       }
                       if(count >= 9){
                           QString fileNameGlCm9 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM9(fileNameGlCm9);
                           fileGlCM9.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM9(&fileGlCM9);
                           fluxGlCM9.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM9 = fluxGlCM9.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM9.replace("GL_CM_Name_Line", GL_CM9_Name_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Img_Line", GL_CM9_Img_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Cat_Line", GL_CM9_Cat_Line->currentText());
                               GCG_GL_CM9.replace("GL_CM_Comp1_Line", GL_CM9_Comp1_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Comp2_Line", GL_CM9_Comp2_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Comp3_Line", GL_CM9_Comp3_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Alg1_Line", GL_CM9_Alg1_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Alg2_Line", GL_CM9_Alg2_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Alg3_Line", GL_CM9_Alg3_Line->text());
                               GCG_GL_CM9.replace("GL_CM_Desc_Line", GL_CM9_Desc_Line->toPlainText());
                       }
                       if(count >= 10){
                           QString fileNameGlCm10 = settings.value("Configuration/TemplateGL").toString() + "\\cm.cfg";
                           QFile fileGlCM10(fileNameGlCm10);
                           fileGlCM10.open(QIODevice::ReadOnly | QIODevice::Text);
                           QTextStream fluxGlCM10(&fileGlCM10);
                           fluxGlCM10.setCodec("UTF-8");
                           //Lecture du Template Glace_CM
                               GCG_GL_CM10 = fluxGlCM10.readAll();
                           //Remplacement des Variables par les valeurs stockés dans le registre
                               GCG_GL_CM10.replace("GL_CM_Name_Line", GL_CM10_Name_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Img_Line", GL_CM10_Img_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Cat_Line", GL_CM10_Cat_Line->currentText());
                               GCG_GL_CM10.replace("GL_CM_Comp1_Line", GL_CM10_Comp1_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Comp2_Line", GL_CM10_Comp2_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Comp3_Line", GL_CM10_Comp3_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Alg1_Line", GL_CM10_Alg1_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Alg2_Line", GL_CM10_Alg2_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Alg3_Line", GL_CM10_Alg3_Line->text());
                               GCG_GL_CM10.replace("GL_CM_Desc_Line", GL_CM10_Desc_Line->toPlainText());
                       }

            //Importation du Template Glace_Alrt
                QString fileNameGlAlrt = settings.value("Configuration/TemplateGL").toString() + "\\alrt.cfg";
                QFile fileGlAlrt(fileNameGlAlrt);
                fileGlAlrt.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream fluxGlAlrt(&fileGlAlrt);
                fluxGlAlrt.setCodec("UTF-8");

                    //Lecture du Template Glace_Alrt
                        GCG_GL_Alrt = fluxGlAlrt.readAll();
                    //Remplacement des Variables par les valeurs stockés dans le registre
                        GCG_GL_Alrt.replace("GL_CM_NAlrt1_Line", GL_CM_NAlrt1_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_NAlrt2_Line", GL_CM_NAlrt2_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_NAlrt3_Line", GL_CM_NAlrt3_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_FAlrt1_Line", GL_CM_FAlrt1_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_FAlrt2_Line", GL_CM_FAlrt2_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_FAlrt3_Line", GL_CM_FAlrt3_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_HAlrt1_Line", GL_CM_HAlrt1_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_HAlrt2_Line", GL_CM_HAlrt2_Line->text());
                        GCG_GL_Alrt.replace("GL_CM_HAlrt3_Line", GL_CM_HAlrt3_Line->text());
            }
        //START_GL_Plan
            //Importation du Template GL_Plan
                QString fileNameGlPlan = settings.value("Configuration/TemplateGL").toString() + "\\plan.cfg";
                QFile fileGlPlan(fileNameGlPlan);
                fileGlPlan.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream fluxGlPlan(&fileGlPlan);
                fluxGlPlan.setCodec("UTF-8");

                    //Lecture du Template GL_Plan
                        GCG_GL_Plan = fluxGlPlan.readAll();
                    //Remplacement des Variables par les valeurs stockés dans le registre
                        GCG_GL_Plan.replace("GL_PL_Img_Line", GL_Main_Plan_Line->text());
        //END_GL_Plan

        //START_GL_Lvl
            //Importation du Template GL_Lvl
                if(glaceon == 1){
                    QString fileNameGlLvl = settings.value("Configuration/TemplateGL").toString() + "\\lvl_cm.cfg";
                    QFile fileGlLvl(fileNameGlLvl);
                    fileGlLvl.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream fluxGlLvl(&fileGlLvl);
                    fluxGlLvl.setCodec("UTF-8");

                        //Lecture du Template GL_Plan
                            GCG_GL_Lvl1 = fluxGlLvl.readAll();
                        //Remplacement des Variables par les valeurs stockés dans le registre
                            GCG_GL_Lvl1.replace("GL_LV_Nbr_Line", "1");
                            GCG_GL_Lvl1.replace("GL_LV_Img_Line", GL_LVl1_Img1_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_CM1_Line", QString::number(GL_Lvl1_CM1_Nbr_Line->value()) + "X " + GL_Lvl1_CM1_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_CM2_Line", QString::number(GL_Lvl1_CM2_Nbr_Line->value()) + "X " + GL_Lvl1_CM2_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_CM3_Line", QString::number(GL_Lvl1_CM3_Nbr_Line->value()) + "X " + GL_Lvl1_CM3_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_CM4_Line", QString::number(GL_Lvl1_CM4_Nbr_Line->value()) + "X " + GL_Lvl1_CM4_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_CM5_Line", QString::number(GL_Lvl1_CM5_Nbr_Line->value()) + "X " + GL_Lvl1_CM5_Line->text());

                            int GCG_GL_Lvl1_VCM1 = GL_Lvl1_CM1_Nbr_Line->value();
                            int GCG_GL_Lvl1_VCM2 = GL_Lvl1_CM2_Nbr_Line->value();
                            int GCG_GL_Lvl1_VCM3 = GL_Lvl1_CM3_Nbr_Line->value();
                            int GCG_GL_Lvl1_VCM4 = GL_Lvl1_CM4_Nbr_Line->value();
                            int GCG_GL_Lvl1_VCM5 = GL_Lvl1_CM5_Nbr_Line->value();

                            int GCG_GL_Lvl1_VCMR = GCG_GL_Lvl1_VCM1 + GCG_GL_Lvl1_VCM2 + GCG_GL_Lvl1_VCM3 + GCG_GL_Lvl1_VCM4 + GCG_GL_Lvl1_VCM5;

                            GCG_GL_Lvl1.replace("GL_LV_CMR_Line", QString::number(GCG_GL_Lvl1_VCMR));
                            GCG_GL_Lvl1.replace("GL_LV_Desc_Line", GL_LVl1_Desc1_Line->toPlainText());
                            GCG_GL_Lvl1.replace("GL_LV_PImg_Line", GL_LVl1_PImg1_Line->text());

                            if(countL >= 2){
                                QString fileNameGlLvl2 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_cm.cfg";
                                QFile fileGlLvl2(fileNameGlLvl2);
                                fileGlLvl2.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl2(&fileGlLvl2);
                                fluxGlLvl2.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl2 = fluxGlLvl2.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl2.replace("GL_LV_Nbr_Line", "2");
                                    GCG_GL_Lvl2.replace("GL_LV_Img_Line", GL_LVl2_Img1_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_CM1_Line", QString::number(GL_Lvl2_CM1_Nbr_Line->value()) + "X " + GL_Lvl2_CM1_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_CM2_Line", QString::number(GL_Lvl2_CM2_Nbr_Line->value()) + "X " + GL_Lvl2_CM2_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_CM3_Line", QString::number(GL_Lvl2_CM3_Nbr_Line->value()) + "X " + GL_Lvl2_CM3_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_CM4_Line", QString::number(GL_Lvl2_CM4_Nbr_Line->value()) + "X " + GL_Lvl2_CM4_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_CM5_Line", QString::number(GL_Lvl2_CM5_Nbr_Line->value()) + "X " + GL_Lvl2_CM5_Line->text());

                                    int GCG_GL_Lvl2_VCM1 = GL_Lvl2_CM1_Nbr_Line->value();
                                    int GCG_GL_Lvl2_VCM2 = GL_Lvl2_CM2_Nbr_Line->value();
                                    int GCG_GL_Lvl2_VCM3 = GL_Lvl2_CM3_Nbr_Line->value();
                                    int GCG_GL_Lvl2_VCM4 = GL_Lvl2_CM4_Nbr_Line->value();
                                    int GCG_GL_Lvl2_VCM5 = GL_Lvl2_CM5_Nbr_Line->value();

                                    int GCG_GL_Lvl2_VCMR = GCG_GL_Lvl2_VCM1 + GCG_GL_Lvl2_VCM2 + GCG_GL_Lvl2_VCM3 + GCG_GL_Lvl2_VCM4 + GCG_GL_Lvl2_VCM5;

                                    GCG_GL_Lvl2.replace("GL_LV_CMR_Line", QString::number(GCG_GL_Lvl2_VCMR));
                                    GCG_GL_Lvl2.replace("GL_LV_Desc_Line", GL_LVl2_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl2.replace("GL_LV_PImg_Line", GL_LVl2_PImg1_Line->text());
                            }
                            if(countL >= 3){
                                QString fileNameGlLvl3 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_cm.cfg";
                                QFile fileGlLvl3(fileNameGlLvl3);
                                fileGlLvl3.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl3(&fileGlLvl3);
                                fluxGlLvl3.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl3 = fluxGlLvl3.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl3.replace("GL_LV_Nbr_Line", "3");
                                    GCG_GL_Lvl3.replace("GL_LV_Img_Line", GL_LVl3_Img1_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_CM1_Line", QString::number(GL_Lvl3_CM1_Nbr_Line->value()) + "X " + GL_Lvl3_CM1_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_CM2_Line", QString::number(GL_Lvl3_CM2_Nbr_Line->value()) + "X " + GL_Lvl3_CM2_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_CM3_Line", QString::number(GL_Lvl3_CM3_Nbr_Line->value()) + "X " + GL_Lvl3_CM3_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_CM4_Line", QString::number(GL_Lvl3_CM4_Nbr_Line->value()) + "X " + GL_Lvl3_CM4_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_CM5_Line", QString::number(GL_Lvl3_CM5_Nbr_Line->value()) + "X " + GL_Lvl3_CM5_Line->text());

                                    int GCG_GL_Lvl3_VCM1 = GL_Lvl1_CM1_Nbr_Line->value();
                                    int GCG_GL_Lvl3_VCM2 = GL_Lvl1_CM2_Nbr_Line->value();
                                    int GCG_GL_Lvl3_VCM3 = GL_Lvl1_CM3_Nbr_Line->value();
                                    int GCG_GL_Lvl3_VCM4 = GL_Lvl1_CM4_Nbr_Line->value();
                                    int GCG_GL_Lvl3_VCM5 = GL_Lvl1_CM5_Nbr_Line->value();

                                    int GCG_GL_Lvl3_VCMR = GCG_GL_Lvl3_VCM1 + GCG_GL_Lvl3_VCM2 + GCG_GL_Lvl3_VCM3 + GCG_GL_Lvl3_VCM4 + GCG_GL_Lvl3_VCM5;

                                    GCG_GL_Lvl3.replace("GL_LV_CMR_Line", QString::number(GCG_GL_Lvl3_VCMR));
                                    GCG_GL_Lvl3.replace("GL_LV_Desc_Line", GL_LVl3_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl3.replace("GL_LV_PImg_Line", GL_LVl3_PImg1_Line->text());
                            }
                            if(countL >= 4){
                                QString fileNameGlLvl4 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_cm.cfg";
                                QFile fileGlLvl4(fileNameGlLvl4);
                                fileGlLvl4.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl4(&fileGlLvl4);
                                fluxGlLvl4.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl4 = fluxGlLvl4.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl4.replace("GL_LV_Nbr_Line", "4");
                                    GCG_GL_Lvl4.replace("GL_LV_Img_Line", GL_LVl4_Img1_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_CM1_Line", QString::number(GL_Lvl4_CM1_Nbr_Line->value()) + "X " + GL_Lvl4_CM1_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_CM2_Line", QString::number(GL_Lvl4_CM2_Nbr_Line->value()) + "X " + GL_Lvl4_CM2_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_CM3_Line", QString::number(GL_Lvl4_CM3_Nbr_Line->value()) + "X " + GL_Lvl4_CM3_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_CM4_Line", QString::number(GL_Lvl4_CM4_Nbr_Line->value()) + "X " + GL_Lvl4_CM4_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_CM5_Line", QString::number(GL_Lvl4_CM5_Nbr_Line->value()) + "X " + GL_Lvl4_CM5_Line->text());

                                    int GCG_GL_Lvl4_VCM1 = GL_Lvl4_CM1_Nbr_Line->value();
                                    int GCG_GL_Lvl4_VCM2 = GL_Lvl4_CM2_Nbr_Line->value();
                                    int GCG_GL_Lvl4_VCM3 = GL_Lvl4_CM3_Nbr_Line->value();
                                    int GCG_GL_Lvl4_VCM4 = GL_Lvl4_CM4_Nbr_Line->value();
                                    int GCG_GL_Lvl4_VCM5 = GL_Lvl4_CM5_Nbr_Line->value();

                                    int GCG_GL_Lvl4_VCMR = GCG_GL_Lvl4_VCM1 + GCG_GL_Lvl4_VCM2 + GCG_GL_Lvl4_VCM3 + GCG_GL_Lvl4_VCM4 + GCG_GL_Lvl4_VCM5;

                                    GCG_GL_Lvl4.replace("GL_LV_CMR_Line", QString::number(GCG_GL_Lvl4_VCMR));
                                    GCG_GL_Lvl4.replace("GL_LV_Desc_Line", GL_LVl4_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl4.replace("GL_LV_PImg_Line", GL_LVl4_PImg1_Line->text());
                            }
                            if(countL >= 5){
                                QString fileNameGlLvl5 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_cm.cfg";
                                QFile fileGlLvl5(fileNameGlLvl5);
                                fileGlLvl5.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl5(&fileGlLvl5);
                                fluxGlLvl5.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl5 = fluxGlLvl5.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl5.replace("GL_LV_Nbr_Line", "5");
                                    GCG_GL_Lvl5.replace("GL_LV_Img_Line", GL_LVl5_Img1_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_CM1_Line", QString::number(GL_Lvl5_CM1_Nbr_Line->value()) + "X " + GL_Lvl5_CM1_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_CM2_Line", QString::number(GL_Lvl5_CM2_Nbr_Line->value()) + "X " + GL_Lvl5_CM2_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_CM3_Line", QString::number(GL_Lvl5_CM3_Nbr_Line->value()) + "X " + GL_Lvl5_CM3_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_CM4_Line", QString::number(GL_Lvl5_CM4_Nbr_Line->value()) + "X " + GL_Lvl5_CM4_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_CM5_Line", QString::number(GL_Lvl5_CM5_Nbr_Line->value()) + "X " + GL_Lvl5_CM5_Line->text());

                                    int GCG_GL_Lvl5_VCM1 = GL_Lvl5_CM1_Nbr_Line->value();
                                    int GCG_GL_Lvl5_VCM2 = GL_Lvl5_CM2_Nbr_Line->value();
                                    int GCG_GL_Lvl5_VCM3 = GL_Lvl5_CM3_Nbr_Line->value();
                                    int GCG_GL_Lvl5_VCM4 = GL_Lvl5_CM4_Nbr_Line->value();
                                    int GCG_GL_Lvl5_VCM5 = GL_Lvl5_CM5_Nbr_Line->value();

                                    int GCG_GL_Lvl5_VCMR = GCG_GL_Lvl5_VCM1 + GCG_GL_Lvl5_VCM2 + GCG_GL_Lvl5_VCM3 + GCG_GL_Lvl5_VCM4 + GCG_GL_Lvl5_VCM5;

                                    GCG_GL_Lvl5.replace("GL_LV_CMR_Line", QString::number(GCG_GL_Lvl5_VCMR));
                                    GCG_GL_Lvl5.replace("GL_LV_Desc_Line", GL_LVl5_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl5.replace("GL_LV_PImg_Line", GL_LVl5_PImg1_Line->text());
                            }
                }
                else{
                    QString fileNameGlHLvl = settings.value("Configuration/TemplateGL").toString() + "\\lvl_hcm.cfg";
                    QFile fileGlLvl(fileNameGlHLvl);
                    fileGlLvl.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream fluxGlLvl(&fileGlLvl);
                    fluxGlLvl.setCodec("UTF-8");

                        //Lecture du Template GL_Plan
                            GCG_GL_Lvl1 = fluxGlLvl.readAll();
                        //Remplacement des Variables par les valeurs stockés dans le registre
                            GCG_GL_Lvl1.replace("GL_LV_Nbr_Line", "1");
                            GCG_GL_Lvl1.replace("GL_LV_Img_Line", GL_LVl1_Img1_Line->text());
                            GCG_GL_Lvl1.replace("GL_LV_Desc_Line", GL_LVl1_Desc1_Line->toPlainText());
                            GCG_GL_Lvl1.replace("GL_LV_PImg_Line", GL_LVl1_PImg1_Line->text());

                            if(countL >= 2){
                                QString fileNameGlHLvl2 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_hcm.cfg";
                                QFile fileGlLvl2(fileNameGlHLvl2);
                                fileGlLvl2.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl2(&fileGlLvl2);
                                fluxGlLvl2.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl2 = fluxGlLvl2.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl2.replace("GL_LV_Nbr_Line", "2");
                                    GCG_GL_Lvl2.replace("GL_LV_Img_Line", GL_LVl2_Img1_Line->text());
                                    GCG_GL_Lvl2.replace("GL_LV_Desc_Line", GL_LVl2_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl2.replace("GL_LV_PImg_Line", GL_LVl2_PImg1_Line->text());
                            }
                            if(countL >= 3){
                                QString fileNameGlHLvl3 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_hcm.cfg";
                                QFile fileGlLvl3(fileNameGlHLvl3);
                                fileGlLvl3.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl3(&fileGlLvl3);
                                fluxGlLvl3.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl3 = fluxGlLvl3.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl3.replace("GL_LV_Nbr_Line", "3");
                                    GCG_GL_Lvl3.replace("GL_LV_Img_Line", GL_LVl3_Img1_Line->text());
                                    GCG_GL_Lvl3.replace("GL_LV_Desc_Line", GL_LVl3_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl3.replace("GL_LV_PImg_Line", GL_LVl3_PImg1_Line->text());
                            }
                            if(countL >= 4){
                                QString fileNameGlHLvl4 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_hcm.cfg";
                                QFile fileGlLvl4(fileNameGlHLvl4);
                                fileGlLvl4.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl4(&fileGlLvl4);
                                fluxGlLvl4.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl4 = fluxGlLvl4.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl4.replace("GL_LV_Nbr_Line", "4");
                                    GCG_GL_Lvl4.replace("GL_LV_Img_Line", GL_LVl4_Img1_Line->text());
                                    GCG_GL_Lvl4.replace("GL_LV_Desc_Line", GL_LVl4_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl4.replace("GL_LV_PImg_Line", GL_LVl4_PImg1_Line->text());
                            }
                            if(countL >= 5){
                                QString fileNameGlHLvl5 = settings.value("Configuration/TemplateGL").toString() + "\\lvl_hcm.cfg";
                                QFile fileGlLvl5(fileNameGlHLvl5);
                                fileGlLvl5.open(QIODevice::ReadOnly | QIODevice::Text);
                                QTextStream fluxGlLvl5(&fileGlLvl5);
                                fluxGlLvl5.setCodec("UTF-8");
                                //Lecture du Template GL_Plan
                                    GCG_GL_Lvl5 = fluxGlLvl5.readAll();
                                //Remplacement des Variables par les valeurs stockés dans le registre
                                    GCG_GL_Lvl5.replace("GL_LV_Nbr_Line", "5");
                                    GCG_GL_Lvl5.replace("GL_LV_Img_Line", GL_LVl5_Img1_Line->text());
                                    GCG_GL_Lvl5.replace("GL_LV_Desc_Line", GL_LVl5_Desc1_Line->toPlainText());
                                    GCG_GL_Lvl5.replace("GL_LV_PImg_Line", GL_LVl5_PImg1_Line->text());
                            }
                }
        //END_Gl_Llv

            QString fileNameGlCmTop = settings.value("Configuration/TemplateGL").toString() + "\\cm_1.cfg";
            QFile fileGlCmTop(fileNameGlCmTop);
            fileGlCmTop.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream fluxGlCmTop(&fileGlCmTop);
            fluxGlCmTop.setCodec("UTF-8");

                //Lecture du Template GL_Plan
                    GCG_GL_CmTop = fluxGlCmTop.readAll();

        //START_Gl_End
            QString fileNameGlEnd = settings.value("Configuration/TemplateGL").toString() + "\\end.cfg";
            QFile fileGlEnd(fileNameGlEnd);
            fileGlEnd.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream fluxGlEnd(&fileGlEnd);
            fluxGlEnd.setCodec("UTF-8");

                //Lecture du Template GL_Plan
                    GCG_GL_End = fluxGlEnd.readAll();
        //END_Gl_End
    //FIN_Glace

    //START_Compil_Glace
        glace += GCG_GL_Main;
        if(glaceon == 1){
            glace += GCG_GL_CmTop;
            glace += GCG_GL_CM1;
            if(count >= 2){
                glace += GCG_GL_CM2;
            }
            if(count >= 3){
                glace += GCG_GL_CM3;
            }
            if(count >= 4){
                glace += GCG_GL_CM4;
            }
            if(count >= 5){
                glace += GCG_GL_CM5;
            }
            if(count >= 6){
                glace += GCG_GL_CM6;
            }
            if(count >= 7){
                glace += GCG_GL_CM7;
            }
            if(count >= 8){
                glace += GCG_GL_CM8;
            }
            if(count >= 9){
                glace += GCG_GL_CM9;
            }
            if(count >= 10){
                glace += GCG_GL_CM10;
            }
            glace += GCG_GL_Alrt;
        }
        glace += GCG_GL_Plan;
        glace += GCG_GL_Lvl1;
        if(countL >= 2){
            glace += GCG_GL_Lvl2;
        }
        if(countL >= 3){
            glace += GCG_GL_Lvl3;
        }
        if(countL >= 4){
            glace += GCG_GL_Lvl4;
        }
        if(countL >= 5){
            glace += GCG_GL_Lvl5;
        }
        glace += GCG_GL_End;

    //END_Compil_Glace

    //Envoi des codes à la classe FrameCodeGenerator
        FrameCodeGenerator *fenetreCode = new FrameCodeGenerator(glace, GCG_Protection, this);
        fenetreCode->exec();
}

void MainFrame::addCM()
{
    count++;
    if(count >10){
        QMessageBox::warning(this, tr("Erreur"), tr("Nombre Maximum de Contre-Mesures atteinte !"));
    }
    else if(count ==2){
        GL_CM2_Name_Line = new QLineEdit;
        GL_CM2_Img_Line = new QLineEdit;
        GL_CM2_Cat_Line = new QComboBox;
        GL_CM2_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM2_Comp1_Line = new QLineEdit;
        GL_CM2_Comp2_Line = new QLineEdit;
        GL_CM2_Comp3_Line = new QLineEdit;
        GL_CM2_Alg1_Line = new QLineEdit;
        GL_CM2_Alg2_Line = new QLineEdit;
        GL_CM2_Alg3_Line = new QLineEdit;
        GL_CM2_Desc_Line = new QTextEdit;

        QFormLayout *L_CM2 = new QFormLayout;
        L_CM2->addRow("&Nom :", GL_CM2_Name_Line);
        L_CM2->addRow("&Url Image :", GL_CM2_Img_Line);
        L_CM2->addRow("&Catégorie :", GL_CM2_Cat_Line);
        L_CM2->addRow("&Composition 1 :", GL_CM2_Comp1_Line);
        L_CM2->addRow("&Composition 2 :", GL_CM2_Comp2_Line);
        L_CM2->addRow("&Composition 3 :", GL_CM2_Comp3_Line);
        L_CM2->addRow("&Algorithme 1 :", GL_CM2_Alg1_Line);
        L_CM2->addRow("&Algorithme 2 :", GL_CM2_Alg2_Line);
        L_CM2->addRow("&Algorithme 3 :", GL_CM2_Alg3_Line);
        L_CM2->addRow("&Description :", GL_CM2_Desc_Line);

        QVBoxLayout *PVB_CM2 = new QVBoxLayout;
        PVB_CM2->addLayout(L_CM2);

        CM2->setLayout(PVB_CM2);

        mainCM->addTab(CM2, "CM2");
    }
    else if(count ==3){
        GL_CM3_Name_Line = new QLineEdit;
        GL_CM3_Img_Line = new QLineEdit;
        GL_CM3_Cat_Line = new QComboBox;
        GL_CM3_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM3_Comp1_Line = new QLineEdit;
        GL_CM3_Comp2_Line = new QLineEdit;
        GL_CM3_Comp3_Line = new QLineEdit;
        GL_CM3_Alg1_Line = new QLineEdit;
        GL_CM3_Alg2_Line = new QLineEdit;
        GL_CM3_Alg3_Line = new QLineEdit;
        GL_CM3_Desc_Line = new QTextEdit;

        QFormLayout *L_CM3 = new QFormLayout;
        L_CM3->addRow("&Nom :", GL_CM3_Name_Line);
        L_CM3->addRow("&Url Image :", GL_CM3_Img_Line);
        L_CM3->addRow("&Catégorie :", GL_CM3_Cat_Line);
        L_CM3->addRow("&Composition 1 :", GL_CM3_Comp1_Line);
        L_CM3->addRow("&Composition 2 :", GL_CM3_Comp2_Line);
        L_CM3->addRow("&Composition 3 :", GL_CM3_Comp3_Line);
        L_CM3->addRow("&Algorithme 1 :", GL_CM3_Alg1_Line);
        L_CM3->addRow("&Algorithme 2 :", GL_CM3_Alg2_Line);
        L_CM3->addRow("&Algorithme 3 :", GL_CM3_Alg3_Line);
        L_CM3->addRow("&Description :", GL_CM3_Desc_Line);

        QVBoxLayout *PVB_CM3 = new QVBoxLayout;
        PVB_CM3->addLayout(L_CM3);

        CM3->setLayout(PVB_CM3);

        mainCM->addTab(CM3, "CM3");
    }
    else if(count ==4){
        GL_CM4_Name_Line = new QLineEdit;
        GL_CM4_Img_Line = new QLineEdit;
        GL_CM4_Cat_Line = new QComboBox;
        GL_CM4_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM4_Comp1_Line = new QLineEdit;
        GL_CM4_Comp2_Line = new QLineEdit;
        GL_CM4_Comp3_Line = new QLineEdit;
        GL_CM4_Alg1_Line = new QLineEdit;
        GL_CM4_Alg2_Line = new QLineEdit;
        GL_CM4_Alg3_Line = new QLineEdit;
        GL_CM4_Desc_Line = new QTextEdit;

        QFormLayout *L_CM4 = new QFormLayout;
        L_CM4->addRow("&Nom :", GL_CM4_Name_Line);
        L_CM4->addRow("&Url Image :", GL_CM4_Img_Line);
        L_CM4->addRow("&Catégorie :", GL_CM4_Cat_Line);
        L_CM4->addRow("&Composition 1 :", GL_CM4_Comp1_Line);
        L_CM4->addRow("&Composition 2 :", GL_CM4_Comp2_Line);
        L_CM4->addRow("&Composition 3 :", GL_CM4_Comp3_Line);
        L_CM4->addRow("&Algorithme 1 :", GL_CM4_Alg1_Line);
        L_CM4->addRow("&Algorithme 2 :", GL_CM4_Alg2_Line);
        L_CM4->addRow("&Algorithme 3 :", GL_CM4_Alg3_Line);
        L_CM4->addRow("&Description :", GL_CM4_Desc_Line);

        QVBoxLayout *PVB_CM4 = new QVBoxLayout;
        PVB_CM4->addLayout(L_CM4);

        CM4->setLayout(PVB_CM4);

        mainCM->addTab(CM4, "CM4");
    }
    else if(count ==5){
        GL_CM5_Name_Line = new QLineEdit;
        GL_CM5_Img_Line = new QLineEdit;
        GL_CM5_Cat_Line = new QComboBox;
        GL_CM5_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM5_Comp1_Line = new QLineEdit;
        GL_CM5_Comp2_Line = new QLineEdit;
        GL_CM5_Comp3_Line = new QLineEdit;
        GL_CM5_Alg1_Line = new QLineEdit;
        GL_CM5_Alg2_Line = new QLineEdit;
        GL_CM5_Alg3_Line = new QLineEdit;
        GL_CM5_Desc_Line = new QTextEdit;

        QFormLayout *L_CM5 = new QFormLayout;
        L_CM5->addRow("&Nom :", GL_CM5_Name_Line);
        L_CM5->addRow("&Url Image :", GL_CM5_Img_Line);
        L_CM5->addRow("&Catégorie :", GL_CM5_Cat_Line);
        L_CM5->addRow("&Composition 1 :", GL_CM5_Comp1_Line);
        L_CM5->addRow("&Composition 2 :", GL_CM5_Comp2_Line);
        L_CM5->addRow("&Composition 3 :", GL_CM5_Comp3_Line);
        L_CM5->addRow("&Algorithme 1 :", GL_CM5_Alg1_Line);
        L_CM5->addRow("&Algorithme 2 :", GL_CM5_Alg2_Line);
        L_CM5->addRow("&Algorithme 3 :", GL_CM5_Alg3_Line);
        L_CM5->addRow("&Description :", GL_CM5_Desc_Line);

        QVBoxLayout *PVB_CM5 = new QVBoxLayout;
        PVB_CM5->addLayout(L_CM5);

        CM5->setLayout(PVB_CM5);

        mainCM->addTab(CM5, "CM5");
    }
    else if(count ==6){
        GL_CM6_Name_Line = new QLineEdit;
        GL_CM6_Img_Line = new QLineEdit;
        GL_CM6_Cat_Line = new QComboBox;
        GL_CM6_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM6_Comp1_Line = new QLineEdit;
        GL_CM6_Comp2_Line = new QLineEdit;
        GL_CM6_Comp3_Line = new QLineEdit;
        GL_CM6_Alg1_Line = new QLineEdit;
        GL_CM6_Alg2_Line = new QLineEdit;
        GL_CM6_Alg3_Line = new QLineEdit;
        GL_CM6_Desc_Line = new QTextEdit;

        QFormLayout *L_CM6 = new QFormLayout;
        L_CM6->addRow("&Nom :", GL_CM6_Name_Line);
        L_CM6->addRow("&Url Image :", GL_CM6_Img_Line);
        L_CM6->addRow("&Catégorie :", GL_CM6_Cat_Line);
        L_CM6->addRow("&Composition 1 :", GL_CM6_Comp1_Line);
        L_CM6->addRow("&Composition 2 :", GL_CM6_Comp2_Line);
        L_CM6->addRow("&Composition 3 :", GL_CM6_Comp3_Line);
        L_CM6->addRow("&Algorithme 1 :", GL_CM6_Alg1_Line);
        L_CM6->addRow("&Algorithme 2 :", GL_CM6_Alg2_Line);
        L_CM6->addRow("&Algorithme 3 :", GL_CM6_Alg3_Line);
        L_CM6->addRow("&Description :", GL_CM6_Desc_Line);

        QVBoxLayout *PVB_CM6 = new QVBoxLayout;
        PVB_CM6->addLayout(L_CM6);

        CM6->setLayout(PVB_CM6);

        mainCM->addTab(CM6, "CM6");
    }
    else if(count ==7){
        GL_CM7_Name_Line = new QLineEdit;
        GL_CM7_Img_Line = new QLineEdit;
        GL_CM7_Cat_Line = new QComboBox;
        GL_CM7_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM7_Comp1_Line = new QLineEdit;
        GL_CM7_Comp2_Line = new QLineEdit;
        GL_CM7_Comp3_Line = new QLineEdit;
        GL_CM7_Alg1_Line = new QLineEdit;
        GL_CM7_Alg2_Line = new QLineEdit;
        GL_CM7_Alg3_Line = new QLineEdit;
        GL_CM7_Desc_Line = new QTextEdit;

        QFormLayout *L_CM7 = new QFormLayout;
        L_CM7->addRow("&Nom :", GL_CM7_Name_Line);
        L_CM7->addRow("&Url Image :", GL_CM7_Img_Line);
        L_CM7->addRow("&Catégorie :", GL_CM7_Cat_Line);
        L_CM7->addRow("&Composition 1 :", GL_CM7_Comp1_Line);
        L_CM7->addRow("&Composition 2 :", GL_CM7_Comp2_Line);
        L_CM7->addRow("&Composition 3 :", GL_CM7_Comp3_Line);
        L_CM7->addRow("&Algorithme 1 :", GL_CM7_Alg1_Line);
        L_CM7->addRow("&Algorithme 2 :", GL_CM7_Alg2_Line);
        L_CM7->addRow("&Algorithme 3 :", GL_CM7_Alg3_Line);
        L_CM7->addRow("&Description :", GL_CM7_Desc_Line);

        QVBoxLayout *PVB_CM7 = new QVBoxLayout;
        PVB_CM7->addLayout(L_CM7);

        CM7->setLayout(PVB_CM7);

        mainCM->addTab(CM7, "CM7");
    }
    else if(count ==8){
        GL_CM8_Name_Line = new QLineEdit;
        GL_CM8_Img_Line = new QLineEdit;
        GL_CM8_Cat_Line = new QComboBox;
        GL_CM8_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM8_Comp1_Line = new QLineEdit;
        GL_CM8_Comp2_Line = new QLineEdit;
        GL_CM8_Comp3_Line = new QLineEdit;
        GL_CM8_Alg1_Line = new QLineEdit;
        GL_CM8_Alg2_Line = new QLineEdit;
        GL_CM8_Alg3_Line = new QLineEdit;
        GL_CM8_Desc_Line = new QTextEdit;

        QFormLayout *L_CM8 = new QFormLayout;
        L_CM8->addRow("&Nom :", GL_CM8_Name_Line);
        L_CM8->addRow("&Url Image :", GL_CM8_Img_Line);
        L_CM8->addRow("&Catégorie :", GL_CM8_Cat_Line);
        L_CM8->addRow("&Composition 1 :", GL_CM8_Comp1_Line);
        L_CM8->addRow("&Composition 2 :", GL_CM8_Comp2_Line);
        L_CM8->addRow("&Composition 3 :", GL_CM8_Comp3_Line);
        L_CM8->addRow("&Algorithme 1 :", GL_CM8_Alg1_Line);
        L_CM8->addRow("&Algorithme 2 :", GL_CM8_Alg2_Line);
        L_CM8->addRow("&Algorithme 3 :", GL_CM8_Alg3_Line);
        L_CM8->addRow("&Description :", GL_CM8_Desc_Line);

        QVBoxLayout *PVB_CM8 = new QVBoxLayout;
        PVB_CM8->addLayout(L_CM8);

        CM8->setLayout(PVB_CM8);

        mainCM->addTab(CM8, "CM8");
    }
    else if(count ==9){
        GL_CM9_Name_Line = new QLineEdit;
        GL_CM9_Img_Line = new QLineEdit;
        GL_CM9_Cat_Line = new QComboBox;
        GL_CM9_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM9_Comp1_Line = new QLineEdit;
        GL_CM9_Comp2_Line = new QLineEdit;
        GL_CM9_Comp3_Line = new QLineEdit;
        GL_CM9_Alg1_Line = new QLineEdit;
        GL_CM9_Alg2_Line = new QLineEdit;
        GL_CM9_Alg3_Line = new QLineEdit;
        GL_CM9_Desc_Line = new QTextEdit;

        QFormLayout *L_CM9 = new QFormLayout;
        L_CM9->addRow("&Nom :", GL_CM9_Name_Line);
        L_CM9->addRow("&Url Image :", GL_CM9_Img_Line);
        L_CM9->addRow("&Catégorie :", GL_CM9_Cat_Line);
        L_CM9->addRow("&Composition 1 :", GL_CM9_Comp1_Line);
        L_CM9->addRow("&Composition 2 :", GL_CM9_Comp2_Line);
        L_CM9->addRow("&Composition 3 :", GL_CM9_Comp3_Line);
        L_CM9->addRow("&Algorithme 1 :", GL_CM9_Alg1_Line);
        L_CM9->addRow("&Algorithme 2 :", GL_CM9_Alg2_Line);
        L_CM9->addRow("&Algorithme 3 :", GL_CM9_Alg3_Line);
        L_CM9->addRow("&Description :", GL_CM9_Desc_Line);

        QVBoxLayout *PVB_CM9 = new QVBoxLayout;
        PVB_CM9->addLayout(L_CM9);

        CM9->setLayout(PVB_CM9);

        mainCM->addTab(CM9, "CM9");
    }
    else if(count ==10){
        GL_CM10_Name_Line = new QLineEdit;
        GL_CM10_Img_Line = new QLineEdit;
        GL_CM10_Cat_Line = new QComboBox;
        GL_CM10_Cat_Line->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
        GL_CM10_Comp1_Line = new QLineEdit;
        GL_CM10_Comp2_Line = new QLineEdit;
        GL_CM10_Comp3_Line = new QLineEdit;
        GL_CM10_Alg1_Line = new QLineEdit;
        GL_CM10_Alg2_Line = new QLineEdit;
        GL_CM10_Alg3_Line = new QLineEdit;
        GL_CM10_Desc_Line = new QTextEdit;

        QFormLayout *L_CM10 = new QFormLayout;
        L_CM10->addRow("&Nom :", GL_CM10_Name_Line);
        L_CM10->addRow("&Url Image :", GL_CM10_Img_Line);
        L_CM10->addRow("&Catégorie :", GL_CM10_Cat_Line);
        L_CM10->addRow("&Composition 1 :", GL_CM10_Comp1_Line);
        L_CM10->addRow("&Composition 2 :", GL_CM10_Comp2_Line);
        L_CM10->addRow("&Composition 3 :", GL_CM10_Comp3_Line);
        L_CM10->addRow("&Algorithme 1 :", GL_CM10_Alg1_Line);
        L_CM10->addRow("&Algorithme 2 :", GL_CM10_Alg2_Line);
        L_CM10->addRow("&Algorithme 3 :", GL_CM10_Alg3_Line);
        L_CM10->addRow("&Description :", GL_CM10_Desc_Line);

        QVBoxLayout *PVB_CM10 = new QVBoxLayout;
        PVB_CM10->addLayout(L_CM10);

        CM10->setLayout(PVB_CM10);

        mainCM->addTab(CM10, "CM10");
    }

}

void MainFrame::stateChanged(QString Slvl)
{
    if(Slvl == "Blanche"){
            GL_CM1_Cat_Line->removeItem(9);
            GL_CM1_Cat_Line->removeItem(9);
            GL_CM1_Cat_Line->removeItem(9);
        if(count >=2){
            GL_CM2_Cat_Line->removeItem(9);
            GL_CM2_Cat_Line->removeItem(9);
            GL_CM2_Cat_Line->removeItem(9);
        }
        if(count >=3){
            GL_CM3_Cat_Line->removeItem(9);
            GL_CM3_Cat_Line->removeItem(9);
            GL_CM3_Cat_Line->removeItem(9);
        }
        if(count >=4){
            GL_CM4_Cat_Line->removeItem(9);
            GL_CM4_Cat_Line->removeItem(9);
            GL_CM4_Cat_Line->removeItem(9);
        }
        if(count >=5){
            GL_CM5_Cat_Line->removeItem(9);
            GL_CM5_Cat_Line->removeItem(9);
            GL_CM5_Cat_Line->removeItem(9);
        }
        if(count >=6){
            GL_CM6_Cat_Line->removeItem(9);
            GL_CM6_Cat_Line->removeItem(9);
            GL_CM6_Cat_Line->removeItem(9);
        }
        if(count >=7){
            GL_CM7_Cat_Line->removeItem(9);
            GL_CM7_Cat_Line->removeItem(9);
            GL_CM7_Cat_Line->removeItem(9);
        }
        if(count >=8){
            GL_CM8_Cat_Line->removeItem(9);
            GL_CM8_Cat_Line->removeItem(9);
            GL_CM8_Cat_Line->removeItem(9);
        }
        if(count >=9){
            GL_CM9_Cat_Line->removeItem(9);
            GL_CM9_Cat_Line->removeItem(9);
            GL_CM9_Cat_Line->removeItem(9);
        }
        if(count >=10){
            GL_CM10_Cat_Line->removeItem(9);
            GL_CM10_Cat_Line->removeItem(9);
            GL_CM10_Cat_Line->removeItem(9);
        }

    } else if (Slvl == "Grise"){
        GL_CM1_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        if(count >=2){
            GL_CM2_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=3){
            GL_CM3_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=4){
            GL_CM4_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=5){
            GL_CM5_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=6){
            GL_CM6_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=7){
            GL_CM7_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=8){
            GL_CM8_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=9){
            GL_CM9_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(count >=10){
            GL_CM10_Cat_Line->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
    }
}

void MainFrame::addLvl()
{
    countL++;
    if(countL >5){
        QMessageBox::warning(this, tr("Erreur"), tr("Nombre Maximum de Niveaux atteint !"));
    }
    else if(countL ==2){
        GL_LVl2_LImg1_Line = new QLabel;
        GL_LVl2_LImg1_Line->setText("Url Image :");
        GL_LVl2_LSpacer1_Line = new QLabel;
        GL_LVl2_LSpacer1_Line->setText("---------------------------------------------------------------------------");
        GL_LVl2_LSpacer2_Line = new QLabel;
        GL_LVl2_LSpacer2_Line->setText("---------------------------------------------------------------------------");
        GL_LVl2_LSpacer3_Line = new QLabel;
        GL_LVl2_LSpacer3_Line->setText("---------------------------------------------------------------------------");
        GL_LVl2_LCM1_Line = new QLabel;
        GL_LVl2_LCM1_Line->setText("Nom CM1 :");
        GL_LVl2_LCM2_Line = new QLabel;
        GL_LVl2_LCM2_Line->setText("Nom CM2 :");
        GL_LVl2_LCM3_Line = new QLabel;
        GL_LVl2_LCM3_Line->setText("Nom CM3 :");
        GL_LVl2_LCM4_Line = new QLabel;
        GL_LVl2_LCM4_Line->setText("Nom CM4 :");
        GL_LVl2_LCM5_Line = new QLabel;
        GL_LVl2_LCM5_Line->setText("Nom CM5 :");
        GL_LVl2_LDesc_Line = new QLabel;
        GL_LVl2_LDesc_Line->setText("Description du Niveau :");
        GL_LVl2_LImg2_Line = new QLabel;
        GL_LVl2_LImg2_Line->setText("Plan du Niveau (Url Image):");
        GL_Lvl2_CM1_Line = new QLineEdit;
        GL_Lvl2_CM1_Nbr_Line = new QSpinBox;
        GL_Lvl2_CM1_Nbr_Line->setMaximumWidth(50);
        GL_LVL2_LCM1NBR_Line = new QLabel;
        GL_LVL2_LCM1NBR_Line->setText("Nbr CM1 :");
        GL_Lvl2_CM2_Line = new QLineEdit;
        GL_Lvl2_CM2_Nbr_Line = new QSpinBox;
        GL_Lvl2_CM2_Nbr_Line->setMaximumWidth(50);
        GL_LVL2_LCM2NBR_Line = new QLabel;
        GL_LVL2_LCM2NBR_Line->setText("Nbr CM2 :");
        GL_Lvl2_CM3_Line = new QLineEdit;
        GL_Lvl2_CM3_Nbr_Line = new QSpinBox;
        GL_Lvl2_CM3_Nbr_Line->setMaximumWidth(50);
        GL_LVL2_LCM3NBR_Line = new QLabel;
        GL_LVL2_LCM3NBR_Line->setText("Nbr CM3 :");
        GL_Lvl2_CM4_Line = new QLineEdit;
        GL_Lvl2_CM4_Nbr_Line = new QSpinBox;
        GL_Lvl2_CM4_Nbr_Line->setMaximumWidth(50);
        GL_LVL2_LCM4NBR_Line = new QLabel;
        GL_LVL2_LCM4NBR_Line->setText("Nbr CM4 :");
        GL_Lvl2_CM5_Line = new QLineEdit;
        GL_Lvl2_CM5_Nbr_Line = new QSpinBox;
        GL_Lvl2_CM5_Nbr_Line->setMaximumWidth(50);
        GL_LVL2_LCM5NBR_Line = new QLabel;
        GL_LVL2_LCM5NBR_Line->setText("Nbr CM5 :");
        GL_LVl2_Img1_Line = new QLineEdit;
        GL_LVl2_Desc1_Line = new QTextEdit;
        GL_LVl2_PImg1_Line = new QLineEdit;

        GL_Lvl2_WCmNbr = new QWidget();
        QHBoxLayout *GL_Lvl2_CmNbr = new QHBoxLayout(GL_Lvl2_WCmNbr);
        GL_Lvl2_CmNbr->addWidget(GL_LVL2_LCM1NBR_Line);
        GL_Lvl2_CmNbr->addWidget(GL_Lvl2_CM1_Nbr_Line);
        GL_Lvl2_CmNbr->addWidget(GL_LVL2_LCM2NBR_Line);
        GL_Lvl2_CmNbr->addWidget(GL_Lvl2_CM2_Nbr_Line);
        GL_Lvl2_CmNbr->addWidget(GL_LVL2_LCM3NBR_Line);
        GL_Lvl2_CmNbr->addWidget(GL_Lvl2_CM3_Nbr_Line);
        GL_Lvl2_CmNbr->addWidget(GL_LVL2_LCM4NBR_Line);
        GL_Lvl2_CmNbr->addWidget(GL_Lvl2_CM4_Nbr_Line);
        GL_Lvl2_CmNbr->addWidget(GL_LVL2_LCM5NBR_Line);
        GL_Lvl2_CmNbr->addWidget(GL_Lvl2_CM5_Nbr_Line);

        GL_LVl2_LSpacer1_Line->setVisible(false);
        GL_LVl2_LCM1_Line->setVisible(false);
        GL_Lvl2_CM1_Line->setVisible(false);
        GL_LVl2_LCM2_Line->setVisible(false);
        GL_Lvl2_CM2_Line->setVisible(false);
        GL_LVl2_LCM3_Line->setVisible(false);
        GL_Lvl2_CM3_Line->setVisible(false);
        GL_LVl2_LCM4_Line->setVisible(false);
        GL_Lvl2_CM4_Line->setVisible(false);
        GL_LVl2_LCM5_Line->setVisible(false);
        GL_Lvl2_CM5_Line->setVisible(false);
        GL_Lvl2_WCmNbr->setVisible(false);

        QGridLayout *GL_Lvl2 = new QGridLayout;
        GL_Lvl2->addWidget(GL_LVl2_LImg1_Line, 0, 0);
        GL_Lvl2->addWidget(GL_LVl2_Img1_Line, 0, 1);
        GL_Lvl2->addWidget(GL_LVl2_LSpacer1_Line, 1, 1, Qt::AlignCenter);
        GL_Lvl2->addWidget(GL_LVl2_LCM1_Line, 2, 0);
        GL_Lvl2->addWidget(GL_Lvl2_CM1_Line, 2, 1);
        GL_Lvl2->addWidget(GL_LVl2_LCM2_Line, 3, 0);
        GL_Lvl2->addWidget(GL_Lvl2_CM2_Line, 3, 1);
        GL_Lvl2->addWidget(GL_LVl2_LCM3_Line, 4, 0);
        GL_Lvl2->addWidget(GL_Lvl2_CM3_Line, 4, 1);
        GL_Lvl2->addWidget(GL_LVl2_LCM4_Line, 5, 0);
        GL_Lvl2->addWidget(GL_Lvl2_CM4_Line, 5, 1);
        GL_Lvl2->addWidget(GL_LVl2_LCM5_Line, 6, 0);
        GL_Lvl2->addWidget(GL_Lvl2_CM5_Line, 6, 1);
        GL_Lvl2->addWidget(GL_Lvl2_WCmNbr, 7, 1);
        GL_Lvl2->addWidget(GL_LVl2_LSpacer2_Line, 8, 1, Qt::AlignCenter);
        GL_Lvl2->addWidget(GL_LVl2_LDesc_Line, 9, 0);
        GL_Lvl2->addWidget(GL_LVl2_Desc1_Line, 9, 1);
        GL_Lvl2->addWidget(GL_LVl2_LSpacer3_Line, 10, 1, Qt::AlignCenter);
        GL_Lvl2->addWidget(GL_LVl2_LImg2_Line, 11, 0);
        GL_Lvl2->addWidget(GL_LVl2_PImg1_Line, 11, 1);

        QVBoxLayout *PVB_Lvl2 = new QVBoxLayout;
        PVB_Lvl2->addLayout(GL_Lvl2);

        Lvl2->setLayout(PVB_Lvl2);
        mainLvl->addTab(Lvl2, "Niveau 2");
    }
    else if(countL ==3){
        GL_LVl3_LImg1_Line = new QLabel;
        GL_LVl3_LImg1_Line->setText("Url Image :");
        GL_LVl3_LSpacer1_Line = new QLabel;
        GL_LVl3_LSpacer1_Line->setText("---------------------------------------------------------------------------");
        GL_LVl3_LSpacer2_Line = new QLabel;
        GL_LVl3_LSpacer2_Line->setText("---------------------------------------------------------------------------");
        GL_LVl3_LSpacer3_Line = new QLabel;
        GL_LVl3_LSpacer3_Line->setText("---------------------------------------------------------------------------");
        GL_LVl3_LCM1_Line = new QLabel;
        GL_LVl3_LCM1_Line->setText("Nom CM1 :");
        GL_LVl3_LCM2_Line = new QLabel;
        GL_LVl3_LCM2_Line->setText("Nom CM2 :");
        GL_LVl3_LCM3_Line = new QLabel;
        GL_LVl3_LCM3_Line->setText("Nom CM3 :");
        GL_LVl3_LCM4_Line = new QLabel;
        GL_LVl3_LCM4_Line->setText("Nom CM4 :");
        GL_LVl3_LCM5_Line = new QLabel;
        GL_LVl3_LCM5_Line->setText("Nom CM5 :");
        GL_LVl3_LDesc_Line = new QLabel;
        GL_LVl3_LDesc_Line->setText("Description du Niveau :");
        GL_LVl3_LImg2_Line = new QLabel;
        GL_LVl3_LImg2_Line->setText("Plan du Niveau (Url Image):");
        GL_Lvl3_CM1_Line = new QLineEdit;
        GL_Lvl3_CM1_Nbr_Line = new QSpinBox;
        GL_Lvl3_CM1_Nbr_Line->setMaximumWidth(50);
        GL_LVL3_LCM1NBR_Line = new QLabel;
        GL_LVL3_LCM1NBR_Line->setText("Nbr CM1 :");
        GL_Lvl3_CM2_Line = new QLineEdit;
        GL_Lvl3_CM2_Nbr_Line = new QSpinBox;
        GL_Lvl3_CM2_Nbr_Line->setMaximumWidth(50);
        GL_LVL3_LCM2NBR_Line = new QLabel;
        GL_LVL3_LCM2NBR_Line->setText("Nbr CM2 :");
        GL_Lvl3_CM3_Line = new QLineEdit;
        GL_Lvl3_CM3_Nbr_Line = new QSpinBox;
        GL_Lvl3_CM3_Nbr_Line->setMaximumWidth(50);
        GL_LVL3_LCM3NBR_Line = new QLabel;
        GL_LVL3_LCM3NBR_Line->setText("Nbr CM3 :");
        GL_Lvl3_CM4_Line = new QLineEdit;
        GL_Lvl3_CM4_Nbr_Line = new QSpinBox;
        GL_Lvl3_CM4_Nbr_Line->setMaximumWidth(50);
        GL_LVL3_LCM4NBR_Line = new QLabel;
        GL_LVL3_LCM4NBR_Line->setText("Nbr CM4 :");
        GL_Lvl3_CM5_Line = new QLineEdit;
        GL_Lvl3_CM5_Nbr_Line = new QSpinBox;
        GL_Lvl3_CM5_Nbr_Line->setMaximumWidth(50);
        GL_LVL3_LCM5NBR_Line = new QLabel;
        GL_LVL3_LCM5NBR_Line->setText("Nbr CM5 :");
        GL_LVl3_Img1_Line = new QLineEdit;
        GL_LVl3_Desc1_Line = new QTextEdit;
        GL_LVl3_PImg1_Line = new QLineEdit;

        GL_Lvl3_WCmNbr = new QWidget();
        QHBoxLayout *GL_Lvl3_CmNbr = new QHBoxLayout(GL_Lvl3_WCmNbr);
        GL_Lvl3_CmNbr->addWidget(GL_LVL3_LCM1NBR_Line);
        GL_Lvl3_CmNbr->addWidget(GL_Lvl3_CM1_Nbr_Line);
        GL_Lvl3_CmNbr->addWidget(GL_LVL3_LCM2NBR_Line);
        GL_Lvl3_CmNbr->addWidget(GL_Lvl3_CM2_Nbr_Line);
        GL_Lvl3_CmNbr->addWidget(GL_LVL3_LCM3NBR_Line);
        GL_Lvl3_CmNbr->addWidget(GL_Lvl3_CM3_Nbr_Line);
        GL_Lvl3_CmNbr->addWidget(GL_LVL3_LCM4NBR_Line);
        GL_Lvl3_CmNbr->addWidget(GL_Lvl3_CM4_Nbr_Line);
        GL_Lvl3_CmNbr->addWidget(GL_LVL3_LCM5NBR_Line);
        GL_Lvl3_CmNbr->addWidget(GL_Lvl3_CM5_Nbr_Line);

        GL_LVl3_LSpacer1_Line->setVisible(false);
        GL_LVl3_LCM1_Line->setVisible(false);
        GL_Lvl3_CM1_Line->setVisible(false);
        GL_LVl3_LCM2_Line->setVisible(false);
        GL_Lvl3_CM2_Line->setVisible(false);
        GL_LVl3_LCM3_Line->setVisible(false);
        GL_Lvl3_CM3_Line->setVisible(false);
        GL_LVl3_LCM4_Line->setVisible(false);
        GL_Lvl3_CM4_Line->setVisible(false);
        GL_LVl3_LCM5_Line->setVisible(false);
        GL_Lvl3_CM5_Line->setVisible(false);
        GL_Lvl3_WCmNbr->setVisible(false);

        QGridLayout *GL_Lvl3 = new QGridLayout;
        GL_Lvl3->addWidget(GL_LVl3_LImg1_Line, 0, 0);
        GL_Lvl3->addWidget(GL_LVl3_Img1_Line, 0, 1);
        GL_Lvl3->addWidget(GL_LVl3_LSpacer1_Line, 1, 1, Qt::AlignCenter);
        GL_Lvl3->addWidget(GL_LVl3_LCM1_Line, 2, 0);
        GL_Lvl3->addWidget(GL_Lvl3_CM1_Line, 2, 1);
        GL_Lvl3->addWidget(GL_LVl3_LCM2_Line, 3, 0);
        GL_Lvl3->addWidget(GL_Lvl3_CM2_Line, 3, 1);
        GL_Lvl3->addWidget(GL_LVl3_LCM3_Line, 4, 0);
        GL_Lvl3->addWidget(GL_Lvl3_CM3_Line, 4, 1);
        GL_Lvl3->addWidget(GL_LVl3_LCM4_Line, 5, 0);
        GL_Lvl3->addWidget(GL_Lvl3_CM4_Line, 5, 1);
        GL_Lvl3->addWidget(GL_LVl3_LCM5_Line, 6, 0);
        GL_Lvl3->addWidget(GL_Lvl3_CM5_Line, 6, 1);
        GL_Lvl3->addWidget(GL_Lvl3_WCmNbr, 7, 1);
        GL_Lvl3->addWidget(GL_LVl3_LSpacer2_Line, 8, 1, Qt::AlignCenter);
        GL_Lvl3->addWidget(GL_LVl3_LDesc_Line, 9, 0);
        GL_Lvl3->addWidget(GL_LVl3_Desc1_Line, 9, 1);
        GL_Lvl3->addWidget(GL_LVl3_LSpacer3_Line, 10, 1, Qt::AlignCenter);
        GL_Lvl3->addWidget(GL_LVl3_LImg2_Line, 11, 0);
        GL_Lvl3->addWidget(GL_LVl3_PImg1_Line, 11, 1);

        QVBoxLayout *PVB_Lvl3 = new QVBoxLayout;
        PVB_Lvl3->addLayout(GL_Lvl3);

        Lvl3->setLayout(PVB_Lvl3);
        mainLvl->addTab(Lvl3, "Niveau 3");
    }
    else if(countL ==4){
        GL_LVl4_LImg1_Line = new QLabel;
        GL_LVl4_LImg1_Line->setText("Url Image :");
        GL_LVl4_LSpacer1_Line = new QLabel;
        GL_LVl4_LSpacer1_Line->setText("---------------------------------------------------------------------------");
        GL_LVl4_LSpacer2_Line = new QLabel;
        GL_LVl4_LSpacer2_Line->setText("---------------------------------------------------------------------------");
        GL_LVl4_LSpacer3_Line = new QLabel;
        GL_LVl4_LSpacer3_Line->setText("---------------------------------------------------------------------------");
        GL_LVl4_LCM1_Line = new QLabel;
        GL_LVl4_LCM1_Line->setText("Nom CM1 :");
        GL_LVl4_LCM2_Line = new QLabel;
        GL_LVl4_LCM2_Line->setText("Nom CM2 :");
        GL_LVl4_LCM3_Line = new QLabel;
        GL_LVl4_LCM3_Line->setText("Nom CM3 :");
        GL_LVl4_LCM4_Line = new QLabel;
        GL_LVl4_LCM4_Line->setText("Nom CM4 :");
        GL_LVl4_LCM5_Line = new QLabel;
        GL_LVl4_LCM5_Line->setText("Nom CM5 :");
        GL_LVl4_LDesc_Line = new QLabel;
        GL_LVl4_LDesc_Line->setText("Description du Niveau :");
        GL_LVl4_LImg2_Line = new QLabel;
        GL_LVl4_LImg2_Line->setText("Plan du Niveau (Url Image):");
        GL_Lvl4_CM1_Line = new QLineEdit;
        GL_Lvl4_CM1_Nbr_Line = new QSpinBox;
        GL_Lvl4_CM1_Nbr_Line->setMaximumWidth(50);
        GL_LVL4_LCM1NBR_Line = new QLabel;
        GL_LVL4_LCM1NBR_Line->setText("Nbr CM1 :");
        GL_Lvl4_CM2_Line = new QLineEdit;
        GL_Lvl4_CM2_Nbr_Line = new QSpinBox;
        GL_Lvl4_CM2_Nbr_Line->setMaximumWidth(50);
        GL_LVL4_LCM2NBR_Line = new QLabel;
        GL_LVL4_LCM2NBR_Line->setText("Nbr CM2 :");
        GL_Lvl4_CM3_Line = new QLineEdit;
        GL_Lvl4_CM3_Nbr_Line = new QSpinBox;
        GL_Lvl4_CM3_Nbr_Line->setMaximumWidth(50);
        GL_LVL4_LCM3NBR_Line = new QLabel;
        GL_LVL4_LCM3NBR_Line->setText("Nbr CM3 :");
        GL_Lvl4_CM4_Line = new QLineEdit;
        GL_Lvl4_CM4_Nbr_Line = new QSpinBox;
        GL_Lvl4_CM4_Nbr_Line->setMaximumWidth(50);
        GL_LVL4_LCM4NBR_Line = new QLabel;
        GL_LVL4_LCM4NBR_Line->setText("Nbr CM4 :");
        GL_Lvl4_CM5_Line = new QLineEdit;
        GL_Lvl4_CM5_Nbr_Line = new QSpinBox;
        GL_Lvl4_CM5_Nbr_Line->setMaximumWidth(50);
        GL_LVL4_LCM5NBR_Line = new QLabel;
        GL_LVL4_LCM5NBR_Line->setText("Nbr CM5 :");
        GL_LVl4_Img1_Line = new QLineEdit;
        GL_LVl4_Desc1_Line = new QTextEdit;
        GL_LVl4_PImg1_Line = new QLineEdit;

        GL_Lvl4_WCmNbr = new QWidget();
        QHBoxLayout *GL_Lvl4_CmNbr = new QHBoxLayout(GL_Lvl4_WCmNbr);
        GL_Lvl4_CmNbr->addWidget(GL_LVL4_LCM1NBR_Line);
        GL_Lvl4_CmNbr->addWidget(GL_Lvl4_CM1_Nbr_Line);
        GL_Lvl4_CmNbr->addWidget(GL_LVL4_LCM2NBR_Line);
        GL_Lvl4_CmNbr->addWidget(GL_Lvl4_CM2_Nbr_Line);
        GL_Lvl4_CmNbr->addWidget(GL_LVL4_LCM3NBR_Line);
        GL_Lvl4_CmNbr->addWidget(GL_Lvl4_CM3_Nbr_Line);
        GL_Lvl4_CmNbr->addWidget(GL_LVL4_LCM4NBR_Line);
        GL_Lvl4_CmNbr->addWidget(GL_Lvl4_CM4_Nbr_Line);
        GL_Lvl4_CmNbr->addWidget(GL_LVL4_LCM5NBR_Line);
        GL_Lvl4_CmNbr->addWidget(GL_Lvl4_CM5_Nbr_Line);

        GL_LVl4_LSpacer1_Line->setVisible(false);
        GL_LVl4_LCM1_Line->setVisible(false);
        GL_Lvl4_CM1_Line->setVisible(false);
        GL_LVl4_LCM2_Line->setVisible(false);
        GL_Lvl4_CM2_Line->setVisible(false);
        GL_LVl4_LCM3_Line->setVisible(false);
        GL_Lvl4_CM3_Line->setVisible(false);
        GL_LVl4_LCM4_Line->setVisible(false);
        GL_Lvl4_CM4_Line->setVisible(false);
        GL_LVl4_LCM5_Line->setVisible(false);
        GL_Lvl4_CM5_Line->setVisible(false);
        GL_Lvl4_WCmNbr->setVisible(false);

        QGridLayout *GL_Lvl4 = new QGridLayout;
        GL_Lvl4->addWidget(GL_LVl4_LImg1_Line, 0, 0);
        GL_Lvl4->addWidget(GL_LVl4_Img1_Line, 0, 1);
        GL_Lvl4->addWidget(GL_LVl4_LSpacer1_Line, 1, 1, Qt::AlignCenter);
        GL_Lvl4->addWidget(GL_LVl4_LCM1_Line, 2, 0);
        GL_Lvl4->addWidget(GL_Lvl4_CM1_Line, 2, 1);
        GL_Lvl4->addWidget(GL_LVl4_LCM2_Line, 3, 0);
        GL_Lvl4->addWidget(GL_Lvl4_CM2_Line, 3, 1);
        GL_Lvl4->addWidget(GL_LVl4_LCM3_Line, 4, 0);
        GL_Lvl4->addWidget(GL_Lvl4_CM3_Line, 4, 1);
        GL_Lvl4->addWidget(GL_LVl4_LCM4_Line, 5, 0);
        GL_Lvl4->addWidget(GL_Lvl4_CM4_Line, 5, 1);
        GL_Lvl4->addWidget(GL_LVl4_LCM5_Line, 6, 0);
        GL_Lvl4->addWidget(GL_Lvl4_CM5_Line, 6, 1);
        GL_Lvl4->addWidget(GL_Lvl4_WCmNbr, 7, 1);
        GL_Lvl4->addWidget(GL_LVl4_LSpacer2_Line, 8, 1, Qt::AlignCenter);
        GL_Lvl4->addWidget(GL_LVl4_LDesc_Line, 9, 0);
        GL_Lvl4->addWidget(GL_LVl4_Desc1_Line, 9, 1);
        GL_Lvl4->addWidget(GL_LVl4_LSpacer3_Line, 10, 1, Qt::AlignCenter);
        GL_Lvl4->addWidget(GL_LVl4_LImg2_Line, 11, 0);
        GL_Lvl4->addWidget(GL_LVl4_PImg1_Line, 11, 1);

        QVBoxLayout *PVB_Lvl4 = new QVBoxLayout;
        PVB_Lvl4->addLayout(GL_Lvl4);

        Lvl4->setLayout(PVB_Lvl4);
        mainLvl->addTab(Lvl4, "Niveau 4");
    }
    else if(countL ==5){
        GL_LVl5_LImg1_Line = new QLabel;
        GL_LVl5_LImg1_Line->setText("Url Image :");
        GL_LVl5_LSpacer1_Line = new QLabel;
        GL_LVl5_LSpacer1_Line->setText("---------------------------------------------------------------------------");
        GL_LVl5_LSpacer2_Line = new QLabel;
        GL_LVl5_LSpacer2_Line->setText("---------------------------------------------------------------------------");
        GL_LVl5_LSpacer3_Line = new QLabel;
        GL_LVl5_LSpacer3_Line->setText("---------------------------------------------------------------------------");
        GL_LVl5_LCM1_Line = new QLabel;
        GL_LVl5_LCM1_Line->setText("Nom CM1 :");
        GL_LVl5_LCM2_Line = new QLabel;
        GL_LVl5_LCM2_Line->setText("Nom CM2 :");
        GL_LVl5_LCM3_Line = new QLabel;
        GL_LVl5_LCM3_Line->setText("Nom CM3 :");
        GL_LVl5_LCM4_Line = new QLabel;
        GL_LVl5_LCM4_Line->setText("Nom CM4 :");
        GL_LVl5_LCM5_Line = new QLabel;
        GL_LVl5_LCM5_Line->setText("Nom CM5 :");
        GL_LVl5_LDesc_Line = new QLabel;
        GL_LVl5_LDesc_Line->setText("Description du Niveau :");
        GL_LVl5_LImg2_Line = new QLabel;
        GL_LVl5_LImg2_Line->setText("Plan du Niveau (Url Image):");
        GL_Lvl5_CM1_Line = new QLineEdit;
        GL_Lvl5_CM1_Nbr_Line = new QSpinBox;
        GL_Lvl5_CM1_Nbr_Line->setMaximumWidth(50);
        GL_LVL5_LCM1NBR_Line = new QLabel;
        GL_LVL5_LCM1NBR_Line->setText("Nbr CM1 :");
        GL_Lvl5_CM2_Line = new QLineEdit;
        GL_Lvl5_CM2_Nbr_Line = new QSpinBox;
        GL_Lvl5_CM2_Nbr_Line->setMaximumWidth(50);
        GL_LVL5_LCM2NBR_Line = new QLabel;
        GL_LVL5_LCM2NBR_Line->setText("Nbr CM2 :");
        GL_Lvl5_CM3_Line = new QLineEdit;
        GL_Lvl5_CM3_Nbr_Line = new QSpinBox;
        GL_Lvl5_CM3_Nbr_Line->setMaximumWidth(50);
        GL_LVL5_LCM3NBR_Line = new QLabel;
        GL_LVL5_LCM3NBR_Line->setText("Nbr CM3 :");
        GL_Lvl5_CM4_Line = new QLineEdit;
        GL_Lvl5_CM4_Nbr_Line = new QSpinBox;
        GL_Lvl5_CM4_Nbr_Line->setMaximumWidth(50);
        GL_LVL5_LCM4NBR_Line = new QLabel;
        GL_LVL5_LCM4NBR_Line->setText("Nbr CM4 :");
        GL_Lvl5_CM5_Line = new QLineEdit;
        GL_Lvl5_CM5_Nbr_Line = new QSpinBox;
        GL_Lvl5_CM5_Nbr_Line->setMaximumWidth(50);
        GL_LVL5_LCM5NBR_Line = new QLabel;
        GL_LVL5_LCM5NBR_Line->setText("Nbr CM5 :");
        GL_LVl5_Img1_Line = new QLineEdit;
        GL_LVl5_Desc1_Line = new QTextEdit;
        GL_LVl5_PImg1_Line = new QLineEdit;

        GL_Lvl5_WCmNbr = new QWidget();
        QHBoxLayout *GL_Lvl5_CmNbr = new QHBoxLayout(GL_Lvl5_WCmNbr);
        GL_Lvl5_CmNbr->addWidget(GL_LVL5_LCM1NBR_Line);
        GL_Lvl5_CmNbr->addWidget(GL_Lvl5_CM1_Nbr_Line);
        GL_Lvl5_CmNbr->addWidget(GL_LVL5_LCM2NBR_Line);
        GL_Lvl5_CmNbr->addWidget(GL_Lvl5_CM2_Nbr_Line);
        GL_Lvl5_CmNbr->addWidget(GL_LVL5_LCM3NBR_Line);
        GL_Lvl5_CmNbr->addWidget(GL_Lvl5_CM3_Nbr_Line);
        GL_Lvl5_CmNbr->addWidget(GL_LVL5_LCM4NBR_Line);
        GL_Lvl5_CmNbr->addWidget(GL_Lvl5_CM4_Nbr_Line);
        GL_Lvl5_CmNbr->addWidget(GL_LVL5_LCM5NBR_Line);
        GL_Lvl5_CmNbr->addWidget(GL_Lvl5_CM5_Nbr_Line);

        GL_LVl5_LSpacer1_Line->setVisible(false);
        GL_LVl5_LCM1_Line->setVisible(false);
        GL_Lvl5_CM1_Line->setVisible(false);
        GL_LVl5_LCM2_Line->setVisible(false);
        GL_Lvl5_CM2_Line->setVisible(false);
        GL_LVl5_LCM3_Line->setVisible(false);
        GL_Lvl5_CM3_Line->setVisible(false);
        GL_LVl5_LCM4_Line->setVisible(false);
        GL_Lvl5_CM4_Line->setVisible(false);
        GL_LVl5_LCM5_Line->setVisible(false);
        GL_Lvl5_CM5_Line->setVisible(false);
        GL_Lvl5_WCmNbr->setVisible(false);

        QGridLayout *GL_Lvl5 = new QGridLayout;
        GL_Lvl5->addWidget(GL_LVl5_LImg1_Line, 0, 0);
        GL_Lvl5->addWidget(GL_LVl5_Img1_Line, 0, 1);
        GL_Lvl5->addWidget(GL_LVl5_LSpacer1_Line, 1, 1, Qt::AlignCenter);
        GL_Lvl5->addWidget(GL_LVl5_LCM1_Line, 2, 0);
        GL_Lvl5->addWidget(GL_Lvl5_CM1_Line, 2, 1);
        GL_Lvl5->addWidget(GL_LVl5_LCM2_Line, 3, 0);
        GL_Lvl5->addWidget(GL_Lvl5_CM2_Line, 3, 1);
        GL_Lvl5->addWidget(GL_LVl5_LCM3_Line, 4, 0);
        GL_Lvl5->addWidget(GL_Lvl5_CM3_Line, 4, 1);
        GL_Lvl5->addWidget(GL_LVl5_LCM4_Line, 5, 0);
        GL_Lvl5->addWidget(GL_Lvl5_CM4_Line, 5, 1);
        GL_Lvl5->addWidget(GL_LVl5_LCM5_Line, 6, 0);
        GL_Lvl5->addWidget(GL_Lvl5_CM5_Line, 6, 1);
        GL_Lvl5->addWidget(GL_Lvl5_WCmNbr, 7, 1);
        GL_Lvl5->addWidget(GL_LVl5_LSpacer2_Line, 8, 1, Qt::AlignCenter);
        GL_Lvl5->addWidget(GL_LVl5_LDesc_Line, 9, 0);
        GL_Lvl5->addWidget(GL_LVl5_Desc1_Line, 9, 1);
        GL_Lvl5->addWidget(GL_LVl5_LSpacer3_Line, 10, 1, Qt::AlignCenter);
        GL_Lvl5->addWidget(GL_LVl5_LImg2_Line, 11, 0);
        GL_Lvl5->addWidget(GL_LVl5_PImg1_Line, 11, 1);

        QVBoxLayout *PVB_Lvl5 = new QVBoxLayout;
        PVB_Lvl5->addLayout(GL_Lvl5);

        Lvl5->setLayout(PVB_Lvl5);
        mainLvl->addTab(Lvl5, "Niveau 5");
    }
}

void MainFrame::uniqIDShow(){
    QSettings settings("Exiel", "DC_Tools");

    QString UniqID;
    UniqID = settings.value("Configuration/ID").toString();

    QMessageBox::information(this, tr("ID Unique"), tr("L'ID unique de cet ordinateur est : ") + UniqID);
}
