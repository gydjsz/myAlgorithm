/*
Id:[1523]	
2019春校赛--求索溪边的树 (10分)
题目内容:
三峡大学求索溪路边种了三行树，每棵树的高度可以用 0-9 的数字表示，因此每行树都可以用一个数字串(由数字字
符组成的字符串) s 来表示。有一次走在小溪边，我非常惊喜地发现 s 竟然可以通过某个较短的数字串 t 重复 k 次得到。
最近(4月5日左右), 学校把求索溪路边中间一行的一些树挖出来了，假设学校想要通过去掉一些树来让表示这行树
的数字串 s 表示的数字看起来更美丽, 这里对美丽的定义是这个数字可以被 5 整除。
现在学校想知道总共有多少种方法可以达到目的。

注意：

1. 当我们把字符串变成数字时，要忽略前面的0，例如“000123”表示的数字为123。
2. 只要去掉的树不同，就是不同的方法。
3. 由于结果可能很大，所以只需要输出结果对 1000000007 的余数即可。
4. 不能把所有的树都移除。

例如，s="100"时，有以下六种方法，下划线表示对应位置的树被去掉了。
100
10_
1_0
_00
_0_
__0
输入描述:
第一行一个正整数 T(<10), 表述测试数据组数。
接下来 T 行，每行先是一个数字 k(<=100000), 然后是一个数字串 t(长度<=20)，表示 s 是由 t 重复 k 次得到的。
输出描述:
输出包括 T 行，每行一个正整数.
第 i 行的正整数表示第 i 组测试数据的答案，也就是方法数对 1000000007 取余数的结果。
输入样例:
1
1 100
输出样例:
6
*/

#include <iostream> 
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll f_pow(ll x, ll n){
	if(n < 0)
		return 0;
	ll res = 1;
	while(n > 0){
		if(n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int solve(){
	int k;
	string s;
	cin >> k >> s;
	ll b[100005];
	memset(b, 0, sizeof(b));
	int bk = 0, x = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0' || s[i] == '5')
			b[bk++] = x;
		x++;
	}
	ll sum = 0;
	for(int i = 0; i < bk; i++){
		for(int j = 0; j < k; j++){
			sum = (sum + f_pow(2, b[i] + j * s.length())) % MOD;
		}
	}
	cout << sum << endl;
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
