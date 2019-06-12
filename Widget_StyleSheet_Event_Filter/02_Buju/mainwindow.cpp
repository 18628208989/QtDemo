#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap(":/new/prefix1/屏幕快照 2019-06-10 上午1.00.38.png"));
    //ui->labelImage->setPixmap(QPixmap("://屏幕快照 2019-06-09 下午5.54.03.png"));
    //让图片自动适应label大小
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
