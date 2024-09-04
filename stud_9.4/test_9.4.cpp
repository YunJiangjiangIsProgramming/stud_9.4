#define _CRT_SECURE_NO_WARNINGS 1
#include<thread>
#include<list>
#include<iostream>
#include<vector>

using namespace std;


int x1()
{
	// ����int����Ƚϵ�lambda
	// lambda--�ɵ��ö���
	//[](int x, int y)->bool{return x + y; };
	auto compare = [](int x, int y){return x > y; };
	cout << compare(1, 2) << endl;


	return 0;
}

int x2()
{
	int a = 0, b = 1;
	auto add1 = [](int x, int y) {return x + y; };
	cout << add1(a, b) << endl;

	auto add2 = [b](int x) {return x + b; };
	cout << add2(a) << endl;

	/*auto swap1 = [a, b]()mutable
	{
		int tmp = a;
		a = b;
		b = tmp;
	};

	swap1();
	cout << a << ":" << b << endl;*/
	// �����õķ�ʽ��׽
	//auto swap1 = [&]()
	auto swap1 = [&a, &b]()
	{
		int tmp = a;
		a = b;
		b = tmp;
	};

	swap1();
	cout << a << ":" << b << endl;

	// ��ϲ�׽
	int x = 0, y = 1;
	auto func1 = [x,&y]()
	{};
	func1();

	auto func2 = [=, &y]()
	{
		//cout << m << endl;
		cout << x << endl;
	};
	func2();

	int m = 0, n = 1;



	return 0;
}



//void print1(int& x)
//{
//	for (; x < 100; ++x)
//	{
//		cout <<"thread1:" << x << endl;
//	}
//}
//
//void print2(int& y)
//{
//	for (; y < 100; ++y)
//	{
//		cout <<"thread2:"<< y << endl;
//	}
//}
//
int x5()
{
	int i = 0;
	//thread t1(print1, ref(i));
	//thread t2(print2, ref(i));

	//t1.join();
	//t2.join();

	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	return 0;
}

int x3()
{
	// N���߳�ͬʱ��
	int i = 0;
	thread t1([&i]() 
		{
			for (; i < 100; ++i)
			{
				cout << "thread1:" << i << endl;
			}
		});

	thread t2([&i]()
		{
			for (; i < 100; ++i)
			{
				cout << "thread2:" << i << endl;
			}
		});

	//t1 = t2;

	t1.join();
	t2.join();

	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	return 0;
}

int x4()
{
	vector<thread> vThreads;
	int n;
	cin >> n;
	vThreads.resize(n);

	int i = 0;
	int x = 0;
	for (auto& t : vThreads)
	{
		t = thread([&i, x]
			{
				while (i < 1000)
				{
					cout << "thread" << x << "->" << i << endl;
					++i;
				}
			});
		x++;
	}

	for (auto& t : vThreads)
	{
		t.join();
	}

	return 0;
}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

int x9()
{
	// ��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);

	// lambda
	auto r2 = [=](double monty, int year)->double {return monty * rate * year; };
	r2(10000, 2);

	auto r3 = [=](double monty, int year)->double {return monty * rate * year; };
	r3(10000, 2);
	return 0;
}

 // Args��һ��ģ���������args��һ�������ββ�����
 // ����һ��������Args...args������������п��԰���0�������ģ�������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	// ���������м�������
//	cout << sizeof...(args) << endl;
//	for (size_t i = 0; i < sizeof...(args); ++i)
//	{
//		cout << args[i] << endl;
//	}
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1, 1.1);
//	ShowList(1, 1.1, string("xxxxxx"));
//	ShowList();
//
//
//	return 0;
//}

//void ShowList()
//{
//	cout << endl;
//}
//
//// args���������Խ���0-N������
//template <class T, class ...Args>
//void ShowList(T val, Args... args)
//{
//	cout <<val << " ";
//	ShowList(args...);
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1, 1.1);
//	ShowList(1, 1.1, string("xxxxxx"));
//	ShowList();
//
//	return 0;
//}


//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
//
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}

//template <class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//	return 0;
//}
//
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}

//int main()
//{
//	ShowList(1);
//	ShowList(1, 1.1);
//	ShowList(1, 1.1, string("xxxxxx"));
//
//	return 0;
//}

int main()
{

	return 0;
}
