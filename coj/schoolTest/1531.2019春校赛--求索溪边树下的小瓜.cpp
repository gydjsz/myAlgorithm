/*
Id:[1531]	
2019春校赛--求索溪边树下的小瓜 (10分)
题目内容:
 “三峡畔，长江边...”小瓜哼着校歌，慢悠悠的求索溪边散步。忽然，他在求索溪旁边发现一个非常漂亮的银杏树。
 于是小瓜走到树下一手拉着银杏树，开始蹦蹦跳跳的围着银杏树转圈。现在设小瓜发现银杏树时，自己的位置为A（Xa，Ya），
 在银杏树下初始位置为B（Xb,Yb）,围着银杏树（坐标为（0,0））顺时针转了K弧度，结束时小瓜的位置为C（Xc,Yc）。
 现在小瓜想知道自己发现银杏树时的位置A，在树下的初始位置B，与结束时的位置C形成的三角形△ABC面积S。
 你能编程帮助小瓜解决这个问题吗？（π取3.1415926）
输入描述:
输入A点坐标，B点坐标以及弧度K（坐标为整型实数）
输出描述:
围成的△ABC的面积S（结果保留小数点后两位）
输入样例:
-2 0 -1 0 1.5707963
输出样例:
0.50
*/


/*
 *
 *思路：极坐标系求出C点的坐标，然后用海伦公式得到三角形的面积
 x = R * cos(k - $\theta$)
 y = R * sin(k - $\theta$)

 k - $\theta$ 为C点相对于x轴转的角度

 *
 */

#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double x1, y1;
	double x2, y2;
	double k;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> k;
	//AB边
	double AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	//求C点的坐标
	double R = sqrt(x2 * x2 + y2 * y2);
	double x3 = R * (cos(k) * x2 / R + sin(k) * y2 / R);
	double y3 = R * (sin(k) * x2 / R - cos(k) * y2 / R);
	
	double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	//海伦公式
	double p = (AB + BC + AC) / 2;
	double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
	cout << fixed << setprecision(2) << S << endl;
    return 0;
}
