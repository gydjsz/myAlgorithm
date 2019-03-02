/*
 * x ^ n = ((x^2)^2)...
 * x ^ n = x^(2^k1) * x^(2^k2)...
 * x^22 = x^2 * x^4 * x^16
 * x^21 = x * x^4 * 2^16  //21的二进制为10101，在１处进行res *= x;
 */

#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 10000000007;

//非递归
ll fast_pow1(ll x, ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1)   //n为奇数，如3,二进制为11, 末尾为１，11 & 1 => 11 & 01 => 1(true)，res = 1 * x,进行了n >>= 1操作后，最终n变为1, 1 & 1 => 1, res = 2 * 4 = 8; n为偶数,if操作只有当n = 1时才执行
			res = res * x % MOD;   //根据题意是否添加% MOD
		x = x * x % MOD;    //根据题意是否添加% MOD
		n >>= 1;   //右移操作，相当于除２
	}
	return res;
}

//递归
ll fast_pow2(ll x, ll n){
	if(n == 0)
		return 1;
	ll res = fast_pow2(x * x, n / 2);
	if(n & 1)
		res = res * x;
	return res;

}

int main(){
	int x, n;
	cin >> x >> n;
	cout << fast_pow1(x, n) << endl;
	cout << fast_pow2(x, n) << endl;
	return 0;
}
