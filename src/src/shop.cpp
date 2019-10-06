#include<iostream>
#include"shop.h"

//正常收费
float Normal::price_count(float price)
{
	return price;
}
//打折 构造    
Discount::Discount(float d_c)
{
	this->d_c = d_c;
}
//打折 析构
Discount::~Discount()
{

}
//打折计算
float Discount::price_count(float price)
{
	return d_c*price;
}
//满减 构造
Full_rece::Full_rece(float full,float sub)
{
	this->full = full;
	this->sub = sub;
}
//满减 析构
Full_rece::~Full_rece()
{

}
//满减 计算
float Full_rece::price_count(float price)
{
	return price>=full?(price - sub):price;
}

//商家构造
/*Shop::Shop(int num,const string & pass,float d_c,float full,float rece,float p_s):Person(num,pass)
{
	//this->num = num;
	this->d_c = d_c;
	this->full = full;
	this->rece = rece;
	income = 0;
	policy_flag = NORMAL;
	price_send = p_s;
}*/

Shop::Shop(int num,const string & name,const string & tel,const string & add,const string & pass,float income,int policy,float price_send,float dc,float full,float rece):Person(num,name,tel,pass)
{
	this->add = add;
	this->income = income;
	policy_flag = policy;
	this->price_send = price_send;
	d_c = dc;
	this->full = full;
	this->rece = rece;
}

//商家析构
Shop::~Shop()
{
	list<Dishes*>::iterator it;
	for(it=dish.begin();it!=dish.end();)
	{
		delete (*it);
		dish.erase(it);
		it=dish.begin();
	}
}

int Shop::get_num()
{
	return num;
}

//获取商家名称
string & Shop::get_name()
{
	return name;
}
//获取商家电话
string & Shop::get_tel()
{
	return tel;
}
//获取商家地址
string & Shop::get_add()
{
	return add;
}
//获取商家登陆密码
string & Shop::get_passward()
{
	return passward;
}
//修改商家名称
bool Shop::name_modify(const string name)
{
	this->name = name;
	return true;
}
//修改商家电话
bool Shop::tel_modify(const string tel)
{
	this->tel = tel;
	return true;
}
//修改商家地址
bool Shop::add_modify(const string add)
{
	this->add = add;
	return true;
}
//修改商家密码
bool Shop::pass_modify(string & pass)
{
	passward = pass;
	return true;
}
//获取优惠方式
int Shop::get_policy()
{
	return policy_flag;
}
//设置优惠方式
void Shop::set_policy(int flag)
{
	policy_flag = flag;
}

//商家折扣修改
bool Shop::discount_modify(float d_c)
{
	this->d_c = d_c;
	return true;
}

float Shop::get_dc()
{
	return d_c;
}
//商家满减值修改
bool Shop::full_rece_modify(float full,float rece)
{
	this->full = full;
	this->rece = rece;
	return true;
}

float Shop::get_full()
{
	return full;
}

float Shop::get_rece()
{
	return rece;
}

void Shop::set_income(float money)
{
	income += money;
}

float Shop::get_income()
{
	return income;
}

float Shop::get_price_send()
{
	return price_send;
}

void Shop::set_price_send(float p_s)
{
	price_send = p_s;
}

//重载 商家输入
istream & operator>>(istream & in,Shop &shop)
{
	cout<<endl<<"\t商家店名：";
	in>>shop.name;
	cout<<endl<<"\t联系方式：";
	in>>shop.tel;
	cout<<endl<<"\t商店地址：";
	in>>shop.add;
	return in;
}
//重载 商家输出
ostream & operator<<(ostream & out,Shop &shop)
{
	out<<shop.num<<'\t'<<shop.name<<'\t'<<shop.tel<<'\t'<<shop.add<<'\t';
	//cout<<"当前优惠策略:";
	if(shop.policy_flag == NORMAL)
	{
		cout<<"正常收费";
	}
	else if(shop.policy_flag == DISCOUNT)
	{
		cout<<"打"<<shop.d_c<<"折  ";
	}
	else
	{
		cout<<"满"<<shop.full<<"减"<<shop.rece;
	}
	cout<<'\t'<<shop.income<<endl;
	return out;
}




