#ifndef MAPFORM_H
#define MAPFORM_H

/************************************************************************/
/* Author: Wang Yongbo                                               */
/* paint path start icon destination icon */
/************************************************************************/

#include <QWidget>
#include <QtGui>
#include <stdio.h>
#include "gpsreader.h"
#include <list>
#include "road.h"

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
    void  paintEvent(QPaintEvent  *);
private slots:
    void on_PBtn_Start_clicked();
    void on_PBtn_Destination_clicked();
    void getGPSData();
private:
    Ui::MapForm *ui;
    GPSReader m_gps;
    bool m_start_flag;//decide paint start icon
    bool m_des_flag;//decide paint des icon
    bool m_path_flag;//decide draw path
    int x_start;//start icon's x to screen
    int y_start;//start icon's y to screen
    int x_des;//des icon's x to screen
    int y_des;//des icon's y to screen
    list<posNode> nodes_w;// nodes
    list<posNode> nodes_path;// nodes
    double m_latitude;
    double m_longitude;

    int test;
};

#endif // MAPFORM_H
