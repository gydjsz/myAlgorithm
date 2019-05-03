/*
Id:[76]	
排列组合 (15分)
题目内容:
对字符串（数字，字母，符号）进行全排列，并统计全排列的种树

输入描述:
输入一个字符串

输出描述:
输出字符串的全排列，每种情况占一行，最后一行输出全排列的个数

输入样例:
123
输出样例:
123
132
213
231
312
321
6
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXSIZE = 10000;
string s;
string a[MAXSIZE];
int amount;

int swap(char &a, char &b){
	char t = a;
	a = b;
	b = t;
	return 0;
}

int judge(int start, int end){
	for(int i = start; i < end; i++)
		if(s[i] == s[end])
			return 0;

	return 1;
}

int permutation(int i){
	if(i == s.length()){
		a[amount++] = s;
		return 0;
	}
	for(int j = i; j < s.length(); j++){
		if(judge(i, j)){
			swap(s[i], s[j]);
			permutation(i + 1);
			swap(s[i], s[j]);
		}
	}
	return 0;
}

int main(){
	getline(cin, s);
	permutation(0);
	sort(a, a + amount);
	for(int i = 0; i < amount; i++)
		cout << a[i] << endl;
	cout << amount << endl;
    return 0;
}
