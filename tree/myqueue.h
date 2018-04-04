#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<utility>
using namespace std;
struct node
{
	pair<int, char> element;
	node* leftchild;
	node* rightchild;
	int balance;
	int n_height;
	int n_side;
	int divd;
};//创建节点类型,包含pair类型的元素，左孩子，右孩子

//struct store
//{
//	int contant;
//	store* next;
//};

class Queue
{
public:
	node * getqueue();
	bool empty();
	void push(node* t);
	void pop();
	void createqueue();
	Queue(int size);
private:
	node * * queue;
	int listsize;
	int _tsize;
};

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

#endif
