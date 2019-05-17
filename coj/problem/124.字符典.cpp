/*
Id:[124]	
字符典 (15分)
题目内容:
 在数据压缩和数据加密过程中常需要对特殊的字符串进行编码. 给定的字母表A由26

个小写英文字母组成A?={a,b,...z}. 该字母表产生的升序字符串指的是字符串中字母按

照从左到右出现的次序与字母表中出现的次序相同，且每个字符最多出现1次. 例如，

a,b,ab,xyz,ax等都是升序字符串. 现在对字母表A产生的所有长度不超过6的升序字符串

按照字典序排列如下.
1	2	3	…	26	27	28	…
a	b	c	…	z	ab	ac	…
对于给定长度不超过6的升序字符串，编程计算出它在上述字典中的编码.
输入描述:
输入数据的第1行是一个正整数k,表示接下来共有k行.在接下来的k行中，每行给出一个

字符串.
输出描述:
输出结果，每行对应于一个字符串的编码.
输入样例:
3
a
b
abc
输出样例:
1
2
352
*/

//https://wenku.baidu.com/view/db6dd59ba1c7aa00b52acb62.html

#include <iostream> 
#include <cstring>
using namespace std;

int num[6];

double factorial(double n){
	if(n == 1 || n == 0)
		return 1;
	return n * factorial(n - 1);
}

double C(double m, double n){
	return factorial(n) / (factorial(n - m) * factorial(m));
}

int find(){
	int a[26];
	int t = 5;
	string s[] = {"z", "yz", "xyz", "wxyz", "vwxyz"};
	for(int i = 0; i < t; i++){
		memset(a, 0, sizeof(a));
		for(int j = 0; j < s[i].length(); j++){
			a[s[i][j] - 97] = 1;
		}
		double sum = 0;
		int k = 1;
		for(int j = 0; j < 26; j++){
			if(a[j] != 1){
				sum += C(s[i].length() - k, 26 - j - 1);
			}
			else
				k++;
		}
		num[i] = sum + 1;
	}
	return 0;
}

int solve(){
	string s;
	cin >> s;
	int len = s.length();
	int sum = 0;
	for(int i = 0; i < s.length() - 1; i++){
		sum += num[i];
	}
	int a[26];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < len; i++){
		a[s[i] - 97] = 1;
	}
	double p = 0;
	int k = 1;
	for(int j = 0; j < 26 && k <= len; j++){
		if(a[j] != 1){
			p += C(len - k, 26 - j - 1);
		}
		else
			k++;
	}
	sum += p + 1;
	cout << sum << endl;
	return 0;
}


int main(){
	int n;
	cin >> n;
	find();
	while(n--){
		solve();
	}
    return 0;
}
