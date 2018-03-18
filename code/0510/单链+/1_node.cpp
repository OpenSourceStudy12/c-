#include "1_node.h"

//EMPLOYEE
Employee::Employee():num(0),name("noname"),duty(0),salary(0),next(NULL){}
Employee::Employee(int n,const string & na,int d,double s):num(n),name(na),duty(d),salary(s),next(NULL){}
Employee::~Employee(){}

//MANAGER
Manager* Manager::head=NULL;
Manager::Manager():m_next(NULL){}
Manager::Manager(int n,const string & na,int d,double s):Employee(n,na,d,s)
{
	m_next=NULL;
	
	this->m_next=head;
	head=this;
}
Manager::~Manager()
{
	if(this==head)
		head=head->m_next;
	else
	{
		Manager *tmp=head;
		while(tmp->m_next!=NULL)
		{
			if(tmp->m_next==this)
			{
				tmp->m_next=this->m_next;
				break;
			}
			tmp=tmp->m_next;
		}
	}
}

Manager* Manager::getHead()
{
	return head;
}
	
void Manager::display()
{
	cout << "num : " << num << "\tname : " << name << "\tduty : " << duty << "\tsalary : " << salary << endl;
}
void Manager::cal_salary()
{
	salary=SALARY_MANAGER;
}

//TECH
Tech* Tech::head=NULL;
Tech::Tech():hour(0){}
Tech::Tech(int n,const string & na,int d,double s,double h):Employee(n,na,d,s),hour(h)
{
	this->m_next=head;
	head=this;
}
Tech::~Tech()
{
	if(this==head)
		head=head->m_next;
	else
	{
		Tech *tmp=head;
		while(tmp->m_next!=NULL)
		{
			if(tmp->m_next==this)
			{
				tmp->m_next=this->m_next;
				break;
			}
			tmp=tmp->m_next;
		}
	}
}
 Tech*Tech:: getHead()
 {
 	return head;
 }
void Tech::display()
{
	cout << "num : " << num << "\tname : " << name << "\tduty : " << duty << "\tsalary : " << salary << "\thour : " << hour << endl;
}
void Tech::cal_salary()
{
	salary=hour*SALARY_TECH_HOUR;
}

//SALESMAN
double Salesman::all_c=0;
Salesman* Salesman::head=NULL;
Salesman::Salesman():count(0){}
Salesman::Salesman(int n,const string & na,int d,double s,double c):Employee(n,na,d,s),count(c)
{
	all_c=all_c+c;
	
	this->m_next=head;
	head=this;
}
Salesman::~Salesman()
{
	if(this==head)
		head=head->m_next;
	else
	{
		Salesman *tmp=head;
		while(tmp->m_next!=NULL)
		{
			if(tmp->m_next==this)
			{
				tmp->m_next=this->m_next;
				break;
			}
			tmp=tmp->m_next;
		}
	}
}
Salesman* Salesman::getHead()
{
	return head;
}
double Salesman::getAll(){ return all_c; }
void Salesman::display()
{
	cout << "num : " << num << "\tname : " << name << "\tduty : " << duty << "\tsalary : " << salary << "\tcount : " << count << endl;
}
void Salesman::cal_salary()
{
	salary=SALARY_SALE_BASE+count*SALARY_SALE_S;
}

//SALEMANAGER
SaleManager* SaleManager::head=NULL;
SaleManager::SaleManager():all(0){}
SaleManager::SaleManager(int n,const string & na,int d,double s,double a):Employee(n,na,d,s),all(a)
{
	this->m_next=head;
	head=this;
}
SaleManager::~SaleManager()
{
	if(this==head)
		head=head->m_next;
	else
	{
		SaleManager *tmp=head;
		while(tmp->m_next!=NULL)
		{
			if(tmp->m_next==this)
			{
				tmp->m_next=this->m_next;
				break;
			}
			tmp=tmp->m_next;
		}
	}
}

SaleManager* SaleManager::getHead()
{
	return head;
}

void SaleManager::setAll()
{
	all=getAll();
}
	
void SaleManager::display()
{
	cout << "num : " << num << "\tname : " << name << "\tduty : " << duty << "\tsalary : " << salary << "\tall : " << all << endl;
}
void SaleManager::cal_salary()
{
	//salary=SALARY_SM_B+all*SALARY_SM_S;
	salary=SALARY_SM_B+Salesman::getAll()*SALARY_SM_S;
}










