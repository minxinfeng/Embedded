GPSMapProject
======

The final project about the Embedded System & Embedded Linux Development Class: GPS Location and Calculation Route Project


Project Requirement    

1.  make the map data.
	* map format: make your university campus map by the specific  format( should include  longitude and latitude ). 
	* construct road network.    
	* map block:  divide map into some blocks averagely.
2. load the map block which the current point belongs to in the screen when moving GPS.
3. show latitude and longitude of the current point in the screen  when moving GPS. 
4. calculate the route of start point and end point.
	* if there is no enough power cord, you may save the start point to file, when restart ARM board load the start point again, then calculate the rout after set the end piont.

*******
subProject
------
The process flow as following:  
	

1. Show latitude and longitude of the current point in the screen  when moving GPS. When click the "start" button,capture the position data: latitude and longitude, and save these data into file "/data/map/start.txt", and marked this point as the start position on the map.
	
2. When click "stop" button, find the road from start to the end. Show the road and mark the end position on the map.

### get the road
How to get the road?
	
1. Read all the nodes info we collected before from the file "data/map/node.txt", which save the info of the posNode:
```
	int id;		//the unique id of the node
    int x;
	int y;
	float latitude;
	float longitude;
```
 All the node info will store in: list<posNode> nodes
	
2. Read all the map info from file "/data/map/graph.txt", and all the data store in a two-dimensional array -- map[i][j]: means weather i and j is connected, 0 is not, 1 is connected.
	
3. Read file "/data/map/start.txt" to get the start position, and find the nearest point of the start point.
	
4. Find the nearest node we collected of the start node and end node.
	
5. Get the shorted path node id by floyd algorithm， all the ids store in: list<int> ids;
	
6. Get the detail info of the nodes and return the list<posNode> pathNodes