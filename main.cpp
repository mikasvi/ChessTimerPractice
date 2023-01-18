#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*QObject::connect(&w, SIGNAL(stopProgram()),
            &a, SLOT(stop()));*/

    w.show();
    return a.exec();
}
