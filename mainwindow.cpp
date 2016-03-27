#include "mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

}

void MainWindow::showMsg(QString msg)
{
    QMessageBox *msgBox = new QMessageBox(0);
    msgBox->setText(msg);
    msgBox->setWindowModality(Qt::NonModal);
    msgBox->exec();
}
