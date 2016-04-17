#include "qpaintwidget.h"
#include "config.h"

#include <QDebug>
#include <QPainter>

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
  // Initialization

}


void QPaintWidget::clear()
{
    lineStack.clear();
    this->repaint();
}

void QPaintWidget::drawLine(int x1, int y1, int x2, int y2)
{
    double lm = this->width()/2;
    double tm = this->height()/2;

    lineStack.push_back( new QLine(lm+x1, tm+y1, lm+x2, tm+y2) );
    this->update();
}

void QPaintWidget::paintEvent(QPaintEvent *) {

    QPainter ppainter(this);
    ppainter.setPen(QPen(Qt::blue, kDrawPenWidth));
    ppainter.setBrush(QBrush(Qt::transparent));

    foreach (QLine *line, lineStack)
    {
        ppainter.drawLine(*line);
    }

}
