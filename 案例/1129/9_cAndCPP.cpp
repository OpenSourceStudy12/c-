#include <iostream>

using namespace std;

//g++ -c 9_cAndCPP.cpp -o f1.o
//gcc -c 9_cAndCPP.c -o f2.o
//g++ f1.o f2.o

//gcc 9_cAndCPP.c 9_cAndCPP.cpp -lstdc++

extern "C"
{
	void fun();
}

int main()
{
	fun();
}
