/*
Id:[641]	
并查集-臭虫也疯狂 (10分)
题目内容:
霍普教授研究臭虫的性取向。实验前他弄清楚了n个臭虫的性别，并在臭虫的背上标了数字编号（1~n）。现在给一批臭虫的编号
配对，要检查里面有没有同性恋。
输入描述:
第一行是整数c,下面接着有c个测试用例。
每个测试用例的第一行是臭虫的数目n（1~2000），以及配对的数目m（1~10^6）。接下来的行就是m个配对的臭虫编号.
输出描述:
一共c行， 每行打印“testcase i:没有发现同性恋”,或者“testcase i:发现同性恋”
输入样例:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
输出样例:
testcase 1:发现同性恋
testcase 2:没有发现同性恋
*/

#include <stdio.h>
#include <string.h>
const int SIZE = 4005;
int father[SIZE], height[SIZE];
int flag;

int init(int n){
	flag = 0;
	memset(height, 0, sizeof(height));
	for(int i = 1; i <= n; i++)
		father[i] = i;
	return 0;
}

int find(int v){
	if(father[v] == v)
		return v;
	int t = find(father[v]);
	height[v] = (height[v] + height[father[v]]) % 2;
	father[v] = t;
	return t;
}

int Union(int a, int b){
	int fa = find(a);
	int fb = find(b);
	if(fa == fb){
		if(height[a] == height[b])
			flag = 1;
		return 0;
	}
	father[fa] = fb;
	height[fa] = (height[a] - height[b] + 1 + 2) % 2;
	return 0;
}

int solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	int a, b;
	while(m--){
		scanf("%d%d", &a, &b);
		if(flag)
			continue;
		Union(a, b);
	}
	return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		solve();
		if(flag)
			printf("testcase %d:发现同性恋\n", i);
		else
			printf("testcase %d:没有发现同性恋\n", i);
	}
	return 0;
}


