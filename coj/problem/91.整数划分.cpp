/*
Id:[91]	
整数划分 (15分)
题目内容:
对于一个正整数n的划分，就是把n变成一系列正整数之和的表达式。注意，分划与顺序无关，例如6=5+1跟6=1+5是
同一种分划。另外，单独这个整数本身也算一种分划。
例如：对于正整数n=5，可以划分为：
1+1+1+1+1
1+1+1+2
1+1+3
1+2+2
2+3
1+4
5
输入描述:
输入一个正整数n
输出描述:
输出n整数划分的总数k
输入样例:
5
输出样例:
7
*/

#include <iostream> 
using namespace std;

int f(int m, int n){
	if(m == 0 || n == 1)
		return 1;
	if(m < n)
		return f(m, m);
	if(m >= n)
		return f(m - n, n) + f(m, n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << f(n, n) << endl;
    return 0;
}
