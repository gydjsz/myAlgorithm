#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0)
			sum += 2;
	}
	if(pow((int)sqrt(n), 2) == n)
		sum--;
	cout << sum << endl;
	return 0;
}
