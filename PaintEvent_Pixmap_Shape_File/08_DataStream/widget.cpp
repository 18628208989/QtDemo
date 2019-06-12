#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    //创建文件对象
    QFile file("/Users/zhangboqiang/QtCode/date03/QDataStream测试文本.txt");

    //打开文件，只写方式打开
    bool isOK = file.open(QIODevice::WriteOnly);
    if(true == isOK)
    {
        //创建数据流和file文件关联
        //往数据流中写数据，相当于往文件里写数据
        QDataStream stream(&file);

        stream << QString("测试字符串") << 000;

        file.close();
    }
}

void Widget::readData()
{
    //创建文件对象
    QFile file("/Users/zhangboqiang/QtCode/date03/QDataStream测试文本.txt");

    //打开文件，只读方式打开
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        //创建数据流和file文件关联
        //往数据流中读数据，相当于往文件里读数据
        QDataStream stream(&file);
        //读的时候，按写的顺序取数据
        QString str;
        int a;
        stream >> str >> a;
        //qDebug() << str.toUtf8().data() << a;
        cout << str.toUtf8().data() << a;

        file.close();
    }
}
