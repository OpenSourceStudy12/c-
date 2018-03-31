#include<sql_lrh.h>


int Sql::id = 0;

void Sql::client_info_read(MYSQL* mysql,list<Person*>& person)//用户信息读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		MYSQL_RES* res;
		string str = "select * from client";
		mysql_query(mysql,str.c_str());
		res = mysql_store_result(mysql);
		if(res)
		{
			int row = mysql_num_rows(res);
			int field = mysql_num_fields(res);
			int i,j;
			int num,cancel,state;
			string name,tel,add,pass1,pass2;
			float money;
			for(i=0;i<row;i++)
			{
				MYSQL_ROW r = mysql_fetch_row(res);
				for(j=0;j<field;j++)
				{
					switch(j)
					{
						case 0:
							num = atoi(r[j]);
							break;
						case 1:
							name = r[j];
							break;
						case 2:
							tel = r[j];
							break;
						case 3:
							add = r[j];
							break;
						case 4:
							pass1 = r[j];
							break;	
						case 5:
							pass2 = r[j];
							break;
						case 6:
							money = atof(r[j]);
							break;
						case 7:
							cancel  = atoi(r[j]);
							break;
						case 8:
							state = atoi(r[j]);
							break;
						default:
							break;
					}
				}
				//添加用户
				Client* tmp = new Client(num,name,tel,add,pass1,pass2,money,cancel,state);
				person.push_back(tmp);
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}

void Sql::shop_info_read(MYSQL* mysql,list<Person*>& person)//商家信息读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		MYSQL_RES* res;
		string str = "select * from shop";
		mysql_query(mysql,str.c_str());
		res = mysql_store_result(mysql);
		if(res)
		{
			int row = mysql_num_rows(res);
			int field = mysql_num_fields(res);
			int i,j;
			int num,policy;
			string name,tel,add,pass;
			float dc,full,rece,income,price_send;
			for(i=0;i<row;i++)
			{
				MYSQL_ROW r = mysql_fetch_row(res);
				for(j=0;j<field;j++)
				{
					switch(j)
					{
						case 0:
							num = atoi(r[j]);
							break;
						case 1:
							name = r[j];
							break;
						case 2:
							tel = r[j];
							break;
						case 3:
							add = r[j];
							break;
						case 4:
							pass = r[j];
							break;	
						case 5:
							income = atof(r[j]);
							break;
						case 6:
							policy = atoi(r[j]);
							break;
						case 7:
							price_send = atof(r[j]);
							break;
						case 8:
							dc = atof(r[j]);
							break;
						case 9:
							full = atof(r[j]);
							break;
						case 10:
							rece = atof(r[j]);
							break;
						default:
							break;
					}
				}
				//添加用户
				Shop* tmp = new Shop(num,name,tel,add,pass,income,policy,price_send,dc,full,rece);
				person.push_back(tmp);
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}

}
void Sql::courier_info_read(MYSQL* mysql,list<Person*>& person)//配送员信息读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		MYSQL_RES* res;
		string str = "select * from courier";
		mysql_query(mysql,str.c_str());
		res = mysql_store_result(mysql);
		if(res)
		{
			int row = mysql_num_rows(res);
			int field = mysql_num_fields(res);
			int i,j;
			int num;
			string name,tel,pass;
			for(i=0;i<row;i++)
			{
				MYSQL_ROW r = mysql_fetch_row(res);
				for(j=0;j<field;j++)
				{
					switch(j)
					{
						case 0:
							num = atoi(r[j]);
							break;
						case 1:
							name = r[j];
							break;
						case 2:
							tel = r[j];
							break;
						case 3:
							pass = r[j];
							break;	
						default:
							break;
					}
				}
				//添加用户
				Courier* tmp = new Courier(num,name,tel,pass);
				person.push_back(tmp);
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}
void Sql::dish_info_read(MYSQL* mysql,list<Person*>& person)//菜式信息读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		if(!person.empty())
		{
			list<Person*>::iterator it;
			int num;
			Shop* ps = NULL;
			for(it=person.begin();it!=person.end();it++)
			{
				num = (*it)->get_num();
				if(num>SHOP*1000 && num<=(SHOP+1)*1000)
				{
					ps = (Shop*)(*it);
					list<Dishes*>& dish = ps->get_dish();
					int s_num = ps->get_num();
					MYSQL_RES* res;
					string str = "select * from dishes where s_num = " + to_string(s_num);
					mysql_query(mysql,str.c_str());
					res = mysql_store_result(mysql);
					if(res)
					{
						int row = mysql_num_rows(res);
						int field = mysql_num_fields(res);
						int i,j;
						int ss_num;
						string classname,name;
						float price;
						for(i=0;i<row;i++)
						{
							MYSQL_ROW r = mysql_fetch_row(res);
							for(j=0;j<field;j++)
							{
								switch(j)
								{
									case 0:
										ss_num = atoi(r[j]);
										break;
									case 1:
										classname = r[j];
										break;
									case 2:
										name = r[j];
										break;
									case 3:
										price = atoi(r[j]);
										break;	
									default:
										break;
								}
							}
							//添加菜式
							Dishes* tmp = new Dishes(ss_num,classname,name,price);
							dish.push_back(tmp);
						}
					}
				}
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}

void Sql::cancel_read(MYSQL* mysql,list<Person*>& person)//退单请求读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		if(!person.empty())
		{
			list<Person*>::iterator it;
			int num;
			Shop* ps = NULL;
			for(it=person.begin();it!=person.end();it++)
			{
				num = (*it)->get_num();
				if(num>SHOP*1000 && num<=(SHOP+1)*1000)
				{
					ps = (Shop*)(*it);
					vector<int>& cancel = ps->get_cancel();
					int s_num = ps->get_num();
					MYSQL_RES* res;
					string str = "select * from cancel where s_num = " + to_string(s_num);
					mysql_query(mysql,str.c_str());
					res = mysql_store_result(mysql);
					if(res)
					{
						int row = mysql_num_rows(res);
						int field = mysql_num_fields(res);
						int i,j;
						int ss_num;
						string classname,name;
						float price;
						for(i=0;i<row;i++)
						{
							MYSQL_ROW r = mysql_fetch_row(res);
							for(j=0;j<field;j++)
							{
								switch(j)
								{
									case 0:
										ss_num = atoi(r[j]);
										break;
									default:
										break;
								}
							}
							//添加菜式
							cancel.push_back(ss_num);
						}
					}
				}
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}

void Sql::shop_com_read(MYSQL* mysql,list<Person*>& person)//商家评价读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		if(!person.empty())
		{
			list<Person*>::iterator it;
			int num;
			Shop* ps = NULL;
			for(it=person.begin();it!=person.end();it++)
			{
				num = (*it)->get_num();
				if(num>SHOP*1000 && num<=(SHOP+1)*1000)
				{
					ps = (Shop*)(*it);
					vector<map<string,string>>& com = ps->get_com();
					int s_num = ps->get_num();
					MYSQL_RES* res;
					string str = "select * from s_comment where s_num = " + to_string(s_num);
					mysql_query(mysql,str.c_str());
					res = mysql_store_result(mysql);
					if(res)
					{
						int row = mysql_num_rows(res);
						int field = mysql_num_fields(res);
						int i,j;
						string cl_num,name;
						for(i=0;i<row;i++)
						{
							MYSQL_ROW r = mysql_fetch_row(res);
							for(j=0;j<field;j++)
							{
								switch(j)
								{
									case 1:
										name = r[j];
										break;
									case 2:
										cl_num = r[j];
										break;
									default:
										break;
								}
							}
							//添加商家评价
							map<string,string> m;
							m[cl_num] = name;
							com.push_back(m);
						}
					}
				}
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}

void Sql::courier_com_read(MYSQL* mysql,list<Person*>& person)//配送员评价读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		if(!person.empty())
		{
			list<Person*>::iterator it;
			int num;
			Courier* pc = NULL;
			for(it=person.begin();it!=person.end();it++)
			{
				num = (*it)->get_num();
				if(num>COURIER*1000 && num<=(COURIER+1)*1000)
				{
					pc = (Courier*)(*it);
					vector<map<string,string>>& com = pc->get_com();
					int c_num = pc->get_num();
					MYSQL_RES* res;
					string str = "select * from c_comment where c_num = " + to_string(c_num);
					mysql_query(mysql,str.c_str());
					res = mysql_store_result(mysql);
					if(res)
					{
						int row = mysql_num_rows(res);
						int field = mysql_num_fields(res);
						int i,j;
						string cl_num,name;
						for(i=0;i<row;i++)
						{
							MYSQL_ROW r = mysql_fetch_row(res);
							for(j=0;j<field;j++)
							{
								switch(j)
								{
									case 1:
										name = r[j];
										break;
									case 2:
										cl_num = r[j];
										break;
									default:
										break;
								}
							}
							//添加商家评价
							map<string,string> m;
							m[cl_num] = name;
							com.push_back(m);
						}
					}
				}
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}

void Sql::order_read(MYSQL* mysql,list<Order*>& order)//订单读取
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		MYSQL_RES* res;
		string str = "select indent.num,indent.name,indent.price,indent.c_num,indent.c_name,indent.c_tel,indent.state,indent.Date,indent.Time,client.cl_num,client.cl_name,client.cl_tel,client.cl_add,shop.s_num,shop.s_name,shop.s_tel,shop.s_add from indent,client,shop where indent.cl_num=client.cl_num and indent.s_num=shop.s_num";
		mysql_query(mysql,str.c_str());
		res = mysql_store_result(mysql);
		if(res)
		{
			int o_num,cl_num,s_num,c_num,state;
			string name,cl_name,s_name,c_name,cl_tel,s_tel,c_tel,cl_add,s_add,date,time;
			float price;
			int row = mysql_num_rows(res);
			int field = mysql_num_fields(res);
			int i,j;
			for(i=0;i<row;i++)
			{
				MYSQL_ROW r = mysql_fetch_row(res);
				for(j=0;j<field;j++)
				{
					switch(j)
					{
						case 0:
							o_num = atoi(r[j]);
							break;
						case 1:
							name = r[j];
							break;
						case 2:
							price = atof(r[j]);
							break;
						case 3:
							c_num = atoi(r[j]);
							break;
						case 4:
							c_name = r[j];
							break;
						case 5:
							c_tel = r[j];
							break;
						case 6:
							state = atoi(r[j]);
							break;
						case 7:
							date = r[j];
							break;
						case 8:
							time = r[j];
							break;
						case 9:
							cl_num = atoi(r[j]);
							break;
						case 10:
							cl_name = r[j];
							break;
						case 11:
							cl_tel = r[j];
							break;
						case 12:
							cl_add = r[j];
							break;
						case 13:
							s_num = atoi(r[j]);
							break;
						case 14:
							s_name = r[j];
							break;
						case 15:
							s_tel = r[j];
							break;
						case 16:
							s_add = r[j];
							break;
						default:
							break;
					}		
				}
				Order* pr = new Order(o_num,name,cl_num,s_num,c_num,cl_name,s_name,c_name,cl_tel,s_tel,c_tel,cl_add,s_add,price,state,date,time);
				order.push_back(pr);
			}
		}
		mysql_close(mysql);
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}	
}

int Sql::order_state_read(MYSQL* mysql,int num)
{
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		MYSQL_RES* res;
		string str = "select state from indent where num = "+to_string(num);
		mysql_query(mysql,str.c_str());
		res = mysql_store_result(mysql);
		int state;
		if(res)
		{
			int row = mysql_num_rows(res);
			int field = mysql_num_fields(res);
			int i,j;
			for(i=0;i<row;i++)
			{
				MYSQL_ROW r = mysql_fetch_row(res);
				for(j=0;j<field;j++)
				{
					switch(j)
					{
						case 0:
							state = atoi(r[j]);
							break;
						default:
							break;
					}
				}
			}
		}
		mysql_close(mysql);
		return state;
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
}
bool Sql::info_update(MYSQL* mysql,string & str)//信息更新
{
	bool rest = false;
	if(mysql_real_connect(mysql,"localhost","root","123456","Order_system",0,NULL,0)!=NULL)
	{
		if(mysql_query(mysql,str.c_str())==0)
			rest = true;
	}
	else
	{
		cout<<"\n数据库连接失败..\n";
		sleep(1);
	}
	mysql_close(mysql);
	return rest;
}

/*
void Sql::shop_info_update(MYSQL*,string &)//商家信息更新
{}
void Sql::courier_info_update(M)//配送员信息更新
{}
void Sql::dish_info_update()//菜式信息更新
{}
void Sql::shop_com_update()//商家评价更新
{}
void Sql::courier_com_update()//配送员评价更新
{}
void Sql::order_update()//订单更新
{}
void Sql::cancel_update()//退单更新
{}
*/
#if 0
void Sql::client_info_write(MYSQL* mysql,list<Person*>& person)//用户信息保存
{
	mysql_query(mysql,"delete from indent");//清空订单
	mysql_query(mysql,"delete from client");//清空数据
	if(!person.empty())
	{	//提取用户
		vector<Client*>client;
		int num;
		for(auto tmp:person)
		{
			num = tmp->get_num();
			if(num>USER*1000 && num<=(USER+1)*1000)
			{
				client.push_back((Client*)tmp);
			}
		}
		if(!client.empty())
		{
			int money,cancel,state;
			mysql_query(mysql,"delete from client");//清空数据
			for(auto tmp:client)
			{
				num = tmp->get_num();
				money = tmp->get_money();
				cancel = tmp->get_cancel();
				state = tmp->get_state();
				string str = "insert into client values ("+to_string(num)+"," + 
					"'"+tmp->get_name()+"'," + "'"+tmp->get_tel()+"'," + 
					"'"+tmp->get_add()+"'," + "'"+tmp->get_passward()+"'," + 
					"'"+tmp->get_pass_pay()+"'," + to_string(money) +","+ to_string(cancel)+","+to_string(state)+")";
				mysql_query(mysql,str.c_str());//插入数据
			}
		}
	}
}
void Sql::shop_info_write(MYSQL* mysql,list<Person*>& person)//商家信息保存
{
	mysql_query(mysql,"delete from indent");//清空订单
	mysql_query(mysql,"delete from shop");//清空商家
	if(!person.empty())
	{	//提取商家
		vector<Shop*>shop;
		int num;
		for(auto tmp:person)
		{
			num = tmp->get_num();
			if(num>SHOP*1000 && num<=(SHOP+1)*1000)
			{
				shop.push_back((Shop*)tmp);
			}
		}
		if(!shop.empty())
		{
			int income,policy;
			float full,rece,dc,price_send;
			for(auto tmp:shop)
			{
				num = tmp->get_num();
				policy = tmp->get_policy();
				full  =tmp->get_full();
				rece = tmp->get_rece();
				dc = tmp->get_dc();
				price_send = tmp->get_price_send();
				income = tmp->get_income();
				string str = "insert into shop values ("+to_string(num)+"," + "'"+tmp->get_name()+"'," + "'"+tmp->get_tel()+"'," + "'"+tmp->get_add()+"'," + "'"+tmp->get_passward()+"'," + to_string(income)+","+to_string(policy)+","+to_string(price_send)+","+to_string(dc)+","+to_string(full)+","+to_string(rece)+")";
				mysql_query(mysql,str.c_str());//插入商家
				dish_info_write(mysql,tmp);//菜式信息保存
				cancel_write(mysql,tmp);//退单请求保存
				shop_com_write(mysql,tmp);//商家评价保存
			}
		}
	}


}
void Sql::courier_info_write(MYSQL* mysql,list<Person*>& person)//配送员信息保存
{
	mysql_query(mysql,"delete from courier");//清空数据
	if(!person.empty())
	{	//提取配送员
		vector<Courier*>courier;
		int num;
		for(auto tmp:person)
		{
			num = tmp->get_num();
			if(num>COURIER*1000 && num<=(COURIER+1)*1000)
			{
				courier.push_back((Courier*)tmp);
			}
		}
		if(!courier.empty())
		{
			for(auto tmp:courier)
			{
				num = tmp->get_num();
				string str = "insert into courier values ("+to_string(num)+"," + 
					"'"+tmp->get_name()+"'," + "'"+tmp->get_tel()+"'," + 
					"'"+tmp->get_passward()+"')";
				mysql_query(mysql,str.c_str());//插入数据
				courier_com_write(mysql,tmp);//配送员评价保存
			}
		}
	}
}
void Sql::dish_info_write(MYSQL* mysql,Shop* ps)//菜式信息保存
{
	list<Dishes*>& dish = ps->get_dish();
	if(!dish.empty())
	{
		list<Dishes*>::iterator it;
		int d_num,s_num;
		float price;
		string str;
		s_num = ps->get_num();
		for(it=dish.begin();it!=dish.end();it++)
		{
			d_num = (*it)->get_num();
			price = (*it)->get_price();
			str = "insert into dishes values (" + to_string(d_num)+",'"+
				(*it)->get_classname()+"','"+(*it)->get_name()+"',"+
				to_string(price)+","+to_string(ps->get_num())+")";
			//mysql_query(mysql,"delete from dishes");//清空菜式
			mysql_query(mysql,str.c_str());//插入菜式
		}
	}
}

void Sql::cancel_write(MYSQL* mysql,Shop* ps)//退单请求保存
{
	vector<int>& cancel = ps->get_cancel();
	if(!cancel.empty())
	{
		vector<int>::iterator it;
		int num,s_num;
		string str;
		s_num = ps->get_num();
		for(it=cancel.begin();it!=cancel.end();it++)
		{
			num = (*it);
			str = "insert into cancel values (" + to_string(num)+","+to_string(s_num)+")";
			mysql_query(mysql,str.c_str());
		}
	}
}

void Sql::shop_com_write(MYSQL* mysql,Shop* ps)//商家评价保存
{
	vector<map<string,string>>& com = ps->get_com();
	if(!com.empty())
	{
		vector<map<string,string>>::iterator it;
		string cl_num,comment;
		string str;
		int s_num = ps->get_num();
		for(it=com.begin();it!=com.end();it++)
		{
			for(auto tmp:(*it))
			{
				cl_num = tmp.first;
				comment = tmp.second;
				str = "insert into s_comment values (" +to_string(++id)+",'" + 
					comment +"',"+cl_num+","+ to_string(s_num)+")";
				mysql_query(mysql,str.c_str());//插入商家评价
			}
		}
	}
}

void Sql::courier_com_write(MYSQL* mysql,Courier* pc)//配送员评价保存
{
	vector<map<string,string>>& com = pc->get_com();
	if(!com.empty())
	{
		vector<map<string,string>>::iterator it;
		string cl_num,comment;
		string str;
		int c_num = pc->get_num();
		for(it=com.begin();it!=com.end();it++)
		{
			for(auto tmp:(*it))
			{
				cl_num = tmp.first;
				comment = tmp.second;
				str = "insert into c_comment values (" +to_string(++id)+",'" + 
					comment +"',"+cl_num+","+ to_string(c_num)+")";
				mysql_query(mysql,str.c_str());//插入配送员评价
			}
		}
	}

}
void Sql::order_write(MYSQL* mysql,list<Order*>& order)//订单保存
{
	mysql_query(mysql,"delete from indent");
	if(!order.empty())
	{
		int num,cl_num,s_num,c_num,state;
		float price;
		string str,date,time;
		mysql_query(mysql,"delete from indent");
		for(auto tmp:order)
		{
			num = tmp->get_num();
			cl_num = tmp->get_cl_num();
			s_num = tmp->get_s_num();
			c_num = tmp->get_c_num();
			price = tmp->get_price();
			state = tmp->get_state();
			tmp->get_time(date,time);
			str = "insert into indent values ("+to_string(num)+",'"+tmp->get_d_name()+"',"+to_string(price)+","+to_string(cl_num)+","+to_string(s_num)+","+to_string(c_num)+",'"+tmp->get_c_name()+"','"+tmp->get_c_tel()+"',"+to_string(state)+",'"+date+"','"+time+"')";
			mysql_query(mysql,str.c_str());
		}
	}
}

#endif

