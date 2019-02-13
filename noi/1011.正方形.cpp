/*
题目描述
有一个正方形，四个角的坐标分别是（1，-1），（1，1），（-1，-1），（-1，1）。写一个程序，判断一个给定的点（x,y）是否在这个正方形内（包括正方形边界），如果在正方形内输出“Yes”，否则输出“No”。

输入
一行两个空格隔开的实数x,y，表示点的坐标。

输出
如果点(x,y)在正方形内输出“Yes”，否则输出“No”。

样例输入
0 0

样例输出
Yes
*/

#include <iostream>
using namespace std;

int main(){
	double x, y;
	cin >> x >> y;
	if(x >= -1 && x <= 1 && y >= -1 && y <= 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
