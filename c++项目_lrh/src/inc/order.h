#ifndef _ORDER_H
#define _ORDER_H

#include<iostream>
#include"menu.h"
//#include"client.h"
//#include"shop.h"
//#include"courier.h
//#include"dishes.h"

using namespace std;

/*
#define REJECT -1
#define QX      0
#define BOOK    1
#define GET     2
#define SEND    3
#define RECEIVE 4
#define COM     5
*/

//订单状态枚举
enum
{
	cancel = -2,
	reject,
	book,
	take,
	rob,
	send,
	receive,
	comment
};


//日期类
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	~Date();
	void SetDate(int,int,int);
	int GetYear();
	int GetMonth();
	int GetDay();
	friend ostream &operator<<(ostream &, Date &);
	friend istream &operator>>(istream &, Date &);
};

istream &operator>>(istream &, Date &);
ostream &operator<<(ostream &, Date &);

//时间类
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	~Time();
	void SetTime(int,int,int);
	int GetHour();
	int GetMinute();
	int GetSecond();
	friend ostream &operator<<(ostream &, Time &);
	friend istream &operator>>(istream &, Time &);
};

ostream &operator<<(ostream &, Time &);
istream &operator>>(istream &, Time &);


//订单类
class Order
{
private:
	int num;//订单编号
	int cl_num;//客户编号
	int s_num;//商家编号
	int c_num;//配送员编号
       	string cl_name;//客户名称
	string s_name;//商家名称
	string c_name;//配送员名称
	string cl_tel;//客户电话
	string s_tel;//商家电话
	string c_tel;//配送员电话
	string cl_add;//客户地址
	string s_add;//商家地址
	string d_name;//订单内容
	string date;//订单日期
	string time;//订单时间
	int state;
	float price;
public:
	Order(int,string &,int,int,string &,string &,string &,string &,string &,string &,float);
	Order(int,string &,int,int,int,string &,string &,string &,string &,string &,string &,string &,string &,float,int,string &,string &);
	~Order();
	//void GetOrder(int ,string &,string &,string &,float);
	//void RejectOrder(int,string &,string &,string &,float);
	void order_display(int);
	//获取编号
	int get_num();
	int get_cl_num();
	int get_s_num();
	int get_c_num();
	//获取名称
	string & get_cl_name();
	string & get_s_name();
	string & get_c_name();
	string & get_d_name();
	//获取联系方式
	string & get_cl_tel();
	string & get_s_tel();
	string & get_c_tel();
	//获取地址
	string & get_cl_add();
	string & get_s_add();
	//获取订单状态
	int get_state();
	//设置订单状态
	void set_state(int);
	void info_add(int,string &,string &);//配送员信息添加
	float get_price();
	void set_time(const string &,const string &);
	//void count_time();
	void get_time(string &,string &);	

};


bool date_check(int,int,int);
bool time_check(int,int,int);





#endif
