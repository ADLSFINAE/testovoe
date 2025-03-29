#include <QApplication>

#include "generaladapter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GeneralAdapter* adapter = new GeneralAdapter;
    Q_UNUSED(adapter)

    return a.exec();
}
