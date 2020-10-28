#include "data.h"
#include <qstring.h>
#include <qpixmap.h>
#include <QPixmap>
#include <QString>
Data::Data()
{

}

int Data::level=0;
int Data::money=100;
int Data::empirical=0;
int Data::cost[]={10,3,5,5,8,6,5,2,4,5,5,5,12,10,15,20,6,10,15,15};
int Data::price[]={25,5,12,10,20,12,13,12,12,14,15,12,30,24,30,45,15,22,35,30};
int Data::empirical_value[]={6,2,3,4,5,4,4,3,4,5,4,6,8,5,12,16,4,8,12,15};
int Data::growtime[]={30,15,20,20,25,25,30,30,25,30,30,35,35,50,45,45,20,30,35,35};
int Data::plantlevel[]={0,0,0,1,2,3,4,5,0,2,3,4,7,7,9,11,0,2,4,6};
int Data::seed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Data::product[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
