#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

signals:
    void stopProgram();

private slots:
    void updateProgressBar();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::MainWindow *ui;
    QTimer * pQTimer;
    void setGameInfoText(QString, short);
    short player1Time, player2Time, currentPlayer, gameTime;

};
#endif // MAINWINDOW_H
