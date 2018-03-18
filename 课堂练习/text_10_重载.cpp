#if 0
#include<iostream>
using namespace std;

class Point
{
	private:
		float x;
		float y;
	public:
		Point():x(0),y(0){}
		Point(int i,int j):x(i),y(j){}
		Point(Point &);
		~Point();
		void offset(int,int);
		void offset(Point &);
		bool operator==(const Point &);
		bool operator!=(const Point &);
		void operator+=(const Point &);
		void operator-=(const Point &);
		Point & operator+(const Point &);
		Point & operator-(const Point &);
		int getx(){return x;}
		int gety(){return y;}
		void display()
		{
			cout<<'('<<x<<','<<y<<')';
		}


};

Point::Point(Point &p)
{
	x = p.x;
	y = p.y;
}

Point::~Point()
{

}

void Point::offset(int i,int j)
{
	x += i;
	y += j;
}

void Point::offset(Point &p)
{
	x += p.x;
	y += p.y;
}

bool Point::operator==(const Point &p)
{
	if(x == p.x && y == p.y)
		return true;
	else
		return false;
}

bool Point::operator!=(const Point &p)
{
	if(x == p.x && y == p.y)
		return false;
	else
		return true;
}

void Point::operator+=(const Point &p)
{
	x += p.x;
	y += p.y;
}

void Point::operator-=(const Point &p)
{
	x -= p.x;
	y -= p.y;
}

Point & Point::operator+(const Point &p)
{
	static Point q;
	q.x = x + p.x;
	q.y = y + p.y;
	return q;
}

Point & Point::operator-(const Point &p)
{
	static Point q;
	q.x = x - p.x;
	q.y = y - p.y;
	return q;
}

int main()
{
	Point p1;
	cout<<endl;
	p1.display();
	cout<<endl;
	Point p2(2,5);
	Point p3(3,6);
	Point p4;


	p1.display();
	cout<<'+'<<'('<<3<<','<<7<<")=";
	p1.offset(3,7);
	p1.display();
	cout<<endl;

	p1.display();
	cout<<'+';
	p3.display();
	cout<<'=';
	p1.offset(p3);
	p1.display();
	cout<<endl;
	
	if(p2 == p3)
		cout<<"p2 == p3"<<endl;
	else
		cout<<"p2 != p3"<<endl;
	//p2 += p3
	p2.display();
	cout<<'+';
	p3.display();
	p2 += p3;
	cout<<'=';
	p2.display();
	cout<<endl;
	//p2 -= p3
	p2.display();
	cout<<'-';
	p3.display();
	p2 -= p3;
	cout<<'=';
	p2.display();
	cout<<endl;
	//p4 = p2 + p3
	p2.display();
	cout<<'+';
	p3.display();
	p4 = p2 + p3;
	cout<<'=';
	p4.display();
	cout<<endl;

	//p4 = p2 - p3
	p2.display();
	cout<<'-';
	p3.display();
	p4 = p2 - p3;
	cout<<'=';
	p4.display();
	cout<<endl;

	return 0;
}
#endif

#if 0
#include<iostream>
#include<cstring>
using namespace std;

class Country
{
	private:
		char *name;
		char *caption;
		double area;
		double person_num;
	public:
		Country();
		Country(const Country &);
		Country(const char *,const char *,double,double);
		bool operator=(const Country &);//Country &
		~Country();
		void set(const char*,const char*,double,double);
		void print()const; //

};

Country::Country()
{
	name = new char[100];
	strcpy(name,"中国");
	caption = new char[100];
	strcpy(caption,"北京");
	area = 960;
	person_num =130000.00;
}

Country::Country(const Country &c)
{
	name = new char[strlen(c.name)];
	strcpy(name,c.name);
	caption = new char[strlen(c.caption)];
	strcpy(caption,c.caption);
	area = c.area;
	person_num = c.person_num;
}

Country::Country(const char *n,const char *c,double a,double p)
{
	name = new char[strlen(n)];
	strcpy(name,n);
	caption = new char[strlen(c)];
	strcpy(caption,c);
	area = a;
	person_num = p;
}

bool Country::operator=(const Country &c)
{
	if(strlen(c.name)<100)
	{
		strcpy(name,c.name);
		strcpy(caption,c.caption);
		area = c.area;
		person_num = c.person_num;
		return true;
	}
	else
		return false;
}

Country::~Country()
{
	cout<<name<<"对象被析构了"<<endl;
	delete []name;
	delete []caption;
}

void Country::set(const char *n,const char *c,double a,double p)
{
	strcpy(name,n);
	strcpy(caption,c);
	area = a;
	person_num = p;
}

void Country::print()const
{
	cout<<name<<' '<<caption<<endl;
	cout<<area<<' '<<person_num<<endl;
}


int main()
{
	Country c1;
	c1.print();
	Country c2("美国","纽约",543,100000.00);
	c2.print();
	Country c3(c2);
	c3.print();
	Country c4 = c2;
	c4.print();
	c1.set("英国","伦敦",213.23,2321.123);
	c1.print();
	Country *co = new Country("日本","东京",37.835,12665.9683);
	co->print();
	delete co;
	return 0;

}

#endif

#if 1

#include<iostream>
using namespace std;

class Rmb
{
	private:
		int yuan;
		int jiao;
		int fen;
	public:
		Rmb():yuan(0),jiao(0),fen(0){}
		Rmb(int i,int j,int k):yuan(i),jiao(j),fen(k){}
		Rmb(const Rmb &);
		~Rmb(){cout<<"析构函数被调用"<<endl;}
		Rmb(double);
		friend ostream & operator<<(ostream &,const Rmb &);
		Rmb & operator++();//前置++
		Rmb & operator++(int);//后置++
		Rmb & operator+(const Rmb &);


};

Rmb::Rmb(const Rmb &r)
{
	yuan = r.yuan;
	jiao = r.jiao;
	fen = r.fen;
}

Rmb::Rmb(double r)
{
	int t = (int)r;
	int i=1;
	yuan = 0,jiao = 0,fen = 0;
	while(t)
	{
		yuan += t%10*i;
		t = t/10;
		i *= 10;
	}
	jiao = (int)((r-yuan)*10);
	fen = (int)((r-yuan)*100)%10;
}

ostream & operator<<(ostream &out,const Rmb &r)
{
	out<<r.yuan<<"元"<<r.jiao<<"角"<<r.fen<<"分"<<endl;
	return out;
}
//前置++
Rmb & Rmb::operator++()
{
	if(++fen >= 10)
	{
		fen = 0;
		if(++jiao >= 10)
		{
			jiao = 0;
			yuan++;
		}
	}
	return *this;
}
//后置++
Rmb & Rmb::operator++(int k)
{
	static Rmb r = *this;
	if(++fen >= 10)
	{
		fen = 0;
		if(++jiao >= 10)
		{
			jiao = 0;
			yuan++;
		}
	}
	return r;
}

Rmb & Rmb::operator+(const Rmb & r)
{
	static Rmb rm;
	rm.yuan = 0;
	rm.jiao = 0;
	rm.fen = 0;
	if((rm.fen = fen + r.fen) >= 10)
	{
		rm.fen -= 10;
		if(++rm.jiao >= 10)
		{
			rm.jiao = 0;
			rm.yuan++;
		}
	}
	if((rm.jiao += jiao + r.jiao) >= 10)
	{
		rm.jiao -= 10;
		rm.yuan++;
	}
	rm.yuan += yuan + r.yuan;
	return rm;
}

void fn(const Rmb &x)
{
	cout<<"in fn:"<<x<<endl;
}


int main()
{
	Rmb m1(21,5,9);
	cout<<m1<<endl<<endl<<endl;
	Rmb m2(1001,9,9);
	m2++;
	cout<<m2<<endl;
	++m2;
	cout<<m2<<endl<<endl<<endl;
	Rmb m3(m2);
	cout<<m3<<endl<<endl<<endl;
	Rmb m4 = m1 + m2;
	cout<<m4<<endl<<endl<<endl;
	m4 = m1 + 50.0;
	cout<<m4<<endl<<endl<<endl;
	fn(50.1233);
	

}




#endif








