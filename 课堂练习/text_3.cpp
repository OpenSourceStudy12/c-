#include<iostream>
using namespace std;
#define PI 3.14

class Circle
{
	private:
		float x,y,r;
		//float pi;
	public:
		float c,s;
		//默认值构造函数
		Circle(float c_x=0,float c_y=0,float c_r=0);

#if 0           //重载构造函数
		Circle();
		Circle(float,float,float);
		Circle(float);
#endif
		inline void set(float,float,float);
		inline float get_c();
		inline float get_s();
		inline void display();
};

void Circle::set(float c_x,float c_y,float c_r)
{
	x = c_x;
	y = c_y;
	r = c_r;
	//pi = c_pi;
}

float Circle::get_c()
{
	c = 2*PI*r;
	return c;
}

float Circle::get_s()
{
	s = PI*r*r;
	return s;
}

void Circle::display()
{
	cout<<'('<<x<<','<<y<<") "<<r<<endl;
	cout<<endl<<"c = "<<c<<endl;
	cout<<"s = "<<s<<endl;

}

#if 0  //重载构造函数
Circle::Circle()
{
	x = 0;
	y = 0;
	r = 0;
}
Circle::Circle(float c_x,float c_y,float c_r)
{
	x = c_x;
	y = c_y;
	r = c_r;
}
Circle::Circle(float c_r)
{
	x = 0;
	y = 0;
	r = c_r;
}
#endif

#if 1  //默认值构造函数
Circle::Circle(float c_x,float c_y,float c_r)
{
	x = c_x;
	y = c_y;
	r = c_r;
}
#endif
int main()
{
	float x,y,r;
	Circle rund(0,1,5);
	rund.display();
	cout<<"x:";
	cin>>x;
	cout<<"y:";
	cin>>y;
	cout<<"r:";
	cin>>r;
	rund.set(x,y,r);
	rund.get_c();
	rund.get_s();
	rund.display();
	return 0;
}



