#include <iostream>
#include <mysql/mysql.h>

using namespace std;


int main()
{
	MYSQL mysql;
	if(mysql_init(&mysql))
		cout << "init" << endl;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	if(mysql_real_connect(&mysql,"localhost","root","123456","hotel_system_lrh",0,NULL,0) != NULL)
		cout << "connect\n";
		
	string num;
	string name;
	string str="insert into dishes values(1003,'鸡蛋',23.4)";
	cout << str << endl;
	if(mysql_query(&mysql,str.c_str())==0)
		cout << "insert\n";
	str="insert into dishes values(1004,'腐竹',23.4)";
	cout << str << endl;
	if(mysql_query(&mysql,str.c_str())==0)
		cout << "insert\n";
		
	
	str="select * from dishes";
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
	
	mysql_close(&mysql);
	
}
