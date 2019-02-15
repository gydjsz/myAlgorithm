/*
题目描述
2008年北京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)。现在要统计一下A国所获得的金、银、铜牌数目及总奖牌数。
 

输入
输入n＋1行，第1行是A国参与决赛项目的天数n，其后n行，每一行是该国某一天获得的金、银、铜牌数目，以一个空格分开。

输出
输出仅1行，包括4个整数，为A国所获得的金、银、铜牌总数及总奖牌数，以一个空格分开。

样例输入
3
1 0 3
3 1 0
0 3 0

样例输出
 4 4 3 11
*/

#include <iostream>
using namespace std;

int main(){
	int day, j, y, t;
	cin >> day;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum = 0;
	for(int i = 0; i < day; ++i){
		cin >> j >> y >> t;
		sum1 += j;
		sum2 += y;
		sum3 += t;
	}
	sum = sum1 + sum2 + sum3;
	cout << sum1 << " " << sum2 << " " << sum3 << " " << sum << endl;
	return 0;
}

