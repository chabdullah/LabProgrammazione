#ifndef TESTPROGRESS_H
#define TESTPROGRESS_H

#include "../observer.h"
#include "../fileloader.h"

class TestProgress : public Observer
{
public:
    TestProgress(FileLoader* pfl);
    void update(int p_progress, QString line);
    int getProgress();

private:
    FileLoader* fileLoader;
    int progress;
};

#endif // TESTPROGRESS_H
