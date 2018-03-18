/*
关键字 this:
this 是一个指针，指向当前对象 每一个成员函数都有一个this指针




 
*/
#include<iostream>
using namespace std;

class Point
{
	private:
		int x,y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
		Point(int x,int y)
		{
			this->x = x;
			this->y = y;
		}
		void display()
		{
			cout<<this<<endl;
			cout<<"x:"<<x<<' '<<"y:"<<y<<endl;
		}

};

int main()
{
	Point p1;
	p1.display();
	cout<<"&p1="<<&p1<<endl;

	Point p2(3,4);
	p2.display();
	cout<<"&p2="<<&p2<<endl;
	return 0;
}






