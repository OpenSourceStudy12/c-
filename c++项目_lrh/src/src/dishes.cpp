#include"dishes.h"

Dishes::Dishes(int nu,const string & c_n,const string & n,float p)
{
	num = nu;
	class_name = c_n;
	name = n;
	price = p;
}

Dishes::~Dishes()
{

}
//获取菜式的价格
float Dishes::get_price()
{
	return price;
}
//修改菜式的价格
bool Dishes::price_modify(float price)
{
	this->price = price;
	return true;
}

string & Dishes::get_classname()
{
	return class_name;
}
string & Dishes::get_name()
{
	return name;
}

void Dishes::dishes_display()
{
	cout<<"------------------------------------\n";
	cout<<"编  号："<<num<<endl;
	cout<<"菜式类："<<class_name<<endl;
	cout<<"菜式名："<<name<<endl;
	cout<<"价  格："<<price<<" 元"<<endl;
	cout<<"------------------------------------\n";
}

ostream & operator<<(ostream & out,Dishes & dish)
{
	out<<dish.num<<'\t'<<dish.class_name<<"\t\t"<<dish.name<<"\t\t"<<dish.price;
	return out;
}
/*
istream & operator>>(istream & in,Dishes & dish)
{
	cout<<"菜式类：";
	cin>>dish.class_name;
	cout<<"菜式名：";
	cin>>dish.name;
	cout<<"价格：";
	cin>>dish.price;
	return in;
}
*/
