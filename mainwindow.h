#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "observer.h"
#include "fileloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(FileLoader *fileLoader, QWidget *parent = nullptr);
    void update(int progress, QString line);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FileLoader* fileLoader;
};

#endif // MAINWINDOW_H
