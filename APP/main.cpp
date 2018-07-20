#include "app.h"
#include <QApplication>

int main(int argc, char *argv[])//this is submitted by productor
{
    QApplication a(argc, argv);
    miniPrApp app;
    app.run();
    return a.exec();
}
