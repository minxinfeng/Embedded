#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <fstream> //the header of file read and write
#include <list>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES//for using the PI
#include <math.h>
#include "posNode.h"
using namespace std;

/************************************************************************/
/* Author: Feng Xiangmin                                                */
/* Find the road from start to the end*/
/************************************************************************/

#define INF 100000//not connect directly
#define NUM 16 // the number of the Node
const double EARTH_RADIUS = 6371.004;//earth radius

int n=NUM,// the number of node
    path[NUM+1][NUM+1],// path[i][j]:the max id of the node in the road between i and j表示该路径中的最大顶点
    dist[NUM+1][NUM+1],//dist[j][j]:the shortest distance between i and j
    map[NUM+1][NUM+1];//map[i][j]: means weather i and j is connected, 0 is not, 1 is connected

list<posNode> nodes;//all nodes list
list<int> ids;//all the node ids

/************************************************************************/
/* get the path from start file to the end point by lat and lng         */
/************************************************************************/
list<posNode> getPath(double endlat, double endlng);

/************************************************************************/
/* get all the data info                                                */
/************************************************************************/
list<posNode> getAllNode();

/************************************************************************/
/* get the node detail data                                             */
/************************************************************************/
posNode getNodeData(int id);

/************************************************************************/
/* get the mapdata by reading the file                                  */
/************************************************************************/
void getMapData();

/************************************************************************/
/* get the nearest Node by latitude and longitude                       */
/* iterate all the node and find the nearest one*/
/************************************************************************/
posNode getTheNearestNode(double latitude, double longitude);

/************************************************************************/
/* change list<posNode>::iterator to posNode                            */
/************************************************************************/
posNode toNode(list<posNode>::iterator iter);

double rad(double d)
{
    return d *  M_PI/ 180.0;
}

/************************************************************************/
/* get the real distance of two point                                   */
/************************************************************************/
double GetDistance(double lat1, double lng1, double lat2, double lng2);

/************************************************************************/
/* split the string to get the info of the node                         */
/************************************************************************/
posNode getNodeInfoByLine(string str);

//最短路径算法
void floyd();

//get the path nodes ids
void output(int i,int j);

#endif // ROAD_H
