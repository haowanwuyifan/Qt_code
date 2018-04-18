#ifndef AVL_H
#define AVL_H
#include"myqueue.h"

#define posilchild(p) ((p)->leftchild ? (p)->leftchild->horizontal_position : (p)->horizontal_position)
#define posirchild(p) ((p)->rightchild ? (p)->rightchild->horizontal_position : (p)->horizontal_position)


class AVLtree
{
public:
    AVLtree();							//构造函数
    void buildtree(QList<QString> key,int size);			//创建搜索树
    node* Search(QString _key);						//按关键字搜索
    node* _Search(int key);
    void Insert(QString _key);						//按关键字插入
    void Delete(QString _key);						//按关键字删除
	void Ascend(node* t);						//升序输出
	void getbalance(node* t);					//计算平衡因子
	int getheight(node* t);						//计算树的高度
	void test();								//测试用函数
	node* getroot();							//得到节点
	node* standard(node* t);					//标准化AVL树
	int gettsize();								//得到长度
	void l_lroll(node* t);						//LL旋转
	void r_rroll(node* t);						//RR旋转
	void l_rroll(node* t);						//LR旋转
	void r_lroll(node* t);						//RL旋转
	void merge(AVLtree av);						//合并两棵AVL树
    void divide(node* t,AVLtree &b);						//将一棵AVL树分裂
	node* iterator(node* t, node* y);
	void erase(int key);
	node* max_right(node* t);
    //node *Insert(node* tp);
    void getdivide(QString _key, node* t);
	int getdiv(node* t);
    bool empty();
    int toint(QString a);
    char* tochar(QString a);
    void calculatePosition();
    void updateDistanceToRoot(node* x);
    node* succ(node *x);
    void display();
private:
	node * root;
	int height;
	int tsize;
	int i_size;
};


#endif // AVL_H
