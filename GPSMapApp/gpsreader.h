/*
 *
 *
 */
#ifndef GPSREADER_H
#define GPSREADER_H

class GPSReader
{
public:
    GPSReader();
    int startFD();
    int parseNE( char* buff );
    int set_opt( int fd, int nSpeed, int nBits, char nEvent, int nStop );
    int writeToFile();
    double getLongitude(){return m_longitude; }
    double getLatitude(){return m_latitude; }
private:
    double m_longitude;
    double m_latitude;
};

#endif // GPSREADER_H
