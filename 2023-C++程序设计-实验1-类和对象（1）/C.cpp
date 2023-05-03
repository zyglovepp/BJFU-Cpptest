/*
过道和栅栏的造价
描述

一矩形体育场如下图所示，现在需在其周围建一矩形过道，并在四周围安上栅栏。栅栏价格为50元/米，过道造价为240元/平方米。过道宽为1.5米，体育场的长宽由键盘输入。

图片.png

体育场和矩形过道都是如下Rectangle的对象，请实现以下Rectagnle类，编写main函数计算并输出过道和栅栏的造价。

class Rectangle

{

private:

  double length; //长

  double width; //宽
public:

  Rectangle(double Length=10.,double Width=5.);

  double Area(); //获取面积

  double Perimeter();//获取周长
};


输入

体育场的长和宽


输出

输出2行

第一行是栅栏的造价

第二行是过道的造价


输入样例 1

2.4 1.2
输出样例 1

960
4752
输入样例 2

2 1
输出样例 2

900
4320
提示

体育场用对象 rect1(x, y)来表示的话，过道外的矩形就用对象 rect2(x + 3, y + 3)表示
*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length; // 长
    double width;  // 宽
public:
    Rectangle(double Length = 10., double Width = 5.); // 构造函数
    double Area();                                     // 获取面积
    double Perimeter();                                // 获取周长
};

Rectangle::Rectangle(double l, double w)
{
    length = l;
    width = w;
}

double Rectangle::Area()
{
    return length * width;
}

double Rectangle::Perimeter()
{
    return 2 * (length + width);
}

int main()
{
    double length, width;
    cin >> length >> width;

    Rectangle stadium(length, width);
    Rectangle runway(length + 3, width + 3);

    double fence_price = 50 * runway.Perimeter();
    double runway_price = 240 * (runway.Area() - stadium.Area());
    cout << int(fence_price + 0.5) << endl;
    cout << int(runway_price + 0.5) << endl;

    return 0;
}
