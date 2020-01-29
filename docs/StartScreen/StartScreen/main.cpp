#include "startscreenwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startScreenWindow w;
    w.show();

    return a.exec();
}
