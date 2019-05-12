/*
Id:[648]	
欧拉定理-最小x (10分)
题目内容:
 给定一个n, 求满足 2^x =1 (mod n)的最小x.
输入描述:
输入整数n
输出描述:
输出最小的x, 或者输出“不存在”
输入样例:
5
输出样例:
4
*/

/*
 * 欧拉函数是小于x的整数中与x互质的数的个数，一般用φ(x)表示。特殊的，φ(1)=1。
 *
思路：
1. 当n为偶数时，bn + 1（b为整数）是奇数，而2^x是偶数，故 2^x mod n = 1不可能成立；
2. 当n等于1时，不能成立
3. 当n为非1的奇数时，n和2互质，由欧拉定理：若a，n为正整数，且两者互素，则a^phi(n) mod n = 1，其中phi(n)是n的欧拉函数。知2^phi(n) mod n = 1.因此phi(n)必是符合要求的x，但phi(n)未必是最小的，遍历小于其的正整数，逐一试验即可，计算2^x mod n时用快速幂乘。
 */

#include <iostream>
using namespace std;

typedef long long ll;


ll eular(ll n){
	ll ans = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			ans -= ans / i;
			while(n % i == 0) n /= i; 
		}
	}
	if(n > 1)
		ans -= ans / n;
	return ans;
}

ll fast_pow(ll x, ll k, ll n){
	ll res = 1;
	while(k > 0){
		if(k & 1) res = res * x % n;
		x = x * x % n;
		k >>= 1;
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	if(n <= 1 || n % 2 == 0){
		cout << "不存在" << endl;
		return 0;
	}
	ll phi = eular(n);
	for(int i = 1; i < phi; i++){
		if(fast_pow(2, i, n) == 1){
			cout << i << endl;
			return 0;
		}
	}
	cout << phi << endl;
    return 0;
}
