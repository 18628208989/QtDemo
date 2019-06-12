#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>//标准对话框
#include <QFileDialog>//文件对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar -> addMenu("对话框");

    QAction *p1 = menu -> addAction("模态对话框");

    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "1111111";
            }
            );

    QAction *p2 = menu -> addAction("非模态对话框");

    connect(p2, &QAction::triggered,
            [=]()
            {
                //窗口定义为对象
                dlg.show();
                qDebug() << "1111111";

                //不会自动释放空间，不好
                //QDialog *p = new QDialog(this);
                //p -> show();

                //设定为关闭时自动释放
                //QDialog *p = new QDialog();
                //p -> setAttribute(Qt::WA_DeleteOnClose);
                //p -> show();
            }
            );

    QAction *p3 = menu -> addAction("关于对话框");

    connect(p3, &QAction::triggered,
            [=]()
            {
                //参数 父类，标题，内容
                QMessageBox::about(this, "about", "关于Qt");
            }
            );

    QAction *p4 = menu -> addAction("问题对话框");

    connect(p4, &QAction::triggered,
            [=]()
            {
                //参数 父类，标题，内容
                int ret = QMessageBox::question(this, "question", "Are you ok?",
                                                QMessageBox::Ok,//自定义选项的内容
                                                QMessageBox::Cancel
                                                );
                switch (ret) {
                    case QMessageBox::Ok:
                        qDebug() << "I am OK";
                        break;
                    case QMessageBox::Cancel:
                        qDebug() << "I am bad";
                    default:
                        break;
                }
            }
            );

    QAction *p5 = menu -> addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=]()
            {
                //参数 父类，标题，上一级路径,指定格式
                QString path = QFileDialog::getOpenFileName(
                            this,
                            "open",
                            "../",
                            "source(*.cpp *.h);;Text(*.txt);;all(*.*)"
                            );
                qDebug() << path;
            }
            );
}

MainWindow::~MainWindow()
{

}
