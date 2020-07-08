#include "mainframe.h"
#include "framecodegenerator.h"
#include "config.h"

MainFrame::MainFrame()
{
    version = "1.0";
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint );
    resize(510, 680);

    centralArea = new QWidget;

    //Creating ToolBar Menu
        QToolBar *mainToolBar = addToolBar("Main");
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(40, 40));

        //Add Left Buttons
            QAction *programButton = mainToolBar->addAction("&Programme");
            QAction *glaceButton = mainToolBar->addAction("&GLACE/RV");
            QAction *aiButton = mainToolBar->addAction("&IA");
        //Add Spacer
            QWidget *spacer = new QWidget();
            spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            mainToolBar->addWidget(spacer);
        //Add Right-Left Buttons
            QAction *updateButton = mainToolBar->addAction("&Mise à Jour");
            QAction *configButton = mainToolBar->addAction("&Config");
        //Add Separator
            mainToolBar->addSeparator();
        //Add Right-Right Buttons
            QAction *minimizeButton = mainToolBar->addAction("&Réduire");
            QAction *exitButton = mainToolBar->addAction("&Fermer");

        //Add Icons to Buttons
            programButton->setIcon(QIcon(":/images/program"));
            glaceButton->setIcon(QIcon(":/images/glace"));
            aiButton->setIcon(QIcon(":/images/ai"));
            updateButton->setIcon(QIcon(":/images/update"));
            configButton->setIcon(QIcon(":/images/config"));
            minimizeButton->setIcon(QIcon(":/images/minimize"));
            exitButton->setIcon(QIcon(":/images/exit"));

    //Signals
        connect(programButton, SIGNAL(triggered()), this, SLOT(program()));
        connect(glaceButton, SIGNAL(triggered()), this, SLOT(glace()));
        connect(aiButton, SIGNAL(triggered()), this, SLOT(ai()));
        connect(updateButton, SIGNAL(triggered()), this, SLOT(updater()));
        connect(configButton, SIGNAL(triggered()), this, SLOT(config()));
        connect(minimizeButton, SIGNAL(triggered()), this, SLOT(showMinimized()));
        connect(exitButton, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Shortcuts
        new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_U), this, SLOT(uniqueIdShow()));

    setCentralWidget(centralArea);
}

void MainFrame::program()
{
    QSettings settings("Exiel", "DC_Tools");
    //Window Name
        PRG_WindowName = new QLabel("Créateur de Programme");
    //Program Main Frame
        //Main Group
            PRG_Main_Name = new QLineEdit;
            PRG_Main_Desc = new QLineEdit;

            //Main Group Layout
                QFormLayout *PRG_Main_Layout = new QFormLayout;
                PRG_Main_Layout->addRow("&Nom :", PRG_Main_Name);
                PRG_Main_Layout->addRow("&Description :", PRG_Main_Desc);

            //Main Group GroupBox
                QGroupBox *PRG_Main_GroupBox = new QGroupBox("Principal");
                PRG_Main_GroupBox->setLayout(PRG_Main_Layout);

        //Description Group
            PRG_Desc_Img = new QLineEdit;
            PRG_Desc_Desc = new QTextEdit;

            //Description Group Layout
                QFormLayout *PRG_Desc_Layout = new QFormLayout;
                PRG_Desc_Layout->addRow("&Image (URL) :", PRG_Desc_Img);
                PRG_Desc_Layout->addRow("&Description Complète :", PRG_Desc_Desc);

            //Description Group GroupBox
                QGroupBox *PRG_Desc_GroupBox = new QGroupBox("Description");
                PRG_Desc_GroupBox->setLayout(PRG_Desc_Layout);

        //Technical_Sheet Group
            PRG_Tech_Auth = new QLineEdit;
            PRG_Tech_Auth->setText(settings.value("Configuration/Auteur").toString());
            PRG_Tech_Type = new QComboBox;
            PRG_Tech_Type->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Shield" << "Mirror" << "Leurre" << "Cloak" << "Sonde" << "Sniffer" << "Analyseur" << "Booster" << "Assist" << "Override" << "Purge" );
            PRG_Tech_Desc = new QLineEdit;
            PRG_Tech_Auto = new QLineEdit;
            PRG_Tech_Inte = new QLineEdit;
            PRG_Tech_Vers = new QLineEdit;
            PRG_Tech_Acti = new QLineEdit;
            PRG_Tech_Util = new QLineEdit;
            PRG_Tech_Mate = new QLineEdit;
            PRG_Tech_Mate->setText(settings.value("Configuration/Materiel").toString());
            PRG_Tech_Dure = new QLineEdit;


            //Technical_Sheet Group Layout
                QFormLayout *PRG_Tech_Layout = new QFormLayout;
                PRG_Tech_Layout->addRow("&Auteur :", PRG_Tech_Auth);
                PRG_Tech_Layout->addRow("&Type :", PRG_Tech_Type);
                PRG_Tech_Layout->addRow("&Description :", PRG_Tech_Desc);
                PRG_Tech_Layout->addRow("&Autorisations :", PRG_Tech_Auto);
                PRG_Tech_Layout->addRow("&Interdictions :", PRG_Tech_Inte);
                PRG_Tech_Layout->addRow("&Version :", PRG_Tech_Vers);
                PRG_Tech_Layout->addRow("&Activation :", PRG_Tech_Acti);
                PRG_Tech_Layout->addRow("&Utilisation :", PRG_Tech_Util);
                PRG_Tech_Layout->addRow("&Matériel Hôte :", PRG_Tech_Mate);
                PRG_Tech_Layout->addRow("&Durée d'Effet :", PRG_Tech_Dure);

            //Technical_Sheet Group GroupBox
                QGroupBox *PRG_Tech_GroupBox = new QGroupBox("Fiche Technique");
                PRG_Tech_GroupBox->setLayout(PRG_Tech_Layout);

        //Generate Button
            PRG_Generate = new QPushButton("&Générer !");

    //Main Layout
        QVBoxLayout *PRG_Layout = new QVBoxLayout;
        PRG_Layout->addWidget(PRG_WindowName);
        PRG_Layout->addWidget(PRG_Main_GroupBox);
        PRG_Layout->addWidget(PRG_Desc_GroupBox);
        PRG_Layout->addWidget(PRG_Tech_GroupBox);
        PRG_Layout->addWidget(PRG_Generate);

        QWidget *PRG_LayoutWidget = new QWidget();
        PRG_LayoutWidget->setLayout(PRG_Layout);

    //Signals
        connect(PRG_Generate, SIGNAL(clicked()), this, SLOT(generateCodeProgram()));

    setCentralWidget(PRG_LayoutWidget);
}

void MainFrame::glace()
{
    //Window Name
        GL_WindowName = new QLabel("Créateur de GLACE/RV");
    //Glace Main Frame
        GL_Main_Tab = new QTabWidget(this);
        GL_Main_Page = new QWidget;
        GL_Cm_Page = new QWidget;
        GL_Alarm_Page = new QWidget;
        GL_Lvl_Page = new QWidget;

        //Main Page
            GL_Main_Name = new QLineEdit;
            GL_Main_Img = new QLineEdit;
            GL_Main_Vers = new QLineEdit;
            GL_Main_Desc = new QTextEdit;
            GL_Main_Plan = new QLineEdit;
            GL_Main_GlaceCheck = new QCheckBox;

            //Main Page Layout
                QFormLayout *GL_Main_Layout = new QFormLayout;
                GL_Main_Layout->addRow("&Nom :", GL_Main_Name);
                GL_Main_Layout->addRow("&Image (URL) :", GL_Main_Img);
                GL_Main_Layout->addRow("&Version :", GL_Main_Vers);
                GL_Main_Layout->addRow("&Description :", GL_Main_Desc);
                GL_Main_Layout->addRow("&Plan Général d'Intéraction (URL) :", GL_Main_Plan);
                GL_Main_Layout->addRow("&GLACE ?", GL_Main_GlaceCheck);

            GL_Main_Page->setLayout(GL_Main_Layout);

        //Cm Page
            GL_Cm_Tab = new QTabWidget;
            GL_Cm_GLType = new QComboBox;
            GL_Cm_GLType->addItems(QStringList() << "Blanche" << "Grise");
            GL_Cm_AddCM = new QPushButton("&Ajouter Contre-Mesure");

            Gl_Cm_CM1 = new QWidget;
            Gl_Cm_CM2 = new QWidget;
            Gl_Cm_CM3 = new QWidget;
            Gl_Cm_CM4 = new QWidget;
            Gl_Cm_CM5 = new QWidget;
            Gl_Cm_CM6 = new QWidget;
            Gl_Cm_CM7 = new QWidget;
            Gl_Cm_CM8 = new QWidget;
            Gl_Cm_CM9 = new QWidget;
            Gl_Cm_CM10 = new QWidget;

            //CM1
                GL_Cm_CM1_Name = new QLineEdit;
                GL_Cm_CM1_Img = new QLineEdit;
                GL_Cm_CM1_Cat = new QComboBox;
                GL_Cm_CM1_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
                GL_Cm_CM1_Comp1 = new QLineEdit;
                GL_Cm_CM1_Comp2 = new QLineEdit;
                GL_Cm_CM1_Comp3 = new QLineEdit;
                GL_Cm_CM1_Alg1 = new QLineEdit;
                GL_Cm_CM1_Alg2 = new QLineEdit;
                GL_Cm_CM1_Alg3 = new QLineEdit;
                GL_Cm_CM1_Desc = new QTextEdit;

                //Layout Tab CM1
                    QFormLayout *GL_Cm_CM1_Layout = new QFormLayout;
                    GL_Cm_CM1_Layout->addRow("&Nom :", GL_Cm_CM1_Name);
                    GL_Cm_CM1_Layout->addRow("&Image (URL) :", GL_Cm_CM1_Img);
                    GL_Cm_CM1_Layout->addRow("&Catégorie :", GL_Cm_CM1_Cat);
                    GL_Cm_CM1_Layout->addRow("&Composition 1 :", GL_Cm_CM1_Comp1);
                    GL_Cm_CM1_Layout->addRow("&Composition 2 :", GL_Cm_CM1_Comp2);
                    GL_Cm_CM1_Layout->addRow("&Composition 3 :", GL_Cm_CM1_Comp3);
                    GL_Cm_CM1_Layout->addRow("&Algorithme 1 :", GL_Cm_CM1_Alg1);
                    GL_Cm_CM1_Layout->addRow("&Algorithme 2 :", GL_Cm_CM1_Alg2);
                    GL_Cm_CM1_Layout->addRow("&Algorithme 3 :", GL_Cm_CM1_Alg3);
                    GL_Cm_CM1_Layout->addRow("&Description :", GL_Cm_CM1_Desc);

                    QVBoxLayout *GL_Cm_CM1_VLayout = new QVBoxLayout;
                    GL_Cm_CM1_VLayout->addLayout(GL_Cm_CM1_Layout);

            //Layout GLACE Type
                QFormLayout *GL_Cm_GLType_Layout = new QFormLayout;
                GL_Cm_GLType_Layout->addRow("&GLACE :", GL_Cm_GLType);

                QGroupBox *GL_Cm_GLType_GroupBox = new QGroupBox;
                GL_Cm_GLType_GroupBox->setLayout(GL_Cm_GLType_Layout);

            Gl_Cm_CM1->setLayout(GL_Cm_CM1_VLayout);
            GL_Cm_Tab->addTab(Gl_Cm_CM1, "CM1");

            //GLACE Page Layout
                QVBoxLayout *GL_Cm_Layout = new QVBoxLayout;
                GL_Cm_Layout->addWidget(GL_Cm_Tab);
                GL_Cm_Layout->addWidget(GL_Cm_GLType_GroupBox);
                GL_Cm_Layout->addWidget(GL_Cm_AddCM);

            GL_Cm_Page->setLayout(GL_Cm_Layout);

        //Alarm Page
            GL_Alarm_Label1 = new QLabel("Aucune Alerte : Etat passif.");
            GL_Alarm_Label2 = new QLabel("Alerte faible : Légère perturbation dans la RV (absence de cloak, programmes visibles).");
            GL_Alarm_Label3 = new QLabel("Alerte élevée : Plongeurs combatifs, Intrusion réseau détecté, CMs engagées.");

            GL_Alarm_NoAlarm1 = new QLineEdit;
            GL_Alarm_NoAlarm2 = new QLineEdit;
            GL_Alarm_NoAlarm3 = new QLineEdit;

            GL_Alarm_LowAlarm1 = new QLineEdit;
            GL_Alarm_LowAlarm2 = new QLineEdit;
            GL_Alarm_LowAlarm3 = new QLineEdit;

            GL_Alarm_HighAlarm1 = new QLineEdit;
            GL_Alarm_HighAlarm2 = new QLineEdit;
            GL_Alarm_HighAlarm3 = new QLineEdit;

            //Alarm Page Layout
                QFormLayout *GL_Alarm_Layout = new QFormLayout;
                GL_Alarm_Layout->addWidget(GL_Alarm_Label1);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_NoAlarm1);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_NoAlarm2);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_NoAlarm3);
                GL_Alarm_Layout->addWidget(GL_Alarm_Label2);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_LowAlarm1);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_LowAlarm2);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_LowAlarm3);
                GL_Alarm_Layout->addWidget(GL_Alarm_Label3);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_HighAlarm1);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_HighAlarm2);
                GL_Alarm_Layout->addRow("&► ", GL_Alarm_HighAlarm3);

                QGroupBox *GL_Alarm_GroupBox = new QGroupBox;
                GL_Alarm_GroupBox->setLayout(GL_Alarm_Layout);

                QVBoxLayout *GL_Alarm_VLayout = new QVBoxLayout;
                GL_Alarm_VLayout->addWidget(GL_Alarm_GroupBox);

            GL_Alarm_Page->setLayout(GL_Alarm_VLayout);

        //Lvl Page
            GL_Lvl_Tab = new QTabWidget;
            GL_Lvl_AddLvl = new QPushButton("&Ajouter Niveau");

            GL_Lvl_Lvl1 = new QWidget;
            GL_Lvl_Lvl2 = new QWidget;
            GL_Lvl_Lvl3 = new QWidget;
            GL_Lvl_Lvl4 = new QWidget;
            GL_Lvl_Lvl5 = new QWidget;

            //Lvl1
                GL_Lvl_Lvl1_Img = new QLineEdit;
                GL_Lvl_Lvl1_CM1 = new QLineEdit;
                GL_Lvl_Lvl1_CM2 = new QLineEdit;
                GL_Lvl_Lvl1_CM3 = new QLineEdit;
                GL_Lvl_Lvl1_CM4 = new QLineEdit;
                GL_Lvl_Lvl1_CM5 = new QLineEdit;
                GL_Lvl_Lvl1_LNbrCM1 = new QLabel;
                GL_Lvl_Lvl1_LNbrCM1->setText("Nbr CM1 :");
                GL_Lvl_Lvl1_LNbrCM2 = new QLabel;
                GL_Lvl_Lvl1_LNbrCM2->setText("Nbr CM2 :");
                GL_Lvl_Lvl1_LNbrCM3 = new QLabel;
                GL_Lvl_Lvl1_LNbrCM3->setText("Nbr CM3 :");
                GL_Lvl_Lvl1_LNbrCM4 = new QLabel;
                GL_Lvl_Lvl1_LNbrCM4->setText("Nbr CM4 :");
                GL_Lvl_Lvl1_LNbrCM5 = new QLabel;
                GL_Lvl_Lvl1_LNbrCM5->setText("Nbr CM5 :");
                GL_Lvl_Lvl1_NbrCM1 = new QSpinBox;
                GL_Lvl_Lvl1_NbrCM2 = new QSpinBox;
                GL_Lvl_Lvl1_NbrCM3 = new QSpinBox;
                GL_Lvl_Lvl1_NbrCM4 = new QSpinBox;
                GL_Lvl_Lvl1_NbrCM5 = new QSpinBox;
                GL_Lvl_Lvl1_Desc = new QTextEdit;
                GL_Lvl_Lvl1_PlanImg = new QLineEdit;

                GL_Lvl_Lvl1_Spacer1 = new QWidget;
                GL_Lvl_Lvl1_Spacer1->setFixedHeight(2);
                GL_Lvl_Lvl1_Spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                GL_Lvl_Lvl1_Spacer1->setStyleSheet(QString("background-color: #000000;"));

                GL_Lvl_Lvl1_Spacer2 = new QWidget;
                GL_Lvl_Lvl1_Spacer2->setFixedHeight(2);
                GL_Lvl_Lvl1_Spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                GL_Lvl_Lvl1_Spacer2->setStyleSheet(QString("background-color: #000000;"));

                //Layout Nbr Cm Lvl1
                    GL_Lvl_Lvl1_WNbrCM = new QWidget;

                    QHBoxLayout *GL_Lvl_Lvl1_NbrCM_HLayout = new QHBoxLayout(GL_Lvl_Lvl1_WNbrCM);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_LNbrCM1);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_NbrCM1);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_LNbrCM2);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_NbrCM2);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_LNbrCM3);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_NbrCM3);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_LNbrCM4);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_NbrCM4);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_LNbrCM5);
                    GL_Lvl_Lvl1_NbrCM_HLayout->addWidget(GL_Lvl_Lvl1_NbrCM5);

                    GL_Lvl_Lvl1_WCM = new QWidget;
                    QFormLayout *GL_Lvl_Lvl1_CM_Layout = new QFormLayout;
                    GL_Lvl_Lvl1_CM_Layout->addRow("&Nom CM1 :", GL_Lvl_Lvl1_CM1);
                    GL_Lvl_Lvl1_CM_Layout->addRow("&Nom CM2 :", GL_Lvl_Lvl1_CM2);
                    GL_Lvl_Lvl1_CM_Layout->addRow("&Nom CM3 :", GL_Lvl_Lvl1_CM3);
                    GL_Lvl_Lvl1_CM_Layout->addRow("&Nom CM4 :", GL_Lvl_Lvl1_CM4);
                    GL_Lvl_Lvl1_CM_Layout->addRow("&Nom CM5 :", GL_Lvl_Lvl1_CM5);

                    QVBoxLayout *GL_Lvl_Lvl1_CM_VLayout = new QVBoxLayout(GL_Lvl_Lvl1_WCM);
                    GL_Lvl_Lvl1_CM_VLayout->addLayout(GL_Lvl_Lvl1_CM_Layout);

                //Layout Lvl1
                    QFormLayout *GL_Lvl_Lvl1_Layout = new QFormLayout;
                    GL_Lvl_Lvl1_Layout->addRow("&Image (URL) :", GL_Lvl_Lvl1_Img);
                    GL_Lvl_Lvl1_Layout->addWidget(GL_Lvl_Lvl1_Spacer1);
                    GL_Lvl_Lvl1_Layout->addWidget(GL_Lvl_Lvl1_WCM);
                    GL_Lvl_Lvl1_Layout->addWidget(GL_Lvl_Lvl1_WNbrCM);
                    GL_Lvl_Lvl1_Layout->addWidget(GL_Lvl_Lvl1_Spacer2);
                    GL_Lvl_Lvl1_Layout->addRow("&Description :", GL_Lvl_Lvl1_Desc);
                    GL_Lvl_Lvl1_Layout->addRow("&Plan (URL) :", GL_Lvl_Lvl1_PlanImg);

                GL_Lvl_Lvl1_WCM->setVisible(false);
                GL_Lvl_Lvl1_Spacer1->setVisible(false);
                GL_Lvl_Lvl1_Spacer2->setVisible(false);
                GL_Lvl_Lvl1_WNbrCM->setVisible(false);

            QVBoxLayout *GL_Lvl_Lvl1_VLayout = new QVBoxLayout;
            GL_Lvl_Lvl1_VLayout->addLayout(GL_Lvl_Lvl1_Layout);

            GL_Lvl_AddLvl = new QPushButton("&Ajouter Niveau");

            GL_Lvl_Lvl1->setLayout(GL_Lvl_Lvl1_VLayout);
            GL_Lvl_Tab->addTab(GL_Lvl_Lvl1, "&Niveau 1");

            //Lvl Page Layout
                QVBoxLayout *GL_Lvl_VLayout = new QVBoxLayout;
                GL_Lvl_VLayout->addWidget(GL_Lvl_Tab);
                GL_Lvl_VLayout->addWidget(GL_Lvl_AddLvl);

            GL_Lvl_Page->setLayout(GL_Lvl_VLayout);

            QPushButton *GL_Generate = new QPushButton("&Générer !");

        //Main Layout
            GL_Main_Tab->insertTab(0, GL_Main_Page, "&Principal");
            GL_Main_Tab->insertTab(3, GL_Lvl_Page, "&Niveaux");

            QVBoxLayout *GL_MainLayout = new QVBoxLayout;
            GL_MainLayout->addWidget(GL_WindowName);
            GL_MainLayout->addWidget(GL_Main_Tab);
            GL_MainLayout->addWidget(GL_Generate);

            QWidget *GL_LayoutWidget = new QWidget();
            GL_LayoutWidget->setLayout(GL_MainLayout);

    //Signals
        connect(GL_Main_GlaceCheck, SIGNAL(stateChanged(int)), this, SLOT(uGlaceCm(int)));
        connect(GL_Cm_AddCM, SIGNAL(clicked()), this, SLOT(addCm()));
        connect(GL_Cm_GLType, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(stateChanged(QString)));
        connect(GL_Lvl_AddLvl, SIGNAL(clicked()), this, SLOT(addLvl()));
        connect(GL_Generate, SIGNAL(clicked()), this, SLOT(generateCodeGlace()));

    setCentralWidget(GL_LayoutWidget);
}

void MainFrame::ai()
{
    //Window Name
        AI_WindowName = new QLabel("Créateur d'IA");
    //Ai Main Frame
        AI_Main_Tab = new QTabWidget(this);
        AI_Main_Page = new QWidget;
        AI_Desc_Page = new QWidget;
        AI_Tech_Page = new QWidget;

        //Main Page
            AI_Main_Name = new QLineEdit;
            AI_Main_Img = new QLineEdit;

            //Main Page Layout
                QFormLayout *AI_Main_Layout = new QFormLayout;
                AI_Main_Layout->addRow("&Nom :", AI_Main_Name);
                AI_Main_Layout->addRow("&Image (URL) :", AI_Main_Img);

            AI_Main_Page->setLayout(AI_Main_Layout);

        //Desc Page
            AI_Desc_Task = new QTextEdit;
            AI_Desc_Phys = new QTextEdit;
            AI_Desc_Phys_Img = new QLineEdit;
            AI_Desc_Beha = new QTextEdit;
            AI_Desc_Fight = new QTextEdit;
            AI_Desc_Disa = new QTextEdit;

            //Desc Page Layout
                QFormLayout *AI_Desc_Layout = new QFormLayout;
                AI_Desc_Layout->addRow("&Tâche :", AI_Desc_Task);
                AI_Desc_Layout->addRow("&Physique :", AI_Desc_Phys);
                AI_Desc_Layout->addRow("&Apparence (URL) :", AI_Desc_Phys_Img);
                AI_Desc_Layout->addRow("&Comportement Général :", AI_Desc_Beha);
                AI_Desc_Layout->addRow("&Combat :", AI_Desc_Fight);
                AI_Desc_Layout->addRow("&Situation de Désavantage :", AI_Desc_Disa);

            AI_Desc_Page->setLayout(AI_Desc_Layout);

        //Tech Page
            AI_Tech_Nature1 = new QComboBox;
            AI_Tech_Nature1->addItems(QStringList() << "Faible" << "Forte");
            AI_Tech_Nature2 = new QComboBox;
            AI_Tech_Nature2->addItems(QStringList() << "Fixe" << "Evolutive");
            AI_Tech_Nature3 = new QComboBox;
            AI_Tech_Nature3->addItems(QStringList() << "Statique" << "Mobile");
            AI_Tech_Home = new QLineEdit;
            AI_Tech_HomeP = new QLineEdit;
            AI_Tech_HomeM = new QLineEdit;
            AI_Tech_Func = new QTextEdit;
            AI_Tech_Hier = new QTextEdit;
            AI_Tech_Scope = new QTextEdit;
            AI_Tech_Ress = new QTextEdit;
            AI_Tech_Meth = new QTextEdit;

            //Tech Page Layout
                QFormLayout *AI_Tech_Layout = new QFormLayout;
                AI_Tech_Layout->addRow("&Nature :", AI_Tech_Nature1);
                AI_Tech_Layout->addWidget(AI_Tech_Nature2);
                AI_Tech_Layout->addWidget(AI_Tech_Nature3);
                AI_Tech_Layout->addRow("&Hébergement :", AI_Tech_Home);
                AI_Tech_Layout->addRow("&Localisation Physique du Coeur :", AI_Tech_HomeP);
                AI_Tech_Layout->addRow("&Localisation Matricielle du Coeur :", AI_Tech_HomeM);
                AI_Tech_Layout->addRow("&Fonctions/Lois :", AI_Tech_Func);
                AI_Tech_Layout->addRow("&Hiérarchie des Utilisateurs :", AI_Tech_Hier);
                AI_Tech_Layout->addRow("&Portée d'Action de l'IA :", AI_Tech_Scope);
                AI_Tech_Layout->addRow("&Ressources :", AI_Tech_Ress);
                AI_Tech_Layout->addRow("&Méthodes utilisées pour la conception de l'IA :", AI_Tech_Meth);

            AI_Tech_Page->setLayout(AI_Tech_Layout);

            QPushButton *AI_Generate = new QPushButton("&Générer !");

        //Main Layout
            AI_Main_Tab->addTab(AI_Main_Page, "Principal");
            AI_Main_Tab->addTab(AI_Desc_Page, "Description");
            AI_Main_Tab->addTab(AI_Tech_Page, "Détails Techniques");

            QVBoxLayout *AI_MainLayout = new QVBoxLayout;
            AI_MainLayout->addWidget(AI_WindowName);
            AI_MainLayout->addWidget(AI_Main_Tab);
            AI_MainLayout->addWidget(AI_Generate);

            QWidget *AI_LayoutWidget = new QWidget();
            AI_LayoutWidget->setLayout(AI_MainLayout);

        //Signals
            connect(AI_Generate, SIGNAL(clicked()), this, SLOT(generateCodeIa()));

        setCentralWidget(AI_LayoutWidget);
}

void MainFrame::updater()
{
    QNetworkAccessManager Updater_Manager;
    QUrl Updater_Url = QUrl("http://dctools.xyz/DC_Tools/version.txt");
    QTcpSocket Updater_Socket;

    //Connect to the server
    Updater_Socket.connectToHost(Updater_Url.host(), 80);
    if(Updater_Socket.waitForConnected()){
        Updater_Socket.write("HEAD " + Updater_Url.path().toUtf8() + " HTTP/1.1\r\n"
                             "Host: " + Updater_Url.host().toUtf8() + "\r\n\r\n");
        if(Updater_Socket.waitForReadyRead()){
            QByteArray Updater_Bytes = Updater_Socket.readAll();
            //Check if the server is online
            if(Updater_Bytes.contains("200 OK")){
                Updater_Reply = Updater_Manager.get(QNetworkRequest(Updater_Url));
                QEventLoop Updater_Loop;
                QObject::connect(Updater_Reply, SIGNAL(finished()), &Updater_Loop, SLOT(quit()));
                Updater_Loop.exec();
                Updater_Server_Version = Updater_Reply->readAll();
                //Check the server version
                if(version != Updater_Server_Version){
                    QProcess *Updater_Launch = new QProcess(this);
                    Updater_Launch->setProgram("bin/updater.exe");
                    Updater_Launch->startDetached();
                    close();
                }else {
                    QMessageBox::information(this, "UPDATER", "Aucune mise à jours n'a été trouvée.");
                }
            }else {
                QMessageBox::information(this, "ERROR", "Le serveur de Mise à Jours est actuellement Hors-Ligne."
                                                        "Mise à Jour Impossible.");
            }
        }
    }
}

void MainFrame::config()
{
    class Config *Config = new class Config();
    Config->exec();
}

void MainFrame::showMinimized()
{
    setWindowState(Qt::WindowMinimized);
}

void MainFrame::uniqueIdShow()
{
    QSettings settings("Exiel", "DC_Tools");

    QString UniqueID = settings.value("Configuration/ID").toString();

    QMessageBox::information(this, "ID Unique", "L'ID Unique de cet Ordinateur est : " + UniqueID);
}

void MainFrame::uGlaceCm(int state)
{
    if((state == 2) || (state == 1)){
        //Set Glace_State to Active
        Glace_State = 1;

        //Add Pages to Glace Main Tab
        GL_Main_Tab->insertTab(1, GL_Cm_Page, "Contres-Mesures");
        GL_Main_Tab->insertTab(2, GL_Alarm_Page, "Alertes");

        //Set Lvl1 CM Visible
        GL_Lvl_Lvl1_WCM->setVisible(true);
        GL_Lvl_Lvl1_Spacer1->setVisible(true);
        GL_Lvl_Lvl1_Spacer2->setVisible(true);
        GL_Lvl_Lvl1_WNbrCM->setVisible(true);

        if(GL_Lvl_LvlCount >= 2){

            //Set Lvl2 CM Visible
            GL_Lvl_Lvl2_WCM->setVisible(true);
            GL_Lvl_Lvl2_Spacer1->setVisible(true);
            GL_Lvl_Lvl2_Spacer2->setVisible(true);
            GL_Lvl_Lvl2_WNbrCM->setVisible(true);
        }

        if(GL_Lvl_LvlCount >= 3){

            //Set Lvl3 CM Visible
            GL_Lvl_Lvl3_WCM->setVisible(true);
            GL_Lvl_Lvl3_Spacer1->setVisible(true);
            GL_Lvl_Lvl3_Spacer2->setVisible(true);
            GL_Lvl_Lvl3_WNbrCM->setVisible(true);
        }

        if(GL_Lvl_LvlCount >= 4){

            //Set Lvl4 CM Visible
            GL_Lvl_Lvl4_WCM->setVisible(true);
            GL_Lvl_Lvl4_Spacer1->setVisible(true);
            GL_Lvl_Lvl4_Spacer2->setVisible(true);
            GL_Lvl_Lvl4_WNbrCM->setVisible(true);
        }

        if(GL_Lvl_LvlCount >= 5){

            //Set Lvl5 CM Visible
            GL_Lvl_Lvl5_WCM->setVisible(true);
            GL_Lvl_Lvl5_Spacer1->setVisible(true);
            GL_Lvl_Lvl5_Spacer2->setVisible(true);
            GL_Lvl_Lvl5_WNbrCM->setVisible(true);
        }
    }else if(state == 0){

        //Set Glace_State to Inactive
        Glace_State = 0;

        //Remove Pages to Glace Main Tab
        GL_Main_Tab->removeTab(2);
        GL_Main_Tab->removeTab(1);

        //Set Lvl1 CM Invisible
        GL_Lvl_Lvl1_WCM->setVisible(false);
        GL_Lvl_Lvl1_Spacer1->setVisible(false);
        GL_Lvl_Lvl1_Spacer2->setVisible(false);
        GL_Lvl_Lvl1_WNbrCM->setVisible(false);

        if(GL_Lvl_LvlCount >= 2){

            //Set Lvl2 CM Invisible
            GL_Lvl_Lvl2_WCM->setVisible(false);
            GL_Lvl_Lvl2_Spacer1->setVisible(false);
            GL_Lvl_Lvl2_Spacer2->setVisible(false);
            GL_Lvl_Lvl2_WNbrCM->setVisible(false);
        }

        if(GL_Lvl_LvlCount >= 3){

            //Set Lvl3 CM Invisible
            GL_Lvl_Lvl3_WCM->setVisible(false);
            GL_Lvl_Lvl3_Spacer1->setVisible(false);
            GL_Lvl_Lvl3_Spacer2->setVisible(false);
            GL_Lvl_Lvl3_WNbrCM->setVisible(false);
        }

        if(GL_Lvl_LvlCount >= 4){

            //Set Lvl4 CM Invisible
            GL_Lvl_Lvl4_WCM->setVisible(false);
            GL_Lvl_Lvl4_Spacer1->setVisible(false);
            GL_Lvl_Lvl4_Spacer2->setVisible(false);
            GL_Lvl_Lvl4_WNbrCM->setVisible(false);
        }

        if(GL_Lvl_LvlCount >= 5){

            //Set Lvl5 CM Invisible
            GL_Lvl_Lvl5_WCM->setVisible(false);
            GL_Lvl_Lvl5_Spacer1->setVisible(false);
            GL_Lvl_Lvl5_Spacer2->setVisible(false);
            GL_Lvl_Lvl5_WNbrCM->setVisible(false);
        }
    }
}

void MainFrame::addCm()
{
    GL_Cm_CmCount++;
    if(GL_Cm_CmCount >10){
        QMessageBox::information(this, "ERROR", "Nombre maximum de Contres-Mesures atteint !");
    }else if(GL_Cm_CmCount == 2){
        //CM2
            GL_Cm_CM2_Name = new QLineEdit;
            GL_Cm_CM2_Img = new QLineEdit;
            GL_Cm_CM2_Cat = new QComboBox;
            GL_Cm_CM2_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM2_Comp1 = new QLineEdit;
            GL_Cm_CM2_Comp2 = new QLineEdit;
            GL_Cm_CM2_Comp3 = new QLineEdit;
            GL_Cm_CM2_Alg1 = new QLineEdit;
            GL_Cm_CM2_Alg2 = new QLineEdit;
            GL_Cm_CM2_Alg3 = new QLineEdit;
            GL_Cm_CM2_Desc = new QTextEdit;

            //Layout Tab CM2
                QFormLayout *GL_Cm_CM2_Layout = new QFormLayout;
                GL_Cm_CM2_Layout->addRow("&Nom :", GL_Cm_CM2_Name);
                GL_Cm_CM2_Layout->addRow("&Image (URL) :", GL_Cm_CM2_Img);
                GL_Cm_CM2_Layout->addRow("&Catégorie :", GL_Cm_CM2_Cat);
                GL_Cm_CM2_Layout->addRow("&Composition 1 :", GL_Cm_CM2_Comp1);
                GL_Cm_CM2_Layout->addRow("&Composition 2 :", GL_Cm_CM2_Comp2);
                GL_Cm_CM2_Layout->addRow("&Composition 3 :", GL_Cm_CM2_Comp3);
                GL_Cm_CM2_Layout->addRow("&Algorithme 1 :", GL_Cm_CM2_Alg1);
                GL_Cm_CM2_Layout->addRow("&Algorithme 2 :", GL_Cm_CM2_Alg2);
                GL_Cm_CM2_Layout->addRow("&Algorithme 3 :", GL_Cm_CM2_Alg3);
                GL_Cm_CM2_Layout->addRow("&Description :", GL_Cm_CM2_Desc);

                QVBoxLayout *GL_Cm_CM2_VLayout = new QVBoxLayout;
                GL_Cm_CM2_VLayout->addLayout(GL_Cm_CM2_Layout);

        Gl_Cm_CM2->setLayout(GL_Cm_CM2_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM2, "CM2");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 3){
        //CM3
            GL_Cm_CM3_Name = new QLineEdit;
            GL_Cm_CM3_Img = new QLineEdit;
            GL_Cm_CM3_Cat = new QComboBox;
            GL_Cm_CM3_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM3_Comp1 = new QLineEdit;
            GL_Cm_CM3_Comp2 = new QLineEdit;
            GL_Cm_CM3_Comp3 = new QLineEdit;
            GL_Cm_CM3_Alg1 = new QLineEdit;
            GL_Cm_CM3_Alg2 = new QLineEdit;
            GL_Cm_CM3_Alg3 = new QLineEdit;
            GL_Cm_CM3_Desc = new QTextEdit;

            //Layout Tab CM3
                QFormLayout *GL_Cm_CM3_Layout = new QFormLayout;
                GL_Cm_CM3_Layout->addRow("&Nom :", GL_Cm_CM3_Name);
                GL_Cm_CM3_Layout->addRow("&Image (URL) :", GL_Cm_CM3_Img);
                GL_Cm_CM3_Layout->addRow("&Catégorie :", GL_Cm_CM3_Cat);
                GL_Cm_CM3_Layout->addRow("&Composition 1 :", GL_Cm_CM3_Comp1);
                GL_Cm_CM3_Layout->addRow("&Composition 2 :", GL_Cm_CM3_Comp2);
                GL_Cm_CM3_Layout->addRow("&Composition 3 :", GL_Cm_CM3_Comp3);
                GL_Cm_CM3_Layout->addRow("&Algorithme 1 :", GL_Cm_CM3_Alg1);
                GL_Cm_CM3_Layout->addRow("&Algorithme 2 :", GL_Cm_CM3_Alg2);
                GL_Cm_CM3_Layout->addRow("&Algorithme 3 :", GL_Cm_CM3_Alg3);
                GL_Cm_CM3_Layout->addRow("&Description :", GL_Cm_CM3_Desc);

                QVBoxLayout *GL_Cm_CM3_VLayout = new QVBoxLayout;
                GL_Cm_CM3_VLayout->addLayout(GL_Cm_CM3_Layout);

        Gl_Cm_CM3->setLayout(GL_Cm_CM3_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM3, "CM3");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 4){
        //CM4
            GL_Cm_CM4_Name = new QLineEdit;
            GL_Cm_CM4_Img = new QLineEdit;
            GL_Cm_CM4_Cat = new QComboBox;
            GL_Cm_CM4_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM4_Comp1 = new QLineEdit;
            GL_Cm_CM4_Comp2 = new QLineEdit;
            GL_Cm_CM4_Comp3 = new QLineEdit;
            GL_Cm_CM4_Alg1 = new QLineEdit;
            GL_Cm_CM4_Alg2 = new QLineEdit;
            GL_Cm_CM4_Alg3 = new QLineEdit;
            GL_Cm_CM4_Desc = new QTextEdit;

            //Layout Tab CM4
                QFormLayout *GL_Cm_CM4_Layout = new QFormLayout;
                GL_Cm_CM4_Layout->addRow("&Nom :", GL_Cm_CM4_Name);
                GL_Cm_CM4_Layout->addRow("&Image (URL) :", GL_Cm_CM4_Img);
                GL_Cm_CM4_Layout->addRow("&Catégorie :", GL_Cm_CM4_Cat);
                GL_Cm_CM4_Layout->addRow("&Composition 1 :", GL_Cm_CM4_Comp1);
                GL_Cm_CM4_Layout->addRow("&Composition 2 :", GL_Cm_CM4_Comp2);
                GL_Cm_CM4_Layout->addRow("&Composition 3 :", GL_Cm_CM4_Comp3);
                GL_Cm_CM4_Layout->addRow("&Algorithme 1 :", GL_Cm_CM4_Alg1);
                GL_Cm_CM4_Layout->addRow("&Algorithme 2 :", GL_Cm_CM4_Alg2);
                GL_Cm_CM4_Layout->addRow("&Algorithme 3 :", GL_Cm_CM4_Alg3);
                GL_Cm_CM4_Layout->addRow("&Description :", GL_Cm_CM4_Desc);

                QVBoxLayout *GL_Cm_CM4_VLayout = new QVBoxLayout;
                GL_Cm_CM4_VLayout->addLayout(GL_Cm_CM4_Layout);

        Gl_Cm_CM4->setLayout(GL_Cm_CM4_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM4, "CM4");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 5){
        //CM5
            GL_Cm_CM5_Name = new QLineEdit;
            GL_Cm_CM5_Img = new QLineEdit;
            GL_Cm_CM5_Cat = new QComboBox;
            GL_Cm_CM5_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM5_Comp1 = new QLineEdit;
            GL_Cm_CM5_Comp2 = new QLineEdit;
            GL_Cm_CM5_Comp3 = new QLineEdit;
            GL_Cm_CM5_Alg1 = new QLineEdit;
            GL_Cm_CM5_Alg2 = new QLineEdit;
            GL_Cm_CM5_Alg3 = new QLineEdit;
            GL_Cm_CM5_Desc = new QTextEdit;

            //Layout Tab CM5
                QFormLayout *GL_Cm_CM5_Layout = new QFormLayout;
                GL_Cm_CM5_Layout->addRow("&Nom :", GL_Cm_CM5_Name);
                GL_Cm_CM5_Layout->addRow("&Image (URL) :", GL_Cm_CM5_Img);
                GL_Cm_CM5_Layout->addRow("&Catégorie :", GL_Cm_CM5_Cat);
                GL_Cm_CM5_Layout->addRow("&Composition 1 :", GL_Cm_CM5_Comp1);
                GL_Cm_CM5_Layout->addRow("&Composition 2 :", GL_Cm_CM5_Comp2);
                GL_Cm_CM5_Layout->addRow("&Composition 3 :", GL_Cm_CM5_Comp3);
                GL_Cm_CM5_Layout->addRow("&Algorithme 1 :", GL_Cm_CM5_Alg1);
                GL_Cm_CM5_Layout->addRow("&Algorithme 2 :", GL_Cm_CM5_Alg2);
                GL_Cm_CM5_Layout->addRow("&Algorithme 3 :", GL_Cm_CM5_Alg3);
                GL_Cm_CM5_Layout->addRow("&Description :", GL_Cm_CM5_Desc);

                QVBoxLayout *GL_Cm_CM5_VLayout = new QVBoxLayout;
                GL_Cm_CM5_VLayout->addLayout(GL_Cm_CM5_Layout);

        Gl_Cm_CM5->setLayout(GL_Cm_CM5_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM5, "CM5");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 6){
        //CM6
            GL_Cm_CM6_Name = new QLineEdit;
            GL_Cm_CM6_Img = new QLineEdit;
            GL_Cm_CM6_Cat = new QComboBox;
            GL_Cm_CM6_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM6_Comp1 = new QLineEdit;
            GL_Cm_CM6_Comp2 = new QLineEdit;
            GL_Cm_CM6_Comp3 = new QLineEdit;
            GL_Cm_CM6_Alg1 = new QLineEdit;
            GL_Cm_CM6_Alg2 = new QLineEdit;
            GL_Cm_CM6_Alg3 = new QLineEdit;
            GL_Cm_CM6_Desc = new QTextEdit;

            //Layout Tab CM6
                QFormLayout *GL_Cm_CM6_Layout = new QFormLayout;
                GL_Cm_CM6_Layout->addRow("&Nom :", GL_Cm_CM6_Name);
                GL_Cm_CM6_Layout->addRow("&Image (URL) :", GL_Cm_CM6_Img);
                GL_Cm_CM6_Layout->addRow("&Catégorie :", GL_Cm_CM6_Cat);
                GL_Cm_CM6_Layout->addRow("&Composition 1 :", GL_Cm_CM6_Comp1);
                GL_Cm_CM6_Layout->addRow("&Composition 2 :", GL_Cm_CM6_Comp2);
                GL_Cm_CM6_Layout->addRow("&Composition 3 :", GL_Cm_CM6_Comp3);
                GL_Cm_CM6_Layout->addRow("&Algorithme 1 :", GL_Cm_CM6_Alg1);
                GL_Cm_CM6_Layout->addRow("&Algorithme 2 :", GL_Cm_CM6_Alg2);
                GL_Cm_CM6_Layout->addRow("&Algorithme 3 :", GL_Cm_CM6_Alg3);
                GL_Cm_CM6_Layout->addRow("&Description :", GL_Cm_CM6_Desc);

                QVBoxLayout *GL_Cm_CM6_VLayout = new QVBoxLayout;
                GL_Cm_CM6_VLayout->addLayout(GL_Cm_CM6_Layout);

        Gl_Cm_CM6->setLayout(GL_Cm_CM6_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM6, "CM6");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 7){
        //CM7
            GL_Cm_CM7_Name = new QLineEdit;
            GL_Cm_CM7_Img = new QLineEdit;
            GL_Cm_CM7_Cat = new QComboBox;
            GL_Cm_CM7_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM7_Comp1 = new QLineEdit;
            GL_Cm_CM7_Comp2 = new QLineEdit;
            GL_Cm_CM7_Comp3 = new QLineEdit;
            GL_Cm_CM7_Alg1 = new QLineEdit;
            GL_Cm_CM7_Alg2 = new QLineEdit;
            GL_Cm_CM7_Alg3 = new QLineEdit;
            GL_Cm_CM7_Desc = new QTextEdit;

            //Layout Tab CM7
                QFormLayout *GL_Cm_CM7_Layout = new QFormLayout;
                GL_Cm_CM7_Layout->addRow("&Nom :", GL_Cm_CM7_Name);
                GL_Cm_CM7_Layout->addRow("&Image (URL) :", GL_Cm_CM7_Img);
                GL_Cm_CM7_Layout->addRow("&Catégorie :", GL_Cm_CM7_Cat);
                GL_Cm_CM7_Layout->addRow("&Composition 1 :", GL_Cm_CM7_Comp1);
                GL_Cm_CM7_Layout->addRow("&Composition 2 :", GL_Cm_CM7_Comp2);
                GL_Cm_CM7_Layout->addRow("&Composition 3 :", GL_Cm_CM7_Comp3);
                GL_Cm_CM7_Layout->addRow("&Algorithme 1 :", GL_Cm_CM7_Alg1);
                GL_Cm_CM7_Layout->addRow("&Algorithme 2 :", GL_Cm_CM7_Alg2);
                GL_Cm_CM7_Layout->addRow("&Algorithme 3 :", GL_Cm_CM7_Alg3);
                GL_Cm_CM7_Layout->addRow("&Description :", GL_Cm_CM7_Desc);

                QVBoxLayout *GL_Cm_CM7_VLayout = new QVBoxLayout;
                GL_Cm_CM7_VLayout->addLayout(GL_Cm_CM7_Layout);

        Gl_Cm_CM7->setLayout(GL_Cm_CM7_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM7, "CM7");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 8){
        //CM8
            GL_Cm_CM8_Name = new QLineEdit;
            GL_Cm_CM8_Img = new QLineEdit;
            GL_Cm_CM8_Cat = new QComboBox;
            GL_Cm_CM8_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM8_Comp1 = new QLineEdit;
            GL_Cm_CM8_Comp2 = new QLineEdit;
            GL_Cm_CM8_Comp3 = new QLineEdit;
            GL_Cm_CM8_Alg1 = new QLineEdit;
            GL_Cm_CM8_Alg2 = new QLineEdit;
            GL_Cm_CM8_Alg3 = new QLineEdit;
            GL_Cm_CM8_Desc = new QTextEdit;

            //Layout Tab CM8
                QFormLayout *GL_Cm_CM8_Layout = new QFormLayout;
                GL_Cm_CM8_Layout->addRow("&Nom :", GL_Cm_CM8_Name);
                GL_Cm_CM8_Layout->addRow("&Image (URL) :", GL_Cm_CM8_Img);
                GL_Cm_CM8_Layout->addRow("&Catégorie :", GL_Cm_CM8_Cat);
                GL_Cm_CM8_Layout->addRow("&Composition 1 :", GL_Cm_CM8_Comp1);
                GL_Cm_CM8_Layout->addRow("&Composition 2 :", GL_Cm_CM8_Comp2);
                GL_Cm_CM8_Layout->addRow("&Composition 3 :", GL_Cm_CM8_Comp3);
                GL_Cm_CM8_Layout->addRow("&Algorithme 1 :", GL_Cm_CM8_Alg1);
                GL_Cm_CM8_Layout->addRow("&Algorithme 2 :", GL_Cm_CM8_Alg2);
                GL_Cm_CM8_Layout->addRow("&Algorithme 3 :", GL_Cm_CM8_Alg3);
                GL_Cm_CM8_Layout->addRow("&Description :", GL_Cm_CM8_Desc);

                QVBoxLayout *GL_Cm_CM8_VLayout = new QVBoxLayout;
                GL_Cm_CM8_VLayout->addLayout(GL_Cm_CM8_Layout);

        Gl_Cm_CM8->setLayout(GL_Cm_CM8_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM8, "CM8");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 9){
        //CM9
            GL_Cm_CM9_Name = new QLineEdit;
            GL_Cm_CM9_Img = new QLineEdit;
            GL_Cm_CM9_Cat = new QComboBox;
            GL_Cm_CM9_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM9_Comp1 = new QLineEdit;
            GL_Cm_CM9_Comp2 = new QLineEdit;
            GL_Cm_CM9_Comp3 = new QLineEdit;
            GL_Cm_CM9_Alg1 = new QLineEdit;
            GL_Cm_CM9_Alg2 = new QLineEdit;
            GL_Cm_CM9_Alg3 = new QLineEdit;
            GL_Cm_CM9_Desc = new QTextEdit;

            //Layout Tab CM9
                QFormLayout *GL_Cm_CM9_Layout = new QFormLayout;
                GL_Cm_CM9_Layout->addRow("&Nom :", GL_Cm_CM9_Name);
                GL_Cm_CM9_Layout->addRow("&Image (URL) :", GL_Cm_CM9_Img);
                GL_Cm_CM9_Layout->addRow("&Catégorie :", GL_Cm_CM9_Cat);
                GL_Cm_CM9_Layout->addRow("&Composition 1 :", GL_Cm_CM9_Comp1);
                GL_Cm_CM9_Layout->addRow("&Composition 2 :", GL_Cm_CM9_Comp2);
                GL_Cm_CM9_Layout->addRow("&Composition 3 :", GL_Cm_CM9_Comp3);
                GL_Cm_CM9_Layout->addRow("&Algorithme 1 :", GL_Cm_CM9_Alg1);
                GL_Cm_CM9_Layout->addRow("&Algorithme 2 :", GL_Cm_CM9_Alg2);
                GL_Cm_CM9_Layout->addRow("&Algorithme 3 :", GL_Cm_CM9_Alg3);
                GL_Cm_CM9_Layout->addRow("&Description :", GL_Cm_CM9_Desc);

                QVBoxLayout *GL_Cm_CM9_VLayout = new QVBoxLayout;
                GL_Cm_CM9_VLayout->addLayout(GL_Cm_CM9_Layout);

        Gl_Cm_CM9->setLayout(GL_Cm_CM9_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM9, "CM9");

        stateChanged(GL_Cm_GLType->currentText());
    }else if(GL_Cm_CmCount == 10){
        //CM10
            GL_Cm_CM10_Name = new QLineEdit;
            GL_Cm_CM10_Img = new QLineEdit;
            GL_Cm_CM10_Cat = new QComboBox;
            GL_Cm_CM10_Cat->addItems(QStringList() << "Pavlov" << "Databomb" << "Killer" << "Crippler" << "Sonde" << "Trace" << "Sentinelle" << "Brouilleur" << "Environnementale");
            GL_Cm_CM10_Comp1 = new QLineEdit;
            GL_Cm_CM10_Comp2 = new QLineEdit;
            GL_Cm_CM10_Comp3 = new QLineEdit;
            GL_Cm_CM10_Alg1 = new QLineEdit;
            GL_Cm_CM10_Alg2 = new QLineEdit;
            GL_Cm_CM10_Alg3 = new QLineEdit;
            GL_Cm_CM10_Desc = new QTextEdit;

            //Layout Tab CM10
                QFormLayout *GL_Cm_CM10_Layout = new QFormLayout;
                GL_Cm_CM10_Layout->addRow("&Nom :", GL_Cm_CM10_Name);
                GL_Cm_CM10_Layout->addRow("&Image (URL) :", GL_Cm_CM10_Img);
                GL_Cm_CM10_Layout->addRow("&Catégorie :", GL_Cm_CM10_Cat);
                GL_Cm_CM10_Layout->addRow("&Composition 1 :", GL_Cm_CM10_Comp1);
                GL_Cm_CM10_Layout->addRow("&Composition 2 :", GL_Cm_CM10_Comp2);
                GL_Cm_CM10_Layout->addRow("&Composition 3 :", GL_Cm_CM10_Comp3);
                GL_Cm_CM10_Layout->addRow("&Algorithme 1 :", GL_Cm_CM10_Alg1);
                GL_Cm_CM10_Layout->addRow("&Algorithme 2 :", GL_Cm_CM10_Alg2);
                GL_Cm_CM10_Layout->addRow("&Algorithme 3 :", GL_Cm_CM10_Alg3);
                GL_Cm_CM10_Layout->addRow("&Description :", GL_Cm_CM10_Desc);

                QVBoxLayout *GL_Cm_CM10_VLayout = new QVBoxLayout;
                GL_Cm_CM10_VLayout->addLayout(GL_Cm_CM10_Layout);

        Gl_Cm_CM10->setLayout(GL_Cm_CM10_VLayout);
        GL_Cm_Tab->addTab(Gl_Cm_CM10, "CM10");

        stateChanged(GL_Cm_GLType->currentText());
    }
}

void MainFrame::addLvl()
{
    GL_Lvl_LvlCount++;
    if(GL_Lvl_LvlCount > 5){
        QMessageBox::information(this, "ERROR", "Nombre maximum de Niveaux atteint !");
    }else if(GL_Lvl_LvlCount == 2){
        //Lvl 2
            GL_Lvl_Lvl2_Img = new QLineEdit;
            GL_Lvl_Lvl2_CM1 = new QLineEdit;
            GL_Lvl_Lvl2_CM2 = new QLineEdit;
            GL_Lvl_Lvl2_CM3 = new QLineEdit;
            GL_Lvl_Lvl2_CM4 = new QLineEdit;
            GL_Lvl_Lvl2_CM5 = new QLineEdit;
            GL_Lvl_Lvl2_LNbrCM1 = new QLabel;
            GL_Lvl_Lvl2_LNbrCM1->setText("Nbr CM1 :");
            GL_Lvl_Lvl2_LNbrCM2 = new QLabel;
            GL_Lvl_Lvl2_LNbrCM2->setText("Nbr CM2 :");
            GL_Lvl_Lvl2_LNbrCM3 = new QLabel;
            GL_Lvl_Lvl2_LNbrCM3->setText("Nbr CM3 :");
            GL_Lvl_Lvl2_LNbrCM4 = new QLabel;
            GL_Lvl_Lvl2_LNbrCM4->setText("Nbr CM4 :");
            GL_Lvl_Lvl2_LNbrCM5 = new QLabel;
            GL_Lvl_Lvl2_LNbrCM5->setText("Nbr CM5 :");
            GL_Lvl_Lvl2_NbrCM1 = new QSpinBox;
            GL_Lvl_Lvl2_NbrCM2 = new QSpinBox;
            GL_Lvl_Lvl2_NbrCM3 = new QSpinBox;
            GL_Lvl_Lvl2_NbrCM4 = new QSpinBox;
            GL_Lvl_Lvl2_NbrCM5 = new QSpinBox;
            GL_Lvl_Lvl2_Desc = new QTextEdit;
            GL_Lvl_Lvl2_PlanImg = new QLineEdit;

            GL_Lvl_Lvl2_Spacer1 = new QWidget;
            GL_Lvl_Lvl2_Spacer1->setFixedHeight(2);
            GL_Lvl_Lvl2_Spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl2_Spacer1->setStyleSheet(QString("background-color: #000000;"));

            GL_Lvl_Lvl2_Spacer2 = new QWidget;
            GL_Lvl_Lvl2_Spacer2->setFixedHeight(2);
            GL_Lvl_Lvl2_Spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl2_Spacer2->setStyleSheet(QString("background-color: #000000;"));

            //Layout Nbr Cm Lvl2
                GL_Lvl_Lvl2_WNbrCM = new QWidget;

                QHBoxLayout *GL_Lvl_Lvl2_NbrCM_HLayout = new QHBoxLayout(GL_Lvl_Lvl2_WNbrCM);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_LNbrCM1);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_NbrCM1);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_LNbrCM2);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_NbrCM2);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_LNbrCM3);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_NbrCM3);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_LNbrCM4);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_NbrCM4);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_LNbrCM5);
                GL_Lvl_Lvl2_NbrCM_HLayout->addWidget(GL_Lvl_Lvl2_NbrCM5);

                GL_Lvl_Lvl2_WCM = new QWidget;
                QFormLayout *GL_Lvl_Lvl2_CM_Layout = new QFormLayout;
                GL_Lvl_Lvl2_CM_Layout->addRow("&Nom CM1 :", GL_Lvl_Lvl2_CM1);
                GL_Lvl_Lvl2_CM_Layout->addRow("&Nom CM2 :", GL_Lvl_Lvl2_CM2);
                GL_Lvl_Lvl2_CM_Layout->addRow("&Nom CM3 :", GL_Lvl_Lvl2_CM3);
                GL_Lvl_Lvl2_CM_Layout->addRow("&Nom CM4 :", GL_Lvl_Lvl2_CM4);
                GL_Lvl_Lvl2_CM_Layout->addRow("&Nom CM5 :", GL_Lvl_Lvl2_CM5);

                QVBoxLayout *GL_Lvl_Lvl2_CM_VLayout = new QVBoxLayout(GL_Lvl_Lvl2_WCM);
                GL_Lvl_Lvl2_CM_VLayout->addLayout(GL_Lvl_Lvl2_CM_Layout);

            //Layout Lvl2
                QFormLayout *GL_Lvl_Lvl2_Layout = new QFormLayout;
                GL_Lvl_Lvl2_Layout->addRow("&Image (URL) :", GL_Lvl_Lvl2_Img);
                GL_Lvl_Lvl2_Layout->addWidget(GL_Lvl_Lvl2_Spacer1);
                GL_Lvl_Lvl2_Layout->addWidget(GL_Lvl_Lvl2_WCM);
                GL_Lvl_Lvl2_Layout->addWidget(GL_Lvl_Lvl2_WNbrCM);
                GL_Lvl_Lvl2_Layout->addWidget(GL_Lvl_Lvl2_Spacer2);
                GL_Lvl_Lvl2_Layout->addRow("&Description :", GL_Lvl_Lvl2_Desc);
                GL_Lvl_Lvl2_Layout->addRow("&Plan (URL) :", GL_Lvl_Lvl2_PlanImg);

            GL_Lvl_Lvl2_WCM->setVisible(false);
            GL_Lvl_Lvl2_Spacer1->setVisible(false);
            GL_Lvl_Lvl2_Spacer2->setVisible(false);
            GL_Lvl_Lvl2_WNbrCM->setVisible(false);

        QVBoxLayout *GL_Lvl_Lvl2_VLayout = new QVBoxLayout;
        GL_Lvl_Lvl2_VLayout->addLayout(GL_Lvl_Lvl2_Layout);

        GL_Lvl_Lvl2->setLayout(GL_Lvl_Lvl2_VLayout);
        GL_Lvl_Tab->addTab(GL_Lvl_Lvl2, "Niveau 2");

        if(GL_Main_GlaceCheck->isChecked() != 0){
            uGlaceCm(GL_Main_GlaceCheck->isChecked());
        }
    }else if(GL_Lvl_LvlCount == 3){
        //Lvl 3
            GL_Lvl_Lvl3_Img = new QLineEdit;
            GL_Lvl_Lvl3_CM1 = new QLineEdit;
            GL_Lvl_Lvl3_CM2 = new QLineEdit;
            GL_Lvl_Lvl3_CM3 = new QLineEdit;
            GL_Lvl_Lvl3_CM4 = new QLineEdit;
            GL_Lvl_Lvl3_CM5 = new QLineEdit;
            GL_Lvl_Lvl3_LNbrCM1 = new QLabel;
            GL_Lvl_Lvl3_LNbrCM1->setText("Nbr CM1 :");
            GL_Lvl_Lvl3_LNbrCM2 = new QLabel;
            GL_Lvl_Lvl3_LNbrCM2->setText("Nbr CM2 :");
            GL_Lvl_Lvl3_LNbrCM3 = new QLabel;
            GL_Lvl_Lvl3_LNbrCM3->setText("Nbr CM3 :");
            GL_Lvl_Lvl3_LNbrCM4 = new QLabel;
            GL_Lvl_Lvl3_LNbrCM4->setText("Nbr CM4 :");
            GL_Lvl_Lvl3_LNbrCM5 = new QLabel;
            GL_Lvl_Lvl3_LNbrCM5->setText("Nbr CM5 :");
            GL_Lvl_Lvl3_NbrCM1 = new QSpinBox;
            GL_Lvl_Lvl3_NbrCM2 = new QSpinBox;
            GL_Lvl_Lvl3_NbrCM3 = new QSpinBox;
            GL_Lvl_Lvl3_NbrCM4 = new QSpinBox;
            GL_Lvl_Lvl3_NbrCM5 = new QSpinBox;
            GL_Lvl_Lvl3_Desc = new QTextEdit;
            GL_Lvl_Lvl3_PlanImg = new QLineEdit;

            GL_Lvl_Lvl3_Spacer1 = new QWidget;
            GL_Lvl_Lvl3_Spacer1->setFixedHeight(2);
            GL_Lvl_Lvl3_Spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl3_Spacer1->setStyleSheet(QString("background-color: #000000;"));

            GL_Lvl_Lvl3_Spacer2 = new QWidget;
            GL_Lvl_Lvl3_Spacer2->setFixedHeight(2);
            GL_Lvl_Lvl3_Spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl3_Spacer2->setStyleSheet(QString("background-color: #000000;"));

            //Layout Nbr Cm Lvl3
                GL_Lvl_Lvl3_WNbrCM = new QWidget;

                QHBoxLayout *GL_Lvl_Lvl3_NbrCM_HLayout = new QHBoxLayout(GL_Lvl_Lvl3_WNbrCM);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_LNbrCM1);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_NbrCM1);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_LNbrCM2);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_NbrCM2);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_LNbrCM3);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_NbrCM3);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_LNbrCM4);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_NbrCM4);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_LNbrCM5);
                GL_Lvl_Lvl3_NbrCM_HLayout->addWidget(GL_Lvl_Lvl3_NbrCM5);

                GL_Lvl_Lvl3_WCM = new QWidget;
                QFormLayout *GL_Lvl_Lvl3_CM_Layout = new QFormLayout;
                GL_Lvl_Lvl3_CM_Layout->addRow("&Nom CM1 :", GL_Lvl_Lvl3_CM1);
                GL_Lvl_Lvl3_CM_Layout->addRow("&Nom CM2 :", GL_Lvl_Lvl3_CM2);
                GL_Lvl_Lvl3_CM_Layout->addRow("&Nom CM3 :", GL_Lvl_Lvl3_CM3);
                GL_Lvl_Lvl3_CM_Layout->addRow("&Nom CM4 :", GL_Lvl_Lvl3_CM4);
                GL_Lvl_Lvl3_CM_Layout->addRow("&Nom CM5 :", GL_Lvl_Lvl3_CM5);

                QVBoxLayout *GL_Lvl_Lvl3_CM_VLayout = new QVBoxLayout(GL_Lvl_Lvl3_WCM);
                GL_Lvl_Lvl3_CM_VLayout->addLayout(GL_Lvl_Lvl3_CM_Layout);

            //Layout Lvl3
                QFormLayout *GL_Lvl_Lvl3_Layout = new QFormLayout;
                GL_Lvl_Lvl3_Layout->addRow("&Image (URL) :", GL_Lvl_Lvl3_Img);
                GL_Lvl_Lvl3_Layout->addWidget(GL_Lvl_Lvl3_Spacer1);
                GL_Lvl_Lvl3_Layout->addWidget(GL_Lvl_Lvl3_WCM);
                GL_Lvl_Lvl3_Layout->addWidget(GL_Lvl_Lvl3_WNbrCM);
                GL_Lvl_Lvl3_Layout->addWidget(GL_Lvl_Lvl3_Spacer2);
                GL_Lvl_Lvl3_Layout->addRow("&Description :", GL_Lvl_Lvl3_Desc);
                GL_Lvl_Lvl3_Layout->addRow("&Plan (URL) :", GL_Lvl_Lvl3_PlanImg);

            GL_Lvl_Lvl3_WCM->setVisible(false);
            GL_Lvl_Lvl3_Spacer1->setVisible(false);
            GL_Lvl_Lvl3_Spacer2->setVisible(false);
            GL_Lvl_Lvl3_WNbrCM->setVisible(false);

        QVBoxLayout *GL_Lvl_Lvl3_VLayout = new QVBoxLayout;
        GL_Lvl_Lvl3_VLayout->addLayout(GL_Lvl_Lvl3_Layout);

        GL_Lvl_Lvl3->setLayout(GL_Lvl_Lvl3_VLayout);
        GL_Lvl_Tab->addTab(GL_Lvl_Lvl3, "&Niveau 3");

        if(GL_Main_GlaceCheck->isChecked() != 0){
            uGlaceCm(GL_Main_GlaceCheck->isChecked());
        }
    }else if(GL_Lvl_LvlCount == 4){
        //Lvl 4
            GL_Lvl_Lvl4_Img = new QLineEdit;
            GL_Lvl_Lvl4_CM1 = new QLineEdit;
            GL_Lvl_Lvl4_CM2 = new QLineEdit;
            GL_Lvl_Lvl4_CM3 = new QLineEdit;
            GL_Lvl_Lvl4_CM4 = new QLineEdit;
            GL_Lvl_Lvl4_CM5 = new QLineEdit;
            GL_Lvl_Lvl4_LNbrCM1 = new QLabel;
            GL_Lvl_Lvl4_LNbrCM1->setText("Nbr CM1 :");
            GL_Lvl_Lvl4_LNbrCM2 = new QLabel;
            GL_Lvl_Lvl4_LNbrCM2->setText("Nbr CM2 :");
            GL_Lvl_Lvl4_LNbrCM3 = new QLabel;
            GL_Lvl_Lvl4_LNbrCM3->setText("Nbr CM3 :");
            GL_Lvl_Lvl4_LNbrCM4 = new QLabel;
            GL_Lvl_Lvl4_LNbrCM4->setText("Nbr CM4 :");
            GL_Lvl_Lvl4_LNbrCM5 = new QLabel;
            GL_Lvl_Lvl4_LNbrCM5->setText("Nbr CM5 :");
            GL_Lvl_Lvl4_NbrCM1 = new QSpinBox;
            GL_Lvl_Lvl4_NbrCM2 = new QSpinBox;
            GL_Lvl_Lvl4_NbrCM3 = new QSpinBox;
            GL_Lvl_Lvl4_NbrCM4 = new QSpinBox;
            GL_Lvl_Lvl4_NbrCM5 = new QSpinBox;
            GL_Lvl_Lvl4_Desc = new QTextEdit;
            GL_Lvl_Lvl4_PlanImg = new QLineEdit;

            GL_Lvl_Lvl4_Spacer1 = new QWidget;
            GL_Lvl_Lvl4_Spacer1->setFixedHeight(2);
            GL_Lvl_Lvl4_Spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl4_Spacer1->setStyleSheet(QString("background-color: #000000;"));

            GL_Lvl_Lvl4_Spacer2 = new QWidget;
            GL_Lvl_Lvl4_Spacer2->setFixedHeight(2);
            GL_Lvl_Lvl4_Spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl4_Spacer2->setStyleSheet(QString("background-color: #000000;"));

            //Layout Nbr Cm Lvl4
                GL_Lvl_Lvl4_WNbrCM = new QWidget;

                QHBoxLayout *GL_Lvl_Lvl4_NbrCM_HLayout = new QHBoxLayout(GL_Lvl_Lvl4_WNbrCM);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_LNbrCM1);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_NbrCM1);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_LNbrCM2);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_NbrCM2);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_LNbrCM3);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_NbrCM3);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_LNbrCM4);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_NbrCM4);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_LNbrCM5);
                GL_Lvl_Lvl4_NbrCM_HLayout->addWidget(GL_Lvl_Lvl4_NbrCM5);

                GL_Lvl_Lvl4_WCM = new QWidget;
                QFormLayout *GL_Lvl_Lvl4_CM_Layout = new QFormLayout;
                GL_Lvl_Lvl4_CM_Layout->addRow("&Nom CM1 :", GL_Lvl_Lvl4_CM1);
                GL_Lvl_Lvl4_CM_Layout->addRow("&Nom CM2 :", GL_Lvl_Lvl4_CM2);
                GL_Lvl_Lvl4_CM_Layout->addRow("&Nom CM3 :", GL_Lvl_Lvl4_CM3);
                GL_Lvl_Lvl4_CM_Layout->addRow("&Nom CM4 :", GL_Lvl_Lvl4_CM4);
                GL_Lvl_Lvl4_CM_Layout->addRow("&Nom CM5 :", GL_Lvl_Lvl4_CM5);

                QVBoxLayout *GL_Lvl_Lvl4_CM_VLayout = new QVBoxLayout(GL_Lvl_Lvl4_WCM);
                GL_Lvl_Lvl4_CM_VLayout->addLayout(GL_Lvl_Lvl4_CM_Layout);

            //Layout Lvl4
                QFormLayout *GL_Lvl_Lvl4_Layout = new QFormLayout;
                GL_Lvl_Lvl4_Layout->addRow("&Image (URL) :", GL_Lvl_Lvl4_Img);
                GL_Lvl_Lvl4_Layout->addWidget(GL_Lvl_Lvl4_Spacer1);
                GL_Lvl_Lvl4_Layout->addWidget(GL_Lvl_Lvl4_WCM);
                GL_Lvl_Lvl4_Layout->addWidget(GL_Lvl_Lvl4_WNbrCM);
                GL_Lvl_Lvl4_Layout->addWidget(GL_Lvl_Lvl4_Spacer2);
                GL_Lvl_Lvl4_Layout->addRow("&Description :", GL_Lvl_Lvl4_Desc);
                GL_Lvl_Lvl4_Layout->addRow("&Plan (URL) :", GL_Lvl_Lvl4_PlanImg);

            GL_Lvl_Lvl4_WCM->setVisible(false);
            GL_Lvl_Lvl4_Spacer1->setVisible(false);
            GL_Lvl_Lvl4_Spacer2->setVisible(false);
            GL_Lvl_Lvl4_WNbrCM->setVisible(false);

        QVBoxLayout *GL_Lvl_Lvl4_VLayout = new QVBoxLayout;
        GL_Lvl_Lvl4_VLayout->addLayout(GL_Lvl_Lvl4_Layout);

        GL_Lvl_Lvl4->setLayout(GL_Lvl_Lvl4_VLayout);
        GL_Lvl_Tab->addTab(GL_Lvl_Lvl4, "&Niveau 4");

        if(GL_Main_GlaceCheck->isChecked() != 0){
            uGlaceCm(GL_Main_GlaceCheck->isChecked());
        }
    }else if(GL_Lvl_LvlCount == 5){
        //Lvl 5
            GL_Lvl_Lvl5_Img = new QLineEdit;
            GL_Lvl_Lvl5_CM1 = new QLineEdit;
            GL_Lvl_Lvl5_CM2 = new QLineEdit;
            GL_Lvl_Lvl5_CM3 = new QLineEdit;
            GL_Lvl_Lvl5_CM4 = new QLineEdit;
            GL_Lvl_Lvl5_CM5 = new QLineEdit;
            GL_Lvl_Lvl5_LNbrCM1 = new QLabel;
            GL_Lvl_Lvl5_LNbrCM1->setText("Nbr CM1 :");
            GL_Lvl_Lvl5_LNbrCM2 = new QLabel;
            GL_Lvl_Lvl5_LNbrCM2->setText("Nbr CM2 :");
            GL_Lvl_Lvl5_LNbrCM3 = new QLabel;
            GL_Lvl_Lvl5_LNbrCM3->setText("Nbr CM3 :");
            GL_Lvl_Lvl5_LNbrCM4 = new QLabel;
            GL_Lvl_Lvl5_LNbrCM4->setText("Nbr CM4 :");
            GL_Lvl_Lvl5_LNbrCM5 = new QLabel;
            GL_Lvl_Lvl5_LNbrCM5->setText("Nbr CM5 :");
            GL_Lvl_Lvl5_NbrCM1 = new QSpinBox;
            GL_Lvl_Lvl5_NbrCM2 = new QSpinBox;
            GL_Lvl_Lvl5_NbrCM3 = new QSpinBox;
            GL_Lvl_Lvl5_NbrCM4 = new QSpinBox;
            GL_Lvl_Lvl5_NbrCM5 = new QSpinBox;
            GL_Lvl_Lvl5_Desc = new QTextEdit;
            GL_Lvl_Lvl5_PlanImg = new QLineEdit;

            GL_Lvl_Lvl5_Spacer1 = new QWidget;
            GL_Lvl_Lvl5_Spacer1->setFixedHeight(2);
            GL_Lvl_Lvl5_Spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl5_Spacer1->setStyleSheet(QString("background-color: #000000;"));

            GL_Lvl_Lvl5_Spacer2 = new QWidget;
            GL_Lvl_Lvl5_Spacer2->setFixedHeight(2);
            GL_Lvl_Lvl5_Spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            GL_Lvl_Lvl5_Spacer2->setStyleSheet(QString("background-color: #000000;"));

            //Layout Nbr Cm Lvl5
                GL_Lvl_Lvl5_WNbrCM = new QWidget;

                QHBoxLayout *GL_Lvl_Lvl5_NbrCM_HLayout = new QHBoxLayout(GL_Lvl_Lvl5_WNbrCM);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_LNbrCM1);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_NbrCM1);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_LNbrCM2);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_NbrCM2);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_LNbrCM3);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_NbrCM3);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_LNbrCM4);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_NbrCM4);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_LNbrCM5);
                GL_Lvl_Lvl5_NbrCM_HLayout->addWidget(GL_Lvl_Lvl5_NbrCM5);

                GL_Lvl_Lvl5_WCM = new QWidget;
                QFormLayout *GL_Lvl_Lvl5_CM_Layout = new QFormLayout;
                GL_Lvl_Lvl5_CM_Layout->addRow("&Nom CM1 :", GL_Lvl_Lvl5_CM1);
                GL_Lvl_Lvl5_CM_Layout->addRow("&Nom CM2 :", GL_Lvl_Lvl5_CM2);
                GL_Lvl_Lvl5_CM_Layout->addRow("&Nom CM3 :", GL_Lvl_Lvl5_CM3);
                GL_Lvl_Lvl5_CM_Layout->addRow("&Nom CM4 :", GL_Lvl_Lvl5_CM4);
                GL_Lvl_Lvl5_CM_Layout->addRow("&Nom CM5 :", GL_Lvl_Lvl5_CM5);

                QVBoxLayout *GL_Lvl_Lvl5_CM_VLayout = new QVBoxLayout(GL_Lvl_Lvl5_WCM);
                GL_Lvl_Lvl5_CM_VLayout->addLayout(GL_Lvl_Lvl5_CM_Layout);

            //Layout Lvl2
                QFormLayout *GL_Lvl_Lvl5_Layout = new QFormLayout;
                GL_Lvl_Lvl5_Layout->addRow("&Image (URL) :", GL_Lvl_Lvl5_Img);
                GL_Lvl_Lvl5_Layout->addWidget(GL_Lvl_Lvl5_Spacer1);
                GL_Lvl_Lvl5_Layout->addWidget(GL_Lvl_Lvl5_WCM);
                GL_Lvl_Lvl5_Layout->addWidget(GL_Lvl_Lvl5_WNbrCM);
                GL_Lvl_Lvl5_Layout->addWidget(GL_Lvl_Lvl5_Spacer2);
                GL_Lvl_Lvl5_Layout->addRow("&Description :", GL_Lvl_Lvl5_Desc);
                GL_Lvl_Lvl5_Layout->addRow("&Plan (URL) :", GL_Lvl_Lvl5_PlanImg);

            GL_Lvl_Lvl5_WCM->setVisible(false);
            GL_Lvl_Lvl5_Spacer1->setVisible(false);
            GL_Lvl_Lvl5_Spacer2->setVisible(false);
            GL_Lvl_Lvl5_WNbrCM->setVisible(false);

        QVBoxLayout *GL_Lvl_Lvl5_VLayout = new QVBoxLayout;
        GL_Lvl_Lvl5_VLayout->addLayout(GL_Lvl_Lvl5_Layout);

        GL_Lvl_Lvl5->setLayout(GL_Lvl_Lvl5_VLayout);
        GL_Lvl_Tab->addTab(GL_Lvl_Lvl5, "&Niveau 5");

        if(GL_Main_GlaceCheck->isChecked() != 0){
            uGlaceCm(GL_Main_GlaceCheck->isChecked());
        }
    }
}

void MainFrame::stateChanged(QString stateLvl)
{
    if(stateLvl == "Blanche"){

            GL_Cm_CM1_Cat->removeItem(9);
            GL_Cm_CM1_Cat->removeItem(9);
            GL_Cm_CM1_Cat->removeItem(9);

        if(GL_Cm_CmCount >= 2){
            GL_Cm_CM2_Cat->removeItem(9);
            GL_Cm_CM2_Cat->removeItem(9);
            GL_Cm_CM2_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 3){
            GL_Cm_CM3_Cat->removeItem(9);
            GL_Cm_CM3_Cat->removeItem(9);
            GL_Cm_CM3_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 4){
            GL_Cm_CM4_Cat->removeItem(9);
            GL_Cm_CM4_Cat->removeItem(9);
            GL_Cm_CM4_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 5){
            GL_Cm_CM5_Cat->removeItem(9);
            GL_Cm_CM5_Cat->removeItem(9);
            GL_Cm_CM5_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 6){
            GL_Cm_CM6_Cat->removeItem(9);
            GL_Cm_CM6_Cat->removeItem(9);
            GL_Cm_CM6_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 7){
            GL_Cm_CM7_Cat->removeItem(9);
            GL_Cm_CM7_Cat->removeItem(9);
            GL_Cm_CM7_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 8){
            GL_Cm_CM8_Cat->removeItem(9);
            GL_Cm_CM8_Cat->removeItem(9);
            GL_Cm_CM8_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 9){
            GL_Cm_CM9_Cat->removeItem(9);
            GL_Cm_CM9_Cat->removeItem(9);
            GL_Cm_CM9_Cat->removeItem(9);
        }
        if(GL_Cm_CmCount >= 10){
            GL_Cm_CM10_Cat->removeItem(9);
            GL_Cm_CM10_Cat->removeItem(9);
            GL_Cm_CM10_Cat->removeItem(9);
        }
    }else if(stateLvl == "Grise"){
        GL_Cm_CM1_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        if(GL_Cm_CmCount >= 2){
            GL_Cm_CM2_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 3){
            GL_Cm_CM3_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 4){
            GL_Cm_CM4_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 5){
            GL_Cm_CM5_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 6){
            GL_Cm_CM6_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 7){
            GL_Cm_CM7_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 8){
            GL_Cm_CM8_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 9){
            GL_Cm_CM9_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
        if(GL_Cm_CmCount >= 10){
            GL_Cm_CM10_Cat->addItems(QStringList() << "Blaster" << "Foudre" << "Ripper");
        }
    }
}

void MainFrame::generateCodeProgram()
{
    if(PRG_Main_Name->text().isEmpty()){
        QMessageBox::information(this, "ERROR", "Veuillez entrer au moins le nom du programme.");
        return;
    }

    QSettings settings("Exiel", "DC_Tools");

    QString Protection;
    QString Program;

    //Load Protection Template
        QString Protection_Template_Path = settings.value("Protection/TemplateProtection").toString();
        QFile Protection_File(Protection_Template_Path);
        Protection_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream Protection_TextStream(&Protection_File);
        Protection_TextStream.setCodec("UTF-8");

        Protection = Protection_TextStream.readAll();

        //Replace Protection Values by Config Values
            Protection.replace("PR_Name", settings.value("Protection/Name").toString());
            Protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            Protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            Protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            Protection.replace("PR_Read", settings.value("Protection/Read").toString());
            Protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            Protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            Protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());

    //Load Program Template
        QString Program_Template_Path = settings.value("Configuration/TemplateProgram").toString();
        QFile Program_File(Program_Template_Path);
        Program_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream Program_TextStream(&Program_File);
        Program_TextStream.setCodec("UTF-8");

        Program = Program_TextStream.readAll();

        //Replace Program Values by program() Values
            Program.replace("GB_Desc_Img_Line", PRG_Desc_Img->text());
            Program.replace("GB_Main_Name_Line", PRG_Main_Name->text());
            Program.replace("GB_Main_Desc_Line", PRG_Main_Desc->text());
            Program.replace("GB_Desc_Desc_Line", PRG_Desc_Desc->toPlainText());
            Program.replace("GB_Main_Name_Line", PRG_Main_Name->text());
            Program.replace("GB_Tech_Aute_Line", PRG_Tech_Auth->text());
            Program.replace("GB_Tech_Type_Comb", PRG_Tech_Type->currentText());
            Program.replace("GB_Tech_Desc_Line", PRG_Tech_Desc->text());
            Program.replace("GB_Tech_Auto_Line", PRG_Tech_Auto->text());
            Program.replace("GB_Tech_Inte_Line", PRG_Tech_Inte->text());
            Program.replace("GB_Tech_Vers_Line", PRG_Tech_Vers->text());
            Program.replace("GB_Tech_Acti_Line", PRG_Tech_Acti->text());
            Program.replace("GB_Tech_Util_Line", PRG_Tech_Util->text());
            Program.replace("GB_Tech_Mate_Line", PRG_Tech_Mate->text());
            Program.replace("GB_Tech_Dure_Line", PRG_Tech_Dure->text());

    //Send Data to the FrameCodeGenerator Class
        FrameCodeGenerator *frameCode = new FrameCodeGenerator(Program, Protection, this);
        frameCode->exec();
}

void MainFrame::generateCodeGlace()
{
    if(GL_Main_Name->text().isEmpty()){
        QMessageBox::information(this, "ERROR", "Veuillez entrer au moins le nom de la GLACE/RV.");
        return;
    }

    QSettings settings("Exiel", "DC_Tools");

    QString Protection;
    QString Glace;

    QString GL_Main;

    QString GL_CMTop;

    QString GL_CM1;
    QString GL_CM2;
    QString GL_CM3;
    QString GL_CM4;
    QString GL_CM5;
    QString GL_CM6;
    QString GL_CM7;
    QString GL_CM8;
    QString GL_CM9;
    QString GL_CM10;

    QString GL_Alarm;
    QString GL_Plan;

    QString GL_Lvl1;
    QString GL_Lvl2;
    QString GL_Lvl3;
    QString GL_Lvl4;
    QString GL_Lvl5;

    QString GL_End;

    //Load Protection Template
        QString Protection_Template_Path = settings.value("Protection/TemplateProtection").toString();
        QFile Protection_File(Protection_Template_Path);
        Protection_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream Protection_TextStream(&Protection_File);
        Protection_TextStream.setCodec("UTF-8");

        Protection = Protection_TextStream.readAll();

        //Replace Protection Values by Config Values
            Protection.replace("PR_Name", settings.value("Protection/Name").toString());
            Protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            Protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            Protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            Protection.replace("PR_Read", settings.value("Protection/Read").toString());
            Protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            Protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            Protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());

    //Load Glace Template
        QString GL_Main_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\main.pouik";
        QFile GL_Main_File(GL_Main_Template_Path);
        GL_Main_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream GL_Main_TextStream(&GL_Main_File);
        GL_Main_TextStream.setCodec("UTF-8");

        GL_Main = GL_Main_TextStream.readAll();

        //Replace GL_Main Values by glace() Main Page Values
            GL_Main.replace("GL_Main_Img_Line", GL_Main_Img->text());
            GL_Main.replace("GL_Main_Name_Line", GL_Main_Name->text());
            if(Glace_State == 1){
                GL_Main.replace("GL_Main_Lvl_Line", GL_Cm_GLType->currentText());
            }else{
                GL_Main.replace("GL_Main_Lvl_Line", "");
            }
            GL_Main.replace("GL_Main_Vers_Line", GL_Main_Vers->text());
            GL_Main.replace("Gl_Main_Desc_Line", GL_Main_Desc->toPlainText());

        if(Glace_State == 1){
            //Load GL_Cm Template
                QString GL_CM1_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                QFile GL_CM1_File(GL_CM1_Template_Path);
                GL_CM1_File.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream GL_CM1_TextStream(&GL_CM1_File);
                GL_CM1_TextStream.setCodec("UTF-8");

                GL_CM1 = GL_CM1_TextStream.readAll();

                //Replace GL_CM1 Values by glace() CM_CM1 Page Values
                    GL_CM1.replace("GL_CM_Name_Line", GL_Cm_CM1_Name->text());
                    GL_CM1.replace("GL_CM_Img_Line", GL_Cm_CM1_Img->text());
                    GL_CM1.replace("GL_CM_Cat_Line", GL_Cm_CM1_Cat->currentText());
                    GL_CM1.replace("GL_CM_Comp1_Line", GL_Cm_CM1_Comp1->text());
                    GL_CM1.replace("GL_CM_Comp2_Line", GL_Cm_CM1_Comp2->text());
                    GL_CM1.replace("GL_CM_Comp3_Line", GL_Cm_CM1_Comp3->text());
                    GL_CM1.replace("GL_CM_Alg1_Line", GL_Cm_CM1_Alg1->text());
                    GL_CM1.replace("GL_CM_Alg2_Line", GL_Cm_CM1_Alg2->text());
                    GL_CM1.replace("GL_CM_Alg3_Line", GL_Cm_CM1_Alg3->text());
                    GL_CM1.replace("GL_CM_Desc_Line", GL_Cm_CM1_Desc->toPlainText());

            if(GL_Cm_CmCount >= 2){
                //Load GL_Cm Template
                    QString GL_CM2_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM2_File(GL_CM2_Template_Path);
                    GL_CM2_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM2_TextStream(&GL_CM2_File);
                    GL_CM2_TextStream.setCodec("UTF-8");

                    GL_CM2 = GL_CM2_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM1 Page Values
                        GL_CM2.replace("GL_CM_Name_Line", GL_Cm_CM2_Name->text());
                        GL_CM2.replace("GL_CM_Img_Line", GL_Cm_CM2_Img->text());
                        GL_CM2.replace("GL_CM_Cat_Line", GL_Cm_CM2_Cat->currentText());
                        GL_CM2.replace("GL_CM_Comp1_Line", GL_Cm_CM2_Comp1->text());
                        GL_CM2.replace("GL_CM_Comp2_Line", GL_Cm_CM2_Comp2->text());
                        GL_CM2.replace("GL_CM_Comp3_Line", GL_Cm_CM2_Comp3->text());
                        GL_CM2.replace("GL_CM_Alg1_Line", GL_Cm_CM2_Alg1->text());
                        GL_CM2.replace("GL_CM_Alg2_Line", GL_Cm_CM2_Alg2->text());
                        GL_CM2.replace("GL_CM_Alg3_Line", GL_Cm_CM2_Alg3->text());
                        GL_CM2.replace("GL_CM_Desc_Line", GL_Cm_CM2_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 3){
                //Load GL_Cm Template
                    QString GL_CM3_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM3_File(GL_CM3_Template_Path);
                    GL_CM3_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM3_TextStream(&GL_CM3_File);
                    GL_CM3_TextStream.setCodec("UTF-8");

                    GL_CM3 = GL_CM3_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM3 Page Values
                        GL_CM3.replace("GL_CM_Name_Line", GL_Cm_CM3_Name->text());
                        GL_CM3.replace("GL_CM_Img_Line", GL_Cm_CM3_Img->text());
                        GL_CM3.replace("GL_CM_Cat_Line", GL_Cm_CM3_Cat->currentText());
                        GL_CM3.replace("GL_CM_Comp1_Line", GL_Cm_CM3_Comp1->text());
                        GL_CM3.replace("GL_CM_Comp2_Line", GL_Cm_CM3_Comp2->text());
                        GL_CM3.replace("GL_CM_Comp3_Line", GL_Cm_CM3_Comp3->text());
                        GL_CM3.replace("GL_CM_Alg1_Line", GL_Cm_CM3_Alg1->text());
                        GL_CM3.replace("GL_CM_Alg2_Line", GL_Cm_CM3_Alg2->text());
                        GL_CM3.replace("GL_CM_Alg3_Line", GL_Cm_CM3_Alg3->text());
                        GL_CM3.replace("GL_CM_Desc_Line", GL_Cm_CM3_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 4){
                //Load GL_Cm Template
                    QString GL_CM4_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM4_File(GL_CM4_Template_Path);
                    GL_CM4_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM4_TextStream(&GL_CM4_File);
                    GL_CM4_TextStream.setCodec("UTF-8");

                    GL_CM4 = GL_CM4_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM4 Page Values
                        GL_CM4.replace("GL_CM_Name_Line", GL_Cm_CM4_Name->text());
                        GL_CM4.replace("GL_CM_Img_Line", GL_Cm_CM4_Img->text());
                        GL_CM4.replace("GL_CM_Cat_Line", GL_Cm_CM4_Cat->currentText());
                        GL_CM4.replace("GL_CM_Comp1_Line", GL_Cm_CM4_Comp1->text());
                        GL_CM4.replace("GL_CM_Comp2_Line", GL_Cm_CM4_Comp2->text());
                        GL_CM4.replace("GL_CM_Comp3_Line", GL_Cm_CM4_Comp3->text());
                        GL_CM4.replace("GL_CM_Alg1_Line", GL_Cm_CM4_Alg1->text());
                        GL_CM4.replace("GL_CM_Alg2_Line", GL_Cm_CM4_Alg2->text());
                        GL_CM4.replace("GL_CM_Alg3_Line", GL_Cm_CM4_Alg3->text());
                        GL_CM4.replace("GL_CM_Desc_Line", GL_Cm_CM4_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 5){
                //Load GL_Cm Template
                    QString GL_CM5_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM5_File(GL_CM5_Template_Path);
                    GL_CM5_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM5_TextStream(&GL_CM5_File);
                    GL_CM5_TextStream.setCodec("UTF-8");

                    GL_CM5 = GL_CM5_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM5 Page Values
                        GL_CM5.replace("GL_CM_Name_Line", GL_Cm_CM5_Name->text());
                        GL_CM5.replace("GL_CM_Img_Line", GL_Cm_CM5_Img->text());
                        GL_CM5.replace("GL_CM_Cat_Line", GL_Cm_CM5_Cat->currentText());
                        GL_CM5.replace("GL_CM_Comp1_Line", GL_Cm_CM5_Comp1->text());
                        GL_CM5.replace("GL_CM_Comp2_Line", GL_Cm_CM5_Comp2->text());
                        GL_CM5.replace("GL_CM_Comp3_Line", GL_Cm_CM5_Comp3->text());
                        GL_CM5.replace("GL_CM_Alg1_Line", GL_Cm_CM5_Alg1->text());
                        GL_CM5.replace("GL_CM_Alg2_Line", GL_Cm_CM5_Alg2->text());
                        GL_CM5.replace("GL_CM_Alg3_Line", GL_Cm_CM5_Alg3->text());
                        GL_CM5.replace("GL_CM_Desc_Line", GL_Cm_CM5_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 6){
                //Load GL_Cm Template
                    QString GL_CM6_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM6_File(GL_CM6_Template_Path);
                    GL_CM6_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM6_TextStream(&GL_CM6_File);
                    GL_CM6_TextStream.setCodec("UTF-8");

                    GL_CM6 = GL_CM6_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM6 Page Values
                        GL_CM6.replace("GL_CM_Name_Line", GL_Cm_CM6_Name->text());
                        GL_CM6.replace("GL_CM_Img_Line", GL_Cm_CM6_Img->text());
                        GL_CM6.replace("GL_CM_Cat_Line", GL_Cm_CM6_Cat->currentText());
                        GL_CM6.replace("GL_CM_Comp1_Line", GL_Cm_CM6_Comp1->text());
                        GL_CM6.replace("GL_CM_Comp2_Line", GL_Cm_CM6_Comp2->text());
                        GL_CM6.replace("GL_CM_Comp3_Line", GL_Cm_CM6_Comp3->text());
                        GL_CM6.replace("GL_CM_Alg1_Line", GL_Cm_CM6_Alg1->text());
                        GL_CM6.replace("GL_CM_Alg2_Line", GL_Cm_CM6_Alg2->text());
                        GL_CM6.replace("GL_CM_Alg3_Line", GL_Cm_CM6_Alg3->text());
                        GL_CM6.replace("GL_CM_Desc_Line", GL_Cm_CM6_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 7){
                //Load GL_Cm Template
                    QString GL_CM7_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM7_File(GL_CM7_Template_Path);
                    GL_CM7_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM7_TextStream(&GL_CM7_File);
                    GL_CM7_TextStream.setCodec("UTF-8");

                    GL_CM7 = GL_CM7_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM7 Page Values
                        GL_CM7.replace("GL_CM_Name_Line", GL_Cm_CM7_Name->text());
                        GL_CM7.replace("GL_CM_Img_Line", GL_Cm_CM7_Img->text());
                        GL_CM7.replace("GL_CM_Cat_Line", GL_Cm_CM7_Cat->currentText());
                        GL_CM7.replace("GL_CM_Comp1_Line", GL_Cm_CM7_Comp1->text());
                        GL_CM7.replace("GL_CM_Comp2_Line", GL_Cm_CM7_Comp2->text());
                        GL_CM7.replace("GL_CM_Comp3_Line", GL_Cm_CM7_Comp3->text());
                        GL_CM7.replace("GL_CM_Alg1_Line", GL_Cm_CM7_Alg1->text());
                        GL_CM7.replace("GL_CM_Alg2_Line", GL_Cm_CM7_Alg2->text());
                        GL_CM7.replace("GL_CM_Alg3_Line", GL_Cm_CM7_Alg3->text());
                        GL_CM7.replace("GL_CM_Desc_Line", GL_Cm_CM7_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 8){
                //Load GL_Cm Template
                    QString GL_CM8_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM8_File(GL_CM8_Template_Path);
                    GL_CM8_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM8_TextStream(&GL_CM8_File);
                    GL_CM8_TextStream.setCodec("UTF-8");

                    GL_CM8 = GL_CM8_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM8 Page Values
                        GL_CM8.replace("GL_CM_Name_Line", GL_Cm_CM8_Name->text());
                        GL_CM8.replace("GL_CM_Img_Line", GL_Cm_CM8_Img->text());
                        GL_CM8.replace("GL_CM_Cat_Line", GL_Cm_CM8_Cat->currentText());
                        GL_CM8.replace("GL_CM_Comp1_Line", GL_Cm_CM8_Comp1->text());
                        GL_CM8.replace("GL_CM_Comp2_Line", GL_Cm_CM8_Comp2->text());
                        GL_CM8.replace("GL_CM_Comp3_Line", GL_Cm_CM8_Comp3->text());
                        GL_CM8.replace("GL_CM_Alg1_Line", GL_Cm_CM8_Alg1->text());
                        GL_CM8.replace("GL_CM_Alg2_Line", GL_Cm_CM8_Alg2->text());
                        GL_CM8.replace("GL_CM_Alg3_Line", GL_Cm_CM8_Alg3->text());
                        GL_CM8.replace("GL_CM_Desc_Line", GL_Cm_CM8_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 9){
                //Load GL_Cm Template
                    QString GL_CM9_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM9_File(GL_CM9_Template_Path);
                    GL_CM9_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM9_TextStream(&GL_CM9_File);
                    GL_CM9_TextStream.setCodec("UTF-8");

                    GL_CM9 = GL_CM9_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM9 Page Values
                        GL_CM9.replace("GL_CM_Name_Line", GL_Cm_CM9_Name->text());
                        GL_CM9.replace("GL_CM_Img_Line", GL_Cm_CM9_Img->text());
                        GL_CM9.replace("GL_CM_Cat_Line", GL_Cm_CM9_Cat->currentText());
                        GL_CM9.replace("GL_CM_Comp1_Line", GL_Cm_CM9_Comp1->text());
                        GL_CM9.replace("GL_CM_Comp2_Line", GL_Cm_CM9_Comp2->text());
                        GL_CM9.replace("GL_CM_Comp3_Line", GL_Cm_CM9_Comp3->text());
                        GL_CM9.replace("GL_CM_Alg1_Line", GL_Cm_CM9_Alg1->text());
                        GL_CM9.replace("GL_CM_Alg2_Line", GL_Cm_CM9_Alg2->text());
                        GL_CM9.replace("GL_CM_Alg3_Line", GL_Cm_CM9_Alg3->text());
                        GL_CM9.replace("GL_CM_Desc_Line", GL_Cm_CM9_Desc->toPlainText());
            }
            if(GL_Cm_CmCount >= 10){
                //Load GL_Cm Template
                    QString GL_CM10_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm.pouik";
                    QFile GL_CM10_File(GL_CM10_Template_Path);
                    GL_CM10_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_CM10_TextStream(&GL_CM10_File);
                    GL_CM10_TextStream.setCodec("UTF-8");

                    GL_CM10 = GL_CM10_TextStream.readAll();

                    //Replace GL_CM1 Values by glace() CM_CM10 Page Values
                        GL_CM10.replace("GL_CM_Name_Line", GL_Cm_CM10_Name->text());
                        GL_CM10.replace("GL_CM_Img_Line", GL_Cm_CM10_Img->text());
                        GL_CM10.replace("GL_CM_Cat_Line", GL_Cm_CM10_Cat->currentText());
                        GL_CM10.replace("GL_CM_Comp1_Line", GL_Cm_CM10_Comp1->text());
                        GL_CM10.replace("GL_CM_Comp2_Line", GL_Cm_CM10_Comp2->text());
                        GL_CM10.replace("GL_CM_Comp3_Line", GL_Cm_CM10_Comp3->text());
                        GL_CM10.replace("GL_CM_Alg1_Line", GL_Cm_CM10_Alg1->text());
                        GL_CM10.replace("GL_CM_Alg2_Line", GL_Cm_CM10_Alg2->text());
                        GL_CM10.replace("GL_CM_Alg3_Line", GL_Cm_CM10_Alg3->text());
                        GL_CM10.replace("GL_CM_Desc_Line", GL_Cm_CM10_Desc->toPlainText());
            }

        //Load GL_Alarm Template
            QString GL_Alarm_Template_Path = settings.value("Configuration/TempalteGlace").toString() + "\\alrt.pouik";
            QFile GL_Alarm_File(GL_Alarm_Template_Path);
            GL_Alarm_File.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream GL_Alarm_TextStream(&GL_Alarm_File);
            GL_Alarm_TextStream.setCodec("UTF-8");

            GL_Alarm = GL_Alarm_TextStream.readAll();

            //Replace GL_Alarm Values by glace() Alarm Page Values
            GL_Alarm.replace("GL_CM_NAlrt1_Line", GL_Alarm_NoAlarm1->text());
            GL_Alarm.replace("GL_CM_NAlrt2_Line", GL_Alarm_NoAlarm2->text());
            GL_Alarm.replace("GL_CM_NAlrt3_Line", GL_Alarm_NoAlarm3->text());
            GL_Alarm.replace("GL_CM_FAlrt1_Line", GL_Alarm_LowAlarm1->text());
            GL_Alarm.replace("GL_CM_FAlrt2_Line", GL_Alarm_LowAlarm2->text());
            GL_Alarm.replace("GL_CM_FAlrt3_Line", GL_Alarm_LowAlarm3->text());
            GL_Alarm.replace("GL_CM_HAlrt1_Line", GL_Alarm_HighAlarm1->text());
            GL_Alarm.replace("GL_CM_HAlrt2_Line", GL_Alarm_HighAlarm2->text());
            GL_Alarm.replace("GL_CM_HAlrt3_Line", GL_Alarm_HighAlarm3->text());
        }
    //Load GL_Plan Template
        QString GL_Plan_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\plan.pouik";
        QFile GL_Plan_File(GL_Plan_Template_Path);
        GL_Plan_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream GL_Plan_TextStream(&GL_Plan_File);
        GL_Plan_TextStream.setCodec("UTF-8");

        GL_Plan = GL_Plan_TextStream.readAll();

        //Replace GL_Plan Values by glace() Main Page Plan Values
            GL_Plan.replace("GL_PL_Img_Line", GL_Main_Plan->text());

        if(Glace_State == 1){
            //Load GL_Lvl Template
                QString GL_Lvl1_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_cm.pouik";
                QFile GL_Lvl1_File(GL_Lvl1_Template_Path);
                GL_Lvl1_File.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream GL_Lvl1_TextStream(&GL_Lvl1_File);
                GL_Lvl1_TextStream.setCodec("UTF-8");

                GL_Lvl1 = GL_Lvl1_TextStream.readAll();

                //Replace GL_Lvl1 Values by glace() Lvl_Lvl1 Page Values
                    GL_Lvl1.replace("GL_LV_Nbr_Line", "1");
                    GL_Lvl1.replace("GL_LV_Img_Line", GL_Lvl_Lvl1_Img->text());
                    GL_Lvl1.replace("GL_LV_CM1_Line", QString::number(GL_Lvl_Lvl1_NbrCM1->value()) + "X " + GL_Lvl_Lvl1_CM1->text());
                    GL_Lvl1.replace("GL_LV_CM2_Line", QString::number(GL_Lvl_Lvl1_NbrCM2->value()) + "X " + GL_Lvl_Lvl1_CM2->text());
                    GL_Lvl1.replace("GL_LV_CM3_Line", QString::number(GL_Lvl_Lvl1_NbrCM3->value()) + "X " + GL_Lvl_Lvl1_CM3->text());
                    GL_Lvl1.replace("GL_LV_CM4_Line", QString::number(GL_Lvl_Lvl1_NbrCM4->value()) + "X " + GL_Lvl_Lvl1_CM4->text());
                    GL_Lvl1.replace("GL_LV_CM5_Line", QString::number(GL_Lvl_Lvl1_NbrCM5->value()) + "X " + GL_Lvl_Lvl1_CM5->text());

                    int GL_Lvl1_VCM1 = GL_Lvl_Lvl1_NbrCM1->value();
                    int GL_Lvl1_VCM2 = GL_Lvl_Lvl1_NbrCM2->value();
                    int GL_Lvl1_VCM3 = GL_Lvl_Lvl1_NbrCM3->value();
                    int GL_Lvl1_VCM4 = GL_Lvl_Lvl1_NbrCM4->value();
                    int GL_Lvl1_VCM5 = GL_Lvl_Lvl1_NbrCM5->value();

                    int GL_Lvl1_VCMR = GL_Lvl1_VCM1 + GL_Lvl1_VCM2 + GL_Lvl1_VCM3 + GL_Lvl1_VCM4 + GL_Lvl1_VCM5;

                    GL_Lvl1.replace("GL_LV_CMR_Line", QString::number(GL_Lvl1_VCMR));
                    GL_Lvl1.replace("GL_LV_Desc_Line", GL_Lvl_Lvl1_Desc->toPlainText());
                    GL_Lvl1.replace("GL_LV_PImg_Line", GL_Lvl_Lvl1_PlanImg->text());

            if(GL_Lvl_LvlCount >= 2){
                //Load GL_Lvl Templat
                    QString GL_Lvl2_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_cm.pouik";
                    QFile GL_Lvl2_File(GL_Lvl2_Template_Path);
                    GL_Lvl2_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl2_TextStream(&GL_Lvl2_File);
                    GL_Lvl2_TextStream.setCodec("UTF-8");

                    GL_Lvl2 = GL_Lvl2_TextStream.readAll();

                    //Replace GL_Lvl2 Values by glace() Lvl_Lvl2 Page Values
                        GL_Lvl2.replace("GL_LV_Nbr_Line", "2");
                        GL_Lvl2.replace("GL_LV_Img_Line", GL_Lvl_Lvl2_Img->text());
                        GL_Lvl2.replace("GL_LV_CM1_Line", QString::number(GL_Lvl_Lvl2_NbrCM1->value()) + "X " + GL_Lvl_Lvl2_CM1->text());
                        GL_Lvl2.replace("GL_LV_CM2_Line", QString::number(GL_Lvl_Lvl2_NbrCM2->value()) + "X " + GL_Lvl_Lvl2_CM2->text());
                        GL_Lvl2.replace("GL_LV_CM3_Line", QString::number(GL_Lvl_Lvl2_NbrCM3->value()) + "X " + GL_Lvl_Lvl2_CM3->text());
                        GL_Lvl2.replace("GL_LV_CM4_Line", QString::number(GL_Lvl_Lvl2_NbrCM4->value()) + "X " + GL_Lvl_Lvl2_CM4->text());
                        GL_Lvl2.replace("GL_LV_CM5_Line", QString::number(GL_Lvl_Lvl2_NbrCM5->value()) + "X " + GL_Lvl_Lvl2_CM5->text());

                        int GL_Lvl2_VCM1 = GL_Lvl_Lvl2_NbrCM1->value();
                        int GL_Lvl2_VCM2 = GL_Lvl_Lvl2_NbrCM2->value();
                        int GL_Lvl2_VCM3 = GL_Lvl_Lvl2_NbrCM3->value();
                        int GL_Lvl2_VCM4 = GL_Lvl_Lvl2_NbrCM4->value();
                        int GL_Lvl2_VCM5 = GL_Lvl_Lvl2_NbrCM5->value();

                        int GL_Lvl2_VCMR = GL_Lvl2_VCM1 + GL_Lvl2_VCM2 + GL_Lvl2_VCM3 + GL_Lvl2_VCM4 + GL_Lvl2_VCM5;

                        GL_Lvl2.replace("GL_LV_CMR_Line", QString::number(GL_Lvl2_VCMR));
                        GL_Lvl2.replace("GL_LV_Desc_Line", GL_Lvl_Lvl2_Desc->toPlainText());
                        GL_Lvl2.replace("GL_LV_PImg_Line", GL_Lvl_Lvl2_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 3){
                //Load GL_Lvl Templat
                    QString GL_Lvl3_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_cm.pouik";
                    QFile GL_Lvl3_File(GL_Lvl3_Template_Path);
                    GL_Lvl3_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl3_TextStream(&GL_Lvl3_File);
                    GL_Lvl3_TextStream.setCodec("UTF-8");

                    GL_Lvl3 = GL_Lvl3_TextStream.readAll();

                    //Replace GL_Lvl3 Values by glace() Lvl_Lvl3 Page Values
                        GL_Lvl3.replace("GL_LV_Nbr_Line", "3");
                        GL_Lvl3.replace("GL_LV_Img_Line", GL_Lvl_Lvl3_Img->text());
                        GL_Lvl3.replace("GL_LV_CM1_Line", QString::number(GL_Lvl_Lvl3_NbrCM1->value()) + "X " + GL_Lvl_Lvl3_CM1->text());
                        GL_Lvl3.replace("GL_LV_CM2_Line", QString::number(GL_Lvl_Lvl3_NbrCM2->value()) + "X " + GL_Lvl_Lvl3_CM2->text());
                        GL_Lvl3.replace("GL_LV_CM3_Line", QString::number(GL_Lvl_Lvl3_NbrCM3->value()) + "X " + GL_Lvl_Lvl3_CM3->text());
                        GL_Lvl3.replace("GL_LV_CM4_Line", QString::number(GL_Lvl_Lvl3_NbrCM4->value()) + "X " + GL_Lvl_Lvl3_CM4->text());
                        GL_Lvl3.replace("GL_LV_CM5_Line", QString::number(GL_Lvl_Lvl3_NbrCM5->value()) + "X " + GL_Lvl_Lvl3_CM5->text());

                        int GL_Lvl3_VCM1 = GL_Lvl_Lvl3_NbrCM1->value();
                        int GL_Lvl3_VCM2 = GL_Lvl_Lvl3_NbrCM2->value();
                        int GL_Lvl3_VCM3 = GL_Lvl_Lvl3_NbrCM3->value();
                        int GL_Lvl3_VCM4 = GL_Lvl_Lvl3_NbrCM4->value();
                        int GL_Lvl3_VCM5 = GL_Lvl_Lvl3_NbrCM5->value();

                        int GL_Lvl3_VCMR = GL_Lvl3_VCM1 + GL_Lvl3_VCM2 + GL_Lvl3_VCM3 + GL_Lvl3_VCM4 + GL_Lvl3_VCM5;

                        GL_Lvl3.replace("GL_LV_CMR_Line", QString::number(GL_Lvl3_VCMR));
                        GL_Lvl3.replace("GL_LV_Desc_Line", GL_Lvl_Lvl3_Desc->toPlainText());
                        GL_Lvl3.replace("GL_LV_PImg_Line", GL_Lvl_Lvl3_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 4){
                //Load GL_Lvl Templat
                    QString GL_Lvl4_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_cm.pouik";
                    QFile GL_Lvl4_File(GL_Lvl4_Template_Path);
                    GL_Lvl4_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl4_TextStream(&GL_Lvl4_File);
                    GL_Lvl4_TextStream.setCodec("UTF-8");

                    GL_Lvl4 = GL_Lvl4_TextStream.readAll();

                    //Replace GL_Lvl4 Values by glace() Lvl_Lvl4 Page Values
                        GL_Lvl4.replace("GL_LV_Nbr_Line", "4");
                        GL_Lvl4.replace("GL_LV_Img_Line", GL_Lvl_Lvl4_Img->text());
                        GL_Lvl4.replace("GL_LV_CM1_Line", QString::number(GL_Lvl_Lvl4_NbrCM1->value()) + "X " + GL_Lvl_Lvl4_CM1->text());
                        GL_Lvl4.replace("GL_LV_CM2_Line", QString::number(GL_Lvl_Lvl4_NbrCM2->value()) + "X " + GL_Lvl_Lvl4_CM2->text());
                        GL_Lvl4.replace("GL_LV_CM3_Line", QString::number(GL_Lvl_Lvl4_NbrCM3->value()) + "X " + GL_Lvl_Lvl4_CM3->text());
                        GL_Lvl4.replace("GL_LV_CM4_Line", QString::number(GL_Lvl_Lvl4_NbrCM4->value()) + "X " + GL_Lvl_Lvl4_CM4->text());
                        GL_Lvl4.replace("GL_LV_CM5_Line", QString::number(GL_Lvl_Lvl4_NbrCM5->value()) + "X " + GL_Lvl_Lvl4_CM5->text());

                        int GL_Lvl4_VCM1 = GL_Lvl_Lvl4_NbrCM1->value();
                        int GL_Lvl4_VCM2 = GL_Lvl_Lvl4_NbrCM2->value();
                        int GL_Lvl4_VCM3 = GL_Lvl_Lvl4_NbrCM3->value();
                        int GL_Lvl4_VCM4 = GL_Lvl_Lvl4_NbrCM4->value();
                        int GL_Lvl4_VCM5 = GL_Lvl_Lvl4_NbrCM5->value();

                        int GL_Lvl4_VCMR = GL_Lvl4_VCM1 + GL_Lvl4_VCM2 + GL_Lvl4_VCM3 + GL_Lvl4_VCM4 + GL_Lvl4_VCM5;

                        GL_Lvl4.replace("GL_LV_CMR_Line", QString::number(GL_Lvl4_VCMR));
                        GL_Lvl4.replace("GL_LV_Desc_Line", GL_Lvl_Lvl4_Desc->toPlainText());
                        GL_Lvl4.replace("GL_LV_PImg_Line", GL_Lvl_Lvl4_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 5){
                //Load GL_Lvl Templat
                    QString GL_Lvl5_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_cm.pouik";
                    QFile GL_Lvl5_File(GL_Lvl5_Template_Path);
                    GL_Lvl5_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl5_TextStream(&GL_Lvl5_File);
                    GL_Lvl5_TextStream.setCodec("UTF-8");

                    GL_Lvl5 = GL_Lvl5_TextStream.readAll();

                    //Replace GL_Lvl5 Values by glace() Lvl_Lvl5 Page Values
                        GL_Lvl5.replace("GL_LV_Nbr_Line", "5");
                        GL_Lvl5.replace("GL_LV_Img_Line", GL_Lvl_Lvl5_Img->text());
                        GL_Lvl5.replace("GL_LV_CM1_Line", QString::number(GL_Lvl_Lvl5_NbrCM1->value()) + "X " + GL_Lvl_Lvl5_CM1->text());
                        GL_Lvl5.replace("GL_LV_CM2_Line", QString::number(GL_Lvl_Lvl5_NbrCM2->value()) + "X " + GL_Lvl_Lvl5_CM2->text());
                        GL_Lvl5.replace("GL_LV_CM3_Line", QString::number(GL_Lvl_Lvl5_NbrCM3->value()) + "X " + GL_Lvl_Lvl5_CM3->text());
                        GL_Lvl5.replace("GL_LV_CM4_Line", QString::number(GL_Lvl_Lvl5_NbrCM4->value()) + "X " + GL_Lvl_Lvl5_CM4->text());
                        GL_Lvl5.replace("GL_LV_CM5_Line", QString::number(GL_Lvl_Lvl5_NbrCM5->value()) + "X " + GL_Lvl_Lvl5_CM5->text());

                        int GL_Lvl5_VCM1 = GL_Lvl_Lvl5_NbrCM1->value();
                        int GL_Lvl5_VCM2 = GL_Lvl_Lvl5_NbrCM2->value();
                        int GL_Lvl5_VCM3 = GL_Lvl_Lvl5_NbrCM3->value();
                        int GL_Lvl5_VCM4 = GL_Lvl_Lvl5_NbrCM4->value();
                        int GL_Lvl5_VCM5 = GL_Lvl_Lvl5_NbrCM5->value();

                        int GL_Lvl5_VCMR = GL_Lvl5_VCM1 + GL_Lvl5_VCM2 + GL_Lvl5_VCM3 + GL_Lvl5_VCM4 + GL_Lvl5_VCM5;

                        GL_Lvl5.replace("GL_LV_CMR_Line", QString::number(GL_Lvl5_VCMR));
                        GL_Lvl5.replace("GL_LV_Desc_Line", GL_Lvl_Lvl5_Desc->toPlainText());
                        GL_Lvl5.replace("GL_LV_PImg_Line", GL_Lvl_Lvl5_PlanImg->text());
            }
        }else{
            //Load GL_Lvl Template
                QString GL_Lvl1_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_hcm.pouik";
                QFile GL_Lvl1_File(GL_Lvl1_Template_Path);
                GL_Lvl1_File.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream GL_Lvl1_TextStream(&GL_Lvl1_File);
                GL_Lvl1_TextStream.setCodec("UTF-8");

                GL_Lvl1 = GL_Lvl1_TextStream.readAll();

                //Replace GL_Lvl1 Values by glace() Lvl_Lvl1 Page Values
                    GL_Lvl1.replace("GL_LV_Nbr_Line", "1");
                    GL_Lvl1.replace("GL_LV_Img_Line", GL_Lvl_Lvl1_Img->text());
                    GL_Lvl1.replace("GL_LV_Desc_Line", GL_Lvl_Lvl1_Desc->toPlainText());
                    GL_Lvl1.replace("GL_LV_PImg_Line", GL_Lvl_Lvl1_PlanImg->text());

            if(GL_Lvl_LvlCount >= 2){
                //Load GL_Lvl Templat
                    QString GL_Lvl2_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_hcm.pouik";
                    QFile GL_Lvl2_File(GL_Lvl2_Template_Path);
                    GL_Lvl2_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl2_TextStream(&GL_Lvl2_File);
                    GL_Lvl2_TextStream.setCodec("UTF-8");

                    GL_Lvl2 = GL_Lvl2_TextStream.readAll();

                    //Replace GL_Lvl2 Values by glace() Lvl_Lvl2 Page Values
                        GL_Lvl2.replace("GL_LV_Nbr_Line", "2");
                        GL_Lvl2.replace("GL_LV_Img_Line", GL_Lvl_Lvl2_Img->text());
                        GL_Lvl2.replace("GL_LV_Desc_Line", GL_Lvl_Lvl2_Desc->toPlainText());
                        GL_Lvl2.replace("GL_LV_PImg_Line", GL_Lvl_Lvl2_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 3){
                //Load GL_Lvl Templat
                    QString GL_Lvl3_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_hcm.pouik";
                    QFile GL_Lvl3_File(GL_Lvl3_Template_Path);
                    GL_Lvl3_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl3_TextStream(&GL_Lvl3_File);
                    GL_Lvl3_TextStream.setCodec("UTF-8");

                    GL_Lvl3 = GL_Lvl3_TextStream.readAll();

                    //Replace GL_Lvl3 Values by glace() Lvl_Lvl3 Page Values
                        GL_Lvl3.replace("GL_LV_Nbr_Line", "3");
                        GL_Lvl3.replace("GL_LV_Img_Line", GL_Lvl_Lvl3_Img->text());
                        GL_Lvl3.replace("GL_LV_Desc_Line", GL_Lvl_Lvl3_Desc->toPlainText());
                        GL_Lvl3.replace("GL_LV_PImg_Line", GL_Lvl_Lvl3_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 4){
                //Load GL_Lvl Templat
                    QString GL_Lvl4_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_hcm.pouik";
                    QFile GL_Lvl4_File(GL_Lvl4_Template_Path);
                    GL_Lvl4_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl4_TextStream(&GL_Lvl4_File);
                    GL_Lvl4_TextStream.setCodec("UTF-8");

                    GL_Lvl4 = GL_Lvl4_TextStream.readAll();

                    //Replace GL_Lvl4 Values by glace() Lvl_Lvl4 Page Values
                        GL_Lvl4.replace("GL_LV_Nbr_Line", "4");
                        GL_Lvl4.replace("GL_LV_Img_Line", GL_Lvl_Lvl4_Img->text());
                        GL_Lvl4.replace("GL_LV_Desc_Line", GL_Lvl_Lvl4_Desc->toPlainText());
                        GL_Lvl4.replace("GL_LV_PImg_Line", GL_Lvl_Lvl4_PlanImg->text());
            }
            if(GL_Lvl_LvlCount >= 5){
                //Load GL_Lvl Templat
                    QString GL_Lvl5_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\lvl_hcm.pouik";
                    QFile GL_Lvl5_File(GL_Lvl5_Template_Path);
                    GL_Lvl5_File.open(QIODevice::ReadOnly | QIODevice::Text);
                    QTextStream GL_Lvl5_TextStream(&GL_Lvl5_File);
                    GL_Lvl5_TextStream.setCodec("UTF-8");

                    GL_Lvl5 = GL_Lvl5_TextStream.readAll();

                    //Replace GL_Lvl5 Values by glace() Lvl_Lvl5 Page Values
                        GL_Lvl5.replace("GL_LV_Nbr_Line", "5");
                        GL_Lvl5.replace("GL_LV_Img_Line", GL_Lvl_Lvl5_Img->text());
                        GL_Lvl5.replace("GL_LV_Desc_Line", GL_Lvl_Lvl5_Desc->toPlainText());
                        GL_Lvl5.replace("GL_LV_PImg_Line", GL_Lvl_Lvl5_PlanImg->text());
            }
        }
        //Load GL_CMTop Template
            QString GL_CMTop_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\cm_1.pouik";
            QFile GL_CMTop_File(GL_CMTop_Template_Path);
            GL_CMTop_File.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream GL_CMTop_TextStream(&GL_CMTop_File);
            GL_CMTop_TextStream.setCodec("UTF-8");

            GL_CMTop = GL_CMTop_TextStream.readAll();

       //Load GL_End Template
            QString GL_End_Template_Path = settings.value("Configuration/TemplateGlace").toString() + "\\end.pouik";
            QFile GL_End_File(GL_End_Template_Path);
            GL_End_File.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream GL_End_TextStream(&GL_End_File);
            GL_End_TextStream.setCodec("UTF-8");

            GL_End = GL_End_TextStream.readAll();

        Glace += GL_Main;
        if(Glace_State == 1){
            Glace += GL_CMTop;
            Glace += GL_CM1;
            if(GL_Cm_CmCount >= 2){
                Glace += GL_CM2;
            }
            if(GL_Cm_CmCount >= 3){
                Glace += GL_CM3;
            }
            if(GL_Cm_CmCount >= 4){
                Glace += GL_CM4;
            }
            if(GL_Cm_CmCount >= 5){
                Glace += GL_CM5;
            }
            if(GL_Cm_CmCount >= 6){
                Glace += GL_CM6;
            }
            if(GL_Cm_CmCount >= 7){
                Glace += GL_CM7;
            }
            if(GL_Cm_CmCount >= 8){
                Glace += GL_CM8;
            }
            if(GL_Cm_CmCount >= 9){
                Glace += GL_CM9;
            }
            if(GL_Cm_CmCount >= 10){
                Glace += GL_CM10;
            }
            Glace += GL_Alarm;
        }
        Glace += GL_Plan;
        Glace += GL_Lvl1;
        if(GL_Lvl_LvlCount >= 2){
            Glace += GL_Lvl2;
        }
        if(GL_Lvl_LvlCount >= 3){
            Glace += GL_Lvl3;
        }
        if(GL_Lvl_LvlCount >= 4){
            Glace += GL_Lvl4;
        }
        if(GL_Lvl_LvlCount >= 5){
            Glace += GL_Lvl5;
        }
        Glace += GL_End;

    //Send Date to the FrameCodeGenerator Class
        FrameCodeGenerator *frameCode = new FrameCodeGenerator(Glace, Protection, this);
        frameCode->exec();
}

void MainFrame::generateCodeIa()
{
    if(AI_Main_Name->text().isEmpty()){
        QMessageBox::information(this, "ERROR", "Veuillez entrer au moins le nom de l'IA.");
        return;
    }

    QSettings settings("Exiel", "DC_Tools");

    QString Protection;
    QString Ai;

    //Load Protection Template
        QString Protection_Template_Path = settings.value("Protection/TemplateProtection").toString();
        QFile Protection_File(Protection_Template_Path);
        Protection_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream Protection_TextStream(&Protection_File);
        Protection_TextStream.setCodec("UTF-8");

        Protection = Protection_TextStream.readAll();

        //Replace Protection Values by Config Values
            Protection.replace("PR_Name", settings.value("Protection/Name").toString());
            Protection.replace("PR_Vers", settings.value("Protection/Version").toString());
            Protection.replace("PR_UrlG", settings.value("Protection/UrlGlace").toString());
            Protection.replace("PR_NGla", settings.value("Protection/NameGlace").toString());
            Protection.replace("PR_Read", settings.value("Protection/Read").toString());
            Protection.replace("PR_Writ", settings.value("Protection/Write").toString());
            Protection.replace("PR_Mode", settings.value("Protection/Moderator").toString());
            Protection.replace("PR_Admi", settings.value("Protection/Administrator").toString());

    //Load Ai Template
        QString Ai_Template_Path = settings.value("Configuration/TemplateAi").toString();
        QFile Ai_File(Ai_Template_Path);
        Ai_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream Ai_TextStream(&Ai_File);
        Ai_TextStream.setCodec("UTF-8");

        Ai = Ai_TextStream.readAll();

        //Replace Ai Values by ai() Values
            Ai.replace("IA_Img_Line", AI_Main_Img->text());
            Ai.replace("IA_Name_Line", AI_Main_Name->text());
            Ai.replace("IA_Tach_Line", AI_Desc_Task->toPlainText());
            Ai.replace("IA_Phys_Line", AI_Desc_Phys->toPlainText());
            Ai.replace("IA_Phys_Img_Line", AI_Desc_Phys_Img->text());
            Ai.replace("IA_Comp_Line", AI_Desc_Beha->toPlainText());
            Ai.replace("IA_Comb_Line", AI_Desc_Fight->toPlainText());
            Ai.replace("IA_Desa_Line", AI_Desc_Disa->toPlainText());
            Ai.replace("IA_Natu1_line", AI_Tech_Nature1->currentText());
            Ai.replace("IA_Natu2_line", AI_Tech_Nature2->currentText());
            Ai.replace("IA_Natu3_line", AI_Tech_Nature3->currentText());
            Ai.replace("IA_Home_Line", AI_Tech_Home->text());
            Ai.replace("IA_HomeP_Line", AI_Tech_HomeP->text());
            Ai.replace("IA_HomeM_Line", AI_Tech_HomeM->text());
            Ai.replace("IA_Fonc_Line", AI_Tech_Func->toPlainText());
            Ai.replace("IA_Hier_Line", AI_Tech_Hier->toPlainText());
            Ai.replace("IA_Port_Line", AI_Tech_Scope->toPlainText());
            Ai.replace("IA_Ress_Line", AI_Tech_Ress->toPlainText());
            Ai.replace("IA_Meth_Line", AI_Tech_Meth->toPlainText());

    //Send Data to the FrameCodeGenerator Class
        FrameCodeGenerator *frameCode = new FrameCodeGenerator(Ai, Protection, this);
        frameCode->exec();
}
