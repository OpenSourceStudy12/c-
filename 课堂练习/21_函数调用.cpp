//函数对象:重载了函数调用的对象定义的对象
//函数指针的地方都可以应用函数对象







class Compare
{
private:
	int cout;
public:
	Compare(){}

	bool operator()(intx ,int y)
	{
		return(x>y);
	}

}
