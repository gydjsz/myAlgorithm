#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, a[100];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	do{
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}while(next_permutation(a, a + n));
	return 0;
}
