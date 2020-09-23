#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<config.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap("bg1.png"));


}
void MainWindow::init(){
    setWindowTitle("众志成城，抗击疫情");

    //setWindowIcon();

}



void MainWindow::on_btn_single_clicked()
{
    game1 = new game();
    game1->show();
}
