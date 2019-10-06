#ifndef _MENU_H
#define _MENU_H

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<ctime>
#include<unistd.h>
#include<list>
#include<vector>
#include<map>
#include<mysql/mysql.h>
#include<sql_lrh.h>
#include"person.h"
#include"shop.h"
#include"client.h"
#include"courier.h"
#include"order.h"
#include"dishes.h"

using namespace std;

//开始菜单
#define USER          1
#define SHOP          2
#define COURIER       3
#define ADMIN         4
//主菜单
#define ENROLL        1
#define LOGIN         2
#define EXIT          0
//客户管理
#define USER_ORDER    1
#define USER_INFO     2
//客户订单
#define ORDER_ADD         1
#define ORDER_DEL         2
#define ORDER_RECEIVE     3
#define ORDER_LOOK        4
#define COMMENT           5
//客户信息
#define INFO_DISPLAY  1
#define INFO_MODIFY   2
#define TOP_UP        3
#define USER_PASS     4
#define USER_PASS_PAY 5
#define PASS_MOD      3
//商家管理
#define SHOP_ORDER    1
#define SHOP_DISHES   2
#define SHOP_POLICY   3
#define SHOP_INFO     4
//商家订单
#define ORDER_GET 1
#define ORDER_REJECT  2
#define COMMENT_LOOK  4
//商家菜式
#define DISHES_ADD    1
#define DISHES_LOOK   2
#define DISHES_MODIFY 3
#define DISHES_DEL    4
//商家优惠策略
#define NORMAL        1
#define DISCOUNT      2
#define FULL_REDECE   3
//配送员管理
#define COURIER_ORDER 1
#define COURIER_INFO  2
//配送员订单
#define ORDER_GET     1
#define ORDER_SEND    2
#define ORDER_SEARCH  3
#define COMMENT_LOOK  4
//管理员
#define USER_MAN      1
#define SHOP_MAN      2
#define COURIER_MAN   3
#define ORDER_MAN     4
//管理员管理
#define DISPLAY       1
#define MODIFY        2
#define DEL           3

class Dishes;
class Person;
class Client;
class Shop;
class Courier;
class Order;
class Sql;

class System
{
private:
	list<Person*>person;
	list<Order*>order;
	MYSQL mysql;
	Sql* sql;
	//Client* pcl;
	//Shop* ps;
	//Courier* pc;
public:
	System();
	~System();
	void free();//清除数据

	int hide_passward(string &);//输入密码，并不回显
	void system_init(list<Person*>&,list<Order*>&);
	void system_exit();
	void menu();
	void head_print();//头标题
	void main_menu();//主菜单
	void user_login_menu();//用户菜单
	void user_main_menu();//用户主菜单
	void user_info_man_menu();//用户信息管理
	void user_order_man_menu();//用户订单管理
	void shop_login_menu();//商家菜单
	void shop_main_menu();//商家主菜单
	void shop_dishes_man_menu();//商家菜式管理
	void shop_order_man_menu();//商家菜式管理
	void shop_policy_man_menu();//商家优惠策略管理
	void shop_info_man_menu();//商家信息管理
	void courier_login_menu();//配送员菜单
	void courier_main_menu();//配送员主菜单
	void courier_info_man_menu();//配送员信息管理
	void courier_order_man_menu();//配送员订单管理
	void admin_login_menu();//管理员菜单
	void admin_main_menu();//管理员主菜单
	void admin_user_menu();//管理客户菜单
	void admin_shop_menu();//管理客户菜单
	void admin_courier_menu();//管理客户菜单
	void admin_order_menu();//管理客户菜单

	bool enroll_check(string &,int);//检验帐号是否已注册
	void start();//程序开始
	void user_deal();//客户开始
	void user_man(int);//客户管理
	void user_order_man(int);//客户订单管理
	void user_info_man(int);//客户信息管理
	void shop_deal();//商家开始
	void shop_man(int);//商家管理
	void shop_order_man(int);//商家订单管理
	void shop_dishes_man(int);//商家菜式管理
	void shop_policy_man(int);//商家优惠策略
	void shop_info_man(int);//商家信息管理
	void courier_deal();//配送员开始
	void courier_man(int);//配送员管理
	void courier_order_man(int);//配送员订单管理
	void courier_info_man(int);//配送员信息管理
	void admin_deal();//管理员开始
	void admin_man();//管理员管理
	void admin_man_user();//管理员管理用户
	void admin_man_shop();//管理员管理商家
	void admin_man_courier();//管理员管理配送员
	void admin_man_order();//管理员管理订单

	void user_enroll();
	int user_login();
	void user_order_add(int);
	void user_cancel_order_deal(int);
	void user_order_del(int);
	void user_order_get(int);//用户确认接单
	void user_order_search(int);
	void user_comment(int);
	void user_info_display(int);
	void user_info_modify(int);
	void user_pass_modify(int);
	void user_pay_modify(int);
	void user_top_up(int);

	void shop_enroll();
	int shop_login();
	void shop_order_receive(int);
	void shop_order_reject(int);
	void shop_order_search(int);
	void shop_cancel_order_deal(int);
	void shop_comment_look(int);
	void dishes_add(int);
	void dishes_look(int);
	bool dishes_check(list<Dishes*>&,string &,string &);
	void dishes_modify(int);
	void dishes_del(int);
	void policy(int,int);
	//void discount_policy();
	//void full_redece_policy();
	void shop_info_display(int);
	void shop_info_modify(int);
	void shop_pass_modify(int);

	void courier_enroll();
	int courier_login();
	void courier_get_order(int);
	void courier_send_order(int);
	void courier_order_look(int);
	void courier_comment_look(int);
	void courier_info_display(int);
	void courier_info_modify(int);
	void courier_pass_modify(int);

	//void admin_enroll();
	void admin_login();
	void admin_user_del();
	void admin_user_mod();
	void admin_user_display();
	void admin_shop_del();
	void admin_shop_mod();
	void admin_shop_display();
	void admin_courier_del();
	void admin_courier_mod();
	void admin_courier_display();
	void admin_order_del();
	void admin_order_mod();
	void admin_order_display();
	
	void count_time(Order &);//获取系统时间
};

#endif

