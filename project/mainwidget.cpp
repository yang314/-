#include "mainwidget.h"
#include "ui_mainwidget.h"
#include<QPushButton>
#include <QPainter>
#include <QPalette>
#include"data.h"
#include"QDebug"
#include"bag.h"
#include<QFile>
#include<QFileDialog>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    setWindowTitle("Happyland");
    widget_begin.show();
    farmwidget = new Farm(this);
    fishwidget = new Fish(this);
    pasturewidget = new Pasture(this);
    ui->setupUi(this);
    ui->stackedWidget->addWidget(farmwidget);
    ui->stackedWidget->addWidget(fishwidget);
    ui->stackedWidget->addWidget(pasturewidget);
    ui->stackedWidget->setCurrentWidget(farmwidget);
    ui->stackedWidget_2->setCurrentWidget(ui->buttonpage_farm);



    setinformation();

    connect(farmwidget,SIGNAL(signal_cost()),this,SLOT(setinformation()));
    connect(farmwidget,SIGNAL(signal_harvest()),this,SLOT(setinformation()));
    connect(fishwidget,SIGNAL(signal_cost()),this,SLOT(setinformation()));
    connect(fishwidget,SIGNAL(signal_harvest()),this,SLOT(setinformation()));

    connect(&widget_warehouse,SIGNAL(sold()),this,SLOT(setinformation()));
    connect(&widget_shop,SIGNAL(buy()),this,SLOT(setinformation()));

    connect(&widget_begin,SIGNAL(gamebegin(int)),this,SLOT(frombegin(int)));
}

void MainWidget::setinformation()
{
    ui->bar_prolevel->setMinimum(0);
    ui->bar_prolevel->setMaximum(Data::level*20+20);
    ui->bar_prolevel->setValue(Data::empirical);
    ui->label_level->setText(QString("<h1>Lv.%1</h1>").arg(Data::level));
    ui->label_money->setText(QString("<h1>%1元</h1>").arg(Data::money));
}

void MainWidget::timerEvent(QTimerEvent *)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(farmwidget->map[i][j]==2)
            {
                if(farmwidget->time[i][j] == Data::growtime[farmwidget->Index[i][j]])
                {
                    farmwidget->map[i][j]=3;
                    farmwidget->update();

                }
                else if(farmwidget->time[i][j] == Data::growtime[farmwidget->Index[i][j]]/3)
                {
                     farmwidget->map[i][j]=7;
                     farmwidget->update();

                }
                else if(farmwidget->time[i][j] == Data::growtime[farmwidget->Index[i][j]]/2)
                {
                    farmwidget->map[i][j]=6;
                     farmwidget->update();

                }
                else if(farmwidget->time[i][j] == Data::growtime[farmwidget->Index[i][j]]*3/4)
                {
                    farmwidget->map[i][j]=5;
                     farmwidget->update();

                }

                farmwidget->time[i][j]++;
            }
            if(fishwidget->map[i][j]==2)
            {
                if(fishwidget->time[i][j] == Data::growtime[fishwidget->Index[i][j]])
                {
                    fishwidget->map[i][j]=3;
                    fishwidget->update();

                }
                fishwidget->time[i][j]++;
            }
            if(pasturewidget->map[i][j]==2)
            {
                if(pasturewidget->time[i][j] == Data::growtime[pasturewidget->Index[i][j]])
                {
                    pasturewidget->map[i][j]=3;
                    pasturewidget->update();

                }
                if(pasturewidget->time[i][j] == Data::growtime[pasturewidget->Index[i][j]]/2)
                {
                    pasturewidget->map[i][j]=5;
                    pasturewidget->update();
                }
                pasturewidget->time[i][j]++;
            }
        }
    }

   /*运行测试
    for(int i=0;i<5;i++)
    {
        qDebug()<<pasturewidget->time[i][0]<<pasturewidget->time[i][1]<<pasturewidget->time[i][2]<<pasturewidget->time[i][3]<<"  "<<pasturewidget->map[i][0]<<pasturewidget->map[i][1]<<pasturewidget->map[i][2]<<pasturewidget->map[i][3];
    }
    qDebug()<<"_________________";*/

}


MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_button_farm_clicked()
{
    ui->stackedWidget->setCurrentWidget(farmwidget);
    ui->stackedWidget_2->setCurrentWidget(ui->buttonpage_farm);
}

void MainWidget::on_button_pasture_clicked()
{
    ui->stackedWidget->setCurrentWidget(pasturewidget);
    ui->stackedWidget_2->setCurrentWidget(ui->buttonpage_pasture);
}

void MainWidget::on_button_fish_clicked()
{
    ui->stackedWidget->setCurrentWidget(fishwidget);
    ui->stackedWidget_2->setCurrentWidget(ui->buttonpage_fish);
}

void MainWidget::on_shop_clicked()
{
    widget_shop.levelchange();
    widget_shop.show();
}

void MainWidget::on_warehouse_clicked()
{
    widget_warehouse.productchange();
    widget_warehouse.show();
}

void MainWidget::on_farmButton_bag_clicked()
{
    farmwidget->function=0;
    farmwidget->bag_farm.setpage(0);
    farmwidget->bag_farm.settext();
    farmwidget->bag_farm.show();
}

void MainWidget::on_farmButton_plant_clicked()
{
    farmwidget->function=0;
}

void MainWidget::on_farmButton_hoe_clicked()
{

    farmwidget->function=1;
}

void MainWidget::on_farmButton_water_clicked()
{
    farmwidget->function=2;
}

void MainWidget::on_farmButton_insect_clicked()
{
    farmwidget->function=3;
}

void MainWidget::on_farmButton_weeds_clicked()
{
    farmwidget->function=4;
}

void MainWidget::on_farmButton_harvrst_clicked()
{
    farmwidget->function=5;
}


void MainWidget::on_fishButton_bag_clicked()
{
    fishwidget->function=0;
    fishwidget->bag_fish.setpage(1);
    fishwidget->bag_fish.settext();
    fishwidget->bag_fish.show();
}

void MainWidget::on_fishButton_plant_clicked()
{
    fishwidget->function=0;
}

void MainWidget::on_fishButton_hoe_clicked()
{
    fishwidget->function=1;
}

void MainWidget::on_fishButton_water_clicked()
{
    fishwidget->function=3;
}

void MainWidget::on_fishButton_harvrst_clicked()
{
    fishwidget->function=2;
}


void MainWidget::on_pastureButton_bag_clicked()
{
    pasturewidget->function=0;
    pasturewidget->bag_pasture.setpage(2);
    pasturewidget->bag_pasture.settext();
    pasturewidget->bag_pasture.show();
}

void MainWidget::on_pastureButton_plant_clicked()
{
    pasturewidget->function=0;
}

void MainWidget::on_pastureButton_hoe_clicked()
{
    pasturewidget->function=1;
}

void MainWidget::on_pastureButton_clean_clicked()
{
    pasturewidget->function=3;
}

void MainWidget::on_pastureButton_vaccines_clicked()
{
    pasturewidget->function=4;
}

void MainWidget::on_pastureButton_harvrst_clicked()
{
    pasturewidget->function=2;
}

void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("../teamsource/main.jpg"));
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}
void MainWidget::closeEvent(QCloseEvent *)
{
    QFile file("./teamdata.txt");
    file.open(QIODevice::WriteOnly);

    file.write(QString::number(Data::level).toUtf8());
    file.write("\n");

    file.write(QString::number(Data::money).toUtf8());
    file.write("\n");

    file.write(QString::number(Data::empirical).toUtf8());
    file.write("\n");

    for(int i=0;i<20;i++)
    {
        file.write(QString::number(Data::seed[i]).toUtf8());
        file.write("\n");
    }

    for(int i=0;i<20;i++)
    {
        file.write(QString::number(Data::product[i]).toUtf8());
        file.write("\n");
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(farmwidget->map[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(farmwidget->time[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(farmwidget->Index[i][j]).toUtf8());
            file.write("\n");
        }
    }//farm

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(pasturewidget->map[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(pasturewidget->time[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(pasturewidget->Index[i][j]).toUtf8());
            file.write("\n");
        }
    }//pasture

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(fishwidget->map[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(fishwidget->time[i][j]).toUtf8());
            file.write("\n");
        }
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            file.write(QString::number(fishwidget->Index[i][j]).toUtf8());
            file.write("\n");
        }
    }

    file.close();
}
void MainWidget::frombegin(int t)
{
    if(t==1)
    {
        QFile file("./teamdata.txt");
        file.open(QIODevice::ReadOnly);
        QByteArray a;

        a=file.readLine();
        for(int i=0;;i++)
        {
            if(a[i]!='\n')
            Data::level=Data::level*10+int(a.at(i))-48;
            else
            break;
        }

        a=file.readLine();
        qDebug()<<a;
        Data::money=0;
        for(int i=0;;i++)
        {
            if(a[i]!='\n')
            Data::money=Data::money*10+int(a.at(i))-48;
            else
            break;
        }

        a=file.readLine();
        for(int i=0;;i++)
        {
            if(a[i]!='\n')
            Data::empirical=Data::empirical*10+int(a.at(i))-48;
            else
            break;
        }

        for(int j=0;j<20;j++)
        {
            a=file.readLine();
            for(int i=0;;i++)
            {
                if(a[i]!='\n')
                Data::seed[j]=Data::seed[j]*10+int(a.at(i))-48;
                else
                break;
            }
        }

        for(int j=0;j<20;j++)
        {
            a=file.readLine();
            for(int i=0;;i++)
            {
                if(a[i]!='\n')
                Data::product[j]=Data::product[j]*10+int(a.at(i))-48;
                else
                break;
            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                farmwidget->map[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    farmwidget->map[j][k]=farmwidget->map[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                farmwidget->time[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    farmwidget->time[j][k]=farmwidget->time[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                farmwidget->Index[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    farmwidget->Index[j][k]=farmwidget->Index[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }//fram


        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                pasturewidget->map[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    pasturewidget->map[j][k]=pasturewidget->map[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                pasturewidget->time[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    pasturewidget->time[j][k]=pasturewidget->time[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                pasturewidget->Index[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    pasturewidget->Index[j][k]=pasturewidget->Index[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }//pasture


        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                fishwidget->map[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    fishwidget->map[j][k]=fishwidget->map[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                fishwidget->time[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    fishwidget->time[j][k]=fishwidget->time[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        for(int j=0;j<5;j++)
        {
            for(int k=0;k<4;k++)
            {
                fishwidget->Index[j][k]=0;
                a=file.readLine();
                for(int i=0;;i++)
                {
                    if(a[i]!='\n')
                    fishwidget->Index[j][k]=fishwidget->Index[j][k]*10+int(a.at(i))-48;
                    else
                    break;
                }

            }
        }

        file.close();
    }
    widget_begin.hide();
    setinformation();
    this->show();
    timeid=this->startTimer(1000);
}

