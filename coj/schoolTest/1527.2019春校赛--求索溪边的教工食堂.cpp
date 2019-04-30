/*
Id:[1527]	
2019春校赛--求索溪边的教工食堂 (10分)
题目内容:
 很多班级选择教工食堂就餐。XX专业进行班级聚餐，若该专业总共有n个班级，定了n张超大圆桌，可以保证同一个班级所有人都可以围桌而坐，第i个班有ai个人， 问每个班的分别有多少种坐法？
注意，以下两种坐法为一种坐法：
   1
 8/~\2
7|   |3
 6\_/4
   5

   8
 7/~\1
6|   |2
 5\_/3
   4
输入描述:
第一行输入一个数n，表示该专业总共有n个班；
第二行输入n个数，分别表示每个班的人数；

已知n<=15,且ai<=15
输出描述:
输出n个数，分别表示每个班聚餐的坐法（空格分隔，末尾有空格）
输入样例:
1
8
输出样例:
5040
*/

#include <iostream> 
using namespace std;

typedef long long ll;

int solve(){
	ll n;
	cin >> n;
	ll sum = 1;
	for(int i = 1; i <= n - 1; i++)
		sum *= i;
	cout << sum << " ";
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
