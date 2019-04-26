/*
Id:[65]	
灯泡 (15分)
题目内容:
一百个灯泡排成一排，第一轮将所有灯泡打开；
第二轮每隔一个灯泡关掉一个。即排在偶数的灯泡被关掉，
第三轮每隔两个灯泡，将开着的灯泡关掉，关掉的灯泡打开。
依次类推，第n轮结束的时候，还有几盏灯泡亮着。
输入描述:
程序输入n( 0 < n < 101)
输出描述:
输出亮的灯数。
输入样例:
2
输出样例:
50
*/

#include <iostream> 
#include <cstring>
using namespace std;

int a[200];

int solve(int n){
	for(int i = 2; i <= n; i++){
		for(int j = i; j <= 100; j += i){
			if(a[j] == 0)
				a[j] = 1;
			else
				a[j] = 0;
		}
	}
	int sum = 0;
	for(int i = 1; i <= 100; i++)
		if(a[i] == 1)
			sum++;
	cout << sum << endl;
	return 0;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= 100; i++)
		a[i] = 1;
	solve(n);
    return 0;
}
