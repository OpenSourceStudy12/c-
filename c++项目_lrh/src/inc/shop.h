#ifndef _SHOP_H
#define _SHOP_H

#include<list>
#include<vector>
#include"menu.h"
#include"person.h"
#include"dishes.h"
#include"order.h"

#define NORMAL    1
#define DISCOUNT  2
#define FULL_RECE 3

//优惠策略基类
class Price
{
public:
	virtual float price_count(float) = 0;
};
//正常
class Normal:public Price
{
public:
	float price_count(float);
};
//打折
class Discount:public Price
{
private:
	float d_c;
public:
	Discount(float d_c=1);
	~Discount();
	float price_count(float);
};
//满减
class Full_rece:public Price
{
private:
	float full;
	float sub;
public:
	Full_rece(float full=0,float sub=0);
	~Full_rece();
	float price_count(float);
};	

//商家类
class Shop:public Person
{
protected:
	//int num;
	string add;
	float income;
	float d_c;//折扣
	float full;//满
	float rece;//减
	float price_send;//配送费
	int policy_flag;//优惠方式
	//list<Order*>order;//订单
	list<Dishes*>dish;//菜式
	vector<map<string,string>>com;//评价
	vector<int>cancel;//退单编号
public:
	//Shop(int,const string &,const string &,const string &,const string & pass = "222222",float d_c=1,float full=0,float rece=0,float p_s=0);//构造函数 传入商家密码和收入
	Shop(int,const string &,const string &,const string &,const string & pass="222222",float income=0,int policy=1,float price_send=0,float dc=1,float full=0,float rece=0);
	~Shop();
	//void info_display();//打印商家信息
	virtual int get_num();
	virtual string & get_name();//读取商家名称
	virtual string & get_tel();//读取商家电话
	virtual string & get_add();//读取商家地址
	virtual string & get_passward();//读取 商家登录密码
	virtual bool name_modify(const string);//商家名称修改
	virtual bool tel_modify(const string);//电话修改
	virtual bool add_modify(const string);//地址修改
	virtual bool pass_modify(string &);//登录密码修改
	int get_policy();
	void set_policy(int);
	bool discount_modify(float);//折扣修改
	float get_dc();
	bool full_rece_modify(float,float);//满减值修改
	float get_full();
	float get_rece();
	float get_price_send();
	void set_price_send(float);
	void set_income(float);
	float get_income();

	list<Dishes*> & get_dish(){return dish;}
	vector<int>& get_cancel(){return cancel;}
	vector<map<string,string>>& get_com(){return com;}
	

	friend istream &operator>>(istream &,Shop &);	
	friend ostream &operator<<(ostream &,Shop &);
};

istream &operator>>(istream &,Shop &);
ostream &operator<<(ostream &,Shop &);



#endif
