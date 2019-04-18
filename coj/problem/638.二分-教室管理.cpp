/*
Id:[638]	
二分-教室管理 (10分)
题目内容:
   在大学期间，经常需要租借教室。大到院系举办活动，小到学习小组自习讨论，都需要向学校申请借教室。教室的大小功能不
同，借教室人的身份不同，借教室的手续也不一样。
   面对海量租借教室的信息，我们自然希望编程解决这个问题。我们需要处理接下来n天的借教室信息，其中第i天学校有ri个教
室可供租借。共有m份订单，每份订单用三个正整数描述，分别为dj,sj,tj，表示某租借者需要从第sj天到第tj天租借教室（包
括第sj天和第tj天），每天需要租借dj个教室。 我们假定，租借者对教室的大小、地点没有要求。即对于每份订单，我们只需要
每天提供dj个教室，而它们具体是哪些教室，每天是否是相同的教室则不用考虑。
   借教室的原则是先到先得，也就是说我们要按照订单的先后顺序依次为每份订单分配教室。如果在分配的过程中遇到一份订单
无法完全满足，则需要停止教室的分配，通知当前申请人修改订单。这里的无法满足指从第sj天到第tj天中有至少一天剩余的教
室数量不足dj个。
   现在我们需要知道，是否会有订单无法完全满足。如果有，首先遇到的是哪一个申请人。
输入描述:
第一行包含两个正整数n,m，表示天数和订单的数量。 
第二行包含n个正整数，其中第i个数为ri，表示第i天可用于租借的教室数量。 
接下来有m行，每行包含三个正整数dj表示租借的数量,sj租借开始天,tj结束天。 
每行相邻的两个数之间均用一个空格隔开。天数与订单均用从1开始的整数编号。

其中有1≤n,m≤10^6,0≤ri,dj≤10^9,1≤sj≤tj≤n。
输出描述:
如果所有订单均可满足，则输出只有一行，包含一个整数0。否则输出需要修改订单的申请人编号(1开始)。
输入样例:
4 3 
2 5 4 3
2 1 3 
3 2 4 
4 2 4
输出样例:
2
*/

#include <iostream> 
#include <cstring>
using namespace std;

typedef long long ll;

int n, m;
int flag = -1;

struct Apply{
	ll num;
	int start;
	int end;
};

bool judge(int mid, ll a[], Apply apply[]){
	ll b[n + 10];
	memset(b, 0, sizeof(b));
	for(int i = 0; i <= mid; i++){
		b[apply[i].start - 1] += apply[i].num; 
		b[apply[i].end] -= apply[i].num;
	}
	for(int i = 1; i < n; i++)
		b[i] += b[i - 1];
	for(int i = 0; i < n; i++)
		if(b[i] > a[i]){
			flag = mid;
			return false;
		}
	return true;
}

int solve(ll a[], Apply apply[]){
	int left = 0, right = m - 1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(judge(mid, a, apply))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if(flag != -1)
		cout << flag + 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}

int main(){
	cin >> n >> m;
	ll a[n + 10];
	Apply apply[n + 10];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++){
		cin >> apply[i].num >> apply[i].start >> apply[i].end;
	}
	solve(a, apply);
    return 0;
}
