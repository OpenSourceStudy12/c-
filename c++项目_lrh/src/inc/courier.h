#ifndef _COURIER_H
#define _COURIER_H

#include<iostream>
#include<vector>
#include"menu.h"
//#include"person.h"
//#include"order.h"


class Courier:public Person
{
protected:
	//int num;
	//list<Order *>order;
	vector<map<string,string>>com;
	//string add;
	//float money;
	//string pass_pay;
public:
	//Courier(int,const string & pass="333333");
	Courier(int,const string &,const string &,const string & pass="333333");
	~Courier();
	virtual int get_num();
	virtual string & get_name();//读取配送员名称
	virtual string & get_tel();//读取配送员电话
	string & get_add();//读取地址
	virtual string & get_passward();//读取配送员登录密码
	virtual bool name_modify(const string);//配送员名称修改
	virtual bool tel_modify(const string);//配送员电话修改
	virtual bool add_modify(const string);//配送员i地址修改
	virtual bool pass_modify(string &);//登录密码修改
	vector<map<string,string>>& get_com(){return com;}
	
	friend istream &operator>>(istream &,Courier &);	
	friend ostream &operator<<(ostream &,Courier &);
};

istream &operator>>(istream &,Courier &);
ostream &operator<<(ostream &,Courier &);











#endif
