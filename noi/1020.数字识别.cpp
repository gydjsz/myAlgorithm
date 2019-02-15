/*
题目描述
输入一个不多于四位的正整数，求出它是几位数，并分别打印出各位上的数字。

输入
输入一个不多于四位的正整数x。

输出
第一行输出x的位数num，接下来num行从高位到低位输出x的每一位上的数字。

样例输入
123

样例输出
3
1
2
3
*/

/*
两种思路：
1. 当作字符串处理，输入s，调用函数length()，可以得到位数，采用下标获取每一位数字
2. 当作数字处理，输入n，先计算位数，然后通过反复去高位得到所有数
*/

#include <iostream>
using namespace std;

int main(){
	//当作字符串处理
	string s;
	cin >> s;
	int n = s.length();
	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << s[i] << endl;
	/*当作数字处理
	  int n;
	  cin >> n;
	  int i = 10, j = 1;
	  while(n / i > 0){
	      i *= 10;
		  j++;
	  }
	  i /= 10;
	  cout << j << endl;
	  for(int k = 1; k <= j; k++){
	      cout << n / i << endl;
		  n = n - n / i * i;
		  i /= 10;
	  }
	  */
	return 0;
}
