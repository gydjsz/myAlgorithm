/*
题目描述
输入两个正整数m和n，判断m和n是否互质（即最大公约数为1），是则输出Yes，否则输出No。
 

输入
输入两个整数m和n，中间用空格隔开。

输出
如互质输出Yes，否则输出No。

样例输入
36 56

样例输出
No
*/

#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int m, n;
	cin >> m >> n;
	if(gcd(m, n) == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
