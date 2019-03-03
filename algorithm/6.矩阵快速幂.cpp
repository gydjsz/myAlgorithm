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

      -   -  
 A = | 1 1 |
     | 1 0 |
      -   - 

 也就是使用矩阵快速幂求出A的n - 1次方，F[1] = 1, F[0] = 0,求得的矩阵为A'(2 * 1)，数列第ｎ个的值为A'[0][0]                 
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
	//Ｃ默认值为0
	mat C(A.size(), vec(B[0].size()));   //A.size()是矩阵的行，B[0].size()是矩阵的列, n * m 矩阵　和　m * k矩阵相乘之后，新矩阵为n * k
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < B.size(); j++)   //B.size()是矩阵的行，也就是A[0].size()
			for(int k = 0; k < B[0].size(); k++)
				C[i][j] += A[i][k] * B[k][j];  //新矩阵当前值=矩阵A的当前行 * 矩阵B的当前列的和
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
	/* //求矩阵Ａ× Ｂ
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	//A(M, vec(M))是vector的组合，就是一个vector中的数据是vector<int>,每个vector<int>存储整数值，可以理解为一个二维数组
	//vec中存储vec1,vec2,vec3,vec4, 而vec1中存储1, 2, 3, 4
	//vec: vec1  vec2  vec3  vec4
	//     1     1     1     1
	//     2     2     2     2
	//     3     3     3     3
	//     4     4     4     4
	mat A(M, vec(M)), B(M, vec(M));
	

	for(int i = 0; i < ax; i++)
		for(int j = 0; j < ay; j++)
			cin >> A[i][j];

	for(int i = 0; i < bx; i++)
		for(int j = 0; j < by; j++)
			cin >> B[i][j];

	mat C = mul(A, B);
	for(int i = 0; i < ax; i++){
		for(int j = 0; j < by; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	*/

	/* // 求矩阵Ａ的ｍ次方
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
	} */

	//求斐波那切数列	
	int n;
	cin >> n;
	Fibonacci(n);
	return 0;
}
