#include"myqueue.h"
Queue::Queue(int size)
{
    _tsize = size;
}

void Queue::createqueue()
{
    listsize = -1;
    queue = new node*[_tsize];
    for (int i = 0; i < listsize; i++)
    {
        queue[i] = NULL;
    }
}

void Queue::push(node* t)
{
    if (listsize == -1)
    {
        queue[0] = t;
        listsize++;
    }
    else
    {
        for (int i = listsize; i >= 0; i--)
        {
            queue[i + 1] = queue[i];
        }
        queue[0] = t;
        listsize++;
    }
}

void Queue::pop()
{
    if (listsize == -1)
    {
        cout << "the queue is empty" << endl;
    }
    else
    {
        listsize--;
    }
}

bool Queue::empty()
{
    if (listsize == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

node* Queue::getqueue()
{
    return queue[listsize];
}
