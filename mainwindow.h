#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void question();

public slots:
    void answerChanged(QString s);
    void blink();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int mBlinkCount = 0;

    QString mCorrectAnswer;

};
#endif // MAINWINDOW_H
