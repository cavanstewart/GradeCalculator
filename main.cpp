#include "mainwindow.h"
#include <QApplication>
#include "hw1.h"
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
