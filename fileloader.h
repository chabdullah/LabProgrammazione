#ifndef FILELOADER_H
#define FILELOADER_H


#include <QFile>
#include <QList>
#include "subject.h"

class FileLoader: public Subject
{
public:
    FileLoader(QString name, QString filePath=":/");
    ~FileLoader() override;

    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notify(int progress, QString line) override;

    void loadFile();
    void read(QString line);
    float getTotSize(){return totSize;}
    QString getFilePath(){return filePath;}
    void setFilePath(QString p_path){filePath = p_path;}
    QString getName(){return name;}
    void setName(QString p_name){name = p_name;}
    void setTotSize(float pTotSize){totSize = pTotSize;}


private:
    QList<Observer*> observers;
    QString name;
    QString filePath;
    int progressBar, size;
    float totSize;
};

#endif // FILELOADER_H
