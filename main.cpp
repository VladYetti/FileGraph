#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("VladYetti");
    QApplication::setApplicationName("FileGraph");
    MainWindow w;
    w.show();
    return a.exec();
}
