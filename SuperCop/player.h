#ifndef Player_H
#define Player_H

#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

class Player : public QObject
{

private:
    enum keyPressed {RIGHT = 1, UP = 2, DOWN = 3};

    int posX;
    int posY;
    int sizeX;
    int sizeY;
    int count;
    QPixmap *image;
    QTimer *animationTimer;

public:

    Player(QWidget *parent);
    ~Player();

    void drawPlayer(QPainter &painter);
    void updatePlayer(int action);
    void changeImage(QString str);

    void jump();
    void roll();
    void run();

    void setPosX(int x);
    void setPosY(int y);
    void setSizeX(int x);
    void setSizeY(int y);

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();

public slots:
    void playerAction(int action);
    void playerJump();
    void playerRoll();
    void playerRun();
};

#endif // Player_H
