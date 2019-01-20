/*
题目描述
计算两个双精度浮点数a和b相除的余数，a和b都是正数。这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。

输入
一行两个空格隔开的数a和b。

输出
输出a除以b的余数(答案保留两位小数)。

样例输入
3 2

样例输出
1.00
*/

/*
首先将最大的k求出来，k就是a / b的商，然后将a - k * b就是余数r。
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double a, b;
	cin >> a >> b;
	int k = 0;
	while(a - k * b >= 0)   //求出商
		k++;
	double r = a - (k - 1) * b;
	cout << fixed << setprecision(2) << r << endl;
	return 0;
}
