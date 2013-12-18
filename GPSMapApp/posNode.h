/************************************************************************/
/* author: FengXiangmin                                                 */
/* the basic data structure of the node*/
/************************************************************************/
#ifndef POSNODE_H
#define POSNODE_H

class posNode
{
    public:
        int id;//the unique id of the node
        int x;
        int y;
        float latitude;
        float longitude;

        posNode(void);
        virtual ~posNode(void);
};

#endif // POSNODE_H
