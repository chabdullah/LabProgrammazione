#include "mainwindow.h"
#include "fileloader.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <QStatusBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FileLoader* fl = new FileLoader("File Loader");
    MainWindow m(fl) ;
    m.setWindowTitle("Loading File");
    m.show();
    fl->setFilePath(":/resources/resources/InstallationLog.txt");
    fl->loadFile();



    return a.exec();
}
