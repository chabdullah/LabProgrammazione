#include <QTextStream>
#include <iostream>
#include "fileloader.h"

void FileLoader::loadFile(){
    int size = 0, progressBar = 0;
    float totSize;
    QFile file(":/resources/resources/InstallationLog.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
    }
    totSize = file.size();
    QTextStream in(&file);
    while (!in.atEnd())
       {
          QString line = in.readLine();
          size += line.size();
          progressBar = ((size/totSize)*100);
          notify(progressBar,line);
       }

    notify(100,QString("Completed!"));
    file.close();

}

void FileLoader::addObserver(Observer *o){
    observers.push_back(o);
}

void FileLoader::removeObserver(Observer *o){
    observers.removeOne(o);
}

void FileLoader::notify(int progress, QString line){
    for(Observer* observer: observers)
        observer->update(progress, line);
}

FileLoader::FileLoader(QString name){
    name = "FileLoader";
}

FileLoader::~FileLoader(){

}
