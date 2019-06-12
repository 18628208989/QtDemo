#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
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
    QFile file;
    file.setFileName("/Users/zhangboqiang/QtCode/date03/QTextStream测试文本.txt");

    bool isOK = file.open(QIODevice::WriteOnly);
    if(true == isOK)
    {
        QTextStream stream(&file);

        //指定编码
        stream.setCodec("UTF-8");

        stream << QString("测试QTextStream") << 110;

        file.close();
    }
}

void Widget::readData()
{
    QFile file;
    file.setFileName("/Users/zhangboqiang/QtCode/date03/QTextStream测试文本.txt");

    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        QTextStream stream(&file);

        //指定编码
        stream.setCodec("UTF-8");

        QString str;
        int a;
        stream >> str >> a;

        cout << str << a;

        file.close();
    }
}

void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "/Users/zhangboqiang/QtCode/date03/");
    if(false == path.isEmpty())
    {
        QFile file;
        file.setFileName("/Users/zhangboqiang/QtCode/date03/QTextStream测试文本.txt");

        bool isOK = file.open(QIODevice::ReadOnly);
        if(true == isOK)
        {
            QTextStream stream(&file);

            //指定编码
            stream.setCodec("UTF-8");
            QString str = stream.readAll();
            ui->textEdit->setText(str);
        }
    }
}
