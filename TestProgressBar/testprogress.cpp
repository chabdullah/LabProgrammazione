#include "testprogress.h"

TestProgress::TestProgress(FileLoader* pfl){
    fileLoader = pfl;
    fileLoader->addObserver(this);
    progress = 0;
}

void TestProgress::update(int p_progress, QString line){
    progress = p_progress;
}

int TestProgress::getProgress(){
    return progress;
}



