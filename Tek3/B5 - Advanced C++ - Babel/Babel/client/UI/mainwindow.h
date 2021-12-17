#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <iostream>
#include <QtCore>
#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <QGraphicsBlurEffect>
#include <QTextCursor>
#include <QSplitter>
#include <QFontDatabase>
#include "../Client.hpp"
#include "IMainWindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addContactToList(std::string &name) override;
    void addMessageToCurrentList(std::string nv_message, std::string sender) override;
    void clearMessagesList() override;

private slots:
    // buttons
    void on_btn_se_connecter_connexion_clicked();
    void on_btn_aller_a_inscription_connexion_clicked();
    void on_btn_mot_de_passe_oublie_connexion_clicked();
    void on_btn_quitter_parametres_clicked();
    void on_btn_s_inscrire_inscription_clicked();
    void on_btn_aller_a_connexion_inscription_clicked();
    void on_btn_deconnect_clicked();
    void on_btn_envoyer_mess_clicked();
    void on_btn_ajouter_contacts_clicked();
    void on_btn_appel_clicked();
    void on_btn_parametres_clicked();
    void on_btn_end_call_clicked();
    void on_btn_micro_mute_clicked();
    void on_btn_sound_mute_clicked();
    void on_btn_retourner_page_connexion_clicked();
    void on_btn_quitter_recherche_contact_clicked();
    void on_btn_search_new_contact_clicked();
    void on_btn_accept_friend_request_clicked();
    void on_btn_decline_friend_request_clicked();
    void on_btn_close_notif_clicked();
    void on_btn_notif_appel_accepter_clicked();
    void on_btn_notif_appel_refuser_clicked();

    // inputs
    void on_input_search_contact_textChanged(const QString &arg1);
    void on_input_nom_d_utilisateur_inscription_textChanged(const QString &arg1);
    void on_input_adresse_mail_inscription_textChanged(const QString &arg1);
    void on_input_mot_de_passe_1_inscription_textChanged(const QString &arg1);
    void on_input_mot_de_passe_2_inscription_textChanged(const QString &arg1);
    void on_input_adresse_mail_connexion_textChanged(const QString &arg1);
    void on_input_mot_de_passe_connexion_textChanged(const QString &arg1);
    void on_input_rechercher_contact_textChanged(const QString &arg1);
    void on_nv_message_textChanged();

    // my_functions
    void set_selected_contact();
    void re_set_selected_contact();
    void set_contacts_lay();
    void set_messages_lay();
    void basic_init();
    bool regex_check(QString, QString, QString);

    void on_input_adresse_mail_connexion_editingFinished();

    void on_input_adresse_mail_inscription_editingFinished();

    void on_input_nom_d_utilisateur_inscription_editingFinished();

    void on_input_mot_de_passe_1_inscription_editingFinished();

    void on_input_mot_de_passe_2_inscription_editingFinished();

    void on_input_mot_de_passe_connexion_editingFinished();

private:
    Ui::MainWindow *ui;

    // style
    QString style_contact = "QPushButton {background: rgb(73, 80, 87); border-radius: 15px; color: white; width: 278px; height: 60px; font-size: 28px; margin: 3px; text-align: left; padding-left: 25px; qproperty-iconSize: 50px;} QPushButton::hover {background: rgb(33, 37, 41);}";
    QString style_contact_selected = "QPushButton {background: rgb(33, 37, 41); border-radius: 15px; color: white; width: 278px; height: 60px; font-size: 28px; margin: 3px; text-align: left; padding-left: 25px; qproperty-iconSize: 50px;} QPushButton::hover {background: rgb(33, 37, 41);}";
    QString style_message_m = "QLabel {background: rgb(52, 58, 64); border-radius: 15px; padding-left: 20px; padding-right: 20px;padding-top: 5px; padding-bottom: 5px; color: white;margin: 3px; font-size: 28px; text-align: left; margin-left: 545px; margin-right: 65px;}";
    QString style_message_a = "QLabel {background: rgb(52, 58, 64); border-radius: 15px; padding-left: 20px; padding-right: 20px; padding-top: 5px; padding-bottom: 5px; color: white; margin: 3px; font-size: 28px; text-align: left; margin-left: 65px; margin-right: 545px;}";
    QString style_input_placeholder = "QLineEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 20px; color: rgb(73, 80, 87);}";
    QString style_input_input = "QLineEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 20px; color: white};";
    QString style_input_correct = "QLineEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 20px; color: white; border-width: 1px; border-style: solid; border-color: transparent transparent green transparent;}";
    QString style_input_incorrect = "QLineEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 20px; color: white; border-width: 1px; border-style: solid; border-color: transparent transparent red transparent;}";
    QString style_nv_message_placeholder = "QTextEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 100px; color: rgb(73, 80, 87);} QScrollArea {border: none;} QScrollBar::vertical {border: none; background: white; width:0px; margin: 0px 0px 0px 0px;} QScrollBar::handle:vertical {background: rgb(52, 58, 64); min-height: 0px;} QScrollBar::add-line:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130)); height: 0px; subcontrol-position: bottom; subcontrol-origin: margin;} QScrollBar::sub-line:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130)); height: 0 px; subcontrol-position: top; subcontrol-origin: margin;} QScrollBar::sub-page:vertical {background-color: rgb(52, 58, 64);} QScrollBar::add-page:vertical {background-color: rgb(52, 58, 64);}";
    QString style_nv_message_input = "QTextEdit {background: rgb(33, 37, 41); border-radius: 15px; padding-left: 20px; padding-right: 100px; color: white;} QScrollArea {border: none;} QScrollBar::vertical {border: none; background: white; width:0px; margin: 0px 0px 0px 0px;} QScrollBar::handle:vertical {background: rgb(52, 58, 64); min-height: 0px;} QScrollBar::add-line:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130)); height: 0px; subcontrol-position: bottom; subcontrol-origin: margin;} QScrollBar::sub-line:vertical {background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130),  stop:1 rgb(32, 47, 130)); height: 0 px; subcontrol-position: top; subcontrol-origin: margin;} QScrollBar::sub-page:vertical {background-color: rgb(52, 58, 64);} QScrollBar::add-page:vertical {background-color: rgb(52, 58, 64);}";

    // data

            // a relier a la DB
            std::vector<std::string> contacts = { };
            std::vector<std::string> contacts_icons = { };
            std::vector<std::string> messages = { };
            std::vector<std::string> messages_p = { };

    std::vector<QPushButton *> contacts_buttons;
    QString selected_contact;
    QString user = "Monsieur XXXX";
    int contacts_disp = 8;
    int contacts_search_disp = 0;
    bool micro_mute = false;
    bool sound_mute = false;
    int cursorplace;

    // layers
    QVBoxLayout *contacts_lay;
    QVBoxLayout *messages_lay;

    Babel::Client::Client *client;

    QString path;
};
#endif // MAINWINDOW_H
