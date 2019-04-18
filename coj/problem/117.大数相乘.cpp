/*
Id:[117]		大数相乘 (20分)
(C时间限制：3000 毫秒 | 
			C内存限制：3000 Kb)
题目内容:
 一个整型变量只能用来存贮较小的n!的值，当 n 较大时，可将阶乘值中的每一个数字放在一个一维数组的一个元素中。使用这方法，打印n!的值；


输入描述:
整数n
输出描述:
n!的值
输入样例:
18
输出样例:
6402373705728000
*/

#include <iostream> 
#include <cstring>
using namespace std;

int getFactorial(){
	int n;
	cin >> n;
	int a[1000];
	memset(a, 0, sizeof(a));
	a[1] = 1;
	int p = 1; 
	for(int i = 1; i <= n; i++){
		int f = 0, t = 0;
		for(int j = 1; j <= p; j++){
			t = a[j] * i + f;
			a[j] = t % 10;
			f = t / 10;

		}
		while(f){
			p++;
			a[p] = f % 10;
			f /= 10;
		}
	}
	for(int i = p; i >= 1; i--)
		cout << a[i];
	return 0;
}

int main(){
	getFactorial();
    return 0;
}
