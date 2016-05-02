#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"

#define FILENAME "/Users/aminbenarieb/GitHub/uni/oop/lab1/vaza.txt"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene(this);
    this->ui->Canvas->setScene(scene);
}

MainWindow::~MainWindow()
{
    ArgumentInfo argument;
    ActionInfo action = ACTION_QUIT;

    handler(action,argument);
    this->close();
    delete ui;

}

void MainWindow::redrawScreen(ActionInfo *action, ArgumentInfo *argument)
{
    this->scene->clear();
    *action = ACTION_DRAW;
    SceneInfo scene = { .instance = this->scene };
    argument->scene = scene;
}
void MainWindow::showErrorMessage(ErrorInfo error)
{
    switch(error)
    {

        case ERROR_FILE_NOT_EXIST:
        {
            QMessageBox::warning(this,"Error", "Not able to open FILE!");
            break;
        }

        case ERROR_FILE_NOT_VALID:
        {
            QMessageBox::warning(this,"Error", "File consists of wrong input data!");
            break;
        }

        case ERROR_MEMORY:
        {
            QMessageBox::warning(this,"Error", "Not able to allocate memory");
            break;
        }

        case ERROR_NOT_INIT:
        {
            QMessageBox::warning(this,"Error", "Model not loaded!");
            break;
        }


        default:
        {
            QMessageBox::warning(this,"Error", "Unknown error! ");
            break;
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *k)
{
    ActionInfo act;
    ArgumentInfo arg;
    ErrorInfo e;

    act = ACTION_CHANGE;
    e = ERROR_OK;

    switch(k->key())
    {
        case Qt::Key_L:
        {
            StreamInfo stream = {.sourceName = FILENAME};
            if(stream.sourceName == NULL)
            {
                return;
            }

            stream.sourceType = SOURCE_FILE;
            arg.stream = &stream;
            act = ACTION_LOAD;

            break;
        }
        case Qt::Key_Q:
        {
            arg.modification.type = TRANSFORM_ROTATE_Z;
            arg.modification.delta = (-2);
            break;
        }

        case Qt::Key_E:
        {
            arg.modification.type = TRANSFORM_ROTATE_Z;
            arg.modification.delta = 2;
           break;
        }

        case Qt::Key_S:
        {
            arg.modification.type = TRANSFORM_ROTATE_X;
            arg.modification.delta = (-2);
            break;
        }

        case Qt::Key_W:
        {
            arg.modification.type = TRANSFORM_ROTATE_X;
            arg.modification.delta = 2;
            break;
        }

        case Qt::Key_A:
        {
            arg.modification.type = TRANSFORM_ROTATE_Y;
            arg.modification.delta = (-2);
            break;
        }

        case Qt::Key_D:
        {
            arg.modification.type = TRANSFORM_ROTATE_Y;
            arg.modification.delta = 2;
            break;
        }

        case Qt::Key_Z:
        {
            arg.modification.type = TRANSFORM_SCALE;
            arg.modification.delta = 1.00 + 0.1;
            break;
        }

        case Qt::Key_X:
        {
            arg.modification.type = TRANSFORM_SCALE;
            arg.modification.delta = 1.00 - 0.1;
            break;
        }

        case Qt::Key_Escape:
        {
            this->quitApp();
            return;
            break;
        }
    }

    e = handler(act,arg);
    if(e != ERROR_OK)
    {
        showErrorMessage(e);
    }

    redrawScreen(&act,&arg);
    handler(act,arg);
}

void MainWindow::quitApp()
{
    ArgumentInfo argument;
    ActionInfo action = ACTION_QUIT;

    handler(action,argument);
    this->close();
}
