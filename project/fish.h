#ifndef FISH_H
#define FISH_H

#include <QWidget>
#include "bag.h"

namespace Ui {
class Fish;
}

class Fish : public QWidget
{
    Q_OBJECT

public:

    int map[5][4];                               /*地图状态
                                                  *0：未开发
                                                  *1：已开发
                                                  *2: 已养殖
                                                  *3：可收获
                                                  *4：需换水
                                                  */
    int function=0;                              /*功能键
                                                  *0：投放幼鱼
                                                  *1：开发鱼塘或放生鱼
                                                  *2：收获
                                                  *3：换水
                                                  */

    int time[5][4];
    int landlevel[5][4]={{0,0,2,2},{0,0,3,3},{4,4,5,5},{6,6,7,7},{8,9,10,11}};
    int Index[5][4];

    Bag bag_fish;
    QPixmap picture[20]={QPixmap("../teamsource/carrot.png"),QPixmap("../teamsource/rice.png"),QPixmap("../teamsource/cabbage.png"),
                        QPixmap("../teamsource/potato.png"),QPixmap("../teamsource/eggplant.png"),QPixmap("../teamsource/maize.png"),
                        QPixmap("../teamsource/pumpkin.png"),QPixmap("../teamsource/watermelon.png"),QPixmap("../teamsource/clownfish.png"),
                        QPixmap("../teamsource/plaettetang.png"),QPixmap("../teamsource/butterflyfish.png"),QPixmap("../teamsource/tigerfish.png"),
                        QPixmap("../teamsource/parrotfish.png"),QPixmap("../teamsource/turtle.png"),QPixmap("../teamsource/goldfish.png"),
                        QPixmap("../teamsource/guppy.png"),QPixmap("../teamsource/chicken.png"),QPixmap("../teamsource/rabbit.png"),
                        QPixmap("../teamsource/sheep.png"),QPixmap("../teamsource/cow.png")};
    explicit Fish(QWidget *parent = 0);
    ~Fish();

private:
    Ui::Fish *ui;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void signal_cost();
    void signal_harvest();
public slots:
    void slot_plant(int index,int i,int j);

};

#endif // FISH_H
