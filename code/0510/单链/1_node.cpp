#include "1_node.h"

//EMPLOYEE
Employee::Employee():num(0),name("noname"),duty(0),salary(0),next(NULL){}
Employee::Employee(int n,const string & na,int d,double s):num(n),name(na),duty(d),salary(s),next(NULL){}
Employee::~Employee(){}

//MANAGER
Manager::Manager(){}
Manager::Manager(int n,const string & na,int d,double s):Employee(n,na,d,s){}
Manager::~Manager(){}	
void Manager::display()
{
	cout << "num : " << num << "\tname : " << name << "\tduty : " << duty << "\tsalary : " << salary << endl;
}
void Manager::cal_salary()
{
	salary=SALARY_MANAGER;
}

//TECH
Tech::Tech():hour(0){}
Tech::Tech(int n,const string & na,int d,double s,double h):Employee(n,na,d,s),hour(h){}
Tech::~Tech(){}
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
Salesman::Salesman():count(0){}
Salesman::Salesman(int n,const string & na,int d,double s,double c):Employee(n,na,d,s),count(c)
{
	all_c=all_c+c;
}
Salesman::~Salesman(){}
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
SaleManager::SaleManager():all(0){}
SaleManager::SaleManager(int n,const string & na,int d,double s,double a):Employee(n,na,d,s),all(a){}
SaleManager::~SaleManager(){}

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










