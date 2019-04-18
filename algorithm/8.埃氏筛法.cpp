/*
 埃氏筛法：首先用一张表把1～n的所有数表示出来，其中2是最小的素数，将表中所有2的倍数划去，表中剩余的最小数字为3，它不能被更小的数整除，因而它是素数，将3的倍数从表中划去，依次类推，就能枚举n以内的素数, 时间复杂度O(nlognlogn)
 */

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100000;

int prime[MAXSIZE];   //存储n以内的素数
bool is_prime[MAXSIZE];   //第i个数是否为素数

int getPrime(int n){
	int p = 0;
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 0; i < n; i++){
		if(is_prime[i]){
			prime[p++] = i;
			for(int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main(){
	int n;
	cin >> n;
	int m = getPrime(n);
	for(int i = 0; i < m; i++)
		cout << prime[i] << " ";
    
    return 0;
}
