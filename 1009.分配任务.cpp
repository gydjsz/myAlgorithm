/*
题目描述
在社会实践活动中有三项任务分别是：种树、采茶、送水。依据小组人数及男生、女生人数决定小组的接受任务，人数小于10人的小组负责送水（输出water），人数大于等于10人且男生多于女生的小组负责种树（输出tree），人数大于等于10人且男生不多于女生的小组负责采茶（输出tea）。输入小组男生人数、女生人数，输出小组接受的任务。

输入
一行两个空格隔开的数，表示小组中男生和女生的人数。

输出
输出对应的任务。

样例输入
5 3

样例输出
water
*/

#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if(sum < 10)
		cout << "water" << endl;
	else if(sum >= 10 && a > b)
		cout << "tree" << endl;
	else
		cout << "tea" << endl;
	return 0;
}
