#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
#if 0
    int num;
	cin >> num;
	cout << setw(4) << num << endl;
	cout << hex << num << endl;
#endif

#if 0
	int num;
	int n;
	cin >> num >> n;        //error cin >> num,n;
	//cin >> num;
	//cin >> n;
	cout << num << endl;
	cout << n << endl;
	cout << num << "," << n << endl << endl << endl;
	
	float f1;
	cin >> f1;
	cout << f1 << endl;
	cout <<  "f1=" <<  f1 << endl;                   //f1=12.1
#endif

#if 1
	int num;
	scanf("%d",&num);
	printf("%d\n",num);
	
	char str[10];
	scanf("%s",str);
	printf("%s\n",str);
#endif
}
