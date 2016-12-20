#include "Board.h"
#include <QPainter>

Board::Board(QWidget *parent) : QWidget(parent)
{

}

void Board::paintEvent(QPaintEvent *event)
{
    QFont font;
    QPainter painter(this);
    int d = 40;


    //Draw 10 lines
    painter.setPen(QColor(255, 0, 0));
    for (int i = 1; i <= 10; i++)
    {
        painter.drawLine(QPoint(d, i*d), QPoint(9*d, i*d));
    }
    // Draw 9 vertical lines
    for (int i = 1; i <= 9; i++)
    {
        if ( i == 1 || i == 9)
            painter.drawLine(QPoint(i*d, d), QPoint(i*d, 10*d));
        else
        {
            painter.drawLine(QPoint(i*d, d), QPoint(i*d, 5*d));
            painter.drawLine(QPoint(i*d, 6*d), QPoint(i*d, 10*d));
        }
    }
    //squared paper for practicing calligraphy
    painter.drawLine(QPoint(4*d, d), QPoint(6*d, 3*d));
    painter.drawLine(QPoint(6*d, d), QPoint(4*d, 3*d));
    painter.drawLine(QPoint(4*d, 10*d), QPoint(6*d, 8*d));
    painter.drawLine(QPoint(6*d, 10*d), QPoint(4*d, 8*d));

    //楚河汉界
    font.setPointSize(d/2);
    painter.setFont(font);
    QRect ff(d, 5*d, 3.5*d , d);
    painter.drawText(ff, Qt::AlignCenter, "楚河");
    ff.setRect(5.5*d, 5*d, 3.5*d, d);
    painter.drawText(ff, Qt::AlignCenter, "汉界");
}
