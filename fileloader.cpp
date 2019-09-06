#include <QTextStream>
#include <iostream>
#include "fileloader.h"

FileLoader::FileLoader(QString pname, QString pFilePath){
    name = pname;
    filePath = pFilePath;
    size = 0;
    progressBar = 0;
    totSize = 0;
}

FileLoader::~FileLoader(){

}


void FileLoader::loadFile(){
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
    }
    setTotSize(file.size());
    QTextStream in(&file);
    while (!in.atEnd())
       {
          read(in.readLine());
       }
    notify(100,QString("Completed!"));
    file.close();
}

void FileLoader::read(QString line){
    size += line.size();
    progressBar = (int)((size/totSize)*100);
    notify(progressBar,line);
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

