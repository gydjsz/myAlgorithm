/*
题目描述
输入年份与月份，求该月共有多少天。

输入
输入两个空格隔开的正整数year和month，分别表示年份和月份

输出
输出对应year这一年month这个月的天数。

样例输入
2000 2

样例输出
29
*/

#include <iostream>
using namespace std;

int main(){
	int year, month;
	cin >> year >> month;
	if(month == 2){
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			cout << 29 << endl;
		else
			cout << 28 << endl;
	}
	else{
		switch(month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				cout << 31 << endl;
				break;
			default:
				cout << 30 << endl;
		}
	}
	return 0;
}
