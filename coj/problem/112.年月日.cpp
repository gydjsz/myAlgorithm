/*
Id:[112]	
年月日 (5分)
题目内容:
 输入某年某月某日，判断这一天是这一年的第几天？
输入描述:
依次输入年月日，中间用空格隔开，如
2012 6 10
输出描述:
2012-6-10是这年的第162天
输入样例:
2012 6 10
输出样例:
162
*/

#include <iostream> 
using namespace std;

int getDay(int year, int month, int day){
	int sum = 0;
	for(int i = 1; i < month; i++){
		switch(i){
			case 4:
			case 6:
			case 9:
			case 11:
				sum += 30;
				break;
			case 2:
				if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
					sum += 29;
				}
				else{
					sum += 28;
				}
				break;
			default:
				sum += 31;
		}
	}
	sum += day;
	cout << sum << endl;
	return 0;
}

int main() {
	int year, month, day;
	cin >> year >> month >> day;
	getDay(year, month, day);
    return 0;
}
