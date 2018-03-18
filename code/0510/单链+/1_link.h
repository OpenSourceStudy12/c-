#ifndef _LINK_H
#define _LINK_H

#include <iostream>
#include <cstdio>

#define ADD 1
#define DEL 2
#define DISPLAY 3
#define EXIT 0

enum
{
	MANAGER=1,TECH,SALESMAN,SALEMANAGER
};

using namespace std;

class Employee;
class Salesman;
class SaleManager;
class Systerm
{
private:
	Employee *head;
public:
	Systerm();
	~Systerm();
	
	void start();
	void menu();
	void add();
	void display();
	
	void print();
	void print_Manager();
	void print_Tech();
	void print_Salesman();
	void print_SaleManager();
	void del(int);
};


#endif
