/*
题目描述
平面上有一个大矩形，其左下角坐标（0，0），右上角坐标（R,R)。大矩形内部包含一些小矩形，小矩形都平行于坐标轴且互不重叠。所有矩形的顶点都是整点。要求画一根平行于y轴的直线x=k（k是整数) ，使得这些小矩形落在直线左边的面积必须大于等于落在右边的面积，且两边面积之差最小。并且，要使得大矩形在直线左边的的面积尽可能大。注意：若直线穿过一个小矩形，将会把它切成两个部分，分属左右两侧。

输入
第一行是整数R，表示大矩形的右上角坐标是(R,R) (1 <= R <= 1,000,000)。
接下来的一行是整数N,表示一共有N个小矩形(0 < N <= 10000)。
再接下来有N 行。每行有4个整数，L,T, W 和 H, 表示有一个小矩形的左上角坐标是(L,T),宽度是W，高度是H (0<=L,T <= R, 0 < W,H <= R). 小矩形不会有位于大矩形之外的部分。

输出
输出整数n，表示答案应该是直线 x=n。如果必要的话，x=R也可以是答案。

样例输入
1000
2
1 1 2 1
5 1 2 1

样例输出
5
*/

#include <iostream>
#include <cstring>
using namespace std;

#define ll long long

int main(){
	int R, n;
	cin >> R >> n;
	int a[R + 2];
	memset(a, 0, sizeof(a));
	int x, y, w, h;
	for(int i = 1; i <= n; i++){
		cin >> x >> y >> w >> h;
		for(int j = x; j < w + x; j++)
			a[j] += h;
	}
	ll left, right;
	int r = R, l = 0, mid;
	while(l < r){
		left = 0;
		right = 0;
		mid = (l + r) / 2;
		for(int i = 0; i < mid; ++i)
			left += a[i];
		for(int i = mid; i <= R; i++)
			right += a[i];
		if(r - l == 1){
			if(left >= right){
				if(left + a[l] >= right - a[l] && left + a[l] - (right - a[l]) <= left - right)
					l++;
				else
					break;
			}
			else
				l++;
		}
		else{
			if(left <= right){
				l = mid;
			}
			else
				r = mid;
		}
	}
	while(l + 1 <= R && a[l + 1] == 0)
		l++;
	cout << l << endl;
	return 0;
}
