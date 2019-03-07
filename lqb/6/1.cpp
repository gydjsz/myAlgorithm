#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, e, f, g, h;
	for(int a = 0; a <= 9; a++)
		for(int b = (a + 1) % 10; b <= 9; b++)
			for(int c = (b + 1) % 10; c <= 9; c++)
				for(int d = (c + 1) % 10; d <= 9; d++)
					for(int e = (d + 1) % 10; e <= 9; e++)
						for(int f = (e + 1) % 10; f <= 9; f++)
							for(int g = (f + 1) % 10; g <= 9; g++)
								for(int h = (g + 1) % 10; h <= 9; h++)
									if(a * 1000 + b * 100 +  c * 10 + d + e * 1000 + f * 100 + g * 10 + b == e * 10000 + f * 1000 + c * 100 + b * 10 + h){
										cout << a << " " << b << " " << c << " " << e << " " << f << " " << g << " " << h << endl;
										cout << "答案为：" << e << " " << f << " " << g << " " << b << endl;	
										return 0;
									}
	return 0;
}
