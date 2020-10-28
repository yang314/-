#include "farm.h"
#include "ui_farm.h"
#include "data.h"
#include "bag.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMessageBox>
#include "mainwidget.h"

Farm::Farm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Farm)
{
    ui->setupUi(this);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            map[i][j]=0;
            time[i][j]=0;
            Index[i][j]=0;
        }
    }
    map[0][0]=map[1][0]=map[0][1]=map[1][1]=1;


    connect(&bag_farm,SIGNAL(signal_plant(int,int,int)),this,SLOT(slot_plant(int,int,int)));
}

Farm::~Farm()
{
    delete ui;
}

void Farm::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font1("宋体",23,QFont::Bold,true);
    QPen pen1;
    pen1.setColor(Qt::red);
    painter.setFont(font1);
    painter.setPen(pen1);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        { 
            if(map[i][j] == 0)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/grassland.jpg"));
                switch (i){
                case 0:
                        painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/board1.png"));
                    break;
                case 1:
                        painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/board2.png"));
                    break;
                case 2:
                        painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/board3.png"));
                    break;
                case 3:
                        painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/board4.png"));
                    break;
                case 4:
                        painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/board5.png"));
                    break;
                default:
                    break;
                }
            }
            else
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/soil.jpg"));
            if(map[i][j] == 2)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, picture[Index[i][j]]);
            }
            if(map[i][j] == 3)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, picture[Index[i][j]]);
                painter.drawText(i*width()/5+6,(j+1)*height()/4-6, tr("可采摘"));
            }
            if(map[i][j] == 4)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, QPixmap("../teamsource/badplant.png"));
                painter.drawText(i*width()/5+6,(j+1)*height()/4-6, tr("需耕地"));
            }
            if(map[i][j] == 5)
            {

                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, picture[Index[i][j]]);
                painter.drawPixmap((i+1)*width()/5-50,j*height()/4, 50,50, QPixmap("../teamsource/deedweed.png"));
                painter.drawText(i*width()/5+6,(j+1)*height()/4-6, tr("需除草"));
            }
            if(map[i][j] == 6)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, picture[Index[i][j]]);
                painter.drawPixmap((i+1)*width()/5-50,j*height()/4, 50,50, QPixmap("../teamsource/insect.png"));
                painter.drawText(i*width()/5+6,(j+1)*height()/4-6, tr("需除虫"));
            }
            if(map[i][j] == 7)
            {
                painter.drawPixmap(i*width()/5,j*height()/4, width()/5,height()/4, picture[Index[i][j]]);
                painter.drawPixmap((i+1)*width()/5-50,j*height()/4, 50,50, QPixmap("../teamsource/needwater.png"));
                painter.drawText(i*width()/5+6,(j+1)*height()/4-6, tr("需浇水"));
            }
        }
    }
    if(map[0][2]==0) painter.drawText(0*width()/5+15,3*height()/4-6, tr("需等级2"));
    if(map[0][3]==0) painter.drawText(0*width()/5+15,4*height()/4-6, tr("需等级2"));
    if(map[1][2]==0) painter.drawText(1*width()/5+15,3*height()/4-6, tr("需等级3"));
    if(map[1][3]==0) painter.drawText(1*width()/5+15,4*height()/4-6, tr("需等级3"));
    if(map[2][0]==0) painter.drawText(2*width()/5+15,1*height()/4-6, tr("需等级4"));
    if(map[2][1]==0) painter.drawText(2*width()/5+15,2*height()/4-6, tr("需等级4"));
    if(map[2][2]==0) painter.drawText(2*width()/5+15,3*height()/4-6, tr("需等级5"));
    if(map[2][3]==0) painter.drawText(2*width()/5+15,4*height()/4-6, tr("需等级5"));
    if(map[3][0]==0) painter.drawText(3*width()/5+15,1*height()/4-6, tr("需等级6"));
    if(map[3][1]==0) painter.drawText(3*width()/5+15,2*height()/4-6, tr("需等级6"));
    if(map[3][2]==0) painter.drawText(3*width()/5+15,3*height()/4-6, tr("需等级7"));
    if(map[3][3]==0) painter.drawText(3*width()/5+15,4*height()/4-6, tr("需等级7"));
    if(map[4][0]==0) painter.drawText(4*width()/5+15,1*height()/4-6, tr("需等级8"));
    if(map[4][1]==0) painter.drawText(4*width()/5+15,2*height()/4-6, tr("需等级9"));
    if(map[4][2]==0) painter.drawText(4*width()/5+6,3*height()/4-6, tr("需等级10"));
    if(map[4][3]==0) painter.drawText(4*width()/5+6,4*height()/4-6, tr("需等级11"));


}


void Farm::mousePressEvent(QMouseEvent *event)
{
    int i=event->x()*5/width();
    int j=event->y()*4/height();
    switch (function) {
    case 0:
       if(map[i][j] == 1)
        {
            bag_farm.setpage(0);
            bag_farm.i=i;
            bag_farm.j=j;
            bag_farm.settext();
            bag_farm.show();
        }
        else
            return;
        break;
    case 1:
        if(map[i][j] == 0)
        {
            if(landlevel[i][j] > Data::level)
            {
                QMessageBox::information(this,"提示","等级不足");
                return;
            }
            else
            {
                if(Data::money-100*(i+1)>=0)
                {
                    map[i][j]=1;
                    Data::money-=100*(i+1);
                    emit signal_cost();
                }
                else
                {
                    QMessageBox::information(this,"提示","金钱不足");
                    return;
                }
            }
        }
        else if(map[i][j] == 2||map[i][j] == 5||map[i][j] == 6||map[i][j] == 7)
        {
            //提示窗口:是否铲除植物
            int ret = QMessageBox::question(this,"提示","是否要铲除植物?");
            switch (ret) {
            case QMessageBox::Yes:
                map[i][j]=1;
                time[i][j]=0;
                break;
            case QMessageBox::No:
                return;
            default:
                break;
            }
        }
        else if(map[i][j] == 4)
        {
            map[i][j]=1;
        }
        break;
    case 2:
        if(map[i][j] == 7)
        {
            map[i][j]=2;
        }
        else if(map[i][j]!=0)
        {
            QMessageBox::information(this,"提示","该地不需要浇水");
            return;
        }
        break;
    case 3:
        if(map[i][j] == 6)
        {
            map[i][j]=2;
        }
        else if(map[i][j]!=0)
        {
            QMessageBox::information(this,"提示","该地不需要除虫");
            return;
        }
        break;
    case 4:
        if(map[i][j] == 5)
        {
            map[i][j]=2;
        }
        else if(map[i][j]!=0)
        {
            QMessageBox::information(this,"提示","该地不需要除草");
            return;
        }
        break;
    case 5:
        if(map[i][j] == 3)
        {
            map[i][j]=4;
            time[i][j]=0;
            Data::product[Index[i][j]]++;
            Data::empirical+=Data::empirical_value[Index[i][j]];
            if(Data::empirical>=Data::level*20+20)
            {
                Data::empirical-=Data::level*20+20;
                Data::level++;
            }
            emit signal_harvest();
        }
        else if(map[i][j]!=0)
        {
            QMessageBox::information(this,"提示","该地还不能收获");
            return;
        }
    default:
        break;
    }
    update();
}

void Farm::slot_plant(int index, int i, int j)
{
    if(map[i][j] == 2) return;
    if(Data::seed[index] == 0)
    {
        QMessageBox::information(NULL,"提示","储量不足");
        return;
    }
    else
    {
        Index[i][j]=index;
        map[i][j]=2;
        Data::seed[index]--;
        bag_farm.hide();
    }
}



