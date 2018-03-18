/*
 当类成员变量中有其它类的对象时，对象的初始化一般采用初始化列表的方法
 
 
 
*/
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
public:
	float x,y;
public:
	Point():x(0),y(0){}
	Point(float x1,float y1):x(x1),y(y1){}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void display()
	{
		cout<<'('<<x<<','<<y<<')';
	}
};

class Cline
{
private:
	Point point1,point2;
public:
	Cline(){}
	Cline(float x1,float y1,float x2,float y2):point1(x1,y1),point2(x2,y2){}
	void display()
	{
		point1.display();
		cout<<' ';
		point2.display();
		cout<<endl;
	}

	float distance()
	{
	/*	float x1,y1,x2,y2,length;
		x1 = point1.getX();
		y1 = point1.getY();
		x2 = point2.getX();
		y2 = point2.getY();
		length = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		return length;
	*/
		float length;
		length = sqrt((point2.x-point1.x)*(point2.x-point1.x)+(point2.y-point1.y)*(point2.y-point1.y));
		return length;
	}

};

int main()
{
	Cline line;
	line.display();
	cout<<"length:"<<line.distance()<<endl<<endl;
	Cline line1(0,0,3,4);
	line1.display();
	cout<<"length:"<<line1.distance()<<endl;
	return 0;
}





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
	Stu():num(0),name("no name"),score(0)
	{

		cout<<__func__<<__LINE__<<endl;
	}
	Stu(int num,const string &name,float score)
	{
		this->num = num;
		this->name = name;
		this->score = score;
		cout<<__func__<<__LINE__<<endl;
	}
	void display()
	{
		cout<<"num:"<<num<<' '<<"name:"<<name<<' '<<"score:"<<score<<endl;
	}

};


class Tea
{
private:
	int num;
	string name;
	//float score;
public:
	Tea():num(0),name("no name")
	{
		cout<<__func__<<__LINE__<<endl;
	
	}
	Tea(int num,const string &name)
	{
		this->num = num;
		this->name = name;
		cout<<__func__<<__LINE__<<endl;
		
		//this->score = score;
	}
	void display()
	{
		cout<<"num:"<<num<<' '<<"name:"<<name<<endl;
	}
};


class Group
{
private:
	Stu stu;
	Tea tea;
public:
	Group()
	{

		cout<<__func__<<__LINE__<<endl;
	}
	Group(int num,const string &name,float score,int num1,const string &name1):stu(num,name,score),tea(num1,name1)
	{
		cout<<__func__<<__LINE__<<endl;
	}
	void display()
	{
		stu.display();
		tea.display();
	}

};

int main()
{
	Group p1;
	p1.display();

	Group p2(1001,"lrh",98,2001,"asd");
	p2.display();
	return 0;

}

#endif
