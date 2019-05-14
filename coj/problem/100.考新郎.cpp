/*
Id:[100]	
考新郎 (10分)
题目内容:
 国庆期间,省城HZ刚刚举行了一场盛大的集体婚礼,为了使婚礼进行的丰富一些,司仪临时想出了有一个有意思的节目,叫做"考新
郎",具体的操作是这样的:首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;然后,让各位新郎寻找自己的
新娘.每人只准找一个,并且不允许多人找一个.最后,揭开盖头,如果找错了对象就要当众跪搓衣板..
  假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
输入描述:
N M
输出描述:
可能的种数
输入样例:
3 2
输出样例:
3
*/

//https://www.cnblogs.com/c1299401227/p/5349727.html

#include <iostream> 
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	long long f[1000];
	f[1] = 0;
	f[2] = 1;
	for(int i = 3; i <= m; i++)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	long long s1 = 1;
	long long s2 = 1;
	int t = n - m > m ? m : n - m;
	for(int i = 1; i <= t; i++){
		s1 *= n--;
	}
	for(int i = 1; i <= m; i++)
		s2 *= i;
	cout << s1 / s2 * f[m] << endl;
    return 0;
}
