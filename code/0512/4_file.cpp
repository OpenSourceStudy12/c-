#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int num[4]={0};
	ifstream in("num",ios::in|ios::binary);
	
	in.read((char *)num,16);
	
	for(auto tmp : num)
		cout << tmp << "  ";
	cout << endl;
	
	in.close();

#if 0
	int num[4]={4,2,3,1};
	ofstream out("num",ios::out|ios::binary);
	
	out.write((char *)num,sizeof(num));
	
	out.close();
#endif	
}
