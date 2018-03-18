#include<iostream>
#include<iomanip>
using namespace std;

int main(int argc ,char *argv[])
{
	cout<<"argc = "<<argc<<endl;
	if(argv[1] != NULL)
		cout<<"my name is "<<argv[1]<<endl;
	else
		cout<<"my name is a secert"<<endl;
	cout<<"my year is "<<argv[2]<<endl;
/*	int yearold;
	cin>>yearold;
	cout<<"my yearold is "<<yearold<<endl;
*/
/*
	int num1,num2;
	float num3;
	cout<<"num1 = ";
	cin>>num1;
	cout<<"num2 = ";
	cin>>num2;
	cout<<"num1 = "<<setw(4)<<num1<<endl<<"num2 = "<<setw(4)<<num2<<endl;
	cout<<"num3 = ";
	cin>>num3;
	cout<<"num3 = "<<num3<<endl;
*/
}

