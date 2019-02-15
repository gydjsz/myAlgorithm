/*
题目描述
计算ab的个位数。

输入
一行两个空格隔开的正整数表示a和b。

输出
输出ab的个位数。

样例输入
2 4

样例输出
6
*/

#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int sum = 1;
	for(int i = 0; i < b; i++){
		sum = (sum * a) % 10;
	}
	cout << sum << endl;
	return 0;
}
