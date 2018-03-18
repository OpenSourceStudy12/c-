#include <iostream>
#include <vector> 
using namespace std;

//容器
//序列式容器：vector，list，deque
//关联式容器：map，set

int main()
{
	vector<int> v1;
	v1.push_back(100);     //100
	v1.push_back(45);      //100 45
	v1.push_back(89);       //100 45 89
	
	v1.insert(v1.begin(),99);     //99, 100 45 89
	
	vector<int>::iterator it=v1.begin();
	it=it+2;
	v1.insert(it,22);                 //99 100 22 45 89
	
	for(auto tmp:v1)
		cout << tmp << endl;
	
	
	cout << "\n\n------------------分隔符---------------\n\n";	
	v1.pop_back();         //99 100 22 45
	
	//v1.erase(v1.begin());     //100 22 45
	v1.erase(v1.begin(),v1.begin()+2);    // 22 45
	
	for(auto tmp:v1)
		cout << tmp << endl;
		
	

#if 0
	vector<int> v1;
	if(v1.empty())     //empty()  判断数组是否为空
		cout << "empty vector\n";
	cout << v1.size() << endl;       //size() : 计算元素个数
	
	vector<int> v2(4,100);
	int i=0;
	for(i=0;i<v2.size();i++)           //1,通过下标遍历
	{
		cout << v2[i] << endl;
	}

	cout << "\n\n------------------分隔符---------------\n\n";
	int num[4]={2,4,1,5};
	vector<int> v3(num,num+4);
	
	vector<int>::iterator it;
	for(it=v3.begin();it!=v3.end();it++)           //2 通过迭代器 
	{
		cout << *it << "  ";
	}
	cout << endl;

	cout << "\n\n------------------分隔符---------------\n\n";
	vector<int> v4={6,7,4,9};
	for(auto tmp : v4)                                        //3 for()
	{
		cout << tmp << endl;
	}
	
	auto n1=123;       //auto: 类型自动推断
	auto f1=123.4;
	
	int arr[]={5,3,9,1,4};
	for(auto t : arr)
	{
		cout << t << "  ";
	}
	cout << endl;
#endif
}



