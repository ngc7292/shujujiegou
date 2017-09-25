// 数据结构.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int gcd(int a,int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		gcd(b, a%b);
	}
}

int main()
{
	int a, b,c;
	cin >> a >> b;
	c = gcd(a, b);
	cout << c << endl;
	cin >> a;
    return 0;
}

