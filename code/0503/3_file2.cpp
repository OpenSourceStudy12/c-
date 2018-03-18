#include <iostream>
using namespace std;

//gcc 3_file.c 3_file2.cpp -lstdc++

//gcc -c 3_file.c -o f1.o
//g++ -c 3_file2.cpp -o f2.o
//g++ f1.o f2.o

extern "C"
{
	void fun();
}

void f1()
{
	cout << __FILE__ << "  " << __func__ << "  " << __LINE__ << endl;
}

int main()
{
	f1();
	cout << endl << endl;
	fun();
}
