#include "mydraw.h"

#include <QPainter>

DrawWidget::DrawWidget(QWidget *p):QWidget(p)
{
    avl=new AVLtree;
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (avl->empty()!=0)
    {
        avl->display(); //调用命令行显示 从而计算结点位置
        node* t = avl->getroot();
        Queue qu(avl->gettsize());
        qu.createqueue();
        qu.push(t);
        while (qu.empty())
        {
            node* parent=avl->iterator(avl->getroot(),t);
            if(t==NULL)
            {
                parent=NULL;
            }
            if (t && parent)
                painter.drawLine(30*t->horizontal_position+30, 30+100 * t->distance_to_root, 30*parent->horizontal_position+30, 30+100 * parent->distance_to_root);
            if (t->leftchild != NULL)
            {
                qu.push(t->leftchild);
            }
            if (t->rightchild != NULL)
            {
                qu.push(t->rightchild);
            }
            qu.pop();
            t = qu.getqueue();
        }
        t = avl->getroot();
        Queue _qu(avl->gettsize());
        _qu.createqueue();
        _qu.push(t);
        while (_qu.empty())
        {
			
			painter.setBrush(Qt::yellow);
            painter.drawEllipse(30*t->horizontal_position, 100 * t->distance_to_root, 60, 60);
            painter.drawText(30*t->horizontal_position+20, 100 * t->distance_to_root+30, t->element.second);
            if (t->leftchild != NULL)
            {
                _qu.push(t->leftchild);
            }
            if (t->rightchild != NULL)
            {
                _qu.push(t->rightchild);
            }
            _qu.pop();
            t = _qu.getqueue();
        }
    }

}
