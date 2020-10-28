#ifndef SHOPBUY_H
#define SHOPBUY_H

#include <QWidget>
#include<QPixmap>
#include<QSpinBox>

namespace Ui {
class shopbuy;
}

class shopbuy : public QWidget
{
    Q_OBJECT

public:
    explicit shopbuy(QWidget *parent = 0);
    ~shopbuy();
    void deal();
    QPixmap picture[20]={QPixmap("../teamsource/carrot.png"),QPixmap("../teamsource/rice.png"),QPixmap("../teamsource/cabbage.png"),
                        QPixmap("../teamsource/potato.png"),QPixmap("../teamsource/eggplant.png"),QPixmap("../teamsource/maize.png"),
                        QPixmap("../teamsource/pumpkin.png"),QPixmap("../teamsource/watermelon.png"),QPixmap("../teamsource/clownfish.png"),
                        QPixmap("../teamsource/plaettetang.png"),QPixmap("../teamsource/butterflyfish.png"),QPixmap("../teamsource/tigerfish.png"),
                        QPixmap("../teamsource/parrotfish.png"),QPixmap("../teamsource/turtle.png"),QPixmap("../teamsource/goldfish.png"),
                        QPixmap("../teamsource/guppy.png"),QPixmap("../teamsource/chicken.png"),QPixmap("../teamsource/rabbit.png"),
                        QPixmap("../teamsource/sheep.png"),QPixmap("../teamsource/cow.png")};
    QString name[20]={"胡萝卜","水稻","大白菜","土豆","茄子","玉米","南瓜","西瓜",
                      "小丑鱼","蓝唐王鱼","蝶鱼","虎皮鱼","鹦鹉鱼","绿海龟","金鱼","孔雀鱼",
                     "鸡","兔子","羊","牛"};
    int i=0;
private:
    Ui::shopbuy *ui;

protected :
public slots:
private slots:
    void on_pushButton_surebuy_clicked();

signals:
    void surebuy();
};

#endif // SHOPBUY_H
