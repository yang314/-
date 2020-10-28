#include "waresold.h"
#include "ui_waresold.h"
#include"data.h"
#include<QSpinBox>
#include<QMessageBox>

waresold::waresold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waresold)
{
    ui->setupUi(this);
    setWindowTitle("详细信息");
    this->setFixedSize(468,414);
    this->setWindowModality(Qt::ApplicationModal);
    connect(ui->spinBox,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=](int j)
    {
        ui->label_earn->setText(QString("<h1>总计收入:%1</h1>").arg(Data::price[i]*j));
    });
}

waresold::~waresold()
{
    delete ui;
}

void waresold::deal()
{
    if(Data::product[i]!=0)
    {
    ui->label_price->setText(QString("<h1>单个售价:%1元</h1>").arg(Data::price[i]));
    ui->label_earn->setText(QString("<h1>总计收入:%1元</h1").arg(Data::price[i]));
    ui->label_name->setText(name[i]);
    ui->label_picture->setPixmap(picture[i]);
    ui->label_picture->setScaledContents(true);
    ui->spinBox->setRange(1,Data::product[i]);
    ui->label_tip->setText(QString("<h1>卖出数量:1~%1</h1>").arg(Data::product[i]));
    this->show();
    }
    else
    {
        int ok1=QMessageBox::information(this,"tips","该产品数量为0");
    }
}

void waresold::on_pushButton_sold_clicked()
{
    Data::money+=ui->spinBox->value()*Data::price[i];
    Data::product[i]-=ui->spinBox->value();
    emit thingchange();
    this->hide();
}
