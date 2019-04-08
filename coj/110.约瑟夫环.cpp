/*
Id:[110]	
约瑟夫环 (5分)
题目内容:
 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的

人退出圈子，问最后留下的是原来第几号的那位?
输入描述:
正整数n
输出描述:
直接输出结果
输入样例:
10
输出样例:
4
*/

/*
 思路:设最后一个出圈的人为fn, 前一个出圈的人为fn-1, 则fn = (fn-1 + m % n) % n, 这里m < n, 
fn = (fn-1 + m) % n, 利用该递推方程则可以求出最后一个出圈的人, 即留下的那位
 */
#include <iostream> 
using namespace std;

int main() {
	int n;
	cin >> n;
	int s = 0, m = 3;
	for(int i = 2; i <= n; i++){
		s = (s + m) % i;
	}
	cout << s + 1 << endl;
    return 0;
}
