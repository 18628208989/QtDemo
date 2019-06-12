#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>//获取文件信息
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "/Users/zhangboqiang/QtCode/date03/", "TXT(*.txt)");

    if(path.isEmpty() == false)
    {
        //文件对象,默认只识别utf8编码
        QFile file(path);

        //打开文件,只读打开
        bool isOK = file.open(QIODevice::ReadOnly);
        if(isOK == true)
        {
#if 0
            //读文件
            QByteArray array = file.readAll();
            //显示到编辑区
            ui->textEdit->setText(QString(array));
#endif

            QByteArray array;
            while (file.atEnd() == false)
            {
                //读一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }

        //关闭文件
        file.close();

        //获取文件信息
        QFileInfo info(path);
        qDebug() << "文件名字：" << info.fileName().toUtf8().data();
        qDebug() << "文件后缀：" << info.suffix();
        qDebug() << "文件大小：" << info.size();
        qDebug() << "文件创建事件：" << info.created().toString("yyyy-MM-dd hh:mm:ss"); //2019-06-12 15:19
    }


}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "/Users/zhangboqiang/QtCode/date03/", "TXT(*.txt)");

    if(path.isEmpty() == false)
    {
        QFile file; //创建文件对象
        //关联文件名字
        file.setFileName(path);

        //打开文件，只写方式
        bool isOK = file.open(QIODevice::WriteOnly);
        if(isOK == true)
        {
            //获取编辑区内容
            QString str = ui->textEdit->toPlainText();

            //写文件
            //QString -> QByteArray
            file.write(str.toUtf8());

            //QString -> c++ string -> char *
            //file.write(str.toStdString().data());

            //转换为本地平台编码
            //file.write(str.toLocal8Bit());

            //QString -> QByteArray
            //QString buf = "123";
            //QByteArray a = buf.toUtf8();
            //a = buf.toLocal8Bit(); //本地编码

            //QByteArray -> char *
            //char *b = a.data();

            //char * -> QString
            //char *p = "abc";
            //QString c = QString(p);

        }

        file.close();
    }
}
