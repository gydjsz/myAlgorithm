/*
 树状数组:
 1. 给定i, 计算a1 + a2 + ... + ai
 2. 给定i和x, 执行ai += x;
 时间复杂度: O(logn)
 */

int bit[MAX], n;

int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

int add(int i, int x){
	while(i <= n){
		bit[i] += x;
		i += i & -i;
	}
	return 0;
}

