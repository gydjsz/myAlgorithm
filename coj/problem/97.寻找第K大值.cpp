/*
Id:[97]	
寻找第K大值 (15分)
题目内容:
 在一个整数数组中，寻找第k大值所在位置。假设每个数值都不一样。要求算法时间复杂性通常情况下为线性。
输入描述:
包括一个数组长度n,一个k, 以及紧接着的n个整数值。整数之间用空格隔开。
输出描述:
第k大值所在位置编号。规定数组的第一个位置编号为0.
输入样例:
7 3
1 4 3 9 8 7 2
输出样例:
5
*/

#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n], c[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		c[i] = a[i];
	}
	sort(a, a + n);
	int t = a[n - k];
	for(int i = 0; i < n ;i++)
		if(t == c[i]){
			cout << i << endl;
			return 0;
		}
    return 0;
}
