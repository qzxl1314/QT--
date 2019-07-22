#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>
#include<QCloseEvent>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
private slots:
    void addscore();
    void pause();
    void stop();
    void start();
    void GameOver();
    void Starttime();
private:
    Ui::MainWindow *ui;
    myscene * sc;
    QTimer * timer;
    int score;
    int a;
};

#endif // MAINWINDOW_H
