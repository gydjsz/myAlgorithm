/*
   题目描述
   打印一个n*n的数字方阵，例如n=4时：(n<=100)
   1  3   4   10
   2  5   9   11
   6  8   12  15
   7  13  14  16
   输入n。

   输出
   输出n*n的方阵。

   样例输入
   4

   样例输出
   1 3 4 10
   2 5 9 11
   6 8 12 15
   7 13 14 16
   */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n + 1][n + 1];
	int k = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++){
			if(i % 2)
				a[i - j][j] = ++k;
			else
				a[j][i - j] = ++k;
		}
	k = n * n;
	int m = n - 1;
	for(int i = 0; i < m; i++)
		for(int j = 0; j <= i; j++){
			if(i % 2)
				a[m - i + j][m - j] = k--;
			else
				a[m - j][m - i + j] = k--;
		}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
