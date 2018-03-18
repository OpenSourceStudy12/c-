#include"client.h"

Client::Client(int num,const string & name,const string & tel,const string & add,const string & pass1,const string & pass2):Person(num,name,tel,pass1)
{
	this->add = add;
	money = 0;
	pass_pay = pass2;
	cancel = 0;
	state = CANCEL;
}

Client::Client(int num,const string & name,const string & tel,const string & add,const string & pass1,const string & pass2,float money,int cancel,int state):Person(num,name,tel,pass1)
{
	this->add = add;
	pass_pay = pass2;
	this->money = money;
	this->cancel = cancel;
	this->state = state;

}

Client::~Client()
{

}
int Client::get_num()
{
	return num;
}

//获取客户名称
string & Client::get_name()
{
	return name;
}
//获取客户电话
string & Client::get_tel()
{
	return tel;
}
//获取客户地址
string & Client::get_add()
{
	return add;
}
//获取客户登陆密码
string & Client::get_passward()
{
	return passward;
}
//获取客户支付密码
string & Client::get_pass_pay()
{
	return pass_pay;
}
//修改客户名称
bool Client::name_modify(const string name)
{
	this->name = name;
	return true;
}
//修改客户电话
bool Client::tel_modify(const string tel)
{
	this->tel = tel;
	return true;
}
//修改客户地址
bool Client::add_modify(const string add)
{
	this->add = add;
	return true;
}
//修改客户登录密码
bool Client::pass_modify(string & pass)
{
	passward = pass;
	return true;;
}

//修改客户支付密码
bool Client::pass_pay_modify(string & pass)
{
	pass_pay = pass;
	return true;
}
//充值
void Client::set_money(float m)
{
	money += m;
}
//读钱
float Client::get_money()
{
	return money;
}
//扣钱
bool Client::sub_money(float m)
{
	if(money<m)
		return false;
	money -= m;
	return true;
}

//重载 客户输入
istream & operator>>(istream & in,Client &client)
{
	cout<<endl<<"\t用户名称：";
	in>>client.name;
	cout<<endl<<"\t联系方式：";
	in>>client.tel;
	cout<<endl<<"\t地    址：";
	in>>client.add;
	return in;
}
//重载 客户输出
ostream & operator<<(ostream & out,Client &client)
{
	out<<client.num<<'\t'<<client.name<<'\t'<<client.tel<<'\t'<<client.add<<'\t'<<client.passward<<'\t'<<client.money;
	return out;
}

