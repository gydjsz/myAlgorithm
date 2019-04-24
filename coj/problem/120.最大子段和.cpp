/*
Id:[120]	
最大子段和 (20分)
题目内容:
 实数序列a[1],a[2],...a[n], 一个子段指一段连续的子序列a[i],a[i+1],...a[j], 其中1<=i<=j<=n. 要求给出具有最
大和的子段。要求算法时间复杂性为o(n)。
输入描述:
第一行输入一个整数n,表示原序列共有n个数据；
第二行输入n个实数，用空格隔开。
输出描述:
最大和的子段，每个数据也用空格隔开。
（本题的测试数据能保证最大和的那一个子段是唯一的）
输入样例:
7
-1 3 -2 4 -1 6 -5
输出样例:
3 -2 4 -1 6
*/

#include <iostream> 
using namespace std;

const int MAXSIZE = 1000;

int main(){
	int n;
	int a[MAXSIZE];
	int b[MAXSIZE];
	cin >> n;
	int minF = 0, maxF = 0, minS = 1e9, maxS = -1e9;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
		if(maxS <= b[i]){
			maxS = b[i];
			maxF = i;
		}
	}
	for(int i = 1; i < maxF; i++){
		if(minS > b[i]){
			minS = b[i];
			minF = i;
		}
	}
	for(int i = minF + 1; i <= maxF; i++)
		cout << a[i] << " ";
    return 0;
}
