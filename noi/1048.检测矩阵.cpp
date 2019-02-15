/*
题目描述
给定n*n由0和1组成的矩阵，如果矩阵的每一行和每一列的1的数量都是偶数，则认为符合条件。
你的任务就是检测矩阵是否符合条件，或者在仅改变一个矩阵元素的情况下能否符合条件。
"改变矩阵元素"的操作定义为0变成1或者1变成0。

输入
输入n + 1行，第1行为矩阵的大小n(0 < n < 100)，以下n行为矩阵的每一行的元素，元素之间以一个空格分开。

输出
如果矩阵符合条件，则输出OK；
如果矩阵仅改变一个矩阵元素就能符合条件，则输出需要改变的元素所在的行号和列号，以一个空格分开。
如果不符合以上两条，输出Corrupt。

样例输入
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1

样例输出
OK
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n][n], b[n], c[n];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j]){
				b[i]++;
				c[j]++;
			}
		}
	int flag = 0;
	int x, y;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if(flag == 0 && b[i] % 2 != 0 && c[j] % 2 != 0){
				b[i]++;
				c[j]++;
				flag = 1;
				x = i;
				y = j;
			}
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(b[i] % 2 != 0 || c[j] % 2 != 0){
				cout << "Corrupt" << endl;
				return 0;
			}
	if(flag)
		cout << x + 1 << " " << y + 1 << endl;
	else
		cout << "OK" << endl;
	return 0;
}
