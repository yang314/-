#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<farm.h>
#include<fish.h>
#include<pasture.h>
#include<shop.h>
#include<warehouse.h>
#include<stdio.h>
#include<begin.h>


namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    int timeid;

private slots:

    void on_button_farm_clicked();

    void on_button_pasture_clicked();

    void on_button_fish_clicked();


    void on_shop_clicked();

    void on_warehouse_clicked();


    void on_farmButton_bag_clicked();

    void on_farmButton_plant_clicked();

    void on_farmButton_hoe_clicked();

    void on_farmButton_water_clicked();

    void on_farmButton_insect_clicked();

    void on_farmButton_weeds_clicked();

    void on_farmButton_harvrst_clicked();

    void on_fishButton_bag_clicked();

    void on_fishButton_plant_clicked();

    void on_fishButton_hoe_clicked();

    void on_fishButton_water_clicked();

    void on_fishButton_harvrst_clicked();

    void on_pastureButton_bag_clicked();

    void on_pastureButton_plant_clicked();

    void on_pastureButton_hoe_clicked();

    void on_pastureButton_clean_clicked();

    void on_pastureButton_vaccines_clicked();

    void on_pastureButton_harvrst_clicked();

private:
    Ui::MainWidget *ui;
    shop widget_shop;
    begin widget_begin;
    warehouse widget_warehouse;
    Farm *farmwidget;
    Fish *fishwidget;
    Pasture *pasturewidget;
signals:

protected:
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
public slots:
    void setinformation();
    void frombegin(int );

};

#endif // MAINWIDGET_H
