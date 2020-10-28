#ifndef BEGIN_H
#define BEGIN_H

#include <QWidget>

namespace Ui {
class begin;
}

class begin : public QWidget
{
    Q_OBJECT

public:
    explicit begin(QWidget *parent = 0);
    ~begin();

private:
    Ui::begin *ui;

private slots:
    void on_begin_2_clicked();

    void on_continue_2_clicked();

protected:
    void paintEvent(QPaintEvent *event);
signals:
    void gamebegin(int );
};

#endif // BEGIN_H
