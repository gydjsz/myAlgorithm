/*
 *利用矩阵快速幂求斐波那切数列
 F[i] = 1 * F[i - 1] + 1 * F[i - 2] 
 F[i - 1] = 1 * F[i - 1] + 0 * F[i - 2];

 -       -    -   -     -        -
|  F[i]	  | =| 1 1 | * | F[n - 1] | 
|F[i - 1] |  | 1 0 |   | F[n - 2] |
 -       -    -   -     -        - 
 -       -    -   - ^(n - 1) -    -
|  F[i]	  | =| 1 1 |        | F[1] | 
|F[i - 1] |  | 1 0 |   *    | F[0] |
 -       -    -   -          -    - 

 也就是使用矩阵快速幂求出{1 1} 的n - 1次方，F[1] = 1, F[0] = 0,令求得的矩阵为Ａ，数列第ｎ个的值为A[0][0]                 1 0
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 100;

//矩阵相乘
mat mul(mat &A, mat &B){
	mat C(A.size(), vec(B[0].size()));
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < A.size(); j++)
			for(int k = 0; k < A.size(); k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

//快速幂
mat pow(mat A, ll n){
	mat B(A.size(), vec(A.size()));
	for(int i = 0; i < A.size(); i++)
		B[i][i] = 1;
	while(n > 0){
		if(n & 1)
			B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

//求斐波那切数列
int Fibonacci(int n){
	mat A(2, vec(2));
	A[0][0] = 1;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 0;
	A = pow(A, n - 1);
	cout << A[0][0] << endl;
}

int main(){
	/*
	// 求矩阵Ａ的ｍ次方
	int n, m;
	cin >> n >> m;   //ｎ为矩阵的阶，ｍ为幂次
	mat A(M, vec(M));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	mat B = pow(A, m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
	*/

	//求斐波那切数列	
	int n;
	cin >> n;
	Fibonacci(n);
	return 0;
}
