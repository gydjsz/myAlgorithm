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
using namespace std;

int map[50][50];
int visit[100];
int path[1000][100];
int p;
int n;
int k;

int dfs(int i){
	if(i == k){
		int j = 0;
		for(int i = 0; i < n; i++){
			if(visit[i])
				path[p][j++] = i;
		}
		p++;
		return 0;
	}
	for(int j = 1; j <= n; i++){
		if(!visit[j] && map[i][j] == 1){
			visit[j] = 1;
			dfs(j);
			visit[j] = 0;
		}
	}
	return 0;
}

int main(){
	cin >> k;
	int x, y;
	while(cin >> x >> y && x != 0 && y != 0){
		map[x][y] = 1;
		map[y][x] = 1;
		n = max(n, x);
		n = max(n, y);
	}
	dfs(1);
	for(int i = 0; i < p; i++)
		for(int j = 0; j < n; j++)
			if(path[i][j] != 0)
				cout << path[i][j] << " ";
	return 0;
}
