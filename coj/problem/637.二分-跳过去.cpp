/*
Id:[637]	
二分-跳过去 (10分)
题目内容:
  “跳过去”比赛将在一条河中进行，河中分布着一些大石头。组委会选择了两块石头作为比赛起点和终点。在起点和终点之间，
有 N 块石头（不含起点和终 点的岩石）。比赛时选手们将从起点出发，每一步跳向下一块石头，直到终点。
  为了提高比赛难度，组委会计划移走一些石头，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多
从起点和终点之间移走 M 块石头（不能移走起点和终点的石头）。
输入描述:
输入第一行包含3个整数 L,N，M，表示起点和终点的距离，之间的岩石数，以及组委会至多移走的岩石数。
接下来 N 行，每行一个整数，第 i 行的整数0<d​[i]<L, 表示中间依次的每块石头与起点的距离，保证
d[i]<d[i+1]

其中L<=10^9, M<N-2<=10^5
输出描述:
最短跳跃距离的最大值
输入样例:
25 5 2
2
11
14
17
21
输出样例:
4
*/

#include <iostream> 
using namespace std;

int L, N, M;
int a[100000];

bool judge(int mid){
	int s = 0;
	int i = 0;
	for(int j = 1; j < N; j++){
		if(a[j] - a[i] >= mid){
			i = j;
			s++;
		}
	}
	return N - s >= M;
}

int getDistance(){
	cin >> L >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	int left = 0, right = L;
	while(left < right){
		int mid = right - (right - left) / 2;
		if(judge(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left << endl;
	return 0;
}

int main(){
	getDistance();
    return 0;
}
