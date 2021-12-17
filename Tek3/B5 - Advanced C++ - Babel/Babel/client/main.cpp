/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** main.cpp
*/

#include <QApplication>
#include "UI/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return(0);
}