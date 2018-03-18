#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

bool fun(int a,int b)
{
	return a>b;
}

int main()
{
	list<int> s1;
	if(s1.empty())
		cout << "empty link\n";
	
	s1.push_front(2);     //2
	s1.push_front(5);     //5->2
	s1.push_back(3);      //5->2->3
	
	list<int>::iterator it;
	for(it=s1.begin();it!=s1.end();it++)
	{
		cout << *it << endl;
	}
	
	it=s1.begin();
	//it=it+2;
	advance(it,2);
	s1.insert(it,100);       //5->2->100->3
	for(auto tmp:s1)
		cout << tmp << "  ";
	cout << endl;
	
	//s1.pop_front();     //2->100->3
	//s1.pop_back();      //2->100
	/*it=s1.begin();
	advance(it,3);
	s1.erase(it);  */     //5 2 100 3  ->   5 2 100

	s1.sort();            //5 2 100 3  
	for(auto tmp:s1)
		cout << tmp << "  ";
	cout << endl;
	
	
}
