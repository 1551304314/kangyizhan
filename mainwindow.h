#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QTimer>
#include<map.h>
#include<QPainter>
#include<game.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void init();
    ~MainWindow();
     game * game1;

private slots:
    void on_btn_single_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
