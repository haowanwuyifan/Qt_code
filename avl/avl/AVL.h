#ifndef AVL_H
#define AVL_H
#include"myqueue.h"

#define posilchild(p) ((p)->leftchild ? (p)->leftchild->horizontal_position : (p)->horizontal_position)
#define posirchild(p) ((p)->rightchild ? (p)->rightchild->horizontal_position : (p)->horizontal_position)


class AVLtree
{
public:
    AVLtree();							//���캯��
    void buildtree(QString key,int size);			//����������
    node* Search(QString _key);						//���ؼ�������
    node* _Search(int key);
    void Insert(QString _key);						//���ؼ��ֲ���
    void Delete(QString _key);						//���ؼ���ɾ��
	void Ascend(node* t);						//�������
	void getbalance(node* t);					//����ƽ������
	int getheight(node* t);						//�������ĸ߶�
	node* getroot();							//�õ��ڵ�
	node* standard(node* t);					//��׼��AVL��
	int gettsize();								//�õ�����
	void l_lroll(node* t);						//LL��ת
	void r_rroll(node* t);						//RR��ת
	void l_rroll(node* t);						//LR��ת
	void r_lroll(node* t);						//RL��ת
	void merge(QList<QString>* a);						//�ϲ�����AVL��
    void divide(QList<QString>* a);						//��һ��AVL������
	node* iterator(node* t, node* y);
	void erase(int key);
	node* max_right(node* t);
    void getdivide(QString _key, node* t);
	int getdiv(node* t);
    bool empty();
    int toint(QString a);
    char* tochar(QString a);
    void calculatePosition();
    void updateDistanceToRoot(node* x);
    node* succ(node *x);
    void display();
	int set_mode(int a);
	int get_mode();
	int getpath(node* t);
	void setpath(node* t);
	void removepath(node* t);
	void setindex(node* t);
	node* Search_(int x);
	void _Delete(int x);
	int getop();
	void setop(int);
	friend void Temp(AVLtree* av, node* t);
private:
	node * root;
	int height;
	int tsize;
	int i_size;
	int mode;
	int op;
};


#endif // AVL_H
