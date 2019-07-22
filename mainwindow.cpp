#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include"hander.h"
#include <QTimer>
#include <QString>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->a=0;
    this->timer = new QTimer(this);
    ui->setupUi(this);
    this->sc=new myscene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
    connect(this->ui->stop,SIGNAL(clicked(bool)),this,SLOT(stop()));
    connect(this->ui->pause,SIGNAL(clicked(bool)),this,SLOT(pause()));
    this->score=0;
    hander * hand=hander::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(addscore()));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Starttime()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确定","你要关闭吗？","是","否");
    if(ret==1){
        event->ignore();
    }
}
void MainWindow::addscore(){
    this->score+=10;
    this->ui->lcdNumber->display(this->score);
}
void MainWindow::pause(){
    if(this->ui->pause->text()=="暂停"){
        this->timer->stop();
        this->sc->pause();
        this->ui->pause->setText("继续");
    }else{
        this->timer->start();
        this->sc->contin();
        this->ui->pause->setText("暂停");
    }
}
void MainWindow::stop(){
    this->sc->stop();
    this->timer->stop();
    int ret=QMessageBox::question(this,"确定","确定吗，这样会清空当前分数","是","否");
    if(ret==0){
        this->score=0;
        this->ui->lcdNumber->display(this->score);
        a=60;
        this->ui->lcdNumber_2->display(a);
    }else{
        this->timer->start();
        this->sc->start();
    }
}
void MainWindow::start(){
        a = 60;
        this->ui->lcdNumber_2->display(a);
        timer->start(1000);  //1000ms 表示1秒
        this->sc->start();
}
void MainWindow::Starttime(){
    if(a != 0)
        {
            a = a - 1; //注意字符类型
            this->ui->lcdNumber_2->display(a);
        }
        else
        {
            this->GameOver();
        }

}
void MainWindow::GameOver(){
    this->timer->stop();
    this->sc->ptimer->stop();
    int grade=this->ui->lcdNumber->intValue();
    QString s=QString("游戏结束你的分数为%1,是否重新开始？").arg(grade);
    int ret=QMessageBox::question(this,"确定",s,"是","否");
    if(ret==0){
        this->score=0;
        this->ui->lcdNumber->display(this->score);
        this->start();
    }else{
        this->score=0;
        this->ui->lcdNumber->display(this->score);
        a=60;
        this->ui->lcdNumber_2->display(a);
        int i=0;
        for(i=0;i<16;i++)
        {
            this->sc->item[i]->SetPic(":/pic/pic/hole.jpg");
            this->sc->item[i]->setMouse(false);
        }
    }
}
