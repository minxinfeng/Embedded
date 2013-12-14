#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->bkLabel->setPixmap(QPixmap("map.bmp"));
}

Widget::~Widget()
{
    delete ui;
}
