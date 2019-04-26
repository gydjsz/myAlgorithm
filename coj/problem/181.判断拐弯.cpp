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

	double k1 = (y2 - y1) / (x2 - x1);
	int flag = 1;

	if(k1 > 0){
		if(x2 - x1 >= 0 && y2 - y1 >= 0){
			double y = y1 + k1 * (x3 - x1);
			if(y3 < y)
				flag = 0;
		}
		else{
		
		}
	
	}


	return 0;
}

