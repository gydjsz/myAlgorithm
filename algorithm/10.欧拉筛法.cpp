//O(n)

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 10000;
int prime[MAXSIZE];
bool visit[MAXSIZE];

int getPrime(int n){
	int cnt = 0;
	memset(visit, true, sizeof(visit));
	for(int i = 2; i <= n; i++){
		if(visit[i])
			prime[cnt++] = i;
		for(int j = 0; j < cnt && i * prime[j] <= n; j++){
			visit[i * prime[j]] = false;
			if(i % prime[j] == 0) break;
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	int cnt = getPrime(n);
	for(int i = 0; i < cnt; i++)
		cout << prime[i] << " ";
    return 0;
}
