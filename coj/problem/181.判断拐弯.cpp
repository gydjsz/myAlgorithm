/*
Id:[181]	
判断拐弯 (15分)
题目内容:
 小张用手机传来他开车先后经过的三个地点A, B, C的坐标,请你编程判断小张在B点是左拐弯，还是右拐弯
输入描述:
A, B, C的坐标
输出描述:
left  或者 right
输入样例:
0,0
1,1
2,1
输出样例:
right
*/

#include <iostream>
#include <sstream>
using namespace std;


int getNum(double &x, double &y){
	string s;
	cin >> s;
	string s1;
	int i = 0;
	while(s[i] != ',')
		s1 += s[i++];
	stringstream ss;
	ss << s1;
	ss >> x;

	ss.clear();

	s1 = "";

	i++;

	while(s[i] != '\0')
		s1 += s[i++];

	ss << s1;
	ss >> y;

	return 0;
}

int main(){
	double x1, y1;
	double x2, y2;
	double x3, y3;
	getNum(x1, y1);
	getNum(x2, y2);
	getNum(x3, y3);
	int flag = 0;  //right
	if(x1 == x2){
		if(y1 > y2){
			if(x3 < x1)
				flag = 0;
			else
				flag = 1;
		}
		else{
			if(x3 < x1)
				flag = 1;
			else
				flag = 0;
		}
	}
	else{
		double k = (y2 - y1) / (x2 - x1);
		double y = k * (x3 - x1) + y1;
		if(x1 < x2){
			if(y3 > y)
				flag = 1; 
			else
				flag = 0;
		}
		else{
			if(y3 > y)
				flag = 0;
			else
				flag = 1;
		}
	}
	if(flag)
		cout << "left" << endl;
	else
		cout << "right" << endl;
	return 0;
}

