/*
Id:[85]	
矩形嵌套 (15分)
题目内容:
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相
当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使
得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入描述:
第一行是一个正正数N(0<N<10)，表示测试数据组数，每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个
数(n<=1000)随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽
输出描述:
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行
输入样例:
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
输出样例:
5
*/

#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

struct Rectangle{
	int width;
	int height;
}rectangle[1005];

bool cmp(Rectangle a, Rectangle b){
	if(a.width == b.width)
		return a.height < b.height;
	return a.width < b.width;
}

bool judge(int i, int j){
	if(rectangle[i].width > rectangle[j].width && rectangle[i].height > rectangle[j].height)
		return true;
	return false;
}

int solve(){
	int n;
	cin >> n;
	int w, h;
	memset(rectangle, 0, sizeof(rectangle));
	for(int i = 0; i < n; i++){
		cin >> w >> h;
		rectangle[i].width = w > h ? h : w;
		rectangle[i].height = w > h ? w : h;
	}
	sort(rectangle, rectangle + n, cmp);
	int dp[1005];
	memset(dp, 0, sizeof(dp));
	int res = 0;
	for(int i = 0; i < n; i++){
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
	int T;
	cin >> T;
	while(T--){
		solve();
	}
    return 0;
}

