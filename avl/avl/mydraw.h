#ifndef MYDRAW_H
#define MYDRAW_H


#include "AVL.h"
#include <QWidget>
#include <QPaintEvent>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    AVLtree *avl;
    DrawWidget(QWidget *p = 0);
    void paintEvent(QPaintEvent *);
};

#endif // DRAW_H
