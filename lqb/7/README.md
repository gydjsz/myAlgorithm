# 第七届蓝桥杯真题解题报告

<span id = "0">目录：</span>
1. [煤球数目](#1)
2. [生日蜡烛](#2)
3. [凑算式](#3)
4. [快速排序](#4)
5. [抽签](#5)
6. [方格填数](#6)
7. [剪邮票](#7)
8. [四平方和](#8)
9. [交换瓶子](#9)
10. [最大比例](#10)

[<span id = "1">1. 煤球数目</span>](#0)

有一堆煤球，堆成三角棱锥形。具体：
第一层放1个，
第二层3个（排列成三角形），
第三层6个（排列成三角形），
第四层10个（排列成三角形），
....
如果一共有100层，共有多少个煤球？

请填表示煤球总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

解：
思路：
3 - 1 = 2
6 - 3 = 3
10 - 6 = 4
通过观察可以写出该数列的递推公式: an - an-1 = n, 对an累加求和即可

```cpp
#include <iostream>
using namespace std;

int main(){
	int a = 0, s = 0;
	for(int i = 1; i <= 100; i++){   //递推计算数列
		a += i;   //求an
		s += a;   //累加ai
	}
	cout << s << endl;
	return 0;
}
```

答案：171700
---

[<span id = "2">2. 生日蜡烛</span>](#0)

某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。
现在算起来，他一共吹熄了236根蜡烛。
请问，他从多少岁开始过生日party的？
请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

解：
思路：因为蜡烛数目和年龄数对应，而年龄是一个等差数列，其前n项和为Sn = n * (n + 1) / 2
设他从n年开始举办生日，现在已经m年了，则Sm - Sn + an= 236, (这里+an，是因为会减去开始的那一年的蜡烛数，比如从1开始举办生日，举办了3年，就是Sm = 1+2+3 = 6, Sn = 1, Sm - Sn = 5, (实际应该是6才对).
m * (m + 1) / 2 - n * (n + 1) / 2 + n = 236<br />
=> (m + n)(m - n + 1) = 472<br/>
472因式分解：2, 2, 2, 59<br />
得出m - n + 1只能是2 * 2 * 2 = 8, (m + n)只能是59<br />
m - n + 1 = 8<br />
m + n = 59  联立求得方程组的解为m = 33, n = 26

程序解决：
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int sum;
	for(int i = 1; i <= 150; i++){
		sum = 0;
		for(int j = i; j <= 150; j++){
			sum += j;
			if(sum == 236){
				cout << i << endl;
			}
		}
	}
	return 0;
}
```

答案：26
---


[<span id = "3">3. 凑算式</span>](#0)

```
     B      DEF
A + --- + ------- = 10
     C      GHI
```
     
这个算式中A ~ I代表1 ~ 9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。

解：
思路：生成1-9的全排列，然后暴力尝试即可，这里可以将除法转化为乘法，避免小数的情况，转化后为
A * C * GHI + B * GHI + C * DEF = 10 * C * GHI

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[10];
	for(int i = 1; i <= 9; i++){
		a[i] = i;
	}
	int sum = 0;
	do{
		int A = a[1], B = a[2], C = a[3], D = a[4], E = a[5], F = a[6], G = a[7], H = a[8], I = a[9];
		int GHI = G * 100 + H * 10 + I;
		int DEF = D * 100 + E * 10 + F;
		if(A * C * GHI + B * GHI + C * DEF == 10 * C * GHI){
			sum++;
		}
	}while(next_permutation(a + 1, a + 10));   //全排列函数从生成数组a中[1, 10)的排列
	cout << sum << endl;
	return 0;
}
```

答案：29
---

[<span id = "4">4. 快速排序</span>](#0)

排序在各种场合经常被用到。
快速排序是十分常用的高效率的算法。
其思想是：先选一个“标尺”，
用它把整个队列过一遍筛子，
以保证：其左边的元素都不大于它，其右边的元素都不小于它。
这样，排序问题就被分割为两个子区间。
再分别对子区间排序就可以了。
下面的代码是一种实现，请分析并填写划线部分缺少的代码。

```cpp
#include <stdio.h>
void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r) {
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1){
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
	______________________;
    return j;
}

void quicksort(int a[], int p, int r) {
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main() {
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	quicksort(a, 0, N-1);
	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
```

注意：只填写缺少的内容，不要书写任何题面已有代码或说明性文字。

解：
思路：首先了解程序中的快速排序，采用分治的思想，将数据以第一个数为基准分成两部分,例子：
1. 初始：6 1 2 7 9 3 4 10 8     key = 6
6 1 2 7 9 3 4 10 8
i                  j

2. i从左边开始向右移动，遇到第一个比key大的数，停止(while(i < r && a[++i] < x))，j从最右边开始向左移动,遇到第一个比key小的数，停止(while(a[--j] > x))
```
6 1 2 7 9 3 4 10 8
      i     j

3. 交换i和j的位置,即代码中的swap()
6 1 2 4 9 3 7 10 8
      i     j

4. 重复2操作
6 1 2 4 9 3 7 10 8
        i j

5. 重复4操作
6 1 2 4 3 9 7 10 8
        i j

6. 重复2操作
6 1 2 4 3 9 7 10 8
        j i
```

7. i > j, 跳出循环, 此时由于j在i的左边，所以a[j] < a[i] 并且a[j] < a[0], 否则i不会到j的右边,
swap(a, p, j)操作，将6和3交换位置, 就完成了一次快速排序, 这里的p是传入的数据的最左边位置，也就是样例数据的a[0]

答案：swap(a, p, j)
---

[<span id = "5">5. 抽签</span>](#0)

X星球要派出一个5人组成的观察团前往W星。
其中：
A国最多可以派出4人。
B国最多可以派出2人。
C国最多可以派出2人。
....
那么最终派往W星的观察团会有多少种国别的不同组合呢？
下面的程序解决了这个问题。
数组a[] 中既是每个国家可以派出的最多的名额。
程序执行结果为：
DEFFF
CEFFF
CDFFF
CDEFF
CCFFF
CCEFF
CCDFF
CCDEF
BEFFF
BDFFF
BDEFF
BCFFF
BCEFF
BCDFF
BCDEF
....
(以下省略，总共101行)

```cpp
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[]) {
	int i,j;
	if(k==N){ 
		b[M] = 0;
		if(m==0) printf("%s\n",b);
		return;
	}

	for(i=0; i<=a[k]; i++){
		for(j=0; j<i; j++) b[M-m+j] = k+'A';
		______________________;  //填空位置
	}
}

int main() {	
	int  a[N] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,M,b);
	return 0;
}
```
仔细阅读代码，填写划线部分缺少的内容。
注意：不要填写任何已有内容或说明性文字。

解：
思路：a数组表示各国能派出的人数，b数组表示派出的组合，在f()函数中，第一个循环是遍历各国，第二个循环是各国派出的人数，这里明显是一个递归方程，k应该不断增加1，才能遍历完每一个国家，由于b中存储各国的人员，所以循环j次，就代表派出了j个人，m - j就表示还需要派出多少人，观察if内部程序，当k == N时表示对国家选择完，然后再看各国派出的人数是否达到了人，，当m == 0时，表示一种情况生成完毕，输出b数组

答案：f(a, k + 1, m - j, b)
---


[<span id = "6">6. 方格填数</span>]

如下的10个格子
```
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+
```

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）
一共有多少种可能的填数方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

解：
思路：这题直接暴力求解，全排列所有情况，然后一个个试就完事，判断每一个格子与周围格子的绝对值之差是否为1，如果为1就返回false, 否则返回true，每次以当前格子为基础，向四周比较，比较完就把当前格子划掉就不会漏掉。


```
   +--+--+--+                 +--+--+--+
   |a |b |c |                 |  |b |c |  
+--+--+--+--+  比较完a  => +--+--+--+--+,  
|d |e |f |g |              |d |e |f |g |
+--+--+--+--+              +--+--+--+--+
|h |i |j |                 |h |i |j |
+--+--+--+                 +--+--+--+   
```

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool can(int a, int b){
	return abs(a - b) == 1 ? false : true;   //判断格子是否相邻
}

int main(){
	int array[10];
	for(int i = 0; i <= 9; i++)   //初始化数组array
		array[i] = i;
	int sum = 0;

	do{
		int a = array[0], b = array[1], c = array[2], d = array[3], e = array[4], f = array[5], g = array[6], h = array[7], i = array[8], j = array[9];
	
		//一个个比较
		if(can(a, b) && can(a, d) && can(a, e) && can(a, f) && can(b, e) && can(b, f) && can(b, c) && can(b, g) && can(c, f) && can(c, g) && can(d, h) && can(d, e) && can(d, i) && can(e, i) && can(e, h) && can(e, f) && can(e, j) && can(f, i) && can(f, j) && can(f, g) && can(g, j) && can(h, i) && can(i, j))  
			sum++;
	}while(next_permutation(array, array + 10));   //生成全排列
	cout << sum << endl;
	return 0;
}
```

答案：1508
---

[<span id = "7">7. 剪邮票</span>](#0)

如<img src = "./7/7/图1.jpg" width = "50%" height = "50%"/>, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，<img src = "./7/7/图2.jpg" width = "50%" height = "50%"/>，<img src = "./7/7/图3.jpg" width = "50%" height = "50%"/>中，粉红色所示部分就是合格的剪取。
请你计算，一共有多少种不同的剪取方法。
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

解：
思路：将邮票的标号改为1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 这样上下相差5，左右相差1，下左边界和上右边界的数就相差2，便于判断，暴力循环求所有情况生成的数组c，dfs搜索c判断邮票是否连接，标号+{-1, 1, -5, 5}表示上下左右移动，已知c数组的第一个数如果该数经过移动操作能和c中第二个数相等，那么表示两个邮票连接

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int visit[5];
int a[] = {1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14}; 
int b[] = {-1, 1, -5, 5};
int c[5];

void dfs(int n){
    for(int i = 0; i < 4; i++) {
        int t = c[n] + b[i];
        if(t < 1 || t > 14 || t == 5 || t == 10) continue;
        for(int j = 0; j < 5; j++)
            if(!visit[j] && c[j] == t) {
                visit[j] = 1;
                dfs(j);
            }
    }
}

int main(){
	int sum = 0;
	for(int i = 1; i <= 14; i++)
		for(int j = i + 1; j <= 14; j++)
			for(int k = j + 1; k <= 14; k++)
				for(int p = k + 1; p <= 14; p++)
					for(int q = p + 1; q <= 14; q++) {
					c[0] = a[i];
					c[1] = a[j];
					c[2] = a[k];
					c[3] = a[p];
					c[4] = a[q];
					memset(visit, 0, sizeof(visit));
					visit[0] = 1;
					dfs(0);
					int flag = 0;
					for(int i = 0; i < 5; i++){
						if(visit[i] == 1){
							flag++;
						}
					}
					if(flag == 5)
						sum++;
				}
	cout << sum << endl;
	return 0;
}
```
答案：116
---

[<span id = "8">8. 四平方和</span>](#0)

四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。
比如：
5 = 0^2 + 0^2 + 1^2 + 2^2
7 = 1^2 + 1^2 + 1^2 + 2^2
（^符号表示乘方的意思）
对于一个给定的正整数，可能存在多种平方和的表示法。

要求你对4个数排序：
0 <= a <= b <= c <= d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法

程序输入为一个正整数N (N<5000000)

要求输出4个非负整数，按从小到大排序，中间用空格分开
例如，输入：
5
则程序应该输出：
0 0 1 2

再例如，输入：
12
则程序应该输出：
0 2 2 2

再例如，输入：
773535
则程序应该输出：
1 1 267 838

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

解：
思路：暴力枚举，附加一些条件即可。每一层循环的终点就是剩余的值，比如第一层循环i, 终点为sqrt(n)，需要遍历0 ~ sqrt(n), 第二层循环ｊ，终点为sqrt(n - i * i), 因为已经有一个i值，不需要从0 ~ sqrt(n)，第三层循环就为0 ~ sqrt(n - i * i - j * j)，第四层就不需要循环了，因为，虽然有四个未知数,，但只要知道其中三个，另一个就可以直接求出来，只需要判断第四个数的开方是否为整数就行了

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i <= sqrt(n); i++){
		for(int j = 0; j <= sqrt(n - i * i); j++)
			for(int k = 0; k <= sqrt(n - i * i - j * j); k++){
				double s = 1.0 * sqrt(n - i * i - j * j - k * k);
				if(s == (int)s){
					cout << i << " " << j << " " << k << " " << s << endl;
					return 0;
				}
			}
	}
	return 0;
}
```
---

[<span id = "9">9. 交换瓶子</span>](#9)

有N个瓶子，编号 1 ~ N，放在架子上。
比如有5个瓶子：
2 1 3 5 4
要求每次拿起2个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5
对于这么简单的情况，显然，至少需要交换2次就可以复位。
如果瓶子更多呢？你可以通过编程来解决。

输入格式为两行：
第一行: 一个正整数N（N<10000）, 表示瓶子的数目
第二行：N个正整数，用空格分开，表示瓶子目前的排列情况。
输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。

例如，输入：
5
3 1 2 5 4
程序应该输出：
3

再例如，输入：
5
5 4 3 2 1
程序应该输出：
2

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

解：
思路：求最少交换次数，那么每次交换的结果必须是最终的位置，那么只需要通过选择排序，每次都从后面挑选出最小的数换到前面它所在的位置就行了.

```cpp
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int min, flag = 0;
	int sum = 0;
	for(int i = 0; i < n; i++){
		min = a[i];
		flag = i;
		for(int j = i; j < n; j++)
			if(min > a[j]){
				min = a[j];
				flag = j;
			}
		if(flag != i){
			sum++;
			a[flag] = a[i];
			a[i] = min;
		}
	}
	cout << sum << endl;
	return 0;
}
```

[<span id = "10">10. 最大比例</span>](#0)

X星球的某个大奖赛设了M级奖励。每个级别的奖金是一个正整数。
并且，相邻的两个级别间的比例是个固定值。
也就是说：所有级别的奖金数构成了一个等比数列。比如：
16,24,36,54
其等比值为：3/2
现在，我们随机调查了一些获奖者的奖金数。
请你据此推算可能的最大的等比值。

输入格式：
第一行为数字 N (0< N <100)，表示接下的一行包含N个正整数
第二行N个正整数Xi(Xi<1 000 000 000 000)，用空格分开。每个整数表示调查到的某人的奖金数额

要求输出：
一个形如A/B的分数，要求A、B互质。表示可能的最大比例系数
测试数据保证了输入格式正确，并且最大比例是存在的。

例如，输入：
3
1250 200 32

程序应该输出： 
25/4

再例如，输入：
4
3125 32 32 200
程序应该输出：
5/2

再例如，输入：
3
549755813888 524288 2
程序应该输出：
4/1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Node{
	ll p;
	ll q;
};

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	ll n;
	cin >> n;
	ll a[n];
	Node b[n];
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);  //对a数组排序
	ll size = 0;
	for(ll i = 1; i < n; i++){  //剔除重复的元素
		if(a[size] != a[i]){
			a[++size] = a[i];
		}
	}
	if(a[0] == a[size])    //如果最终只有一个元素,那么直接输出
		cout << 1 << "/" << 1 << endl;
	else{
		for(ll i = 1; i <= size; i++){   //求出比值的分子分母
			ll g = gcd(a[i], a[i - 1]);
			b[i - 1].p = a[i] / g;
			b[i - 1].q = a[i - 1] / g;
		}
		ll pq1, pq2;
		ll A, B;
		double t = 999999999, t1;
		for(ll i = 0; i < size; i++)   //求出最小的比例系数
			for(ll j = i; j < size; j++){
				if(b[i].p * b[j].q > b[i].q * b[j].p){
					pq1 = b[i].p * b[j].q;
					pq2 = b[i].q * b[j].p;
					t1 = pq1 / pq2; 
				}
				else if(b[i].p * b[j].q < b[i].q * b[j].p){
					pq1 = b[i].q * b[j].p;
					pq2 = b[i].p * b[j].q;
					t1 = pq1 / pq2;
				} 
				else{
					pq1 = b[i].p;
					pq2 = b[i].q;
					t1 = pq1 / pq2;
				}
				if(t1 < t){
					t = t1;
					A = pq1;
					B = pq2;
				}
			}
		ll g = gcd(A, B);   //对系数进行化简
		cout << A / g << "/" << B / g << endl;
	}
	return 0;
}
```
