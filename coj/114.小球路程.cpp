/*
Id:[114]	
小球路程 (5分)
题目内容:
 小球从n米高处自由下落，每次弹起的高度是下落高度的70%，当小球弹起的高度不足原高度的千分之一时， 小球很快会停止跳动，请计算小球在整个弹跳过程中所经历的总路程（忽略弹起高度不足原高度千分之一的部分）。

（注：本题计算过程请用双精度实数）

输入描述:
高度数据，一个实数
输出描述:
总路程，保留4位小数
输入样例:
100
输出样例:
566.1347
*/

#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	double n; 
	cin >> n;
	double x = n, m = n;
	while(n * 0.7 >= m / 1000){
		n *= 0.7;
		x += n * 2;
	}
	cout << fixed << setprecision(4) << x << endl;
	return 0;
}
