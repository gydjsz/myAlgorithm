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

/*
 *这题用dfs搜索图的所有路径，由于是从1~n逐个搜索，所以搜索出的结果已经是字典序，可以直接输出，
 这题坑点在于，图的点可以为0, 比如1 0 6(被卡了很久很久).可以先判断能否从1到k, 用简单的dfs, 从1开始遍历能到达k直接返回
 *
 */


//邻接表
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vec;
const int MAXSIZE = 100;
int map[MAXSIZE][MAXSIZE];
int visit[MAXSIZE];
vec node[MAXSIZE];
vec path;
int k;
int n;
int amount;
int count;

int dfs(int i){
	if(i == k) return true;
	for(int j = 0; j < node[i].size(); j++){
		if(!visit[node[i][j]]){
			int x = node[i][j];
			visit[x] = 1;
			if(dfs(x)) return true;
		}
	}
	return 0;
}

int search(int i){
	if(i == k){
		amount++;
		for(int j = 0; j < path.size() - 1; j++)
			cout << path[j] << " ";
		cout << path[path.size() - 1] << endl;
		return 0;
	}
	for(int j = 0; j < node[i].size(); j++){
		if(!visit[node[i][j]]){
			int x = node[i][j];
			visit[x] = 1;
			path.push_back(x);
			search(x);
			visit[x] = 0;
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
	n = k;
	int x, y;
	while(cin >> x >> y, x || y){
		map[x][y] = 1;
		map[y][x] = 1;
		n = max(n, max(x, y));
	}
	cout << "CASE " << count << ":" << endl;
	for(int i = 0; i <= n; i++){
		node[i].clear();
		for(int j = 0; j <= n; j++){
			if(map[i][j])
				node[i].push_back(j);
		}
	}
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


//邻接矩阵
/*
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vec;
const int MAXSIZE = 100;

int map[MAXSIZE][MAXSIZE];   //存储图
int visit[MAXSIZE];    //记录是否访问过
vec path;   //记录路径
int k;      //记录终点
int node;   //记录最大的结点
int amount;  //记录路径总数
int count;   //记录样例


//简单的dfs，搜索从1到k是否存在路径
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
		//找到一条路径后直接输出
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
		node = max(node, max(x, y));  //最大结点即为图的大小
	}
	cout << "CASE " << count << ":" << endl;
	visit[1] = 1;
	if(dfs(1)){
		memset(visit, 0, sizeof(visit));  //dfs后改变了visit, 需要初始化
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
*/

