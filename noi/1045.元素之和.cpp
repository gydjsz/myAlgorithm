/*
题目描述
输入4*4方阵，分别求两条对角线上元素之和。

输入
输入4*4方阵。

输出
输出两条对角线上元素之和(如样例所示)。

样例输入
0 0 2 7 
5 3 2 1 
9 9 7 0 
9 1 9 5 

样例输出
15 27
*/

#include <iostream>
using namespace std;

int main(){
	int a;
	int x = 0, y = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			cin >> a;
			if(i == j)
				x += a;
			if(i + j == 3)
				y += a;
		}
	cout << x << " " << y << endl;
	return 0;
}
