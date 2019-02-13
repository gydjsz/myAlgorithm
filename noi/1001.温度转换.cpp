/*
题目描述
将输入的华氏温度转换为摄氏温度。由华氏温度F与摄氏温度C的转换公式为：F＝C×9/5＋32。

输入
输入一个实数，表示华氏温度

输出
输出对应的摄氏温度，答案保留4位小数。

样例输入
50

样例输出
10.0000
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double F, C;
	cin >> F;
	C = (F - 32) * 5 / 9;
	cout << fixed << setprecision(4) << C << endl;
	return 0;
}
