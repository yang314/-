#ifndef FARM_H
#define FARM_H

#include <QWidget>
#include <QImage>
#include "bag.h"

namespace Ui {
class Farm;
}

class Farm : public QWidget
{
    Q_OBJECT

public:
    int map[5][4];                          /*地图状态
                                             * 0：未开发
                                             * 1：开发的土地
                                             * 2：已种植
                                             * 3：可采摘
                                             * 4：需耕地
                                             * 5：需除草
                                             * 6：需除虫
                                             * 7：需浇水
                                             */

    int function=0;                         /* 功能键
                                             * 0：点击已开发的土地，进行种植
                                             * 1：铲地：对未开发的土地进行开垦，对需要耕地的土地进行耕地，将已种植的土地的植物铲除
                                             * 2：浇水
                                             * 3: 除虫
                                             * 4：除草
                                             * 5：收获
                                             */
    int time[5][4];                      //每块地的种植时间
    int landlevel[5][4]={{0,0,2,2},{0,0,3,3},{4,4,5,5},{6,6,7,7},{8,9,10,11}};
    int Index[5][4];
    Bag bag_farm;

    QPixmap picture[20]={QPixmap("../teamsource/carrot.png"),QPixmap("../teamsource/rice.png"),QPixmap("../teamsource/cabbage.png"),
                        QPixmap("../teamsource/potato.png"),QPixmap("../teamsource/eggplant.png"),QPixmap("../teamsource/maize.png"),
                        QPixmap("../teamsource/pumpkin.png"),QPixmap("../teamsource/watermelon.png"),QPixmap("../teamsource/clownfish.png"),
                        QPixmap("../teamsource/plaettetang.png"),QPixmap("../teamsource/butterflyfish.png"),QPixmap("../teamsource/tigerfish.png"),
                        QPixmap("../teamsource/parrotfish.png"),QPixmap("../teamsource/turtle.png"),QPixmap("../teamsource/goldfish.png"),
                        QPixmap("../teamsource/guppy.png"),QPixmap("../teamsource/chicken.png"),QPixmap("../teamsource/rabbit.png"),
                        QPixmap("../teamsource/sheep.png"),QPixmap("../teamsource/cow.png")};


    explicit Farm(QWidget *parent = 0);
    ~Farm();

private:
    Ui::Farm *ui;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void signal_cost();
    void signal_harvest();
public slots:
    void slot_plant(int index,int i,int j);

};

#endif // FARM_H
