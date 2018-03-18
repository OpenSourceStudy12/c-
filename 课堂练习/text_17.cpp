#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int main()
{
	set<string>Mat;
	set<string>Pat;
	int i=1;
	string s;
	while(1)
	{
		cout<<"Mat的第"<<i<<"个朋友:";
		cin>>s;
		if(s=="exit")
			break;
		i++;
		Mat.insert(s);
	}
	i=1;
	while(1)
	{
		cout<<"Pat的第"<<i<<"个朋友:";
		cin>>s;
		if(s=="exit")
			break;
		i++;
		Pat.insert(s);
	}
	cout<<"Mat的朋友有:\n";
	for(auto tmp:Mat)
		cout<<tmp<<endl;

	cout<<endl<<"Pat的朋友有:\n";
	set<string>::iterator it;
	for(it=Pat.begin();it!=Pat.end();it++)
		cout<<*it<<endl;
#if 1
	int size = Mat.size()+Pat.size();
	vector<string>all(100);
	vector<string>::iterator ie;
	ie = set_union(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),all.begin());
	cout<<"Mat和Pat的朋友:\n";
	all.resize(ie-all.begin());
	for(auto tmp:all)
	{
		cout<<tmp<<endl;
	}

#endif

}
