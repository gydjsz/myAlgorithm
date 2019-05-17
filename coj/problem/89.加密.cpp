/*
Id:[89]	
加密 (15分)
题目内容:
一种Playfair密码变种加密方法如下：首先选择一个密钥单词（称为pair）（字母不重复，且都为小写字母），然后与字母表中
其他字母一起填入至一个5x5的方阵中，填入方法如下：
1.首先按行填入密钥串。
2.紧接其后，按字母序按行填入不在密钥串中的字母。
3.由于方阵中只有25个位置，最后剩下的那个字母则不需变换。
如果密钥为youandme，则该方阵如下： 
y o u a n
d m e b c
f g h i j
k l p q r
s t v w x
在加密一对字母时，如am，在方阵中找到以这两个字母为顶点的矩形：
o u a 
m e b 

这对字母的加密字母为该矩形的另一对顶点，如本例中为ob。
请设计程序，使用上述方法对输入串进行加密，并输出加密后的串。
另外有如下规定：
1、一对一对取字母，如果最后只剩下一个字母，则不变换，直接放入加密串中；
2、如果一对字母中的两个字母相同，则不变换，直接放入加密串中；
3、如果一对字母中有一个字母不在正方形中，则不变换，直接放入加密串中；
4、如果字母对出现在方阵中的同一行或同一列，如df或hi，则只需简单对调这两个字母，即变换为fd或ih；
5、如果在正方形中能够找到以字母对为顶点的矩形，假如字母对为am，则该矩形的另一对顶点字母中，与a同行的字母应在前
面，在上例中应是ob；同样若待变换的字母对为ta，则变换后的字母对应为wo；
6、本程序中输入串均为小写字母，并不含标点、空格或其它字符。
解密方法与加密相同，即对加密后的字符串再加密，将得到原始串。
输入描述:
从控制台输入两行字符串，第一行为密钥单词（长度小于等于25，字母不重复，且都为小写字母），第二行为待加密字符串（长度
小于等于50），两行字符串末尾都有一个回车换行符，并且两行字符串均为小写字母，不含其它字符。
输出描述:
在标准输出上输出加密后的字符串。
输入样例:
youandme
welcometohangzhou
输出样例:
vbrmmomvugnagzguu
*/

#include <iostream> 
#include <cstring>
using namespace std;

string s1, s2;
const int M = 5;

int solve(){
	int a[26];
	char b[M][M];
	memset(a, 0, sizeof(a));
	int x = 0, y = 0;
	for(int i = 0; i < s1.length(); i++){
		a[s1[i] - 97] = 1;
		b[x][y++] = s1[i];
		if(y == 5){
			x++;
			y = 0;
		}
	}
	for(int i = 0; i < 26; i++){
		if(a[i] != 1){
			a[i] = 1;
			b[x][y++] = char(i + 97);
		}
		if(y == 5){
			x++;
			y = 0;
		}
		if(x == 5)
			break;
	}
	string s3 = "";

	for(int i = 0; i < s2.length(); i += 2){
		if(i == s2.length() - 1){  // 1、一对一对取字母，如果最后只剩下一个字母，则不变换，直接放入加密串中；
			s3 += s2[i];
			break;
		}
		char p = s2[i], q = s2[i + 1];  // 2、如果一对字母中的两个字母相同，则不变换，直接放入加密串中；
		if(p == q){
			s3 = s3 + p + q;
			continue;
		}
		if(a[p - 97] == 0 || a[q - 97] == 0){ // 3、如果一对字母中有一个字母不在正方形中，则不变换，直接放入加密串中；
			s3 = s3 + p + q;
			continue;
		}
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		for(int r = 0; r < M; r++){
			for(int w = 0; w < M; w++){
				if(b[r][w] == p){
					x1 = r;
					y1 = w;
				}
				if(b[r][w] == q){
					x2 = r;
					y2 = w;
				}
			}
			if(x1 != -1 && x2 != -1)
				break;
		}
	   /* 4、如果字母对出现在方阵中的同一行或同一列，如df或hi，则只需简单对调这两个字母，即变换为fd或ih； */
		if(x1 == x2 || y1 == y2){
			s3 = s3 + q + p;
			continue;
		}
	   /* 5、如果在正方形中能够找到以字母对为顶点的矩形，假如字母对为am，则该矩形的另一对顶点字母中，与a同行的字母应在前 */
		p = b[x1][y2];
		q = b[x2][y1];
		s3 = s3 + p + q;
	}
	cout << s3 << endl;
	return 0;
}

int main(){
	cin >> s1 >> s2;
	solve();
    return 0;
}
