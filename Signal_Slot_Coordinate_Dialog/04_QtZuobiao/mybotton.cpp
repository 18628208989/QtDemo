#include "mybotton.h"
#include <QDebug>

MyBotton::MyBotton(QWidget *parent) : QPushButton(parent)
{

}

MyBotton::~MyBotton()
{
    qDebug() << "按钮被析构";
}
