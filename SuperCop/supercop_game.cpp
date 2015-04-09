#include "supercop_game.h"

#include <QtQuick/QQuickView>

SuperCopGame::SuperCopGame()
{
    qmlView= new QQuickView();
    qmlView->setSource(QUrl::fromLocalFile("../SuperCop/CopRollAnim.qml"));

//    this->setMinimumSize(500, 500);
//    this->setMaximumSize(500, 500);
//    this->setFocusPolicy(Qt::TabFocus);

    qmlView->show();

}

SuperCopGame::~SuperCopGame()
{

}




