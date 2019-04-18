/*
Id:[81]	
特别的幸运数 (15分)
题目内容:
YF不爱名利，所以他既不喜欢6，也不喜欢8。他的幸运数字是4和7。如果一个数字中只包含4和7，他就认为这个数字是他的幸运数。
现在给你两个正整数a,b，要求返回a,b之间的幸运数的个数，包括a,b本身。
输入描述:
第一行输入数目n,表示后面有n组ab
第2行开始，每行一组a b, 空格隔开。
输出描述:
每行输出一个数，即a,b之间的幸运数的个数。
输入样例:
3
11 20
4 7
1 10

输出样例:
0
2
2

*/

#include <iostream> 
using namespace std;

int solve(){
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for(int i = a; i <= b; i++){
		int m = i;
		while(m){
			if(m % 10 == 4 || m % 10 == 7)
				m /= 10;
			else
				break;
		}
		if(m == 0)
			sum++;
	}
	cout << sum << endl;
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
