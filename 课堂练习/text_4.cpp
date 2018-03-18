#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef struct node
{
	unsigned int ID;
	string name;
	char gender[3];
	int age;
	node *pri;
	node *next;
}Node,*PNode;

class StuList
{
	private:
		PNode head;
		PNode tail;
		int size;
	public:
		StuList();//构造函数
		~StuList();//析构函数
		bool load();//建立链表
		bool save();//保存链表
		void clear();//删除链表
		bool front_insert(unsigned int,const string &,const char *gen);//头部插入节点
		bool tail_insert(unsigned int,const string &,const char *gen);//尾部插入节点
		bool insert(int,unsigned int id,const string &na,const char *gen);//从下标n处插入节点
		bool front_del();//删除头节点
		bool tail_del();//删除尾结点
		bool remove(unsigned int n);//删除下标为n的节点
		int find_id(unsigned int id);//查找id
		int find_name(const string &);//查找姓名
		Node *getNode(int index);//查找对应下标的指针
		void sort_id();//按ID排序
		void print();//打印链表
		bool isEmpty();//判断链表是否为空
		int getSize();//节点个数

};

//构造函数
StuList::StuList()
{
	head = NULL;
	tail = NULL;
	size  = 0;
}

//析构函数
StuList::~StuList()
{
	clear();
}
//建立链表
bool StuList::load()
{
	unsigned int id;
	PNode s = NULL,p = NULL;
	size = 0;
	cout<<"ID:";
	cin>>id;
	while(getchar() != '\n');
	while(id)
	{
		size ++;
		s = new Node;
		s->ID = id;
		cout<<"name:";
		getline(cin,s->name);
		//while(getchar() != '\n');
		cout<<"sex:";
		cin>>(s->gender);
		while(getchar() != '\n');
		cout<<"age:";
		cin>>(s->age);
		while(getchar() != '\n');

		if(head == NULL)
		{
			s->next = NULL;
			head = s;
		}
		else
		{
			s->pri = tail;
			s->next = NULL;
			tail->next = s;
		}
		tail = s;

		cout<<"ID:";
		cin>>id;
		while(getchar() != '\n');
	}
	if(head != NULL && tail != NULL)
		return true;
	else
		return false;
}

bool StuList::save()
{


}
//删除链表
void StuList::clear()
{
	PNode p = NULL;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	tail = NULL;
	size = 0;
}
//链表头部插入节点
bool StuList::front_insert(unsigned int id,const string &na,const char *gen)
{
	PNode s = head;
	while(s != NULL)
	{
		if(id == s->ID)
			return false;
		s = s->next;
	}
		
	s = new Node;
	s->ID = id;
	s->name = na;
	strcpy(s->gender,gen);
	
	s->pri = NULL;
	s->next = head;
	head->pri = s;
	head = s;

	size ++;
	return true;
}


//链表尾部插入节点
bool StuList::tail_insert(unsigned int id,const string &na,const char *gen)
{
	PNode s = tail;
	while(s != NULL)
	{
		if(id == s->ID)
			return false;
		s = s->pri;
	}

	s = new Node;
	s->ID = id;
	s->name = na;
	strcpy(s->gender,gen);
	
	s->next = NULL;
	tail->next = s;
	s->pri = tail;
	tail = s;

	size ++;
	return true;
}


//从下标n处插入节点
bool StuList::insert(int n,unsigned int id,const string &na,const char *gen)
{
	PNode s = tail,p = head;
	int i=0;
	while(s != NULL)
	{
		if(id == s->ID)
			return false;
		s = s->pri;
	}
	if(n <= size)
	{
		s = new Node;
		s->ID = id;
		s->name = na;
		strcpy(s->gender,gen);

		if(n==0)
		{
			s->pri = NULL;
			s->next = head;
			head->pri = s;
			head = s;
			size ++;
		}
	
		else if(n==size)
		{
			s->next = NULL;
			tail->next = s;
			s->pri = tail;
			tail = s;
			size ++;
		}

		else 
		{
			while(p != NULL)
			{
				if(i == n-1)
				{
					s->pri = p;
					s->next = p->next;
					p->next = s;
					p->next->pri = s;
					break;
				}
				p = p->next;
				i++;
			}
			size ++;		
		}
		return true;
	}
	else
		return false;
}
//删除头节点
bool StuList::front_del()
{
	PNode p = NULL;
	if(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
		size--;
	}
	if(head == NULL)
	{
		tail = NULL;
		return false;
	}
	else
	{
		head->pri = NULL;
		return true;
	}
}

//删除尾节点
bool StuList::tail_del()
{
	PNode p = NULL;
	if(tail != NULL)
	{
		p = tail;
		tail = tail->pri;
		delete p;
		size--;
	}
	if(tail == NULL)
	{
		head = NULL;
		return false;
	}
	else
	{
		tail->next = NULL;
		return true;
	}
}
//删除指定下标的节点
bool StuList::remove(unsigned int n)
{
	int i=0;
	PNode p = NULL;
	if(n<size)
	{
		if(!n)
		{
			p = head;
			head = head->next;
			if(head == NULL)
				tail = NULL;
			else
				head->pri = NULL;
			delete p;
		}
		else if(n == size-1)
		{
			p = tail;
			tail = tail->pri;
			tail->next = NULL;
			delete p;
		}
		else
		{
			PNode q = NULL;
			p = head;
			while(p != NULL)
			{
				if(i == n-1)
				{
					q = p->next;
					p->next = q->next;
					q->next->pri = p;
					delete q;
				}
				p = p->next;
				i++;
			}
		
		}	
		size--;
		return true;
	}
	else
		return false;
}
//查找id
int StuList::find_id(unsigned int id)
{
	PNode p = head;
	int n = 0;
	while(p != NULL)
	{
		if(p->ID == id)
			return n;
		p = p->next;
		n++;
	}
	return -1;
}

//查找姓名
int StuList::find_name(const string &na)
{
	PNode p = head;
	int n = 0;
	while(p != NULL)
	{
		if(p->name == na)
			return n;
		p = p->next;
		n++;
	}
	return -1;
}
//查找下标的指针
Node * StuList::getNode(int index)
{
	Node *p = head;
	int n=0;
	if(index < size)
	{
		while(p != NULL)
		{
			if(n == index)
				return p;
			p = p->next;
			n ++;
		}
	}
	else 
		return NULL;
}

PNode find_min(PNode p)
{
	PNode q = p;
	p = p->next;
	while(p != NULL)
	{
		if(q->ID > p->ID)
			q = p;
		p = p->next;
	}
	return q;
}

PNode re_move(PNode head,PNode pmin)
{
	if(head == pmin)
	{	
		head = head->next;
		if(head != NULL)
			head->pri = NULL;
	}
	else
	{
		PNode p = head;
		while(p->next != pmin)
			p = p->next;
		p->next = pmin->next;
		if(pmin->next != NULL)
			pmin->next->pri = p;
	}
	return head;
}

PNode creat(PNode head,PNode pmin)
{
	if(head == NULL)
	{	
		head = pmin;
		pmin->pri = NULL;
	}
	else
	{
		PNode p = head;
		while(p->next != NULL)
			p = p->next;
		p->next = pmin;
		pmin->pri = p;
	}
	pmin->next = NULL;
	return head;
}
//按id排序
void StuList::sort_id()
{
	PNode p = head,pmin = NULL;
	head = NULL;
	while(p != NULL)
	{
		pmin = find_min(p);
		p = re_move(p,pmin);
		head = creat(head,pmin);
	}
	tail = pmin;
}


//打印链表
void StuList::print()
{
	PNode p = head;
	if(p != NULL)
	{
		cout<<"ID\t"<<"name\t"<<"gender\t"<<"age"<<endl;
		while(p != NULL)
		{
			cout<<(p->ID)<<"\t"<<(p->name)<<"\t"<<(p->gender)<<"\t"<<(p->age)<<endl;
			p = p->next;
		}
	}
	else
		cout<<"link is empty.."<<endl;
}
//判断链表是否为空 空返回true 非空返回false
bool StuList::isEmpty()
{
	if(head == NULL)
		return true;
	else
		return false;
}
//节点个数
int StuList::getSize()
{
	return size;
}


int main()
{
	StuList mylist;
	if(mylist.isEmpty())
		cout<<"Empty"<<endl;
	mylist.load();//建立链表
	mylist.print();//打印链表
	cout<<endl;
	mylist.front_insert(1009,"肖雯","女");//链表头部插入节点
	mylist.tail_insert(1010,"莫山","男");//链表尾部插入节点
	mylist.print();
	cout<<mylist.getSize()<<endl<<endl;//链表中节点的个数
	mylist.insert(1,1011,"杨哲","男");//向链表中第1个位置插入节点
	mylist.print();
	cout<<endl;
	mylist.sort_id();//按ID排序
	//mylist.save();
	mylist.print();
	cout<<endl;
	mylist.front_del();//删除链表头节点
	mylist.tail_del();//删除链表尾结点
	mylist.print();
	cout<<endl;
	mylist.remove(1);//删除链表的第1个节点
	mylist.print();
	cout<<endl;
	int index = mylist.find_id(1009);//查找链表中ID为1002的节点下标
	if(index != -1)
	{
		Node *ptr = mylist.getNode(index);
		cout<<ptr->ID<<' '<<ptr->name<<' '<<ptr->gender<<' '<<ptr->age<<endl;
	}
	cout<<endl;
	index = mylist.find_name("肖雯");
	if(index != -1)
	{
		Node *ptr = mylist.getNode(index);
		cout<<ptr->ID<<' '<<ptr->name<<' '<<ptr->gender<<' '<<ptr->age<<endl;
	
	}


	return 0;
}









