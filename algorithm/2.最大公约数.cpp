//辗转相除法
/*a = 6 b = 4
 a - b * k = n
 a % b = n
 *6 - 4 * 1 = 2   gcd(b, a % b) => a = 4(b) b = 2(a % b)
 *4 - 2 * 1 = 2   => a = 2 b = 2
 *2 - 2 * 1 = 0   => a = 2 b = 0   当ｂ＝０时,得到最大公约数2
 */
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	ll a, b;
	cin >> a >> b;
	ll result = gcd(a, b);
	cout << result << endl;
	return 0;
}
