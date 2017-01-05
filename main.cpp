#include "mainwindow.h"
#include <QApplication>

#include <QSurfaceFormat>

int main (int argc, char *argv[]) {
    QApplication a (argc, argv);
    MainWindow w;
    w.show ();

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    return a.exec ();
}
