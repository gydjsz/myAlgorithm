/*
题目描述
根据给定的n，输出乘法口诀表的前n行。

输入
输入正整数n。

输出
输出乘法口诀的前n行。

样例输入
3

样例输出
1*1=1
1*2=2 2*2=4
1*3=3 2*3=6 3*3=9
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	int sum;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; ++j){
			sum = i * j;
			cout << j << "*" << i << "=" << sum << " ";
		}
		cout << endl;
	}
	return 0;
}
