#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer;

    connect(pQTimer,SIGNAL( timeout() ),
      this,SLOT( updateProgressBar() ));
    short a = 10;
    QString t = "Select playtime and press start game!";
    setGameInfoText(t,a);
    currentPlayer = 1;

}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pQTimer;
    pQTimer = nullptr;
}

void MainWindow::updateProgressBar()
{
    if(currentPlayer == 1)
    {
    player1Time = ui->progressBar->value();
    player1Time--;
    ui->progressBar->setValue(player1Time);
    }
        if(currentPlayer == 2)
    {
    player2Time = ui->progressBar_2->value();
    player2Time--;
    ui->progressBar_2->setValue(player2Time);
    }
        qDebug() << player1Time;
        if(player1Time == 0)
        {
            short a = 10;
            QString t = "Player 2 WON!";
            setGameInfoText(t,a);
            pQTimer->stop();
        }
        if(player2Time == 0)
        {
            short a = 10;
            QString t = "Player 1 WON!";
            setGameInfoText(t,a);
            pQTimer->stop();
        }
}


void MainWindow::on_pushButton_clicked()
{
    gameTime=120;
    short a = 10;
    QString t = "Ready to play";
    setGameInfoText(t,a);

}
void MainWindow::on_pushButton_2_clicked()
{
    gameTime = 300;
    short a = 10;
    QString t = "Ready to play";
    setGameInfoText(t,a);
}
void MainWindow::on_pushButton_3_clicked()
{

    pQTimer->start(20*gameTime);
    short a = 10;
    QString t = "Game ongoing";
    setGameInfoText(t,a);

}
void MainWindow::on_pushButton_4_clicked()
{
    pQTimer->stop();
    short a = 10;
    QString t = "New game via start button";
    setGameInfoText(t,a);
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
}


void MainWindow::on_pushButton_5_clicked()
{
    currentPlayer = 2;
    qDebug() << currentPlayer;
}


void MainWindow::on_pushButton_6_clicked()
{
    currentPlayer = 1;
    qDebug() << currentPlayer;
}

void MainWindow::setGameInfoText(QString teksti, short luku)
{
    ui->label->setText(teksti);
    QFont font = ui->label->font();
    font.setPointSize(luku);
    font.setBold(true);
    ui->label->setFont(font);
}

