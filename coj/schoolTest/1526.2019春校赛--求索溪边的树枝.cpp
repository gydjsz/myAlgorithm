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
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vec;
const int MAXSIZE = 100;
int n;
int len;
int amount;
vec tree;
vec visit(MAXSIZE, 0);
int flag;
int differ;

int init(){
	tree.assign(MAXSIZE, 0);
	visit.assign(MAXSIZE, 0);
	len = 0;
	amount = 0;
	flag = 0;
	differ = 0;
	return 0;
}

int dfs(int i, int am, int L){
	if(flag) return true;  //如果已经找到m根树枝，直接返回true
	if(amount == am){   //如果满足找到的数量和m相等，标记flag,并返回true
		flag = 1;
		return true;
	}
	if(L == len) return dfs(0, am + 1, 0);   //可以拼出L长度的树枝，继续找
	if(len - L > differ) return false;    //如果剩余的树枝总长比还需要的树枝长度少，返回false
	if(L + tree[n - 1] > len) return false;   //如果当前长度加上最小的树枝长比想要的长度大，返回false
	for(int j = i; j < n; j++){
		if(!visit[j] && tree[j] + L <= len){
			visit[j] = 1;
			differ -= tree[j];  //记录还剩的长度
			if(dfs(j + 1, am, tree[j] + L)) return true;  
			visit[j] = 0;
			differ += tree[j];
			if(i == 0) return false;   //如果第一次拼不出来，以后的树枝都拼不出来
			while(j + 1 < n && tree[j] == tree[j + 1]) j++;  //如果后面的树枝长度和当前一样长，那么跳过
		}
	}
	return 0;
}

int solve(){
	int x;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		tree.push_back(x);
		sum += x;
	}
	differ = sum;
	sort(tree.begin(), tree.end(), greater<int>());
	for(int i = n; i >= 1; i--){
		if(sum % i == 0){
			len = sum / i;
			amount = i;
			if(dfs(0, 0, 0)){
				cout << len << endl;
				return 0;
			}
		}
	}
	return 0;
}

int main(){
	while(cin >> n && n != 0){
		init();
		solve();	
	}
    return 0;
}
