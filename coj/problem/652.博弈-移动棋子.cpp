/*
Id:[652]	
博弈-移动棋子 (10分)
题目内容:
 甲乙两人下一种棋。棋盘是一个n个连续的方格子，棋盘上随机放着m个棋子，一个格子只能放一个棋子。
玩家轮流选择一个棋子移动，移动只能从右向左，至少要移动一个格子，但不能跨越其他的棋子和第一个格子,
最后无法移动格子的玩家失败。甲始终先移动。对任何一种初始局面，你能判断谁能赢？
输入描述:
第一行是测试用例的数目c, 下面的行是各测试用例
每个测试用例的第一行是整数m(<=1000),表示有m个棋子,第二行是m个整数，表示每个棋子的方格编号（左到右从1开始编号）

输出描述:
每个测试用例中赢的一方。
“甲”或者“乙”或者“不确定”
输入样例:
2
3
1 2 3
8
1 5 6 7 9 12 14 17
输出样例:
乙
甲
*/

#include <iostream> 
#include <cstring>
using namespace std;

int solve(){
	int n;
	cin >> n;
	int a[1005]; 
	memset(a, 0, sizeof(a));
	int s = 0;
	if(n % 2 == 1){
		s++;
		n++;
	}
	for(int i = s; i < n; i++){
		cin >> a[i];
	}
	int num = 0;
	for(int i = 0; i < n - 1; i += 2){
		num ^= (a[i + 1] - a[i] - 1);
	}
	if(num == 0)
		cout << "乙" << endl;
	else
		cout << "甲" << endl;
	return 0;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();	
	}
    return 0;
}
