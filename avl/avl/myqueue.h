#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<QDebug>
#include <algorithm>
#include <iostream>
#include <cstdio>
using std::pair;
using std::max;
using std::cout;
using std::endl;
struct node
{
    pair<int, QString> element;
	node* leftchild;
	node* rightchild;
	int balance;
	int n_height;
	int n_side;
	int divd;
    int horizontal_position;
    int distance_to_root;
};//创建节点类型,包含pair类型的元素，左孩子，右孩子

struct store
{
    QString contant;
    store* next;
};

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



#endif
