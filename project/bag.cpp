#include "bag.h"
#include "ui_bag.h"
#include "data.h"
#include <QPainter>

Bag::Bag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bag)
{
    ui->setupUi(this);
    setWindowTitle("背包");

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

    this->setFixedSize(800,577);
    this->setWindowModality(Qt::ApplicationModal);

   settext();
}

void Bag::settext()
{
    ui->label_carrot->setText(QString("<h1>%1</h1>").arg(Data::seed[0]));
    ui->label_rice->setText(QString("<h1>%1</h1>").arg(Data::seed[1]));
    ui->label_cabbage->setText(QString("<h1>%1</h1>").arg(Data::seed[2]));
    ui->label_potato->setText(QString("<h1>%1</h1>").arg(Data::seed[3]));
    ui->label_eggplant->setText(QString("<h1>%1</h1>").arg(Data::seed[4]));
    ui->label_maize->setText(QString("<h1>%1</h1>").arg(Data::seed[5]));
    ui->label_pumpkin->setText(QString("<h1>%1</h1>").arg(Data::seed[6]));
    ui->label_watermelon->setText(QString("<h1>%1</h1>").arg(Data::seed[7]));
    ui->label_clownfish->setText(QString("<h1>%1</h1>").arg(Data::seed[8]));
    ui->label_plaettetang->setText(QString("<h1>%1</h1>").arg(Data::seed[9]));
    ui->label_butterflyfish->setText(QString("<h1>%1</h1>").arg(Data::seed[10]));
    ui->label_tigerfish->setText(QString("<h1>%1</h1>").arg(Data::seed[11]));
    ui->label_parrotfish->setText(QString("<h1>%1</h1>").arg(Data::seed[12]));
    ui->label_turtle->setText(QString("<h1>%1</h1>").arg(Data::seed[13]));
    ui->label_goldfish->setText(QString("<h1>%1</h1>").arg(Data::seed[14]));
    ui->label_guppy->setText(QString("<h1>%1</h1>").arg(Data::seed[15]));
    ui->label_chicken->setText(QString("<h1>%1</h1>").arg(Data::seed[16]));
    ui->label_rabbit->setText(QString("<h1>%1</h1>").arg(Data::seed[17]));
    ui->label_sheep->setText(QString("<h1>%1</h1>").arg(Data::seed[18]));
    ui->label_cow->setText(QString("<h1>%1</h1>").arg(Data::seed[19]));
}

Bag::~Bag()
{
    delete ui;
}

void Bag::setpage(int x)
{
    ui->bag->setCurrentIndex(x);
}


void Bag::on_pushbutton_carrot_clicked()
{
    emit signal_plant(0,i,j);
}

void Bag::on_pushButton_rice_clicked()
{
    emit signal_plant(1,i,j);
}

void Bag::on_pushButton_cabbage_clicked()
{
    emit signal_plant(2,i,j);
}

void Bag::on_pushButton_potato_clicked()
{
    emit signal_plant(3,i,j);
}

void Bag::on_pushButton_eggplant_clicked()
{
    emit signal_plant(4,i,j);
}

void Bag::on_pushButton_maize_clicked()
{
    emit signal_plant(5,i,j);
}

void Bag::on_pushButton_pumpkin_clicked()
{
    emit signal_plant(6,i,j);
}

void Bag::on_pushButton_watermelon_clicked()
{
    emit signal_plant(7,i,j);
}

void Bag::on_pushButton_clownfish_clicked()
{
    emit signal_plant(8,i,j);
}

void Bag::on_pushButton_plaettetang_clicked()
{
    emit signal_plant(9,i,j);
}

void Bag::on_pushButton_butterflyfish_clicked()
{
    emit signal_plant(10,i,j);
}

void Bag::on_pushButton_tigerfish_clicked()
{
    emit signal_plant(11,i,j);
}

void Bag::on_pushButton_parrotfish_clicked()
{
    emit signal_plant(12,i,j);
}

void Bag::on_pushButton_turtle_clicked()
{
    emit signal_plant(13,i,j);
}

void Bag::on_pushButton_goldfish_clicked()
{
    emit signal_plant(14,i,j);
}

void Bag::on_pushButton_guppy_clicked()
{
    emit signal_plant(15,i,j);
}

void Bag::on_pushButton_chicken_clicked()
{
    emit signal_plant(16,i,j);
}

void Bag::on_pushButton_ribbat_clicked()
{
    emit signal_plant(17,i,j);
}

void Bag::on_pushButton_sheep_clicked()
{
    emit signal_plant(18,i,j);
}

void Bag::on_pushButton_cow_clicked()
{
    emit signal_plant(19,i,j);
}

void Bag::paintEvent(QPaintEvent *)
{

     QPainter painter(this);
     painter.drawPixmap(rect(), QPixmap("../teamsource/main.jpg"));
     QPalette pal = palette();
     pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
     setPalette(pal);

}
