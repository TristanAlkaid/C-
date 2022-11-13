#include <iostream>
#include <string>

using namespace std;

class MyChar
{
public:
    MyChar() : num(0) {}
    char ch; //字符
    int num; //出现次数
};

class MyString : public string
{
public:
    void input()
    {
        getline(cin, *this); //输入一行，支持空格
        sum = 0;
    }
    void putchar(char ch); //放入字符
    void compute();
    void output();

private:
    MyChar chars[300]; //字符计数
    int sum;
};

//添加你的代码
void MyString::putchar(char ch)
{
    for (int i = 0; i < sum; i++)
    {
        if (chars[i].ch == ch)
        {
            chars[i].num++;
            return;
        }
    }
    chars[sum].ch = ch;
    chars[sum].num++;
    sum++;
}

void MyString::compute()
{ //分析字符出现频次
    for (auto i : (*this))
        putchar(i);
}
void MyString::output()
{
    int judge[sum + 5];
    for (int i = 0; i < sum; i++)
        judge[i] = 0;
    for (int i = 0, tag = 0; i < sum; i++)
    {
        int pos = -1, rec = 0;
        for (int j = 0; j < sum; j++)
        {
            if (judge[j])
                continue;
            if (chars[j].num > rec)
                pos = j, rec = chars[j].num;
        }
        judge[pos] = 1;
        cout << chars[pos].ch << "-" << chars[pos].num;
        if (++tag == 4)
            cout << endl;
        else 
            cout << " ";
        tag %= 4;
    }
}

//使得程序正确执行
int main()
{
    MyString s;
    s.input();
    s.compute();
    s.output();
    return 0;
}