#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "Chessmen.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

    Chessmen _s[32];
    int _r;
    int _selectid;
    bool _bRedTurn;

    QPoint center(int id);
    QPoint center(int row, int col);

    void drawChessmen(QPainter& painter, int id);
signals:

public slots:
};

#endif // BOARD_H
