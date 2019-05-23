/*
Id:[60]	
同色三角形 (15分)
题目内容:
 平面上有n个点（n≤8000），每两个点之间都有一条红色或者是黑色的线段，任意三点均不共线。
现在，已知哪些点之间连的线段是红色的，剩下的线段都是黑色的，要求计算这些点组成的三角
形中有多少是同色的（顶点编号从1到n）？
输入描述:
第一行是n, m（3≤n≤8000），n表示点的个数，m表示红色线段的条数。下面m行，每
一行都是两个整数a和b，表示点a和点b之间的线段是红色的（a<b）。
输出描述:
只有一行，表示同色三角形的个数。
提示：本题输出数据可能会超出长整数（long int）的范围。
输入样例:
6 5
1 2
1 3
2 3
2 5
3 6
输出样例:
7
*/

/*
如果以某一个点开始找如果两条边异色，那么一定不是单色三角形，所以枚举与每个点相连的边里两种颜色的边的个数，然后计算n(红)＊n(黑)
因为是双向边，所以每条边会被算两次，所以要去重，也就是/2
*/

#include <iostream> 
using namespace std;

typedef long long ll;
const int MAXSIZE = 8005;
ll a[MAXSIZE][MAXSIZE];

ll c(ll m, ll n){
	if(n <= m)
		return 1;
	return n * c(m, n - 1);
}

int main(){
	int n, m;
	cin >> n >> m;
	ll x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	ll sum = 0;
	for(int i = 1; i <= n; i++){
		ll red = 0;
		ll black = 0;
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1)
				red++;
		}
		black = n - 1 - red;
		sum += (red * black) / 2;
	}
	ll result = c(n - 3, n) / 6 - sum;
	cout << result << endl;
    return 0;
}
