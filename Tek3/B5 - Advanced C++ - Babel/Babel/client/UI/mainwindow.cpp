#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

// QT functions
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), path(QDir().absolutePath())
{
    ui->setupUi(this);

    basic_init();
    client = new Babel::Client::Client(ui, this);
    setWindowTitle("Babel");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// my functions
QFont &use_font(int size)
{
    QFont *font = new QFont("HelveticaNeue", size, QFont::Normal);

    return (*font);
}

bool MainWindow::regex_check(QString exp, QString txt, QString errormsg)
{
    QRegularExpression reg(exp);
    if (!reg.match(txt).hasMatch()) {
        QMessageBox::information(this, "Erreur", errormsg);
        return false;
    }
    return true;
}

void MainWindow::re_set_selected_contact()
{
    bool found = false;
    for (unsigned int i = 0; (i != contacts.size() && (ui->input_search_contact->text() == "" && contacts_search_disp == 0)) || (contacts_search_disp != 0 && i < (unsigned int)contacts_search_disp); i++) {
        contacts_buttons.at(i)->setStyleSheet(style_contact);
        if (contacts_buttons.at(i)->text().remove(0, 2) == selected_contact && !found) {
            found = true;
            contacts_buttons.at(i)->setStyleSheet(style_contact_selected);
        }
        if (std::find(contacts_icons.begin(), contacts_icons.end(), contacts_buttons.at(i)->text().remove(0, 2).toStdString()) != contacts_icons.end()) {
            std::string tmp = path.toStdString() + "/client/UI/assets/contact-images/" + contacts_buttons.at(i)->text().remove(0, 2).toStdString() + ".jpg";
            contacts_buttons.at(i)->setIcon(QIcon(QString::fromStdString(tmp)));
        } else
            contacts_buttons.at(i)->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    }
}

void MainWindow::set_selected_contact()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text().remove(0, 2);

    ui->nv_message->show();
    ui->btn_envoyer_mess->show();
    ui->btn_appel->show();
    ui->icon_contact_select->show();
    client->sendAskMessagesHistory(buttonText.toStdString());
    selected_contact = buttonText;
    ui->label_nom_contact_select->setText(buttonText);
    ui->icon_contact_select->setIcon(buttonSender->icon());
    for (unsigned int i = 0; (i < contacts.size() && (ui->input_search_contact->text() == "" && contacts_search_disp == 0)) || (contacts_search_disp != 0 && i < (unsigned int)contacts_search_disp); ++i) {
        contacts_buttons.at(i)->setStyleSheet(style_contact);
        if (std::find(contacts_icons.begin(), contacts_icons.end(), contacts.at(i)) != contacts_icons.end()) {
            std::string tmp = path.toStdString() + "/client/UI/assets/contact-images/" + contacts.at(i) + ".jpg";
            contacts_buttons.at(i)->setIcon(QIcon(QString::fromStdString(tmp)));
        } else
            contacts_buttons.at(i)->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    }
    buttonSender->setStyleSheet(style_contact_selected);
    if (std::find(contacts_icons.begin(), contacts_icons.end(), buttonText.toStdString()) != contacts_icons.end()) {
        std::string tmp = path.toStdString() + "/client/UI/assets/contact-images/" + buttonText.toStdString() + ".jpg";
        buttonSender->setIcon(QIcon(QString::fromStdString(tmp)));
    } else
        buttonSender->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    ui->nv_message->setPlaceholderText("Envoyer un message à " + buttonText + " ...");
    re_set_selected_contact();
}

void MainWindow::set_messages_lay()
{
    for (unsigned int i = 0; i != messages.size(); i++) {
        QLabel* tmp_label = new QLabel(QString::fromStdString(messages.at(i)), this);
        if (messages_p.at(i) == "m")
            tmp_label->setStyleSheet(style_message_m);
        else
            tmp_label->setStyleSheet(style_message_a);
        tmp_label->setFont(use_font(20));
        tmp_label->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
        tmp_label->setWordWrap(true);
        messages_lay->setAlignment(Qt::AlignTop);
        messages_lay->addWidget(tmp_label);
    }
    ui->scrollAreaWidgetContents->setLayout(messages_lay);
}

void MainWindow::set_contacts_lay()
{
    //contacts_lay->
    std::sort(contacts.begin(), contacts.end());
    for (unsigned int i = 0; i != contacts.size(); i++) {
        QPushButton* tmp_button = new QPushButton("  " + QString::fromStdString(contacts.at(i)), this);
        tmp_button->setStyleSheet(style_contact);
        tmp_button->setFont(use_font(20));
        if (std::find(contacts_icons.begin(), contacts_icons.end(), contacts.at(i)) != contacts_icons.end()) {
            std::string tmp = path.toStdString() + "/client/UI/assets/contact-images/" + contacts.at(i) + ".jpg";
            tmp_button->setIcon(QIcon(QString::fromStdString(tmp)));
        } else
            tmp_button->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
        tmp_button->setObjectName("pushButton_contact_" + QString::fromStdString(std::to_string(i)));
        connect(tmp_button, SIGNAL(clicked()), this, SLOT(set_selected_contact()));
        tmp_button->setCursor(Qt::PointingHandCursor);
        contacts_buttons.push_back(tmp_button);
        contacts_lay->setAlignment(Qt::AlignTop);
        contacts_lay->addWidget(contacts_buttons.back());
    }
    ui->scrollContents_contacts->setLayout(contacts_lay);
}

void MainWindow::basic_init()
{
    ui->frame_deco_recherche_contacts->hide();

    ui->frame_deco_parametres->hide();

    ui->call_box->hide();

    ui->stackedWidget->setCurrentIndex(0);

    ui->label_titre_connexion->setFont(use_font(36));
    ui->label_adresse_mail_connexion->setFont(use_font(20));
    ui->input_adresse_mail_connexion->setFont(use_font(18));
    ui->label_mot_de_passe_connexion->setFont(use_font(20));
    ui->input_mot_de_passe_connexion->setFont(use_font(18));
    ui->btn_mot_de_passe_oublie_connexion->setFont(use_font(16));
    ui->btn_se_connecter_connexion->setFont(use_font(28));
    ui->btn_aller_a_inscription_connexion->setFont(use_font(28));
    ui->label_title_inscription->setFont(use_font(36));
    ui->label_nom_d_utilisateur_inscription->setFont(use_font(20));
    ui->input_nom_d_utilisateur_inscription->setFont(use_font(18));
    ui->label_adresse_mail_inscription->setFont(use_font(20));
    ui->input_adresse_mail_inscription->setFont(use_font(18));
    ui->label_mot_de_passe_1_inscription->setFont(use_font(20));
    ui->input_mot_de_passe_1_inscription->setFont(use_font(18));
    ui->label_mot_de_passe_2_inscription->setFont(use_font(20));
    ui->input_mot_de_passe_2_inscription->setFont(use_font(18));
    ui->btn_s_inscrire_inscription->setFont(use_font(28));
    ui->btn_aller_a_connexion_inscription->setFont(use_font(28));
    ui->btn_envoyer_mess->setFont(use_font(34));
    ui->input_search_contact->setFont(use_font(18));
    ui->label_mes_contacts->setFont(use_font(22));
    ui->label_nom_contact_select->setFont(use_font(22));
    ui->label_user->setFont(use_font(22));
    ui->label_microphone_parametres->setFont(use_font(22));
    ui->label_titre_parametres->setFont(use_font(36));
    ui->input_rechercher_contact->setFont(use_font(18));
    ui->label_titre_ajouter_contact->setFont(use_font(36));
    ui->nv_message->setFont(use_font(18));
    ui->label_titre_invitation->setFont(use_font(36));
    ui->label_name_friend_request->setFont(use_font(14));
    ui->btn_accept_friend_request->setFont(use_font(16));
    ui->btn_decline_friend_request->setFont(use_font(16));
    ui->label_msg_add_contact->setFont(use_font(12));
    ui->label_notif_nom->setFont(use_font(16));
    ui->label_notif->setFont(use_font(16));
    ui->btn_notif_appel_accepter->setFont(use_font(16));
    ui->btn_notif_appel_refuser->setFont(use_font(16));
    ui->label_notif_appel_nom->setFont(use_font(14));
    ui->label_title_notif_appel->setFont(use_font(36));

    ui->btn_se_connecter_connexion->setIcon(QIcon(path + "/client/UI/assets/icons/connection.png"));
    ui->btn_search_new_contact->setIcon(QIcon(path + "/client/UI/assets/icons/plus.png"));
    ui->btn_aller_a_inscription_connexion->setIcon(QIcon(path + "/client/UI/assets/icons/enregistrer.png"));
    ui->btn_sound_mute->setIcon(QIcon(path + "/client/UI/assets/icons/casque.png"));
    ui->btn_quitter_recherche_contact->setIcon(QIcon(path + "/client/UI/assets/icons/croix.png"));
    ui->btn_quitter_parametres->setIcon(QIcon(path + "/client/UI/assets/icons/croix.png"));
    ui->btn_end_call->setIcon(QIcon(path + "/client/UI/assets/icons/croix.png"));
    ui->btn_micro_mute->setIcon(QIcon(path + "/client/UI/assets/icons/micro.png"));
    ui->btn_aller_a_connexion_inscription->setIcon(QIcon(path + "/client/UI/assets/icons/connection.png"));
    ui->btn_s_inscrire_inscription->setIcon(QIcon(path + "/client/UI/assets/icons/enregistrer.png"));
    ui->btn_appel->setIcon(QIcon(path + "/client/UI/assets/icons/appel.png"));
    ui->btn_ajouter_contacts->setIcon(QIcon(path + "/client/UI/assets/icons/ajouter_contact.png"));
    ui->btn_parametres->setIcon(QIcon(path + "/client/UI/assets/icons/parametres.png"));
    ui->btn_envoyer_mess->setIcon(QIcon(path + "/client/UI/assets/icons/envoyer.png"));
    ui->btn_deconnect->setIcon(QIcon(path + "/client/UI/assets/icons/deconnecter.png"));
    ui->icon_contact_select->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    ui->icon_user->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    ui->caller_1->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    ui->caller_2->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
    ui->btn_close_notif->setIcon(QIcon(path + "/client/UI/assets/icons/croix.png"));
    ui->frame_notif->hide();
    ui->frame_deco_friend_request->hide();
    ui->erreur_connexion->hide();
    ui->erreur_inscription->hide();
    ui->label_msg_add_contact->hide();
    ui->frame_deco_appel->hide();
    ui->nv_message->hide();
    ui->btn_envoyer_mess->hide();
    ui->btn_appel->hide();
    ui->icon_contact_select->hide();

    contacts_lay = new QVBoxLayout(this);

    messages_lay = new QVBoxLayout(this);

    set_contacts_lay();

    set_messages_lay();

    //contacts_buttons.at(0)->click();
}

void MainWindow::addMessageToCurrentList(std::string nv_message, std::string sender)
{
    QLayoutItem* item;

    int j = 0;
    for (unsigned int i = 0; i != nv_message.length(); i++) {
        if (j == 49) {
            nv_message.insert(i, "\n");
            j = 0;
        }
        j++;
    }

    while ((item = messages_lay->layout()->takeAt(0)) != 0)
        delete item->widget();

    messages.push_back(nv_message);
    messages_p.push_back(sender);

    for (unsigned int i = 0; i != messages.size(); i++) {
        QLabel* tmp_label = new QLabel(QString::fromStdString(messages.at(i)), this);
        tmp_label->setFont(use_font(20));
        if (messages_p.at(i) == "m") {
            tmp_label->setStyleSheet(style_message_m);
        } else {
            tmp_label->setStyleSheet(style_message_a);
        }
        tmp_label->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
        tmp_label->setWordWrap(true);
        messages_lay->setAlignment(Qt::AlignTop);
        messages_lay->addWidget(tmp_label);
    }
    ui->scrollAreaWidgetContents->setLayout(messages_lay);
}

// buttons functions
void MainWindow::on_btn_envoyer_mess_clicked()
{
    // PIERRE
    std::string sender = ui->label_user->text().toStdString();
    std::string receiver = ui->label_nom_contact_select->text().toStdString();
    std::string nv_message = ui->nv_message->toPlainText().toStdString();

    client->sendMessage(receiver, nv_message);

    addMessageToCurrentList(nv_message, "m");
    ui->nv_message->setText("");
}

void MainWindow::on_btn_ajouter_contacts_clicked()
{
    ui->frame_deco_recherche_contacts->show();
//    if (contacts_disp < contacts.size())
//        contacts_disp++;

//    QLayoutItem* item;
//    while ((item = contacts_lay->layout()->takeAt(0)) != 0)
//        delete item->widget();

//    contacts_buttons.clear();
//    for (int i = 0; i != contacts_disp; i++) {
//        std::string c = contacts.at(i);
//        std::string s = ui->input_search_contact->text().toStdString();
//        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
//        std::transform(c.begin(), c.end(), c.begin(), ::tolower);
//        if (c.rfind(s, 0) == 0) {
//            QPushButton* tmp_button = new QPushButton("  " + QString::fromStdString(contacts.at(i)), this);
//            tmp_button->setStyleSheet(style_contact);
//            tmp_button->setObjectName("pushButton_contact_" + QString::fromStdString(std::to_string(i)));
//            tmp_button->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
//            connect(tmp_button, SIGNAL(clicked()), this, SLOT(set_selected_contact()));
//            tmp_button->setCursor(Qt::PointingHandCursor);
//            contacts_buttons.push_back(tmp_button);
//            contacts_lay->addWidget(tmp_button);
//        }
//    }
//    re_set_selected_contact();
}

void MainWindow::on_btn_retourner_page_connexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_se_connecter_connexion_clicked()
{
    // PIERRE
    std::string mail = ui->input_adresse_mail_connexion->text().toStdString();
    std::string password = ui->input_mot_de_passe_connexion->text().toStdString();


    client->sendConnection(mail, password);

    //ui->label_user->setText(user);
    //ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btn_aller_a_inscription_connexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btn_quitter_parametres_clicked()
{
    ui->frame_deco_parametres->hide();
}

void MainWindow::on_btn_quitter_recherche_contact_clicked()
{
    ui->frame_deco_recherche_contacts->hide();
    ui->input_rechercher_contact->setText("");
}

void MainWindow::on_btn_mot_de_passe_oublie_connexion_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btn_s_inscrire_inscription_clicked()
{
    // PIERRE
    std::string username = ui->input_nom_d_utilisateur_inscription->text().toStdString();
    std::string mail = ui->input_adresse_mail_inscription->text().toStdString();
    std::string password1 = ui->input_mot_de_passe_1_inscription->text().toStdString();
    std::string password2 = ui->input_mot_de_passe_2_inscription->text().toStdString();

    client->sendSubscribe(mail, username, password1);
}

void MainWindow::on_btn_aller_a_connexion_inscription_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_deconnect_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_appel_clicked()
{
    // PIERRE
    std::string sender = ui->label_user->text().toStdString();
    std::string receiver = ui->label_nom_contact_select->text().toStdString();

    client->sendCall(receiver);

    /*ui->message_box->setGeometry(0, 200, 1471, 621);
    ui->icon_contact_select->setGeometry(40, 20, 51, 51);
    ui->label_nom_contact_select->setGeometry(100, 20, 250, 51);
    ui->call_box->show();
    ui->btn_appel->hide();
    ui->caller_2->setIcon(ui->icon_contact_select->icon());*/
}

void MainWindow::on_btn_parametres_clicked()
{
    ui->frame_deco_parametres->show();
}

void MainWindow::on_btn_end_call_clicked()
{
    ui->message_box->setGeometry(0, 0, 1471, 821);
    ui->icon_contact_select->setGeometry(100, 20, 51, 51);
    ui->label_nom_contact_select->setGeometry(160, 20, 250, 51);
    ui->call_box->hide();
    ui->btn_appel->show();
    ui->btn_micro_mute->setIcon(QIcon(path + "/client/UI/assets/icons/micro.png"));
    micro_mute = false;
    ui->btn_sound_mute->setIcon(QIcon(path + "/client/UI/assets/icons/casque.png"));
    sound_mute = false;
    client->sendEndCall();
}

void MainWindow::on_btn_micro_mute_clicked()
{
    if (micro_mute) {
        ui->btn_micro_mute->setIcon(QIcon(path + "/client/UI/assets/icons/micro.png"));
        micro_mute = false;
    } else {
        ui->btn_micro_mute->setIcon(QIcon(path + "/client/UI/assets/icons/micro_coupe.png"));
        micro_mute = true;
    }
}

void MainWindow::on_btn_sound_mute_clicked()
{
    if (sound_mute) {
        ui->btn_sound_mute->setIcon(QIcon(path + "/client/UI/assets/icons/casque.png"));
        sound_mute = false;
    } else {
        ui->btn_sound_mute->setIcon(QIcon(path + "/client/UI/assets/icons/casque_coupe.png"));
        sound_mute = true;
    }
}

void MainWindow::on_btn_search_new_contact_clicked()
{
    std::string pseudo = ui->input_rechercher_contact->text().toStdString();

    client->sendFriendRequest(pseudo);
}

void MainWindow::on_btn_accept_friend_request_clicked()
{
    ui->frame_deco_friend_request->hide();
    client->sendAcceptFriendRequest(ui->label_name_friend_request->text().toStdString());
}

void MainWindow::on_btn_decline_friend_request_clicked()
{
    ui->frame_deco_friend_request->hide();
    client->sendRefuseFriendRequest(ui->label_name_friend_request->text().toStdString());
}

void MainWindow::on_btn_close_notif_clicked()
{
    ui->frame_notif->hide();
}

void MainWindow::on_btn_notif_appel_accepter_clicked()
{
    client->sendAcceptCall(ui->label_notif_appel_nom->text().toStdString());
    ui->message_box->setGeometry(0, 200, 1471, 621);
    ui->icon_contact_select->setGeometry(40, 20, 51, 51);
    ui->label_nom_contact_select->setGeometry(100, 20, 250, 51);
    ui->call_box->show();
    ui->btn_appel->hide();
    ui->frame_deco_appel->hide();
}

void MainWindow::on_btn_notif_appel_refuser_clicked()
{
    client->sendRefuseCall(ui->label_notif_appel_nom->text().toStdString());
    ui->frame_deco_appel->hide();
}

// inputs functions
void MainWindow::on_input_search_contact_textChanged(const QString &arg1)
{
    QLayoutItem* item;
    while ((item = contacts_lay->layout()->takeAt(0)) != 0)
        delete item->widget();

    if (ui->input_search_contact->text() != "")
        ui->input_search_contact->setStyleSheet(style_input_input);
    else
        ui->input_search_contact->setStyleSheet(style_input_placeholder);
    contacts_search_disp = 0;
    contacts_buttons.clear();
    for (unsigned int i = 0; i != contacts.size(); i++) {
        std::string c = contacts.at(i);
        std::string s = ui->input_search_contact->text().toStdString();
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::transform(c.begin(), c.end(), c.begin(), ::tolower);
        if (c.find(s) != std::string::npos) {
            contacts_search_disp++;
            QPushButton* tmp_button = new QPushButton("  " + QString::fromStdString(contacts.at(i)), this);
            tmp_button->setFont(use_font(20));
            tmp_button->setStyleSheet(style_contact);
            tmp_button->setObjectName("pushButton_contact_" + QString::fromStdString(std::to_string(i)));
            tmp_button->setIcon(QIcon(path + "/client/UI/assets/contact-images/undefined.jpg"));
            connect(tmp_button, SIGNAL(clicked()), this, SLOT(set_selected_contact()));
            tmp_button->setCursor(Qt::PointingHandCursor);
            contacts_buttons.push_back(tmp_button);
            contacts_lay->addWidget(tmp_button);
        }
    }
    if (ui->input_search_contact->text() == "")
        contacts_search_disp = 0;
    re_set_selected_contact();
}

void MainWindow::on_input_nom_d_utilisateur_inscription_textChanged(const QString &arg1)
{
    if (ui->input_nom_d_utilisateur_inscription->text() != "")
        ui->input_nom_d_utilisateur_inscription->setStyleSheet(style_input_input);
    else
        ui->input_nom_d_utilisateur_inscription->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_adresse_mail_inscription_textChanged(const QString &arg1)
{
    QString txt = ui->input_adresse_mail_inscription->text();

    cursorplace = ui->input_adresse_mail_inscription->cursorPosition();
    ui->input_adresse_mail_inscription->setText(txt.toLower());
    if (ui->input_adresse_mail_inscription->text() != "")
        ui->input_adresse_mail_inscription->setStyleSheet(style_input_input);
    else
        ui->input_adresse_mail_inscription->setStyleSheet(style_input_placeholder);
    ui->input_adresse_mail_inscription->setCursorPosition(cursorplace);
}

void MainWindow::on_input_mot_de_passe_1_inscription_textChanged(const QString &arg1)
{
    if (ui->input_mot_de_passe_1_inscription->text() != "")
        ui->input_mot_de_passe_1_inscription->setStyleSheet(style_input_input);
    else
        ui->input_mot_de_passe_1_inscription->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_mot_de_passe_2_inscription_textChanged(const QString &arg1)
{
    if (ui->input_mot_de_passe_2_inscription->text() != "")
        ui->input_mot_de_passe_2_inscription->setStyleSheet(style_input_input);
    else
        ui->input_mot_de_passe_2_inscription->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_adresse_mail_connexion_textChanged(const QString &arg1)
{
    QString txt = ui->input_adresse_mail_connexion->text();

    cursorplace = ui->input_adresse_mail_connexion->cursorPosition();
    ui->input_adresse_mail_connexion->setText(txt.toLower());
    if (ui->input_adresse_mail_connexion->text() != "")
        ui->input_adresse_mail_connexion->setStyleSheet(style_input_input);
    else
        ui->input_adresse_mail_connexion->setStyleSheet(style_input_placeholder);
    ui->input_adresse_mail_connexion->setCursorPosition(cursorplace);
}

void MainWindow::on_input_mot_de_passe_connexion_textChanged(const QString &arg1)
{
    if (ui->input_mot_de_passe_connexion->text() != "")
        ui->input_mot_de_passe_connexion->setStyleSheet(style_input_input);
    else
        ui->input_mot_de_passe_connexion->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_nv_message_textChanged()
{
    if (ui->nv_message->toPlainText() != "")
        ui->nv_message->setStyleSheet(style_nv_message_input);
    else
        ui->nv_message->setStyleSheet(style_nv_message_placeholder);

    if (ui->nv_message->toPlainText().length() > 512) {
        int diff = ui->nv_message->toPlainText().length() - 512;
        QString newStr = ui->nv_message->toPlainText();
        newStr.chop(diff);
        ui->nv_message->setText(newStr);
        QTextCursor cursor(ui->nv_message->textCursor());
        cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->nv_message->setTextCursor(cursor);
    }
}

void MainWindow::on_input_rechercher_contact_textChanged(const QString &arg1)
{
    if (ui->input_rechercher_contact->text() != "")
        ui->input_rechercher_contact->setStyleSheet(style_input_input);
    else
        ui->input_rechercher_contact->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_adresse_mail_connexion_editingFinished()
{
    QString errormsg = "L'e-mail que vous avez entrée est incorrecte !";
    QString expr = "^(?=.{1,64}@)[a-z0-9_-]+(\\.[a-z0-9_-]+)*@[^-][a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,})$";

    if (ui->input_adresse_mail_connexion->text() == "")
        ui->input_adresse_mail_connexion->setStyleSheet(style_input_placeholder);
    else if (!regex_check(expr, ui->input_adresse_mail_connexion->text(), errormsg))
        ui->input_adresse_mail_connexion->setStyleSheet(style_input_incorrect);
    else
        ui->input_adresse_mail_connexion->setStyleSheet(style_input_correct);
}

void MainWindow::on_input_mot_de_passe_connexion_editingFinished()
{
    ui->input_mot_de_passe_connexion->setStyleSheet(style_input_correct);
    if (ui->input_mot_de_passe_connexion->text() == "")
        ui->input_mot_de_passe_connexion->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_adresse_mail_inscription_editingFinished()
{
    QString errormsg = "L'e-mail que vous avez entrée est incorrecte !";
    QString expr = "^(?=.{1,64}@)[a-z0-9_-]+(\\.[a-z0-9_-]+)*@[^-][a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,})$";

    if (ui->input_adresse_mail_inscription->text() == "")
        ui->input_adresse_mail_inscription->setStyleSheet(style_input_placeholder);
    else if (!regex_check(expr, ui->input_adresse_mail_inscription->text(), errormsg))
        ui->input_adresse_mail_inscription->setStyleSheet(style_input_incorrect);
    else
        ui->input_adresse_mail_inscription->setStyleSheet(style_input_correct);
}

void MainWindow::on_input_nom_d_utilisateur_inscription_editingFinished()
{
    ui->input_nom_d_utilisateur_inscription->setStyleSheet(style_input_correct);
    if (ui->input_nom_d_utilisateur_inscription->text() == "")
        ui->input_nom_d_utilisateur_inscription->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_mot_de_passe_1_inscription_editingFinished()
{
    ui->input_mot_de_passe_1_inscription->setStyleSheet(style_input_correct);
    if (ui->input_mot_de_passe_1_inscription->text() == "")
        ui->input_mot_de_passe_1_inscription->setStyleSheet(style_input_placeholder);
}

void MainWindow::on_input_mot_de_passe_2_inscription_editingFinished()
{
    if (ui->input_mot_de_passe_1_inscription->text() == ui->input_mot_de_passe_2_inscription->text())
        ui->input_mot_de_passe_2_inscription->setStyleSheet(style_input_correct);
    else
        ui->input_mot_de_passe_2_inscription->setStyleSheet(style_input_incorrect);
    if (ui->input_mot_de_passe_2_inscription->text() == "")
        ui->input_mot_de_passe_2_inscription->setStyleSheet(style_input_placeholder);
}

void clearLayout(QLayout *layout) {
    if (layout == nullptr)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void MainWindow::addContactToList(std::string &name)
{
    clearLayout(contacts_lay);
    contacts_buttons.clear();
    contacts.push_back(name);
    set_contacts_lay();
}

void MainWindow::clearMessagesList() {
    clearLayout(messages_lay);
    messages.clear();
    messages_p.clear();
}
