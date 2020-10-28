#ifndef BAG_H
#define BAG_H

#include <QWidget>

namespace Ui {
class Bag;
}

class Bag : public QWidget
{
    Q_OBJECT

public:
    void setpage(int x);
    int i,j;

    void settext();
    explicit Bag(QWidget *parent = 0);
    ~Bag();

signals:
    void signal_plant(int index,int i,int j);

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

private:
    Ui::Bag *ui;

protected:
    void paintEvent(QPaintEvent *event);
};


#endif // BAG_H
