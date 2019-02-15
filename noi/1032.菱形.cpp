/*
题目描述
输入一个正整数n，输出用1至(2n-1)的数字组成的菱形。

输入
输入正整数n。

输出
输出对应的菱形(见样例)。

样例输入
3

样例输出
  1 
 123
12345
 123
  1
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n; 
	for(int i = 1; i <= 2 * n - 1; ++i){
		for(int j = 1; j <= abs(n - i); ++j)
			cout << " ";
		for(int j = 1; j <= 2 * (n - abs(n - i)) - 1; ++j)
			cout << j;
		cout << endl;
	}
	return 0;
}


