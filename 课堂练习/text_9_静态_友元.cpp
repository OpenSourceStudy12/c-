#if 0
#include<iostream>
using namespace std;

class Point
{
	private:
		float x,y;
	public:
		Point(float m=0,float n=0):x(m),y(n){}
		Point(Point&);
		~Point(){}
		void display();
		friend Point& _plus(Point &,Point &);
		friend Point& _minus(Point &,Point &);
};

Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
}

void Point::display()
{
	cout<<'('<<x<<','<<y<<')'<<endl;
}
Point& _plus(Point &p1,Point &p2)
{
	static Point p;
	p.x = p1.x+p2.x;
	p.y = p1.y+p2.y;
	return p;
}


Point& _minus(Point &p1,Point &p2)
{
	static Point p;
	p.x = p1.x-p2.x;
	p.y = p1.y-p2.y;
	return p;
}

int main()
{
	Point p1(3,5),p2(5,8);
	Point p_plus(_plus(p1,p2));
	Point p_minus(_minus(p1,p2));
	p1.display();
	p2.display();
	p_plus.display();
	p_minus.display();
	return 0;
}
#endif

#if 0

#include<iostream>
using namespace std;

class Stu
{
	private:
		int num;
		string name;
		float score;
	public:
		friend int main();
};

int main()
{
	Stu stu;
	stu.num = 1001;
	stu.name = "lrh";
	stu.score = 98;
	cout<<"num:"<<stu.num<<' '<<"name:"<<stu.name<<' '<<"score:"<<stu.score<<endl;
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;


class Date
{
	private:
		int year;
		int month;
		int day;
	public:
		Date(int y=2000,int m=1,int d=1):year(y),month(m),day(d){}
		int getYear()
		{
			return year;
		}
		int getMonth()
		{
			return month;
		}
		int getDay()
		{
			return day;
		}
		void display(bool flag)
		{
			if(flag)
				cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
			else
				cout<<month<<'/'<<day<<'/'<<year<<endl;
		}
		bool Setdate(int y,int m,int d)
		{
			if(y >= 0 && m >= 0 && m <= 12 && d >= 0 && d <= 29)		
			{
				year = y;
				month = m;
				day = d;
				return true;
			}
			return false;
		}
		//friend class Aount;
		//friend void Aount::SaveMoney(float,int,int,int);
		friend int day_count(Date &date,int,int,int);
};

class Aount
{
	private:
		float money;//账户余额
		Date date;//存款日期
		static float interestRate;
	public:
		Aount(float m=0,int y=2000,int mo=1,int d=1):money(m),date(y,mo,d){}
		~Aount(){}
		static void SetRate(float);
		float GetRate();
		void SaveMoney(float,int,int,int);
		float LendMoney(float,int,int,int);
		float Calcinterest(int,int,int);
		bool Saveinterest(int,int,int);
		void display(bool flag);
		//friend int day(int,int,int);

};

float Aount::interestRate = 0.036;

void Aount::SetRate(float rate)
{
	interestRate = rate;
}

float Aount::GetRate()
{
	return interestRate;
}

void Aount::SaveMoney(float money,int y,int m,int d)
{
	this->money = money;
	//date.year = y;
	//date.month = m;
	//date.day = d;
	date.Setdate(y,m,d);
}

int day_count(Date &date,int y,int m,int d)
{
	int day;
	day = (y - date.year)*360 + 
		(m - date.month)*30 + 
		(d - date.day);
	return day;
}

float Aount::LendMoney(float money,int y,int m,int d)
{
	int day,L_money = -1;
	if(money <= this->money)
	{
		day = day_count(date,y,m,d);
		if(day >= 0)
		{
			this->money -= money;
			L_money = money + money*interestRate/360*d;
		}
	}
	return L_money;
}

float Aount::Calcinterest(int y,int m,int d)
{
	float rate;
	rate = day_count(date,y,m,d)*interestRate;
	return rate;
}

bool Aount::Saveinterest(int y,int m,int d)
{
	float rate = Calcinterest(y,m,d);
	if(rate >= 0)
	{	
		money += rate;
		date.Setdate(y,m,d);
		return true;
	}
	return false;
}

void Aount::display(bool flag)
{
	cout<<"本金:"<<money<<" "<<"利息:"<<Aount::interestRate<<endl;
	date.display(flag);
}


int main()
{
	Aount aount1;
	aount1.SaveMoney(5000,2011,5,18);
	aount1.display(true);
	aount1.Saveinterest(2013,5,27);
	aount1.display(true);

	aount1.LendMoney(10000,2015,5,12);
	aount1.display(false);
	return 0;
}

#endif

#if 1
#include<iostream>
using namespace std;

class Link
{
	private:
		int num;
		string name;
		Link * next;
		static Link * head;
		static Link * tail;
		static int size;
	public:
		Link(int num=0,const string &str = "no name");
		~Link();
		Link *find(const string &);
		Link *find(int);
		void print_Link(Link *);
		void display();

};

Link* Link::head = NULL;
Link* Link::tail = NULL;

int Link::size = 0;

Link::Link(int n,const string &str)
{
	num = n;
	name = str;
	if(tail == NULL)
		tail = this;
	this->next = head;
	head = this;
	size++;
}

Link* Link::find(const string &str)
{
	Link *p = head;
	while(p != NULL)
	{
		if(p->name == str)
			return p;
		p = p->next;
	}
	return NULL;
}


Link* Link::find(int n)
{
	Link *p = head;
	while(p != NULL)
	{
		if(p->num == n)
			return p;
		p = p->next;
	}
	return NULL;
}

void Link::print_Link(Link *p)
{
	if(p != NULL)
	{
		cout<<"num:"<<p->num<<' '<<"name:"<<p->name<<endl;
	}
	else
		cout<<"没有该学生\n";

}
void Link::display()
{
	Link* p = head;
	while(p != NULL)
	{
		cout<<"num:"<<p->num<<' '<<"name:"<<p->name<<endl;
		p = p->next;
	}

}

Link::~Link()
{
	Link *p = head;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
		cout<<__func__<<' '<<__LINE__<<endl;
	}
}


#endif

int main()
{
	Link* p = NULL;
	Link* p1 = new Link(1001,"lrh");
	Link* p2 = new Link(1002,"qwe");
	Link* p3 = new Link(1003,"asd");
	p1->display();
	p2->display();
	p = p1->find("asddf");
	p1->print_Link(p);
	p1->~Link();

}

