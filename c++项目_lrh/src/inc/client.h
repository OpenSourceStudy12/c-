#ifndef _CLIENT_H
#define _CLIENT_H

#include<list>
#include"menu.h"
#include"person.h"
#include"order.h"

//退单状态
#define EXIST    0
#define RECEIVE  1
#define REJECT  -1
#define CANCEL   2



class Client:public Person
{
protected:
	//int num;
	string add;
	float money;
	string pass_pay;
	//list<Order *>order;
	int cancel;//退单编号
	int state;//退单状态
	
public:
	Client(int,const string &,const string &,const string &,const string & pass1="111111",const string & pass2="123456");
	Client(int,const string &,const string &,const string &,const string &,const string &,float,int,int);
	~Client();
	virtual int get_num();
	virtual string & get_name();//读取客户名称
	virtual string & get_tel();//读取客户电话
	virtual string & get_add();//读取客户地址
	virtual string & get_passward();//读取客户登录密码
	virtual string & get_pass_pay();//读取客户支付密码
	virtual bool name_modify(const string);//客户名称修改
	virtual bool tel_modify(const string);//电话修改
	virtual bool add_modify(const string);//地址修改
	virtual bool pass_modify(string &);//登录密码修改
	bool pass_pay_modify(string &);//支付密码修改
	void set_money(float);//充钱
	float get_money();//读取钱
	bool sub_money(float);//扣钱
	int get_cancel(){return cancel;}
	int get_state(){return state;}
	void set_cancel(int can){cancel = can;}
	void set_state(int s){state = s;}
	
	
	friend istream &operator>>(istream &,Client &);	
	friend ostream &operator<<(ostream &,Client &);
};

istream &operator>>(istream &,Client &);
ostream &operator<<(ostream &,Client &);

#endif
