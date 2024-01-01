#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//  void on_backChange_clicked();
    void updateLabel();

private slots:
    void on_pomoTimer_clicked();
    void updateTime();
    void breakTime();
//    void updateLabel_quote();
//    QString getRandomQuote();

    //void on_change_pomodoro_timer_clicked();

    //void on_change_bg_clicked();

    void on_change_bg_6_clicked();

    void on_spinBox_11_valueChanged(int arg1);

    void on_spinBox_12_valueChanged(int arg1);

    void on_pomoTimer_12_clicked();
    void resetProgressBar(bool flag);


    void showQuotes();
    void on_spinBox_valueChanged(int arg1);






    //void on_progressBar_6_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //setting *second_window;


    QTimer timer1,timer2,timer3;
    int newValue;
    short int minute;
    short int second;
    int breakMinutes;
    int breakSeconds;
    int elapsedTime;
    int progress;
    QTimer *breakTimer;
    bool pauser;
    int timeset_focus;
    int timeset_break;
    int slideshow_time;
      bool show_quote;
//    setting *timenumber =timenumber;
//    std::string improvementQuotes;


};
#endif // MAINWINDOW_H
