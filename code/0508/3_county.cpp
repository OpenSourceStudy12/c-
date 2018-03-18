#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 40

class Country
{
private:
	char *name;
	char *caption;
	double area;
	double num;
public:
	Country();
	Country(const char*, const char* , double, double); // 带参数的构造函数 
	Country(const Country&);
	~Country();
	
	Country& operator=(const Country&);
	void set(char*,char*, double, double); // 设置属性的成员函数
	void print()const;
};
Country::Country()
{
	name=new char[SIZE];
	strcpy(name,"中国");
	caption=new char[SIZE];
	strcpy(caption,"北京");
	area=960;
	num=130000;
}
Country::Country(const char *n,const char *c,double a,double nu)
{
	name=new char[SIZE];
	strcpy(name,n);
	caption=new char[SIZE];
	strcpy(caption,c);
	area=a;
	num=nu;
}

Country::Country(const Country& c1)
{
	name=new char[SIZE];
	strcpy(name,c1.name);
	caption=new char[SIZE];
	strcpy(caption,c1.caption);
	area=c1.area;
	num=c1.num;
}

Country::~Country()
{
	delete[] name;
	delete[] caption;
}

Country& Country::operator=(const Country& c1)
{
	strcpy(name,c1.name);
	strcpy(caption,c1.caption);
	area=c1.area;
	num=c1.num;
}

void Country::set(char* n,char* c, double a, double nu)
{
	strcpy(name,n);
	strcpy(caption,c);
	area=a;
	num=nu;
}
void Country::print()const
{
	cout << "国家名称：" << name << endl;
	cout << "首都名称：" << caption << endl;
	cout << "面积：" << area << endl;
	cout << "人口数量：" << num << endl;
}

int main()
{
	Country *c1=new Country("日本","东京",37.835,12665.9683);
	c1->print();
	
	delete c1;
}












