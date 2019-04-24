/*
Id:[82]	
导弹拦截 (15分)
题目内容:
某国为了防御敌国的导弹袭击，研发出一套导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发拦截
炮弹能够到达任意的高度，但是以后每一发拦截炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的多枚导弹来
袭。
输入描述:
输入的第一行为导弹的个数n (0<n<10000),接下来的一行为导弹依次飞来的高度h（不大于
30000 的正整数）
输出描述:
输出最多拦截的导弹个数。
输入样例:
6
5 3 2 4 1 3

输出样例:
4
*/

#include <iostream> 
#include <algorithm>
using namespace std;

const int MAXSIZE = 1000;
int n;
int a[MAXSIZE];
int b[MAXSIZE];

int solve(){
	int len = 0;
	for(int i = n - 1; i >= 0; i--){
		if(b[len] <= a[i])
			b[++len] = a[i];
		else{
			int k = upper_bound(b, b + len, a[i]) - b;	
			b[k] = a[i];
		}
	}
	cout << len << endl;
	return 0;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	solve();
    return 0;
}
