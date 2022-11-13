#include <iostream>
#include <string>

using namespace std;

class Document
{ 
private:
    string name;

public:
    Document(string nam) : name(nam) //构造函数，构造Document()函数
    {
        cout << "Name:" << name << endl;
    }
    ~Document() {} //析构函数，释放内存
};

class Book : public Document
{ 
private:
    int pageCount;

public:
    Book(string nam, int ag) : Document(nam), pageCount(ag) //构造函数，构造派生类的对象
    {
        cout << "Page:" << pageCount << endl;
    }
    ~Book() {}
};

int main()
{
    int page;
    string name;
    cout << "Input Name and Page:";
    cin >> name >> page; //输入name和page
    Book b(name, page);  //传递参数
    return 0;
}
