/*
题目描述
输入三角形三边长a,b,c（保证能构成三角形），输出三角形面积。

输入
一行三个用一个空格隔开的实数a,b,c，表示三角形的三条边长。

输出
输出三角形的面积，答案保留四位小数。

样例输入
3 4 5

样例输出
6.0000
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a + b + c) / 2;
	double area = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << fixed << setprecision(4) << area << endl;
	return 0;
}
