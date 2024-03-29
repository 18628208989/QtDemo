#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>//打印

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2 -> setText("abc");

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /*  &b1:信号发出者，指针类型
     *  &QPushButton::pressed：处理的信号，    &发送者的类名::信号名字
     *  this：信号接受者
     *  &MainWidget::close：槽函数，信号处理函数   &接收者的类名::槽函数名字
     */

    /*  自定义槽，普通函数的用法
     *  Qt5:任意的成员函数，普通全局函数，静态函数
     *  槽函数需要和信号一致（参数，返回值）
     * 由于信号都是没有返回值，所以槽函数一定没有返回值
     */
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);

    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);
    /* 信号：短信
     * 槽函数：接受短信的手机
     */

    setWindowTitle("老大");
    this -> setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    //显示子窗口
    //w.show();

    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    //处理子窗口的信号
    //void (SubWidget::*funSignal)() = &SubWidget::mySignal;
    //connect(&w, funSignal, this, &MainWidget::dealSub);
    //void (SubWidget::*testSignal)(int, QString) = &SubWidget::mySignal;
    //connect(&w, testSignal, this, &MainWidget::dealSlot);

    //Qt4信号连接
    //Qt4槽函数必须有slots关键字来修饰
    connect(&w, SIGNAL(mySignal()), this, SLOT(dealSub()));
    connect(&w, SIGNAL(mySignal(int,QString)), this, SLOT(dealSlot(int,QString)));
    //SIGNAL SLOT将函数名字转换成字符串，不进行错误检查

    //Lambda表达式，匿名函数对象
    //C++11增加的特性，项目文件：  CONFIG += C++11
    //Qt配合信号一起使用，非常方便

    QPushButton *b4 = new QPushButton(this);
    b4 -> setText("Lambda表达式");
    b4 -> move(150, 150);

    int a = 10, b = 100;
    connect(b4, &QPushButton::clicked,
            //=:把外部所有局部变量、类中所有成员以值传递方式传进来
            //this:类中所有成员以值传递方式
            //&：把外部所有局部变量，引用符号
            [=](bool isCheck) mutable
            {
                b4 -> setText("123");
                qDebug() << "1111111";
                qDebug() << a << b;
                a = 11;
                qDebug() << isCheck;
            }
            );


    resize(400, 300);
}

void MainWidget::mySlot()
{
    b2 -> setText("123");
}

void MainWidget::changeWin()
{
    //子窗口显示
    w.show();
    //本窗口隐藏
    this -> hide();
}

void MainWidget::dealSub()
{
    w.hide();
    this -> show();
}

void MainWidget::dealSlot(int a, QString str)
{
    qDebug() << a << str.toUtf8().data();
}

MainWidget::~MainWidget()
{

}
