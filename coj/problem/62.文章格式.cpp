/*
Id:[62]	
文章格式 (15分)
题目内容:
 编写程序实现将一段文章格式化打印出来。打印时每行的长度为20个字符。
如果一行的最后一个单词超过了本行的20个字符的范围，则应把它移到下一行。
另外在每个单词之间增加一个空格，最后一个单词前面可能需要增加多个空格，
使每行的末尾准确地处在第20个位置处。
输入描述:
输入n个单词（连续输入，每个单词不能超过20个字母，单词间用空格隔开，但不
要人为转行，也就是说如果输入的单词超过一行也不要按Enter）
输出描述:
将上面n个单词分行打印，每行20个字符，如果一行只能放一个单词则单词后用空格填充，
若一行可放多个单词，则末尾必须为单词，且一个单词不能跨行输出。
输入样例:
The relationship between XML functional dependencies and XML keys are also discussed
输出样例:
The     relationship
between          XML
functional          
dependencies and XML
keys are        also
discussed
*/

#include <iostream> 
#include <cstring>
using namespace std;


string s[1000];
int amount; 

int solve(){
	for(int i = 0; i < amount; i++){
		int len = 20;
		int j;
		for(j = 0; i + j < amount && len + 1 >= 0; j++){
			len -= s[i + j].length() + 1;
		}
		string s1;
		if(i + j < amount){
			j--;
			if(j == 1){
				cout << s[i];
				len = 20 - s[i].length();
				s1.assign(len, ' ');
				cout << s1 << endl; 
			}
			else{
				len = 20;
				for(int k = 0; k < j - 1; k++){
					cout << s[i + k] << " ";
					len -= s[i + k].length() + 1;
				}
				len -= s[i + j - 1].length();
				s1.assign(len, ' ');
				cout << s1 << s[i + j - 1] << endl;
				i += j - 1;
			}
		}
		else{
			j--;
			if(len + 1 < 0){
				len = 20;
				j--;
				for(int k = 0; k < j; k++){
					cout << s[i + k] << " ";
					len -= s[i + k].length() + 1;
				}
				len -= s[i + j].length();
				s1.assign(len, ' ');
				cout << s1 << s[i + j] << endl;
				i += j;
			}
			else{
				len = 20;
				if(j == 0){
					cout << s[i];
					s1.assign(20 - s[i].length(), ' ');
					cout << s1 << endl;
				}
				else{
					for(int k = 0; k < j; k++){
						cout << s[i + k] << " ";
						len -= s[i + k].length() + 1;
					}
					len -= s[i + j].length();
					s1.assign(len, ' ');
					cout << s1 << s[i + j] << endl;
					i += j;			
				}
			}
		}
	}
	return 0;
}
int main(){   
	int i = 0;
	while(cin >> s[i++]);
	amount = i;
	solve();
	return 0;
}
