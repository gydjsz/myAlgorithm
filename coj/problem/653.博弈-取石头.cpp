/*
Id:[653]	
博弈- 取石头 (10分)
题目内容:
 m堆石子,甲乙两人轮流取，每次需先选择1堆，并取任意数目的石子. 最后取完者的获胜.
规定甲先取。
输入描述:
可能有多组测试数据。每组的第一行是m, 第二行是m个整数，表示每堆石子的数目。
输出描述:
每个测试用例，甲失败则输出“No”。
否则输出"Yes", 并在下面的行输出取法。
按堆号顺序输出各种甲能取胜的首次取法a,b,表示在第a堆石子中取完石子后剩下b个，甲可以获胜。
输入样例:
2
45 45
3
3 6 9
5
5 7 8 9 10
输出样例:
No
Yes
9 5
Yes
8 1
9 0
10 3
*/

#include <iostream> 
using namespace std;

int n;

int solve(){
	int a[n];
	int s = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s ^= a[i];
	}
	if(s == 0){
		cout << "No" << endl;
		return 0;
	}
	else{
		cout << "Yes" << endl;
	}
	for(int i = 0; i < n; i++){
		s ^= a[i];
		for(int j = 0; j < a[i]; j++){
			s ^= j;
			if(s == 0){
				cout << a[i] << " " << j << endl;
				s ^= j;
				break;
			}
			s ^= j;
		}
		s ^= a[i];
	}
	return 0;
}

int main(){
	while(cin >> n){
		solve();
	}
    return 0;
}
