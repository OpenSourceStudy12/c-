#include <iostream>
using namespace std;

struct Node
{
	int num;
	string name;
	Node *pri;
	Node *next;
};

class Link
{
private:
	Node *head;
	Node *tail;
	int size;
public:
	Link(){ head=NULL; tail=NULL; size=0; }
	void clear()    // 释放链表中的每一个结点
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
	
	bool front_insert(int n,string & na)
	{
		Node *p=head;
		while(p!=NULL)
		{
			if(p->num==n)
				return false;
			p=p->next;
		}
		
		Node *tmp=new Node;
		tmp->num=n;
		tmp->name=na;
		
		tmp->pri=NULL;
		tmp->next=head;
		
		if(head!=NULL)
			head->pri=tmp;
		
		head=tmp;
		if(size==0)
			tail=tmp;
		
		size=size+1;
		return true;
	}
	
	bool insert(int index, int n, const string & na)
	{
		if(index<0||index>size)
			return false;
			
		Node *p=head;
		while(p!=NULL)
		{
			if(p->num==n)
				return false;
			p=p->next;
		}
		
		Node *tmp=new Node;
		tmp->num=n;
		tmp->name=na;
		
		if(index==0)
		{
			tmp->pri=NULL;
			tmp->next=head;
			if(size==0)
				tail=tmp;
			else
				head->pri=tmp;
			head=tmp;
		}
		else
		{
			int i=0;
			p=head;
			for(i=0;i<index-1;i++)
			{
				p=p->next;
			}
			
			tmp->pri=p;
			tmp->next=p->next;
			
			if(p->next==NULL)
			{
				tail=tmp;
			}
			else
			{
				p->next->pri=tmp;
			}
			p->next=tmp;	
		}
		size=size+1;
		return true;
	}
	
	void print()
	{
		if(head==NULL)
			return;
		else
		{	
			Node *p=head;
			cout << "--------from begin to end-------------\n";
			while(p!=NULL)
			{
				cout << p->num << "   " << p->name << endl;
				p=p->next;
			}
			cout << "--------from end to begin-------------\n";
			p=tail;
			while(p!=NULL)
			{
				cout << p->num << "   " << p->name << endl;
				p=p->pri;
			}
		}
	}
};

int main()
{
	Link link1;
	string s1="aaa";
	link1.front_insert(1001,s1);
	
	string s2="zzz";
	link1.insert(1, 1002, s2);
	if(link1.insert(1, 1002, s2))
		cout << "insert!!!!!\n";
	else
		cout << "NO!!!!!!\n";
	link1.insert(0, 1003, s2);
	link1.print();
	link1.clear();
}

