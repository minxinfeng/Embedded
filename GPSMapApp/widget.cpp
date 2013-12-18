#include "widget.h"
#include "ui_widget.h"
#include "QPainter"

int x1,y1,x2,y2;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap("/data/map/map.bmp")));
    this->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}

//重新实现paintEvent
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPen pen;

    x1=0;
    y1=0;
    x2=100;
    y2=100;

    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawLine(x1,y1,x2,y2);
}
