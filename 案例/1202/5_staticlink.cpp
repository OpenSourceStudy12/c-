#include <iostream>
using namespace std;

class node
{
private:
	int num;
	string name;
	node *next;
	static node * head;
	static node * tail;
	static int size;
public:
	node(int n,string na)
	{
		num=n;
		name=na;
		next=NULL;
		
		if(head==NULL)
		{
			head=this;
			tail=this;
			size++;
		}
		else
		{
			//头插
			#if 0
			next=head;
			head=this;
			size++;
			#endif
			
			//尾插
			tail->next=this;
			tail=this;
			size++;
		}
	}
	
	static void display()
	{
		node *p=head;
		while(p!=NULL)
		{
			cout << p->num << "   " << p->name << endl;
			p=p->next;
		}
	}
	
	static void clear()
	{
		node *tmp;
		while(head!=NULL)
		{
			tmp=head;
			head=head->next;
			delete tmp;
		}
		tail=NULL;
		size=0;
	}
	
	static int getsize(){ return size; }
};

node* node::head=NULL;
node* node::tail=NULL;
int node::size=0;

int main()
{
	node *n1=new node(1001,"aaa");
	node *n2=new node(1002,"sss");
	node::display();
	cout << node::getsize() << endl;
	node::clear();
	cout << node::getsize() << endl;
}

