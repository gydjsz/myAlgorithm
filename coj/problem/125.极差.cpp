/*
Id:[125]	
极差 (15分)
题目内容:
 在黑板上写了N个正整数组成的一个数列，进行如下操作：每次擦去其中的两个数a和b，
然后在数列中加入一个数a*b＋1，如此下去直至黑板上剩下一个数，在所有按这种操作方式
最后得到的数中，最大的为max，最小的为min，则该数列的极差定义为M＝max－min.请你编程，
对于给定的数列，计算极差.
输入描述:
输入包含多个测试集.每个测试集的第一行N表示正整数序列长度（0＜＝N＜＝50000），随后第二行是N个正整数.当N为0时结束.
输出描述:
每个结果一行.
输入样例:
3
3 5 7
输出样例:
4
*/

#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[50005];
	int b[50005];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++){
		a[i] = a[i - 1] * a[i] + 1;
	}
	for(int i = n - 2; i >= 0; i--){
		b[i] = b[i + 1] * b[i] + 1;
	}
	cout << a[n - 1] - b[0] << endl;
    return 0;
}
