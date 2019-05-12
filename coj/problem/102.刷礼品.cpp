/*
Id:[102]	
刷礼品 (15分)
题目内容:
 一年一度的百度之星又开始了，这次参赛人数创下了吉尼斯世界纪录，于是百度之星决定奖励一部分人：所有资格赛提交ID以x
结尾的参赛选手将得到精美礼品一份。
小小度同学非常想得到这份礼品，于是他就连续提交了很多次，提交ID从a连续到b，他想问问你他能得到多少份礼品，你能帮帮
他吗？
输入描述:
第一行一个正整数T表示数据组数；
接下去T行，每行三个正整数x，a，b (0<=x<=10^18， 1<=a，b <=10^18，a<= b)
输出描述:
T行，每行为对应的数据情况下，小小度得到的礼品数
输入样例:
1
88888 88888 88888
输出样例:
1
*/

#include <iostream> 
#include <cstring>
#include <sstream>
#include <cmath>
using namespace std;

typedef long long ll;

int solve(){
	ll x, a, b;
	cin >> x >> a >> b;
	ll len = x == 0 ? 1 : ll(log10(x)) + 1;
	ll L = pow(10, len);
	ll n1, n2;
	n1 = a % L > x ? ((a / L) + 1) * pow(10, len) + x : (a / L) * pow(10, len) + x;
	n2 = b % L >= x ? (b / L) * pow(10, len) + x : ((b / L) - 1) * pow(10, len) + x;
	if(n2 > b || n1 > n2)
		cout << 0 << endl;
	else{
		L = pow(10, len);
		n1 /= L; 
		n2 /= L;
		ll sum = n2 - n1 + 1;
		cout << sum << endl;
	}
	return 0;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
    return 0;
}
