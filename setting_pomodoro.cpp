#include "setting_pomodoro.h"
#include "ui_setting_pomodoro.h"


setting_pomodoro::setting_pomodoro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting_pomodoro)
{
    ui->setupUi(this);
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->time_setter,SLOT(setValue(int)));
}

setting_pomodoro::~setting_pomodoro()
{
    delete ui;
}




void setting_pomodoro::on_spinBox_valueChanged(int arg1)
{
    timenumber=arg1;
}

