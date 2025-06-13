#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addSpacing(30);

    QLabel *penLabel = new QLabel("Pen Width:");
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(1, 10);
    penWidthSpinBox->setValue(2);

    QLabel *borderLabel = new QLabel("Border Color:");
    borderColorLineEdit = new QLineEdit;
    borderColorLineEdit->setFixedWidth(100);

    QLabel *fillLabel = new QLabel("Fill Color:");
    fillColorLineEdit = new QLineEdit;
    fillColorLineEdit->setFixedWidth(100);

    controlsLayout->addWidget(penLabel);
    controlsLayout->addWidget(penWidthSpinBox);
    controlsLayout->addSpacing(20);
    controlsLayout->addWidget(borderLabel);
    controlsLayout->addWidget(borderColorLineEdit);
    controlsLayout->addSpacing(20);
    controlsLayout->addWidget(fillLabel);
    controlsLayout->addWidget(fillColorLineEdit);
    controlsLayout->addStretch();

    mainLayout->addLayout(controlsLayout);

    QHBoxLayout *middleLayout = new QHBoxLayout;
    QVBoxLayout *buttonsLayout = new QVBoxLayout;

    rectangleButton = new QPushButton("Rectangle");
    circleButton = new QPushButton("Circle");
    squareButton = new QPushButton("Square");
    rhombusButton = new QPushButton("Rhombus");
    triangleButton = new QPushButton("Triangle");

    buttonsLayout->addWidget(rectangleButton);
    buttonsLayout->addWidget(circleButton);
    buttonsLayout->addWidget(squareButton);
    buttonsLayout->addWidget(rhombusButton);
    buttonsLayout->addWidget(triangleButton);
    buttonsLayout->addStretch();

    shapeWidget = new ShapeWidget(this);
    shapeWidget->setMinimumSize(400, 300);

    middleLayout->addLayout(buttonsLayout);
    middleLayout->addWidget(shapeWidget, 1);

    mainLayout->addLayout(middleLayout);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Shape Drawer");

    connect(rectangleButton, &QPushButton::clicked, this, &MainWindow::setShapeRectangle);
    connect(circleButton, &QPushButton::clicked, this, &MainWindow::setShapeCircle);
    connect(squareButton, &QPushButton::clicked, this, &MainWindow::setShapeSquare);
    connect(rhombusButton, &QPushButton::clicked, this, &MainWindow::setShapeRhombus);
    connect(triangleButton, &QPushButton::clicked, this, &MainWindow::setShapeTriangle);

    connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updatePenWidth);
    connect(borderColorLineEdit, &QLineEdit::editingFinished, this, &MainWindow::applyBorderColor);
    connect(fillColorLineEdit, &QLineEdit::editingFinished, this, &MainWindow::applyFillColor);

    setShapeRectangle();
}

MainWindow::~MainWindow()
{
    cout<<"Mainwindow Destructor called"<<endl;
}

void MainWindow::setShapeRectangle()
{
    shapeWidget->setShapeType("Rectangle");
}

void MainWindow::setShapeCircle()
{
    shapeWidget->setShapeType("Circle");
}
void MainWindow::setShapeSquare()
{
    shapeWidget->setShapeType("Square");
}
void MainWindow::setShapeRhombus()
{
    shapeWidget->setShapeType("Rhombus");
}
void MainWindow::setShapeTriangle()
{
    shapeWidget->setShapeType("Triangle");
}

void MainWindow::updatePenWidth(int width)
{
    shapeWidget->setPenWidth(width);
}

void MainWindow::applyBorderColor()
{
    QColor color(borderColorLineEdit->text());
    if (color.isValid())
    {
        shapeWidget->setBorderColor(color);
    }
}


void MainWindow::applyFillColor()
{
    QColor color(fillColorLineEdit->text());
    if (color.isValid())
    {
        shapeWidget->setFillColor(color);
    }
}
