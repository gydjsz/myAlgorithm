/*
题目描述
输入一个正整数n，输出高为n的由*组成的等腰三角形。

输入
输入一个正整数。

输出
输出高为n的由*组成的等腰三角形。

样例输入
3

样例输出
  *
 ***
*****
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n - i; ++j)
			cout << " ";
		for(int j = 1; j <= 2 * i - 1; ++j)
			cout << "*";
		cout << endl;
	}
	return 0;
}
