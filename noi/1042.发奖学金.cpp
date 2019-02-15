/*
题目描述
某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。期末，每个学生都有3门课的成绩:语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面，这样，每个学生的排序是唯一确定的。
任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数:学号、总分) 是:
7 279
5 279
这两行数据的含义是:总分最高的两个同学的学号依次是7号、5号。这两名同学的总分都是 279 (总分等于输入的语文、数学、英语三科成绩之和) ，但学号为7的学生语文成绩更高一些。如果你的前两名的输出数据是:
5 279
7 279
则按输出错误处理，不能得分。

输入
包含n+1行: 第1行为一个正整数n，表示该校参加评选的学生人数。
第2到n+1行，每行有3个用空格隔开的数字，每个数字都在0到100之间。第j行的3个数字依次表示学号为 j-1 的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为1~n (恰好是输入数据的行号减1)。所给的数据都是正确的，不必检验。

输出
共有5行，每行是两个用空格隔开的正整数，依次表示前5名学生的学号和总分。

样例输入
6
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98

样例输出
6 265
4 264
3 258
2 244
1 237
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Students{
	int yu, s, yi;
	int num;
	int score;
};

bool cmp(Students a, Students b){
	if(a.score == b.score){
		if(a.yu == b.yu)
			return a.num < b.num;
		return a.yu > b.yu;
	}
	return a.score > b.score;
}

int main(){
	int n;
	cin >> n;
	Students students[n];
	for(int i = 0; i < n; i++){
		cin >> students[i].yu >> students[i].s >> students[i].yi;
		students[i].num = i + 1;
		students[i].score = students[i].yu + students[i].s + students[i].yi; 
	}
	sort(students, students + n, cmp);
	for(int i = 0; i < 5; i++)
		cout << students[i].num << " " << students[i].score << endl;
	return 0;
}
