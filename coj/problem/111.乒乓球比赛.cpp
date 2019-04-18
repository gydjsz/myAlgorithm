/*
Id:[111]	
乒乓球比赛 (10分)
题目内容:
 两个乒乓球队进行比赛，各出三人。甲队为a，b，c三人，乙队为x，y，z三人。已抽签
决定比赛名单。共三场比赛，所有队员必须参加比赛。有人向队员打听比赛的名单，
a说他不和x比，c说他不和x，z比，请编程找出三场比赛赛手的名单。
输入描述:
不需要输入
输出描述:
假设a和y比，则输出
a vs y
严格按照上面的格式输出，不要有多余的文字叙述或符号，每场比赛输出占一行
输入样例:
不需要输入
输出样例:
a vs y
*/

#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
	int a[] = {0, 1, 2};
	char b[] = {'x', 'y', 'z'};
	do{
		//a说他不和x比，c说他不和x，z比
		if(a[0] != 0 && a[2] != 0 && a[2] != 2){
			cout << "a vs " << b[a[0]] << endl; 
			cout << "b vs " << b[a[1]] << endl;
			cout << "c vs " << b[a[2]] << endl;
		}
	}while(next_permutation(a, a + 3));
    return 0;
}
