#include <iostream>
using namespace std;
class Tree//�� 
{
	public:
	   virtual void show() = 0;	
	   virtual ~Tree();	
}; 

Tree::~Tree()
{
	cout<<"����һ��������!"<<endl;
} 
void Tree::show()
{
	cout<<"���Ƿǳ���Ҫ��һ�����ݽṹ��"<<endl; 
} 
class Binary_Tree:public Tree//������ 
{
      public:
         virtual void show();	
	       virtual ~Binary_Tree();	
};

Binary_Tree::~Binary_Tree()
{
	cout<<"����һ������������!"<<endl;
} 

void Binary_Tree::show()
{
    cout<<"������ÿ�����������������������������֮�֣�"<<endl; 	
} 
class Binary_Sort_Tree:public Binary_Tree//���������� 
{
     public:
         virtual void show();	
	       virtual ~Binary_Sort_Tree();
};

Binary_Sort_Tree::~Binary_Sort_Tree()
{
	cout<<"����һ����������������!"<<endl;
}
void Binary_Sort_Tree::show()
{
	cout<<"����������������һ�Ŷ�������"<<endl;
	cout<<"������������գ�������С�ڸ��ڵ㣡"<<endl;
	cout<<"������������գ����������ڸ��ڵ㣡"<<endl;  
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