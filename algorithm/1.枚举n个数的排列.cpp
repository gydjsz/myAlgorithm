#include <iostream>
using namespace std;

int swap(int &a, int &b){   //交换数组中两个元素位置
	int t = a;
	a = b;
	b = t;
	return 0;
}

int permutation(int k, int n, int perm[]){
	if(k == n - 1){
		for(int i = 0; i < n; i++)   //输出一个排列
			cout << perm[i] << " ";
		cout << endl;
		return 0;
	}
	for(int i = k; i < n; i++){
		if(i != k && perm[i] == perm[k]) continue;    //除本身外，如果交换的两个数相同，则跳过
		swap(perm[i], perm[k]);   
		permutation(k + 1, n, perm);   //递归进行排列
		swap(perm[i], perm[k]);        //恢复原来的位置
	}
	return 0;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	permutation(0, n, a);
	return 0;
}
