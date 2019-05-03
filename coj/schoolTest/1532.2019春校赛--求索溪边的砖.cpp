/*
Id:[1532]	
2019春校赛--求索溪边的砖 (10分)
题目内容:
 众所周知，求索溪边堆了很多砖。 
这些砖的长宽高规格不太一样。 一共有n{n<=30}种砖，第i种砖的长宽高分别为{Xi,Yi,Zi}, {xi,yi,zi < 10000}，每种砖有无限多。学校开展桃花节需要将这些砖搬走, 高级搬砖工小胖接了活。

我们搬砖时都是将砖叠成一摞再搬。小胖的力气非常大，当然希望尽可能的摞到最高, 但是只有上面砖的底面两条边都小于下面砖底面相对的两条边时，才能叠稳，注意砖可以旋转。(如: 长宽高为[3,4,5]的砖能叠在[2，5，5]，[5,4,3]上,不能叠在[2,4,3]上)。 帮小胖算算他第一次最多能搬走多少砖。
输入描述:
多组输入 ， 每组一个整数n{n<=30}表示砖的种类，接下来n行每行3个整数x,y,z {x,y,z < 10000} 
n=0表示输入结束。
输出描述:
n 行，每行一个整数表示该组样例中第一次最多能搬砖的数量
输入样例:
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
输出样例:
2
3
7
6
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int amount;

struct Rectangle{
	int width;
	int height;
}rectangle[100];

int getRectangle(int L, int W, int H){
	rectangle[amount].width = L > W ? W : L;
	rectangle[amount++].height = L > W ? L : W;

	rectangle[amount].width = L > H ? H : L;
	rectangle[amount++].height = L > H ? L : H;

	rectangle[amount].width = W > H ? H : W;
	rectangle[amount++].height = W > H ? W : H;
	return 0;
}

bool judge(int i, int j){
	if(rectangle[i].width > rectangle[j].width && rectangle[i].height > rectangle[j].height){
		return true;
	}
	return false;
}

bool cmp(Rectangle a, Rectangle b){
	if(a.width == b.width)
		return a.height < b.height;
	return a.width < b.width;
}

int solve(){
	amount = 0;
	memset(rectangle, 0, sizeof(rectangle));
	int dp[100];
	memset(dp, 0, sizeof(dp));
	int L, W, H;
	int j = 0;
	for(int i = 0; i < n; i++){
		cin >> L >> W >> H;
		getRectangle(L, W, H);
	}
	int res = 0;
	sort(rectangle, rectangle + amount, cmp);
	for(int i = 0; i < amount; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(judge(i, j)){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
}


int main(){
	while(cin >> n && n != 0){
		solve();
	}
	return 0;
}

