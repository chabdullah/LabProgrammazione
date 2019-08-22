#ifndef FILELOADER_H
#define FILELOADER_H


#include <QFile>
#include <QList>
#include "subject.h"

class FileLoader: public Subject
{
public:
    FileLoader(QString name, QString filePath=":/");
    ~FileLoader();

    void addObserver(Observer *o);
    void removeObserver(Observer *o);
    void notify(int progress, QString line);

    void loadFile();
    QString getFilePath(){return filePath;}
    void setFilePath(QString p_path){filePath = p_path;}
    QString getName(){return name;}
    void setName(QString p_name){name = p_name;}


private:
    QList<Observer*> observers;
    QString name;
    QString filePath;
};

#endif // FILELOADER_H
