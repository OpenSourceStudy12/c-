#include <iostream>
#include <set>
#include <algorithm> 
#include <iterator> 
using namespace std;

int main()
{
#if 0
	set<int> s1={3,2,6,5,9};
	set<int> s2={1,4,3,7,6};
	
	for(auto tmp : s1)
		cout << tmp << "  ";
	cout << endl;
	
	for(auto tmp : s2)
		cout << tmp << "  ";
	cout << endl;
	
	vector<int> v1(10);
	for(auto tmp : v1)
		cout << tmp << "  ";
	cout << endl;
	
	set<int> s3;
	
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.end()));
	for(auto tmp : s3)
		cout << tmp << "  ";
	cout << endl;
	
	/*set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),v1.begin());
	for(auto tmp : v1)
		cout << tmp << "  ";
	cout << endl;*/
#endif	
	

 #if 1
	set<int> s1;
	if(s1.empty())
		cout << "empty set\n";
	
	cout << s1.size() << endl;
	
	
	cout << "\n\n-----------------------------\n";
	int num[5]={5,1,4,1,2};
	set<int> s2(num,num+5);
	for(auto tmp : s2)
		cout << tmp << endl;
	
	cout << "\n\n-----------------------------\n";
	set<int> s3={4,1,8,7,3,2,1};
	for(auto tmp : s3)
		cout << tmp << endl;
	cout << s3.size() << endl;
#endif	
}
