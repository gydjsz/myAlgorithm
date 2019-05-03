/*
Id:[94]	
子集和 (10分)
题目内容:
 对于由从1到N(1<=N<=39)这N个连续的整数组成的集合来说，我们有时可以将集合分成两个部分和相同的子集合。
例如，N=3时，可以将集合{1,2,3}分为{1,2}和{3}。此时称有一种方式（即与顺序无关）。
N=7时，共有四种方式可以将集合{1,2,3,...,7}分为两个部分和相同的子集合：
{1,6,7}和{2,3,4,5}
{2,5,7}和{1,3,4,6}
{3,4,7}和{1,2,5,6}
{1,2,4,7}和{3,5,6}

输入描述:
程序从标准输入读入数据，只有一组测试用例。如上所述的N。
输出描述:
方式数。若不存在这样的拆分，则输出0。
输入样例:
7
输出样例:
4
*/

//http://www.cnblogs.com/kangjianwei101/p/5332451.html

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int sum = n * (n + 1) / 4;
	ll f[40][500];
	if((n * (n + 1) / 2) % 2){
		cout << 0 << endl;
		return 0;
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(i <= j)
				f[i][j] = f[i - 1][j] + f[i - 1][j - i];
			else
				f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][sum] / 2 << endl;
	/*
	if(sum % 2){
		cout << 0 << endl;
		return 0;
	}
	ll f[500];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = sum; j >= i; j--)
			f[j] += f[j - i];
	cout << f[sum] / 2 << endl;
	*/
    return 0;
}
