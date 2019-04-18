/*
Id:[113]	
找零钱 (5分)
题目内容:
一个小孩买了价值少于1美元的糖，假设提供了数目不限的面值为2 5美分、1 0美分、5美分、及1美分的硬币，写一个算法让小孩
用最少的硬币付款。1美元=100美分

输入描述:
糖的价格
输出描述:
4种硬币的个数，中间用空格隔开。
输入样例:
75
输出样例:
3 0 0 0
*/

#include <iostream> 
#include <cstring>
using namespace std;

int solve(int n){
	int a[n];
	int b[] = {25, 10, 5, 1};
	memset(a, 0, sizeof(a));
	for(int i = 0; i < 4; i++){
		a[i] = n / b[i];
		n -= a[i] * b[i];
	}
	for(int i = 0; i < 4; i++)
		cout << a[i] << " ";
	return 0;
}

int main(){
	int n;
	cin >> n;
	solve(n);
    return 0;
}
