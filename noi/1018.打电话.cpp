/*
题目描述
某市的IC卡电话计费标准如下：首次为0.5元/3分钟(不足3分钟按3分钟计费)，之后是0.2元/1分钟，不足一分钟按一分钟来算，如一个人打了6分30秒，那计费是按照7分钟来算，花费为1.3元。已知某人打一次电话花费为x元，问这个人有可能打了多长时间的电话？（精确到分钟）

输入
输入一个实数x，表示打电话的花费。

输出
输出打电话的最长时长(精确到分钟)。

样例输入
0.5

样例输出
3
*/

#include <iostream>
using namespace std;

int main(){
	double x;
	cin >> x;
	if(x == 0.5)
		cout << "3" << endl;
	else{
		double cost = (x - 0.5) / 0.2;
		if(cost > int(cost))
			cout << int(cost) + 4 << endl;
		else
			cout << int(cost) + 3 << endl;
	}
	return 0;
}

