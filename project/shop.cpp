#include "shop.h"
#include "data.h"
#include "ui_shop.h"
#include<QWidget>
#include <QPainter>
#include<QDebug>

shop::shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);
    setWindowTitle("商店");
    widget_shopbuy.hide();
    ui->pushbutton_carrot->setStyleSheet("QPushButton{border-image:url(../teamsource/carrot.png);}");
    ui->pushButton_cabbage->setStyleSheet("QPushButton{border-image:url(../teamsource/cabbage.png);}");
    ui->pushButton_rice->setStyleSheet("QPushButton{border-image:url(../teamsource/rice.png);}");
    ui->pushButton_potato->setStyleSheet("QPushButton{border-image:url(../teamsource/potato.png);}");
    ui->pushButton_watermelon->setStyleSheet("QPushButton{border-image:url(../teamsource/watermelon.png);}");
    ui->pushButton_maize->setStyleSheet("QPushButton{border-image:url(../teamsource/maize.png);}");
    ui->pushButton_pumpkin->setStyleSheet("QPushButton{border-image:url(../teamsource/pumpkin.png);}");
    ui->pushButton_eggplant->setStyleSheet("QPushButton{border-image:url(../teamsource/eggplant.png);}");

    ui->pushButton_clownfish->setStyleSheet("QPushButton{border-image:url(../teamsource/clownfish.png);}");
    ui->pushButton_plaettetang->setStyleSheet("QPushButton{border-image:url(../teamsource/plaettetang.png);}");
    ui->pushButton_butterflyfish->setStyleSheet("QPushButton{border-image:url(../teamsource/butterflyfish.png);}");
    ui->pushButton_parrotfish->setStyleSheet("QPushButton{border-image:url(../teamsource/parrotfish.png);}");
    ui->pushButton_turtle->setStyleSheet("QPushButton{border-image:url(../teamsource/turtle.png);}");
    ui->pushButton_goldfish->setStyleSheet("QPushButton{border-image:url(../teamsource/goldfish.png);}");
    ui->pushButton_guppy->setStyleSheet("QPushButton{border-image:url(../teamsource/guppy.png);}");
    ui->pushButton_tigerfish->setStyleSheet("QPushButton{border-image:url(../teamsource/tigerfish.png);}");

    ui->pushButton_chicken->setStyleSheet("QPushButton{border-image:url(../teamsource/chicken.png);}");
    ui->pushButton_ribbat->setStyleSheet("QPushButton{border-image:url(../teamsource/rabbit.png);}");
    ui->pushButton_sheep->setStyleSheet("QPushButton{border-image:url(../teamsource/sheep.png);}");
    ui->pushButton_cow->setStyleSheet("QPushButton{border-image:url(../teamsource/cow.png);}");

    this->setFixedSize(561,461);
    this->setWindowModality(Qt::ApplicationModal);
    ui->label_carrot->setScaledContents(true);
    ui->label_rice->setScaledContents(true);
    ui->label_cabbage->setScaledContents(true);
    ui->label_potato->setScaledContents(true);
    ui->label_eggplant->setScaledContents(true);
    ui->label_maize->setScaledContents(true);
    ui->label_pumpkin->setScaledContents(true);
    ui->label_watermelom->setScaledContents(true);
    ui->label_clownfish->setScaledContents(true);
    ui->label_plaettetang->setScaledContents(true);
    ui->label_butterflyfisn->setScaledContents(true);
    ui->label_tigerfish->setScaledContents(true);
    ui->label_parrot->setScaledContents(true);
    ui->label_turtle->setScaledContents(true);
    ui->label_goldfish->setScaledContents(true);
    ui->label_guppy->setScaledContents(true);
    ui->label_chicken->setScaledContents(true);
    ui->label_rabbit->setScaledContents(true);
    ui->label_sheep->setScaledContents(true);
    ui->label_cow->setScaledContents(true);
    levelchange();
    connect(&widget_shopbuy,SIGNAL(surebuy()),this,SLOT(havebuy()));
}

shop::~shop()
{
    delete ui;
}

void shop::havebuy()
{
    emit buy();
}

void shop::on_pushbutton_carrot_clicked()
{
    widget_shopbuy.i=0;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_rice_clicked()
{
    widget_shopbuy.i=1;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_cabbage_clicked()
{
    widget_shopbuy.i=2;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_potato_clicked()
{
    widget_shopbuy.i=3;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_eggplant_clicked()
{
    widget_shopbuy.i=4;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_maize_clicked()
{
    widget_shopbuy.i=5;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_pumpkin_clicked()
{
    widget_shopbuy.i=6;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_watermelon_clicked()
{
    widget_shopbuy.i=7;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_clownfish_clicked()
{
    widget_shopbuy.i=8;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_plaettetang_clicked()
{
    widget_shopbuy.i=9;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_butterflyfish_clicked()
{
    widget_shopbuy.i=10;
   if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_tigerfish_clicked()
{
    widget_shopbuy.i=11;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_parrotfish_clicked()
{
    widget_shopbuy.i=12;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_turtle_clicked()
{
    widget_shopbuy.i=13;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_goldfish_clicked()
{
    widget_shopbuy.i=14;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_guppy_clicked()
{
    widget_shopbuy.i=15;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_chicken_clicked()
{
    widget_shopbuy.i=16;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_ribbat_clicked()
{
    widget_shopbuy.i=17;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_sheep_clicked()
{
    widget_shopbuy.i=18;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }
}

void shop::on_pushButton_cow_clicked()
{
    widget_shopbuy.i=19;
    if(Data::level>=Data::plantlevel[widget_shopbuy.i])
    {
    widget_shopbuy.deal();
    widget_shopbuy.show();
    }

}

void shop::levelchange()
{
    if(Data::level>=Data::plantlevel[0])
    ui->label_carrot->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[0]));
    else
    ui->label_carrot->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[0]));

    if(Data::level>=Data::plantlevel[1])
    ui->label_rice->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[1]));
    else
    ui->label_rice->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[1]));

    if(Data::level>=Data::plantlevel[2])
    ui->label_cabbage->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[2]));
    else
    ui->label_cabbage->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[2]));

    if(Data::level>=Data::plantlevel[3])
    ui->label_potato->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[3]));
    else
    ui->label_potato->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[3]));

    if(Data::level>=Data::plantlevel[4])
    ui->label_eggplant->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[4]));
    else
    ui->label_eggplant->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[4]));

    if(Data::level>=Data::plantlevel[5])
    ui->label_maize->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[5]));
    else
    ui->label_maize->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[5]));

    if(Data::level>=Data::plantlevel[6])
    ui->label_pumpkin->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[6]));
    else
    ui->label_pumpkin->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[6]));

    if(Data::level>=Data::plantlevel[7])
    ui->label_watermelom->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[7]));
    else
    ui->label_watermelom->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[7]));

    if(Data::level>=Data::plantlevel[8])
    ui->label_clownfish->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[8]));
    else
    ui->label_clownfish->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[8]));

    if(Data::level>=Data::plantlevel[9])
    ui->label_plaettetang->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[9]));
    else
    ui->label_plaettetang->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[9]));

    if(Data::level>=Data::plantlevel[10])
    ui->label_butterflyfisn->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[10]));
    else
    ui->label_butterflyfisn->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[10]));

    if(Data::level>=Data::plantlevel[11])
    ui->label_tigerfish->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[11]));
    else
    ui->label_tigerfish->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[11]));

    if(Data::level>=Data::plantlevel[12])
    ui->label_parrot->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[12]));
    else
    ui->label_parrot->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[12]));

    if(Data::level>=Data::plantlevel[13])
    ui->label_turtle->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[13]));
    else
    ui->label_turtle->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[13]));

    if(Data::level>=Data::plantlevel[14])
    ui->label_goldfish->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[14]));
    else
    ui->label_goldfish->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[14]));

    if(Data::level>=Data::plantlevel[15])
    ui->label_guppy->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[15]));
    else
    ui->label_guppy->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[15]));

    if(Data::level>=Data::plantlevel[16])
    ui->label_chicken->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[16]));
    else
    ui->label_chicken->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[16]));

    if(Data::level>=Data::plantlevel[17])
    ui->label_rabbit->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[17]));
    else
    ui->label_rabbit->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[17]));

    if(Data::level>=Data::plantlevel[18])
    ui->label_sheep->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[18]));
    else
    ui->label_sheep->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[18]));

    if(Data::level>=Data::plantlevel[19])
    ui->label_cow->setText(QString("<h1>￥:%1</h1>").arg(Data::cost[19]));
    else
    ui->label_cow->setText(QString("<h1>%1级解锁</h1>").arg(Data::plantlevel[19]));
}

void shop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("../teamsource/main.jpg"));
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}
