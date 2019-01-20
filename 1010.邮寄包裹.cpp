/* 题目描述
某邮局对邮寄包裹有如下规定：若包裹的重量超过30千克,不予邮寄，对可以邮寄的包裹每件收手续费0.2元，再加上根据下表按重量wei计算的结果：
   
重量(千克)      收费标准(元/公斤)          
wei<=10              0.80        
10<wei<=20        0.75         
20<wei<=30        0.70 
请你编写一个程序，输入包裹重量，输出所需费用或”Fail”表示无法邮寄。

输入
输入一个正整数，表示邮寄包裹的重量。

输出
输出对应的费用(答案保留2位小数)或“Fail”表示无法邮寄。

样例输入
7

样例输出
5.80

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double wei;
	cin >> wei;
	double sum;
	if(wei <= 10)
		sum = 0.8 * wei + 0.2;
	else if(wei <= 20)
		sum = 0.75 * wei + 0.2;
	else if(wei <= 30)
		sum = 0.7 * wei + 0.2;
	else
		sum = -1;
	if(sum == -1)
		cout << "Fail" << endl;
	else
		cout << fixed << setprecision(2) << sum << endl;
	return 0;
}

