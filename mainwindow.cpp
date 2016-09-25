#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    ui->pushButton->setStyleSheet("background-color: red;");
    this->setStyleSheet("background-color: black;");
    ui->centralWidget->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;

    QMediaPlaylist *playlist = new QMediaPlaylist(player);
    if(playlist->addMedia(QUrl::fromLocalFile("/home/jose/Proyecto1/1.mp4"))){
        if(playlist->addMedia(QUrl::fromLocalFile("/home/jose/Proyecto1/2.mp4"))){
            QVideoWidget *videoWidget = new QVideoWidget;
            player->setVideoOutput(videoWidget);
            videoWidget->showFullScreen();

            videoWidget->show();
            playlist->setCurrentIndex(1);
            player->play();
        }
    }
}
