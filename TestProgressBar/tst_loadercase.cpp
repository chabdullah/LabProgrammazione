#include <QtTest>


#include "testprogress.h"
#include "../fileloader.h"
#include "../fileloader.cpp"



class LoaderCase : public QObject
{
    Q_OBJECT

public:
    LoaderCase();
    ~LoaderCase();

private slots:
    void test_constructor();
    void test_constructor_wo_filePath();
    void test_setFilePath();
    void test_setName();
    void test_progress();

};

void LoaderCase::test_constructor()
{
    FileLoader* fl = new FileLoader("File Loader",":/Path/to/file");
    QVERIFY2(fl->getName() == "File Loader", "Il nome dell'oggeto FileLoader non va bene");
    QVERIFY2(fl->getFilePath() == ":/Path/to/file", "Il percorso del file non va bene");
}

void LoaderCase::test_constructor_wo_filePath()
{
    FileLoader* fl = new FileLoader("File Loader");
    QVERIFY2(fl->getName() == "File Loader", "Il nome dell'oggeto FileLoader non va bene se non è specificato il filePath nel costruttore");
    QVERIFY2(fl->getFilePath() == ":/", "Il percorso di default del file non va bene");
}

void LoaderCase::test_setFilePath()
{
    FileLoader* fl = new FileLoader("File Loader");
    fl->setFilePath(":/Path/to/file");
    QVERIFY2(fl->getFilePath() == ":/Path/to/file", "SetFilePath non va bene");
}

void LoaderCase::test_setName()
{
    FileLoader* fl = new FileLoader("File Loader 1");
    fl->setName("File Loader 2");
    QVERIFY2(fl->getName() == "File Loader 2", "SetName non va bene");
}

void LoaderCase::test_progress()
{
    FileLoader* fl = new FileLoader("File Loader");
    TestProgress tp(fl);
    fl->setTotSize(50);

    QVERIFY2(tp.getProgress() == 0, "Errore nell'inizializzazione del valore della progressBar");
    fl->read("Riga uno");
    QVERIFY2(tp.getProgress() == (8./(50))*100, "Errore nell'aggiornamento del valore della progressBar - Riga 1");
    fl->read("Riga due");
    QVERIFY2(tp.getProgress() == (16./(50))*100, "Errore nell'aggiornamento del valore della progressBar - Riga 2");
    fl->read("Riga tre");
    QVERIFY2(tp.getProgress() == (24./(50))*100, "Errore nell'aggiornamento del valore della progressBar - Riga 3");
    fl->read("Nel mezzo del cammin di ..");
    QVERIFY2(tp.getProgress() == (50./(50))*100, "Errore nell'aggiornamento del valore della progressBar - Riga 4");
}

LoaderCase::LoaderCase(){

}

LoaderCase::~LoaderCase(){

}

QTEST_APPLESS_MAIN(LoaderCase)

#include "tst_loadercase.moc"
