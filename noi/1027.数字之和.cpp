/*
题目描述
对于任意输入的整数，计算其各个数位上的数字之和。

输入
输入一个正整数N。

输出
输出N的各个位上的数字之和。

样例输入
1234

样例输出
10
*/

#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.length(); ++i)
		sum += s[i] - '0';
	cout << sum << endl;
	return 0;
}

