/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_deco_connexion;
    QLabel *label_adresse_mail_connexion;
    QLabel *label_mot_de_passe_connexion;
    QPushButton *btn_mot_de_passe_oublie_connexion;
    QLabel *erreur_connexion;
    QLabel *label_titre_connexion;
    QLineEdit *input_adresse_mail_connexion;
    QLineEdit *input_mot_de_passe_connexion;
    QPushButton *btn_se_connecter_connexion;
    QPushButton *btn_aller_a_inscription_connexion;
    QWidget *page_2;
    QFrame *frame_deco_inscription;
    QLabel *label_adresse_mail_inscription;
    QLabel *label_mot_de_passe_1_inscription;
    QLabel *label_nom_d_utilisateur_inscription;
    QLabel *label_mot_de_passe_2_inscription;
    QLabel *erreur_inscription;
    QLabel *label_title_inscription;
    QPushButton *btn_s_inscrire_inscription;
    QLineEdit *input_mot_de_passe_1_inscription;
    QLineEdit *input_adresse_mail_inscription;
    QPushButton *btn_aller_a_connexion_inscription;
    QLineEdit *input_nom_d_utilisateur_inscription;
    QLineEdit *input_mot_de_passe_2_inscription;
    QWidget *page_3;
    QLabel *label_tmp;
    QPushButton *btn_retourner_page_connexion;
    QWidget *page_4;
    QFrame *frame_deco_contacts;
    QLineEdit *input_search_contact;
    QLabel *label_mes_contacts;
    QPushButton *btn_ajouter_contacts;
    QScrollArea *scrollArea_contacts;
    QWidget *scrollContents_contacts;
    QFrame *frame_notif;
    QLabel *label_notif;
    QPushButton *btn_close_notif;
    QLabel *label_notif_nom;
    QFrame *frame_deco_haut_de_page;
    QLabel *label_nom_contact_select;
    QPushButton *btn_appel;
    QPushButton *btn_parametres;
    QLabel *label_user;
    QPushButton *btn_deconnect;
    QPushButton *icon_contact_select;
    QPushButton *icon_user;
    QTextEdit *nv_message;
    QPushButton *btn_envoyer_mess;
    QFrame *frame_message_box_1;
    QFrame *frame_messages_box_2;
    QScrollArea *message_box;
    QWidget *scrollAreaWidgetContents;
    QFrame *call_box;
    QFrame *frame_deco_barre_separation;
    QFrame *frame_deco_boutons_appel;
    QPushButton *btn_end_call;
    QPushButton *btn_sound_mute;
    QPushButton *btn_micro_mute;
    QPushButton *caller_1;
    QPushButton *caller_2;
    QFrame *bulle_1;
    QFrame *bulle_2;
    QFrame *bulle_3;
    QFrame *bulle_4;
    QFrame *bulle_5;
    QFrame *frame_deco_recherche_contacts;
    QFrame *frame_deco_interieure_recherche_contact;
    QPushButton *btn_quitter_recherche_contact;
    QLineEdit *input_rechercher_contact;
    QLabel *label_titre_ajouter_contact;
    QPushButton *btn_search_new_contact;
    QLabel *label_msg_add_contact;
    QFrame *frame_deco_parametres;
    QFrame *frame_deco_interieure_parametres;
    QPushButton *btn_quitter_parametres;
    QLabel *label_titre_parametres;
    QLabel *label_microphone_parametres;
    QComboBox *comboBox_choix_micro_parametres;
    QFrame *frame_deco_friend_request;
    QFrame *frame_deco_interieur_friend_request;
    QLabel *label_titre_invitation;
    QLabel *label_name_friend_request;
    QPushButton *btn_accept_friend_request;
    QPushButton *btn_decline_friend_request;
    QFrame *frame_deco_appel;
    QFrame *frame_deco_interieur_appel;
    QLineEdit *label_title_notif_appel;
    QPushButton *btn_notif_appel_accepter;
    QPushButton *btn_notif_appel_refuser;
    QLabel *label_notif_appel_nom;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1920, 1080));
        stackedWidget->setStyleSheet(QString::fromUtf8("background: rgb(73, 80, 87);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_deco_connexion = new QFrame(page);
        frame_deco_connexion->setObjectName(QString::fromUtf8("frame_deco_connexion"));
        frame_deco_connexion->setGeometry(QRect(410, 170, 1100, 696));
        frame_deco_connexion->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);\n"
"border-radius: 100px;"));
        frame_deco_connexion->setFrameShape(QFrame::StyledPanel);
        frame_deco_connexion->setFrameShadow(QFrame::Raised);
        label_adresse_mail_connexion = new QLabel(frame_deco_connexion);
        label_adresse_mail_connexion->setObjectName(QString::fromUtf8("label_adresse_mail_connexion"));
        label_adresse_mail_connexion->setGeometry(QRect(130, 150, 471, 31));
        QFont font;
        font.setPointSize(20);
        label_adresse_mail_connexion->setFont(font);
        label_adresse_mail_connexion->setStyleSheet(QString::fromUtf8("color: white;"));
        label_mot_de_passe_connexion = new QLabel(frame_deco_connexion);
        label_mot_de_passe_connexion->setObjectName(QString::fromUtf8("label_mot_de_passe_connexion"));
        label_mot_de_passe_connexion->setGeometry(QRect(130, 290, 511, 31));
        label_mot_de_passe_connexion->setFont(font);
        label_mot_de_passe_connexion->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_mot_de_passe_oublie_connexion = new QPushButton(frame_deco_connexion);
        btn_mot_de_passe_oublie_connexion->setObjectName(QString::fromUtf8("btn_mot_de_passe_oublie_connexion"));
        btn_mot_de_passe_oublie_connexion->setGeometry(QRect(740, 410, 231, 23));
        QFont font1;
        font1.setPointSize(16);
        btn_mot_de_passe_oublie_connexion->setFont(font1);
        btn_mot_de_passe_oublie_connexion->setCursor(QCursor(Qt::PointingHandCursor));
        btn_mot_de_passe_oublie_connexion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	text-decoration: underline;\n"
"}"));
        erreur_connexion = new QLabel(frame_deco_connexion);
        erreur_connexion->setObjectName(QString::fromUtf8("erreur_connexion"));
        erreur_connexion->setGeometry(QRect(400, 150, 361, 21));
        QFont font2;
        font2.setPointSize(12);
        erreur_connexion->setFont(font2);
        erreur_connexion->setStyleSheet(QString::fromUtf8("color: red;"));
        label_titre_connexion = new QLabel(page);
        label_titre_connexion->setObjectName(QString::fromUtf8("label_titre_connexion"));
        label_titre_connexion->setGeometry(QRect(824, 230, 571, 51));
        QFont font3;
        font3.setPointSize(36);
        label_titre_connexion->setFont(font3);
        label_titre_connexion->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: rgb(52, 58, 64);"));
        input_adresse_mail_connexion = new QLineEdit(page);
        input_adresse_mail_connexion->setObjectName(QString::fromUtf8("input_adresse_mail_connexion"));
        input_adresse_mail_connexion->setGeometry(QRect(535, 360, 850, 73));
        QFont font4;
        font4.setPointSize(22);
        input_adresse_mail_connexion->setFont(font4);
        input_adresse_mail_connexion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_adresse_mail_connexion->setMaxLength(64);
        input_adresse_mail_connexion->setClearButtonEnabled(true);
        input_mot_de_passe_connexion = new QLineEdit(page);
        input_mot_de_passe_connexion->setObjectName(QString::fromUtf8("input_mot_de_passe_connexion"));
        input_mot_de_passe_connexion->setGeometry(QRect(535, 500, 850, 73));
        input_mot_de_passe_connexion->setFont(font4);
        input_mot_de_passe_connexion->setCursor(QCursor(Qt::IBeamCursor));
        input_mot_de_passe_connexion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_mot_de_passe_connexion->setMaxLength(32);
        input_mot_de_passe_connexion->setEchoMode(QLineEdit::Password);
        input_mot_de_passe_connexion->setClearButtonEnabled(true);
        btn_se_connecter_connexion = new QPushButton(page);
        btn_se_connecter_connexion->setObjectName(QString::fromUtf8("btn_se_connecter_connexion"));
        btn_se_connecter_connexion->setGeometry(QRect(771, 650, 378, 80));
        QFont font5;
        font5.setPointSize(28);
        btn_se_connecter_connexion->setFont(font5);
        btn_se_connecter_connexion->setCursor(QCursor(Qt::PointingHandCursor));
        btn_se_connecter_connexion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(73, 80, 87);\n"
"	border-radius: 15px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background: rgb(91, 100, 109);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("assets/icons/connection.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_se_connecter_connexion->setIcon(icon);
        btn_se_connecter_connexion->setIconSize(QSize(45, 45));
        btn_aller_a_inscription_connexion = new QPushButton(page);
        btn_aller_a_inscription_connexion->setObjectName(QString::fromUtf8("btn_aller_a_inscription_connexion"));
        btn_aller_a_inscription_connexion->setGeometry(QRect(828, 760, 263, 56));
        btn_aller_a_inscription_connexion->setFont(font5);
        btn_aller_a_inscription_connexion->setCursor(QCursor(Qt::PointingHandCursor));
        btn_aller_a_inscription_connexion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(73, 80, 87);\n"
"	border-radius: 15px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background: rgb(91, 100, 109);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("assets/icons/enregistrer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_aller_a_inscription_connexion->setIcon(icon1);
        btn_aller_a_inscription_connexion->setIconSize(QSize(35, 35));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        frame_deco_inscription = new QFrame(page_2);
        frame_deco_inscription->setObjectName(QString::fromUtf8("frame_deco_inscription"));
        frame_deco_inscription->setGeometry(QRect(410, 90, 1100, 850));
        frame_deco_inscription->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);\n"
"border-radius: 100px;"));
        frame_deco_inscription->setFrameShape(QFrame::StyledPanel);
        frame_deco_inscription->setFrameShadow(QFrame::Raised);
        label_adresse_mail_inscription = new QLabel(frame_deco_inscription);
        label_adresse_mail_inscription->setObjectName(QString::fromUtf8("label_adresse_mail_inscription"));
        label_adresse_mail_inscription->setGeometry(QRect(140, 250, 511, 31));
        label_adresse_mail_inscription->setFont(font);
        label_adresse_mail_inscription->setStyleSheet(QString::fromUtf8("color: white;"));
        label_mot_de_passe_1_inscription = new QLabel(frame_deco_inscription);
        label_mot_de_passe_1_inscription->setObjectName(QString::fromUtf8("label_mot_de_passe_1_inscription"));
        label_mot_de_passe_1_inscription->setGeometry(QRect(140, 380, 631, 31));
        label_mot_de_passe_1_inscription->setFont(font);
        label_mot_de_passe_1_inscription->setStyleSheet(QString::fromUtf8("color: white;"));
        label_nom_d_utilisateur_inscription = new QLabel(frame_deco_inscription);
        label_nom_d_utilisateur_inscription->setObjectName(QString::fromUtf8("label_nom_d_utilisateur_inscription"));
        label_nom_d_utilisateur_inscription->setGeometry(QRect(140, 120, 491, 31));
        label_nom_d_utilisateur_inscription->setFont(font);
        label_nom_d_utilisateur_inscription->setStyleSheet(QString::fromUtf8("color: white;"));
        label_mot_de_passe_2_inscription = new QLabel(frame_deco_inscription);
        label_mot_de_passe_2_inscription->setObjectName(QString::fromUtf8("label_mot_de_passe_2_inscription"));
        label_mot_de_passe_2_inscription->setGeometry(QRect(140, 510, 721, 31));
        label_mot_de_passe_2_inscription->setFont(font);
        label_mot_de_passe_2_inscription->setStyleSheet(QString::fromUtf8("color: white;"));
        erreur_inscription = new QLabel(frame_deco_inscription);
        erreur_inscription->setObjectName(QString::fromUtf8("erreur_inscription"));
        erreur_inscription->setGeometry(QRect(410, 120, 301, 16));
        erreur_inscription->setFont(font2);
        erreur_inscription->setStyleSheet(QString::fromUtf8("color: red;"));
        label_title_inscription = new QLabel(page_2);
        label_title_inscription->setObjectName(QString::fromUtf8("label_title_inscription"));
        label_title_inscription->setGeometry(QRect(810, 130, 661, 51));
        label_title_inscription->setFont(font3);
        label_title_inscription->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: rgb(52, 58, 64);"));
        btn_s_inscrire_inscription = new QPushButton(page_2);
        btn_s_inscrire_inscription->setObjectName(QString::fromUtf8("btn_s_inscrire_inscription"));
        btn_s_inscrire_inscription->setGeometry(QRect(771, 750, 378, 80));
        btn_s_inscrire_inscription->setFont(font5);
        btn_s_inscrire_inscription->setCursor(QCursor(Qt::PointingHandCursor));
        btn_s_inscrire_inscription->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(73, 80, 87);\n"
"	border-radius: 15px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background: rgb(91, 100, 109);\n"
"}"));
        btn_s_inscrire_inscription->setIcon(icon1);
        btn_s_inscrire_inscription->setIconSize(QSize(45, 45));
        input_mot_de_passe_1_inscription = new QLineEdit(page_2);
        input_mot_de_passe_1_inscription->setObjectName(QString::fromUtf8("input_mot_de_passe_1_inscription"));
        input_mot_de_passe_1_inscription->setGeometry(QRect(535, 510, 850, 73));
        input_mot_de_passe_1_inscription->setFont(font4);
        input_mot_de_passe_1_inscription->setCursor(QCursor(Qt::IBeamCursor));
        input_mot_de_passe_1_inscription->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_mot_de_passe_1_inscription->setMaxLength(32);
        input_mot_de_passe_1_inscription->setEchoMode(QLineEdit::Password);
        input_mot_de_passe_1_inscription->setClearButtonEnabled(true);
        input_adresse_mail_inscription = new QLineEdit(page_2);
        input_adresse_mail_inscription->setObjectName(QString::fromUtf8("input_adresse_mail_inscription"));
        input_adresse_mail_inscription->setGeometry(QRect(535, 380, 850, 73));
        input_adresse_mail_inscription->setFont(font4);
        input_adresse_mail_inscription->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_adresse_mail_inscription->setMaxLength(64);
        input_adresse_mail_inscription->setClearButtonEnabled(true);
        btn_aller_a_connexion_inscription = new QPushButton(page_2);
        btn_aller_a_connexion_inscription->setObjectName(QString::fromUtf8("btn_aller_a_connexion_inscription"));
        btn_aller_a_connexion_inscription->setGeometry(QRect(810, 850, 301, 56));
        btn_aller_a_connexion_inscription->setFont(font5);
        btn_aller_a_connexion_inscription->setCursor(QCursor(Qt::PointingHandCursor));
        btn_aller_a_connexion_inscription->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(73, 80, 87);\n"
"	border-radius: 15px;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background: rgb(91, 100, 109);\n"
"}"));
        btn_aller_a_connexion_inscription->setIcon(icon);
        btn_aller_a_connexion_inscription->setIconSize(QSize(35, 35));
        input_nom_d_utilisateur_inscription = new QLineEdit(page_2);
        input_nom_d_utilisateur_inscription->setObjectName(QString::fromUtf8("input_nom_d_utilisateur_inscription"));
        input_nom_d_utilisateur_inscription->setGeometry(QRect(535, 250, 850, 73));
        input_nom_d_utilisateur_inscription->setFont(font4);
        input_nom_d_utilisateur_inscription->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_nom_d_utilisateur_inscription->setMaxLength(32);
        input_nom_d_utilisateur_inscription->setClearButtonEnabled(true);
        input_mot_de_passe_2_inscription = new QLineEdit(page_2);
        input_mot_de_passe_2_inscription->setObjectName(QString::fromUtf8("input_mot_de_passe_2_inscription"));
        input_mot_de_passe_2_inscription->setGeometry(QRect(535, 640, 850, 73));
        input_mot_de_passe_2_inscription->setFont(font4);
        input_mot_de_passe_2_inscription->setCursor(QCursor(Qt::IBeamCursor));
        input_mot_de_passe_2_inscription->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_mot_de_passe_2_inscription->setMaxLength(32);
        input_mot_de_passe_2_inscription->setEchoMode(QLineEdit::Password);
        input_mot_de_passe_2_inscription->setClearButtonEnabled(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_tmp = new QLabel(page_3);
        label_tmp->setObjectName(QString::fromUtf8("label_tmp"));
        label_tmp->setGeometry(QRect(840, 650, 711, 41));
        label_tmp->setFont(font4);
        label_tmp->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_retourner_page_connexion = new QPushButton(page_3);
        btn_retourner_page_connexion->setObjectName(QString::fromUtf8("btn_retourner_page_connexion"));
        btn_retourner_page_connexion->setGeometry(QRect(860, 710, 301, 71));
        btn_retourner_page_connexion->setFont(font);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        frame_deco_contacts = new QFrame(page_4);
        frame_deco_contacts->setObjectName(QString::fromUtf8("frame_deco_contacts"));
        frame_deco_contacts->setGeometry(QRect(0, -1, 450, 1081));
        frame_deco_contacts->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);\n"
"border: none;"));
        frame_deco_contacts->setFrameShape(QFrame::StyledPanel);
        frame_deco_contacts->setFrameShadow(QFrame::Raised);
        input_search_contact = new QLineEdit(frame_deco_contacts);
        input_search_contact->setObjectName(QString::fromUtf8("input_search_contact"));
        input_search_contact->setGeometry(QRect(30, 30, 391, 45));
        input_search_contact->setFont(font);
        input_search_contact->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_search_contact->setMaxLength(32);
        input_search_contact->setClearButtonEnabled(true);
        label_mes_contacts = new QLabel(frame_deco_contacts);
        label_mes_contacts->setObjectName(QString::fromUtf8("label_mes_contacts"));
        label_mes_contacts->setGeometry(QRect(36, 90, 231, 41));
        QFont font6;
        font6.setPointSize(24);
        label_mes_contacts->setFont(font6);
        label_mes_contacts->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_ajouter_contacts = new QPushButton(frame_deco_contacts);
        btn_ajouter_contacts->setObjectName(QString::fromUtf8("btn_ajouter_contacts"));
        btn_ajouter_contacts->setGeometry(QRect(380, 90, 41, 41));
        QFont font7;
        font7.setPointSize(34);
        btn_ajouter_contacts->setFont(font7);
        btn_ajouter_contacts->setCursor(QCursor(Qt::PointingHandCursor));
        btn_ajouter_contacts->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("assets/icons/ajouter_contact.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ajouter_contacts->setIcon(icon2);
        btn_ajouter_contacts->setIconSize(QSize(35, 35));
        scrollArea_contacts = new QScrollArea(frame_deco_contacts);
        scrollArea_contacts->setObjectName(QString::fromUtf8("scrollArea_contacts"));
        scrollArea_contacts->setGeometry(QRect(10, 135, 431, 861));
        scrollArea_contacts->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"		border: none;\n"
"}\n"
"\n"
"QScrollBar::vertical {              \n"
"        border: none;\n"
"        background: white;\n"
"        width:0px;\n"
"        margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"        background: rgb(52, 58, 64);\n"
"        min-height: 0px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));\n"
"        height: 0 px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical { \n"
"		background-color: rgb(52, 58, 64);\n"
"}\n"
"\n"
"QS"
                        "crollBar::add-page:vertical {\n"
"		 background-color: rgb(52, 58, 64);\n"
"}"));
        scrollArea_contacts->setWidgetResizable(true);
        scrollContents_contacts = new QWidget();
        scrollContents_contacts->setObjectName(QString::fromUtf8("scrollContents_contacts"));
        scrollContents_contacts->setGeometry(QRect(0, 0, 431, 861));
        scrollContents_contacts->setStyleSheet(QString::fromUtf8("margin-bottom: 10px;"));
        frame_notif = new QFrame(scrollContents_contacts);
        frame_notif->setObjectName(QString::fromUtf8("frame_notif"));
        frame_notif->setGeometry(QRect(10, 800, 411, 51));
        frame_notif->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);\n"
"border-radius: 15px;"));
        frame_notif->setFrameShape(QFrame::StyledPanel);
        frame_notif->setFrameShadow(QFrame::Raised);
        label_notif = new QLabel(frame_notif);
        label_notif->setObjectName(QString::fromUtf8("label_notif"));
        label_notif->setGeometry(QRect(10, 10, 161, 31));
        label_notif->setFont(font2);
        label_notif->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_close_notif = new QPushButton(frame_notif);
        btn_close_notif->setObjectName(QString::fromUtf8("btn_close_notif"));
        btn_close_notif->setGeometry(QRect(330, 0, 41, 51));
        btn_close_notif->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("assets/icons/croix.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_close_notif->setIcon(icon3);
        btn_close_notif->setIconSize(QSize(25, 25));
        label_notif_nom = new QLabel(frame_notif);
        label_notif_nom->setObjectName(QString::fromUtf8("label_notif_nom"));
        label_notif_nom->setGeometry(QRect(170, 10, 231, 31));
        label_notif_nom->setFont(font2);
        label_notif_nom->setStyleSheet(QString::fromUtf8("color: white;"));
        label_notif_nom->raise();
        label_notif->raise();
        btn_close_notif->raise();
        scrollArea_contacts->setWidget(scrollContents_contacts);
        frame_deco_haut_de_page = new QFrame(page_4);
        frame_deco_haut_de_page->setObjectName(QString::fromUtf8("frame_deco_haut_de_page"));
        frame_deco_haut_de_page->setGeometry(QRect(450, 0, 1470, 89));
        frame_deco_haut_de_page->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);"));
        frame_deco_haut_de_page->setFrameShape(QFrame::StyledPanel);
        frame_deco_haut_de_page->setFrameShadow(QFrame::Raised);
        label_nom_contact_select = new QLabel(frame_deco_haut_de_page);
        label_nom_contact_select->setObjectName(QString::fromUtf8("label_nom_contact_select"));
        label_nom_contact_select->setGeometry(QRect(160, 20, 250, 51));
        label_nom_contact_select->setFont(font4);
        label_nom_contact_select->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_appel = new QPushButton(frame_deco_haut_de_page);
        btn_appel->setObjectName(QString::fromUtf8("btn_appel"));
        btn_appel->setEnabled(true);
        btn_appel->setGeometry(QRect(40, 20, 51, 51));
        btn_appel->setFont(font7);
        btn_appel->setCursor(QCursor(Qt::PointingHandCursor));
        btn_appel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("assets/icons/appel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_appel->setIcon(icon4);
        btn_appel->setIconSize(QSize(45, 45));
        btn_appel->setCheckable(false);
        btn_parametres = new QPushButton(frame_deco_haut_de_page);
        btn_parametres->setObjectName(QString::fromUtf8("btn_parametres"));
        btn_parametres->setGeometry(QRect(1320, 20, 51, 51));
        btn_parametres->setFont(font7);
        btn_parametres->setCursor(QCursor(Qt::PointingHandCursor));
        btn_parametres->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("assets/icons/parametres.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_parametres->setIcon(icon5);
        btn_parametres->setIconSize(QSize(45, 45));
        label_user = new QLabel(frame_deco_haut_de_page);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(980, 20, 250, 51));
        label_user->setFont(font4);
        label_user->setLayoutDirection(Qt::LeftToRight);
        label_user->setStyleSheet(QString::fromUtf8("color: white;"));
        label_user->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_deconnect = new QPushButton(frame_deco_haut_de_page);
        btn_deconnect->setObjectName(QString::fromUtf8("btn_deconnect"));
        btn_deconnect->setGeometry(QRect(1380, 20, 51, 51));
        btn_deconnect->setFont(font7);
        btn_deconnect->setCursor(QCursor(Qt::PointingHandCursor));
        btn_deconnect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("assets/icons/deconnecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_deconnect->setIcon(icon6);
        btn_deconnect->setIconSize(QSize(60, 60));
        icon_contact_select = new QPushButton(frame_deco_haut_de_page);
        icon_contact_select->setObjectName(QString::fromUtf8("icon_contact_select"));
        icon_contact_select->setEnabled(true);
        icon_contact_select->setGeometry(QRect(100, 20, 51, 51));
        icon_contact_select->setFont(font7);
        icon_contact_select->setCursor(QCursor(Qt::ArrowCursor));
        icon_contact_select->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("assets/contact-images/undefined.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon_contact_select->setIcon(icon7);
        icon_contact_select->setIconSize(QSize(45, 45));
        icon_contact_select->setCheckable(false);
        icon_user = new QPushButton(frame_deco_haut_de_page);
        icon_user->setObjectName(QString::fromUtf8("icon_user"));
        icon_user->setEnabled(true);
        icon_user->setGeometry(QRect(1240, 20, 51, 51));
        icon_user->setFont(font7);
        icon_user->setCursor(QCursor(Qt::ArrowCursor));
        icon_user->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        icon_user->setIcon(icon7);
        icon_user->setIconSize(QSize(45, 45));
        icon_user->setCheckable(false);
        nv_message = new QTextEdit(page_4);
        nv_message->setObjectName(QString::fromUtf8("nv_message"));
        nv_message->setGeometry(QRect(480, 910, 1400, 91));
        nv_message->setFont(font4);
        nv_message->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        nv_message->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 100px;\n"
"	padding-top: 5px;\n"
"	padding-bottom: 5px;\n"
"	color: rgb(73, 80, 87);\n"
"}\n"
"\n"
"QScrollArea {\n"
"		border: none;\n"
"}\n"
"\n"
"QScrollBar::vertical {              \n"
"        border: none;\n"
"        background: white;\n"
"        width:0px;\n"
"        margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"        background: rgb(52, 58, 64);\n"
"        min-height: 0px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47,"
                        " 130));\n"
"        height: 0 px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical { \n"
"		background-color: rgb(52, 58, 64);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"		 background-color: rgb(52, 58, 64);\n"
"}"));
        btn_envoyer_mess = new QPushButton(page_4);
        btn_envoyer_mess->setObjectName(QString::fromUtf8("btn_envoyer_mess"));
        btn_envoyer_mess->setGeometry(QRect(1790, 910, 51, 91));
        btn_envoyer_mess->setFont(font7);
        btn_envoyer_mess->setCursor(QCursor(Qt::PointingHandCursor));
        btn_envoyer_mess->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(33, 37, 41);\n"
"	color: white;\n"
"	border: none;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("assets/icons/envoyer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_envoyer_mess->setIcon(icon8);
        btn_envoyer_mess->setIconSize(QSize(35, 35));
        btn_envoyer_mess->setCheckable(false);
        frame_message_box_1 = new QFrame(page_4);
        frame_message_box_1->setObjectName(QString::fromUtf8("frame_message_box_1"));
        frame_message_box_1->setGeometry(QRect(450, 90, 1471, 821));
        frame_message_box_1->setStyleSheet(QString::fromUtf8("background: rgb(73, 80, 87);\n"
"border: none;"));
        frame_message_box_1->setFrameShape(QFrame::StyledPanel);
        frame_message_box_1->setFrameShadow(QFrame::Raised);
        frame_messages_box_2 = new QFrame(frame_message_box_1);
        frame_messages_box_2->setObjectName(QString::fromUtf8("frame_messages_box_2"));
        frame_messages_box_2->setGeometry(QRect(-1, 0, 1471, 821));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_messages_box_2->sizePolicy().hasHeightForWidth());
        frame_messages_box_2->setSizePolicy(sizePolicy);
        frame_messages_box_2->setStyleSheet(QString::fromUtf8("margin-top: 5px;\n"
"margin-bottom: 5px;"));
        frame_messages_box_2->setFrameShape(QFrame::StyledPanel);
        frame_messages_box_2->setFrameShadow(QFrame::Raised);
        message_box = new QScrollArea(frame_messages_box_2);
        message_box->setObjectName(QString::fromUtf8("message_box"));
        message_box->setGeometry(QRect(0, 0, 1471, 821));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(message_box->sizePolicy().hasHeightForWidth());
        message_box->setSizePolicy(sizePolicy1);
        message_box->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"		border: none;\n"
"}\n"
"\n"
"QScrollBar::vertical {              \n"
"        border: none;\n"
"        background: white;\n"
"        width:0px;\n"
"        margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"        background: rgb(52, 58, 64);\n"
"        min-height: 0px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));\n"
"        height: 0px;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130));\n"
"        height: 0 px;\n"
"        subcontrol-position: top;\n"
"        subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical { \n"
"		background-color: rgb(52, 58, 64);\n"
"}\n"
"\n"
"QS"
                        "crollBar::add-page:vertical {\n"
"		 background-color: rgb(52, 58, 64);\n"
"}"));
        message_box->setWidgetResizable(true);
        message_box->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1461, 811));
        message_box->setWidget(scrollAreaWidgetContents);
        call_box = new QFrame(page_4);
        call_box->setObjectName(QString::fromUtf8("call_box"));
        call_box->setGeometry(QRect(449, 90, 1471, 200));
        call_box->setStyleSheet(QString::fromUtf8("background: rgb(73, 80, 87);"));
        call_box->setFrameShape(QFrame::StyledPanel);
        call_box->setFrameShadow(QFrame::Raised);
        frame_deco_barre_separation = new QFrame(call_box);
        frame_deco_barre_separation->setObjectName(QString::fromUtf8("frame_deco_barre_separation"));
        frame_deco_barre_separation->setGeometry(QRect(-1, 180, 1471, 20));
        frame_deco_barre_separation->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);\n"
"border: none;"));
        frame_deco_barre_separation->setFrameShape(QFrame::StyledPanel);
        frame_deco_barre_separation->setFrameShadow(QFrame::Raised);
        frame_deco_boutons_appel = new QFrame(call_box);
        frame_deco_boutons_appel->setObjectName(QString::fromUtf8("frame_deco_boutons_appel"));
        frame_deco_boutons_appel->setGeometry(QRect(645, 149, 211, 51));
        frame_deco_boutons_appel->setStyleSheet(QString::fromUtf8("background: rgb(52, 58, 64);\n"
"border: none;\n"
"border-radius: 25px;"));
        frame_deco_boutons_appel->setFrameShape(QFrame::StyledPanel);
        frame_deco_boutons_appel->setFrameShadow(QFrame::Raised);
        btn_end_call = new QPushButton(frame_deco_boutons_appel);
        btn_end_call->setObjectName(QString::fromUtf8("btn_end_call"));
        btn_end_call->setGeometry(QRect(140, 0, 51, 51));
        btn_end_call->setCursor(QCursor(Qt::PointingHandCursor));
        btn_end_call->setIcon(icon3);
        btn_end_call->setIconSize(QSize(35, 35));
        btn_sound_mute = new QPushButton(frame_deco_boutons_appel);
        btn_sound_mute->setObjectName(QString::fromUtf8("btn_sound_mute"));
        btn_sound_mute->setGeometry(QRect(80, 0, 51, 51));
        btn_sound_mute->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("assets/icons/casque.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_sound_mute->setIcon(icon9);
        btn_sound_mute->setIconSize(QSize(35, 35));
        btn_micro_mute = new QPushButton(frame_deco_boutons_appel);
        btn_micro_mute->setObjectName(QString::fromUtf8("btn_micro_mute"));
        btn_micro_mute->setGeometry(QRect(20, 0, 51, 51));
        btn_micro_mute->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("assets/icons/micro.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_micro_mute->setIcon(icon10);
        btn_micro_mute->setIconSize(QSize(35, 35));
        caller_1 = new QPushButton(call_box);
        caller_1->setObjectName(QString::fromUtf8("caller_1"));
        caller_1->setEnabled(true);
        caller_1->setGeometry(QRect(470, 20, 141, 141));
        caller_1->setFont(font7);
        caller_1->setCursor(QCursor(Qt::ArrowCursor));
        caller_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        caller_1->setIcon(icon7);
        caller_1->setIconSize(QSize(125, 125));
        caller_1->setCheckable(false);
        caller_2 = new QPushButton(call_box);
        caller_2->setObjectName(QString::fromUtf8("caller_2"));
        caller_2->setEnabled(true);
        caller_2->setGeometry(QRect(890, 20, 141, 141));
        caller_2->setFont(font7);
        caller_2->setCursor(QCursor(Qt::ArrowCursor));
        caller_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgb(52, 58, 64);\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        caller_2->setIcon(icon7);
        caller_2->setIconSize(QSize(125, 125));
        caller_2->setCheckable(false);
        bulle_1 = new QFrame(call_box);
        bulle_1->setObjectName(QString::fromUtf8("bulle_1"));
        bulle_1->setGeometry(QRect(640, 80, 20, 20));
        bulle_1->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);;\n"
"border: none;\n"
"border-radius: 10px;"));
        bulle_1->setFrameShape(QFrame::StyledPanel);
        bulle_1->setFrameShadow(QFrame::Raised);
        bulle_2 = new QFrame(call_box);
        bulle_2->setObjectName(QString::fromUtf8("bulle_2"));
        bulle_2->setGeometry(QRect(700, 80, 20, 20));
        bulle_2->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);;\n"
"border: none;\n"
"border-radius: 10px;"));
        bulle_2->setFrameShape(QFrame::StyledPanel);
        bulle_2->setFrameShadow(QFrame::Raised);
        bulle_3 = new QFrame(call_box);
        bulle_3->setObjectName(QString::fromUtf8("bulle_3"));
        bulle_3->setGeometry(QRect(740, 80, 20, 20));
        bulle_3->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);;\n"
"border: none;\n"
"border-radius: 10px;"));
        bulle_3->setFrameShape(QFrame::StyledPanel);
        bulle_3->setFrameShadow(QFrame::Raised);
        bulle_4 = new QFrame(call_box);
        bulle_4->setObjectName(QString::fromUtf8("bulle_4"));
        bulle_4->setGeometry(QRect(780, 80, 20, 20));
        bulle_4->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);;\n"
"border: none;\n"
"border-radius: 10px;"));
        bulle_4->setFrameShape(QFrame::StyledPanel);
        bulle_4->setFrameShadow(QFrame::Raised);
        bulle_5 = new QFrame(call_box);
        bulle_5->setObjectName(QString::fromUtf8("bulle_5"));
        bulle_5->setGeometry(QRect(840, 80, 20, 20));
        bulle_5->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);;\n"
"border: none;\n"
"border-radius: 10px;"));
        bulle_5->setFrameShape(QFrame::StyledPanel);
        bulle_5->setFrameShadow(QFrame::Raised);
        frame_deco_recherche_contacts = new QFrame(page_4);
        frame_deco_recherche_contacts->setObjectName(QString::fromUtf8("frame_deco_recherche_contacts"));
        frame_deco_recherche_contacts->setGeometry(QRect(0, 0, 1920, 1080));
        frame_deco_recherche_contacts->setStyleSheet(QString::fromUtf8("background: rgba( 33, 37, 41, 95% );"));
        frame_deco_recherche_contacts->setFrameShape(QFrame::StyledPanel);
        frame_deco_recherche_contacts->setFrameShadow(QFrame::Raised);
        frame_deco_interieure_recherche_contact = new QFrame(frame_deco_recherche_contacts);
        frame_deco_interieure_recherche_contact->setObjectName(QString::fromUtf8("frame_deco_interieure_recherche_contact"));
        frame_deco_interieure_recherche_contact->setGeometry(QRect(447, 440, 1006, 200));
        frame_deco_interieure_recherche_contact->setStyleSheet(QString::fromUtf8("background: rgba( 52, 58, 64, 100% );\n"
"border-radius: 100px;"));
        frame_deco_interieure_recherche_contact->setFrameShape(QFrame::StyledPanel);
        frame_deco_interieure_recherche_contact->setFrameShadow(QFrame::Raised);
        btn_quitter_recherche_contact = new QPushButton(frame_deco_interieure_recherche_contact);
        btn_quitter_recherche_contact->setObjectName(QString::fromUtf8("btn_quitter_recherche_contact"));
        btn_quitter_recherche_contact->setGeometry(QRect(910, 30, 51, 51));
        btn_quitter_recherche_contact->setCursor(QCursor(Qt::PointingHandCursor));
        btn_quitter_recherche_contact->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: rgb(52, 58, 64);"));
        btn_quitter_recherche_contact->setIcon(icon3);
        btn_quitter_recherche_contact->setIconSize(QSize(45, 45));
        input_rechercher_contact = new QLineEdit(frame_deco_interieure_recherche_contact);
        input_rechercher_contact->setObjectName(QString::fromUtf8("input_rechercher_contact"));
        input_rechercher_contact->setGeometry(QRect(110, 120, 791, 45));
        input_rechercher_contact->setFont(font);
        input_rechercher_contact->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background: rgb(33, 37, 41);\n"
"	border-radius: 15px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	color: rgb(73, 80, 87);\n"
"}"));
        input_rechercher_contact->setMaxLength(32);
        label_titre_ajouter_contact = new QLabel(frame_deco_interieure_recherche_contact);
        label_titre_ajouter_contact->setObjectName(QString::fromUtf8("label_titre_ajouter_contact"));
        label_titre_ajouter_contact->setGeometry(QRect(290, 33, 581, 41));
        label_titre_ajouter_contact->setFont(font3);
        label_titre_ajouter_contact->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_search_new_contact = new QPushButton(frame_deco_interieure_recherche_contact);
        btn_search_new_contact->setObjectName(QString::fromUtf8("btn_search_new_contact"));
        btn_search_new_contact->setGeometry(QRect(840, 120, 41, 45));
        btn_search_new_contact->setCursor(QCursor(Qt::PointingHandCursor));
        btn_search_new_contact->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("assets/icons/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search_new_contact->setIcon(icon11);
        btn_search_new_contact->setIconSize(QSize(35, 35));
        label_msg_add_contact = new QLabel(frame_deco_interieure_recherche_contact);
        label_msg_add_contact->setObjectName(QString::fromUtf8("label_msg_add_contact"));
        label_msg_add_contact->setGeometry(QRect(110, 90, 791, 20));
        label_msg_add_contact->setFont(font2);
        label_msg_add_contact->setStyleSheet(QString::fromUtf8("color: white;"));
        label_msg_add_contact->setAlignment(Qt::AlignCenter);
        frame_deco_parametres = new QFrame(page_4);
        frame_deco_parametres->setObjectName(QString::fromUtf8("frame_deco_parametres"));
        frame_deco_parametres->setGeometry(QRect(0, 0, 1920, 1080));
        frame_deco_parametres->setStyleSheet(QString::fromUtf8("background: rgba( 33, 37, 41, 95% );"));
        frame_deco_parametres->setFrameShape(QFrame::StyledPanel);
        frame_deco_parametres->setFrameShadow(QFrame::Raised);
        frame_deco_interieure_parametres = new QFrame(frame_deco_parametres);
        frame_deco_interieure_parametres->setObjectName(QString::fromUtf8("frame_deco_interieure_parametres"));
        frame_deco_interieure_parametres->setGeometry(QRect(447, 170, 1006, 696));
        frame_deco_interieure_parametres->setStyleSheet(QString::fromUtf8("background: rgba( 52, 58, 64, 100% );\n"
"border-radius: 100px;"));
        frame_deco_interieure_parametres->setFrameShape(QFrame::StyledPanel);
        frame_deco_interieure_parametres->setFrameShadow(QFrame::Raised);
        btn_quitter_parametres = new QPushButton(frame_deco_interieure_parametres);
        btn_quitter_parametres->setObjectName(QString::fromUtf8("btn_quitter_parametres"));
        btn_quitter_parametres->setGeometry(QRect(910, 30, 51, 51));
        btn_quitter_parametres->setCursor(QCursor(Qt::PointingHandCursor));
        btn_quitter_parametres->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: rgb(52, 58, 64);"));
        btn_quitter_parametres->setIcon(icon3);
        btn_quitter_parametres->setIconSize(QSize(45, 45));
        label_titre_parametres = new QLabel(frame_deco_interieure_parametres);
        label_titre_parametres->setObjectName(QString::fromUtf8("label_titre_parametres"));
        label_titre_parametres->setGeometry(QRect(380, 34, 521, 41));
        label_titre_parametres->setFont(font3);
        label_titre_parametres->setStyleSheet(QString::fromUtf8("color: white;"));
        label_microphone_parametres = new QLabel(frame_deco_interieure_parametres);
        label_microphone_parametres->setObjectName(QString::fromUtf8("label_microphone_parametres"));
        label_microphone_parametres->setGeometry(QRect(170, 150, 161, 41));
        label_microphone_parametres->setFont(font4);
        label_microphone_parametres->setStyleSheet(QString::fromUtf8("color: white;"));
        comboBox_choix_micro_parametres = new QComboBox(frame_deco_interieure_parametres);
        comboBox_choix_micro_parametres->setObjectName(QString::fromUtf8("comboBox_choix_micro_parametres"));
        comboBox_choix_micro_parametres->setGeometry(QRect(340, 150, 421, 41));
        comboBox_choix_micro_parametres->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox_choix_micro_parametres->setStyleSheet(QString::fromUtf8("background: rgb(33, 37, 41);\n"
"border-radius: 10px;"));
        frame_deco_friend_request = new QFrame(page_4);
        frame_deco_friend_request->setObjectName(QString::fromUtf8("frame_deco_friend_request"));
        frame_deco_friend_request->setGeometry(QRect(0, 0, 1920, 1080));
        frame_deco_friend_request->setStyleSheet(QString::fromUtf8("background: rgba( 33, 37, 41, 95% );"));
        frame_deco_friend_request->setFrameShape(QFrame::StyledPanel);
        frame_deco_friend_request->setFrameShadow(QFrame::Raised);
        frame_deco_interieur_friend_request = new QFrame(frame_deco_friend_request);
        frame_deco_interieur_friend_request->setObjectName(QString::fromUtf8("frame_deco_interieur_friend_request"));
        frame_deco_interieur_friend_request->setGeometry(QRect(447, 440, 1006, 200));
        frame_deco_interieur_friend_request->setStyleSheet(QString::fromUtf8("background: rgba( 52, 58, 64, 100% );\n"
"border-radius: 100px;"));
        frame_deco_interieur_friend_request->setFrameShape(QFrame::StyledPanel);
        frame_deco_interieur_friend_request->setFrameShadow(QFrame::Raised);
        label_titre_invitation = new QLabel(frame_deco_interieur_friend_request);
        label_titre_invitation->setObjectName(QString::fromUtf8("label_titre_invitation"));
        label_titre_invitation->setGeometry(QRect(332, 30, 341, 41));
        label_titre_invitation->setFont(font3);
        label_titre_invitation->setStyleSheet(QString::fromUtf8("color: white;"));
        label_name_friend_request = new QLabel(frame_deco_interieur_friend_request);
        label_name_friend_request->setObjectName(QString::fromUtf8("label_name_friend_request"));
        label_name_friend_request->setGeometry(QRect(320, 110, 361, 41));
        QFont font8;
        font8.setPointSize(14);
        label_name_friend_request->setFont(font8);
        label_name_friend_request->setLayoutDirection(Qt::LeftToRight);
        label_name_friend_request->setStyleSheet(QString::fromUtf8("color: white;"));
        label_name_friend_request->setFrameShape(QFrame::NoFrame);
        label_name_friend_request->setTextFormat(Qt::PlainText);
        label_name_friend_request->setAlignment(Qt::AlignCenter);
        btn_accept_friend_request = new QPushButton(frame_deco_interieur_friend_request);
        btn_accept_friend_request->setObjectName(QString::fromUtf8("btn_accept_friend_request"));
        btn_accept_friend_request->setGeometry(QRect(50, 110, 230, 40));
        btn_accept_friend_request->setFont(font1);
        btn_accept_friend_request->setCursor(QCursor(Qt::PointingHandCursor));
        btn_accept_friend_request->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background:  green;\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        btn_decline_friend_request = new QPushButton(frame_deco_interieur_friend_request);
        btn_decline_friend_request->setObjectName(QString::fromUtf8("btn_decline_friend_request"));
        btn_decline_friend_request->setGeometry(QRect(730, 110, 230, 40));
        btn_decline_friend_request->setFont(font1);
        btn_decline_friend_request->setCursor(QCursor(Qt::PointingHandCursor));
        btn_decline_friend_request->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background:  red;\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        frame_deco_appel = new QFrame(page_4);
        frame_deco_appel->setObjectName(QString::fromUtf8("frame_deco_appel"));
        frame_deco_appel->setGeometry(QRect(-1, 0, 1921, 1081));
        frame_deco_appel->setStyleSheet(QString::fromUtf8("background: rgba( 33, 37, 41, 95% );"));
        frame_deco_appel->setFrameShape(QFrame::StyledPanel);
        frame_deco_appel->setFrameShadow(QFrame::Raised);
        frame_deco_interieur_appel = new QFrame(frame_deco_appel);
        frame_deco_interieur_appel->setObjectName(QString::fromUtf8("frame_deco_interieur_appel"));
        frame_deco_interieur_appel->setGeometry(QRect(447, 440, 1006, 200));
        frame_deco_interieur_appel->setStyleSheet(QString::fromUtf8("background: rgba( 52, 58, 64, 100% );\n"
"border-radius: 100px;"));
        frame_deco_interieur_appel->setFrameShape(QFrame::StyledPanel);
        frame_deco_interieur_appel->setFrameShadow(QFrame::Raised);
        label_title_notif_appel = new QLineEdit(frame_deco_interieur_appel);
        label_title_notif_appel->setObjectName(QString::fromUtf8("label_title_notif_appel"));
        label_title_notif_appel->setGeometry(QRect(360, 20, 291, 61));
        label_title_notif_appel->setFont(font3);
        label_title_notif_appel->setStyleSheet(QString::fromUtf8("color: white;"));
        btn_notif_appel_accepter = new QPushButton(frame_deco_interieur_appel);
        btn_notif_appel_accepter->setObjectName(QString::fromUtf8("btn_notif_appel_accepter"));
        btn_notif_appel_accepter->setGeometry(QRect(50, 110, 230, 40));
        btn_notif_appel_accepter->setFont(font1);
        btn_notif_appel_accepter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background:  green;\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        btn_notif_appel_refuser = new QPushButton(frame_deco_interieur_appel);
        btn_notif_appel_refuser->setObjectName(QString::fromUtf8("btn_notif_appel_refuser"));
        btn_notif_appel_refuser->setGeometry(QRect(730, 110, 230, 40));
        btn_notif_appel_refuser->setFont(font1);
        btn_notif_appel_refuser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background:  red;\n"
"	color: white;\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}"));
        label_notif_appel_nom = new QLabel(frame_deco_interieur_appel);
        label_notif_appel_nom->setObjectName(QString::fromUtf8("label_notif_appel_nom"));
        label_notif_appel_nom->setGeometry(QRect(320, 110, 361, 41));
        label_notif_appel_nom->setFont(font8);
        label_notif_appel_nom->setStyleSheet(QString::fromUtf8("color: white;"));
        label_notif_appel_nom->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(input_adresse_mail_connexion, input_mot_de_passe_connexion);
        QWidget::setTabOrder(input_mot_de_passe_connexion, btn_mot_de_passe_oublie_connexion);
        QWidget::setTabOrder(btn_mot_de_passe_oublie_connexion, btn_se_connecter_connexion);
        QWidget::setTabOrder(btn_se_connecter_connexion, btn_aller_a_inscription_connexion);
        QWidget::setTabOrder(btn_aller_a_inscription_connexion, input_nom_d_utilisateur_inscription);
        QWidget::setTabOrder(input_nom_d_utilisateur_inscription, input_adresse_mail_inscription);
        QWidget::setTabOrder(input_adresse_mail_inscription, input_mot_de_passe_1_inscription);
        QWidget::setTabOrder(input_mot_de_passe_1_inscription, input_mot_de_passe_2_inscription);
        QWidget::setTabOrder(input_mot_de_passe_2_inscription, btn_s_inscrire_inscription);
        QWidget::setTabOrder(btn_s_inscrire_inscription, btn_aller_a_connexion_inscription);
        QWidget::setTabOrder(btn_aller_a_connexion_inscription, btn_retourner_page_connexion);
        QWidget::setTabOrder(btn_retourner_page_connexion, nv_message);
        QWidget::setTabOrder(nv_message, btn_envoyer_mess);
        QWidget::setTabOrder(btn_envoyer_mess, input_search_contact);
        QWidget::setTabOrder(input_search_contact, btn_ajouter_contacts);
        QWidget::setTabOrder(btn_ajouter_contacts, btn_appel);
        QWidget::setTabOrder(btn_appel, btn_parametres);
        QWidget::setTabOrder(btn_parametres, btn_deconnect);
        QWidget::setTabOrder(btn_deconnect, icon_user);
        QWidget::setTabOrder(icon_user, scrollArea_contacts);
        QWidget::setTabOrder(scrollArea_contacts, message_box);
        QWidget::setTabOrder(message_box, btn_end_call);
        QWidget::setTabOrder(btn_end_call, icon_contact_select);
        QWidget::setTabOrder(icon_contact_select, btn_sound_mute);
        QWidget::setTabOrder(btn_sound_mute, btn_micro_mute);
        QWidget::setTabOrder(btn_micro_mute, caller_1);
        QWidget::setTabOrder(caller_1, caller_2);
        QWidget::setTabOrder(caller_2, btn_quitter_recherche_contact);
        QWidget::setTabOrder(btn_quitter_recherche_contact, input_rechercher_contact);
        QWidget::setTabOrder(input_rechercher_contact, btn_search_new_contact);
        QWidget::setTabOrder(btn_search_new_contact, btn_quitter_parametres);
        QWidget::setTabOrder(btn_quitter_parametres, comboBox_choix_micro_parametres);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_adresse_mail_connexion->setText(QCoreApplication::translate("MainWindow", "Adresse mail:", nullptr));
        label_mot_de_passe_connexion->setText(QCoreApplication::translate("MainWindow", "Mot de passe:", nullptr));
        btn_mot_de_passe_oublie_connexion->setText(QCoreApplication::translate("MainWindow", "Mot de passe oubli\303\251 ?", nullptr));
        erreur_connexion->setText(QCoreApplication::translate("MainWindow", "Adresse mail ou mot de passe incrorrect !", nullptr));
        label_titre_connexion->setText(QCoreApplication::translate("MainWindow", "CONNEXION", nullptr));
        input_adresse_mail_connexion->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre adresse mail ...", nullptr));
        input_mot_de_passe_connexion->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre mot de passe ...", nullptr));
#if QT_CONFIG(tooltip)
        btn_se_connecter_connexion->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btn_se_connecter_connexion->setText(QCoreApplication::translate("MainWindow", "  Se connecter", nullptr));
        btn_aller_a_inscription_connexion->setText(QCoreApplication::translate("MainWindow", "  S'inscrire", nullptr));
        label_adresse_mail_inscription->setText(QCoreApplication::translate("MainWindow", "Adresse mail:", nullptr));
        label_mot_de_passe_1_inscription->setText(QCoreApplication::translate("MainWindow", "Mot de passe:", nullptr));
        label_nom_d_utilisateur_inscription->setText(QCoreApplication::translate("MainWindow", "Nom d'utilisateur:", nullptr));
        label_mot_de_passe_2_inscription->setText(QCoreApplication::translate("MainWindow", "Confirmation du mot de passe:", nullptr));
        erreur_inscription->setText(QCoreApplication::translate("MainWindow", "Nom d'utilisateur ou mail d\303\251j\303\240 utilis\303\251 !", nullptr));
        label_title_inscription->setText(QCoreApplication::translate("MainWindow", "INSCRIPTION", nullptr));
        btn_s_inscrire_inscription->setText(QCoreApplication::translate("MainWindow", "  S'inscrire", nullptr));
        input_mot_de_passe_1_inscription->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre mot de passe ...", nullptr));
        input_adresse_mail_inscription->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre adresse mail ...", nullptr));
        btn_aller_a_connexion_inscription->setText(QCoreApplication::translate("MainWindow", " Se connecter", nullptr));
        input_nom_d_utilisateur_inscription->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre nom d'utilisateur ...", nullptr));
        input_mot_de_passe_2_inscription->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre mot de passe ...", nullptr));
        label_tmp->setText(QCoreApplication::translate("MainWindow", "PAGE mot de passe oublie", nullptr));
        btn_retourner_page_connexion->setText(QCoreApplication::translate("MainWindow", "Retourner \303\240 connexion", nullptr));
        input_search_contact->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher ...", nullptr));
        label_mes_contacts->setText(QCoreApplication::translate("MainWindow", "MES CONTACTS", nullptr));
        btn_ajouter_contacts->setText(QString());
        label_notif->setText(QCoreApplication::translate("MainWindow", "Nouveau message de ", nullptr));
        btn_close_notif->setText(QString());
        label_notif_nom->setText(QCoreApplication::translate("MainWindow", "Pierre Jeannin", nullptr));
        label_nom_contact_select->setText(QString());
        btn_appel->setText(QString());
        btn_parametres->setText(QString());
        label_user->setText(QString());
        btn_deconnect->setText(QString());
        icon_contact_select->setText(QString());
        icon_user->setText(QString());
        nv_message->setMarkdown(QString());
        nv_message->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        btn_envoyer_mess->setText(QString());
        btn_end_call->setText(QString());
        btn_sound_mute->setText(QString());
        btn_micro_mute->setText(QString());
        caller_1->setText(QString());
        caller_2->setText(QString());
        btn_quitter_recherche_contact->setText(QString());
        input_rechercher_contact->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher des nouveaux contacts ...", nullptr));
        label_titre_ajouter_contact->setText(QCoreApplication::translate("MainWindow", "AJOUTER CONTACT", nullptr));
        btn_search_new_contact->setText(QString());
        label_msg_add_contact->setText(QCoreApplication::translate("MainWindow", "blanc", nullptr));
        btn_quitter_parametres->setText(QString());
        label_titre_parametres->setText(QCoreApplication::translate("MainWindow", "PARAMETRES", nullptr));
        label_microphone_parametres->setText(QCoreApplication::translate("MainWindow", "Microphone:", nullptr));
        label_titre_invitation->setText(QCoreApplication::translate("MainWindow", "Invitation re\303\247ue", nullptr));
        label_name_friend_request->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        btn_accept_friend_request->setText(QCoreApplication::translate("MainWindow", "ACCEPTER", nullptr));
        btn_decline_friend_request->setText(QCoreApplication::translate("MainWindow", "REFUSER", nullptr));
        label_title_notif_appel->setText(QCoreApplication::translate("MainWindow", "Appel entrant", nullptr));
        btn_notif_appel_accepter->setText(QCoreApplication::translate("MainWindow", "ACCEPTER", nullptr));
        btn_notif_appel_refuser->setText(QCoreApplication::translate("MainWindow", "REFUSER", nullptr));
        label_notif_appel_nom->setText(QCoreApplication::translate("MainWindow", "Pierre Jeannin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
