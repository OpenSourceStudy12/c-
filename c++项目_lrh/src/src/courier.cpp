#include"client.h"

//Courier::Courier(int num,const string & pass):Person(num,pass)
//{}

Courier::Courier(int num,const string & name,const string & tel,const string & pass):Person(num,name,tel,pass)
{}

Courier::~Courier()
{

}

int Courier::get_num()
{
	return num;
}
//获取配送员名称
string & Courier::get_name()
{
	return name;
}
//获取配送员电话
string & Courier::get_tel()
{
	return tel;
}
//获取配送员地址
string & Courier::get_add()
{
	static string ad="no add";
	return ad;
}
//获取配送员登陆密码
string & Courier::get_passward()
{
	return passward;
}
//修改配送员名称
bool Courier::name_modify(const string name)
{
	this->name = name;
	return true;
}
//修改配送员电话
bool Courier::tel_modify(const string tel)
{
	this->tel = tel;
	return true;
}
//修改配送员地址
bool Courier::add_modify(const string add)
{
	return true;
}
//修改配送员登录密码
bool Courier::pass_modify(string & pass)
{
	passward = pass;
	return true;;
}


//重载 配送员输入
istream & operator>>(istream & in,Courier &courier)
{
	cout<<endl<<"\t用户名：";
	in>>courier.name;
	cout<<endl<<"\t联系方式：";
	in>>courier.tel;
	return in;
}
//重载 配送员输出
ostream & operator<<(ostream & out,Courier &courier)
{
	out<<courier.num<<'\t'<<courier.name<<'\t'<<courier.tel;
	return out;
}

