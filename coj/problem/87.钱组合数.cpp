/*
Id:[87]	
钱组合数 (15分)
题目内容:
给你足够多的1，2，5面值的钱币，输入一个钱数n，设计一个程序使能够计算出所有的组合！
输入描述:
钱数N
输出描述:
所有的组合数的个数
输入样例:
20
输出样例:
29
*/

#include <iostream>
#include <cstring>
using namespace std;

/*dfs暴力求解

int a[] = {1, 2, 5};
int b[3];
int n, k;

int dfs(int sum, int j){
	if(sum == n){
		k++;	
		for(int i = 0; i < 3; i++)
			cout << b[i] << " ";
		cout << endl;
		return 0;
	}
	if(sum > n)
		return 0;
	for(int i = j; i < 3; i++){
		b[i]++;
		dfs(sum + a[i], i);
		b[i]--;
	}
	return 0;
}

*/

//动态规划
//dp[i] 表示钱数为i时的方案数, 当钱数为j, 硬币为x时,钱数为j - x的方案数为dp[j - x],
//dp[j] = dp[j - x] + dp[j - 2 * x] + dp[j - 3 * x] +...+ dp[j - m * x], 表示方案数为dp[j - x]时，再加一个硬币x，能得到j，方案数为dp[j - 2 * x]时，再加硬币钱数为2 * x，能得到j..., 把所有的方案数相加，便得到钱数为j的方案数.
int solve(){
	int n;
	cin >> n;
	int a[] = {1, 2, 5};
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < 3; i++){
		for(int j = a[i]; j <= n; j++){
			dp[j] += dp[j - a[i]];
		}
	}
	cout << dp[n] << endl;
	return 0;
}

int main(){
	solve();
	return 0;
}

