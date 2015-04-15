#include "supercopgame.h"
#include "player.h"
#include <QGraphicsScene>
#include <QQmlComponent>
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QDebug>
#include <ctime>
#include <cstdlib>



SuperCopGame::SuperCopGame(QWidget *parent) :
    QWidget(parent)
{
    srand(time(0));
    player = new Player(this);

    //Sets the Game Background (Currently Temporary)
    QPixmap bkgnd("../SuperCop/Images/background_temp.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    timer = new QTimer();
    timer->setInterval(40);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateField()));
    timer->start();

    keyTimer = new QTimer();
    keyTimer->setInterval(5);
//    connect(keyTimer, SIGNAL(timeout()), this, SLOT(pollKey()));
    keyTimer->start();

    isUpPressed = false;
    isDownPressed = false;
    isLeftPressed = false;
    isRightPressed = false;

    lastKeyPress = 0;
}


SuperCopGame::~SuperCopGame()
{
    delete timer;
    delete player;
    delete keyTimer;
}


void SuperCopGame::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_D:
        isRightPressed = true;
        break;
    case Qt::Key_S:
        isDownPressed = true;
        break;
    case Qt::Key_W:
        isUpPressed = true;
        break;
    case Qt::Key_A:
        isLeftPressed = true;
        break;
    default:
        break;
    }
}


void SuperCopGame::keyReleaseEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_D:
        isRightPressed = false;
        break;
    case Qt::Key_S:
        isDownPressed = false;
        break;
    case Qt::Key_W:
        isUpPressed = false;
        break;
    case Qt::Key_A:
        isLeftPressed = false;
        break;
    default:
        break;
    }
}


void SuperCopGame::setLastKeyPress(int key)
{
    this->lastKeyPress = key;
}


void SuperCopGame::pollKey()
{
    //Checks if any of the keys are pressed.
    if(isRightPressed || isLeftPressed || isUpPressed || isDownPressed)
    {
        if(isRightPressed)
            lastKeyPress = 1;
        else if(isUpPressed)
            lastKeyPress = 2;
        else if(isDownPressed)
            lastKeyPress = 3;
        else if(isLeftPressed)
            lastKeyPress = 4;
        else
            lastKeyPress = 0;
    }
    else
    {
        //Checks if none of the keys are pressed before checking if some of the keys are pressed.
        if(!isUpPressed && !isDownPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = lastKeyPress;
        else if(!isUpPressed && !isDownPressed && !isLeftPressed)
            lastKeyPress = 1;
        else if(!isUpPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = 2;
        else if(!isUpPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = 3;
        else if(!isUpPressed && !isDownPressed && !isRightPressed)
            lastKeyPress = 4;
        else
            lastKeyPress = 0;
     }
//     }
}


void SuperCopGame::updateField()
{
    pollKey();
    player->playerAction(lastKeyPress);
    this->update();
}


void SuperCopGame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    player->drawPlayer(painter);

    //For debugging purposes
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);
    painter.drawText(10,10, QString("Frame: %1").arg(QString::number(player->getFrame())));
    painter.drawText(20,20, QString("LastKeyPress: %1").arg(QString::number(lastKeyPress)));
}
