/*
题目描述
已知矩形的大小为n×m，现用a×a的正方形填充该矩形。输入三个正整数n,m,a（n,m,a≤10^9），计算至多能填入多少正方形？（正方形可以正好碰到矩形边界，但不能超出矩形外）

输入
一行三个用一个空格隔开的正整数n,m,a。

输出
输出能填入正方形的数量。

样例输入
3 4 1

样例输出
12
*/

/*这题就是看矩形的两边相当于多少个a，然后相乘即可*/
/*
 __ __ __ __ __
|              |
|              |
|              |
|__ __ __ __ __|

*/

#include <iostream>
using namespace std;
#define ll long long

int main(){
	ll n, m, a;
	cin >> n >> m >> a;
	ll sum = (n / a) * (m / a);  //乍一看和n * m / (a * a)差不多，但是不一样，n / a 和 m / a, 如果除不尽就损失了精度，求出来的就是能填入的个数
	cout << sum << endl;
	return 0;
}
