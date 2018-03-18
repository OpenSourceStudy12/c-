#include <iostream>
using namespace std;

struct Node
{
	int num;
	string name;
	Node *pri;
	Node *next;
	Node(int n,const string & str){ num=n; name=str; pri=NULL; next=NULL; }
};

class Linklist
{
private:
	Node *head;
	Node *tail;
	int size;
public:
	Linklist();
	~Linklist();
	
	void clear();  // —— 释放链表中的每一个结点	
	bool front_insert(int n,const string & str);     //在头部插入节点
	bool tail_insert(int n,const string & str);    //在尾部添加节点
	bool insert(int index,int n,const string & str);     //在index位置添加节点
	bool front_del();
	
	Node *searchByIndex(int index);     //按序号查找节点
	
	bool chachong(int n);
	
	void display();
};

//节点序号从0开始
Node* Linklist::searchByIndex(int index)
{
	if(index<0||index>=size)
		return NULL;
	int i=0;
	Node *tmp=head;
	for(i=0;i<index;i++)
		tmp=tmp->next;
	return tmp;
}

bool Linklist::chachong(int n)
{
	Node *tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->num==n)
			return true;
		tmp=tmp->next;
	}
	return false;
}

Linklist::Linklist():head(NULL),tail(NULL),size(0){}
Linklist::~Linklist(){}

void Linklist::clear()
{
	Node *tmp=NULL;
	while(head!=NULL)
	{
		tmp=head;
		head=head->next;
		delete tmp;
	}
	tail=NULL;
	size=0;
}

bool Linklist::front_insert(int n,const string & str)
{
	Node *tmp=head;
	//查重
	while(tmp!=NULL)
	{
		if(tmp->num==n)
			return false;
		tmp=tmp->next;
	}
	
	tmp=new Node(n,str);
	
	if(head==NULL)
	{
		head=tmp;
		tail=tmp;
	}
	else
	{
		head->pri=tmp;
		tmp->next=head;
		head=tmp;
	}
	size++;
	return true;
}

bool Linklist::tail_insert(int n,const string & str)
{
	Node *tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->num==n)
			return false;
		tmp=tmp->next;
	}
	
	tmp=new Node(n,str);
	
	if(tail==NULL)
	{
		head=tmp;
		tail=tmp;
	}
	else
	{
		tail->next=tmp;
		tmp->pri=tail;
		tail=tmp;
	}
	size++;
	return true;
}

bool Linklist::insert(int index,int n,const string & str)
{
	if(index<0||index>size)
	{
		cout << "index error\n";
		return false;
	}
	
	if(chachong(n))
		return false;
	
	//Node *tmp=new Node(n,str);
	
	if(index==0)
	{
		front_insert(n,str);
	}
	else if(index==size)
	{
		tail_insert(n,str);
	}
	else
	{
		Node *tmp=new Node(n,str);
		Node *p=searchByIndex(index-1);
		tmp->pri=p;
		tmp->next=p->next;
		p->next->pri=tmp;
		p->next=tmp;
		size++;
	}
	return true;
}

void Linklist::display()
{
	Node *tmp=head;
	if(head==NULL)
	{
		cout << "empty link\n";
		return ;
	}
	while(tmp!=NULL)
	{
		cout << tmp->num << "  " << tmp->name << endl;
		tmp=tmp->next;
	}
}

bool Linklist::front_del()
{
	if(head==NULL)
		return false;
	Node *tmp=head;
	head=head->next;
	delete tmp;
	
	if(head==NULL)
	{
		tail=NULL;	
	}
	else
	{
		head->pri=NULL;
	}
	size--;
	return true;
}

int main()
{
	Linklist link;
	link.display();
	cout<<"--------------"<<endl;
	
	link.front_insert(1001,"aaa");        //1001
	link.display();
	cout<<"--------------"<<endl;
	
	link.front_insert(1002,"sss");      //1002->1001
	link.display();
	cout<<"--------------"<<endl;
	
	link.tail_insert(1003,"qwe");        //1002->1001->1003
	link.display();
	cout<<"--------------"<<endl;
	
	link.tail_insert(1004,"zxc");         //1002->1001->1003->1004
	link.display();
	cout<<"--------------"<<endl;
	
	link.insert(3,1005,"ccc");          //1002->1001->1003->1005->1004;
	link.display();
	cout<<"--------------"<<endl;
	
	link.front_del();       //1001->1003->1005->1004
	link.display();
	cout<<"--------------"<<endl;
	
	link.clear();
}









