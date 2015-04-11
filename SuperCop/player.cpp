#include "Player.h"
#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

Player::Player(QWidget *parent)
{
    posX = 10;
    posY = parent->height() - 220;
    sizeX = 126;
    sizeY = 204;
    image = new QPixmap("../SuperCop/Images/player.png");
    animationTimer = new QTimer();
    animationTimer->setInterval(17);
    count = 0;
    animationTimer->start();
}

Player::~Player()
{
    delete image;
    animationTimer->stop();
    delete animationTimer;
}

void Player::drawPlayer(QPainter &painter)
{
    painter.drawPixmap(posX, posY, sizeX, sizeY, *image);
}

void Player::updatePlayer(int action)
{
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(playerAction(action)));
}

void Player::changeImage(QString str)
{
    delete image;
    image = new QPixmap(str);
}

void Player::playerAction(int action)
{
    switch (action)
    {
    case RIGHT:
        playerRun();
        break;
    case UP:
        playerJump();
        break;
    case DOWN:
        playerRoll();
        break;
    default:
        break;
    }
}

void Player::jump()
{
    //IGNORE THIS FUNCTION FOR NOW
}


void Player::playerJump()
{
    //IGNORE THIS FUNCTION FOR NOW
}

void Player::roll()
{
    for(int frame = 0; frame < 8; frame++)
        playerRoll();
}

void Player::playerRoll()
{
    //Reset the animation counter
//    if(count > 0)
//        count = 0;

    count++;

    if(1 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll1.png");
    }
    else if(2 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll2.png");
    }
    else if(3 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll3.png");
    }
    else if(4 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll4.png");
    }
    else if(5 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll5.png");
    }
    else if(6 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll6.png");
    }
    else if(7 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll7.png");
    }
    else if(8 == count)
    {
        changeImage("../SuperCop/Images/Rolling/Roll8.png");
    }
    else
        count = 0;
}

void Player::playerRun()
{
    count++;

    if(1 == count)
    {
        changeImage("../SuperCop/Images/Running/Run1.png");
    }
    else if(2 == count)
    {
        changeImage("../SuperCop/Images/Running/Run2.png");
    }
    else if(3 == count)
    {
        changeImage("../SuperCop/Images/Running/Run3.png");
    }
    else
        count = 0;
}


