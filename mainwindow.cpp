#include "mainwindow.h"

#include <QEvent>
#include <QResizeEvent>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->installEventFilter(this);
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


bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(event->type() == QEvent::Resize )
    {
       QResizeEvent *res = reinterpret_cast<QResizeEvent*>(event);
        qDebug()<<res;
        return true;
    }
    else if(event->type() == QKeyEvent::KeyPress )
    {
        QKeyEvent *keyPress = (QKeyEvent*)event;

        QString msg;
        switch (keyPress->key())
        {
        case Qt::Key_Up:
            msg = "Camera up";
            break;
        case Qt::Key_Down:
            msg = "Camera down";
            break;
        case Qt::Key_Left:
            msg = "Camera left";
            break;
        case Qt::Key_Right:
            msg = "Camera right";
            break;
        default:
            break;
        }
        if (msg.count() != 0)
            showMsg(msg);

        return true;
    }

    return false;
}
