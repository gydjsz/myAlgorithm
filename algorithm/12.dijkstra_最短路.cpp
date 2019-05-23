//O(n^2)

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXSIZE = 1000;
const int INF = 0x3f3f3f3f;
int map[MAXSIZE][MAXSIZE];  //邻接矩阵
int visit[MAXSIZE];  //标记点是否访问过
int dis[MAXSIZE];   //存储某点到各个点的最短路径
int N;    //点的个数

void dijkstra(){
	memset(dis, INF, sizeof(dis));    //初始化点的距离为无穷大
	memset(visit, 0, sizeof(visit));  //每个点都没有访问过
	dis[1] = 0;  //初始化自己到自己的距离为0
	for(int i = 1; i <= N; i++){
		int m = INF;
		int flag = -1;
		for(int j = 1; j <= N; j++){
			if(!visit[j] && dis[j] < m){  //寻找距离更短点
				m = dis[j];
				flag = j;
			}
		}
		if(flag == -1) break;  //找不到更短距离的点
		visit[flag] = 1;
		for(int j = 1; j <= N; j++){
			if(!visit[j])
				dis[j] = min(dis[j], dis[flag] + map[flag][j]);  //更新距离
		}
	}
	cout << dis[N] << endl;
}

int main(){
	int m;   //边的个数
	cin >> N >> m;
	int x, y;
	memset(map, INF, sizeof(map));  //没有路径,则距离为无穷大
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	dijkstra();
    return 0;
}
