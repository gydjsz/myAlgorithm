/*
Id:[69]	
线数目 (15分)
题目内容:
现有画有黑线（直线或曲线）的白底图片一张，计算出有多少条黑线、并依次输出每条黑线所占的点数。图片我们用0、1图表示，
1代表黑点 0 代表白点，某点周围8个方向都算连通，如下图所示，共有3条黑线，长度分别是5、3、5：
1 0 0 0 0 0 0
0 1 1 1 1 0 0
0 0 0 0 0 0 0
1 1 0 0 0 1 1
1 0 0 1 1 1 0
输入描述:
图的宽w、高h，换行输入图的像素点.(测试数据结果唯一确定)
输出描述:
黑线条数、换行输出每条线长度.（条数及每个长度各占一行）.
输入样例:
7 5 
1 0 0 0 0 0 0
0 1 1 1 1 0 0
0 0 0 0 0 0 0
1 1 0 0 0 1 1
1 0 0 1 1 1 0
输出样例:
3
5
3
5
*/

#include <iostream> 
#include <cstring>
using namespace std;

const int MAXSIZE = 100;
int map[MAXSIZE][MAXSIZE];
int w, h;
int sum;
int d[][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1,
	-1, -1,
	1, -1,
	-1, 1,
	1, 1
};

int dfs(int x, int y){
	map[x][y] = 0;
	for(int i = 0; i < 8; i++){
		int fx = x + d[i][0];
		int fy = y + d[i][1];
		if(1 <= fx && fx <= h && 1 <= fy && fy <= w && map[fx][fy] == 1){
			sum++;
			dfs(fx, fy);
		}
	}
	return 0;
}

int main(){
	cin >> w >> h;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> map[i][j];
	int a[MAXSIZE], k = 0;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			if(map[i][j]){
				sum = 1;
				dfs(i, j);
				a[k++] = sum;
			}
	cout << k << endl;
	for(int i = 0; i < k; i++)
		cout << a[i] << endl;
    return 0;
}
