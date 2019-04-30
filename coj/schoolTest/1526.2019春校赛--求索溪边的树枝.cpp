/*
Id:[1526]	
2019春校赛--求索溪边的树枝 (10分)
题目内容:
求索溪边散落一些树枝。 给你n根树枝，这些树枝能拼接出m根长度一样的大树枝，求能拼接的最小长度。

输入描述:
每组输入包含2行。
第一行为树枝数量n(n <= 45)。
第二行包含由空格分隔的每一根树枝的长度。
n输入为0时表示结束。
输出描述:
每组输出最小的拼接长度。
输入样例:
4
1 2 3 4
9
15 4 3 1 2 8 11 8 8
0

输出样例:
5
20
*/

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXSIZE = 100;
int a[MAXSIZE];
int visit[MAXSIZE];
int n;
int len, amount, aim;

bool dfs(int am, int i, int le){
	if(len < le) return false;
	if(amount == am) return true;
	if(len == le) return dfs(am + 1, 0, 0);
	for(int j = i; j < n; j++){
		if(!visit[j] && le + a[j] <= len){
			visit[j] = 1;
			if(dfs(am, i + 1, le + a[j])) return true;
			visit[j] = 0;
			if(i == 0) return false;
			while(i + 1 < n && a[i] == a[i + 1]) i++;
		}
	}
	return false;
}

int solve(){
	memset(a, 0, sizeof(a));
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n, greater<int>());
	for(int i = n; i >= 1; i--){
		if(sum % i == 0){
			memset(visit, 0, sizeof(visit));
			amount = i;
			len = sum / i;
			if(dfs(0, 0, 0)){
				aim = len;
				break;
			}
		}
	}
	cout << aim << endl;
	return 0;
}

int main(){
	while(cin >> n && n != 0){
		solve();
	}
    return 0;
}
