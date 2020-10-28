#ifndef DATA_H
#define DATA_H
#include <qstring.h>
#include <qpixmap.h>
#include <QPixmap>
#include <QString>

class Data
{
public:
    Data();
public:
    static int level;      //角色等级
    static int money;      //金钱
    static int empirical;  //经验值

    static int cost[20];//进价
    static int price[20];//售价
    static int empirical_value[20];//产生经验值
    static int growtime[20];//成熟时间
    static int plantlevel[20];//购买所需等级
    static int seed[20];//种子，鱼苗，幼崽
    static int product[20];//成品
};

#endif // DATA_H
