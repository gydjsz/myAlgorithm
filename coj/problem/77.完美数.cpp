/*
Id:[77]	
完美数 (15分)
题目内容:
如果有一正整数n，其真因数的总和等于n，则称之为完美数。
例如以下几个数都是完美数：
6=1+2+3
28=1+2+4+7+14
496=1+2+4+8+16+31+62+124+248
求小于n的所有完美数.
 
输入描述:
输入一个正整数n

输出描述:
输出小于n的完美数，按升序输出，每个数据占一行

输入样例:
10
输出样例:
6
*/

/*
 *
 假设这个数是n，质因数分解后可以写成
 n=a1^k1*a2^k2*……*ai^ki
 所求的数的因数和f(n)就等于
 f(n)=(1+a1+a1^2+……+a1^k1)*(1+a2+a2^2+……+a2^k2)*……*(1+ai+ai^2+……+ai^ki)

 因子个数为g(n) = (1 + k1) * (1 + k2) * ... * (1 + ki)
 真因数为不包括本身的因数
 */

#include <iostream> 
#include <cstring>
#include <cmath>
using namespace std;

const int MAXSIZE = 100000;
int prime[MAXSIZE];
bool is_prime[MAXSIZE];
int p = 0;

int getPrime(int n){
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <= n; i++){
		if(is_prime[i]){
			prime[p++] = i;
			for(int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return 0;
}

int solve(int n){
	int t = n;
	int sum = 1;
	for(int i = 0; i < p && t != 1; i++){
		int k = 0;
		if(t % prime[i] == 0){
			while(t % prime[i] == 0){
				t /= prime[i];
				k++;
			}
			sum *=  (pow(prime[i], k + 1) - 1) / (prime[i] - 1);
		}
	}
	sum -= n;
	if(sum == n)
		cout << n << endl;
	return 0;
}

int main(){
	int n;
	cin >> n;
	getPrime(n);
	for(int i = 2; i < n; i++){
		solve(i);
	}
	return 0;
}

