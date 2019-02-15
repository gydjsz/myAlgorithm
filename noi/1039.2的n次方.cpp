/*
题目描述
对于任意给定的n，计算2的n次方。

输入
输入整数n。

输出
输出2的n次方的值。

样例输入
3

样例输出
8
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	cout << (int)pow(2, n) << endl;
	return 0;
}
