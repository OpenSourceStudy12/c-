#include <iostream>
using namespace std;

class Link
{
private:
	int num;
	string name;
	Link *next;
	
	static Link *head;
	static Link *tail;
	static int size;
public:
	//Link(int n=0,const string & str="noname");
	Link(int n=0,const string & str="noname",int index=0);
	~Link();
	
	void clear();
	
	void display();	
};

Link* Link::head=NULL;
Link* Link::tail=NULL;
int Link::size=0;

/*
Link::Link(int n,const string & str)
{
	num=n;
	name=str;
	next=NULL;
	
	//头插
	if(head==NULL)
	{
		head=this;
		tail=this;
	}
	else
	{
		this->next=head;
		head=this;
	}
	size++;
}
*/


Link::Link(int n,const string & str,int index)
{
	num=n;
	name=str;
	next=NULL;
	
	if(index<0)
		index=0;
	else if(index>size)
		index=size;
	
	if(index==0)
	{
		next=head;
		head=this;	
	}
	else
	{
		int i=0;
		Link *tmp=head;
		for(i=0;i<index-1;i++)
			tmp=tmp->next;
		next=tmp->next;
		tmp->next=this;
	}
	if(index==size)
		tail=this;
	size++;
}

Link::~Link()
{
	if(head==this)
	{
		head=head->next;
		if(head==NULL)
			tail=NULL;
	}
	else
	{
		Link *tmp=head;
		while(tmp->next!=NULL)
		{
			if(tmp->next==this)
			{
				tmp->next=this->next;
				if(tmp->next==NULL)
					tail=tmp;
				break;
			}
			tmp=tmp->next;
		}
	}
	size--;
	
	cout << __func__ << endl;
}

void Link::display()
{
	Link *tmp=head;
	while(tmp!=NULL)
	{
		cout << tmp->num << "  " << tmp->name << endl;
		tmp=tmp->next;
	}
}

void Link::clear()
{
	//Link* tmp = NULL;
	while(head!=NULL)
	{
		//tmp = head;
		//head = head->next;
		delete tmp;
	}
	tail=NULL;
	size=0;
}

int main()
{
	Link *n1=new Link(1001,"aaa");    //1001
	Link *n2=new Link(1002,"qwe");    //1002->1001
	Link *n3=new Link(1003,"zxc");    //1003->1002->1001
	Link *n4=new Link(1004,"fgh",1);  //1003->1004->1002->1001
	
	n1->display();
	cout << endl; 
	
	delete n3;
	n3=NULL;
	
	n1->display();
	
	n1->clear();
}









