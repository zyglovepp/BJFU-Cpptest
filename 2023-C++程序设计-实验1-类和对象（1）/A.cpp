/**描述

编写一个圆类Circle，实现半径的输入、面积的计算和输出。要求在Circle类中分别写3个成员函数实现输入半径、计算面积、输出面积。


输入

输入一行，输入圆的半径(double类型)。


输出

输出一行，输出圆的面积(保留小数点后两位)。


输入样例 1

3
输出样例 1

28.27
输入样例 2

1.2
输出样例 2

4.52
提示

1、在输出面积前使用如下语句：cout<<setiosflags(ios::fixed)<<setprecision(2);来设置输出格式，因此需要包含iomanip头文件

2、使用acos(-1.0)来得到圆周率的值，可将其设置为常量，因此：const double PI=acos（-1.0）；需要包含cmath头文件
**/
// 以下是解答:
//  引入iostream头文件，用于输入输出
#include <iostream>
// 引入iomanip头文件，用于对输出进行格式化处理
#include <iomanip>
// 引入cmath头文件，用于使用acos函数
#include <cmath>
using namespace std;

// 定义PI的值为acos(-1.0)，即圆周率的值
const double PI = acos(-1.0);

// 定义一个叫做Circle的类
class Circle
{
private:
    double r; // 定义圆的半径r
    double a; // 定义圆的面积a

public:
    void input_r() // 定义输入半径的函数
    {
        cin >> r;
    }
    void calc_a() // 定义计算面积的函数
    {
        a = PI * r * r;
    }
    void output_a() // 定义输出面积的函数
    {
        // 对输出进行格式化处理
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << a << endl;
    }
};

// 主函数
int main()
{
    Circle c;     // 创建一个Circle对象
    c.input_r();  // 调用Circle类的输入半径的函数
    c.calc_a();   // 调用Circle类的计算面积的函数
    c.output_a(); // 调用Circle类的输出面积的函数
    return 0;     // 返回0，表示程序正常结束
}