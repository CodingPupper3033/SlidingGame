//
// Created by codin on 2/3/26.
//

#include <QApplication>
#include "GUI/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(400, 400);
    window.show();

    return QApplication::exec();
}