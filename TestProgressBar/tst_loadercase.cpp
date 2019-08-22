#include <QtTest>


#include "../fileloader.h"
#include "../fileloader.cpp"

class LoaderCase : public QObject
{
    Q_OBJECT

public:
    LoaderCase();
    ~LoaderCase();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

LoaderCase::LoaderCase()
{

}

LoaderCase::~LoaderCase()
{

}

void LoaderCase::initTestCase()
{

}

void LoaderCase::cleanupTestCase()
{

}

void LoaderCase::test_case1()
{
    FileLoader* fl = new FileLoader("File Loader");
    QVERIFY2(fl->getName() == "File Loader", "Il nome dell'ooggeto FileLoader non va bene");
}

QTEST_APPLESS_MAIN(LoaderCase)

#include "tst_loadercase.moc"
