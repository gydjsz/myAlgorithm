/*
Id:[1532]	
2019春校赛--求索溪边的砖 (10分)
题目内容:
 众所周知，求索溪边堆了很多砖。 
这些砖的长宽高规格不太一样。 一共有n{n<=30}种砖，第i种砖的长宽高分别为{Xi,Yi,Zi}, {xi,yi,zi < 10000}，每种砖有无限多。学校开展桃花节需要将这些砖搬走, 高级搬砖工小胖接了活。

我们搬砖时都是将砖叠成一摞再搬。小胖的力气非常大，当然希望尽可能的摞到最高, 但是只有上面砖的底面两条边都小于下面砖底面相对的两条边时，才能叠稳，注意砖可以旋转。(如: 长宽高为[3,4,5]的砖能叠在[2，5，5]，[5,4,3]上,不能叠在[2,4,3]上)。 帮小胖算算他第一次最多能搬走多少砖。
输入描述:
多组输入 ， 每组一个整数n{n<=30}表示砖的种类，接下来n行每行3个整数x,y,z {x,y,z < 10000} 
n=0表示输入结束。
输出描述:
n 行，每行一个整数表示该组样例中第一次最多能搬砖的数量
输入样例:
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
输出样例:
2
3
7
6
*/

#include <iostream> 
#include <cstring>
#include <algorithm>
using namespace std;

int n;

struct Brick{
	int x;
	int y;
	int z;
}brick[50];

int order(int &x, int &y, int &z){
	int t;
	if(x > y){
		t = x;
		x = y;
		y = t;
	}
	if(y > z){
		t = y;
		y = z;
		z = t;
	}
	return 0;
} 

bool cmp(Brick a, Brick b){
	if(a.x == b.x){
		if(a.y == b.y)
			return a.z < b.z;
		return a.y < b.y;
	}
	return a.x < b.x;
}

int solve(){
	memset(brick, 0, sizeof(brick));
	int x, y, z;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
		order(x, y, z);
		brick[i].x = x;
		brick[i].y = y;
		brick[i].z = z;
	}
	sort(brick, brick + n, cmp);
	for(int i = 0; i < n; i++)
	return 0;
}

int main(){
	while(cin >> n && n != 0){
		solve();
	}
	

    return 0;
}
