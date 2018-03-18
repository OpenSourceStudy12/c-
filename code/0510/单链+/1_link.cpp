#include "1_node.h"
#include "1_link.h"

Systerm::Systerm():head(NULL){}
Systerm::~Systerm()
{
	if(head == NULL)
		return;
	Employee *tmp = NULL;
	while(head != NULL)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void Systerm::menu()
{
	cout << "1 add\n";
	cout << "2 del\n";
	cout << "3 display\n";
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
		else if(select==DEL)
		{
			int k;
			display();
			cout<<"请输入想要删除的序号：";
			cin>>k;
			del(k);
		}
		else if(select==DISPLAY)
			//display();
			print();
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

void Systerm::print()
{
	int select=0;
	cout <<  "1 Manager\t2 Tech\t3 Salesman\t4 SaleManager\t5 All Employee\n";
	cout << "please select : ";
	cin >> select;
	if(select==MANAGER)
		print_Manager();
	else if(select==TECH)
		print_Tech();
	else if(select==SALESMAN)
		print_Salesman();
	else if(select==SALEMANAGER)
		print_SaleManager();
	else if(select==5)
		display();
}

void Systerm::print_Manager()
{
	Manager *tmp=Manager::getHead();
	while(tmp!=NULL)
	{
		tmp->display();
		tmp=tmp->m_next;
	}
}

void Systerm::print_Tech()
{
	Tech *tmp=Tech::getHead();
	if(tmp==NULL)
	{
		cout << "no Tech\n\n";
		return;
	}
	while(tmp!=NULL)
	{
		tmp->display();
		tmp=tmp->m_next;
	}
}

void Systerm::print_Salesman()
{
	Salesman *tmp=Salesman::getHead();
	if(tmp==NULL)
	{
		cout << "no Salesman\n\n";
		return;
	}
	while(tmp!=NULL)
	{
		tmp->display();
		tmp=tmp->m_next;
	}
}

void Systerm::print_SaleManager()
{
	SaleManager *tmp=SaleManager::getHead();
	if(tmp==NULL)
	{
		cout << "no SaleManager\n\n";
		return;
	}
	while(tmp!=NULL)
	{
		tmp->display();
		tmp=tmp->m_next;
	}
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

void Systerm::del(int index)
{
	if(head == NULL)
		return;
	Employee *tmp = head,*p = NULL;
	if(index == 0)
	{
		tmp = head;
		head = head->next;
		if(tmp->getduty()==SALESMAN)
		{
			SaleManager *p=SaleManager::getHead();
			p->setall();
			p->setAll();
			p->cal_salary();	
		}
		delete tmp;
		return;
	}
	int i=0;
	while(tmp != NULL)
	{
		if(i==index-1)
		{
			p = tmp->next;
			if(tmp->next!=NULL)
			{
				tmp->next = p->next;
			}
			else
			{
				tmp->next = NULL;
			}
			if(p->getduty()==SALESMAN)
			{
				SaleManager *q=SaleManager::getHead();
				q->setall();
				q->setAll();
				q->cal_salary();	
			}
			delete p;
			return;
		}
		tmp = tmp->next;
		i++;
	}
}



