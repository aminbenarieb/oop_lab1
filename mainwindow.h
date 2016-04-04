#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QEvent>
#include <QPoint>

#include "ui_mainwindow.h"
#include "handler.h"

class MainWindow : public  QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    ~MainWindow();

    MainWindow(QMainWindow* pwgt = 0) : QMainWindow(pwgt) {

        setupUi(this);

        this->setWindowTitle(kTextTitle);
        this->installEventFilter(this);

        //***** QPaintWidget Settings ******
        wgt->setAutoFillBackground(true);
        QPalette Pal = palette();
        Pal.setColor(QPalette::Background, Qt::white);
        wgt->setPalette(Pal);

        //*******************************

        //***** Buttons Settings ******
        btnLoad->setText(kBtnTextLoad);
        //*******************************

        //*******************************
        QObject::connect(btnLoad, SIGNAL(clicked()), this, SLOT(slotLoad()));
        //*******************************

    }

public slots:
    void slotLoad()
    {

        QByteArray byteArray = QFileDialog::getOpenFileName(this,
                                                     tr("Open model"), "./", tr("Model files (*.txt)")).toLatin1();

        hParam param = hParam();
        param.filename = byteArray.data();

        fStatus status = handle(hLoad, &param);

        switch (status)
        {
            case (fOk):
                break;
            case (fNotFound):
            {
                showMsg(kMsgFileNotFound);
                break;
            }
            case (fCorrupted):
            {
                showMsg(kMsgFileCorrupted);
                break;
            }
            case (fOutOfMemory):
            {
                showMsg(kMsgFileOutMemory);
                break;
            }
            default:
            {
                showMsg(kMsgUnknowError);
            }
        }

    }


private:
    QPoint mousePoint;
    bool eventFilter(QObject *, QEvent *event)
    {
        if(event->type() == QEvent::MouseButtonPress )
        {
            mousePoint = ((QMouseEvent *)event)->pos();
            return true;
        }
        else if(event->type() == QEvent::MouseMove )
        {
            QMouseEvent *e = ((QMouseEvent *)event);
            if(e->buttons() == Qt::LeftButton)
            {
                double dy = (e->x() - mousePoint.x()) / kMouseSensetivity;
                double dx = (e->y() - mousePoint.y()) / kMouseSensetivity;
                mousePoint = e->pos();

                sMove move;
                move.dx = dx;
                move.dy = 0.0;
                move.dz = dy;

                hParam param;
                param.move = move;

                handle(hRotate, &param);
            }

            return true;
        }
        else if(event->type() == QKeyEvent::KeyPress )
        {
            QKeyEvent *keyPress = (QKeyEvent*)event;

            switch (keyPress->key())
            {
                case Qt::Key_Up:
                {
                    // Shift up
                    sMove shift;
                    shift.dx = 0;
                    shift.dy = -1;
                    shift.dz = 0;

                    hParam param;
                    param.move = shift;

                    handle(hScale, &param);

                    break;
                }
                case Qt::Key_Down:
                {


                    //Shift down
                    sMove shift;
                    shift.dx = 0;
                    shift.dy = 1;
                    shift.dz = 0;

                    hParam param;
                    param.move = shift;

                    handle(hScale, &param);

                    break;
                }
                case Qt::Key_Left:
                {
                    // Shift left
                    sMove shift;
                    shift.dx = -1;
                    shift.dy = 0;
                    shift.dz = 0;

                    hParam param;
                    param.move = shift;

                    handle(hScale, &param);
                    break;
                }
                case Qt::Key_Right:
                {
                    // Shift right
                    sMove shift;
                    shift.dx = 1;
                    shift.dy = 0;
                    shift.dz = 0;

                    hParam param;
                    param.move = shift;

                    handle(hScale, &param);
                    break;
                }
                case Qt::Key_W:
                {
                    // Zoom in
                    hParam param;
                    param.scale = 1.1;
                    handle(hScale, &param);
                    break;
                }
                case Qt::Key_S:
                {
                    // Zoom out
                    hParam param;
                    param.scale = 0.9;
                    handle(hScale, &param);
                    break;
                }
            default:
                break;
            }
        }

        return false;
    }
    void showMsg(QString msg)
    {
        QMessageBox *msgBox = new QMessageBox(0);
        msgBox->setText(msg);
        msgBox->setWindowModality(Qt::NonModal);
        msgBox->exec();
    }


};

#endif // MAINWINDOW_H
