/*
Id:[101]	
二十四点 (15分)
题目内容:
 问题描述：输入4个数，通过 加、减、乘、除运算看能否得到 结果 24，每个数只用一次。
输入描述:
输入四个正整数
输出描述:
能通过某种方式得到24则输出1，不能则输出0
输入样例:
6 6 6 6
输出样例:
1
*/

#include <iostream> 
#include <algorithm>
using namespace std;

const int n = 4;
double array[n];

int main() {
	for(int i = 0; i < n; i++)
		cin >> array[i];
	double sum;
	do{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++){
					sum = 0;
					switch(i){
						case 0: sum = array[0] + array[1]; break;
						case 1: sum = array[0] - array[1]; break;
						case 2: sum = array[0] * array[1]; break;
						case 3: sum = array[0] / array[1]; break;
					}
					switch(j){
						case 0: sum += array[2]; break;
						case 1: sum -= array[2]; break;
						case 2: sum *= array[2]; break;
						case 3: sum /= array[2]; break;
					}
					switch(k){
						case 0: sum += array[3]; break;
						case 1: sum -= array[3]; break;
						case 2: sum *= array[3]; break;
						case 3: sum /= array[3]; break;
					}
					if(sum == 24){
						cout << 1 << endl;
						return 0;
					}
				}
	}while(next_permutation(array, array + n));
	cout << 0 << endl;
    return 0;
}
