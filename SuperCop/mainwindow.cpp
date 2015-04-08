#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Dell/Documents/SuperCop/SuperCop.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        contact = NULL;
        controls = NULL;
        hScore = NULL;
}//Sets the background image for the main menu

MainWindow::~MainWindow()
{
    delete ui;
}//Clears potential memory leaks

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}//Exits the program

void MainWindow::on_actionContact_Us_triggered()
{
    if(contact==NULL){
        contact = new ContactUs();
    }
    contact->show();
}

void MainWindow::on_actionControls_triggered()
{
    if(controls==NULL){
        controls = new Controls();
    }
    controls->show();
}

void MainWindow::on_actionHigh_Scores_triggered()
{
    if(hScore==NULL){
        hScore = new HighScores();
    }
    hScore->show();
}
