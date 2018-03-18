#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int a,b,c;
	cin >> a;
	cin >> b >> c;
	
	cout << "a=" << a << "\tb=" << b << "\tc=" << c << endl; 
	cout << setw(5) << hex << left << a << endl;        //setw(n) 设置输出宽度  hex：输出十六进制  left：左对齐
	cout << setw(2) << oct <<b << endl;
	
	float f1;
	cin >> f1;
	cout << "f1=" << f1 << endl;
}
