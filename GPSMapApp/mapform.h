#ifndef MAPFORM_H
#define MAPFORM_H

/************************************************************************/
/* Author: Wang Yongbo                                               */
/* paint path start icon destination icon */
/************************************************************************/

#include <QWidget>
#include <QtGui>
#include <stdio.h>

namespace Ui {
class MapForm;
}
class MapForm : public QWidget
{
    Q_OBJECT
public:
    explicit MapForm(QWidget *parent = 0);
    ~MapForm();    
protected:
    void  paintEvent(QPaintEvent  * event);
private slots:


    void on_PBtn_Start_clicked();

    void on_PBtn_Destination_clicked();

private:
    Ui::MapForm *ui;
};

#endif // MAPFORM_H
