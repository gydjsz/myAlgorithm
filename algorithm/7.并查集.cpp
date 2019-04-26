#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;

int father[SIZE], height[SIZE];   //father记录每个元素的上级，height记录等级

void init(int n){
	for(int i = 0; i < n; i++){  
		father[i] = i;    //初始时，每个元素的上司是自己
		height[i] = 1;    //初始等级为1
	}
}

int find(int v){
	return father[v] = father[v] == v ? v : find(father[v]);   //找到元素的最高一级指挥官
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(height[x] < height[y])    //把等级低的放等级高的下面
		father[x] = father[y];
	else{
		father[y] = x;               // 如果后者等级高，那么将等级低的归自己管
		if(height[x] == height[y])   //如果两者等级相等，那么当把同等级的归自己管，而自己等级需+1
			height[x]++;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int x, y;
	init(n);   //初始化等级
	for(int i = 1; i <= m; i++){
		cin >> x >> y;      //输入有关联的两个人
		join(x, y);         //加入到集合中来 
	}
	for(int i = 1; i <= n; i++)
		cout << i << " ";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << find(i) << " ";
	return 0;
}
