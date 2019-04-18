/*
Id:[66]	
砝码组合 (15分)
题目内容:
用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
如果只有5个砝码，重量分别是1，3，9，27，81。
则它们可以组合称出1到121之间任意整数重量（砝码允许放在左右两个盘中）。
本题目要求编程实现：对用户输入的重量(1~121)，
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
例如：
输入：
5
输出：
9-3-1

输入：
19
输出：
27-9+1

要求程序输出的组合总是大数在前小数在后。
输入描述:
用户输入的重量(1~121)，
输出描述:
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
输入样例:
19
输出样例:
27-9+1
*/

#include <iostream>
using namespace std;

//int a[] = {1, 3, 9, 27, 81};
int a[] = {81, 27, 9, 3, 1};

const int MAXSIZE = 5;
int visit[MAXSIZE][MAXSIZE];
int n, k, flag, m;

int dfs(int i, int sum){
	if(n == sum){
		k++;
		return 0;
	}
	if(i >= 5)
		return 0;

	dfs(i + 1, sum);

	visit[k][i] = 1;
	dfs(i + 1, sum + a[i]);
	visit[k][i] = 0;

	visit[k][i] = 2;
	dfs(i + 1, sum - a[i]);
	visit[k][i] = 0;

	return 0;
}

int main(){
	cin >> n;
	dfs(0, 0);
	int m = 6, flag = 0;
	for(int i = 0; i < k; i++){
		int s = 0;
		for(int j = 0; j < MAXSIZE; j++)
			if(visit[i][j] != 0)
				s++;
		if(m > s){
			m = s;
			flag = i;
		}
	}
	int f = 0;
	for(int i = 0; i < MAXSIZE; i++){
		if(visit[flag][i] != 0){
			if(f == 0){
				cout << a[i];
				f = 1;
			}
			else if(visit[flag][i] == 1)
				cout << "+" << a[i];
			else
				cout << "-" << a[i];
		}
	}
	cout << endl;
	return 0;
}
