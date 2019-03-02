/* a * x = 1 (mod p)   x称为ａ关于１模p的乘法逆元,求x
 *
 * 方法一：扩展欧拉定理
 * a * x = 1 (mod p)  => a * x + p * y = 1
 * 利用扩展欧几里得法求得ｘ和ｙ，其中x为a关于１模ｐ乘法逆元
 *
 * 方法二：费马小定理
 * 费马小定理：假如p是质数，且gcd(a,p)=1，那么 a^(p-1)≡ 1（mod p）  (p是质数)
 *    a ^ (p - 1) = 1 (mod p)
 * => a * a ^ (p - 2) = 1 (mod p)
 * 令x = a^-1, x = a ^ (p - 2)(mod p)
 * 利用快速幂求得x
 */

#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

//扩展欧几里得
ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1; 
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return gcd;
} 

ll inv(ll a, ll b){
	ll d, x, y;
	d = exgcd(a, b, x, y);
	return  d == 1 ? (x + b) % b : -1;  //1.负数情况转为正, 2.必须满足互质，否则无逆元
}

ll powMod(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ll a;
	cin >> a;
	ll result = powMod(a, MOD - 2);
	cout << result << endl; 
	result = inv(a, MOD);
	cout << result << endl;
	return 0;
}

