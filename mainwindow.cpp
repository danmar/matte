#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pic1->setVisible(false);
    ui->pic2->setVisible(false);
    timer = new QTimer();
    timer->setInterval(100);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::blink);

    std::srand(std::time(nullptr));

    question();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::question() {
    ui->count->setText(QString::number(++mQuestionCount));
    int v1 = 1+std::rand() % 5;
    int v2 = 2+std::rand() % (9 - v1);
    if (mQuestionCount % 5 == 0) {
        int sub1 = std::max(v1,v2);
        int sub2 = std::min(v1,v2);
        ui->label->setText(QString::number(sub1) + " - " + QString::number(sub2));
        mCorrectAnswer = QString::number(sub1 - sub2);
    } else {
        ui->label->setText(QString::number(v1) + " + " + QString::number(v2));
        mCorrectAnswer = QString::number(v1 + v2);
    }
}

void MainWindow::answerChanged(QString s) {
    if (s == mCorrectAnswer) {
        mBlinkCount = 20;
        question();
        ui->lineEdit->setText("");
    }
}

void MainWindow::blink() {
    if (mBlinkCount > 0)
        --mBlinkCount;
    //ui->blinkCount->setText(QString::number(mBlinkCount));
    ui->pic1->setVisible(mBlinkCount > 0 && (mBlinkCount & 1) == 0);
    ui->pic2->setVisible(mBlinkCount > 0 && (mBlinkCount & 1) == 1);
}
