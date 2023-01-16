#include "view/mainwindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    QApplication a(argc, argv);
    s21::Controller controller;
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
