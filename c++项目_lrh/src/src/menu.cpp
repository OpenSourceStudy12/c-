#include"menu.h"

System::System()
{

}

System::~System()
{
	list<Person*>::iterator it;
	for(it=person.begin();it!=person.end();)
	{
		delete (*it);
		person.erase(it);
		it=person.begin();
	}
	
	list<Order*>::iterator ie;
	for(ie=order.begin();ie!=order.end();)
	{
		delete (*ie);
		order.erase(ie);
		ie=order.begin();
	}
}
int System::hide_passward(string & pass)//输入密码，并不回显
{
	//printf("\t请输入密码\n");
	char passwd[7];
	char ch;
	int i = 0;
	setbuf(stdin,NULL);
	system("stty -echo raw");
	while(1)//输入密码
	{
		
		ch=getchar();
		putchar('*');
		if(ch!='\b')
		{
			passwd[i] = ch;
			if(ch=='\r')
			{
				break;
			}
			i++;
		}
		else
			putchar('\b');
		if(i>=6)
			break;
	}
	system("stty echo -raw");
	passwd[i] = '\0';
	pass = passwd;
	cout<<endl;
	return 0;
}
void System::system_init(list<Person*>& person,list<Order*>& order)
{
	bool f1 = false,f2 = false;
	if(mysql_init(&mysql)!=NULL)
		f1 = true;
	if(mysql_real_connect(&mysql,"localhost","root","123456","order_system",0,NULL,0)!=NULL)
		f2 = true;
	if(f1&f2)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t正在连接数据数据库....."<<endl;
		sleep(1);
		cout<<"\n\t\t\t\t数据库连接成功，正在数据数据....."<<endl;
		sql->client_info_read(&mysql,person);//用户信息读取
		sql->shop_info_read(&mysql,person);//商家信息读取
		sql->courier_info_read(&mysql,person);//配送员信息读取
		sql->dish_info_read(&mysql,person);//菜式信息读取
		sql->cancel_read(&mysql,person);//退单请求读取
		sql->shop_com_read(&mysql,person);//商家评价读取
		sql->courier_com_read(&mysql,person);//配送员评价读取
		sql->order_read(&mysql,order);//订单读取
		sleep(1);
		cout<<"\n\t\t\t\t数据加载完成,请稍等....."<<endl;
		sleep(1);
	
	}
	else
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t数据读取失败,请自行输入....."<<endl;
		sleep(1);
	
	}
	mysql_close(&mysql);
}

void System::system_exit()
{
	system("clear");
	if(mysql_real_connect(&mysql,"localhost","root","123456","order_system",0,NULL,0)!=NULL)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t正在退出系统.."<<endl;
		//sql->client_info_write(&mysql,person);//用户信息保存
		//sql->shop_info_write(&mysql,person);//商家信息保存
		//sql->courier_info_write(&mysql,person);//配送员信息保存
		//sql->order_write(&mysql,order);//订单保存
		//mysql_close(&mysql);
		//mysql_library_end();	
		sleep(1);
	}
	mysql_close(&mysql);
	mysql_library_end();

}

void System::head_print()
{
	system("clear");
	cout<<"\t\t\t*****************************************************************\n\n";
	cout<<"\t\t\t****************欢 迎 来 到 外 卖 订 餐 系 统********************\n\n";
	cout<<"\t\t\t*****************************************************************\n";
}


void System::main_menu()
{
	head_print();
	cout<<"\n\t\t\t\t                  请 输 入 选 项";
	cout<<"\n\t\t\t\t    ------------------------------------------\n";
	cout<<"\t\t\t\t    |            --1客 户 入 口--            |\n";
	cout<<"\t\t\t\t    |                                        |\n";
	cout<<"\t\t\t\t    |            --2商 家 入 口--            |\n";
	cout<<"\t\t\t\t    |                                        |\n";
	cout<<"\t\t\t\t    |            --3配 送 员 入 口--         |\n";
	cout<<"\t\t\t\t    |                                        |\n";
	cout<<"\t\t\t\t    |            --4管 理 员 入 口--         |\n";
	cout<<"\t\t\t\t    |                                        |\n";
	cout<<"\t\t\t\t    |            --0退       出--            |\n";
	cout<<"\t\t\t\t    ------------------------------------------\n";
}

void System::user_login_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   主   菜   单*************\n";	
	cout<<"\n\t\t\t\t                 请 输 入 选 项";
	cout<<"\n\t\t\t\t     ----------------------------------------\n";
	cout<<"\t\t\t\t     |         --1注           册--          |\n";
	cout<<"\t\t\t\t     |                                       |\n";
	cout<<"\t\t\t\t     |         --2登           录--          |\n";
	cout<<"\t\t\t\t     |                                       |\n";
	cout<<"\t\t\t\t     |         --0返           回--          |\n";      
	cout<<"\t\t\t\t     |                                       |\n";
	cout<<"\t\t\t\t     -----------------------------------------\n";

}

void System::user_main_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   管   理   菜   单*************\n";	
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t       --------------------------------------\n";
	cout<<"\t\t\t\t       |         --1订  单  管  理--        |\n";
	cout<<"\t\t\t\t       |                                    |\n";
	cout<<"\t\t\t\t       |         --2信  息  管  理--        |\n";
	cout<<"\t\t\t\t       |                                    |\n";
	cout<<"\t\t\t\t       |         --0返          回--        |\n";
	cout<<"\t\t\t\t       ---------------------------------------\n";
}

void System::user_info_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   信   息   管   理*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\n\t\t\t\t       -----------------------------------------\n";
	cout<<"\t\t\t\t       |         --1信   息   查   询--        |\n";
	cout<<"\t\t\t\t       |                                       |\n";
	cout<<"\t\t\t\t       |         --2信   息   修   改--        |\n";
	cout<<"\t\t\t\t       |                                       |\n";
	cout<<"\t\t\t\t       |         --3账   户   充   值--        |\n";
	cout<<"\t\t\t\t       |                                       |\n";
	cout<<"\t\t\t\t       |         --4登 录 密 码 修 改--        |\n";
	cout<<"\t\t\t\t       |                                       |\n";
	cout<<"\t\t\t\t       |         --5支 付 密 码 修 改--        |\n";
	cout<<"\t\t\t\t       |                                       |\n";
	cout<<"\t\t\t\t       |         --0返             回--        |\n";
	cout<<"\t\t\t\t       ------------------------------------------\n";
}

void System::user_order_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   订   单   管   理*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\n\t\t\t\t        --------------------------------------\n";
	cout<<"\t\t\t\t        |       --1下             单--      |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |       --2退             单--      |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |       --3确   认   接   单--      |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |       --4查   看   订   单--      |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |       --5评             价--      |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |       --0返             回--      |\n";
	cout<<"\t\t\t\t        --------------------------------------\n";
}

void System::shop_login_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t****************商   家   主   菜   单*************\n";
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t      ---------------------------------------\n";
	cout<<"\t\t\t\t      |        --1注            册--        |\n";
	cout<<"\t\t\t\t      |                                     |\n";
	cout<<"\t\t\t\t      |        --2登            录--        |\n";
	cout<<"\t\t\t\t      |                                     |\n";
	cout<<"\t\t\t\t      |        --0返            回--        |\n";
	cout<<"\t\t\t\t      ----------------------------------------\n";
}

void System::shop_main_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   管   理   菜   单*************\n";
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t        -------------------------------------\n";
	cout<<"\t\t\t\t        |        --1订  单  管  理--        |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |        --2菜  式  管  理--        |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |        --3优  惠  策  略--        |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |        --4账  户  管  理--        |\n";
	cout<<"\t\t\t\t        |                                   |\n";
	cout<<"\t\t\t\t        |        --0注          销--        |\n";
	cout<<"\t\t\t\t        --------------------------------------\n";
}

void System::shop_order_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   订   单   管   理*************\n";
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t       ---------------------------------------\n";
	cout<<"\t\t\t\t       |         --1接          单--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |         --2拒          单--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |         --3查  看  订  单--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |         --4查  看  评  论--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |         --0返          回--         |\n";
	cout<<"\t\t\t\t       ----------------------------------------\n";
}

void System::shop_dishes_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   菜   式   管   理*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\n\t\t\t\t         ------------------------------------\n";
	cout<<"\t\t\t\t         |        --1添  加  菜  式--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --2查  看  菜  式--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --3修  改  菜  式--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --4删  除  菜  式--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --0返          回--        |\n";
	cout<<"\t\t\t\t         --------------------------------------\n";
}

void System::shop_policy_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商  家  优  惠  策  略  管  理*************\n";
	cout<<"\n\t\t\t\t                     请 输 入 选 项";
	cout<<"\n\t\t\t\t          ------------------------------------\n";
	cout<<"\t\t\t\t          |        --1正  常  收  费--        |\n";
	cout<<"\t\t\t\t          |                                   |\n";
	cout<<"\t\t\t\t          |        --2打  折  策  略--        |\n";
	cout<<"\t\t\t\t          |                                   |\n";
	cout<<"\t\t\t\t          |        --3满  减  策  略--        |\n";
	cout<<"\t\t\t\t          |                                   |\n";
	cout<<"\t\t\t\t          |        --0返          回--        |\n";
	cout<<"\t\t\t\t          --------------------------------------\n";
}

void System::shop_info_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   信   息   管   理*************\n";
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t        --------------------------------------\n";
	cout<<"\t\t\t\t        |        --1信  息  查  询--         |\n";
	cout<<"\t\t\t\t        |                                    |\n";
	cout<<"\t\t\t\t        |        --2信  息  修  改--         |\n";
	cout<<"\t\t\t\t        |                                    |\n";
	cout<<"\t\t\t\t        |        --3密  码  修  改--         |\n";
	cout<<"\t\t\t\t        |                                    |\n";
	cout<<"\t\t\t\t        |        --0返          回--         |\n";
	cout<<"\t\t\t\t        ---------------------------------------\n";
}

void System::courier_login_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************配   送   员   主   菜   单*************\n";	
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t       ---------------------------------------\n";
	cout<<"\t\t\t\t       |        --1注           册--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |        --2登           录--         |\n";
	cout<<"\t\t\t\t       |                                     |\n";
	cout<<"\t\t\t\t       |        --0返           回--         |\n";
	cout<<"\t\t\t\t       ---------------------------------------\n";
}

void System::courier_main_menu()
{

	system("clear");
	cout<<"\n\t\t\t\t*************配  送  员  管  理   菜   单*************\n";	
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t        --------------------------------------\n";
	cout<<"\t\t\t\t        |        --1订  单  管  理--         |\n";
	cout<<"\t\t\t\t        |                                    |\n";
	cout<<"\t\t\t\t        |        --2信  息  管  理--         |\n";
	cout<<"\t\t\t\t        |                                    |\n";
	cout<<"\t\t\t\t        |        --0注          销--         |\n";
	cout<<"\t\t\t\t        --------------------------------------\n";
}

void System::courier_info_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************配  送  员   信   息   管   理*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\t\t\t\t           -------------------------------------\n";
	cout<<"\t\t\t\t         |        --1信  息  查  询--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --2信  息  修  改--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --3密  码  修  改--        |\n";
	cout<<"\t\t\t\t         |                                   |\n";
	cout<<"\t\t\t\t         |        --0返          回--        |\n";
	cout<<"\t\t\t\t         -------------------------------------\n";
}

void System::courier_order_man_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************配  送  员   订   单   管   理*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\n\t\t\t\t         --------------------------------------\n";
	cout<<"\t\t\t\t         |        --1抢          单--         |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |        --2送          单--         |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |        --3查  看  订  单--         |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |        --4查  看  评  价--         |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |        --0返          回--         |\n";
	cout<<"\t\t\t\t         --------------------------------------\n";
}

void System::admin_login_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   主   菜   单*************\n";
	cout<<"\n\t\t\t\t                   请 输 入 选 项";
	cout<<"\n\t\t\t\t      ---------------------------------------\n";
	cout<<"\t\t\t\t      |         --1登           录--        |\n";
	cout<<"\t\t\t\t      |                                     |\n";
	cout<<"\t\t\t\t      |         --0返           回--        |\n";
	cout<<"\t\t\t\t      ---------------------------------------\n";
}

void System::admin_main_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员    管   理   菜   单*************\n";
	cout<<"\n\t\t\t\t                    请 输 入 选 项";
	cout<<"\n\t\t\t\t        ---------------------------------------\n";
	cout<<"\t\t\t\t        |         --1管  理  客  户--         |\n";
	cout<<"\t\t\t\t        |                                     |\n";
	cout<<"\t\t\t\t        |         --2管  理  商  家--         |\n";
	cout<<"\t\t\t\t        |                                     |\n";
	cout<<"\t\t\t\t        |         --3管  理  配  送  员--     |\n";
	cout<<"\t\t\t\t        |                                     |\n";
	cout<<"\t\t\t\t        |         --4管  理  订  单--         |\n";
	cout<<"\t\t\t\t        |                                     |\n";
	cout<<"\t\t\t\t        |         --0注          销--         |\n";
	cout<<"\t\t\t\t        ---------------------------------------\n";
}

void System::admin_user_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   客   户   管   理*************\n";
	cout<<"\n\t\t\t\t                      请 输 入 选 项";
	cout<<"\n\t\t\t\t           -------------------------------------\n";
	cout<<"\t\t\t\t           |        --1查  看  客  户--        |\n";
	cout<<"\t\t\t\t           |                                   |\n";
	cout<<"\t\t\t\t           |        --2修  改  客  户--        |\n";
	cout<<"\t\t\t\t           |                                   |\n";
	cout<<"\t\t\t\t           |        --3删  除  客  户--        |\n";
	cout<<"\t\t\t\t           |                                   |\n";
	cout<<"\t\t\t\t           |        --0返          回--        |\n";
	cout<<"\t\t\t\t           -------------------------------------\n";

}

void System::admin_shop_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   商   家   管   理*************\n";
	cout<<"\n\t\t\t\t                      请 输 入 选 项";
	cout<<"\n\t\t\t\t          ---------------------------------------\n";
	cout<<"\t\t\t\t          |         --1查  看  商  家--         |\n";
	cout<<"\t\t\t\t          |                                     |\n";
	cout<<"\t\t\t\t          |         --2修  改  商  家--         |\n";
	cout<<"\t\t\t\t          |                                     |\n";
	cout<<"\t\t\t\t          |         --3删  除  商  家--         |\n";
	cout<<"\t\t\t\t          |                                     |\n";
	cout<<"\t\t\t\t          |         --0返          回--         |\n";
	cout<<"\t\t\t\t          ---------------------------------------\n";

}

void System::admin_courier_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   配   送   员   管   理*************\n";
	cout<<"\n\t\t\t\t                      请 输 入 选 项";
	cout<<"\n\t\t\t\t           --------------------------------------\n";
	cout<<"\t\t\t\t           |       --1查  看  配 送 员--        |\n";
	cout<<"\t\t\t\t           |                                    |\n";
	cout<<"\t\t\t\t           |       --2修  改  配 送 员--        |\n";
	cout<<"\t\t\t\t           |                                    |\n";
	cout<<"\t\t\t\t           |       --3删  除  配 送 员--        |\n";
	cout<<"\t\t\t\t           |                                    |\n";
	cout<<"\t\t\t\t           |       --0返            回--        |\n";
	cout<<"\t\t\t\t           --------------------------------------\n";
}

void System::admin_order_menu()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   订   单   管   理*************\n";
	cout<<"\n\t\t\t\t                     请 输 入 选 项";
	cout<<"\n\t\t\t\t         --------------------------------------\n";
	cout<<"\t\t\t\t         |         --1查  看  订  单--        |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |         --2修  改  订  单--        |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |         --3删  除  订  单--        |\n";
	cout<<"\t\t\t\t         |                                    |\n";
	cout<<"\t\t\t\t         |         --0返          回--        |\n";
	cout<<"\t\t\t\t         --------------------------------------\n";
}


void System::start()
{
	system("clear");
	system_init(person,order);//读取数据
	int select;
	while(select)
	{
		main_menu();
		cin>>select;
		switch(select)
		{
			case USER:
				user_deal();
				break;
			case SHOP:
				shop_deal();
				break;
			case COURIER:
				courier_deal();
				break;
			case ADMIN:
				admin_deal();
				break;
			case EXIT:
				select = 0;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::user_deal()
{
	int select,n;
	Client* pcl;
	while(select)
	{
		pcl = NULL;
		user_login_menu();
		cin>>select;
		switch(select)
		{
			case ENROLL:
				user_enroll();
				break;
			case LOGIN:
				pcl = user_login();
				if(pcl!=NULL)
					user_man(pcl);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::user_man(Client* pcl)
{
	user_cancel_order_deal(pcl);
	int select;
	while(select)
	{
		user_main_menu();
		cin>>select;
		switch(select)
		{
			case USER_ORDER:
				user_order_man(pcl);
				break;
			case USER_INFO:
				user_info_man(pcl);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::user_order_man(Client* pcl)
{
	int select;
	while(select)
	{
		user_order_man_menu();
		cin>>select;
		switch(select)
		{
			case ORDER_ADD:
				user_order_add(pcl);
				break;
			case ORDER_DEL:
				user_order_del(pcl);
				break;
			case ORDER_RECEIVE:
				user_order_get(pcl);
				break;
			case ORDER_LOOK:
				user_order_search(pcl);
				break;
			case COMMENT:
				user_comment(pcl);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::user_info_man(Client* pcl)
{
	int select;
	while(select)
	{
		user_info_man_menu();
		cin>>select;
		switch(select)
		{
			case INFO_DISPLAY:
				user_info_display(pcl);
				break;
			case INFO_MODIFY:
				user_info_modify(pcl);
				break;
			case TOP_UP:
				user_top_up(pcl);//账户充值
				break;
			case USER_PASS:
				user_pass_modify(pcl);//账户充值
				break;
			case USER_PASS_PAY:
				user_pay_modify(pcl);//账户充值
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}


void System::shop_deal()
{
	int select,n;
	Shop* ps;
	while(select)
	{
		ps = NULL;
		shop_login_menu();
		cin>>select;
		switch(select)
		{
			case ENROLL:
				shop_enroll();
				break;
			case LOGIN:
				ps = shop_login();
				if(ps!=NULL)
					shop_man(ps);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::shop_man(Shop* ps)
{
	shop_cancel_order_deal(ps);
	int select;
	while(select)
	{
		shop_main_menu();
		cin>>select;
		switch(select)
		{
			case SHOP_ORDER:
				shop_order_man(ps);
				break;
			case SHOP_DISHES:
				shop_dishes_man(ps);
				break;
			case SHOP_POLICY:
			    	 shop_policy_man(ps);
				 break;
			case SHOP_INFO:
				shop_info_man(ps);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::shop_order_man(Shop* ps)
{
	int select;
	while(select)
	{
		shop_order_man_menu();
		cin>>select;
		switch(select)
		{
			case ORDER_GET:
				shop_order_receive(ps);
				break;
			case ORDER_REJECT:
				shop_order_reject(ps);
				break;
			case ORDER_SEARCH:
				shop_order_search(ps);
				break;
			case COMMENT_LOOK:
				shop_comment_look(ps);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::shop_dishes_man(Shop* ps)
{
	int select;
	while(select)
	{
		shop_dishes_man_menu();
		cin>>select;
		switch(select)
		{
			case DISHES_ADD:
				dishes_add(ps);
				break;
			case DISHES_LOOK:
				dishes_look(ps);
				break;
			case DISHES_MODIFY:
				dishes_modify(ps);
				break;
			case DISHES_DEL:
				dishes_del(ps);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::shop_policy_man(Shop* ps)
{
	int select;
	while(select)
	{
		shop_policy_man_menu();
		cin>>select;
		switch(select)
		{
			case NORMAL:
				policy(ps,NORMAL);
				break;
			case DISCOUNT:
				policy(ps,DISCOUNT);
				break;
			case FULL_REDECE:
				policy(ps,FULL_REDECE);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::shop_info_man(Shop* ps)
{
	int select;
	while(select)
	{
		shop_info_man_menu();
		cin>>select;
		switch(select)
		{
			case INFO_DISPLAY:
				shop_info_display(ps);
				break;
			case INFO_MODIFY:
				shop_info_modify(ps);
				break;
			case PASS_MOD:
				shop_pass_modify(ps);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::courier_deal()
{
	int select,n;
	Courier* pc;
	while(select)
	{
		pc = NULL;
		courier_login_menu();
		cin>>select;
		switch(select)
		{
			case ENROLL:
				courier_enroll();
				break;
			case LOGIN:
				pc = courier_login();
				if(pc!=NULL)
					courier_man(pc);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::courier_man(Courier* pc)
{
	int select;
	while(select)
	{
		courier_main_menu();
		cin>>select;
		switch(select)
		{
			case COURIER_ORDER:
				courier_order_man(pc);
				break;
			case COURIER_INFO:
				courier_info_man(pc);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::courier_order_man(Courier* pc)
{
	int select;
	while(select)
	{
		courier_order_man_menu();
		cin>>select;
		switch(select)
		{
			case ORDER_GET:
				courier_get_order(pc);
				break;
			case ORDER_SEND:
				courier_send_order(pc);
				break;
			case ORDER_SEARCH:
				courier_order_look(pc);
				break;
			case COMMENT_LOOK:
				courier_comment_look(pc);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::courier_info_man(Courier* pc)
{
	int select;
	while(select)
	{
		courier_info_man_menu();
		cin>>select;
		switch(select)
		{
			case INFO_DISPLAY:
				courier_info_display(pc);
				break;
			case INFO_MODIFY:
				courier_info_modify(pc);
				break;
			case PASS_MOD:
				courier_pass_modify(pc);
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::admin_deal()
{
	int select=1;
	while(select)
	{
		admin_login_menu();
		//getchar();
		cin>>select;
		switch(select)
		{
			case ENROLL:
				admin_login();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}

}

void System::admin_man()
{
	int select;
	while(select)
	{
		admin_main_menu();
		cin>>select;
		switch(select)
		{
			case USER_MAN:
				admin_man_user();
				break;
			case SHOP_MAN:
				admin_man_shop();
				break;
			case COURIER_MAN:
				admin_man_courier();
				break;
			case ORDER_MAN:
				admin_man_order();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::admin_man_user()
{
	int select;
	while(select)
	{
		admin_user_menu();
		cin>>select;
		switch(select)
		{
			case DISPLAY:
				admin_user_display();
				break;
			case MODIFY:
				admin_user_mod();
				break;
			case DEL:
				//admin_user_del();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::admin_man_shop()
{
	int select;
	while(select)
	{
		admin_shop_menu();
		cin>>select;
		switch(select)
		{
			case DISPLAY:
				admin_shop_display();
				break;
			case MODIFY:
				admin_shop_mod();
				break;
			case DEL:
				//admin_shop_del();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::admin_man_courier()
{
	int select;
	while(select)
	{
		admin_courier_menu();
		cin>>select;
		switch(select)
		{
			case DISPLAY:
				admin_courier_display();
				break;
			case MODIFY:
				admin_courier_mod();
				break;
			case DEL:
				admin_courier_del();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}

void System::admin_man_order()
{
	int select;
	while(select)
	{
		admin_order_menu();
		cin>>select;
		switch(select)
		{
			case DISPLAY:
				admin_order_display();
				break;
			case MODIFY:
				//admin_order_mod();
				break;
			case DEL:
				admin_order_del();
				break;
			case EXIT:
				select = EXIT;
				break;
			default:
				cout<<"输入无效，请重新输入\n";
				break;
		}
	}
}
//注册检查
bool System::enroll_check(string & name,int people)
{
	bool flag = true;
	string c_name;
	int num;
	if(!person.empty())
	{
		for(auto tmp:person)
		{
			c_name = tmp->get_name();
			num = tmp->get_num();
			if(people==USER)
			{
				if(num>USER*1000 && num<=(USER+1)*1000 && name==c_name)
				{	
					flag=false;	
					break;
				}
			}
			else if(people==SHOP)
			{
				if(num>SHOP*1000 && num<=(SHOP+1)*1000 && name==c_name)
				{	
					flag=false;	
					break;
				}
			}
			else
			{
				if(num>COURIER*1000 && num<=(COURIER+1)*1000 && name==c_name)
				{	
					flag=false;	
					break;
				}
			}
		}
	}
	return flag;
}

void System::user_enroll()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   注   册*************\n";	
	int num=0,temp;
	//找最大编号
	if(!person.empty())
	{
		for(auto tmp:person)
		{
			temp = tmp->get_num();
			if(temp > USER*1000 && temp <= (USER+1)*1000 && temp > num)
				num = temp;
		}		
	}

	if(num==0)
	{
		num = USER*1000 + 1;
	}
	else
		num += 1;
	
	string name,tel,add;
	cout<<"\n\n\n\n\t\t\t\t\t    帐    号：";
	while(1)
	{
		setbuf(stdin,NULL);
		getline(cin,name);
		if(enroll_check(name,USER))
			break;
		else
			cout<<"\n该帐号已注册，请重新输入\n";
		cout<<"\t\t\t\t\t    帐    号：";

	}
	cout<<"\n\t\t\t\t\t    联系方式：";
	cin>>tel;
	cout<<"\n\t\t\t\t\t    收货地址：";
	setbuf(stdin,NULL);
	getline(cin,add);
	Person *p = new Client(num,name,tel,add);//构造 输入客户编号 
	//cin>>*(Client*)p;//重载输入客户
	person.push_back(p);//添加客户
	string str = "insert into client values("+to_string(num)+",'"+name+"','"+tel+"','"+add+"','"+"111111"+"','"+"123456"+"',"+to_string(0)+","+to_string(0)+","+to_string(2)+")";
	sql->info_update(&mysql,str);
	cout<<"\n\t\t\t\t注册成功,初始登陆密码为："<<p->get_passward()<<"\n\t\t\t\t支付密码为："<<((Client*)p)->get_pass_pay()<<"\n\t\t\t\t请登录后立即修改！\n";
	sleep(1);
}

Client* System::user_login()
{
	system("clear");
	cout<<"\n\t\t\t\t*************客   户   登   录*************\n";	
	string name,pass;
	cout<<"\n\n\n\n\n\t\t\t\t\t    用户名：";
	setbuf(stdin,NULL);
	getline(cin,name);
	cout<<"\n\t\t\t\t\t    密  码：";
	hide_passward(pass);
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>USER*1000 && num<=(USER+1)*1000)
		{
			if(((Client*)tmp)->get_name() == name && ((Client*)tmp)->get_passward() == pass)
			{
				//pcl = (Client*)tmp;
				cout<<"\n\t\t\t\t\t    正  在  登  录.....\n";
				sleep(1);
				return (Client*)tmp;

			}
		}
	}
	cout<<"\n用户名或密码不对，请重新登录\n";
	sleep(1);
	return NULL;
}

void System::user_order_add(Client* pcl)
{
	if(!person.empty())
	{
		int flag,temp;
		system("clear");
		vector<Shop*>ps;
		//所有商家
		for(auto tmp:person)
		{
			temp = tmp->get_num();
			if(temp > SHOP*1000 && temp <= (SHOP+1)*1000)
			{
				list<Dishes*>& dish = ((Shop*)tmp)->get_dish();
				if(!dish.empty())
				{
					cout<<endl<<((Shop*)tmp)->get_name()<<"("<<((Shop*)						tmp)->get_num()<<")"<<" : ";
					//商家收费方式
					flag = ((Shop*)tmp)->get_policy();
					if(flag == NORMAL)
						cout<<"正常收费"<<endl;
					else if(flag == DISCOUNT)
					{
						cout<<"打 "<<((Shop*)tmp)->get_dc()<<" 折"<<endl;
					}
					else
					{
						cout<<"满 "<<((Shop*)tmp)->get_full()<<" 减 "									<<((Shop*)tmp)->get_rece()<<endl;
					}

					ps.push_back((Shop*)tmp);
				

				}
			}
		}

		if(!ps.empty())
		{
			int s_num;
			//校验商家编号
			while(1)
			{
				cout<<endl<<"\t选择商家(0取消)：";
				cin>>s_num;
				if(s_num>SHOP*1000 && s_num<=(SHOP+1)*1000)
					break;
				else if(s_num == 0)
					return;
				else
				{
					cout<<endl<<"\t编号不正确！";
					cin>>s_num;
				}
			}
			
			vector<Shop*>::iterator it;
			for(it=ps.begin();it!=ps.end();it++)
			{
				if(s_num==(*it)->get_num())
				{
					list<Dishes*>& dish = (*it)->get_dish();
					if(!dish.empty())
					{
						for(auto tm:dish)
						{
							cout<<"\t----------------------------------"<<endl;
							cout<<"\t菜式编号："<<tm->get_num()<<endl;
							cout<<"\t菜式种类："<<tm->get_classname()<<endl;
							cout<<"\t菜    名："<<tm->get_name()<<endl;
							cout<<"\t价    格："<<tm->get_price()<<endl;
							cout<<"\t----------------------------------"<<endl;
						}
						string name;//订单内容
						int num,n,i=0;
						float price1=0,price2=0;
						//选择订单
						while(1)
						{
							flag=1;
							cout<<endl<<"\t选择菜式编号(0结束)：";
							cin>>num;
							for(auto tmp:dish)
							{
								if(tmp->get_num()==num)
								{
									flag=0;
									i++;
									cout<<endl<<"\t选择数量：";
									cin>>n;
									price1 += tmp->get_price() * n;	
									name += tmp->get_name()+"*"+to_string											(n)+" ";
								}
							}
							if(num==0 && i==0)
								return;
							else if(num==0 && i!=0)
								break;	
							if(flag)
							{
								cout<<endl<<"\t菜式编号有误，重新输入"<<endl;
							}
						}
						//计算总价
						price1 += (*it)->get_price_send();
						
						cout<<endl<<"\t订单 "<<name<<" + 配送费："<<(*it)->get_price_send()<<" 元后,价钱为："<<price1<<" 元\n\t商家";
						flag = (*it)->get_policy();//获取商家优惠策略
						Price* p;
						if(flag == NORMAL)
						{
							Normal pr;
							p = &pr;
							cout<<"正常收费";
						}
						else if(flag == DISCOUNT)
						{
							Discount pr((*it)->get_dc());
							p = &pr;
							cout<<"打 "<<(*it)->get_dc()<<" 折";
						}
						else
						{
							Full_rece pr((*it)->get_full(),(*it)->get_rece());
							p = &pr;
							cout<<"满 "<<(*it)->get_full()<<" 减 "<<(*it)->get_rece();
						}

						price2 = p->price_count(price1);//计算价格
						
						//下单确认
						cout<<" 后总价为："<<price2<<" 元"<<"\n\n\t确认下单(y or n)？";
						char select;
						while(1)
						{
							cin>>select;
							while(getchar()!='\n');
							if(select!='y' && select!='Y' && select!='n' && select!='N')
							{
								cout<<endl<<"输入不正确，请重新输入：";
							}
							else
								break;
						}
					
						//下单
						if(select=='y' || select=='Y')
						{
							string pass;
							cout<<endl<<"支付密码：";
							hide_passward(pass);
							if(pass==pcl->get_pass_pay())//密码核对
							{
								if(pcl->sub_money(price2))//判断余额是否充足，扣钱
								{

									//找最大订单编号
									int n=0;
									for(auto tm:order)
									{
										if(tm->get_num()>n)
											n = tm->get_num();
									}
									n += 1;

									//生成订单
									Order* pt = new Order(n,name,pcl->get_num(),(*it)->get_num(),pcl->get_name(),(*it)->get_name(),pcl->get_tel(),(*it)->get_tel(),pcl->get_add(),(*it)->get_add(),price2);
									count_time((*pt));
									order.push_back(pt);
									string date,time;
								       	pt->get_time(date,time);
									string str = "insert into indent values ("+to_string(n)+",'"+name+"',"+to_string(price2)+","+to_string(pcl->get_num())+","+to_string((*it)->get_num())+","+to_string(0)+",'"+"no name"+"','"+"no tel"+"',"+to_string(0)+",'"+date+"','"+time+"')";
									sql->info_update(&mysql,str);
									
									str = "update client set cl_money = cl_money-"+to_string(price2)+" where cl_num = "+to_string(pcl->get_num());
									sql->info_update(&mysql,str);

									cout<<endl<<"下单成功！"<<endl;
									sleep(1);
									return;
								}
								else
								{
									cout<<endl<<"账户余额不足，请及时充值.."<<endl;
									sleep(1);
									return;
								}
							}
							else
							{
								cout<<endl<<"密码错误，支付失败.."<<endl;
								sleep(1);
							}
							return;
						}
						return;
					}
					cout<<endl<<"\t该商家暂无菜式！"<<endl;
					sleep(1);
				}
			}
			cout<<endl<<"无该菜式编号！"<<endl;
			sleep(1);
		}
		else
		{
			cout<<endl<<"当前无商家！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<endl<<"当前无商家！"<<endl;
		sleep(1);
	}
}
//用户退单
void System::user_order_del(Client* pcl)
{
	system("clear");
	if(pcl->get_state()==CANCEL)
	{
		if(!order.empty())
		{
			int cl_num = pcl->get_num(),n;
			list<Order*>order1;//存储未完成的订单
			list<Order*>::iterator it;
			//提取当前用户订单
			for(it=order.begin();it!=order.end();it++)
			{
				n = (*it)->get_cl_num();
				if(n==cl_num)
				{
					if((*it)->get_state()<receive && (*it)->get_state()>reject)	
						order1.push_back((*it));
				}
			}

			//显示订单
			if(!order1.empty())
			{
				cout<<"可退的订单："<<endl;
				for(auto tmp:order1)
				{
					tmp->order_display(USER);
					cout<<endl;
				}
				//退单
				int num;//存储退单编号
				cout<<endl<<"\t请选择退单的编号：";
				cin>>num;

				//根据订单编号查找订单
				Order* pr = NULL;
				for(auto tmp:order1)
				{
					if(num==tmp->get_num())
					{
						pr = tmp;
						break;
					}
				}

				if(pr!=NULL)
				{
					int nu = pr->get_s_num();//获取商家编号
					Shop* ps = NULL;//查找商家
					for(auto tm:person)
					{
						if(nu == tm->get_num())
						{
							ps = (Shop*)tm;
							break;
						}
					}
					if(ps!= NULL)
					{
						pcl->set_cancel(num);
						pcl->set_state(EXIST);
						vector<int>& can = ps->get_cancel();
						can.push_back(num);

						string str = "update client set cancel = "+to_string(num)+", state = "+to_string(EXIST)+" where cl_num = "+to_string(cl_num);
						sql->info_update(&mysql,str);

						str = "insert into cancel values ("+to_string(num)+","+to_string(nu)+")";
						sql->info_update(&mysql,str);

						cout<<endl<<"退单请求发送成功，等待商家回复！"<<endl;
						sleep(1);
					}
				}
				else
				{
					cout<<"\n输入的退单不可退或编号不存在.."<<endl;
					sleep(1);
				}
			}
			else
			{
				cout<<"\t无可退的订单！"<<endl;
				sleep(1);
			}
		}
		else
		{
			cout<<"\t无可退的订单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\n\n\n\n\n\t\t\t有退单未处理，暂不能退单"<<endl;
		sleep(1);
	}
}

void System::user_cancel_order_deal(Client* pcl)
{
	int state = pcl->get_state();
	if(state==REJECT || state==RECEIVE)
	{
		system("clear");
		//int can = pcl->get_cancel();
		if(state==RECEIVE)
		{
			cout<<"\n\n\n\n\t\t商家已同意您的退单请求,订单费用已转回您的账户"<<endl;
			sleep(1);
		}
		else if(state==REJECT)
		{
			cout<<"\n\n\n\n\t\t商家拒绝了您的退单请求"<<endl;
			sleep(1);
		}
		pcl->set_cancel(0);
		pcl->set_state(CANCEL);
		string str = "update client set cancel = "+to_string(0)+", state = "+to_string(CANCEL)+" where cl_num = "+to_string(pcl->get_num());
		sql->info_update(&mysql,str);
	}

/*
	if(!can.empty())
	{
		system("clear");
		cout<<"订单号 ";
		for(auto tmp:can)
		{
			cout<<tmp<<' ';
		}
		cout<<"已成功退单"<<endl;
		vector<int>::iterator it;
		it = can.begin();
		while(it!=can.end())
		{
			can.erase(it);
			it = can.begin();
		}
	}
*/
}

void System::user_order_search(Client* pcl)
{
	system("clear");
	if(!order.empty())
	{
		int num = pcl->get_num(),n;
		list<Order*>order1,order2;//分别保存未完成和完成订单
		list<Order*>::iterator it;
		//提取当前用户订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_cl_num();
			if(n==num)
			{
				if((*it)->get_state() < receive && (*it)->get_state()>reject)	
					order1.push_back((*it));
				else
					order2.push_back((*it));
			}
		}

		int flag = 0;
		//显示未完成订单
		if(!order1.empty())
		{
			cout<<"未完成订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(USER);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<"无未完成订单！"<<endl;
			sleep(1);
		}
		//显示已完成订单
		if(!order2.empty())
		{
			cout<<endl<<"已完成订单："<<endl;
			for(auto tmp:order2)
			{
				tmp->order_display(USER);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<endl<<"无已完成订单！"<<endl;
			sleep(1);
		}
		if(flag)
		{
			getchar();
			getchar();
		}
	}
	else
	{
		cout<<"\t暂无订单信息！"<<endl;
		sleep(1);
	}

}

void System::user_order_get(Client* pcl)
{
	system("clear");
	if(!order.empty())
	{
		int cl_num = pcl->get_num(),n,flag=0;
		list<Order*>order1;//存储配送员已派送的订单
		list<Order*>::iterator it;
		//提取当前用户订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_cl_num();
			if(n==cl_num)
			{
				if((*it)->get_state() == send)	
					order1.push_back((*it));
			}
		}

		//显示订单
		if(!order1.empty())
		{
			cout<<"已送达订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(USER);
				cout<<endl;
			}
			//确认接单
			vector<int>order2;//存储接单编号
			int num;
			while(1)
			{
				flag=0;
				cout<<endl<<"\t确认接单的编号(0结束)：";
				cin>>num;
				if(num==0)
					break;
				for(auto tmp:order1)
				{
					if(tmp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					order2.push_back(num);
				else
					cout<<"\n未找到该订单"<<endl;
			}
			if(!order2.empty())
			{
				for(auto tmp:order2)
				{
					flag=0;
					for(auto temp:order1)
					{
						if(tmp==temp->get_num())
						{
							flag=1;
							temp->set_state(receive);
							//将订单的钱转给商家
							int nu = temp->get_s_num();
							Shop* ps = NULL;
							for(auto tm:person)
							{
								if(nu == tm->get_num())
									ps = (Shop*)tm;
							}

							if(ps==NULL)
								break;
							ps->set_income(temp->get_price());
							string str = "update indent set state = "+to_string(receive)+" where num = "+to_string(tmp);
							sql->info_update(&mysql,str);

							str = "update shop set s_income = s_income + "+to_string(temp->get_price())+" where s_num = "+to_string(ps->get_num());
							sql->info_update(&mysql,str);
							break;
						}	
					}
				}
				if(flag)
				{
					cout<<endl<<"确认接单成功！"<<endl;
					sleep(1);
				}
				else
				{
					cout<<"接单失败..";
					sleep(1);
				}
			}
		}
		else
		{
			cout<<"\n\t暂无送达的订单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\t暂无送达的订单！"<<endl;
		sleep(1);
	}
}

void System::user_comment(Client* pcl)
{
	system("clear");
	static int id;
	int cl_num = pcl->get_num();
	vector<Order*>order1;
	for(auto tmp:order)
	{
		if(tmp->get_cl_num()==cl_num)
		{
			if(tmp->get_state()==receive)
			{
				order1.push_back(tmp);
			}
		}
	}
	if(!order1.empty())
	{
		cout<<"待评价的订单："<<endl<<endl;
		for(auto tmp:order1)
		{
			tmp->order_display(USER);
			cout<<endl;
		}
		int num,flag;
		while(1)
		{
			flag=0;
			cout<<endl<<"\t要评价的单号(0取消)：";
			cin>>num;
			if(num==0)
				return;
			for(auto tmp:order1)
			{
				if(tmp->get_num()==num)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
			else
				cout<<"\n未找到该订单！\n";
		}

		string com_shop,com_cour;
		cout<<endl<<"\t评价商家：";
		setbuf(stdin,NULL);
		getline(cin,com_shop);

		cout<<endl<<"\t评价配送员：";
		setbuf(stdin,NULL);
		getline(cin,com_cour);

		for(auto tmp:order1)
		{
			if(num==tmp->get_num())
			{
				int c_num = tmp->get_c_num();
				int s_num = tmp->get_s_num();
				for(auto temp:person)
				{
					if(temp->get_num()==s_num || temp->get_num()==c_num)
					{
						string str;
						if(temp->get_num()==s_num)
						{
							map<string,string> m;
							m[to_string(pcl->get_num())] = com_shop;
							vector<map<string,string>>& com = ((Shop*)temp)->get_com();
							com.push_back(m);
							str = "insert into s_comment values ("+to_string(id++)+",'"+com_shop+"',"+to_string(cl_num)+","+to_string(s_num)+")";
						}
						else
						{
							map<string,string> m;
							m[to_string(pcl->get_num())] = com_cour;
							vector<map<string,string>>& com = ((Courier*)temp)->get_com();
							com.push_back(m);	
							str = "insert into c_comment values ("+to_string(id++)+",'"+com_cour+"',"+to_string(cl_num)+","+to_string(c_num)+")";
						}
						sql->info_update(&mysql,str);
					
					}
				}
				tmp->set_state(comment);
				string str = "update indent set state = "+to_string(comment)+" where num = "+to_string(num);
				sql->info_update(&mysql,str);
				cout<<endl<<"\t评价完成！"<<endl;
				sleep(1);
				return;
			}
		}
		cout<<endl<<"该定单不存在或还未完成！"<<endl;
		sleep(1);
	}
	else
	{
		cout<<endl<<"暂无可评价订单！"<<endl;
		sleep(1);
	}
}

void System::user_info_display(Client* pcl)
{
	system("clear");
	cout<<"个人信息："<<endl;
	cout<<endl<<"\t编    号："<<pcl->get_num()<<endl;
	cout<<endl<<"\t昵    称："<<pcl->get_name()<<endl;
	cout<<endl<<"\t联系方式："<<pcl->get_tel()<<endl;
	cout<<endl<<"\t收货地址："<<pcl->get_add()<<endl;
	//cout<<endl<<"\t登陆密码："<<pcl->get_passward()<<endl;
	cout<<endl<<"\t账户余额："<<pcl->get_money()<<endl;
	getchar();
	getchar();
}

void System::user_info_modify(Client* pcl)
{
	system("clear");
	string str,pass,tel,add;
	cout<<"客户信息修改："<<endl;
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	if(pass==pcl->get_passward())
	{
		system("clear");
		cout<<"客户信息修改："<<endl;
		cout<<endl<<"\t联系方式：";
		cin>>tel;
		cout<<endl<<"\t用户地址：";
		setbuf(stdin,NULL);
		getline(cin,add);
		pcl->tel_modify(tel);
		pcl->add_modify(add);

		str = "update client set cl_tel = '"+tel+"',cl_add = '"+add+"' where cl_num = "+to_string(pcl->get_num());
		sql->info_update(&mysql,str);

		cout<<endl<<"\t用户信息修改成功！"<<endl;
		sleep(1);
	}
	else
	{
		cout<<"\n登录密码不正确！\n";
		sleep(1);
	}
	//cin>>(*pcl);
	//pcl->pass_modify();
}

void System::user_pass_modify(Client* pcl)
{

	string pass,pass1,pass2,str;
	system("clear");
	cout<<"用户登录密码修改：\n";
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	if(pcl->get_passward()==pass)
	{
		system("clear");
		cout<<"用户密码修改：\n";
		while(1)
		{
			cout<<"\n\t请输入新的登录密码：";
			hide_passward(pass1);
			//cin>>pass1;
			cout<<endl<<"\t请再次输入新密码：";
			hide_passward(pass2);
			//cin>>pass2;
			if(pass1 == pass2)
			{
				pcl->pass_modify(pass1);

				str = "update client set cl_pass = '"+pass1+"' where cl_num = "+to_string(pcl->get_num());
				sql->info_update(&mysql,str);

				break;
			}
			else
				cout<<"\n两次输入的密码不一致";
		}

		cout<<endl<<"\t登陆密码修改成功！\n";
		sleep(1);
	}
	else
	{
		cout<<"\n密码不正确！\n";
		sleep(1);
	}
}

void System::user_pay_modify(Client* pcl)
{

	string pass,pass1,pass2,str;
	system("clear");
	cout<<"支付密码修改：\n";
	cout<<"\n\t输入原支付密码：";
	hide_passward(pass);
	//cin>>pass;
	if(pcl->get_pass_pay()==pass)
	{
		system("clear");
		cout<<"支付密码修改：\n";
		while(1)
		{
			cout<<"\n\t请输入新的支付密码：";
			hide_passward(pass1);
			//cin>>pass1;
			cout<<endl<<"\t请再次输入新密码：";
			hide_passward(pass2);
			//cin>>pass2;
			if(pass1 == pass2)
			{
				pcl->pass_pay_modify(pass1);

				str = "update client set cl_pass_pay = '"+pass1+"' where cl_num = "+to_string(pcl->get_num());
				sql->info_update(&mysql,str);

				break;
			}
			else
				cout<<"\n两次输入的密码不一致";
		}

		cout<<endl<<"\t支付密码修改成功！\n";
		sleep(1);
	}
	else
	{
		cout<<"\n密码不正确！\n";
		sleep(1);
	}
}

void System::user_top_up(Client* pcl)
{
	system("clear");
	cout<<"账户充值："<<endl;
	cout<<endl<<"\t充值金额(0到500之间)：";	
	float money;
	while(1)
	{
		cin>>money;
		if(money>=0 && money<=500)
			break;
		else
			cout<<endl<<"\t输入有误，请重新输入.."<<endl;
	}
	pcl->set_money(money);

	string str = "update client set cl_money = cl_money+"+to_string(money)+" where cl_num = "+to_string(pcl->get_num());
	sql->info_update(&mysql,str);

	cout<<endl<<"\t充值成功！"<<endl;
	sleep(1);
}

void System::shop_enroll()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   注   册*************\n";	
	int num=0,temp;
	//找最大编号
	if(!person.empty())
	{
		for(auto tmp:person)
		{
			temp = tmp->get_num();
			if(temp > SHOP*1000 && temp <= (SHOP+1)*1000 && temp > num)
				num = temp;
		}		
	}
	if(num==0)
	{
		num = SHOP*1000 + 1;
	}
	else
		num += 1;

	string name,tel,add;
	cout<<"\n\n\n\n\t\t\t\t\t    帐    号：";
	while(1)
	{
		setbuf(stdin,NULL);
		getline(cin,name);
		if(enroll_check(name,SHOP))
			break;
		else
			cout<<"\n该帐号已注册，请重新输入\n";
		cout<<"\t\t\t\t\t    帐    号：";

	}
	cout<<"\n\t\t\t\t\t    联系方式：";
	cin>>tel;
	cout<<"\n\t\t\t\t\t    地    址：";
	setbuf(stdin,NULL);
	getline(cin,add);
	Person *p = new Shop(num,name,tel,add);//构造 输入商家编号 
	//cin>>*(Shop*)p;//重载输入商家
	person.push_back(p);//添加商家
	string str = "insert into shop values("+to_string(num)+",'"+name+"','"+tel+"','"+add+"','"+"222222"+"',"+to_string(0)+","+to_string(1)+","+to_string(0)+","+to_string(1)+","+to_string(0)+","+to_string(0)+")";
	sql->info_update(&mysql,str);
	cout<<"\n\t\t\t\t注册成功，初始登陆密码为："<<p->get_passward()<<" 请登录后修改\n";
	sleep(1);
}

Shop* System::shop_login()
{
	system("clear");
	cout<<"\n\t\t\t\t*************商   家   登   录*************\n";	
	string name,pass;
	cout<<"\n\n\n\n\n\t\t\t\t\t    用户名：";
	setbuf(stdin,NULL);
	getline(cin,name);
	cout<<"\n\t\t\t\t\t    密  码：";
	hide_passward(pass);
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>SHOP*1000 && num<=(SHOP+1)*1000)
		{
			if(((Shop*)tmp)->get_name() == name && ((Shop*)tmp)->get_passward() == pass)
			{
				cout<<"\n\t\t\t\t\t    正  在  登  录....\n";
				sleep(1);
				return (Shop*)tmp;
			}
		}
	}
	cout<<"\n用户名或密码不对，请重新登录！\n";
	sleep(1);
	return NULL;
}
void System::shop_order_receive(Shop* ps)
{
	system("clear");
	if(!order.empty())
	{
		int s_num = ps->get_num(),n;
		list<Order*>order1;//存储用户刚下的订单
		list<Order*>::iterator it;
		//提取当前用户订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_s_num();
			if(n==s_num)
			{
				if((*it)->get_state() == book)	
					order1.push_back((*it));
			}
		}

		//显示订单
		if(!order1.empty())
		{
			cout<<"用户订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(SHOP);
				cout<<endl;
			}
			//接单
			vector<int>order2;//存储接单编号
			int num,flag;
			while(1)
			{
				flag=0;
				cout<<endl<<"\t接单的编号(0结束)：";
				cin>>num;
				if(num==0)
					break;
				for(auto temp:order1)
				{
					if(temp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag=1)
					order2.push_back(num);
				else
				{
					cout<<"\n该定单不存在"<<endl;
				}
			}
			
			if(!order2.empty())
			{
				for(auto tmp:order2)
				{
					for(auto temp:order1)
					{
						if(tmp==temp->get_num())
						{
							temp->set_state(take);
							string str = "update indent set state = "+to_string(take)+" where num = "+to_string(tmp);
							sql->info_update(&mysql,str);
							break;
						}	
					}
				}
				cout<<endl<<"接单成功！"<<endl;
				sleep(1);
			}
		}
		else
		{
			cout<<"\n\t暂无用户下单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\t暂无用户下单！"<<endl;
		sleep(1);
	}
}
void System::shop_order_reject(Shop* ps)
{
	system("clear");
	if(!order.empty())
	{
		int s_num = ps->get_num(),n;
		list<Order*>order1;//存储用户刚下的订单
		list<Order*>::iterator it;
		//提取当前用户订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_s_num();
			if(n==s_num)
			{
				if((*it)->get_state() == book)	
					order1.push_back((*it));
			}
		}

		//显示订单
		if(!order1.empty())
		{
			cout<<"用户订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(SHOP);
				cout<<endl;
			}
			//拒单
			vector<int>order2;//存储拒单编号
			int num,flag;
			while(num)
			{
				flag=0;
				cout<<endl<<"\t拒单的编号(0结束)：";
				cin>>num;
				if(num==0)
					break;
				for(auto tmp:order1)
				{
					if(tmp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					order2.push_back(num);
				else
					cout<<"\n未找到该定单"<<endl;
			}
			if(!order2.empty())
			{
				for(auto tmp:order2)
				{
					for(auto temp:order1)
					{
						if(tmp==temp->get_num())
						{
							temp->set_state(reject);
							string str = "update indent set state = "+to_string(reject)+" where num = "+to_string(tmp);
							sql->info_update(&mysql,str);
							break;
						}	
					}
				}
				cout<<endl<<"拒单成功！"<<endl;
				sleep(1);
			}
		}
		else
		{
			cout<<"\n\t暂无用户下单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\t暂无用户下单！"<<endl;
		sleep(1);
	}
}
void System::shop_order_search(Shop* ps)
{
	system("clear");
	if(!order.empty())
	{
		int num = ps->get_num(),n;
		list<Order*>order1,order2;//分别保存未完成和完成订单
		list<Order*>::iterator it;
		//提取当前用户订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_s_num();
			if(n==num)
			{
				if((*it)->get_state() < receive && (*it)->get_state()>reject)	
					order1.push_back((*it));
				else
					order2.push_back((*it));
			}
		}

		int flag = 0;
		//显示未完成订单
		if(!order1.empty())
		{
			cout<<"未完成订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(SHOP);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<"无未完成订单！"<<endl;
			sleep(1);
		}
		//显示已完成订单
		if(!order2.empty())
		{
			cout<<endl<<"已完成订单："<<endl;
			for(auto tmp:order2)
			{
				tmp->order_display(SHOP);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<endl<<"无已完成订单！"<<endl;
			sleep(1);
		}
		if(flag)
		{
			getchar();
			getchar();
		}
	}
	else
	{
		cout<<"\t暂无订单信息！"<<endl;
		sleep(1);
	}

}

void System::shop_comment_look(Shop* ps)
{
	system("clear");
	cout<<"商家评价："<<endl;
	vector<map<string,string>>& com = ps->get_com();
	if(!com.empty())
	{
		for(auto tmp:com)
		{
			for(auto temp:tmp)
			{
				cout<<endl<<temp.first<<" : "<<temp.second<<endl;
			}
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"无用户评论！"<<endl;
		sleep(1);
	}
}

//用户退单处理
void System::shop_cancel_order_deal(Shop* ps)
{
	vector<int>& can = ps->get_cancel();
	if(!can.empty())
	{
		vector<int>::iterator it;
		int cl_num,num,flag;
		string str;
		vector<int>can_num;
		system("clear");
		cout<<"用户退单处理："<<endl;
		vector<Order*>order1;
		for(auto tmp:can)
		{
			for(auto temp:order)
			{
				if(tmp==temp->get_num())
				{
					if(temp->get_state()<receive && temp->get_state()!=reject)
					{
						order1.push_back(temp);		
						break;
					}
					break;
				}
			}
		}
		//显示退单请求
		//cout<<endl<<"\t用户退单请求如下："<<endl;
		for(auto tmp:order1)
		{
			tmp->order_display(SHOP);
			cout<<endl;
		}
		//校验单号
		while(1)
		{
			flag=0;
			cout<<endl<<"\t同意退单的编号(以0结束)：";
			cin>>num;
			if(num==0)
				break;
			else
			{
				for(auto tmp:order1)
				{
					if(tmp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					can_num.push_back(num);
				else
					cout<<endl<<"订单号不存在"<<endl;
			}
		}
		//若拒绝所有，删除所有退单请求
		if(can_num.empty())
		{
			for(auto tmp:can)
			{
				for(auto temp:order1)
				{
					if(temp->get_num()==tmp)
					{
						cl_num = temp->get_cl_num();
						for(auto tm:person)
						{
							if(tm->get_num()==cl_num)
							{
								((Client*)tm)->set_state(REJECT);
								string str = "update client set state = "+to_string(REJECT)+" where cl_num = "+to_string(cl_num);
								sql->info_update(&mysql,str);

								break;
							}
						}
						break;
					}
				}
			}

			it=can.begin();
			while(it!=can.end())
			{
				can.erase(it);
				it=can.begin();
			}
			str = "delete from cancel";
			sql->info_update(&mysql,str);
			return;
		}

		//退单处理
		for(auto temp:order1)
		{
			flag=0;
			num = temp->get_num();
			cl_num = temp->get_cl_num();
			for(auto tm:person)
			{
				if(tm->get_num()==cl_num)
				{
					for(auto tmp:can_num)
					{
						if(tmp==num)
						{
							flag=1;
							break;
						}
					}
					if(flag)//同意退单
					{
						temp->set_state(cancel);
						((Client*)tm)->set_money(temp->get_price());
						((Client*)tm)->set_state(RECEIVE);
						str = "update indent set state = "+to_string(cancel)+" where num = "+to_string(num);
						sql->info_update(&mysql,str);

						str = "update client set state = "+to_string(RECEIVE)+",cl_money = cl_money+"+to_string(temp->get_price())+" where cl_num = "+to_string(cl_num);
					}
					else//拒绝退单
					{
						((Client*)tm)->set_state(REJECT);
						str = "update client set state = "+to_string(REJECT)+" where cl_num = "+to_string(cl_num);
						
					}

					sql->info_update(&mysql,str);
					break;
				}
			}
		}
		it=can.begin();
		while(it!=can.end())
		{
			can.erase(it);
			it=can.begin();
		}
		str = "delete from cancel";
		sql->info_update(&mysql,str);
	}
}

bool System::dishes_check(list<Dishes*>& dish,string & c_n,string & n)
{
	bool flag = true;
	if(!dish.empty())
	{
		for(auto tmp:dish)
		{
			if(tmp->get_classname()==c_n && tmp->get_name()==n)
			{	
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void System::dishes_add(Shop* ps)
{
	string c_n,name;
	float price;
	list<Dishes*>& dish = ps->get_dish();
	int num=0,temp;	

	//找最大编号
	if(!dish.empty())
	{
		for(auto tmp:dish)
		{
			temp = tmp->get_num();
			if(temp > num)
				num = temp;
		}		
	}
	if(num==0)
	{
		num = ps->get_num() * 100;
	}
	else
		num++;
	
	system("clear");
	cout<<"菜式添加：\n";
	while(1)
	{
		cout<<"\n\t菜式类：";
		setbuf(stdin,NULL);//清空缓冲区
		getline(cin,c_n);
		cout<<"\n\t菜式名：";
		setbuf(stdin,NULL);
		getline(cin,name);
		if(dishes_check(dish,c_n,name))
			break;
		else
			cout<<"\n此菜式已存在！\n";
	}
	cout<<"\n\t价  格：";
	cin>>price;
	Dishes* tp = new Dishes(num,c_n,name,price);
	dish.push_back(tp);
	string str = "insert into dishes values ("+to_string(num)+",'"+c_n+"','"+name+"',"+to_string(price)+","+to_string(ps->get_num())+")";
	sql->info_update(&mysql,str);

	cout<<"\n\t添加成功！"<<endl;
	sleep(1);

}

void System::dishes_look(Shop* ps)
{
	list<Dishes*>& dish = ps->get_dish();
	system("clear");
	cout<<"所有菜式：\n";
	if(!dish.empty())
	{
		for(auto tmp:dish)
		{
			tmp->dishes_display();
			cout<<endl;
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tno dishes!"<<endl;
		sleep(1);
	}
}

void System::dishes_modify(Shop* ps)
{
	list<Dishes*>& dish = ps->get_dish();
	dishes_look(ps);
	if(!dish.empty())
	{
		int num;
		float price;
		cout<<"\n\t请输入要修改菜式的编号(0取消)：";
		cin>>num;
		if(num==0)
			return;
		for(auto tmp:dish)
		{
			if(num == tmp->get_num())
			{

				cout<<"\n\t价   格：";
				cin>>price;
				tmp->price_modify(price);

				string str = "update dishes set d_price ="+to_string(price)+"where d_num = "+to_string(num);
				sql->info_update(&mysql,str);

				cout<<"\n菜式价格修改成功！"<<endl;
				sleep(1);
				return;	
			}
		}
		cout<<"\n未找到该菜式编号！"<<endl;
		sleep(1);
	}
}

void System::dishes_del(Shop* ps)
{
	list<Dishes*>& dish = ps->get_dish();
	dishes_look(ps);
	if(!dish.empty())
	{
		int num;
		cout<<"\n\t请输入要删除的菜式编号(0取消)：";
		cin>>num;
		if(num==0)
			return;
		list<Dishes*>::iterator it;
		for(it=dish.begin();it!=dish.end();it++)
		{
			if(num == (*it)->get_num())
			{
				delete (*it);
				dish.erase(it);
				string str = "delete from dishes where d_num = "+to_string(num);
				sql->info_update(&mysql,str);

				cout<<"\n菜式删除成功！"<<endl;
				sleep(1);
				return;	
			}
		}
		cout<<"\n未找到该菜式编号！"<<endl;
		sleep(1);
	}
}

void System::policy(Shop* ps,int flag)
{
	string str;
	system("clear");
	cout<<"优惠策略设置：\n";
	if(flag == NORMAL)
	{
		ps->set_policy(NORMAL);
		str = "update shop set policy = "+to_string(NORMAL)+" where s_num = "+to_string(ps->get_num());
	}
	else if(flag == DISCOUNT)
	{
		ps->set_policy(DISCOUNT);
		float dc;
		while(1)
		{
			cout<<"\n\t折  扣：";
			cin>>dc;
			if(dc<=0 || dc>=1)
				cout<<"\n设置有误";
			else
				break;
		}
		ps->discount_modify(dc);
		str = "update shop set policy = "+to_string(DISCOUNT)+ ",discount = "+to_string(dc)+" where s_num = "+to_string(ps->get_num());
	}
	else
	{
		ps->set_policy(FULL_RECE);
		float full,re;
		while(1)
		{
			cout<<"\n\t满  额：";
			cin>>full;
			cout<<"\n\t减  额：";
			cin>>re;
			if(full>0 && re>0 && full>re)
				break;
			else
				cout<<"\n设置有误";
		}
		ps->full_rece_modify(full,re);
		str = "update shop set policy = "+to_string(FULL_RECE)+",full = "+to_string(full)+",rece = "+to_string(re)+" where s_num = "+to_string(ps->get_num());
	}
	sql->info_update(&mysql,str);

	cout<<"\n设置成功！"<<endl;
	sleep(1);
}
//void System::discount_policy()
//{}
//void System::full_redece_policy()
//{}
void System::shop_info_display(Shop* ps)
{
	system("clear");
	cout<<"商家信息："<<endl;
	cout<<endl<<"\t编    号："<<ps->get_num()<<endl;
	cout<<endl<<"\t名    称："<<ps->get_name()<<endl;
	cout<<endl<<"\t联系方式："<<ps->get_tel()<<endl;
	cout<<endl<<"\t地    址："<<ps->get_add()<<endl;
	cout<<endl<<"\t收费方式：";
	if(ps->get_policy()==NORMAL)
		cout<<"正常收费"<<endl;
	else if(ps->get_policy()==DISCOUNT)
		cout<<"打"<<ps->get_dc()<<"折"<<endl;
	else
		cout<<"满"<<ps->get_full()<<"减"<<ps->get_rece()<<endl;

	cout<<endl<<"\t配送费用："<<ps->get_price_send()<<endl;
	cout<<endl<<"\t收    入："<<ps->get_income()<<endl;
	getchar();
	getchar();
}

void System::shop_info_modify(Shop* ps)
{
	system("clear");
	string str,pass,tel,add;
	float p_s;
	cout<<"商家信息修改："<<endl;
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	//cin>>pass;
	if(pass==ps->get_passward())
	{
		system("clear");
		cout<<"商家信息修改："<<endl;
		cout<<endl<<"\t联系方式：";
		getline(cin,tel);
		cout<<endl<<"\t商家地址：";
		setbuf(stdin,NULL);
		getline(cin,add);
		cout<<endl<<"\t配送费用：";
		cin>>p_s;
		ps->tel_modify(tel);
		ps->add_modify(add);
		ps->set_price_send(p_s);
		str = "update shop set s_tel = '"+tel+"',s_add = '"+add+"',price_send = "+to_string(p_s)+" where s_num = "+to_string(ps->get_num());
		sql->info_update(&mysql,str);

		cout<<endl<<"\t商家信息修改成功！"<<endl;
		sleep(1);
	}
	else
	{
		cout<<"\n登录密码不正确！\n";
		sleep(1);
	}
	//cin>>(*pcl);
	//pcl->pass_modify();
}
/*
void System::shop_info_modify(Shop* ps)
{
	system("clear");
	cout<<"商家信息修改：";
	cin>>*ps;
	ps->pass_modify();
	cout<<"修改成功！"<<endl;
	sleep(1);	
}
*/

void System::shop_pass_modify(Shop* ps)
{

	string pass,pass1,pass2,str;
	system("clear");
	cout<<"商家密码修改：\n";
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	//cin>>pass;
	if(ps->get_passward()==pass)
	{
		system("clear");
		cout<<"商家密码修改：\n";
		while(1)
		{
			cout<<"\n\t请输入新的登录密码：";
			hide_passward(pass1);
			//cin>>pass1;
			cout<<endl<<"\t请再次输入新密码：";
			hide_passward(pass2);
			//cin>>pass2;
			if(pass1 == pass2)
			{
				ps->pass_modify(pass1);

				str = "update shop set s_pass = '"+pass1+"' where s_num = "+to_string(ps->get_num());
				sql->info_update(&mysql,str);

				break;
			}
			else
				cout<<"\n两次输入的密码不一致";
		}

		cout<<endl<<"\t登陆密码修改成功！\n";
		sleep(1);
	}
	else
	{
		cout<<"\n密码不正确！\n";
		sleep(1);
	}
}

void System::courier_enroll()
{
	system("clear");
	cout<<"\n\t\t\t\t*************配   送   员   注   册*************\n";	
	int num=0,temp;
	//找最大编号
	if(!person.empty())
	{
		for(auto tmp:person)
		{
			temp = tmp->get_num();
			if(temp > COURIER*1000 && temp <= (COURIER+1)*1000 && temp > num)
				num = temp;
		}		
	}

	if(num==0)
	{
		num = COURIER*1000 + 1;
	}
	else
		num += 1;
	
	string name,tel;
	cout<<"\n\n\n\n\t\t\t\t\t    帐    号：";
	while(1)
	{
		setbuf(stdin,NULL);
		getline(cin,name);
		if(enroll_check(name,COURIER))
			break;
		else
			cout<<"\n该帐号已注册，请重新输入\n";
		cout<<"\t\t\t\t\t    帐    号：";

	}
	cout<<"\n\t\t\t\t\t    联系方式：";
	cin>>tel;
	Person *p = new Courier(num,name,tel);//构造 输入客户编号 
	//cin>>*(Courier*)p;//重载输入客户
	person.push_back(p);//添加客户
	string str = "insert into courier values ("+to_string(num)+",'"+name+"','"+tel+"','"+"333333"+"')";
	sql->info_update(&mysql,str);
	cout<<"\n\t\t\t\t注册成功,初始登陆密码为："<<p->get_passward()<<" 请登录后修改\n";
	sleep(1);
}

Courier* System::courier_login()
{
	system("clear");
	cout<<"\n\t\t\t\t*************配   送   员   登   录*************\n";	
	string name,pass;
	cout<<"\n\n\n\n\n\t\t\t\t\t    用户名：";
	setbuf(stdin,NULL);
	getline(cin,name);
	cout<<"\n\t\t\t\t\t    密  码：";
	hide_passward(pass);
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>COURIER*1000 && num<=(COURIER+1)*1000)
		{
			if(((Courier*)tmp)->get_name() == name && ((Courier*)tmp)->get_passward() == pass)
			{
				//pc = (Courier*)tmp;
				cout<<"\n\t\t\t\t\t    正  在  登  录....\n";
				sleep(1);
				return (Courier*)tmp;
			}
		}
	}
	cout<<"\n用户名或密码不对，请重新登录\n";
	sleep(1);
	return NULL;
}
void System::courier_get_order(Courier* pc)
{
	system("clear");
	if(!order.empty())
	{
		int n;
		list<Order*>order1;//存储商家接的订单
		list<Order*>::iterator it;
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_state();//商家接的单
			if(n==take)
			{
				order1.push_back((*it));
			}
		}

		//显示订单
		if(!order1.empty())
		{
			cout<<"可抢的订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(COURIER);
				cout<<endl;
			}
			//抢单
			vector<int>order2;//存储抢单编号
			int num,flag;
			while(1)
			{
				flag=0;
				cout<<endl<<"\t请选择抢单的编号(0结束)：";
				cin>>num;
				if(num==0)
					break;
				for(auto tmp:order1)
				{
					if(tmp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					order2.push_back(num);
				else
					cout<<"\n未找到该订单\n";
			}
			if(!order2.empty())
			{
				for(auto tmp:order2)
				{
					for(auto temp:order1)
					{
						if(tmp==temp->get_num())
						{
							//temp->set_state(rob);
							//增添配送员信息
							temp->info_add(pc->get_num(),pc->get_name(),pc->get_tel());
							string str = "update indent set c_num = "+to_string(pc->get_num())+", c_name = '"+pc->get_name()+"', c_tel = '"+pc->get_tel()+"',state = "+to_string(rob)+" where num = "+to_string(tmp);
							sql->info_update(&mysql,str);
							cout<<endl<<"\t"<<tmp<<" 抢单成功.."<<endl;
							sleep(1);
							break;
						}	
					}
				}
			}
		}
		else
		{
			cout<<"\n\t暂无可抢的订单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\t暂无可抢的订单！"<<endl;
		sleep(1);
	}

}
void System::courier_send_order(Courier* pc)
{
	system("clear");
	if(!order.empty())
	{
		int c_num = pc->get_num(),n;
		list<Order*>order1;//存储刚抢的订单
		list<Order*>::iterator it;
		//提取当前配送员抢的单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_c_num();
			if(n==c_num)
			{
				if((*it)->get_state() == rob)	
					order1.push_back((*it));
			}
		}

		//显示订单
		if(!order1.empty())
		{
			cout<<"可派送的订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(COURIER);
				cout<<endl;
			}
			//送单
			vector<int>order2;//存储送单编号
			int num,flag;
			while(num)
			{
				flag=0;
				cout<<endl<<"\t送单的编号(0结束)：";
				cin>>num;
				if(num==0)
					break;
				for(auto tmp:order1)
				{
					if(tmp->get_num()==num)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					order2.push_back(num);
				else
					cout<<"\n未找到该订单"<<endl;
			}
			if(!order2.empty())
			{
				for(auto tmp:order2)
				{
					for(auto temp:order1)
					{
						if(tmp==temp->get_num())
						{
							temp->set_state(send);
							string str = "update indent set state = "+to_string(send)+" where num = "+to_string(tmp);
							sql->info_update(&mysql,str);

							cout<<endl<<"\t"<<tmp<<" 送单成功.."<<endl;
							sleep(1);
							break;
						}	
					}
				}
			}
		}
		else
		{
			cout<<"\n\t暂无可送的订单！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<"\n\t暂无可送的订单！"<<endl;
		sleep(1);
	}
}
void System::courier_order_look(Courier* pc)
{
	system("clear");
	if(!order.empty())
	{
		int num = pc->get_num(),n;
		list<Order*>order1,order2;//分别保存未完成和完成订单
		list<Order*>::iterator it;
		//提取当前配送员的订单
		for(it=order.begin();it!=order.end();it++)
		{
			n = (*it)->get_c_num();
			if(n==num)
			{
				if((*it)->get_state() < receive && (*it)->get_state()>reject)	
					order1.push_back((*it));
				else
					order2.push_back((*it));
			}
		}

		int flag = 0;
		//显示未完成订单
		if(!order1.empty())
		{
			cout<<"未完成订单："<<endl;
			for(auto tmp:order1)
			{
				tmp->order_display(COURIER);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<"无未完成订单！"<<endl;
			sleep(1);
		}
		//显示已完成订单
		if(!order2.empty())
		{
			cout<<endl<<"已完成订单："<<endl;
			for(auto tmp:order2)
			{
				tmp->order_display(COURIER);
				cout<<endl;
			}
			flag = 1;
		}
		else
		{
			cout<<endl<<"无已完成订单！"<<endl;
			sleep(1);
		}
		if(flag)
		{
			getchar();
			getchar();
		}
	}
	else
	{
		cout<<"\t暂无订单信息！"<<endl;
		sleep(1);
	}

}
void System::courier_comment_look(Courier* pc)
{
	system("clear");
	cout<<"配送员评价："<<endl;
	vector<map<string,string>>& com = pc->get_com();
	if(!com.empty())
	{
		for(auto tmp:com)
		{
			for(auto temp:tmp)
			{
				cout<<endl<<temp.first<<" : "<<temp.second<<endl;
			}
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"暂无用户评论！"<<endl;
		sleep(1);
	}

}

void System::courier_info_display(Courier* pc)
{
	system("clear");
	cout<<"配送员信息："<<endl;
	cout<<endl<<"\t编    号："<<pc->get_num()<<endl;
	cout<<endl<<"\t名    称："<<pc->get_name()<<endl;
	cout<<endl<<"\t联系方式："<<pc->get_tel()<<endl;
	getchar();
	getchar();
}

void System::courier_info_modify(Courier* pc)
{
	system("clear");
	string str,pass,tel;
	cout<<"配送员信息修改："<<endl;
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	//cin>>pass;
	if(pass==pc->get_passward())
	{
		system("clear");
		cout<<"配送员信息修改："<<endl;
		cout<<endl<<"\t联系方式：";
		cin>>tel;
		//cout<<endl<<"\t商家地址：";
		//cin>>.add;
		pc->tel_modify(tel);
		//ps->add_modify(add);

		str = "update courier set c_tel = '"+tel+"' where c_num = "+to_string(pc->get_num());
		sql->info_update(&mysql,str);

		cout<<endl<<"\t配送员信息修改成功！"<<endl;
		sleep(1);
	}
	else
	{
		cout<<"\n登录密码不正确！\n";
		sleep(1);
	}
}
/*
void System::courier_info_modify(Courier* pc)
{
	system("clear");
	cout<<"配送员信息修改："<<endl;
	cin>>(*pc);
	pc->pass_modify();
	cout<<endl<<"\t信息修改成功！"<<endl;
	sleep(1);
}
*/

void System::courier_pass_modify(Courier* pc)
{

	string pass,pass1,pass2,str;
	system("clear");
	cout<<"配送员密码修改：\n";
	cout<<"\n\t输入登录密码：";
	hide_passward(pass);
	//cin>>pass;
	if(pc->get_passward()==pass)
	{
		system("clear");
		cout<<"配送员密码修改：\n";
		while(1)
		{
			cout<<"\n\t请输入新的登录密码：";
			hide_passward(pass1);
			//cin>>pass1;
			cout<<endl<<"\t请再次输入新密码：";
			hide_passward(pass2);
			//cin>>pass2;
			if(pass1 == pass2)
			{
				pc->pass_modify(pass1);

				str = "update courier set c_pass = '"+pass1+"' where c_num = "+to_string(pc->get_num());
				sql->info_update(&mysql,str);

				break;
			}
			else
				cout<<"\n两次输入的密码不一致";
		}

		cout<<endl<<"\t登陆密码修改成功！\n";
		sleep(1);
	}
	else
	{
		cout<<"\n密码不正确！\n";
		sleep(1);
	}
}

void System::admin_login()
{
	system("clear");
	cout<<"\n\t\t\t\t*************管   理   员   登   录*************\n";	
	string name,pass;
	cout<<"\n\n\n\n\n\t\t\t\t\t    用户名：";
	getchar();
	cin>>name;
	cout<<"\n\t\t\t\t\t    密  码：";
	hide_passward(pass);
	if(name=="admin" && pass=="admin")
	{
		cout<<endl<<"\n\t\t\t\t\t    正  在  登  录...."<<endl;
		sleep(1);
		admin_man();
	}
	else
	{
		cout<<"\n用户名或密码不对，请重新登录\n";
		sleep(1);
	}
}

void System::admin_user_del()
{
	system("clear");
	list<Client*>client;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>USER*1000 && num<= (USER+1)*1000)
		{
			client.push_back((Client*)tmp);
		}
	}
	if(!client.empty())
	{
		cout<<"所有用户如下："<<endl;
		for(auto tmp:client)
		{
			cout<<*tmp<<endl<<endl;
		}
		vector<int> cancel;
		int num;
		cout<<"\t选择删除的用户编号：";
		while(1)
		{
			cin>>num;
			if(num>USER*1000 && num<=(USER+1)*1000)
			{
				cancel.push_back(num);
				cout<<"\t\t\t";
			}
			else if(num==0)
				break;
			else
			{
				cout<<"\n\t\t\t编号 "<<num<<" 不正确.."<<endl;
				sleep(0.5);
			}
		}
		int flag;
		for(auto tmp:cancel)
		{
			flag = 0;
			//查看用户是否有未完成订单
			for(auto temp:order)
			{
				if(tmp==temp->get_cl_num())
				{
					if(temp->get_state()>reject && temp->get_state()<receive)
					{
						flag = 1;
						break;
					}	
				}
			}
			if(flag)
			{
				cout<<endl<<"用户 "<<tmp<<" 有未完成订单，删除失败.."<<endl;
				sleep(0.5);
			}
			else
			{
				list<Person*>::iterator it;
				for(it=person.begin();it!=person.end();it++)
				{
					if((*it)->get_num() == tmp)
					{
						delete ((Client*)(*it));
						person.erase(it);
						cout<<endl<<'\t'<<tmp<<" 用户删除成功.."<<endl;
						sleep(1);
						break;
					}
				}
			}
		}
	}
	else
	{
		cout<<endl<<"\t当前无用户注册！"<<endl;
		sleep(1);
	}
}

void System::admin_user_mod()
{
	system("clear");
	list<Client*>client;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>USER*1000 && num<= (USER+1)*1000)
		{
			client.push_back((Client*)tmp);
		}
	}
	if(!client.empty())
	{
		cout<<"用户信息修改："<<endl;
		cout<<endl<<"\t用户编号：";
		cin>>num;
		if(num>USER*1000 && num<=(USER+1)*1000)
		{
			for(auto tmp:person)
			{
				if(num==tmp->get_num())
				{
					string tel,add,pass,pass_pay,pay,str;
					cout<<endl<<"\t联系方式：";
					cin>>tel;
					cout<<endl<<"\t用户地址：";
					setbuf(stdin,NULL);
					getline(cin,add);;
					cout<<endl<<"\t登录密码：";
					hide_passward(pass);
					cout<<endl<<"\t支付密码：";
					hide_passward(pass_pay);
					tmp->tel_modify(tel);
					tmp->add_modify(add);
					tmp->pass_modify(pass);
					((Client*)tmp)->pass_pay_modify(pass_pay);

					str = "update client set cl_tel = '"+tel+"',cl_add = '"+add+"',cl_pass = '"+pass+"',cl_pass_pay = '"+pass_pay+"' where cl_num = "+to_string(num);
					sql->info_update(&mysql,str);

					cout<<endl<<"用户信息修改成功！"<<endl;
					sleep(1);
					
					return;
				}
			}
			cout<<endl<<"未找到该用户！"<<endl;
			sleep(1);
		}
		else
		{
			cout<<endl<<"用户编号不正确.."<<endl;
			sleep(1);	
		}
	}
	else
	{
		cout<<endl<<"\n\n\n\n\n\n\t\t\t\t\t\t当前无用户注册.."<<endl;
		sleep(1);
	}
}

void System::admin_user_display()
{
	system("clear");
	list<Client*>client;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>USER*1000 && num<= (USER+1)*1000)
		{
			client.push_back((Client*)tmp);
		}
	}
	if(!client.empty())
	{
		cout<<"所有用户如下："<<endl;
		for(auto tmp:client)
		{
			cout<<*tmp<<endl<<endl;
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"\t当前无用户注册.."<<endl;
		sleep(1);
	}
}

void System::admin_shop_del()
{
	system("clear");
	list<Shop*>shop;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>SHOP*1000 && num<= (SHOP+1)*1000)
		{
			shop.push_back((Shop*)tmp);
		}
	}
	if(!shop.empty())
	{
		cout<<"所有商家如下："<<endl;
		for(auto tmp:shop)
		{
			cout<<*tmp<<endl<<endl;
		}
		vector<int> cancel;
		int num;
		cout<<"\t选择删除的商家编号：";
		while(1)
		{
			cin>>num;
			if(num>SHOP*1000 && num<=(SHOP+1)*1000)
			{
				cancel.push_back(num);
				cout<<"\t\t\t";
			}
			else if(num==0)
				break;
			else
			{
				cout<<"\n\t\t\t编号 "<<num<<" 不正确.."<<endl;
				sleep(0.5);
			}
		}
		int flag;
		for(auto tmp:cancel)
		{
			flag = 0;
			//查看商家是否有未完成订单
			for(auto temp:order)
			{
				if(tmp==temp->get_s_num())
				{
					if(temp->get_state()>book && temp->get_state()<comment)
					{
						flag = 1;
						break;
					}	
				}
			}
			if(flag)
			{
				cout<<endl<<"商家 "<<tmp<<" 有未完成订单，删除失败.."<<endl;
				sleep(0.5);
			}
			else
			{
				list<Person*>::iterator it;
				for(it=person.begin();it!=person.end();it++)
				{
					if((*it)->get_num() == tmp)
					{
						delete ((Shop*)(*it));
						person.erase(it);
						cout<<endl<<'\t'<<tmp<<" 用户删除成功.."<<endl;
						sleep(1);
						break;
					}
				}
			}
		}
	}
	else
	{
		cout<<endl<<"\n\n\n\n\n\n\t\t\t\t\t\t当前无商家注册！"<<endl;
		sleep(1);
	}
}

void System::admin_shop_mod()
{
	system("clear");
	cout<<"商家信息修改："<<endl;
	list<Shop*>shop;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>SHOP*1000 && num<= (SHOP+1)*1000)
		{
			shop.push_back((Shop*)tmp);
		}
	}
	if(!shop.empty())
	{
		cout<<endl<<"\t商家编号：";
		cin>>num;
		if(num>SHOP*1000 && num<=(SHOP+1)*1000)
		{
			for(auto tmp:person)
			{
				if(num==tmp->get_num())
				{
					string tel,add,pass,str;
					float p_s;
					int policy;
					cout<<endl<<"\t联系方式：";
					setbuf(stdin,NULL);
					getline(cin,tel);
					cout<<endl<<"\t商家地址：";
					setbuf(stdin,NULL);
					getline(cin,add);
					cout<<endl<<"\t配送费用：";
					cin>>p_s;
					cout<<endl<<"\t登录密码：";
					hide_passward(pass);
					tmp->tel_modify(tel);
					tmp->add_modify(add);
					((Shop*)tmp)->set_price_send(p_s);
					tmp->pass_modify(pass);
					cout<<"\n\t优惠策略：1正常收费 2打折 3满减"<<endl;
					cin>>policy;
					while(1)
					{
						if(policy==1 || policy==2 || policy==3)
							break;
						else
							cout<<"\n\t输入有误，重新输入：";

						cin>>policy;
					}

					if(policy == NORMAL)
					{
						((Shop*)tmp)->set_policy(NORMAL);
						str = "update shop set s_tel = '"+tel+"',s_add = '"+add+"',price_send = "+to_string(p_s)+",policy = "+to_string(NORMAL)+",s_pass = '"+pass+"' where s_num = "+to_string(num);
					}
					else if(policy == DISCOUNT)
					{
						((Shop*)tmp)->set_policy(DISCOUNT);
						float dc;
						while(1)
						{
							cout<<"\n\t折  扣：";
							cin>>dc;
							if(dc<=0 || dc>=1)
								cout<<"\n设置有误";
							else
								break;
						}
						((Shop*)tmp)->discount_modify(dc);
						str = "update shop set s_tel = '"+tel+"',s_add = '"+add+"',price_send = "+to_string(p_s)+",policy = "+to_string(DISCOUNT)+ ",discount = "+to_string(dc)+" where s_num = "+to_string(num);
					}
					else
					{
						((Shop*)tmp)->set_policy(FULL_RECE);
						float full,re;
						while(1)
						{
							cout<<"\n\t满  额：";
							cin>>full;
							cout<<"\n\t减  额：";
							cin>>re;
							if(full>0 && re>0 && full>re)
								break;
							else
								cout<<"\n设置有误";
						}
						((Shop*)tmp)->full_rece_modify(full,re);
						str = "update shop set s_tel = '"+tel+"',s_add = '"+add+"',price_send = "+to_string(p_s)+",policy = "+to_string(FULL_RECE)+",full = "+to_string(full)+",rece = "+to_string(re)+" where s_num = "+to_string(num);
					}

					sql->info_update(&mysql,str);

					cout<<endl<<"\t商家信息修改成功！"<<endl;
					sleep(1);
					return;
				}
			}
			cout<<endl<<"\t未找到该商家！"<<endl;
			sleep(1);
		}
		else
		{
			cout<<endl<<"\t商家编号不正确！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<endl<<"\t当前无商家注册.."<<endl;
		sleep(1);
	}
}

void System::admin_shop_display()
{
	system("clear");
	list<Shop*>shop;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>SHOP*1000 && num<= (SHOP+1)*1000)
		{
			shop.push_back((Shop*)tmp);
		}
	}
	if(!shop.empty())
	{
		cout<<"所有商家如下："<<endl;
		for(auto tmp:shop)
		{
			cout<<*tmp<<endl<<endl;
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"\t当前无商家注册！"<<endl;
		sleep(1);
	}
}
void System::admin_courier_del()
{
	system("clear");
	list<Courier*>courier;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>COURIER*1000 && num<= (COURIER+1)*1000)
		{
			courier.push_back((Courier*)tmp);
		}
	}
	if(!courier.empty())
	{
		cout<<"所有配送员如下："<<endl;
		for(auto tmp:courier)
		{
			cout<<*tmp<<endl<<endl;
		}
		vector<int> cancel;
		int num;
		while(1)
		{
			cout<<"\n\t要删除的配送员编号(0结束)：";
			cin>>num;
			if(num>COURIER && num<=(COURIER+1)*1000)
			{
		 		cancel.push_back(num);
			}
			else if(num==0)
				break;
			else
			{
				cout<<"\n编  号 "<<num<<" 不正确！"<<endl;
				sleep(1);	
			}
		}
		int flag;
		for(auto tmp:cancel)
		{
			flag = 0;
			//查看配送员是否有未完成订单
			for(auto temp:order)
			{
				if(tmp==temp->get_c_num())
				{
					if(temp->get_state()>take && temp->get_state()<comment)
					{
						flag = 1;
						break;
					}	
				}
			}
			if(flag)
			{
				cout<<endl<<"配送员 "<<tmp<<" 有未完成订单或输入有误，删除失败...."<<endl;
				sleep(0.5);
			}
			else
			{
				list<Person*>::iterator it;
				for(it=person.begin();it!=person.end();it++)
				{
					if((*it)->get_num() == tmp)
					{
						delete ((Courier*)(*it));
						person.erase(it);

						string str = "delete from courier where num = "+to_string(tmp);
						sql->info_update(&mysql,str);

						cout<<endl<<'\t'<<tmp<<" 配送员删除成功...."<<endl;
						sleep(1);
						break;
					}
				}
			}
		}
	}
	else
	{
		cout<<endl<<"\n\n\n\n\n\n\t\t\t\t\t\t当前无配送员注册！"<<endl;
		sleep(1);
	}
}
void System::admin_courier_mod()
{
	system("clear");
	cout<<"配送员信息修改："<<endl;
	list<Courier*>courier;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>COURIER*1000 && num<= (COURIER+1)*1000)
		{
			courier.push_back((Courier*)tmp);
		}
	}
	if(!courier.empty())
	{
		cout<<endl<<"\t配送员编号：";
		cin>>num;
		if(num>COURIER*1000 && num<=(COURIER+1)*1000)
		{
			for(auto tmp:person)
			{
				if(num==tmp->get_num())
				{
					string tel,pass,str;
					cout<<endl<<"\t联系方式：";
					cin>>tel;
					tmp->tel_modify(tel);
					cout<<"\n\t登录密码：";
					hide_passward(pass);
					tmp->pass_modify(pass);

					str = "update courier set c_tel = '"+tel+"',c_pass = '"+pass+"' where c_num = "+to_string(num);
					sql->info_update(&mysql,str);

					cout<<endl<<"\t商家信息修改成功！"<<endl;
					sleep(1);
					return;
				}
			}
			cout<<endl<<"\t未找到该配送员！"<<endl;
			sleep(1);
		}
		else
		{
			cout<<endl<<"\t配送员编号不正确！"<<endl;
			sleep(1);
		}
	}
	else
	{
		cout<<endl<<"\t当前无配送员注册.."<<endl;
		sleep(1);
	}
}
void System::admin_courier_display()
{
	system("clear");
	list<Courier*>courier;
	int num;
	for(auto tmp:person)
	{
		num = tmp->get_num();
		if(num>COURIER*1000 && num<= (COURIER+1)*1000)
		{
			courier.push_back((Courier*)tmp);
		}
	}
	if(!courier.empty())
	{
		cout<<"所有配送员如下："<<endl;
		for(auto tmp:courier)
		{
			cout<<*tmp<<endl<<endl;
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"\t当前无配送员注册！"<<endl;
		sleep(1);
	}
}
void System::admin_order_del()
{
	system("clear");
	if(!order.empty())
	{
		cout<<"所有订单信息如下："<<endl;
		for(auto tmp:order)
		{
			tmp->order_display(ADMIN);
			cout<<endl<<endl;
		}
		vector<int> cancel;
		int num;
		while(1)
		{
			cout<<"\n\t选择删除的单号(0结束)：";
			cin>>num;
			if(num==0)
				break;
			cancel.push_back(num);
		}
		int flag;
		for(auto tmp:cancel)
		{
			flag = 0;
			//查看订单是否可删除
			for(auto temp:order)
			{
				if(tmp==temp->get_c_num())
				{
					if(temp->get_state()>reject && temp->get_state()<receive)
					{
						flag = 1;
						break;
					}	
				}
			}
			if(flag)
			{
				cout<<endl<<"订单 "<<tmp<<" 未完成或不存在，删除失败...."<<endl;
				sleep(1);
			}
			else
			{
				
				list<Order*>::iterator it;
				for(it=order.begin();it!=order.end();it++)
				{
					if((*it)->get_num() == tmp)
					{
						delete (*it);
						order.erase(it);
						
						string str = "delete from indent where num = "+to_string(tmp);
						sql->info_update(&mysql,str);

						cout<<endl<<'\t'<<tmp<<" 订单删除成功...."<<endl;
						sleep(1);
						break;
					}
				}
			}
		}
	}
	else
	{
		cout<<endl<<"\t暂无订单信息！"<<endl;
		sleep(1);
	}
}
void System::admin_order_mod()
{}
void System::admin_order_display()
{
	system("clear");
	if(!order.empty())
	{
		cout<<"所有订单信息如下："<<endl<<endl;
		for(auto tmp:order)
		{
			tmp->order_display(ADMIN);
			cout<<endl<<endl;
		}
		getchar();
		getchar();
	}
	else
	{
		cout<<endl<<"\t暂无订单信息！"<<endl;
		sleep(1);
	}
}


void System::count_time(Order & order)
{
	int sec,min,hour,day,mon,year;
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	sec = timeinfo->tm_sec;
	min = timeinfo->tm_min;
	hour = timeinfo->tm_hour;
	day = timeinfo->tm_mday;
	mon = timeinfo->tm_mon;
	year = timeinfo->tm_year+1900;//获取的系统函数年份 = year-1900
	string date,time;
	//保存日期
	date = to_string(year)+"-";
	if(mon<10)
		date += "0"+ to_string(mon)+"-";
	else
		date += to_string(mon)+"-";
	if(day<10)
		date += "0"+ to_string(day);
	else
		date += to_string(day);
	//保存时间
	if(hour<10)
		time = "0"+to_string(hour)+":";
	else
		time = to_string(hour)+":";
	if(min<10)
		time += "0"+to_string(min)+":";
	else
		time += to_string(min)+":";
	if(sec<10)
		time += "0"+to_string(sec);
	else
		time += to_string(sec);
	order.set_time(date,time);

}

