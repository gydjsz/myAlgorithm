/*
Id:[104]	
N皇后 (15分)
题目内容:
 国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八个皇后如何相安无事的
放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
该题要求N皇后的放置结果共有多少种
输入描述:
输入一个正整数N（N小于16）
输出描述:
输出结果
输入样例:
8
输出样例:
92
*/

#include <iostream> 
#include <cstring>
#include <cmath>
using namespace std; 

int n;
int a[20];
int sum;

int dfs(int k){
	if(k == n + 1){
		sum++;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int j;
		for(j = 1; j < k; j++)
			if(a[j] == i || abs(j - k) == abs(a[j] - i))
				break;
		if(j == k){
			a[k] = i;
			dfs(k + 1);
		}
	}
	return 0;
}


int main(){
	cin >> n;
	dfs(1);
	cout << sum << endl;
	return 0;
}
