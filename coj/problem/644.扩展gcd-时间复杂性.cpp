/*
Id:[644]	
扩展gcd-时间复杂性 (10分)
题目内容:
计算循环语句的执行频次 for(i=A; i!=B ; i+=C) x+=1;
其中A,B,C,i都是k位无符号整数。
输入描述:
A B C k, 其中0<k<32
输出描述:
输出执行频次数，如果是无穷，则输出“forever”
输入样例:
3 7 2 16
输出样例:
2
*/

#include <iostream> 
#include <cmath>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return gcd;
}

int main(){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int x, y;
	int t = 1 << k;
	int gcd = exgcd(c, -1 * t, x, y);
	if(a == 0 && b == 0 && c == 0 && k == 0 || (b - a) % gcd)
		cout << "forever" << endl;
	else{
		x = (x * ((b - a) / gcd)) % t;
		x = (x % (t / gcd) + (t / gcd)) % (t / gcd);
		cout << x << endl;
	}
	return 0;
}

