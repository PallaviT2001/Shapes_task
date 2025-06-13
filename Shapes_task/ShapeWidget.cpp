#include "ShapeWidget.h"
#include <QPainter>
#include <QPolygon>
#include <QtMath>
#include <iostream>
using namespace std;

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent), shapeType("Rectangle"), penWidth(2), borderColor(Qt::black), fillColor(Qt::blue)
{
    cout<<"shape widget constructor called"<<endl;
}

void ShapeWidget::setShapeType(const QString &shape)
{
    shapeType = shape;
    update();
}

void ShapeWidget::setPenWidth(int width)
{
    penWidth = width;
    update();
}

void ShapeWidget::setBorderColor(const QColor &color)
{
    borderColor = color;
    update();
}

void ShapeWidget::setFillColor(const QColor &color)
{
    fillColor = color;
    update();
}

void ShapeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(borderColor, penWidth));
    painter.setBrush(fillColor);

    QRect rect(10, 10, width() / 3, height() / 3);

    if (shapeType == "Rectangle")
    {
        painter.drawRect(rect);
    }
    else if (shapeType == "Circle")
    {
        painter.drawEllipse(rect);
    }
    else if (shapeType == "Square")
    {
        int size = qMin(rect.width(), rect.height());
        QRect square(rect.topLeft(), QSize(size, size));
        painter.drawRect(square);
    }
    else if (shapeType == "Rhombus")
    {
        QPolygon rhombus;
        QPoint center = rect.center();
        int dx = rect.width() / 2;
        int dy = rect.height() / 2;
        rhombus << QPoint(center.x(), center.y() - dy)
                << QPoint(center.x() + dx, center.y())
                << QPoint(center.x(), center.y() + dy)
                << QPoint(center.x() - dx, center.y());
        painter.drawPolygon(rhombus);
    }
    else if (shapeType == "Triangle")
    {
        QPolygon triangle;
        triangle << QPoint(rect.left() + rect.width() / 2, rect.top())
                 << QPoint(rect.left(), rect.bottom())
                 << QPoint(rect.right(), rect.bottom());
        painter.drawPolygon(triangle);
    }
}
