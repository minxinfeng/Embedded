#include "mapform.h"
#include "ui_mapform.h"
#include <fcntl.h>
#include <qtimer.h>

#define X_SHIFT 16
#define Y_SHIFT 33
#define ICON_SIZE 33

MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    m_start_flag = false;
    m_des_flag = false;
    m_path_flag = false;

    //test = 1;

    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(getGPSData()));
    timer->start(3000);

    m_gps.startFD();
}

MapForm::~MapForm()
{
    delete ui;
}

void MapForm::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen = QPen(Qt::green, 5, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);

    painter.drawPixmap(0,0,480,272,QPixmap("Res/map.bmp"));
    //double latitude = test++;
    //double longtitude = test++;
    double latitude = m_gps.getLatitude();
    double longtitude = m_gps.getLongitude();
    char gpsCur[100] = "";
    sprintf(gpsCur, "latitude: %f,longtitude: %f", latitude, longtitude);
    painter.drawText(10,230,gpsCur);


    if(m_start_flag) {
        painter.drawPixmap(x_start-X_SHIFT,y_start-Y_SHIFT,ICON_SIZE,ICON_SIZE,QPixmap("Res/start.png"));
    }
    if(m_des_flag) {
        painter.drawPixmap(x_des-X_SHIFT,y_des-Y_SHIFT,ICON_SIZE,ICON_SIZE,QPixmap("Res/destination.png"));
    }
    if(m_path_flag)
    {

        int x1 = (toNode(nodes_path.begin()).x);
        int y1 = (toNode(nodes_path.begin()).y);
        int x2 = 0;
        int y2 = 0;
        printf("s_x:%d,s_y:%d",x1,y1);
        painter.drawPixmap(x1-X_SHIFT,y1-Y_SHIFT,ICON_SIZE,ICON_SIZE,QPixmap("Res/start.png"));
        painter.drawPixmap(x1-X_SHIFT,y1-Y_SHIFT,ICON_SIZE,ICON_SIZE,QPixmap("Res/start.png"));
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

    // show all nodes on the map
    list<posNode> allnodes=  getAllNode();
    list<posNode>::iterator iter2 = allnodes.begin();
    for(iter2; iter2!=allnodes.end(); iter2 ++)
    {
        posNode node2 = toNode(iter2);
        painter.drawPoint(node2.x,node2.y);
    }

}

/***********************************************
get Longitude latitude until start button pushed;
paint start icon;
save Longitude latitude to file start.txt
************************************************/
void MapForm::on_PBtn_Start_clicked()
{
    m_start_flag = true;
    posNode startPoint;

    m_gps.writeToFile();//39.95185 116.34041
    startPoint = getTheNearestNode(m_gps.getLatitude(),m_gps.getLongitude());
    //startPoint = getTheNearestNode(39.95185,116.34041);
    x_start = startPoint.x;
    y_start = startPoint.y;

    m_path_flag = false;

    this->update();
}
/***********************************************
get Longitude latitude until destination button pushed;
paint destination icon;
paint the path;
************************************************/
void MapForm::on_PBtn_Destination_clicked()
{
    posNode endPoint;
    nodes_path = getPath(m_gps.getLatitude(),m_gps.getLongitude());
    //nodes_path = getPath(39.95146,116.34494);

    endPoint = getTheNearestNode(m_gps.getLatitude(),m_gps.getLongitude());
    //endPoint = getTheNearestNode(39.95146,116.34494);
    x_des = endPoint.x;
    y_des = endPoint.y;
    cout << "endPoint: x = " << x_des << ", y = " << y_des << endl;

    // m_start_flag = true;
    m_des_flag = true;
    m_path_flag = true;
    this->update();
}

void MapForm::getGPSData()
{
    this->update();

    int fd = m_gps.getGPSFD();
    if(fd == -1) return;
    int nread = 0;
    int count = 0;
    char buf;
    char gpsData[256];

    while(1)
    {
        nread = read(fd, &buf, 1);
        if (nread > 0)
        {
            if(buf == '\n')
            {
                gpsData[count] = '\0';

                if(m_gps.parseNE(gpsData)==0)
                    break;
                count = 0;
                memset(gpsData, 0, 256);
            }
            else
            {
                gpsData[count] = buf;
                count++;
            }
        }
    }
}
