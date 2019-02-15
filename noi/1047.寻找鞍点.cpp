/*
题目描述
给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

输入
输入包含一个5行5列的矩阵

输出
如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"

样例输入
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25

样例输出
4 1 8

*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int a[5], b[5], c[5][5];
	memset(a, 0, sizeof(a));
	memset(b, 9999999, sizeof(b));
	memset(c, 0, sizeof(c));
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++){
			cin >> c[i][j];
			a[i] = max(a[i], c[i][j]);
			b[j] = min(b[j], c[i][j]);
		}
	int flag = 0;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(c[i][j] == a[i] && c[i][j] == b[j]){
				cout << i + 1 << " " << j + 1 << " " << c[i][j] << endl;
				flag = 1;
			}
	if(!flag)
		cout << "not found" << endl;
	return 0;
}
