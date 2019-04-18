/*
Id:[73]	
合并排序 (10分)
题目内容:
 使用合并排序算法，对输入的n个数据进行按升序排序。
输入描述:
分两行，第一行是整数n,第二行是n个整数，每个整数之间用空格间隔。
输出描述:
按升序排序的n个整数
输入样例:
8
9 8 7 6 5 4 3 2
输出样例:
2 3 4 5 6 7 8 9
*/

#include <iostream> 
using namespace std;

int a[100];

int merge(int left, int mid, int right){
	int temp[100], t = 0;
	int i = left, j = mid + 1;
	while(i <= mid && j <= right){
		if(a[i] < a[j])
			temp[t++] = a[i++];
		else
			temp[t++] = a[j++];
	}
	while(i <= mid)
		temp[t++] = a[i++];
	while(j <= right)
		temp[t++] = a[j++];
	t = 0;
	while(left <= right)
		a[left++] = temp[t++];
	return 0;
}

int sort(int left, int right){
	if(left < right){
		int mid = (right + left) / 2;
		sort(left, mid);
		sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(0, n - 1);
	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i != n - 1)
			cout << " ";
	}
    return 0;
}
