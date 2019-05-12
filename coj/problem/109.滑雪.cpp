/*
Id:[109]	
滑雪 (10分)
题目内容:
 Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不
得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代
表点的高度。下面是一个例子 
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当
然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入描述:
输入的第一行表示区域的行数R和列数C(1<=R,C<=100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出描述:
输出最长区域的长度。
输入样例:
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例:
25
*/

#include <iostream> 
using namespace std;

const int MAXSIZE = 105;
int a[MAXSIZE][MAXSIZE];
int R, C;
int maxLength;
int d[][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

int dfs(int x, int y, int len){
	maxLength = max(maxLength, len);
	for(int i = 0; i < 4; i++){
		int dx = x + d[i][0];
		int dy = y + d[i][1];
		if(dx < 0 || dy < 0 || dx > C || dy > R || a[dx][dy] >= a[x][y]) continue;
		dfs(dx, dy, len + 1);
	}
	return 0;
}

int main(){
	cin >> R >> C;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			cin >> a[i][j];
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			dfs(j, i, 1);
	cout << maxLength << endl;
    return 0;
}
