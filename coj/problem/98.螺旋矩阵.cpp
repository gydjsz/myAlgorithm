/*
Id:[98]	
螺旋矩阵 (5分)
题目内容:
 一个从里向外逆时针转出来的螺旋n*n的矩阵 输
输入描述:
矩阵的规模，0~50，如5表示5行5列的矩阵
输出描述:
矩阵的规模，0~50，如5表示5行5列的矩阵，每个数占5位
输入样例:
5
输出样例:
25    24   23   22    21
10     9    8    7    20
11     2    1    6    19
12     3    4    5    18
13    14   15   16    17
*/

#include <iostream> 
#include <iomanip>
#include <cstring>
using namespace std;

int solve(int n){
	int sum = 1;
	int a[n + 1][n + 1];
	memset(a, 0, sizeof(a));
	int j = n / 2, i = n % 2 == 0 ? n / 2 - 1 : n / 2;
	int flag = n * n;
	if(n == 0)
		return 0;
/*
25    24   23   22    21
10     9    8    7    20
11     2    1    6    19
12     3    4    5    18
13    14   15   16    17
*/
	a[i][j] = sum;
	j--;
	int x1 = i - 1, x2 = i + 1, y1 = j, y2 = j + 2;
	while(sum != flag){
		for(; i <= x2 && sum != flag; i++)
			a[i][j] = ++sum;
		for(i--, j++; j <= y2 && sum != flag; j++)
			a[i][j] = ++sum;
		for(j--, i--; i >= x1 && sum != flag; i--)
			a[i][j] = ++sum;
		for(i++, j--; j >= y1 && sum != flag; j--)
			a[i][j] = ++sum;
		x1--;
		x2++;
		y1--;
		y2++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j < n - 1)
				cout << left << setw(5) << a[i][j];
			else
				cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}

int main(){
	int n;
	cin >> n;
	solve(n);
	return 0;
}
