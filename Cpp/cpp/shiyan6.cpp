#include <iostream>
using namespace std;
class Tree//树 
{
	public:
	   virtual void show() = 0;	
	   virtual ~Tree();	
}; 

Tree::~Tree()
{
	cout<<"析构一个树对象!"<<endl;
} 
void Tree::show()
{
	cout<<"树是非常重要的一种数据结构！"<<endl; 
} 
class Binary_Tree:public Tree//二叉树 
{
      public:
         virtual void show();	
	       virtual ~Binary_Tree();	
};

Binary_Tree::~Binary_Tree()
{
	cout<<"析构一个二叉树对象!"<<endl;
} 

void Binary_Tree::show()
{
    cout<<"二叉树每个结点至多有两棵子树，且有左右之分！"<<endl; 	
} 
class Binary_Sort_Tree:public Binary_Tree//二叉排序树 
{
     public:
         virtual void show();	
	       virtual ~Binary_Sort_Tree();
};

Binary_Sort_Tree::~Binary_Sort_Tree()
{
	cout<<"析构一个二叉排序树对象!"<<endl;
}
void Binary_Sort_Tree::show()
{
	cout<<"二叉排序树首先是一颗二叉树！"<<endl;
	cout<<"如果左子树不空，左子树小于根节点！"<<endl;
	cout<<"如果右子树不空，右子树大于根节点！"<<endl;  
}
void f(Tree & t)
{
    t.show();
}
void ff(Tree * t)
{
    t->show();
}
void del(Tree * t)
{
    delete t;
}
int main()
{
    //Tree t;
    Binary_Tree bt;
    Binary_Sort_Tree bst;
    //f(t);
    f(bt);
    f(bst);
    ff(&t);
    ff(&bt);
    ff(&bst);
    //Tree * o = new Tree;
    Binary_Tree * p = new Binary_Tree;
    Binary_Sort_Tree * q = new Binary_Sort_Tree;
    //del(o);
    del(p);
    del(q);
    return 0;
}