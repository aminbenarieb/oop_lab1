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

        StreamInfo stream = StreamInfo();
        stream.filename = byteArray.data();

        ParamInfo param = ParamInfo();
        param.stream = stream;

        ErrorInfo status = handle(aLoad, &param);

        switch (status)
        {
            case (eOk):
                break;
            case (eNotFound):
            {
                showMsg(kMsgFileNotFound);
                break;
            }
            case (eCorrupted):
            {
                showMsg(kMsgFileCorrupted);
                break;
            }
            case (eOutOfMemory):
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

                MoveInfo move;
                move.dx = dx;
                move.dy = 0.0;
                move.dz = dy;

                ParamInfo param;
                param.move = move;

                handle(aRotate, &param);
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
                    MoveInfo shift;
                    shift.dx = 0;
                    shift.dy = -1;
                    shift.dz = 0;

                    ParamInfo param;
                    param.move = shift;

                    handle(aScale, &param);

                    break;
                }
                case Qt::Key_Down:
                {


                    //Shift down
                    MoveInfo shift;
                    shift.dx = 0;
                    shift.dy = 1;
                    shift.dz = 0;

                    ParamInfo param;
                    param.move = shift;

                    handle(aScale, &param);

                    break;
                }
                case Qt::Key_Left:
                {
                    // Shift left
                    MoveInfo shift;
                    shift.dx = -1;
                    shift.dy = 0;
                    shift.dz = 0;

                    ParamInfo param;
                    param.move = shift;

                    handle(aScale, &param);
                    break;
                }
                case Qt::Key_Right:
                {
                    // Shift right
                    MoveInfo shift;
                    shift.dx = 1;
                    shift.dy = 0;
                    shift.dz = 0;

                    ParamInfo param;
                    param.move = shift;

                    handle(aScale, &param);
                    break;
                }
                case Qt::Key_W:
                {
                    // Zoom in
                    ScaleInfo scale = ScaleInfo();
                    scale.value = 1.1;

                    ParamInfo param;
                    param.scale = scale;
                    handle(aScale, &param);
                    break;
                }
                case Qt::Key_S:
                {
                    // Zoom out
                    ScaleInfo scale = ScaleInfo();
                    scale.value = 0.9;

                    ParamInfo param;
                    param.scale = scale;
                    handle(aScale, &param);
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
