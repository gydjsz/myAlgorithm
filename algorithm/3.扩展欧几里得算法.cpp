/*
当b = 0时，gcd(a, b) = a, 此时x = 1, y = 0
当a > b时，设a * x1 + b * y1 = gcd(a, b);
             b * x2 + (a % b) * y2 = gcd(b, a % b);
gcd(a, b) = gcd(b, a % b);
所以a * x1 + b * y1 = b * x2 + (a % b) * y2;
=> a * x1 + b * y1 = b * x2 + (a - [a / b] * b) * y2;   []表示取整
=> a * x1 + b * y1 = a * y2 + b * (x2 - [a / b] * y2);
=> x1 = y2,  y1 = x2 - [a / b] * y2

此时得出x1和y1的值基于x2和y2,因而可以将每次a * x2 + b * y2 = gcd(b, a % b)的x2、y2的值代入求得x1和y1, 多次递归后b = 0，x = 1, y = 0,　最终求得x和y的值，即a * x + b * y = gcd(a, b) 的方程组的解
*/
#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
	if(b == 0){   //当ｂ的值为０时的x = 1, y = 0
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);   //求得最小公约数的值
	//将每一次gcd得到的x2 和 y2用公式x1 = y2, y1 = x2 - a / b * y2求得x1和y1
	y -= a / b * x;
	return gcd;
}

int main(){
	int a, b, x, y;
	cin >> a >> b;
	cout << exgcd(a, b, x, y) << endl;  //最大公约数
	cout << x << " " << y << endl;   //求得的一种解
	return 0;
}
