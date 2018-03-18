/*

多重继承//间接继承

class A
{
protected:
	int x;
public:
	A(int x1=0):x(x1){}
	~A(){}
	void display()
	{
		cout<<x<<endl;
	
	}

};

class B:public A
{
protected:
	int y;
public:
	B(int x1=0,int y1=0):A(x1),y(y1)
	{
	
	}
	~B(){}
	void display()
	{
		A::display();
		cout<<y<<endl;
	}

};

class C:public B
{
private:
	int z;
public:
	C(int x1=0,int y1=0,int z1=0):B(x1,y1),z(z1){}
	~C(){}
	void display()
	{
		B::display()
		cout<<z<<endl;
	}
};


多继承:一个子类有多个父类//多个父类派生一个子类

class A
{
protected:
	int x;
public:
	A(int x1=0):x(x1){}
	~A(){}
	void display()
	{
		cout<<x<<endl;
	
	}

};

class B:
{
protected:
	int y;
public:
	B(int y1=0):y(y1)
	{
	
	}
	~B(){}
	void display()
	{
		cout<<y<<endl;
	}

};

class C:public A,public B
{
private:
	int z;
public:
	C(int x1=0,int y1=0,int z1=0):A(x1),B(y1),z(z1){}
	~C(){}
	void display()
	{
B		A::display()
		B::display()
		cout<<z<<endl;
	}
};
 

虚继承     虚基类
(菱形继承)

class A //虚基类
{
protected:
	int x;
public:
	A(int x1=0):x(x1){}
	~A(){}
	void display()
	{
		cout<<x<<endl;
	
	}

};

class B:virtual public A //虚继承
{
protected:
	int y;
public:
	B(int x1=0,int y1=0):A(x1),y(y1)
	{
	
	}
	~B(){}
	void display()
	{
		A::display();
		cout<<y<<endl;
	}

};

class C:virtual public A //虚继承
{
private:
	int z;
public:
	C(int x1=0,int z1=0):A(x1),z(z1){}
	~C(){}
	void display()
	{
		A::display()
		cout<<z<<endl;
	}
};


class D:public B,public C
{
private:
	int k;
public:
	C(int x1=0,int y1=0,int z1=0,int k1=0):A(x1),B(x1,y1),C(x1,z1),k(k1){}
	~C(){}
	void display()
	{
B		A::display();
		B::display();
		C::display();
		cout<<k<<endl;
	}
};













*/
