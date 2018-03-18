/*
函数重载:函数名相同，函数参数类型、顺序或个数不同都会形成函数重载(与返回值类型无关)
  
*/

/*
#include<iostream>

using namespace std;

int min(int x,int y)
{
	cout<<__LINE__<<endl;
	return x<y?x:y;
}

int min(float x,float y)
{
	cout<<__LINE__<<endl;
	return x<y?x:y;
}

int min(int x,float y)
{
	cout<<__LINE__<<endl;
	return x<y?x:y;
}
int min(float x,int y)
{
	cout<<__LINE__<<endl;
	return x<y?x:y;
}


int main()
{
	int x=4,y=7;
	float f1=1.3,f2=2.6;
	//cout<<min(x,y)<<endl;
	//cout<<min(f1,f2)<<endl;
	//cout<<min(x,f1)<<endl;
	cout<<min(f1,x)<<endl;
}
*/

#include<iostream>
using namespace std;
	cout<<"二年级学生成绩总分:"<<sum(a,b,c)<<endl;

double display(double f)
{
	cout<<"A double "<<f<<endl;
}

int display(int x)
{
	cout<<"A int "<<x<<endl;
}

void display(char ch)
{
	cout<<"A char "<<ch<<endl;
}


int main()
{
	short x1 = 1;
	int x2 = 5;
	char ch = 'c';
	float f1 = 1.44;
	double f2 = 45.67;
	display(x2);
	display(ch);
	display(f2);
	//display(x1); 

}























