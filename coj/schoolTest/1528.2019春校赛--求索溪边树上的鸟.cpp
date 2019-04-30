/*
Id:[1528]	
2019春校赛--求索溪边树上的鸟 (10分)
题目内容:
为了避免生态系统太单一，学校打算在求索溪边种两种树，在偶数位置种 A 树，奇数位置种 B 树(序号从 1 开始),
由于这两种树太漂亮了，经常有鸟儿飞到树上来玩耍，过一会又会飞走。现在小明想知道某一时刻从 L 位置到 R
位置这段区间中 A 种树或者 B 种树上鸟儿的总数。

输入描述:
输入描述:
第一行两个正整数 N, M, (N<=1e5 ,M<=50000)。
接下来一行有 N 个正整数，第 i 个数字表示第 i 课树上初始时鸟的数量, 每个数字都在[0,100]之间。
接下来 M 行表示 M 个操作，每条操作的格式为如下二者之一：
0 L R type
1 a b
第一种格式表示查询区间 [L,R] 中 type 种类的树上的鸟儿总数, type 取 0 时表示 A 种树，取 1 时表示 B 种树.
第二种格式表示位置为 a 的树上的鸟儿的数目增加或减少了 b 只(正数表示增加，负数表示减少，题目保证
每棵树上鸟的数量不会小于0, b在[-3,3]之间)

输出描述:
对于每组查询，在一行中输出对应的结果。
输入样例:
5 5
1 2 3 4 5
0 1 3 0
0 1 3 1
1 1 -1
0 1 3 0
0 1 3 1
输出样例:
2
4
2
3
*/

#include <stdio.h>
#include <string.h>

const int MAXSIZE = 1000005;
typedef long long ll;
ll a[MAXSIZE];
ll b[MAXSIZE];

ll getSum(int i, ll array[]){
	ll s = 0;
	while(i > 0){
		s += array[i];
		i -= i & -i;
	}
	return s;
}

int add(int i, int n, ll x, ll array[]){
	while(i <= n){
		array[i] += x;
		i += i & -i;
	}
	return 0;
}

int main(){
	int m;
	int n;
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	ll x;
	int ak = 1, bk = 1;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &x);
		if(i % 2 == 0)
			add(ak++, n / 2, x, a);
		else
			add(bk++, (n + 1) / 2, x, b);
	}
	int p;
	ak--;
	bk--;
	for(int i = 0; i < m; i++){
		ll sum = 0;
		scanf("%d", &p);
		if(p == 0){
			int L, R, type;
			scanf("%d%d%d", &L, &R, &type);
			ll sum = 0;
			if(type == 0){
				L = L % 2 == 0 ? L / 2 : (L + 1) / 2;
				R = R % 2 == 0 ? R / 2 : (R - 1) / 2;
				sum = getSum(R, a) - getSum(L - 1, a);
			}
			else{
				L = L % 2 == 0 ? L / 2 + 1 : (L + 1) / 2;
				R = R % 2 == 0 ? R / 2 : (R + 1) / 2;
				sum = getSum(R, b) - getSum(L - 1, b);
			}
			printf("%lld\n", sum);
		}
		else{
			int t;
			ll s;
			scanf("%d%lld", &t, &s);
			if(t % 2 == 0)
				add(t / 2, ak, s, a);
			else
				add((t + 1) / 2, bk, s, b);
		}
	}
    return 0;
}
