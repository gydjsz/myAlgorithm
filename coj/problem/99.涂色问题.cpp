/*
Id:[99]	
涂色问题 (15分)
题目内容:
 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且
首尾两格也不同色．求全部的满足要求的涂法。
输入描述:
输入正整数n
输出描述:
输出结果
输入样例:
5
输出样例:
30
*/

/*
 * 1. n - 1个格子和第一个格子相同，那么第ｎ个格子有两种颜色可选，方案数为第n - 2个格子的方案数乘以第ｎ个格子的方案数：f[n - 2] * 2
 * 2. n - 1个格子和第一个格子不同，那么第ｎ个格子只有一种颜色可选，方案数为第n - 1个格子的方案数乘以1
 *
 * f(n) = f(n - 1) + 2 * f(n - 2);
 *
 * 第二个格子和第一个格子不同，第三个格子和第一个、第二个都不同。当ｎ<= 3时，没有第一种情况,所以递推从n >= 4开始
 */

#include <iostream> 
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[4];
	a[0] = 0;
	a[1] = 3;
	a[2] = 6;
	a[3] = 6;
	for(int i = 4; i <= n; i++){
		a[i % 4] = a[(i - 1) % 4] + 2 * a[(i - 2) % 4];
	}
	cout << a[n % 4] << endl;

    return 0;
}
