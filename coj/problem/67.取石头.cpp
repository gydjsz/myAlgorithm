/*
Id:[67]	
取石头 (15分)
题目内容:
有一堆石子，A，B两人轮流从中取出石子，每次取出的石子数目只能为1，3，7或8，最后一枚石子谁取到就是输方。
A,B两人都足够聪明，不会做出错误的判断。现给出一定数目的石子，A先取石子，计算A最终是输是赢，赢用1表示，
输用0表示.

输入描述:
第一行为一个整数n(0< n <=100),表示玩n局，接下来n行每行有一个整数，表示对应的局提供的石子数（不大于
10000），
输出描述:
编程输出A对应的n局是赢是输，赢输出1，输输出0.
输入样例:
3
1
3
10
输出样例:
0
0
1
*/

#include <iostream> 
#include <cstring>
using namespace std;

int solve(){
	int n;
	cin >> n;
	int f[10005];
	memset(f, 0, sizeof(f));
	//1 3 7 8
	f[0] = 1;
	f[1] = 0;
	f[2] = 1;
	f[3] = 0;
	f[4] = 1;
	f[5] = 0;
	f[6] = 1;
	f[7] = 0;
	f[8] = 1;
	for(int i = 9; i <= n; i++){
		f[i] = !(f[i - 8] && f[i - 7] && f[i - 3] && f[i - 1]);
	}
	cout << f[n] << endl;
	return 0;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		solve();
	}
    return 0;
}
