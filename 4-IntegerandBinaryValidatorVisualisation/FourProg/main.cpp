#include <QApplication>

#include "generaladapter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GeneralAdapter* generalAdapter = new GeneralAdapter();
    Q_UNUSED(generalAdapter)

    return a.exec();
}
