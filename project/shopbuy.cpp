#include "shopbuy.h"
#include "data.h"
#include "ui_shopbuy.h"
#include<QDebug>
#include<QSpinBox>
#include<QMessageBox>
#include<QDialog>

shopbuy::shopbuy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shopbuy)
{
    ui->setupUi(this);
    setWindowTitle("详细信息");
    this->setFixedSize(410,319);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->spinBox,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int j)
    {
        ui->label_expenditure->setText(QString("<h1>花费 : %1</h1>").arg(Data::cost[i]*j));
    });
}

shopbuy::~shopbuy()
{
    delete ui;
}

void shopbuy::deal()
{
    ui->label_cost->setText(QString("<h1>单价:%1元</h1>").arg(Data::cost[i]));
    ui->label_empirical->setText(QString("<h1>收获经验 : %1</h1>").arg(Data::empirical_value[i]));
    ui->label_growtime->setText(QString("<h1>成熟时间 : %1</h1>").arg(Data::growtime[i]));
    ui->label_price->setText(QString("<h1>预计收入 : %1</h1>").arg(Data::price[i]));
    ui->label_level->setText(QString("<h1>种植等级 : %1</h1>").arg(Data::plantlevel[i]));
    ui->label_name->setText(name[i]);
    ui->label_picture->setPixmap(picture[i]);
    ui->label_picture->setScaledContents(true);
    ui->spinBox->setRange(1,Data::money/Data::cost[i]);
    ui->label_tip->setText(QString("<h1>购买数量:1~%1</h1>").arg(Data::money/Data::cost[i]));
    ui->label_expenditure->setText(QString("<h1>花费 : %1元</h1>").arg(Data::cost[i]*ui->spinBox->value()));
}


void shopbuy::on_pushButton_surebuy_clicked()
{
    Data::money=Data::money-ui->spinBox->value()*Data::cost[i];
    Data::seed[i]+=ui->spinBox->value();
    emit surebuy();
    this->hide();
}
