#include "simulator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Simulator w;
    w.show();

    return app.exec();
}

