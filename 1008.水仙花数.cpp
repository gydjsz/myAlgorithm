/*
题目描述
输入一个三位数n，判断是否为水仙花数，如果是则输出“YES”，不是则输出“NO”。水仙花数：是指一个3位数，它的每个位上的数字的3次幂之和等于它本身。（例如：1^3 + 5^3+ 3^3 = 153）

输入
输入一个三位数n。

输出
按照题目描述输出对应结果。

样例输入
153

样例输出
YES
*/

/*
两种思路：
1. 将n看作字符串, 那么百位、十位、个位分别为n[0]、n[1]、n[2], 该三位数就是
n[0] * 100 + n[1] * 10 + n[2]

2. 按一般的想法：
bai = n / 100;
shi = (n - bai * 100) / 10;
ge = n - bai * 100 - shi * 10
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	string n;
	cin >> n;
	int g = n[2] - '0';
	int s = n[1] - '0';
	int b = n[0] - '0';
	if(pow(g, 3) + pow(s, 3) + pow(b, 3) == b * 100 + s * 10 + g)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
