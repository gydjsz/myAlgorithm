/*
Id:[1524]	
2019春校赛--求索溪边的徘徊 (10分)
题目内容:
求索溪边的各种道路很复杂，构成一个无向图。输入一个n（n <= 20）个结点的无向图以及某个结点k，按照字典序从小到大顺序输出从结点1到结点k的所有路径，要求结点不能重复经过.所谓字典序，就是两个路径如（1，4，2）和（1，3，5），(1,3,5)应先输出。
提示:要事先判断结点1是否可以到达结点k，否则会超时
输入描述:
输入包含多个样例.所有的数不超过20.
每个样例的第一行是一个整数，代表k.
下面的每一行是两个不同的整数，表示这两个位置是相连的.
每个样例以一对0结束.
输出描述:
对于每一个样例，输出要标明样例(如'CASE 1:','CASE 2')。
接下来以字典序的顺序每一行输出一种路径.每个路径只能经过一个点一次.
最后一行表示总共有多少种路径.
输入样例:
6
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
0 0
4
2 3
3 4
5 1
1 6
7 8
8 9
2 5
5 7
3 1
1 8
4 6
6 9
0 0

输出样例:
CASE 1:
1 2 3 4 6
1 2 3 5 6
1 2 4 3 5 6
1 2 4 6
1 3 2 4 6
1 3 4 6
1 3 5 6
There are 7 routes from node 1 to node 6.
CASE 2:
1 3 2 5 7 8 9 6 4
1 3 4
1 5 2 3 4
1 5 7 8 9 6 4
1 6 4
1 6 9 8 7 5 2 3 4
1 8 7 5 2 3 4
1 8 9 6 4
There are 8 routes from node 1 to node 4.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vec;
const int MAXSIZE = 100;

int map[MAXSIZE][MAXSIZE];
int visit[MAXSIZE];
vec path;
int k;
int node;
int amount;
int count;

int dfs(int i){
	if(i == k)
		return true;
	for(int j = 0; j <= node; j++){
		if(!visit[j] && map[i][j] == 1){
			visit[j] = 1;
			if(dfs(j)) return true;
		}
	}
	return false;
}

int search(int i){
	if(i == k){
		amount++;
		for(int j = 0; j < path.size() - 1; j++)
			cout << path[j] << " ";
		cout << path[path.size() - 1] << endl;
		return 0;
	}
	for(int j = 0; j <= node; j++){
		if(!visit[j] && map[i][j] == 1){
			visit[j] = 1;
			path.push_back(j);
			search(j);
			visit[j] = 0;
			path.pop_back();
		}
	}
	return 0;
}

int solve(){
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	path.clear();
	amount = 0;
	count++;
	int x, y;
	node = k;
	while(cin >> x >> y, x || y){
		map[x][y] = 1;
		map[y][x] = 1;
		node = max(node, max(x, y));
	}
	cout << "CASE " << count << ":" << endl;
	visit[1] = 1;
	if(dfs(1)){
		memset(visit, 0, sizeof(visit));
		visit[1] = 1;
		path.push_back(1);
		search(1);
	}
	cout << "There are " << amount << " routes from node 1 to node " << k << "." << endl;
	return 0;
}

int main(){
	while(cin >> k){
		solve();
	}
	return 0;
}

/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 21;

int n, k;
vector<int> neigh[N];
int v[N];
int path_count;
vector<int> path;

bool dfs(int u)
{
    if (u == k) return true;

    for (int i = 0; i < neigh[u].size(); i++) {
        if (!v[neigh[u][i]]) {
            int x = neigh[u][i];
            v[x] = 1;
            if (dfs(x)) return true;
        }
    }
    return false;
}

void find_path()
{
    path_count++;
    for (int i = 0; i < path.size(); i++)
        printf("%d%c", path[i], i == path.size()-1 ? '\n' : ' ');
}

void search(int u)
{
    if (u == k) { find_path(); return; }

    for (int i = 0; i < neigh[u].size(); i++) {
        if (!v[neigh[u][i]]) {
            int x = neigh[u][i];
            v[x] = 1;
            path.push_back(x);
            search(x);
            path.resize(path.size()-1);

            v[x] = 0;
        }
    }
}

int main()
{
    int kase = 0;
    while (scanf("%d", &k) != EOF) {
        int a, b;
        int G[N][N];
        memset(G, 0, sizeof(G));
        n = k;
        while (scanf("%d%d", &a, &b), a || b) {
            n = max(n, max(a, b));
            G[a][b] = G[b][a] = 1;
        }
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            for (int j = 1; j <= n; j++) {
                if (G[i][j]) neigh[i].push_back(j);
            }
        }

        printf("CASE %d:\n", ++kase);
        memset(v, 0, sizeof(v));
        v[1] = 1;
        path_count = 0;
        if (dfs(1)) {
            path.clear();
            memset(v, 0, sizeof(v));
            v[1] = 1;
            path.push_back(1);
            search(1);
        }
//	cout << "There are " << p << " routes from node 1 to node " << k << "." << endl;
		printf("There are %d routes from node 1 to node %d.\n", path_count, k);

    }       

    return 0;
}
*/

