/*
Id:[78]	
圣诞广场 (15分)
题目内容:
Angel最近无聊，去了圣诞岛(CX *^_^*)，他喜欢无目的的乱逛，当然，他不会轻易地回头。Angel想

去广场，那么，他什么时候才能到呢？你已经得到了CX的地图，地图上有N(N <= 100)个交叉路口，交

叉路口之间有马路相连接(不超过1000条马路)。因为CX的人遵循奇怪的规则，道路都是单向的，不同

的道路之间有一定的距离，我们假设Angel所在的地点为点1，广场所在点为N。假设Angel走一单位距

离需要一单位时间。问Angel最早和最迟什么时候到达广场？ 
输入描述:
本题有多组数据，第一行N, M，M是边的数量,以后M行，每行3个整数X, Y, Weight，代表一条从X

城市到Y城市，长度为Wweight的边。

输出描述:
每组数据，第一行是最少时间，第二行是最迟时间，要是可怜的Angel可能永远到不了广场，输

出一行Never。

输入样例:
5 5
1 2 1
1 4 10
2 3 1
3 4 1
4 5 1
输出样例:
4
11
*/

#include <iostream> 
#include <cstring>
using namespace std;

const int MAXSIZE = 105;
const int INF = 0x3f3f3f3f;
int a[MAXSIZE][MAXSIZE];
int N;
int minVisit[MAXSIZE];
int minDis[MAXSIZE];
int maxVisit[MAXSIZE];
int maxDis[MAXSIZE];

int dijikstra(){
	memset(minVisit, 0, sizeof(minVisit));
	memset(maxVisit, 0, sizeof(maxVisit));
	memset(minDis, INF, sizeof(maxVisit));
	memset(maxDis, INF, sizeof(maxDis));
	minDis[1] = 0;
	maxDis[1] = 0;
	for(int i = 1; i <= N; i++){
		int m = INF;
		int n = -1;
		int flag = 0;
		int fg = 0;
		for(int j = 1; j <= N; j++){
			if(!minVisit[j] && minDis[j] < m){
				m = minDis[j];
				flag = j;
			}
			if(!maxVisit[j] && maxDis[j] > n && maxDis[j] != INF){
				n = maxDis[j];
				fg = j;
			}
		}
		minVisit[flag] = 1;
		maxVisit[fg] = 1;
		for(int j = 1; j <= N; j++){
			if(!minVisit[j])
				minDis[j] = min(minDis[j], minDis[flag] + a[flag][j]);
			if(!maxVisit[j]){
				if(maxDis[j] == INF || maxDis[fg] + a[fg][i] >= INF)
					maxDis[j] = min(maxDis[j], maxDis[fg] + a[fg][j]);
				else
					maxDis[j] = max(maxDis[j], maxDis[fg] + a[fg][j]);
			}
		}
	}
	if(minDis[N] == INF){
		cout << "Never" << endl;
	}
	else{
		cout << minDis[N] << endl;
		cout << maxDis[N] << endl;
	}
	return 0;
}

int main(){
	int M;
	cin >> N >> M;
	int x, y, weight;
	memset(a, INF, sizeof(a));
	for(int i = 0; i < M; i++){
		cin >> x >> y >> weight;
		a[x][y] = weight;
		a[y][x] = weight;
	}
	dijikstra();

    return 0;
}
