#ifndef FILELOADER_H
#define FILELOADER_H


#include <QFile>
#include <QList>
#include "subject.h"

class FileLoader: public Subject
{
public:
    FileLoader(QString name);
    ~FileLoader();

    void addObserver(Observer *o);
    void removeObserver(Observer *o);
    void notify(int progress, QString line);

    void loadFile();
    QString getName(){return name;}


private:
    QList<Observer*> observers;
    QString name;
};

#endif // FILELOADER_H
