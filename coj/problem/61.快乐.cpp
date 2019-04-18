/*
Id:[61]	
快乐 (5分)
题目内容:
没有买到奥运会的门票让YF伤心不已，为了使自己开心起来，他去找周围的人聊天，每找一个人聊天，他就会耗费一定的体力，但
他会得到一定量的快乐。YF试图使自己尽可能的高兴，但一旦体力耗尽了(为零或为负)，他也就挂了，就一点快乐都没有了。现
在Yk初始有100点体力，他最多可以获得多少快乐？

输入描述:
数据分多组，对于每组数据：第一行为n，表示有YK的n(0<n<21)个朋友。第二行表示和每个人聊天耗费的体力，第三行表示每个
人所能提供的快乐值。输入以一个0结束。
输出描述:
对于每组输出，输出一个值，YK可以获得的最大的快乐值。
输入样例:
3
1 21 79
20 30 25
4
100 100 100 100
1 2 3 4
0

输出样例:
50
0

*/

/*
 * 设dp[i][j]表示和i个朋友聊天，还剩j点体力的情况下获得的快乐值，则
 * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigth] + value[i])
 */


#include <iostream> 
#include <cstring>
using namespace std;

int solve(int n){
	int weight[n + 1], value[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> weight[i];
	for(int i = 1; i <= n; i++)
		cin >> value[i];
	int dp[n + 1][101];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 100; j++){
			if(j - weight[i] > 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	cout << dp[n][100] << endl;
	return 0;
}

int main(){
	int n;
	while(cin >> n && n != 0){
		solve(n);
	}
    return 0;
}
