#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QLine>

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
    void clear();
    void drawLine(int, int, int, int);

protected:
    void paintEvent(QPaintEvent *);
    QVector<QLine*> lineStack;

};

#endif // QPAINTWIDGET_H
