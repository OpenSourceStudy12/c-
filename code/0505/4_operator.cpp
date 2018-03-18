#include <iostream>
using namespace std;

//1,相似
//2,
//3,

class Fraction
{
private:
	int fenzi;
	int fenmu;
public:
	Fraction(int f1=0,int f2=1):fenzi(f1),fenmu(f2){}
	~Fraction(){}
	void display()
	{
		cout << fenzi << "/" << fenmu;
	}
	
	void setFenzi(int f1)
	{
		fenzi=f1;
	}

	void setFenmu(int f1)
	{
		fenmu=f1;
	}
	int getfenzi() { return fenzi; }
	int getfenmu() { return fenmu; }
	
	
	//b/a+d/c=(b*c+a*d)/(a*c)
	Fraction operator+(Fraction f)
	{
		Fraction tmp;
		tmp.fenzi=fenzi*f.fenmu+fenmu*f.fenzi;
		tmp.fenmu=fenmu*f.fenmu;
		return tmp;
	}
	
	friend Fraction operator-(Fraction f1,Fraction f2);
};

//b/a-d/c=(b*c-a*d)/(a*c)
Fraction operator-(Fraction f1,Fraction f2)
{
	Fraction tmp;
	tmp.fenzi=f1.fenzi*f2.fenmu-f1.fenmu*f2.fenzi;
	tmp.fenmu=f1.fenmu*f2.fenmu;
	//tmp.setFenzi(f1.getfenzi()*f2.getfenmu()-f1.getfenmu()*f2.getfenzi());
	//tmp.setFenmu(f1.getfenmu()*f2.getfenmu());
	return tmp;
}

int main()
{	
	Fraction f1(1,3);
	f1.display();
	cout << endl;
	
	Fraction f2(1,4);
	f2.display();
	cout << endl;
	
	Fraction f3=f1+f2;      //Fraction f3=f1.operator+(f2)
	f3.display();
	cout << endl;
	
	f3=f1-f2;       //operator-(f1,f2);
	f3.display();
	cout << endl;

#if 0	
	int n1=12;
	int n2=23;
	int sum=n1+n2;
#endif	
}	
