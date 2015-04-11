#include "supercopgame.h"
#include "player.h"
#include <QGraphicsScene>
#include <QQmlComponent>
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QDebug>
#include <ctime>
#include <cstdlib>
//#include "ui_supercop_game.h"


SuperCopGame::SuperCopGame(QWidget *parent) :
    QWidget(parent)
{
    srand(time(0));
    player = new Player(this);
    QPixmap bkgnd("../SuperCop/Images/background_temp.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    timer = new QTimer();
    timer->setInterval(40);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateField()));
    timer->start();
    lastKeyPress = 0;
}

SuperCopGame::~SuperCopGame()
{
}

void SuperCopGame::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_Right:
        qDebug() << "Right";
        lastKeyPress = 1;
        break;
    case Qt::Key_Down:
        qDebug() << "Down";
        lastKeyPress = 3;
        break;
    case Qt::Key_Up:
        qDebug() << "Up";
        lastKeyPress = 2;
        break;
    }
}

void SuperCopGame::updateField()
{
    player->playerAction(lastKeyPress);
    this->update();
}



void SuperCopGame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    player->drawPlayer(painter);
}
