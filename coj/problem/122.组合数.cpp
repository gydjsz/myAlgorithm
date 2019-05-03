/*
Id:[122]	
组合数 (15分)
题目内容:
 找出n个自然数（1,2···n）中取r个数的组合，例如当n=5，r=3时所有组合为
1 2 3 
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
此题只需求出组合数的个数
输入描述:
输入两个正整数n、r
输出描述:
计算出n个自然数中取r个数的组合数的个数
输入样例:
5 3
20 18
输出样例:
10
190
*/

#include <iostream> 
using namespace std;

typedef long long ll;

int main(){
	ll n, r;
	cin >> n >> r;
	r = r > n - r ? n - r : r;
	ll c1 = 1, c2 = 1;
	for(int i = r; i > 0; i--){
		c1 *= (n--);
	}
	for(int i = r; i >= 1; i--){
		c2 *= i;
	}
	cout << c1 / c2 << endl;
    return 0;
}
