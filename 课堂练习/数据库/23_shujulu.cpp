#include<iostream>
#include<mysql/mysql.h>  //数据库头文件
using namespace std;

//编译时 g++ 文件名 -lmysqlclient


int main()
{
	//定义句柄
	MYSQL mysql;
	//初始化
	if(mysql_init(&mysql) != NULL) //初始化
		cout<<"init success"<<endl;
	
	//连接数据库
	//"localhost" 或IP地址
	//连接成功返回句柄地址，失败返回NULL
	if(mysql_real_connect(&mysql,"localhost","root","123456",
	"stu_sys",0,NULL,0)!= NULL)
		cout<<"connect success\n";

#if 0
	//插入记录
	string str="insert into major (name,collage) values('huaxue','caiiaoxueyuan');";//sql命令
	if(mysql_query(&mysql,str.c_str())==0) //c_str将字符串对象转换为char*
		cout<<"insert success\n";
#endif

#if 0
	//更新记录
	string name;
	string collage;
	cin>>name;
#endif

	//查询
	string table; //表名
	cin>>table;
	MYSQL_RES *res;
	string sc_m;
	cin>>sc_m;
	string str="select * from "+table+" where degree < "+sc_m+" order by degree asc";
	cout<<str<<endl;
	mysql_query(&mysql,str.c_str());
	res=mysql_store_result(&mysql);
	if(res)
		cout<<"res\n";

	int row =mysql_num_rows(res);
	int field = mysql_num_fields(res);
	cout<<"row:"<<row<<' '<<"field:"<<field<<endl;
	int i,j;
	for(i=0;i<row;i++)
	{
		MYSQL_ROW r=mysql_fetch_row(res);
		for(j=0;j<field;j++)
		{
			cout<<r[j]<<'\t';
		
		}
		cout<<endl;
	}
	cout<<endl;

	mysql_close(&mysql);
	mysql_library_end();

	//int atoi(const char *);//char* 转化为int

}	
