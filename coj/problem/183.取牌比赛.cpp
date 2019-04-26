/*
Id:[183]	
取牌比赛 (15分)
题目内容:
 两个人玩轮流取牌游戏，一共有M张牌，每次可以取1,2,或者5张，取到最后一张牌的人为胜利。编程判断先取牌的是否能胜利。
输入描述:
牌数M
输出描述:
Y或者N
输入样例:
2
输出样例:
Y
*/

#include <iostream> 
using namespace std;

int a[100000];

int solve(int n){
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	a[3] = 0;
	a[4] = 1;
	a[5] = 1;
	for(int i = 5; i <= n; i++)
		a[i] = !(a[i - 5] && a[i - 1] && a[i - 2]);
	if(a[n])
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	return 0;
}

int main(){
	int n;
	cin >> n;
	solve(n);
    return 0;
}
