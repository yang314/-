#include "begin.h"
#include "ui_begin.h"
#include <QPainter>

begin::begin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::begin)
{
    ui->setupUi(this);
    setWindowTitle("Happyland");
}

begin::~begin()
{
    delete ui;
}

void begin::on_begin_2_clicked()
{
    emit gamebegin(0);
}

void begin::on_continue_2_clicked()
{
    emit gamebegin(1);
}

void begin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("../teamsource/happyland.jpg"));
}
