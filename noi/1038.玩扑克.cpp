/*
题目描述
又到休息时间了。两个小伙伴要玩扑克牌比大小的游戏：每人分到一种花色的扑克牌，然后每人随机出一张牌，大者胜，最后获胜次数多的人，赢一轮。
不开心的事发生了，玩了一轮后，发现扑克牌竟然少了一张。到底少了几呢？
你能写个程序，快速找到扑克x吗？
 

输入
输入一行，包括25个用空格分隔的数字（A表示为1，J、Q、K表示为11、12、13）。

输出
输出数字x，表示缺少的扑克牌数字。

样例输入
9 1 13 2 6 10 7 8 3 11 4 1 5 9 10 2 4 3 12 13 11 5 8 6 7

样例输出
12
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int a[14];
	memset(a, 0, sizeof(a));
	int b;
	for(int i = 1; i <= 25; i++){
		cin >> b;
		a[b]++;
	}
	for(int i = 1; i <= 13; ++i)
		if(a[i] == 1){
			cout << i << endl;
			return 0;
		}
	return 0;
}
