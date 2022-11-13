#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Person
{
public:
    void input() //输入人员
    {
        cin >> name >> age;
    }
    void output() //输出人员
    {
        cout << setw(6) << name << setw(3) << age << endl;
    }

protected:
    string name;
    int age;
};

class Student : public Person
{
public:
    void input() //输入学生
    {
        cin >> id;
        Person::input();
    }
    void output() //输出学生
    {
        cout << setw(3) << id;
        Person::output();
        cout << endl;
    }
    bool cmpName(Student &stu) //比较姓名
    {
        if (this->name > stu.name)
        {
            return true;
        }
        return false;
    }
    bool cmpAge(Student &stu) //比较年龄
    {
        if (this->age > stu.age)
        {
            return true;
        }
        else if (this->age == stu.age)
        { //年龄相同，比较姓名
            return this->cmpName(stu);
        }
        return false;
    }
    void swap(Student &stu) //交换对象
    {
        Student temp;
        temp = *this;
        *this = stu;
        stu = temp;
    }

private:
    int id;
};

void sortStudents(Student stu[], int n, bool bename) // bename为true按姓名排序，否则按年龄排序
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bename)
            {
                if (stu[j].cmpName(stu[j + 1]))
                {
                    stu[j].swap(stu[j + 1]);
                }
            }
            else
            {
                if (stu[j].cmpAge(stu[j + 1]))
                {
                    stu[j].swap(stu[j + 1]);
                }
            }
        }
    }
}

void getStudents(Student stu[], int n)
{
    for (int i = 0; i < n; i++)
        stu[i].input();
}
void showStudents(Student stu[], int n)
{
    for (int i = 0; i < n; i++)
        stu[i].output();
}

int main()
{
    int n;
    Student stu[50];
    cin >> n;                    //输入n
    getStudents(stu, n);         //输入n个学生
    sortStudents(stu, n, true);  //姓名排序
    showStudents(stu, n);        //输出n个学生
    sortStudents(stu, n, false); //年龄排序
    showStudents(stu, n);        //输出n个学生
}
