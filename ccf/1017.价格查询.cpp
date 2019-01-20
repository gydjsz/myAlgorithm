/*
题目描述
编程实现以下功能：查询水果的单价。有4种水果，苹果(apples)、梨(pears)、桔子(oranges)和葡萄(grapes)，单价分别是3.00元/公斤，2.50元/公斤，4.10元/公斤和10.20元/公斤。
运行程序后，首先在屏幕上显示以下菜单(编号和选项)（见样例）。
当用户输入编号1～4，显示相应水果的单价(保留1位小数)；输入0，退出查询；输入其他编号，显示价格为0。

输入
输入一个整数。

输出
输出对应的结果。

样例输入
3

样例输出
[1] apples
[2] pears
[3] oranges
[4] grapes
[0] Exit
price=4.1
*/

#include <iostream>
using namespace std;

int main(){
	cout << "[1] apples\n[2] pears\n[3] oranges\n[4] grapes\n[0] Exit" << endl;
	int n;
	cin >> n;
	string a[] = {"3.0", "2.5", "4.1", "10.2"};
	if(n == 0)
		return 0;
	else if(n >= 1 && n <= 4)
		cout << "price=" << a[n - 1] << endl;
	else
		cout << "price=0" << endl;
	return 0;
}
