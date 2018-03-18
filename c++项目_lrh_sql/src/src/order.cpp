#include"order.h"

//检验日期格式
bool date_check(int year,int month,int day)
{
	return true;
}
//检验时间格式
bool time_check(int hour,int minute,int second)
{
	if(hour<24 && minute<60 && second<60)
		return true;
	else
		return false;
}
//日期
Date::Date()
{
	year = 2017;
	month = 5;
	day = 18;
}
Date::~Date()
{

}
//设置日期
void Date::SetDate(int year,int month,int day)
{
	this->year = year;
	this->month =month;
	this->day = day;
}
//获取年
int Date::GetYear()
{
	return year;
}
//获取月
int Date::GetMonth()
{
	return month;
}
//获取日
int Date::GetDay()
{
	return day;
}
//重载日期类输入
istream &operator>>(istream & in,Date &date)
{
	cout<<"日期:";
	while(1)
	{
		in>>date.year;
		in>>date.month;
		in>>date.day;
		if(date_check(date.year,date.month,date.day))
			break;
		else
			cout<<"日期格式不正确，请重新输入:";
	}
	return in;
}
//重载日期类输出
ostream &operator<<(ostream & out,Date &date)
{
	out<<date.year<<'-'<<date.month<<'-'<<date.day;
	return out;
}

//时间
Time::Time()
{
	hour = 12;
	minute = 0;
	second = 0;
}
Time::~Time()
{

}
//设置时间
void Time::SetTime(int hour,int minuth,int second)
{
	this->hour = hour;
	this->minute =minute;
	this->second = second;
}
//获取小时
int Time::GetHour()
{
	return hour;
}
//获取分钟
int Time::GetMinute()
{
	return minute;
}
//获取秒
int Time::GetSecond()
{
	return second;
}
//重载时间类输入
istream &operator>>(istream & in,Time &time)
{
	cout<<"时间:";
	while(1)
	{
		in>>time.hour;
		in>>time.minute;
		in>>time.second;
		if(time_check(time.hour,time.minute,time.second))
			break;
		else
			cout<<"时间格式不正确，请重新输入:";
	}
	return in;
}
//重载时间类输出
ostream &operator<<(ostream & out,Time &time)
{
	out<<time.hour<<':'<<time.minute<<':'<<time.second;
	return out;
}

//下单
Order::Order(int num,string & name,int cl_num,int s_num,string & cl_name,string & s_name,string & cl_tel,string & s_tel,string & cl_add,string & s_add,float price)
{
	this->num = num;
	d_name = name;
	this->cl_num = cl_num;
	this->s_num = s_num;
	c_num = 0;
	this->cl_name = cl_name;
	this->s_name = s_name;
	c_name = "no name";
	this->cl_tel = cl_tel;
	this->s_tel = s_tel;
	c_tel = "no tel";
	this->cl_add = cl_add;
	this->s_add = s_add;
	this->price = price;
	state = book;
}

Order::Order(int num,string & name,int cl_num,int s_num,int c_num,string & cl_name,string & s_name,string & c_name,string & cl_tel,string & s_tel,string & c_tel,string & cl_add,string & s_add,float price,int state,string & date,string & time)
{
	this->num = num;
	d_name = name;
	this->cl_num = cl_num;
	this->s_num = s_num;
	this->c_num = c_num;
	this->cl_name = cl_name;
	this->s_name = s_name;
	this->c_name = c_name;
	this->cl_tel = cl_tel;
	this->s_tel = s_tel;
	this->c_tel = c_tel;
	this->cl_add = cl_add;
	this->s_add = s_add;
	this->price = price;
	this->state = state;
	this->date = date;
	this->time = time;
}

Order::~Order()
{

}
/*
//接单
void Order::GetOrder(int num,string &name,string &tel,string &add,float price)
{
	this->num = (num-SHOP*1000) + this->num*1000;
	s_name = name;
	s_tel = tel;
	s_add = add;
	this->price = price;
	state = get;
}
//拒单
void Order::RejectOrder(int num,string &name,string &tel,string &add,float price)
{
	this->num = (num-SHOP*1000) + this->num*1000;
	s_name = name;
	s_tel = tel;
	s_add = add;
	this->price = price;
	state = reject;
}
*/

void Order::info_add(int n,string & na,string & te)
{
	c_num = n;
	c_name = na;
	c_tel = te;
	state = rob;
}


//打印订单信息
void Order::order_display(int flag)
{
	string date,time;
	get_time(date,time);
	cout<<"\t----------------------------------------------"<<endl;
	cout<<"\t订单编号："<<num<<"  订单状态：";
	switch(state)
		{
			case cancel:
					cout<<"已取消";
					break;
			case reject:
					cout<<"已拒单";
					break;
			case book:
					cout<<"已下单";
					break;
			case take:
					cout<<"已接单";
					break;
			case rob:
					cout<<"已抢单";
					break;
			case send:
					cout<<"已送达";
					break;
			case receive:
					cout<<"已确认收单";
					break;
			case comment:
					cout<<"已评论";
					break;
			default:
					break;					
		}
	cout<<"  价 格："<<price<<endl;
	cout<<"\t下单时间："<<date<<"\t"<<time<<endl;
		
	if(flag==USER)
	{	
		cout<<"\t商家信息："<<s_num<<"  "<<s_name<<"  "<<s_tel<<"  "<<s_add<<endl;
		if(state>=rob)
			cout<<"\t配送员信息："<<c_num<<"  "<<c_name<<"  "<<c_tel<<"  "<<endl;
		else
			cout<<"\t暂无配送员信息!"<<endl;
	}
	
	else if(flag==SHOP)
	{
		cout<<"\t客户信息："<<cl_num<<"  "<<cl_name<<"  "<<cl_tel<<"  "<<cl_add<<endl;
		if(state>=rob)
			cout<<"\t配送员信息："<<c_num<<"  "<<c_name<<"  "<<c_tel<<"  "<<endl;
		else
			cout<<"\t暂无配送员信息!"<<endl;
	
	}
	
	else if(flag==COURIER)
	{
		cout<<"\t客户信息："<<cl_num<<"  "<<cl_name<<"  "<<cl_tel<<"  "<<cl_add<<endl;
		cout<<"\t商家信息："<<s_num<<"  "<<s_name<<"  "<<s_tel<<"  "<<s_add<<endl;
	}
	
	else
	{
		cout<<"\t客户信息："<<cl_num<<"  "<<cl_name<<"  "<<cl_tel<<"  "<<cl_add<<endl;
		cout<<"\t商家信息："<<s_num<<"  "<<s_name<<"  "<<s_tel<<"  "<<s_add<<endl;
		if(state>=rob)
			cout<<"\t配送员信息："<<c_num<<"  "<<c_name<<"  "<<c_tel<<"  "<<endl;
		else
			cout<<"\t暂无配送员信息!"<<endl;	
	}
	
	cout<<"\t----------------------------------------------"<<endl;
}

int Order::get_num()
{
	return num;
}

int Order::get_cl_num()
{
	return cl_num;
}

int Order::get_s_num()
{
	return s_num;
}

int Order::get_c_num()
{
	return c_num;
}

string & Order::get_cl_name()
{
	return cl_name;
}

string & Order::get_s_name()
{
	return s_name;
}

string & Order::get_c_name()
{
	return c_name;
}

string & Order::get_d_name()
{
	return d_name;
}

string & Order::get_cl_tel()
{
	return cl_tel;
}

string & Order::get_s_tel()
{
	return s_tel;
}

string & Order::get_c_tel()
{
	return c_tel;
}

string & Order::get_cl_add()
{
	return cl_add;
}

string & Order::get_s_add()
{
	return s_add;
}


int Order::get_state()
{
	return state;
}

void Order::set_state(int state)
{
	this->state = state;
}

float Order::get_price()
{
	return price;
}

void Order::set_time(const string & date,const string & time)
{
	this->date = date;
	this->time = time;
}
/*
void Order::count_time()
{
	int sec,min,hour,day,mon,year;
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	sec = timeinfo->tm_sec;
	min = timeinfo->tm_min;
	hour = timeinfo->tm_hour;
	day = timeinfo->tm_mday;
	mon = timeinfo->tm_mon;
	year = timeinfo->tm_year+1900;//获取的系统函数年份 = year-1900
	//保存日期
	date = to_string(year)+"-";
	if(mon<10)
		date += "0"+ to_string(mon)+"-";
	else
		date += to_string(mon)+"-";
	if(day<10)
		date += "0"+ to_string(day);
	else
		date += to_string(day);
	//保存时间
	if(hour<10)
		time = "0"+to_string(hour)+":";
	else
		time = to_string(hour)+":";
	if(min<10)
		time += "0"+to_string(min)+":";
	else
		time += to_string(min)+":";
	if(sec<10)
		time += "0"+to_string(sec);
	else
		time += to_string(sec);
}
*/
void Order::get_time(string & date,string & time)
{
	date = this->date;
	time = this->time;
}

