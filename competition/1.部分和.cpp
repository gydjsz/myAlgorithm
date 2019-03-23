/*
 *给定整数a1, a2, a3,...,an,判断是否可以从中选出若干数，使它们的和恰好为k.
 */

#include <iostream>
using namespace std;

int n, k;
int a[100];

int dfs(int i, int sum){
	if(i == n)
		return sum == k;
	if(dfs(i + 1, sum))
		return true;
	if(dfs(i + 1, sum + a[i]))
		return true;
	return false;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(dfs(0, 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
