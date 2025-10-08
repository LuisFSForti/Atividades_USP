//Luís Filipe Silva Forti - 14592348
//Luiza Rodrigues Cardoso - 14593332


#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
