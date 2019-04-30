/*
Id:[79]	
数字列表 (15分)
题目内容:
给出包含M个数字的列表，和列表中所有数字的所有质因数。求出最长的子列表，使得子列表中所有数字的乘积是一个完全平方数.
 
输入描述:
输入文件包含多组测试数据。第一行包含两个整数N , M ( 1 <= N <= 30 , 1 <= M <= 30000 ). N 

是质因数的个数。接下来一行有N个整数，给出所有的质因数。然后一行包含M个整数，给出列表。

输出描述:
对于每组数据，输出最长子列表的两个位置坐标l r。l是该子列表在列表中的起始位置，r是结束位置

。如果多种情况都满足子列表长度最大，输出l最小的一个。如果不存在这样的子列表输出“None”。

输入样例:
3 4
2 3 5
4 9 25 6
3 4
2 3 5
6 6 3 3
0 0
输出样例:
1 3
1 4
*/

#include <iostream> 
#include <cstring>
using namespace std;

int a[30005][40];
int b[40];
int n, m;

int getN(int n, int k){
	int sum = 0;
	while(n % k == 0){
		n /= k;
		sum++;
	}
	return sum;
}

int solve(){
	int x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> x;
		for(int j = 1; j <= n; j++){
			a[i][j] = getN(x, b[j]);
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			a[j][i] += a[j - 1][i];	
		}
	int L = 1, R = 1, maxT = 0;
	for(int i = 1; i <= m; i++)
		for(int j = i; j <= m; j++){
			int flag = 1;
			for(int k = 1; k <= n; k++)
				if((a[j][k] - a[i - 1][k]) % 2 != 0){
					flag = 0;
					break;
				}
			if(flag == 1 && maxT < j - i + 1){
				maxT = j - i + 1;
				L = i;
				R = j;
			}
		}
	cout << L << " " << R << endl;
	return 0;
}

int main(){
	while(cin >> n >> m && n != 0 && m != 0)
		solve();
    return 0;
}
