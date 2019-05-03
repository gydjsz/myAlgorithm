/*
Id:[140]	
带分数 (15分)
题目内容:
 
    100 可以表示为带分数的形式：100 = 3 + 69258 / 714

    还可以表示为：100 = 82 + 3546 / 197

    注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

    类似这样的带分数，100 有 11 种表示法。

题目要求：
从标准输入读入一个正整数N (N<1000*1000)
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！


例如：
用户输入：
100
程序输出：
11
输入描述:
从标准输入读入一个正整数N (N<1000*1000)
输出描述:
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
输入样例:
100
输出样例:
11
*/

#include <iostream> 
#include <algorithm>
using namespace std;

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
	int n;
	cin >> n;
	int count = 0;
	do{
		int A = 0, B = 0, C = 0;
		for(int i = 0; i < 7; i++){
			A = A * 10 + a[i]; 
			B = 0;
			if(A > n)
				continue;
			for(int j = i + 1; j < 8; j++){
				B = B * 10 + a[j];
				C = 0;
				for(int p = j + 1; p < 9; p++)
					C = C * 10 + a[p];
				if(B % C == 0 && A + B / C == n){
					count++;
				}
			}
		}
	}while(next_permutation(a, a + 9));
	cout << count << endl;

    return 0;
}
