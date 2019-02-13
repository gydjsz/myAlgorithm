/*
题目描述
输入数字1~7的表示星期一至星期日，输出对应的星期几的英文名称。
如果是1，输出Monday;
如果是2，输出Tuesday;
如果是3，输出Wednesday;
如果是4，输出Thursday;
如果是5，输出Friday;
如果是6，输出Saturday;
如果是7，输出Sunday;

输入
输入一个数字

输出
输出对应的英文名称

样例输入
1

样例输出
Monday
*/

/*两种思路：
  1. 使用字符串数组存储星期，然后用下标访问
  2. 最直接的使用switch
  */

#include <iostream>
using namespace std;

int main(){
	int day;
	cin >> day;
	/*第一种
	switch(day){
		case 1:
			cout << "Monday" << endl;
			break;
		case 2:
			cout << "Tuesday" << endl;
			break;
		case 3:
			cout << "Wednesday" << endl;
			break;
		case 4:
			cout << "Thursday" << endl;
			break;
		case 5:
			cout << "Friday" << endl;
			break;
		case 6:
			cout << "Saturday" << endl;
			break;
		default:
			cout << "Sunday" << endl;
	}
	*/
	//第二种
	string a[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	cout << a[day - 1] << endl;
	return 0;
}
