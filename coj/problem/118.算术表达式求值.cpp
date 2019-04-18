/*
Id:[118]	
算术表达式求值 (15分)
题目内容:
 输入一个由数字、+，-，*，/ 组成的算术表达式，求其值。

输入描述:
一个表达式，其中每个运算数为正整数
输出描述:
计算结果，保留2位小数
输入样例:
1+12*3-4/2
输出样例:
35.00
*/

#include <iostream> 
#include <stack>
#include <iomanip>
using namespace std;

int getPrecedence(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '#':
			return 2;
		default:
			return 4;
	}
}

double calculate(double d1, double d2, char c){
	switch(c){
		case '+':
			return d1 + d2;
		case '-':
			return d1 - d2;
		case '*':
			return d1 * d2;
		case '/':
			return d1 / d2;
	}
}

int getResult(string s){
	stack<char> c;
	stack<double> d;
	c.push('#');
	int i = 0;
	while(s[i] != '\0'){
		double n = 0;
		if(getPrecedence(s[i]) == 4){
			while(getPrecedence(s[i]) == 4 && i < s.length()){
				n = n * 10 + (s[i++] - '0');
			}
			d.push(n);
		}
		else if(getPrecedence(s[i]) <= getPrecedence(c.top())){
			if(d.size() >= 2){
				double d1 = d.top();
				d.pop();
				double d2 = d.top();
				d.pop();
				double d3 = calculate(d2, d1, c.top());
				c.pop();
				d.push(d3);
			}
			c.push(s[i++]);
		}
		else
			c.push(s[i++]);
	}
	while(c.top() != '#'){
		double d1 = d.top();
		d.pop();
		double d2 = d.top();
		d.pop();
		double d3 = calculate(d2, d1, c.top());
		c.pop();
		d.push(d3);
	}
	cout << fixed << setprecision(2) << d.top() << endl;
	return 0;
}

int main(){
	string s;
	cin >> s;
	getResult(s);
    return 0;
}
