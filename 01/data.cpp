#include "data.h"

gamedata::gamedata(QObject *parent) :
    QObject(parent)
{
    //if having towers, the number of the place will be 100
    for(int i=0;i<=8;i++)
    {
        a[0][0][i]=1;
        a[0][1][i]=0;
        a[0][2][i]=0;
        a[0][3][i]=0;
        a[0][4][i]=0;
    }
    int b[5][9]={0,0,0,0,1,1,1,1,1,
                 0,0,0,0,1,0,0,0,0,
                 0,0,1,1,1,0,0,0,0,
                 1,1,1,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,0};
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=4;j++)
        {
            a[1][j][i]=b[j][i];
            a[2][j][i]=b[j][i];
        }
    }
}
