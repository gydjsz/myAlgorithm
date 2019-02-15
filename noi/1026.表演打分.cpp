/*
题目描述
在一次运动会方队表演中，学校安排了十名老师进行打分。对于给定的每个参赛班级的不同打分（百分制整数），按照去掉一个最高分、去掉一个最低分，再算出平均分的方法，得到该班级的最后得分。

输入
一行10个用空格隔开的正整数，表示十名老师的打分。

输出
输出该班级的最终得分，答案保留三位小数。

样例输入
90 89 92 90 93 95 88 90 89 88

样例输出
90.125
*/

#include <iostream>
#include <deque>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
	deque<int> deq;
	int n;
	for(int i = 0; i < 10; i++){
		cin >> n; 
		deq.push_back(n);
	}
	sort(deq.begin(), deq.end());
	deq.pop_back();
	deq.pop_front();
	double sum = 0;
	for(deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		sum += *it;
	cout << fixed << setprecision(3) << sum / deq.size() << endl;
	return 0;
}
