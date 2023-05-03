/*
描述

以下是图书类Book的声明，缺少实现部分，请实现成员函数并编写main函数测试Book类。

class Book
{
private:
   char *name;                //书名
   char *author;              //作者
   int sale;                  //销售量
public:
   Book();                               //无参构造函数
   Book(char *a, char *b, int c);         //有参构造函数
   Book(const Book &);                   //拷贝构造函数
   void print();                          //显示数据
   ~Book();                              //析构函数
};

输入

在main函数中，我们输入三行数据，第一行是书的名称(长度不超过100，可能含有空格)，第二行是作者的名字(长度不超过100，可能含有空格),第三行是销量(整数类型)。

类中有三个对应的成员变量，分别为name,author和sale，利用题目中所给的构造函数来实例化对象，需要注意的是，题目中有三个构造函数，分别是有参构造函数和无参构造函数还有拷贝构造函数。在此我们特别声明：

（1）当输入的name,author和sale都为-1的时候，请使用无参构造函数来实例化对象，此时我们将name的默认值设置为"No name",author的默认值设置为"No author",sale的默认值设置为0.

（2）当输入都为0的时候，我们使用拷贝构造函数来处理，这种情况具体在main函数中的实现是这样的：

  Book bk1;

  Book bk2(bk1);

  bk2.print();

（3）其他情况下一律用有参数的构造函数来构造对象。


输出

使用类中的void print()方法来输出一定格式的字符串，详见样例。


输入样例 1

The Art of Computer Programming
Donald Ervin Knuth
1000
输出样例 1

Name: The Art of Computer Programming Author: Donald Ervin Knuth Sale: 1000
提示

1、注意输出格式，每个图书的信息占一行，信息的项目之间用\t分隔，最后以\n换行。冒号后面都有一个空格

2、输入书名和作者时，因为会含有空格，请用cin.getline()函数，例如cin.getline(name,sizeof(name))

3、比较两个字符串是否相等，请用strcmp(s1,s2)函数，如果s1=s2，则返回0。例如strcmp(name, "-1")，如果name是“-1”，则返回值为0.

4、请注意，必须要用类（class）来实现代码，否则不得分*/

// 以下是解答
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *name;   // 书名
    char *author; // 作者
    int sale;     // 销售量
public:
    Book();                        // 无参构造函数
    Book(char *a, char *b, int c); // 有参构造函数
    Book(const Book &);            // 拷贝构造函数
    void print();                  // 显示数据
    ~Book();                       // 析构函数
};

Book::Book()
{
    name = new char[7];
    strcpy(name, "No name");
    author = new char[9];
    strcpy(author, "No author");
    sale = 0;
}

Book::Book(char *a, char *b, int sale)
{
    name = new char[strlen(a) + 1];
    strcpy(name, a);
    author = new char[strlen(b) + 1];
    strcpy(author, b);
    this->sale = sale;
}

Book::Book(const Book &book)
{
    name = new char[strlen(book.name) + 1];
    strcpy(name, book.name);
    author = new char[strlen(book.author) + 1];
    strcpy(author, book.author);
    sale = book.sale;
}
void Book::print()
{
    cout << "Name: " << name << "\tAuthor: " << author << "\tSale: " << sale << endl;
}

Book::~Book()
{
    delete[] name;
    delete[] author;
}

int main()
{
    char name[1001], author[1001];
    int sale;
    cin.getline(name, sizeof(name));
    cin.getline(author, sizeof(author));
    cin >> sale;
    // 根据输入的书名、作者和销售量，选择调用哪个构造函数，创建Book对象并调用print函数
    if (strcmp("-1", name) == 0 && strcmp("-1", author) == 0 && sale == -1)
    {
        Book book;
        book.print();
    }
    else if (strcmp("0", name) == 0 && strcmp("0", author) == 0 && sale == 0)
    {
        Book bk1;
        Book bk2(bk1);
        bk2.print();
    }
    else
    {
        Book book(name, author, sale);
        book.print();
    }
    return 0;
}