/*
题目描述
计算两个矩阵的乘法。n*m阶的矩阵A乘以m*k阶的矩阵B得到的矩阵C 是n*k阶的，且C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + …… +A[i][m-1]*B[m-1][j](C[i][j]表示C矩阵中第i行第j列元素)。

输入
第一行为n, m, k，表示A矩阵是n行m列，B矩阵是m行k列，n, m, k均小于100；然后先后输入A和B两个矩阵，A矩阵n行m列，B矩阵m行k列，矩阵中每个元素的绝对值不会大于100。

输出
输出矩阵C，一共n行，每行k个整数，整数之间以一个空格分开。
分析：由定义可得：C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + …… +A[i][m-1]*B[m-1][j](C[i][j]，因此每次计算C[i][j]时可以枚举k=0~m-1，计算的和。

样例输入
2 3 2
1 2 3
2 1 4
1 2
2 1
3 2

样例输出
14 10
16 13
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[n][m], b[m][k], c[n][k];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			cin >> b[i][j];
	int sum = 0;
	for(int i = 0; i < n; i++)
		for(int p = 0; p < k; p++)
			for(int j = 0; j < m; j++){
				c[i][p] += a[i][j] * b[j][p];
		}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}

