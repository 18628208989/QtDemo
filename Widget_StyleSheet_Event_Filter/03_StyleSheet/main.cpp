#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //修改整个应用的样式
    //a.setStyleSheet();

    Widget w;
    w.show();

    return a.exec();
}
