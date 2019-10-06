#ifndef _DISHES_H
#define _DISHES_H

#include<iostream>
using namespace std;

//菜式类
class Dishes
{
protected:
	string class_name;
	string name;
	float price;
	int num;
public:
	Dishes(int,const string &,const string &,float); 
	~Dishes();
	int get_num(){return num;}
	float get_price();
	bool price_modify(float);
	string & get_classname();
	string & get_name();
	void dishes_display();
	friend ostream & operator<<(ostream &,Dishes &);
	friend istream & operator>>(istream &,Dishes &);
};

ostream & operator<<(ostream &,Dishes &);
istream & operator>>(istream &,Dishes &);




#endif
