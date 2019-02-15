/*
题目描述
将任意给定的整百元钞票，兑换成10元、20元、50元小钞票形式。输出兑换方案总数。
输入
输入需要兑换的钞票总数n。

输出
输出方案总数。

样例输入
100

样例输出
10
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i <= n / 50; ++i)
		sum += (n - i * 50) / 20 + 1;
	cout << sum << endl;
	return 0;
}
