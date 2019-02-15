/*
题目描述
编写程序，计算下列分段函数y=f(x)的值（输入数据为浮点数，输出保留小数点后三位）。
f(x) = { x + 2.5                 (0 <= x < 5)
       { 2 - 1.5(x - 3)(x - 3)   (5 <= x < 10)
	   { x / 2 - 1.5             (10 <= x < 20) 

输入
输入x。

输出
输出f(x)的值，答案保留三位小数。

样例输入
1

样例输出
3.500
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double x;
	cin >> x;
	if(x >= 0 && x < 5)
		cout << fixed << setprecision(3) << x + 2.5 << endl;
	else if(x < 10)
		cout << fixed << setprecision(3) << 2 - 1.5 * pow(x - 3, 2) << endl;
	else 
		cout << fixed << setprecision(3) << x / 2 - 1.5 << endl;
	return 0;
}
