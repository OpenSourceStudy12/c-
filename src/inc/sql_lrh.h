#ifndef _SQL_LRH_H
#define _SQL_LRH_H

#include<iostream>
#include<menu.h>
using namespace std;

class Dishes;
class Person;
class Client;
class Shop;
class Courier;
class Order;


class Sql
{
public:
	int static id;
public:
	void client_info_read(MYSQL*,list<Person*>&);//用户信息读取
	void shop_info_read(MYSQL*,list<Person*>&);//商家信息读取
	void courier_info_read(MYSQL*,list<Person*>&);//配送员信息读取
	void dish_info_read(MYSQL*,list<Person*>&);//菜式信息读取
	void cancel_read(MYSQL*,list<Person*>&);//退单请求读取
	void shop_com_read(MYSQL*,list<Person*>&);//商家评价读取
	void courier_com_read(MYSQL*,list<Person*>&);//配送员评价读取
	void order_read(MYSQL*,list<Order*>&);//订单读取
	int order_state_read(MYSQL*,int);

  	bool info_update(MYSQL*,string &);//信息更新
#if 0
	void shop_info_update(MYSQL*,string &);//商家信息更新
	void courier_info_update(MYSQL*,string &);//配送员信息更新
	void dish_info_update(MYSQL*,string &);//菜式信息更新
	void shop_com_update(MYSQL*,string &);//商家评价更新
	void courier_com_update(MYSQL*,string &);//配送员评价更新
	void order_update(MYSQL*,string &);//订单更新
	void cancel_update(MYSQL*,string &);//退单更新

	void client_info_write(MYSQL*,list<Person*>&);//用户信息保存
	void shop_info_write(MYSQL*,list<Person*>&);//商家信息保存
	void courier_info_write(MYSQL*,list<Person*>&);//配送员信息保存
	void dish_info_write(MYSQL*,Shop*);//菜式信息保存
	void cancel_write(MYSQL*,Shop*);//退单请求保存
	void shop_com_write(MYSQL*,Shop*);//商家评价保存
	void courier_com_write(MYSQL*,Courier*);//配送员评价保存
	void order_write(MYSQL*,list<Order*>&);//订单保存
#endif
	//istring int_to_str(int);//将整数转换为string
	//string float_to_str();//将浮点形数据转换为string
};



#endif
