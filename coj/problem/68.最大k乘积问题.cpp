/*
Id:[68]	
最大k乘积问题 (15分)
题目内容:
设I是一个n位十进制整数.如果将I划分为k段,则可得到k个整数.这k个整数的乘积称为I的一个k乘积.试设计一个算法,对于给定
的I和k ,求出I的最大k乘积.
Input
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个n位十进制整数.（n<=10）
Output
输出计算结果，第1行中的数是计算出的最大k乘积.
n位十进制整数.（n<=10）

输入描述:
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个
输出描述:
输出计算结果，第1行中的数是计算出的最大k乘积.
输入样例:
2 1
15
输出样例:
15
*/

#include <iostream> 
using namespace std;

typedef long long ll;

ll sum;
string num;
int k;
int n;

int dfs(int i, int len, ll s){
	if(len == k){
		sum = max(s, sum);
		return 0;
	}
	ll x = 0;
	for(int j = i; j < n; j++){
		x = x * 10 + (num[j] - '0'); 
		dfs(j + 1, len + 1, s * x);
	}
	return 0;
}

int main(){
	cin >> n >> k;
	cin >> num;
	dfs(0, 0, 1);
	cout << sum << endl;
    return 0;
}
