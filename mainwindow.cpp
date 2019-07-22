#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include"hander.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myscene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->start,SIGNAL(clicked(bool)),this->sc,SLOT(start()));
    connect(this->ui->stop,SIGNAL(clicked(bool)),this,SLOT(stop()));
    connect(this->ui->pause,SIGNAL(clicked(bool)),this,SLOT(pause()));
    this->score=0;
    hander * hand=hander::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(addscore()));
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
        this->sc->pause();
        this->ui->pause->setText("继续");
    }else{
        this->sc->contin();
        this->ui->pause->setText("暂停");
    }
}
void MainWindow::stop(){
    this->sc->stop();
    this->score=0;
    this->ui->lcdNumber->display(this->score);
}
