#include "1_node.h"
#include "1_link.h"

Systerm::Systerm():head(NULL){}
Systerm::~Systerm(){}

void Systerm::menu()
{
	cout << "1 add\n";
	cout << "2 display\n";
	cout << "0 exit\n";
	cout << "please select : ";
}
	
void Systerm::start()
{
	int select=0;
	while(1)
	{
		menu();
		cin >> select;
		if(select==ADD)
			add();
		else if(select==DISPLAY)
			display();
		else if(select==EXIT)
			break;
		else 
			cout << "select error\n\n\n";
	}
}
void Systerm::add()
{
	int num=0;
	string name;
	int duty=0;
	Employee *tmp=NULL;
	cout << "num : " ;
	cin >> num ;
	cout << "name : ";
	cin >> name;
	cout << "1 Manager\t2 Tech\t3 Salesman\t4 SaleManager\n";
	cin >> duty;
	
	static SaleManager *p=NULL;
	
	if(duty==MANAGER)
	{
		tmp=new Manager(num,name,MANAGER,SALARY_MANAGER);
	}
	else if(duty==TECH)
	{
		double hour=0;
		cout << "hour : " ;
		cin >> hour;
		tmp=new Tech(num,name,TECH,hour*SALARY_TECH_HOUR,hour);
		//tmp->cal_salary();
	}
	else if(duty==SALESMAN)
	{
		double count=0;
		cout << "count : ";
		cin >> count;
		tmp=new Salesman(num,name,SALESMAN,0,count);
		
		if(p!=NULL)
		{
			p->setAll();
			p->cal_salary();
		}
	}
	else if(duty==SALEMANAGER)
	{
		double all=Salesman::getAll();
		p=new SaleManager(num,name,SALEMANAGER,0,all);
		tmp=p;
	}
	else
	{
		return;
	}
	tmp->cal_salary();
	
	tmp->next=head;
	head=tmp;
}

void Systerm::display()
{
	if(head!=NULL)
	{
		Employee *tmp=head;
		while(tmp!=NULL)
		{
			tmp->display();
			tmp=tmp->next;
		}
	}
	else
		cout << "no employee\n\n";	
	
	getchar();
	getchar();
}
