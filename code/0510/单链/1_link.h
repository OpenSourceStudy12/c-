#ifndef _LINK_H
#define _LINK_H

#include <iostream>
#include <cstdio>

#define ADD 1
#define DISPLAY 2
#define EXIT 0

enum
{
	MANAGER=1,TECH,SALESMAN,SALEMANAGER
};

using namespace std;

class Employee;

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
};


#endif
