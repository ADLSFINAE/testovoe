#include <QApplication>

#include "generaladapter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GeneralAdapter* viewer = new GeneralAdapter(nullptr);
    viewer->showMaximized();

    return app.exec();
}
