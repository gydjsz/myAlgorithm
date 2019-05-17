/*
Id:[182]	
安排车辆 (15分)
题目内容:
 有一家出租车公司，通过网络预约安排出租。现收到M个预约单，希望用车时间区间是（s1,f1）,(s2,f2),...,(sM,fM).
问最少需要准备几辆车才能完成出租。提示：车辆归还后，下一个客户才可以使用。
输入描述:
第一行是M，随后M行是预约的时间区间
输出描述:
最少需要的车的台数
输入样例:
4
1,5
2,7
3,6
8,10
输出样例:
3
*/

#include <iostream> 
#include <cstring>
using namespace std;

/*
int getNum(int &a, int &b, string s){
	int n;
	int i = 0;
	a = 0;
	b = 0;
	while(s[i] != ',')
		a = a * 10 + (s[i++] - '0');
	i++;
	while(s[i])
		b = b * 10 + (s[i++] - '0');
	return 0;
}
*/

int main(){
	int n;
	cin >> n;
	int a[1000];
	memset(a, 0, sizeof(a));
	int x, y;
	int m = 0;
	for(int i = 0; i < n; i++){
		char s;
		cin >> x >> s >> y;
		//getNum(x, y, s);
		a[x]++;
		a[y + 1]--;
		m = max(m, y);
	}
	int t = 0;
	for(int i = 1; i <= m; i++){
		a[i] += a[i - 1];
		t = max(t, a[i]);
	}
	cout << t << endl;
    return 0;
}
