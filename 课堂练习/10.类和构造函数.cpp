/*
面向对象特点：封装、继承、多态
 
一 类:自定义数据类型
1.定义类:
class 类名
{
	成员...(成员变量、成员函数)

};

eg:
class Student(类名)
{
public:
	int num;
	string name;
	char sex;
	int years;
	float score;
	
	void fun() //成员函数定义在类里面 (本身是內联函数)
	{
		
	}
};

成员函数定义在类外面:
s Student(类名)
{
public:
	int num;
	string name;
	char sex;
	int years;
	float score;
	
	void fun();//声明  inline void fun();
};
void Student::fun()//定义 (普通函数)
{

}

2.类的封装
private:私有成员 成员变量
public:公有成员

class Student(类名)
{
public:  //公共的，外面可以访问
	float score;

	void fun()
	{

	}
private://私有的，外面不可访问
	int num;
	string name;
	char sex;
	 int years;

};

二 对象:类的变量
定义对象:
class Student stu1;//(定义类变量:对象)
Student stu2;

stu1.num = 1002;
stu1.name = "asd";
stu1.fun(); //调用成员函数

对象作为参数时，一般传引用
不做修改传常引用

三 c++中结构体既可以定义成员变量也可以定义成员函数
可以直接用结构体名定义结构体变量

结构体同样可以用关键字public private

结构体成员默认属性是公有的(pubic)
类的成员默认属性是私有的(private)

c++中结构体与类几乎相同(默认属性不同)	

类指针访问成员同结构体

四 构造函数
作用:给成员变量初始化
特点:1.函数名和类名相同
     2.构造函数没返回值，void不用写
     3.在定义对象时系统自动调用
在定义类时没有定义构造函数，系统会生成默认的构造函数
在定义类时定义了构造函数，系统不会生成默认的构造函数

eg:
class Time
{
	private:
		int hour;
		int minute;
		int second;
	public: //构造函数
		Time(int h,int m,int s)
		{
			hour = h;
			minute = m;
			second = s;
		}
		display()
		{
		
		}

};

int main()
{	
	Time t(0.0.0);//定义变量时同时调用构造函数传参
}


五 析构函数
作用:资源回收
特点:1.函数名:~类名
     2.无返回值，无void
     3.无参数
     4.对象被释放时自动调用

析构函数调用顺序与构造函数调用顺序相反;
*/

#include<iostream>
using namespace std;

class Stu
{
	private:
		int num;
		string name;
		char sex;
		int year;
		float score;
	public: 
		//默认值构造函数
		Stu(int _num = 0,const string &_name = "lrh",char _sex = 'M',int _year = 23,float _score = 98)
		{
			num = _num;
			name = _name;
			sex = _sex;
			year = _year;
			score = _score;
		}
#if 0
		//构造函数 形成重载
		Stu()
		{
			num = 0;
			name ="";
			sex = 'M';
			year = 0;
			score = 0;		
		}
		//构造函数 形成重载
		Stu(int _num,const string &_name,char _sex,int _year,float _score)
		{
			num = _num;
			name = _name;
			sex = _sex;
			year = _year;
			score = _score;
		}
#endif
		//析构函数
		~Stu()
		{
			cout<<__func__<<' '<<__LINE__<<endl;
		}

		void set(int _num,const string &_name,char _sex,int _year,float _score)
		{
			num = _num;
			name = _name;
			sex = _sex;
			year = _year;
			score = _score;
		}
		void print()
		{	
			cout<<"num:"<<num<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"sex:"<<sex<<endl;
			cout<<"year:"<<year<<endl;
			cout<<"score:"<<score<<endl;
		}
};

#if 0
struct Student
{
	private:
		int num;
		string name;
		char sex;
		int year;
		float score;
	public:
		void set(int _num,const string &_name,char _sex,int _year,float _score)
		{
			num = _num;
			name = _name;
			sex = _sex;
			year = _year;
			score = _score;
		}
		void print()
		{	
			cout<<"num:"<<num<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"sex:"<<sex<<endl;
			cout<<"year:"<<year<<endl;
			cout<<"score:"<<score<<endl;
		}
};
#endif

int main()
{

	//析构函数 对象被释放时调用
	Stu stu;
	stu.print();

#if 0  //构造函数
	Stu stu;
	stu.print();
#endif

#if 0   //结构体
	Student stu;
	int num,year;
	string name;
	char sex;
	float score;
	cout<<"num:";
	cin>>num;
	cout<<"name:";
	cin>>name;
	cout<<"sex:";
	cin>>sex;
	cout<<"year:";
	cin>>year;
	cout<<"score:";
	cin>>score;
	stu.set(num,name,sex,year,score);
	stu.print();
#endif	

#if 0  //类
	Stu stu;
	int num,year;
	string name;
	char sex;
	float score;
	cout<<"num:";
	cin>>num;
	//cout<<"name:";
	//cin>>name;
	//name = "lrh";
	cout<<"sex:";
	cin>>sex;
	cout<<"year:";
	cin>>year;
	cout<<"score:";
	cin>>score;
	stu.set(num,"lrh",sex,year,score);
	stu.print();
#endif
	return 0;
}











