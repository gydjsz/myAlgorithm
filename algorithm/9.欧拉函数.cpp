/*
ϕ (n) =   1..n中与n互质的数的个数
令n = p1r1p2r2...pkrk
则ϕ(n)=n*(1-1/p1)*(1-1/p2)*...*(1-1/pk)
*/

#include <iostream>
using namespace std;

typedef long long ll;

ll eular(ll n){
	ll ans = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			ans -= ans / i;
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1)
		ans -= ans / n;
	return ans;
}

int main(){
	ll n;
	cin >> n;
	cout << eular(n) << endl;
	return 0;
}
