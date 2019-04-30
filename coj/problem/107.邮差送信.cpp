/*
Id:[107]	
邮差送信 (15分)
题目内容:
 有一个邮递员要在n个城市之间来回送信。但有的城市之间有大路相连而有的没有路。
现在要由一个城市到另一个城市送信，中途最少要经过多少个其它的城市呢？
输入描述:
第一行是n,k(1<=n<=10000, 1<=k<=20000)，接下来就是k行。这k行每行有两个数a,b(1<=a,b<= n)，表示城市a和b之间有
大路k行以后就是两个数p和q。
输出描述:
输出从城市p到城市q之间最少要经过的其它的城市的数目。如果p和q之间不连通则输出0
输入样例:
6 6
1 4
1 2
2 3
3 4
5 4
5 6
1 6
输出样例:
2
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec;
vector<vector<int> > mat(10005, vec);
int n, k;

int solve(){
	vector<int> v(n + 1, 0);
	int flag = 0;
	queue<int> que;
	int p, q;
	cin >> p >> q;

	que.push(p);
	v[p] = 1;
	int sum = 0;
	while(!flag && que.size() != 0){
		int t = que.front();
		que.pop();
		for(int i = 0; i < mat[t].size(); i++){
			if(!v[mat[t][i]]){
				v[mat[t][i]] = v[t] + 1;
				if(mat[t][i] == q){
					flag = 1;
					break;
				}
				que.push(mat[t][i]);
			}
		}
	}
	if(v[q] == 0)
		cout << 0 << endl;
	else
		cout << v[q] - 2 << endl;
	return 0;
}

int main(){
	cin >> n >> k;
	int x, y;
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	solve();
	return 0;
}


