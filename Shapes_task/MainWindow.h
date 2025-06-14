#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>
#include "ShapeWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setShapeRectangle();
    void setShapeCircle();
    void setShapeSquare();
    void setShapeRhombus();
    void setShapeTriangle();

    void updatePenWidth(int width);
    void applyBorderColor();
    void applyFillColor();
private:
    ShapeWidget *shapeWidget;

    QSpinBox *penWidthSpinBox;
    QLineEdit *borderColorLineEdit;
    QLineEdit *fillColorLineEdit;

    QPushButton *rectangleButton;
    QPushButton *circleButton;
    QPushButton *squareButton;
    QPushButton *rhombusButton;
    QPushButton *triangleButton;
};

#endif
