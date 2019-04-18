/*
题目内容：
n只蚂蚁在长为L的桥上爬行，速度是1.  知道每只蚂蚁的初始xi坐标，不知道其朝向。 桥很细，只能容许一只蚂蚁通行，两只蚂蚁碰头后，会各自回头。问所有蚂蚁最早和最迟下桥的时间。
输入描述
第一行是桥的长度L和蚂蚁个数n
随后n行是n只蚂蚁的坐标

限制: 1<=L,n<=1000000,  0<=xi<=L

输出描述
一行输出，最早和最迟的下桥时间

输入样例
10 3
2
6
7

输出样例
4 8
*/

/*
 *每只蚂蚁可以看做没有任何区别，那么当它们碰头时，相当于不回头，直接向前走，这样：蚂蚁的最早下桥时间为所有蚂蚁朝最近的一边下桥的最大时间，最迟下桥时间为蚂蚁朝最远的一边下桥的最大时间
 */

#include <iostream>
using namespace std;

int getTime(){
	int n, L;
	cin >> L >> n;
	int a[n];
	int minT = 0, maxT = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		minT = max(minT, min(L - a[i], a[i]));
		maxT = max(maxT, max(L - a[i], a[i]));
	}
	cout << minT << " " << maxT << endl;
	return 0;
}

int main(){
	getTime();
	return 0;
}


