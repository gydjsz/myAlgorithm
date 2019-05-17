/*
Id:[105]	
最大字段和 (15分)
题目内容:
给定长度为n的整数序列，a[1...n], 求[1,n]某个子区间[i , j]使得a[i]+…+a[j]和最大.或者求出最大的这个和.例如(-
2,11,-4,13,-5,2)的最大子段和为20,所求子区间为[2,4].
输入描述:
第一行为一个整数n，表示数组有n个数据，第二行依次输入n个整数
输出描述:
计算出n个整数中连续k个数的最大和
输入样例:
5
1 2 3 4 5

7
6 -5 5 8 -13 5 7
输出样例:
15
14
*/

#include <iostream> 
#include <cstring>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a[n + 1];
	memset(a, 0, sizeof(a));
	ll maxSum = 0;
	ll minSum = 0x3f3f3f3f;
	int flag = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
		if(a[i] >= maxSum){
			maxSum = a[i];
			flag = i;
		}
	}
	for(int i = 0; i < flag; i++){
		minSum = min(a[i], minSum);
	}
	cout << maxSum - minSum << endl;
    return 0;
}
