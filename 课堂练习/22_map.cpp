//map 字典 键 值 对 

#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<string,string>m1;

	m1["shanghai"]="shanghai";
	m1["jiangsu"]="nanjing";
	m1["anhui"]="hefei";

	map<string,string>::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->first<<' '<<it->second<<endl;
	}
	
	m1.insert(pair<string,string>("湖北","武汉"));
	m1["shangxi"]="taiyuan";
	
	cout<<"*************************\n";
	for(auto tmp:m1)
		cout<<tmp.first<<' '<<tmp.second<<endl;
		
	it=m1.find("湖北");
	cout<<"*************************\n";
	if(it!=m1.end())
	{
		cout<<(*it).first<<' '<<(*it).second<<endl;
		m1.erase(it);
		cout<<"*************************\n";
		for(auto tmp:m1)
			cout<<tmp.first<<' '<<tmp.second<<endl;
	}
	else
		cout<<"find fail..\n";
	
	

}

















