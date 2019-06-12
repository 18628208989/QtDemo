#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    //添加MySql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");    //数据库服务IP
    db.setUserName("root"); //数据库用户名
    db.setPassword("a18628208989"); //数据库密码
    db.setDatabaseName("test"); //使用哪个数据库

    //打开数据库
    if(!db.open())  //数据库打开失败
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
//创建表
//    QSqlQuery query;
//    query.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");

    //插入
    QSqlQuery query;
    //query.exec("insert into student(id, name, age, score) values(1, 'mike', 18, 59);");

    //批量插入
    //odbc风格
    //预处理语句
//    query.prepare("insert into student(name, age, score) values(?, ?, ?);");
//    //给字段设置内容list
//    QVariantList nameList;
//    nameList << "xiaoming" << "xiaolong" << "xiaojiang";
//    QVariantList ageList;
//    ageList << 11 << 22 << 33;
//    QVariantList scoreList;
//    scoreList << 59 << 69 << 99;
//    //给字段绑定相应的值,按顺序绑定
//    query.addBindValue(nameList);
//    query.addBindValue(ageList);
//    query.addBindValue(scoreList);
//    //执行预处理命令
//    query.execBatch();

    //oracle风格
//    //占位符 ：+自定义名字
//    query.prepare("insert into student(name, age, score) values(:name, :age, :score);");
//    //给字段设置内容list
//    QVariantList nameList;
//    nameList << "xiaoA" << "xiaoC" << "xiaoD";
//    QVariantList ageList;
//    ageList << 33 << 44 << 55;
//    QVariantList scoreList;
//    scoreList << 89 << 39 << 49;
//    //给字段绑定
//    query.bindValue(":name", nameList);
//    query.bindValue(":score", scoreList);
//    query.bindValue(":age", ageList);
//    //执行预处理命令
//    query.execBatch();

    query.exec("select * from student where name = 'mike'");

    while (query.next()) {  //一行一行遍历
        //取出当前行的内容
        //以列为单位
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
    //获取行编辑的内容
    QString name = ui->lineEdit->text();


    QString sql = QString("delete from student where name = '%1';").arg(name);

    //开启一个事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);
}

void Widget::on_buttonSure_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_buttonCancel_clicked()
{
    //回滚，撤销
    QSqlDatabase::database().rollback();
}
