#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(FileLoader* pfl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileLoader = pfl;
    fileLoader->addObserver(this);

}

MainWindow::~MainWindow()
{
    fileLoader->removeObserver(this);
    delete ui;
}



void MainWindow::update(int progress, QString line){
    ui->progressBar->setValue(progress);
    ui->plainTextEdit->setPlainText(line);
    qApp->processEvents();
}
