/*********************************************************************/
/* Author:Yuting Chen                                                */
/* Gps model:                                                        */
/* 1 communicate with GPS to get Lontitude and Latitude              */
/* 2 function to write current Lontitude and Latitude to file        */
/*********************************************************************/
#ifndef GPSREADER_H
#define GPSREADER_H

class GPSReader
{
public:
    GPSReader();

    /* open GPS Fd and return it */
    int startFD();
    /* write current lontitude and latitude to file */
    int writeToFile();
    /* parse data from Gps output to get lonitude and latitude */
    int parseNE( char* buff );
    /* function to open Gps fd */
    int set_opt( int fd, int nSpeed, int nBits, char nEvent, int nStop );

    double getLongitude(){return m_longitude; }
    double getLatitude(){return m_latitude; }
private:
    double m_longitude;
    double m_latitude;
};

#endif // GPSREADER_H
