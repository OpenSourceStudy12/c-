#ifndef _PERSON_H
#define _PERSON_H

#include<iostream>
using namespace std;

class Person
{
protected:
	int num;
	string name;
	string tel;
	string passward;
public:
	Person(int,const string &);
	Person(int,const string &,const string &,const string &);
	~Person();
	virtual int get_num()=0;//读取编号
	virtual string & get_name()=0;//读取名字
	virtual string & get_tel()=0;//读取电话
	virtual string & get_add()=0;//读取地址
	virtual string & get_passward()=0;//读取登录密码
	virtual bool name_modify(const string)=0;//名称修改
	virtual bool tel_modify(const string)=0;//电话修改
	virtual bool add_modify(const string)=0;//地址修改
	virtual bool pass_modify(string &)=0;//登录密码修改
};

#endif
