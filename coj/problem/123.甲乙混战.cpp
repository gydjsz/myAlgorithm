/*
Id:[123]	
甲乙混战 (15分)
题目内容:
 某游戏规则中，甲乙双方每个回合的战斗总是有一方胜利，一方失败。
游戏规定：失败的一方要把自己的体力值的1/4加给胜利的一方。例如：
如果双方体力值当前都是4，则经过一轮战斗后，双方的体力值会变为：5，3。
现在已知：双方开始时的体力值甲：1000，乙：2000。
假设战斗中，甲乙获胜的概率都是50%求解：双方经过4个回合的战斗，
体力值之差小于1000的理论概率。
输入描述:
此题直接编译出结果就可，不需要输入数据
输出描述:
输出4个回合的战斗后体力值之差小于1000的理论概率，保留6位小数
输入样例:
此题直接编译出结果就可，不需要输入数据
输出样例:
0.000000
*/

#include <iostream> 
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int sum;

int dfs(int i, double j, double y){
	if(i == 4){
		if(fabs(j - y) <= 1000)
			sum++;
		return 0;
	}
	dfs(i + 1, j + y / 4, y - y / 4);
	dfs(i + 1, j - j / 4, y + j / 4);
	return 0;
}

int main(){
	dfs(0, 1000, 2000);
	cout << fixed << setprecision(6) << 1.0 * sum / (1 << 4) << endl;
    return 0;
}
