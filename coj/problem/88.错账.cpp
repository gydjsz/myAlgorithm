/*
Id:[88]	
错账 (15分)
题目内容:
某财务部门结账时发现总金额不对头。很可能是从明细上漏掉了某1笔或几笔。如果已知明细账目清单，能通过编程找到漏掉的是
哪1笔或几笔吗？
如果有多种可能，则输出所有可能的情况。
输入描述:
第一行是有错的总金额，接下来是一个整数n，表示下面将要输入的明细账目的条数。
再接下来是n行整数，分别表示每笔账目的金额。为了方便，这里假设所有的金额都是整数；每笔金额不超过1000，金额的明细条
数不超过100。
输出描述:
所有可能漏掉的金额组合。每个组合1行。组合之间，按首数据在输入中的次序决定组合的先后，如果首数据是同一个，则看下一
个数据的位置。每组金额内部的几个数据按照值从小到大排列，中间用空格分开。
输入样例:
6
5
3
2
4
3
1
输出样例:
3 4
1 3 3
1 2 4

*/

#include <iostream> 
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int MASIZE = 105;
typedef vector<int> vec;
int n;
int a[MASIZE];
int visit[MASIZE];
vec way;
set<vec> sv;
vector<vec> vc;
int sum;

int dfs(int i, int s){
	if(i > n)
		return 0;
	if(s == sum){
		sort(way.begin(), way.end());
		sv.insert(way);
		vc.push_back(way);
		return 0;
	}

	if(s > sum)
		return 0;
	for(int j = i; j < n; j++){
		if(!visit[j]){
			visit[j] = 1;
			way.push_back(a[j]);
			dfs(j + 1, s + a[j]);
			way.pop_back();
			visit[j] = 0;
		}
	}
	return 0;
}

int main(){
	int error;
	cin >> error >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sum -= error;
	dfs(0, 0);
	int i = 0;
	int k = 0;
	while(!sv.empty()){
		set<vec>::iterator it = sv.find(vc[i]);
		if(it != sv.end()){
			for(int j = 0; j != vc[i].size(); j++){
				cout << vc[i][j];
				if(j != vc[i].size() - 1)
					cout << " ";
			}
			cout << endl;
			sv.erase(it);
		}
		i++;
	}
    return 0;
}
