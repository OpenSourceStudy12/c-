/*
#include<iostream>
//#include<>
using namespace std;

typedef struct stu
{
	int num;
	char name[15];
	int years;
	char sex;
	float score;
}Stu,*PStu;

int main()
{
	Stu student[5];
	int n = 3,i;
	for(i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个学生学号:";
		cin>>student[i].num;
		cout<<"请输入第"<<i+1<<"个学生姓名:";
		cin>>student[i].name;
		cout<<"请输入第"<<i+1<<"个学生年龄:";
		cin>>student[i].years;
		cout<<"请输入第"<<i+1<<"个学生性别:";
		cin>>student[i].sex;
		cout<<"请输入第"<<i+1<<"个学生成绩:";
		cin>>student[i].score;
	}
	//cout<<"学生信息"<<endl;
	cout<<"学号\t姓名\t年龄\t性别\t成绩\n";
	for(i=0;i<n;i++)
	{
		cout<<student[i].num<<"\t"<<student[i].name<<"\t"<<student[i].years<<"\t"<<
			student[i].sex<<"\t"<<student[i].score<<endl;
	
	}

}
*/


#include<iostream>
using namespace std;

typedef struct stu
{
	int num;
	char name[15];
	int years;
	char sex;
	float score;
}Stu,*PStu;

void set_data(Stu & student)
{
	cout<<"学生学号:";
	cin>>student.num;
	cout<<"姓名:";
	cin>>student.name;
	cout<<"年龄:";
	cin>>student.years;
	cout<<"性别:";
	cin>>student.sex;
	cout<<"成绩:";
	cin>>student.score;
}
void display(Stu &student)
{
	cout<<"学号:"<<student.num<<endl;
	cout<<"姓名:"<<student.name<<endl;
	cout<<"年龄:"<<student.years<<endl;
	cout<<"性别:"<<student.sex<<endl;
	cout<<"成绩:"<<student.score<<endl;
}


int main()
{
	Stu student;
	set_data(student);
	display(student);
	return 0;
}
 

 
 
 
 
 
 



