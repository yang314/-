#include "warehouse.h"
#include "data.h"
#include "ui_warehouse.h"
#include <QPainter>

warehouse::warehouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warehouse)
{
    ui->setupUi(this);
    widget_waresold.hide();
    setWindowTitle("仓库");
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

    productchange();
    connect(&widget_waresold,SIGNAL(thingchange()),this,SLOT(productchange()));
}

warehouse::~warehouse()
{
    delete ui;
}

void warehouse::on_pushbutton_carrot_clicked()
{
    widget_waresold.i=0;
    widget_waresold.deal();
}

void warehouse::on_pushButton_rice_clicked()
{
    widget_waresold.i=1;
    widget_waresold.deal();
}

void warehouse::on_pushButton_cabbage_clicked()
{
    widget_waresold.i=2;
    widget_waresold.deal();
}

void warehouse::on_pushButton_potato_clicked()
{
    widget_waresold.i=3;
    widget_waresold.deal();
}

void warehouse::on_pushButton_eggplant_clicked()
{
    widget_waresold.i=4;
    widget_waresold.deal();
}

void warehouse::on_pushButton_maize_clicked()
{
    widget_waresold.i=5;
    widget_waresold.deal();
}

void warehouse::on_pushButton_pumpkin_clicked()
{
    widget_waresold.i=6;
    widget_waresold.deal();
}

void warehouse::on_pushButton_watermelon_clicked()
{
    widget_waresold.i=7;
    widget_waresold.deal();
}

void warehouse::on_pushButton_clownfish_clicked()
{
    widget_waresold.i=8;
    widget_waresold.deal();
}

void warehouse::on_pushButton_plaettetang_clicked()
{
    widget_waresold.i=9;
    widget_waresold.deal();
}

void warehouse::on_pushButton_butterflyfish_clicked()
{
    widget_waresold.i=10;
    widget_waresold.deal();
}

void warehouse::on_pushButton_tigerfish_clicked()
{
    widget_waresold.i=11;
    widget_waresold.deal();;
}

void warehouse::on_pushButton_parrotfish_clicked()
{
    widget_waresold.i=12;
    widget_waresold.deal();
}

void warehouse::on_pushButton_turtle_clicked()
{
    widget_waresold.i=13;
    widget_waresold.deal();
}

void warehouse::on_pushButton_goldfish_clicked()
{
    widget_waresold.i=14;
    widget_waresold.deal();
}

void warehouse::on_pushButton_guppy_clicked()
{
    widget_waresold.i=15;
    widget_waresold.deal();
}

void warehouse::on_pushButton_chicken_clicked()
{
    widget_waresold.i=16;
    widget_waresold.deal();
}

void warehouse::on_pushButton_ribbat_clicked()
{
    widget_waresold.i=17;
    widget_waresold.deal();
}

void warehouse::on_pushButton_sheep_clicked()
{
    widget_waresold.i=18;
    widget_waresold.deal();
}

void warehouse::on_pushButton_cow_clicked()
{
    widget_waresold.i=19;
    widget_waresold.deal();
}

void warehouse::productchange()
{
    ui->label_carrot->setText(QString("<h1>%1</h1>").arg(Data::product[0]));
    ui->label_rice->setText(QString("<h1>%1</h1>").arg(Data::product[1]));
    ui->label_cabbage->setText(QString("<h1>%1</h1>").arg(Data::product[2]));
    ui->label_potato->setText(QString("<h1>%1</h1>").arg(Data::product[3]));
    ui->label_eggplant->setText(QString("<h1>%1</h1>").arg(Data::product[4]));
    ui->label_maize->setText(QString("<h1>%1</h1>").arg(Data::product[5]));
    ui->label_pumpkin->setText(QString("<h1>%1</h1>").arg(Data::product[6]));
    ui->label_watermelon->setText(QString("<h1>%1</h1>").arg(Data::product[7]));
    ui->label_clownfish->setText(QString("<h1>%1</h1>").arg(Data::product[8]));
    ui->label_plaettetang->setText(QString("<h1>%1</h1>").arg(Data::product[9]));
    ui->label_butterflyfish->setText(QString("<h1>%1</h1>").arg(Data::product[10]));
    ui->label_tigerfish->setText(QString("<h1>%1</h1>").arg(Data::product[11]));
    ui->label_parrotfish->setText(QString("<h1>%1</h1>").arg(Data::product[12]));
    ui->label_turtle->setText(QString("<h1>%1</h1>").arg(Data::product[13]));
    ui->label_goldfish->setText(QString("<h1>%1</h1>").arg(Data::product[14]));
    ui->label_guppy->setText(QString("<h1>%1</h1>").arg(Data::product[15]));
    ui->label_chicken->setText(QString("<h1>%1</h1>").arg(Data::product[16]));
    ui->label_rabbit->setText(QString("<h1>%1</h1>").arg(Data::product[17]));
    ui->label_sheep->setText(QString("<h1>%1</h1>").arg(Data::product[18]));
    ui->label_cow->setText(QString("<h1>%1</h1>").arg(Data::product[19]));
    emit sold();
}
void warehouse::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("../teamsource/main.jpg"));
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}

