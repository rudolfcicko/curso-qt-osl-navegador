#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Brutal Logic");
    QCoreApplication::setOrganizationDomain("youtube.com");
    QCoreApplication::setApplicationName("WebBrowser");


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
