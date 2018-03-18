#include <iostream>
#include <mysql/mysql.h>

using namespace std;


int main()
{
	MYSQL mysql;
	if(mysql_init(&mysql))
		cout << "init" << endl;
	if(mysql_real_connect(&mysql,"localhost","root","123456","db_0512",0,NULL,0))
		cout << "connect\n";
		
	string tb_name;
	cin >> tb_name;
	string str="select * from "+tb_name;
	if(!mysql_query(&mysql,str.c_str()))
		cout << "select\n";
	MYSQL_RES *res=mysql_store_result(&mysql);
	if(res)
		cout << "res\n";
		
	int row=mysql_num_rows(res);
	int field=mysql_num_fields(res);
	cout << "row=" << row << "  field=" << field <<endl; 
	
	for(int i=0;i<row;i++)
	{
		MYSQL_ROW r=mysql_fetch_row(res);
		for(int j=0;j<field;j++)
		{
			cout << r[j] << "\t";
		}
		cout << endl;
	}
	
	
		
	
	/*	
	string num;
	string name;
	cin >> num;
	cin >> name;
	//string str="insert into stu values(" +num+",'" +name +"','1233','asdfg',90)";
	string str="update stu set name='"+name+"' where num="+num;
	cout << str << endl;
	if(mysql_query(&mysql,str.c_str())==0)
		cout << "update\n";
	*/
	
	mysql_close(&mysql);
	
}
