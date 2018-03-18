//set 集合(无序，不重复)  输出时默认升序
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	set<int>s1={2,4,5,6,7,7};
	set<int>s2={6,5,4,4,3,6};
	
	s1.insert(34);
	s2.insert(65);
	for(auto tmp:s1)
		cout<<tmp<<' ';
	cout<<endl;
	for(auto tmp:s2)
		cout<<tmp<<' ';
	cout<<endl;
	//求并集
	vector<int>v(20);// 0 0 0 0 0 0 0 0 0 0
	set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),v.begin());
	for(auto tmp:v)
		cout<<tmp<<' ';
	cout<<endl;
	
	//求交集
	vector<int>s3(20);
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.end()));
	for(auto tmp:s3)
		cout<<tmp<<' ';
	cout<<endl;
	

	
	
#if 0
	set<int>s1;
	if(s1.empty())
		cout<<"null..";
	
	int num[5]={4,6,7,9，4};
	set<int>s2(num,num+5);
	for(auto tmp:s2)
		cout<<tmp<<endl; //4 6 7 9
	
	set<int>s3={3,2,3,56,7,7,6,34}
	for(auto tmp:s3)
		cout<<tmp<<endl; //2 3 6 7 34 56
#endif
}
