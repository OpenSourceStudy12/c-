#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Stu
{
private:
	int num;
	string name;
	float score;
public:
	Stu(int num=0,const string &name="no name",float score=0):num(num),name(name),score(score){}
	~Stu(){}
	friend ostream &operator<<(ostream &out,Stu &s);
	friend istream &operator>>(istream &in,Stu &s);

};
ostream &operator<<(ostream &out,Stu &s)
{
	out<<s.num<<' ';
	out<<s.name<<' ';
	out<<s.score<<endl;
	return out;
}

istream &operator>>(istream &in,Stu &s)
{
	in>>s.num;
	in>>s.name;
	in>>s.score;
	return in;
}

int main()
{

#if 1
	//读数据
	ifstream in("data.text",ios::in);
	int i;
	vector<Stu>s;
	Stu stu;
	for(i=0;i<5;i++)
	{
		in>>stu;
		s.push_back(stu);	
	}
	for(auto tmp:s)
		cout<<tmp;
#endif

#if 0
	//写数据
	Stu s1(1001,"qwe",65);
	Stu s2(1002,"sdf",76);
	Stu s3(1003,"wer",68);
	Stu s4(1004,"zxc",87);
	Stu s5(1005,"asd",67);

	vector<Stu>s;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);
	s.push_back(s4);
	s.push_back(s5);

	ofstream out("data.text",ios::out);	
	
	for(auto tmp:s)
	{
		out<<tmp<<endl;
	}
	out.close();
	return 0;
#endif
}
