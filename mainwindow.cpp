#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QRandomGenerator>
#include<QTime>
#include<QString>
#include<QVBoxLayout>
#include<QLayout>


//setting_pomodoro Timenumber;
int count = 0;
int check = 0;
const char* pics[] = {
    ":/pics/pics/1_forest.jpg",
    ":/pics/pics/2_snow.jpg",
    ":/pics/pics/study_2.jpg",
    ":/pics/pics/forestred.jpg",
    //":/pics/pics/himalayas.jpg.",
    ":/pics/pics/meguro_river.jpg",
    ":/pics/pics/mountains.jpg",
    ":/pics/pics/mountfuji.jpg",
    ":/pics/pics/mountyoshino.jpg",
    ":/pics/pics/turkey.jpg",
    ":/pics/pics/zhangjiajie.jpg"
};
const char* quotes[] = {
//    blockquote {
//               background-color: #f8f8f8;
//border-left: 5px solid #3498db;
//padding: 15px;
//margin: 10px 0;
//font-size: 18px;
//font-style: italic;
//font-family: 'Arial', sans-serif;
//color: #555;
//}
    "\"  Forge your relentless path.\"",
    "\"Fuel your relentless ambition\"",
    "\"Ignite the flame within\"",
    "\"Master the relentless pursuit.\"",
    "\"Craft a legacy daily.\"",
    "\"Crush goals with determination\"",
    "\"Seize success, leave impact\"",
    "\"Command your destiny fiercely\"",
    "\"Radiate passion, conquer challenges\"",
   "\"Elevate with unwavering effort.\""
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setWindowState(Qt::WindowMaximized); // Maximize and lock
//    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);


    int randomNumber = QRandomGenerator::global()->bounded(8);
    QString selectedPic = QString::fromUtf8(pics[randomNumber]);

    QPixmap pixmap(selectedPic);
    ui->label->setPixmap(pixmap);

   //int count2=0;




    // Initialize variables and connections
    second = 0;
    minute=0;

    breakMinutes = 0;
    breakSeconds = 0;
    elapsedTime = 0;
    progress = 0;
    ui->progressBar_6->setValue(progress);
    timer1.setInterval(1000);
    timer2.setInterval(1000);

    // Connect timer signals to slots
    connect(&timer1, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(&timer2, SIGNAL(timeout()), this, SLOT(breakTime()));
    connect(ui->progressBar_6, &QProgressBar::valueChanged, this, &MainWindow::updateLabel);
     connect(ui->progressBar_6, &QProgressBar::valueChanged, this, &MainWindow::showQuotes);



    connect(&timer3,SIGNAL(timeout()),this,SLOT(updateLabel()));



    ui->label->setScaledContents(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

namespace MyNamespace {
int getvalue(int value);
}
using  namespace MyNamespace;
void MainWindow::breakTime()
{
    breakSeconds = breakSeconds + 1;
    if (breakSeconds == 60) {
        breakMinutes += breakSeconds / 60;
        breakSeconds = breakSeconds % 60;
    }
    ui->break_sec_6->display(breakSeconds);
    ui->break_min_6->display(breakMinutes);

//    if(breakMinutes==1 && breakSeconds==0)
//    {
//        updateLabel();
//    }
    if (breakMinutes ==timeset_focus) {
        breakMinutes = 0;
        breakSeconds = 0;
        timer2.stop();
        timer1.start();
    }
}
//void MainWindow:: updateLabel_quote() {
//    // Get a random quote
//    const QString& randomQuote = getRandomQuote();

//    // Update the label with the random quote and progress value
//    ui->label_4->setText(randomQuote);
//}
//QVector<QString> quotes;



//QString getRandomQuote() {
//    const int randomIndex = rand() % quotes.size();
//    return quotes[randomIndex];
//}


void MainWindow::updateTime()
{
    ++second;
    if (second == 60) {
        minute += second / 60;
        second = second % 60;
    }
    ui->pomo_sec_6->display(second);
    ui->pomo_min_6->display(minute);
    /*if (minute==1 && second==0){
        updateLabel();
    }*/

    if (minute == timeset_focus) {
        minute = 0;
        second = 0;
        progress+=10;
        ui->progressBar_6->setValue(progress);

        if(progress == 100)
        {
            resetProgressBar(true);
        }

        timer1.stop();
        timer2.start();
    }
}




// Assuming progressBar is the name of your QProgressBar and ui->label is the QLabel
// Connect the valueChanged signal to a custom slot (e.g., updateLabel)

void MainWindow::resetProgressBar(bool flag)
{
    if(flag)
    {
        progress=0;
        ui->progressBar_6->setValue(progress);
        flag = false;
    }

}
// Slot function to update the QLabel with a new image
void MainWindow::updateLabel() {
    if (count < 10) {
        QString selectedPic = QString::fromUtf8(pics[count]);

        // Debug: Print selected image path
        qDebug() << "Selected Image:" << selectedPic;


        QPixmap changedMap(selectedPic);

        QSize labelSize = ui->label->size();

        // Debug: Print QLabel size
        qDebug() << "Label Size:" << labelSize;

        // Scale the image to fit within the QLabel while maintaining aspect ratio
        QPixmap scaledMap = changedMap.scaled(labelSize, Qt::KeepAspectRatio);

        ui->label->setPixmap(scaledMap);

        // Debug: Print count after setting pixmap
        qDebug() << "Count:" << count;

        count++;
    } else {
        count = 0;
        qDebug() << "Count reset to 0.";
    }
}





void MainWindow::on_pomoTimer_clicked()
{
    // Stop both timers before starting
    timer1.stop();
    timer2.stop();

    // Start the stopwatch when the push button is clicked
    timer1.start();
}

//void MainWindow::on_change_pomodoro_timer_clicked()
//{
//    second_window =new setting(this);
//    second_window ->show();
//}



void MainWindow::on_change_bg_6_clicked()
{
    if (count <10) {
        QString selectedPic = QString::fromUtf8(pics[count]);
        QPixmap changedMap(selectedPic);

        QSize labelSize = ui->label->size();
        qDebug() << "Label Size Before Scaling:" << labelSize;

        // Ensure the label is properly scaled with KeepAspectRatio
        ui->label->setScaledContents(true);
        ui->label->setPixmap(changedMap);

        labelSize = ui->label->size();
        qDebug() << "Label Size After Scaling:" << labelSize;

        count++;
    } else {
        count = 0;
    }
}



void MainWindow::on_spinBox_11_valueChanged(int arg1)
{
    timeset_focus=arg1;
}

void MainWindow::on_spinBox_12_valueChanged(int arg1)
{
    timeset_break=arg1;
}


void MainWindow::on_pomoTimer_12_clicked()
{
//timer3.start(1000);

    if (pauser==false)
    {
        timer3.start(slideshow_time);//2 min ko lai
        pauser= true;
              ui->pomoTimer_12->setText("pause");
    }
    else{
        pauser=false;
        timer3.stop();
               ui->pomoTimer_12->setText("unpause");
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int min = arg1;
    int milli;
    milli=min * 60000;
    slideshow_time=milli;
}



void MainWindow::showQuotes()
{

    QFrame * fm=new QFrame;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(fm);
    srand(QTime::currentTime().msec());

    // Get a random index for the quotes array
    int randomIndex = rand() % (sizeof(quotes) / sizeof(quotes[0]));

    // Create a QLabel with the randomly selected quote
    QLabel* btn1 = new QLabel(QString(quotes[randomIndex]));




    horizontalLayout->addWidget(btn1);

    ui->verticalLayout_4->addWidget(fm);
}


