#include <iostream>
#include <string>

using namespace std;

class  person
{
public:
        person()
        {
            cout<<"Input id:";
            cin>>id;
            cout<<"Input name:";
            cin>>name;
        }
        void  display()
        {
            cout<<"Id:"<<id<<endl;
            cout<<"Name:"<<name<<endl;
        }
private:
        string  id;
        string  name;
};

class student : public person
{
private:
    string classID;
    double grade;

public:
    student(): person()
    {
        cout << "Input class:";
        cin >> classID;
        cout << "Input score:";
        cin >> grade;
    }
    void display()
    {
        cout << "Student's info:" << endl;
        person::display();
        cout << "Class:" << classID << endl;
        cout << "Score:" << grade << endl;
    }
};


class teacher : public person
{
private:
    string Title;
    string department;

public:
    teacher(): person()
    {
        cout << "Input title:";
        cin >> Title;
        cout << "Input department:";
        cin >> department;
    }
    void display()
    {
        cout << "Teacher's info:" << endl;
        person::display();
        cout << "Title:" << Title << endl;
        cout << "Department:" << department ;
    }
};

int  main()
{
        student  stu;
        teacher  tea;
        stu.display();
        tea.display();
        return  0;
}
