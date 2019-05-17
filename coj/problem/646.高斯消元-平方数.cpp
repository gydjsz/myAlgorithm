/*
Id:[646]	
高斯消元-平方数 (10分)
题目内容:
有n个整数a1,a2,...an，每个数ai的质因子不超过2000. 现从中选取一些数，它们的乘积刚好是平方数。
问有多少种挑选方案。 假定n<=300, ai<=2000


输入描述:
第一行是n
第二行是n个整数

输出描述:
方案数。为防止数目过大，结果需模1000000007.
输入样例:
3
3 3 4
输出样例:
3
*/

#include <iostream> 
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int N = 2005;
const int M = 305;
int a[N][M];
int prime[M];
bool visit[M];
int equ,var;
int x[N]; //解集
int free_x[N];//用来存储自由变元(多解枚举自由变元可以使用)
int free_num;//自由变元的个数

int getPrime(int n){
	int cnt = 0;
	memset(visit, true, sizeof(visit));
	for(int i = 2; i <= n; i++){
		if(visit[i])
			prime[cnt++] = i;
		for(int j = 0; j < cnt && i * prime[j] <= n; j++){
			visit[i * prime[j]] = false;
			if(i * prime[j] == 0) break;
		}
	}
	return cnt;
}

void swap(int &a, int &b){
	int t;
	t = a;
	a = b;
	b = t;
}

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}



ll fpow(ll x, ll n){
	ll res = 1;
	while(n){
		if(n & 1) res = res * x % MOD;;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int Gauss(){
	int max_r, col, k;
	free_num = 0;
	for(k = 0, col = 0; k < equ && col < var; k++, col++){
		max_r = k;	
		for(int i = k + 1; i < equ; i++){
			if(abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		}
		if(a[max_r][col] == 0){
			k--;
			free_x[free_num++] = col;
			continue;
		}
		if(max_r != k){
			for(int j = col; j < var + 1; j++)
				swap(a[k][j], a[max_r][j]);
		}
		for(int i = k + 1; i < equ; i++){
			if(a[i][col] != 0){
				for(int j = col; j < var + 1; j++)
					a[i][j] ^= a[k][j];
			}
		}
	}
	for(int i = k; i < equ; i++)
		if(a[i][col] != 0)
			return -1;
	if(k < var) return var - k;
	for(int i = var - 1; i >= 0; i--){
		x[i] = a[i][var];
		for(int j = i + 1; j < var; j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}



int main(){
	int n;
	cin >> n;
	int cnt = getPrime(n);
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		int s = 0;
		equ = cnt;
		var = n;
		for(int j = 0; j < cnt; j++){
			s = 0;
			while(x % prime[j] == 0){
				x /= prime[j];
				s++;
			}
			if(s & 1)
				a[i][j] = 1;
		}
	}
	int ans = Gauss();
	cout << fpow(2, ans) - 1 << endl;
	return 0;
}
