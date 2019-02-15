/*
题目描述
给定一个长度为n的非负整数序列，请计算序列的最大跨度值（最大跨度值 = 最大值减去最小值）。

输入
输入一共两行，第1行为序列的个数n（1≤n≤1000)，第2行为序列的n个不超过1000的非负整数，整数之间以一个空格分隔。

输出
输出最大跨度值。

样例输入
6
3 0 8 7 5 9

样例输出
9
*/

#include <iostream>
using namespace std;

int main(){
	int n, a;
	cin >> n;
	int big = 0, small = 1000;
	for(int i = 0; i < n; i++){
		cin >> a;
		big = max(a, big);
		small = min(a, small);
	}
	cout << big - small << endl;
	return 0;
}
