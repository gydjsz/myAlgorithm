/*
题目描述
在传递信息的过程中，为了加密，有时需要按一定规则将文本转换成密文发送出去。有一种加密规则是这样的：
1. 对于字母字符，将其转换成其后的第3个字母。例如：A→D，a→d，X→A，x→a；
2. 对于非字母字符，保持不变。
现在，请你根据输入的一行字符，输出其对应的密码。
 

输入
输入一个字符串。

输出
输出加密后的字符串。

样例输入
I(2016)love(08)China(15)!

样例输出
L(2016)oryh(08)Fklqd(15)!
*/

#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	char a[26];
	for(int i = 0; i < 26; ++i)
		a[i] = i + 97;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = a[(s[i] - 97 + 3) % 26];
		}
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = a[(s[i] - 65 + 3) % 26] - 32;
		}
	}
	cout << s << endl;
	return 0;
}
