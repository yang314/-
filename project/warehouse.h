#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QWidget>
#include"waresold.h"

namespace Ui {
class warehouse;
}

class warehouse : public QWidget
{
    Q_OBJECT

public:
    explicit warehouse(QWidget *parent = 0);
    ~warehouse();


private:
    Ui::warehouse *ui;
    waresold widget_waresold;
protected:
    void paintEvent(QPaintEvent *event);
signals:
    void sold();
public slots:
    void productchange();
private slots:
    void on_pushbutton_carrot_clicked();
    void on_pushButton_rice_clicked();
    void on_pushButton_cabbage_clicked();
    void on_pushButton_potato_clicked();
    void on_pushButton_eggplant_clicked();
    void on_pushButton_maize_clicked();
    void on_pushButton_pumpkin_clicked();
    void on_pushButton_watermelon_clicked();
    void on_pushButton_clownfish_clicked();
    void on_pushButton_plaettetang_clicked();
    void on_pushButton_butterflyfish_clicked();
    void on_pushButton_tigerfish_clicked();
    void on_pushButton_parrotfish_clicked();
    void on_pushButton_turtle_clicked();
    void on_pushButton_goldfish_clicked();
    void on_pushButton_guppy_clicked();
    void on_pushButton_chicken_clicked();
    void on_pushButton_ribbat_clicked();
    void on_pushButton_sheep_clicked();
    void on_pushButton_cow_clicked();
};

#endif // WAREHOUSE_H
