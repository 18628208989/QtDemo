#include "mywidget.h"
#include <QPushButton>
#include "mybotton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /* 对于父窗口（主窗口），坐标系统相对于屏幕
     * 原点：相对于屏幕左上角
     * x：往右递增
     * y：往下递增
     */
    move(100, 100);

    /* 子窗口 ，坐标系统相对于父窗口
     * 原点：相对于窗口空白区域左上角（不包括边框）
     * x：往右递增
     * y：往下递增
     */
    QPushButton *b1 = new QPushButton(this);
    b1 -> move(100, 100);
    b1 -> setText("^_^");
    b1 -> resize(200, 100);

    QPushButton *b2 = new QPushButton(b1);
    b2 -> move(10, 10);
    b2 -> setText("@_@");

    //指定父对象后、直接或间接继承与QObject
    //子对象如果是动态分配空间的new，不需要手动释放
    //系统会自动释放
    MyBotton *b3 = new MyBotton(this);
    b3 -> setText("123");
}

MyWidget::~MyWidget()
{

}
