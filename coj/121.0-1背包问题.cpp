/*
Id:[121]	
0-1背包问题 (20分)
题目内容:
背包最大允许装载为C, 有n个物品要放进背包，每个物品的重量为w[1],w[2],...w[n],每个物品的价值为v[1],v[2],...v
[n], 请选择物品装进背包，使得价值最大。C为整数。
输入描述:
第一行为物体个数n,以及背包容量C；
第二行为n个重量（实数），空格隔开
第三行为n个价值（实数），空格隔开
输出描述:
第一行为最大装载的总价值
第二行为每个物品是否装载，1表示装，0表示不装，中间用空格隔开
(测试数据能保证最优解唯一)
输入样例:
5 10
2 2 6 5 4
6 3 5 4 6
输出样例:
15
1 1 0 0 1
*/

#include <iostream> 
#include <cstring>
using namespace std;
typedef long long ll;

int solve(){
	ll n, c;
	cin >> n >> c;
	ll weight[n + 1], value[n + 1];
	memset(weight, 0, sizeof(weight));
	memset(value, 0, sizeof(value));
	for(int i = 1; i <= n; i++)
		cin >> weight[i];
	for(int i = 1; i <= n; i++)
		cin >> value[i];
	ll dp[n + 1][c + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= c; j++){
			dp[i][j] = dp[i - 1][j];
			if(j > weight[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	cout << dp[n][c] << endl;
	int a[n];
	memset(a, 0, sizeof(a));
	for(int i = n; i >= 1; i--){
		if(dp[i][c] > dp[i - 1][c]){
			c -= weight[i];
			a[i] = 1;
		}
	}
	for(int i = 1; i <= n - 1; i++)
		cout << a[i] << " ";
	cout << a[n] << endl;
	return 0;
}
int main(){
	solve();		
    return 0;
}
