/*
评分程序
描述

为一门课写一个评分程序，评分原则如下：

（1）有两次随堂考试，每次满分50分；

（2）有一次期中考试和一次期末考试，每次满分100分；

（3）期末考试占总评成绩的50%，期中考试占总评成绩的25%，两次随堂考试总共占25%;

（4）总评成绩90~100分为A，80~89分为B，70~79分为C，60~69分为D，低于60分为E；

设计一个Socre类，数据成员如下：

string name;//记录学生姓名
double s[4];//存储4次成绩，s[0]和s[1]存储2次随堂考试，s[2]存储期中考试，s[3]存储期末考试
double total;//记录总评成绩
char grade;  //记录对应的等级

学生信息由键盘录入，默认总评成绩的等级为B，其他数据项无默认值。计算总评成绩并给出等级，输出某个同学的全部信息。

主函数如下：

int main()
{
    Score *s1=new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}


输入

输入5行

第1行是学生姓名

第2和3行是两次随堂考试成绩

第4行是期中考试成绩

第5行是期末考试成绩


输出

如果输入的成绩超出了范围，则显示：error

如果输入的成绩在题目要求的范围内，则显示：姓名，总分和等级，详见样例


输入样例 1

Jack
90
90
100
100
输出样例 1

error
输入样例 2

Mary
50
50
90
100
输出样例 2

name: Mary, total: 97.5, grade: A
提示

冒号和逗号后各有一个空格
*/
#include <iostream>
using namespace std;
class Score
{
private:
    string name;  // 记录学生姓名
    double s[4];  // 存储4次成绩，s[0]和s[1]存储2次随堂考试，s[2]存储期中考试，s[3]存储期末考试
    double total; // 记录总评成绩
    char grade;   // 记录对应的等级
public:
    void Input();
    void Evalauate();
    void Output();
};

void Score::Input()
{
    getline(cin, name);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
}
void Score::Evalauate()
{
    total = s[0] * 0.125 * 2 + s[1] * 0.125 * 2 + s[2] * 0.25 + s[3] * 0.5;
    // 根据总评成绩计算等级
    if (total >= 90)
    {
        grade = 'A';
    }
    else if (total >= 80)
    {
        grade = 'B';
    }
    else if (total >= 70)
    {
        grade = 'C';
    }
    else if (total >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'E';
    }
}

void Score::Output()
{
    if (s[0] > 50 || s[0] < 0 || s[1] > 50 || s[1] < 0 || s[2] > 100 || s[2] < 0 || s[3] > 100 || s[3] < 0)
    {
        cout << "error";
    }
    else
    {
        cout << "name: " << name << ", total: " << total << ", grade: " << grade << endl;
    }
}
int main()
{
    // 为了能够动态修改s1的值，所以不能直接Score s1;
    Score *s1 = new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}