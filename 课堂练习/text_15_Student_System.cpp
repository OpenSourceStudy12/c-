#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<algorithm>
using namespace std;

#define ADD    1
#define MOD    2
#define SEARCH 3
#define PRINT  4
#define DEL    5
#define EXIT   0

class Stu
{
private:
	int num;
	string name;
	float score;
public:
	Stu()
	{
		num = 0;
		name = "no name";
		score = 0;
	}
	Stu(int num,string &name,float score)
	{
		this->name = name;
		this->num = num;
		this->score = score;
	}
	int getNum()
	{
		return num;
	}
	friend istream & operator>>(istream &,Stu &);
	friend ostream & operator<<(ostream &,Stu &);
	friend bool operator<(Stu &,Stu &);
	friend bool operator>(Stu &,Stu &);
	~Stu(){}
};

istream &operator>>(istream &in,Stu &s)
{
	cout<<"num:";
	in>>s.num;
	cout<<"name:";
	in>>s.name;
	cout<<"score:";
	in>>s.score;
	return in;
}

ostream &operator<<(ostream &out,Stu &s)
{
	out<<s.num<<'\t'<<s.name<<'\t'<<s.score<<endl;
	return out;
}

bool operator<(Stu &s1,Stu &s2)
{
	return(s1.score<s2.score);
}

bool operator>(Stu &s1,Stu &s2)
{
	return(s1.score>s2.score);
}

class Systerm
{
private:
	vector<Stu> s;   //或者 vector<Stu *>s;
public:
	Systerm();
	~Systerm();
	void start();
	void menu();
	void add_stu();
	void del_stu();
	void search_stu();
	void print_stu();
	void mod_stu();
	//static bool f1(Stu &s1,Stu &s2);
	static bool f2(Stu &s1,Stu &s2);
	void stu_sort();
	static void pt(Stu &stu);
};

Systerm::Systerm(){}
Systerm::~Systerm(){}
void Systerm::menu()
{
	system("clear");
	cout<<"\n学生管理系统\n\n";
	cout<<"1 add student\n";
	cout<<"2 mod student\n";
	cout<<"3 search student\n";
	cout<<"4 print student\n";
	cout<<"5 del student\n";
	cout<<"0 exit\n\n";
	cout<<"please select ";
}
void Systerm::start()
{
	int select;
	int flag = 1;
	while(flag)
	{
		menu();
		cin>>select;
		switch(select)
		{
			case ADD:
				add_stu();
				break;
			case MOD:
				mod_stu();
				break;
			case SEARCH:
				search_stu();
				break;
			case PRINT:
				print_stu();
				break;
			case DEL:
				del_stu();
				break;
			case EXIT:
				flag = 0;
				break;
			default:
				cout<<"输入无效，重新输入\n";
				sleep(1);
				break;
		}
	}
}

void Systerm::add_stu()
{
	system("clear");
	Stu t;
	cin>>t;	
	s.insert(s.begin(),t);
	cout<<"\n添加成功\n";	
	sleep(1);

}

void Systerm::del_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		//getchar();
		//getchar();
		sleep(1);
		return;
	}
	int i,num,flag=0;
	cout<<"请输入要删除学生的学号:";
	cin>>num;
	for(i=0;i<s.size();i++)
	{
		if(s[i].getNum()==num)
		{
			s.erase(s.begin()+i);
			cout<<"\n删除成功\n";		
			flag = 1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"\n该学生不存在\n";
	}
	//getchar();
	//getchar();
	sleep(1);


}

void Systerm::search_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		//getchar();
		//getchar();
		sleep(1);
		return;
	}
	int i,num,flag=0;
	cout<<"请输入学生学号:";
	cin>>num;
	for(i=0;i<s.size();i++)
	{
		if(s[i].getNum() == num)
		{
			cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
			cout<<s[i];
			//flag = 1;
			getchar();
			getchar();
			return;
		}
	}
	//if(!flag)
		cout<<"\n未查找到该学生\n";
	sleep(1);
}

void Systerm::pt(Stu &stu)
{
	cout<<stu;
}
void Systerm::print_stu()
{
	system("clear");
	int i;
	if(s.empty())
	{
		cout<<"no student..\n";
		//getchar();
		//getchar();
		sleep(1);
		return;
	}
	stu_sort();
	cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
	//for(i=0;i<s.size();i++)
	//{
	//	cout<<s[i];
	//}

	for_each(s.begin(),s.end(),pt);
	getchar();
	getchar();
}

void Systerm::mod_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		sleep(1);
		return;
	}
	int i,num,flag=0;
	cout<<"请输入要修改学的生学号:";
	cin>>num;
	for(i=0;i<s.size();i++)
	{
		if(s[i].getNum() == num)
		{
			Stu t;
			cin>>t;
			s.emplace(s.begin()+i,t);
			s.erase(s.begin()+i+1);
			cout<<"\n修改成功\n";
			cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
			cout<<s[i];
			getchar();
			getchar();
			return;
		}
	}
	cout<<"\n未找到该学生\n";
	sleep(1);
	//if(!flag)


}

//bool Systerm::f1(Stu &s1,Stu &s2)
//{
//	return s1<s2;
//}

bool Systerm::f2(Stu &s1,Stu &s2)
{
	return s1>s2;
}

void Systerm::stu_sort()
{
	sort(s.begin(),s.end());
}

int main()
{
	Systerm p;
	p.start();

}

