#ifndef _NODE_H
#define _NODE_H

#include <iostream>

#define SALARY_MANAGER 10000
#define SALARY_TECH_HOUR 30
#define SALARY_SALE_BASE 2000
#define SALARY_SALE_S 0.1
#define SALARY_SM_B 6000
#define SALARY_SM_S 0.03

using namespace std;

class Employee
{
protected:
	int num;
	string name;
	int duty;
	double salary;
public:
	Employee *next;

public:
	Employee();
	Employee(int n,const string & na,int d,double s);
	virtual ~Employee();
	
	virtual void display()=0;
	virtual void cal_salary()=0;
};

class Manager : virtual public Employee
{
public:
	Manager();
	Manager(int n,const string & na,int d,double s);
	~Manager();
	
	void display();
	void cal_salary();
};

class Tech : public Employee
{
private:
	double hour;
public:
	Tech();
	Tech(int n,const string & na,int d,double s,double h);
	~Tech();
	
	void display();
	void cal_salary();
};

class Salesman : virtual public Employee
{
private:
	double count;
	static double all_c;
public:
	Salesman();
	Salesman(int n,const string & na,int d,double s,double c);
	~Salesman();
	
	static double getAll();
	
	void display();
	void cal_salary();
};

class SaleManager : public Manager, public Salesman
{
private:
	double all;
public:
	SaleManager();
	SaleManager(int n,const string & na,int d,double s,double a);
	~SaleManager();
	
	void setAll();
	
	void display();
	void cal_salary();
};

#endif
