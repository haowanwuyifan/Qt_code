#include"AVL.h"


AVLtree::AVLtree()
{
    root = NULL;
	tsize = 0;
}

void AVLtree::buildtree(QList<QString> key,int size)
{
    
    i_size = size;
    root = new node;
    root->element.first = toint(key[0]);
    root->element.second = key[0];
    root->n_side = -1;
    root->divd = 0;
    root->leftchild = root->rightchild = NULL;
    root->horizontal_position = 0;
    root->distance_to_root = 0;
    tsize = 1;
    /*for (int i = 1; i<i_size; i++)
    {
        Insert(key[i]);
    }*/

}

node* AVLtree::getroot()
{
    return root;
}

void AVLtree::test()
{
    node* m = root/*->rightchild->leftchild*/;
    try
    {
        //node* t = iterator(root, m);
        cout << m->balance << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

}

int AVLtree::gettsize()
{
    return tsize;
}

int AVLtree::getheight(node* t)
{
    if (t == NULL)
        return 0;
    int hl = getheight(t->leftchild);
    int hr = getheight(t->rightchild);
    if (hl>hr)
        return ++hl;
    else
        return ++hr;
}

void AVLtree::getbalance(node* t)
{
    if (t == NULL)
    {
        cout << "请输入内容" <<endl;
    }
    else
    {
        t->balance = getheight(t->leftchild) - getheight(t->rightchild);
        t->n_height = (getheight(t->leftchild) > getheight(t->rightchild)) ? getheight(t->leftchild) : getheight(t->rightchild);
    }

}

int AVLtree::getdiv(node* t)
{
    int div_num = 0;
    Queue qu(gettsize());
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        if (t->divd == 1)
        {
            div_num++;
        }
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
    return div_num;
}

node* AVLtree::iterator(node* t, node* y)
{
    Queue qu(gettsize());
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        if (y == root)
        {
            return y;
        }
        if (t == NULL)
        {
            {
                throw"error";
            }
            return t;
        }
        if (t->leftchild == y)
        {
            t->n_side = 0;
            return t;
            break;
        }
        if (t->rightchild == y)
        {
            t->n_side = 1;
            return t;
        }
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
}

node* AVLtree::max_right(node* t)
{
    node* current = t->leftchild;
    while (current->rightchild != NULL)
    {
        current = current->rightchild;
    }
    return current;
}

void AVLtree::l_lroll(node* t)
{
    node* temp = t->leftchild;
    t->leftchild = t->leftchild->rightchild;
    temp->rightchild = t;
    if (t == root)
    {
        root = temp;
    }
    else
    {
        node* parent = iterator(root, t);
        if (parent->n_side == 0)
        {
            parent->leftchild = temp;
        }
        if (parent->n_side == 1)
        {
            parent->rightchild = temp;
        }
    }
}

void AVLtree::r_rroll(node* t)
{
    node* temp = t->rightchild;
    t->rightchild = t->rightchild->leftchild;
    temp->leftchild = t;
    if (root == t)
    {
        root = temp;
    }
    else
    {
        node* parent = iterator(root, t);
        if (parent->n_side == 0)
        {
            parent->leftchild = temp;
        }
        if (parent->n_side == 1)
        {
            parent->rightchild = temp;
        }
    }
}

void AVLtree::l_rroll(node* t)
{
    r_rroll(t->leftchild);
    l_lroll(t);
}

void AVLtree::r_lroll(node* t)
{
    l_lroll(t->rightchild);
    r_rroll(t);
}

node* AVLtree::standard(node* t)
{
    node* current = t;
    Queue qu(gettsize());
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        getbalance(t);
        if ((t->balance == 2 || t->balance == -2) && current->n_height > t->n_height)
        {
            current = t;
        }
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
    return current;
}

node* AVLtree::_Search(int key)
{
    node* current = root;
    while (1)
    {
        if (current == NULL)
        {
            cout << "不存在该关键字！" << endl;
            return NULL;
            break;
        }
        if (key == current->element.first)
        {
            return current;
        }
        if (key < current->element.first/*&&current->leftchild != NULL*/)
        {
            current = current->leftchild;
            continue;
        }
        if (key > current->element.first/*&&current->rightchild != NULL*/)
        {
            current = current->rightchild;
            continue;
        }
    }
}

void AVLtree::erase(int key)
{
    node* t = _Search(key);
    if (t == NULL)
    {
       cout << "不存在该关键字！";
    }
    else
    {
        node* parent = iterator(root, t);
        if (t->leftchild == NULL && t->rightchild == NULL)
        {
            if (parent->n_side == 0)
            {
                parent->leftchild = NULL;
            }
            if (parent->n_side == 1)
            {
                parent->rightchild = NULL;
            }
			if (t == root)
			{
				root = NULL;
			}
        }
        else if (t->rightchild != NULL && t->leftchild != NULL)
        {
            node* max_l = max_right(t);
            node* parent_d = iterator(root, max_l);
			if (parent_d == t)
			{
				max_l->rightchild = t->rightchild;
				if (t == root)
				{
					root = max_l;
					t = NULL;
				}
			}
			else
			{
				parent_d->rightchild = max_l->leftchild;
				//if (max_l->leftchild != NULL)
				//{
					max_l->leftchild = t->leftchild;
					max_l->rightchild = t->rightchild;
				//}
				if (t == root)
				{
					root = max_l;
				}
				else
				{
					if (parent->n_side == 0)
					{
						parent->leftchild = max_l;
					}
					if (parent->n_side == 1)
					{
						parent->rightchild = max_l;
					}
				}
			}
        }
        else if ((t->rightchild != NULL && t->leftchild == NULL) || (t->leftchild != NULL && t->rightchild == NULL))
        {
            node* chil = t->leftchild == NULL ? t->rightchild : t->leftchild;
            if (t == root)
            {
                root = chil;
            }
            else if (parent->n_side == 0)
            {
                parent->leftchild = chil;
            }
            else if (parent->n_side == 1)
            {
                parent->rightchild = chil;
            }
        }
		t = NULL;
        tsize--;
    }
}

node* AVLtree::Search(QString _key)
{
    int key=toint(_key);
    node* current = root;
    while (1)
    {
        if (current == NULL)
        {
            cout << "不存在该关键字！" << endl;
            return NULL;
            break;
        }
        if (key == current->element.first)
        {
            return current;
        }
        if (key < current->element.first/*&&current->leftchild != NULL*/)
        {
            current = current->leftchild;
            continue;
        }
        if (key > current->element.first/*&&current->rightchild != NULL*/)
        {
            current = current->rightchild;
            continue;
        }
    }
}

void AVLtree::Insert(QString _key)
{
    int key=toint(_key);
    node* current = root;
    while (1)
    {
        if (key < current->element.first&&current->leftchild != NULL)
        {
            current = current->leftchild;
        }
        if (key < current->element.first&&current->leftchild == NULL)
        {
            current->leftchild = new node;
            current->leftchild->element.first = key;
            current->leftchild->element.second = _key;
            current->leftchild->n_side = -1;
            current->leftchild->divd = 0;
            current->leftchild->leftchild = current->leftchild->rightchild = NULL;
            node* t = standard(root);
            if (t->balance == 2)
            {
                if (t->leftchild->balance == 1)
                {
                    l_lroll(t);
                }
                else if (t->leftchild->balance == -1)
                {
                    l_rroll(t);
                }
            }
            if (t->balance == -2)
            {
                if (t->rightchild->balance == 1)
                {
                    r_lroll(t);
                }
                else if (t->rightchild->balance == -1)
                {
                    r_rroll(t);
                }
            }
			break;
        }
        if (key > current->element.first&&current->rightchild != NULL)
        {
            current = current->rightchild;
        }
        if (key > current->element.first&&current->rightchild == NULL)
        {
            current->rightchild = new node;
            current->rightchild->element.first = key;
            current->rightchild->element.second = (char)(key + 96);
            current->rightchild->n_side = -1;
            current->rightchild->divd = 0;
            current->rightchild->leftchild = current->rightchild->rightchild = NULL;
            node* t = standard(root);
            if (t->balance == 2)
            {
                if (t->leftchild->balance == 1)
                {
                    l_lroll(t);
                }
                else if (t->leftchild->balance == -1)
                {
                    l_rroll(t);
                }
            }
            if (t->balance == -2)
            {
                if (t->rightchild->balance == 1)
                {
                    r_lroll(t);
                }
                else if (t->rightchild->balance == -1)
                {
                    r_rroll(t);
                }
            }
			break;
        }
    }
    tsize++;
}

void AVLtree::Delete(QString _key)
{
    int key=toint(_key);
    node* t = Search(_key);
    if (t != NULL)
    {
        node* parent = iterator(root, t);
        erase(key);
        getbalance(parent);
		if (t == parent)
		{
			parent = root;
		}
		if (root==NULL)
		{
			return;
		}
        if (parent->balance == 1 || parent->balance == -1)
        {
            return ;
        }
        if (parent->balance == 2 || parent->balance == -2)
        {
            node* t = standard(parent);
            if (t->balance == 2)
            {
                if (t->leftchild->balance == 1|| t->leftchild->balance == 0)
                {
                    l_lroll(t);
                }
                else if (t->leftchild->balance == -1)
                {
                    l_rroll(t);
                }
            }
            if (t->balance == -2)
            {
                if (t->rightchild->balance == 1|| t->rightchild->balance == 0)
                {
                    r_lroll(t);
                }
                else if (t->rightchild->balance == -1)
                {
                    r_rroll(t);
                }
            }
        }
        if (parent->balance == 0)
        {
            node* grand = standard(root);
            if (grand->balance == 2)
            {
                if (grand->leftchild->balance == 1)
                {
                    l_lroll(grand);
                }
                else if (grand->leftchild->balance == -1)
                {
                    l_rroll(grand);
                }
            }
            if (grand->balance == -2)
            {
                if (grand->rightchild->balance == 1)
                {
                    r_lroll(grand);
                }
                else if (grand->rightchild->balance == -1)
                {
                    r_rroll(grand);
                }
            }
        }
        if (t == root)
        {
            node* t = standard(root);
            if (t->balance == 2)
            {
                if (t->leftchild->balance == 1)
                {
                    l_lroll(t);
                }
                else if (t->leftchild->balance == -1)
                {
                    l_rroll(t);
                }
            }
            if (t->balance == -2)
            {
                if (t->rightchild->balance == 1)
                {
                    r_lroll(t);
                }
                else if (t->rightchild->balance == -1)
                {
                    r_rroll(t);
                }
            }
        }
    }
}

void AVLtree::Ascend(node* t)
{
    if (t)
    {
        Ascend(t->leftchild);
        qDebug() << t->element.second << " ";
        Ascend(t->rightchild);
    }
}

void AVLtree::merge(AVLtree av)
{
//	int sizeb = 0;
//	store headb;
//    headb.contant = QString();
//	headb.next = NULL;
//	store* currentb = &headb;
    QList<QString> bs;
    Queue qu(av.gettsize());
    node* t = av.root;
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        //currentb->next = new store;
        bs << t->element.second;
        //currentb = currentb->next;
        //sizeb++;
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
    //QList<QString> bs = new QString[sizeb];
    //store* currentb_2 = headb.next;
//	for (int i = 0; i < ; i++)
//	{
//		bs[i] = currentb_2->contant;
//		currentb_2 = currentb_2->next;
//	}
    for (int i = 0; i < bs.size(); i++)
    {
        Insert(bs[i]);
    }
}

void AVLtree::getdivide(QString _key,node* t)
{
    //int key=toint(_key);
    if (t)
    {
        getdivide(_key, t->leftchild);
        {
            int y = t->element.first;
            if (y > toint(_key))
            {
                t->divd = 1;
            }
        }
        getdivide(_key, t->rightchild);
    }
}

void AVLtree::divide(node* t, AVLtree &b)
{
//	int sizea = 0, sizeb = 0;
//	store heada;
//	heada.contant = NULL;
//	heada.next = NULL;
//	store* currenta = &heada;
//	store headb;
//	headb.contant = NULL;
//	headb.next = NULL;
//	store* currentb = &headb;
    QList<QString> as;
    QList<QString> bs;
    Queue qu(gettsize());
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        if (t->divd == 0)
        {
//			currenta->next = new store;
//			currenta->next->contant = t->element.first;
//			currenta = currenta->next;
//			sizea++;
            as<<t->element.second;
        }
        if (t->divd == 1)
        {
//			currentb->next = new store;
//			currentb->next->contant = t->element.first;
//			currentb = currentb->next;
//			sizeb++;
            bs<<t->element.second;
        }
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
//	int* a = new int[sizea];
//	store* currenta_2 = heada.next;
//	for (int i = 0; i < sizea; i++)
//	{
//		a[i] = currenta_2->contant;
//		currenta_2 = currenta_2->next;
//	}
//	int* bs = new int[sizeb];
//	store* currentb_2 = headb.next;
//	for (int i = 0; i < sizeb; i++)
//	{
//		bs[i] = currentb_2->contant;
//		currentb_2 = currentb_2->next;
//	}
    b.buildtree(bs,bs.size());
    for (int i = 0; i < as.size(); i++)
    {
        Delete(as[i]);
    }
}

void Temp(AVLtree av, void (AVLtree::*function)(int), node* t)
{
    Queue qu(av.gettsize());
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        if (t->divd = 1)
        {
            (av.*function)(t->element.first);
        }
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
}

bool AVLtree::empty()
{
    if(root==NULL)
    {
        return 0;
    }
    else
        return 1;
}

int AVLtree::toint(QString a)
{
    char* s;
    QByteArray ba=a.toLatin1();
    s=ba.data();
    int g=(int)(s[0])-96;
    return g;
}

char* AVLtree::tochar(QString a)
{
    char* s;
    QByteArray ba=a.toLatin1();
    s=ba.data();
    return s;
}

node* AVLtree::succ(node* x)
{

    if (x->rightchild != NULL)
    {
        x = x->rightchild;
        while (x->leftchild != NULL)
            x = x->leftchild;
    }
    else
    {
        if (x == root)
        {
            return NULL;
        }
        node* parent = iterator(root, x);
        while (parent != x && parent->leftchild != x)
        {
            x = parent;
            parent = iterator(root, x);
        }
        parent = iterator(root, x);
        if (parent == x)
        {
            return NULL;
        }
        x = parent;
    }
    return x;
}

void AVLtree::updateDistanceToRoot(node* x)
{
    if (!x) return;
    int i = 0;
    node* p = x;
    while (p != root)
    {
        p = iterator(root, p);
        ++i;
    }

    x->distance_to_root = i ;

    Queue q(gettsize());
    q.createqueue();
    q.push(x);
    while (q.empty())
    {
        node* parent = iterator(root, x);
        if (x != root)
        {
            x->distance_to_root = parent->distance_to_root + 1;
        }
        if (x->leftchild != NULL)
        {
            q.push(x->leftchild);
        }
        if (x->rightchild != NULL)
        {
            q.push(x->rightchild);
        }
        q.pop();
        x = q.getqueue();
    }

}

void AVLtree::calculatePosition()
{
    //计算垂直位置
    updateDistanceToRoot(root);


    //计算水平位置
    int count = 0;
    node* x = root;
    //找到中序遍历的第一个结点
    while (x && x->leftchild != NULL)
        x = x->leftchild;
    //按照中序遍历的次序记录结点访问次序
    while (x != NULL)
    {
        x->horizontal_position = ++count;
        x->horizontal_position *= 4;    //水平位置放缩4倍 命令行显示时结点之间的空隙4个字符
        x = succ(x);
    }


}

void AVLtree::display()
{
    calculatePosition();
    int nowheight = 0;
    int lastheight = 0;
    int levelcount = 0;
    int i = 0;
    node* t=root;
	if (root == NULL)
	{
		return ;
	}
    Queue qu(tsize);
    qu.createqueue();
    qu.push(t);
    while (qu.empty())
    {
        long long int tmpposi;
        if (t)
        {
            nowheight = t->distance_to_root;
            if (nowheight != lastheight)
            {
                lastheight = nowheight;
                cout << endl;
                levelcount = 0;
            }
            for(i = levelcount; i < posilchild(t); ++i)
            {
                printf(" ");
            }
            int firstprint = 1;
            for (; i < t->horizontal_position; ++i)
            {
                if (firstprint)
                {
                    printf("_");
                    firstprint = 0;
                }
                else
                    printf("_");
            }
            tmpposi = cout.tellp();
            qDebug() << t->element.second;
            long long int tellpppp = cout.tellp() - tmpposi;
            levelcount += (int) (tellpppp);

            levelcount += t->horizontal_position - levelcount;

            for (i = levelcount; i < posirchild(t); ++i)
            {
                if (i == posirchild(t) - 1)
                    printf("_");
                else
                    printf("_");
            }
            levelcount = i;
        }
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
    cout<<endl;
}
