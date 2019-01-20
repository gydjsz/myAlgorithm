/*
题目描述
输入某学生成绩score，根据成绩好坏输出相应评语。如果成绩在大于等于90，输出“Excellent”；如果成绩在大于等于80分且小于90分，输出“Good”；如果成绩大于等于60分且小于80分，输出“Pass”；成绩小于60分，输出“Fail”。

输入
输入一个整数score，表示学生的成绩

输出
输出对应的评语。

样例输入
65

样例输出
Pass
*/

#include <iostream>
using namespace std;

int main(){
	int score;
	cin >> score;
	if(score >= 90)
		cout << "Excellent" << endl;
	else if(score >= 80)
		cout << "Good" << endl;
	else if(score >= 60)
		cout << "Pass" << endl;
	else
		cout << "Fail" << endl;
	return 0;
}
