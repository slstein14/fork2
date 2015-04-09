#ifndef SUPERCOP_GAME_H
#define SUPERCOP_GAME_H

#include "mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>
#include <QtQuick/QQuickView>

class SuperCopGame : public QWidget
{
private:

    QVBoxLayout *layout;
    QQuickView *qmlView;

public:
    SuperCopGame();
    ~SuperCopGame();
};

#endif // SUPERCOP_GAME_H
