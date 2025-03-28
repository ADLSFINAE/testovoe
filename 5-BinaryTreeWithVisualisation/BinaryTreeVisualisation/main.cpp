#include <QApplication>

#include "generaladapter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GeneralAdapter* generalAdapter = new GeneralAdapter();
    return a.exec();
}
