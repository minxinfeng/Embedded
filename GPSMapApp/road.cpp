#include "road.h"

/************************************************************************/
/* Author: Feng Xiangmin                                                */
/* Find the road from start to the end*/
/************************************************************************/
const double EARTH_RADIUS = 6371.004;//earth radius
//class posNode;
int n=NUM;// the number of node
int path[NUM+1][NUM+1];// path[i][j]:the max id of the node in the road between i and j表示该路径中的最大顶点
int dist[NUM+1][NUM+1];//dist[j][j]:the shortest distance between i and j
int map[NUM+1][NUM+1];//map[i][j]: means weather i and j is connected, 0 is not, 1 is connected

//list<posNode> nodes;//all nodes list
list<int> ids;//all the node ids

double rad(double d)
{
    return d *  M_PI/ 180.0;
}

list<posNode> getPath(double endlat, double endlng){
    list<posNode> pathNodes;
    posNode startNode;
    posNode endNode;
    int startId;
    int endId;
    list<posNode> nodes;
    ids.clear();
    //get all nodes
    nodes = getAllNode();
    //read file to get the nearest point of the start point
    ifstream startFile("data/map/start.txt");
    if (! startFile.is_open())
    {
        cout << "Error get the start data! Exit!";
        exit (1);
    }
    string str;
    startFile >> str;
    double startlat = atof(str.c_str());
    startFile >> str;
    double startlng = atof(str.c_str());
    startNode = getTheNearestNode(startlat, startlng);
    startId = startNode.id;
    //get the nearest of the end point by lat and lng
    endNode = getTheNearestNode(endlat, endlng);
    endId = endNode.id;
    //get the map data
    getMapData();
    //get the shorted path node id by floyd
    floyd();
    //get the detail info of the nodes
    if(dist[startId][endId]==INF) cout<<"No path"<<endl;
    else{
        ids.push_back(startId);
        output(startId,endId);
        list<int>::iterator iter = ids.begin();
        for(iter; iter!=ids.end(); iter ++)
        {
            pathNodes.push_back(getNodeData(*iter));
        }
    }

    return pathNodes;
}

list<posNode> getAllNode()
{
     char buffer[256];
     list<posNode> nodes;
     ifstream nodefile("data/map/node.txt");
     //ifstream nodefile("node.txt");
     if (! nodefile.is_open())
     {
         cout << "Error get all node data! Exit!";
         exit (1);
     }

     while (!nodefile.eof() )
     {
         nodefile.getline (buffer,100);
         string str = buffer;
         nodes.push_back(getNodeInfoByLine(str));
     }

     nodefile.close();
     return nodes;
 }

 posNode getNodeData(int id)
 {
     int i = 0;
     posNode node;
     list<posNode> nodes = getAllNode();
     list<posNode>::iterator iter = nodes.begin();
     for(i = 0; i < id - 1; i ++)
     {
         iter++ ;
     }
     node = toNode(iter);

     return node;
 }

 void getMapData(){
     char ch;
     int i, j;
     ifstream graphFile("data/map/graph.txt");
     if (! graphFile.is_open())
     {
         cout << "Error get the map data! Exit!";
         exit (1);
     }

    for(i=1;i<=NUM;i++)
     {
         for(j=1;j<=NUM;j++)
         {
             graphFile>>ch;
             map[i][j] = atoi(&ch);
             if(map[i][j] == 0){
                 map[i][j] = INF;
             }
         }
     }

     graphFile.close();
 }

posNode getTheNearestNode(double latitude, double longitude){
    posNode node;
    double tempdist;
    list<posNode> nodes = getAllNode();
    list<posNode>::iterator iter = nodes.begin();

    double mindist = GetDistance(latitude, longitude, iter->latitude, iter->longitude);
    node = toNode(iter);
    iter ++;
    for(iter; iter != nodes.end(); iter ++)
    {
        tempdist = GetDistance(latitude, longitude, iter->latitude, iter->longitude);
        if(tempdist <= mindist){
            mindist = tempdist;
            node = toNode(iter);
        }
    }
    return node;
 }

posNode toNode(list<posNode>::iterator iter){
    posNode node;

    node.id = iter->id;
    node.x = iter->x;
    node.y = iter->y;
    node.latitude = iter->latitude;
    node.longitude = iter->longitude;

    return node;
}

double GetDistance(double lat1, double lng1, double lat2, double lng2)
{
    double radLat1 = rad(lat1);
    double radLat2 = rad(lat2);
    double a = radLat1 - radLat2;
    double b = rad(lng1) - rad(lng2);


    double s = 2 * asin(sqrt(pow(sin(a/2),2) +
        cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)))* EARTH_RADIUS*1000;
    return s;
}

posNode getNodeInfoByLine(string str)
{
    posNode node;
    int posStart;
    int postEnd;

    posStart = 0;
    postEnd = str.find(" ",posStart);
    node.id = atoi(str.substr(posStart, postEnd).c_str());

    posStart = postEnd + 1;
    postEnd = str.find(" ",posStart);
    node.x = atoi(str.substr(posStart, postEnd).c_str());

    posStart = postEnd + 1;
    postEnd = str.find(" ",posStart);
    node.y = atoi(str.substr(posStart, postEnd).c_str());

    posStart = postEnd + 1;
    postEnd = str.find(" ",posStart);
    node.latitude = atof(str.substr(posStart, postEnd).c_str());

    posStart = postEnd + 1;
    postEnd = str.find(" ",posStart);
    node.longitude = atof(str.substr(posStart, postEnd).c_str());

    //cout << "id:" << node.id << ", x:" << node.x << ", y:" << node.y << ", latitude:" << node.latitude << ", longitude:" << node.longitude << endl;

    return node;
}

void floyd(){
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dist[i][j]=map[i][j],path[i][j]=0;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j],path[i][j]=k;
}

void output(int i,int j){
    if(i==j) return;
    if(path[i][j]==0) ids.push_back(j);
    else{
        output(i,path[i][j]);
        output(path[i][j],j);
    }
}
