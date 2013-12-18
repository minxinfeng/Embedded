#include "mapform.h"
#include "ui_mapform.h"
#include "road.h"
#include "gpsreader.h"

#define ICON_SIZE 33

bool m_start_flag;//decide paint start icon
bool m_des_flag;//decide paint des icon
bool m_path_flag;//decide draw path
int x_start;//start icon's x to screen
int y_start;//start icon's y to screen
int x_des;//des icon's x to screen
int y_des;//des icon's y to screen
list<posNode> nodes_w;// nodes
list<posNode> nodes_path;// nodes
GPSReader g;
double m_latitude;
double m_longitude;

MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    m_start_flag = false;
    m_des_flag = false;
    m_path_flag = false;

    m_latitude = 39.95185;
    m_longitude = 116.34041;
    nodes_w = getAllNode();

    ui->setupUi(this);
}

MapForm::~MapForm()
{
    delete ui;
}

void MapForm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,480,272,QPixmap("Res/map.bmp"));
    if(m_start_flag)
    {
        painter.drawPixmap(x_start,y_start,ICON_SIZE,ICON_SIZE,QPixmap("Res/start.png"));
    }
    if(m_des_flag)
    {
        painter.drawPixmap(x_des,y_des,ICON_SIZE,ICON_SIZE,QPixmap("Res/destination.png"));
    }
    if(m_path_flag)
    {
        QPen pen;

        int x1 = (toNode(nodes_path.begin()).x);
        int y1 = (toNode(nodes_path.begin()).y);
        int x2 = 0;
        int y2 = 0;

        pen.setColor(Qt::red);
        painter.setPen(pen);
        //painter.drawLine(x1,y1,x2,y2);

        list<posNode>::iterator iter = nodes_path.begin().operator ++();
        for(iter; iter!=nodes_path.end(); iter ++)
        {
            posNode node = toNode(iter);
            x2 = node.x;
            y2 = node.y;
            painter.drawLine(x1,y1,x2,y2);
            x1 = x2;
            y1 = y2;
        }
    }
}

/***********************************************
get Longitude latitude until start button pushed;
paint start icon;
save Longitude latitude to file start.txt
************************************************/
void MapForm::on_PBtn_Start_clicked()
{    
    posNode node = nodes_w.front();
    x_start = node.x;
    y_start = node.y;

    m_start_flag = !m_start_flag;

    this->update();
}
/***********************************************
get Longitude latitude until destination button pushed;
paint destination icon;
paint the path;
************************************************/
void MapForm::on_PBtn_Destination_clicked()
{
    getPath(m_latitude,m_longitude);
    nodes_path = getPath(39.95146,116.34494);
    //nodes_path = getPath(m_latitude,m_longitude);
    posNode node = nodes_w.back();
    x_des = node.x - 33;
    y_des = node.y;
    m_des_flag = !m_des_flag;
    m_path_flag = !m_path_flag;
    this->update();
}
