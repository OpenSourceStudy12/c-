#if 0
#include<iostream>
using namespace std;
#define PI 3.14

class circle
{
	private:
		float radius;
	public:
		circle(float r=0):radius(r){}
		float getarea()
		{
			return PI*radius*radius;	
		}
};

class table
{
	private:
		float high;
	public:
		table(float h):high(h){}
		float gethigh()
		{
			return high;
		}
};

class roundtable:public circle,public table
{
	private:
		char color;
	public:
		roundtable(float r=0,float h=0,char c='w'):circle(r),table(h),color(c){}
		void print()
		{
			cout<<"area:"<<getarea()<<endl;
			cout<<"high:"<<gethigh()<<endl;
			cout<<"color:"<<color<<endl;
		}
};

int main()
{
	roundtable t1;
	t1.print();
	roundtable t2(10,5,'y');
	t2.print();
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;

class base //虚基类
{
	private:
		string name;
		int age;
	public:
		base(const string &str="no name",int a=0):name(str),age(a){}
		~base(){}
		string getname()
		{
			return name;
		}
		int getage()
		{
			return age;
		}
		void set(const string &na,int a)
		{
			name = na;
			age = a;
		}
		void print()
		{
			cout<<"name:"<<name<<' '<<"age:"<<age<<endl;
		}
};

class leader:virtual public base
{
	private:
		string post;
		string depart;
	public:
		leader(const string &p="mo post",const string &d="no depart"):post(p),depart(d){}
		void set(const string &p,const string &d)
		{
			post = p;
			depart = d;
		}
		string &get_post()
		{
			return post;
		}
		string &get_depart()
		{
			return depart;
		}
		void print()
		{
			//base::print();
			cout<<"post:"<<post<<' '<<"depart:"<<depart<<endl;
		}
};

class engineer:virtual public base
{
	private:
		string post_title;
		string major;
	public:
		engineer(const string &p="lecture",const string &m="chinese"):post_title(p),major(m){}
		~engineer(){}
		void set(const string &p,const string &m)
		{
			post_title = p;
			major = m;
		}
		string & get_post_title()
		{
			return post_title;
		}
		string &get_major()
		{
			return major;
		}
		void print()
		{
			//base::print();
			cout<<"post_title:"<<post_title<<' '<<"major:"<<major<<endl;
		}
};

class chairman:public leader,public engineer
{
	private:

	public:
		chairman(const string &name="no name",int age=0,const string &post="no post",const string &depart="no depart",const string &p_t="lecture",const string &major="chinese"):base(name,age),leader(post,depart),engineer(p_t,major){}
		void set(const string &name,int age,const string &post,const string &depart,const string &p_t,const string &major)
		{
			base::set(name,age);
			leader::set(post,depart);
			engineer::set(p_t,major);
		}
		void print()
		{
			base::print();
			leader::print();
			engineer::print();
		}
};

int main()
{
	chairman m1("lrh",23,"主任","教务处","教授","图像处理");
	m1.print();
	
	chairman m2;
	m2.print();
	m2.set("qwe",34,"校长","纪检","讲师","嵌入式");
	m2.print();

	

}
#endif

#if 0

#include<iostream>
using namespace std;

class Person
{
	private:
		string name;
		int age;
		char sex;
	public:
		Person()
		{
			name = "无名";
			age = 18;
			sex = 'M';
		}
		Person(const string &name,int age,char sex)
		{
			this->name = name;
			this->age= age;
			this->sex = sex;
		}
		void print()
		{
			cout<<"\n姓名:"<<name<<"\n年龄:"<<age<<endl;
			if(sex == 'M')
				cout<<"性别:男"<<endl;
			else
				cout<<"性别:女"<<endl;
		}
};

class Student:public Person
{
	private:
		string collage;
		int grade;
	public:
		Student()
		{
			collage = "苏州大学";
			grade = 1;	
		}
		Student(const string &name,int age,char sex,const string& collage,int grade):Person(name,age,sex)
		{	
			this->collage = collage;
			this->grade = grade;
		}
		void print()
		{
			Person::print();
			cout<<"\n大学:"<<collage<<endl;
			cout<<"\n年级:"<<grade<<endl;	
		}
};

int main()
{
	Student s1;
	s1.print();
	Student s2("liming",21,'M',"苏州大学",1);
	s2.print();
	return 0;

}

#endif

#if 1

#include<iostream>
#include<cstdio>
using namespace std;


class Staff
{
	protected:
		/*int num;
		string name;
		int age;
		char sex;
		string depart;
		//float salary;*/
	public:
/*		Staff()
		{
			num = 0;
			name = "no name";
			age = 18;
			char sex = 'M';
		}
		Staff(const string &name,int age,char sex,const string &depart)
		{
			this->name = name;
			this->age = age;
			this->sex = sex;
			this->depart = depart;
		}

		void display();
		{
			cout<<"name:"<<name<<' '<<"age:"<<age<<"sex:"<<sex<<endl;
			cout<<"部门:"<<depart;//<<"薪资:"<<salary<<endl;
		}
*/
		virtual float salaryCount()=0;
};

//技术人员
class Tech_staff:public Staff
{
	protected:
		int hour;
		//string depart;
	public:
		Tech_staff()
		{
			hour = 0;
			//depart = "技术部";
			//salary = 0;
		}
		Tech_staff(int h)
		{
			hour = h;
			//depart = "技术部";
		}
		virtual float salaryCount()
		{
			return hour*30;
		}
/*
		void display()
		{
			Staff::display();
			cout<<"薪资:"<<salaryCount()<<endl;
		}
*/
};

//经理
class Manager:virtual public Staff
{
	private:
		//float salary;
		//string depart;

	public:
/*
		Manager()
		{
			depart = "高层";
		}
		Manager(int num,const string &name,int age,char sex):Staff(num,name,age,sex)
		{
			//salary = 10000;
			depart = "高层";
		}
*/
		virtual float salaryCount()
		{
			return 10000;
		}
/*
		void display()
		{
			Staff::display();
			cout<<"薪资:"<<salaryCount()<<endl;
		}
*/
};

//销售人员
class Saleman:virtual public Staff
{
	protected:
		int sales;
	public:
		Saleman()
		{
			sales= 0;
			//depart = "销售部";
			//salary = 2000;
		}
		Saleman(int sales)
		{
			//depart = "销售部";
			this->sales = sales;
		}
		virtual float salaryCount()
		{
			return 2000 + sales%10;
		}
/*
		void display()
		{
			Staff::display();
			cout<<"薪资:"<<salaryCount()<<endl;
		}
*/
};

class SaleManager:public Manager,public Saleman
{
	private:
		int sales_total;
	public:				
		SaleManager()
		{
			sales_total = 0;
			//depart = "高层";
		}
		SaleManager(int sales_total)
		{
			this->sales_total = sales_total;
			//depart = "高层";
		}
		virtual float salaryCount()
		{
			return 6000 + sales_total%3;
		}
/*
		void display()
		{
			Staff::display();
			cout<<"薪资:"<<salaryCount()<<endl;
		}
*/
};


class Info_Man
{
	private:
		int num;
		string name;
		int age;
		char sex;
		string post;
		float salary;
		Info_Man *next;
	public:
		static Info_Man *head;
		static int size;
		Info_Man(int index=0);
		~Info_Man();
		void insert(int index=0);
		friend void display(Info_Man *);
		void print();
		friend void clear(Info_Man *);
};
Info_Man * Info_Man::head = NULL;
int  Info_Man::size = 0;

Info_Man::Info_Man(int index)
{
	cout<<"编号:";
	cin>>num;
	while(getchar() !='\n');
	cout<<"姓名:";
	getline(cin,name);
	cout<<"年龄:";
	cin>>age;
	while(getchar() != '\n');
	cout<<"性别:";
	cin>>sex;
	cout<<"职位:\n\n";
	cout<<"1经理\t2技术人员\t3销售人员\t4销售经理\n";
	int n;
	while(1)
	{
		n = 0;
		cin>>n;
		if(n>=1 && n<=4)
			break;
		else
			cout<<"输入有误，请重新输入\n";
	
	}
	Staff *ptr = NULL;
	if(n==1)
	{
		post = "经理";
		Manager m;
		ptr = &m;
		salary = ptr->salaryCount();
	}
	else if(n==2)
	{
		int h;
		post = "技术人员";
		cout<<"请输入工作时长:";
		cin>>h;
		Tech_staff t(h);
		ptr = &t;
	       	salary = ptr->salaryCount();
	}
	else if(n==3)
	{
		int sales;
		post = "销售人员";
		cout<<"请输入个人销售额";
		cin>>sales;
		Saleman s(sales);
		ptr = &s;
		salary = ptr->salaryCount();
	}
	else
	{
		int sales;
		post = "销售经理";
		cout<<"请输入销售总额:";
		cin>>sales;
		SaleManager s(sales);
		ptr = &s;
		salary = ptr->salaryCount();
	}
	insert(index);
}

Info_Man::~Info_Man()
{
/*
	Info_Man *p = head;
	head = head->next;
	delete p;
	size--;
*/
}



void Info_Man::insert(int index)
{
	if(index == 0 || head == NULL)
	{
		next = head;
		head = this;
	}
	else if(index > size-1)
	{
		Info_Man *p = head;
		while(p->next != NULL)
			p = p->next;
		p->next = this;
		next = NULL;
	}
	else
	{
		int i=0;
		Info_Man *p = head;
		for(i=1;i<index;i++)
			p = p->next;
		next = p->next;
		p->next =this;
	}
	size++;
}

void display(Info_Man *p)
{
	cout<<p->num<<'\t'<<p->name<<'\t'<<p->age<<'\t'<<p->sex<<'\t'<<p->post<<"\t\t"<<p->salary<<endl; 
}

void Info_Man::print()
{
	Info_Man *p = head;
	if(p != NULL)
	{
		cout<<"编号\t姓名\t年龄\t性别\t职位\t\t薪资\n";
		while(p != NULL)
		{
			display(p);
			p = p->next;	
		}
	}
	else
		cout<<"null..\n";
}

void clear(Info_Man *head)
{
	Info_Man *p = NULL;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}

}
int main()
{
	//Info_Man in1,in2,in3;
	Info_Man *p1 = new Info_Man;
	Info_Man *p2 = new Info_Man;
	Info_Man *p3 = new Info_Man;
	Info_Man *p4 = new Info_Man(2);
       	Info_Man *p5 = new Info_Man(34);
	p1->print();
	clear(p1->head);
	return 0;
}







#endif



















