/*
题目内容：
 你的朋友提议玩一个游戏：将写有数字的n个纸片放入口袋中．你可以从口袋中抽取4次纸片，每次记下纸片上的数字后都将其放回口袋中如果这4个数字的和是m，就是你赢，否则就是你的朋友赢。你挑战了好几回，结果一次也没赢过，于是怒而撕破口袋，取出所有纸片，检查自己是否真的有赢的可能性。请你编写一个程序，判断当纸片上所写的数字是k1，k2，…，kn时，是否存在抽取4次和为m的方案。如果存在，输出YES；否则，输出NO.
输入描述
第一行输入两个整数n,m,
随后n行是n个整数 k1,k2,..kn

已知1≤n ≤ 1000;   1 ≤ m ≤ 10^8;   1 ≤ Ki ≤ 10^8

输出描述
根据题意输出YES或者NO

输入样例
3 10
1
3
5             

输出样例
YES
*/

/*
 *有四个数a, b, c, d, 先用sum数组存下所有c + d的值, 然后二分查找sum数组中是否有m - a - b的值, 如果有则证明存在a + b + c + d = m, 时间复杂度O(n^2logn)
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

int sum[1000000];   //存储c + d的值，共有n * n个数
int array[1000];

bool b_search(int array[], int n, int x){
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = right - (right - left) / 2;
		if(array[mid] == x) return true;
		else if(array[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}

bool solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> array[i];
	int k = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)   //暴力求解array数组中任意两个数的和
			sum[k++] = array[i] + array[j];
	sort(sum, sum + k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if(b_search(sum, k, m - array[i] - array[j])){  //二分查找sum数组中是否存在m - a[i] - a[j]
				return true;	
			}
		}
	return false;
}

int main(){
	if(solve())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
