/*
Id:[119]	
最短路径 (15分)
题目内容:
 有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。计算从城市A到其他任意城市
的最短路径距离。
输入描述:
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行是D到E的直达距离。
输出描述:
A城市到(B,C,D,E)的最短距离。
输入样例:
2 3 4 5  
3 4 2 
4 3   
3

输出样例:
2 3 4 4
*/

#include <iostream> 
#include <cstring>
using namespace std;

const int n = 5;
const int INF = 0x3f3f3f3f;
int a[5][5];
int visit[5];
int dis[5];

int dijikstra(){
	visit[0] = 1;
	memset(dis, INF, sizeof(dis));
	dis[0] = 0;
	for(int i = 0; i < n; i++){
		int m = INF;
		int flag = 0;
		for(int j = 0; j < n; j++){
			if(visit[j] != 1 && dis[j] < m){
				m = dis[j];
				flag = j;
			}
		}
		visit[flag] = 1;
		for(int j = 0; j < n; j++){
			dis[j] = min(dis[j], dis[flag] + a[flag][j]);
		}
	}
	for(int i = 1; i < 5; i++){
		cout << dis[i];
		if(i != 4)
			cout << " ";
	}
	return 0;
}

int main(){
	memset(a, 0, sizeof(a));
	memset(visit, 0, sizeof(visit));
	int m;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			cin >> m;
			a[i][j] = m;
			a[j][i] = m;
		}
	}
	dijikstra();
    return 0;
}
