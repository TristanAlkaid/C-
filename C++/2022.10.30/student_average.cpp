#include <iostream>
#include <string>

#define N 100
using namespace std;

class student
{
public:
    student(string id = "", int score = 0) : id(id), score(score) {}
    void Set(string id1, int score1)
    {
        id = id1;
        score = score1;
    }
    friend double average(student *p, int count);

private:
    string id;
    int score;
};

double average(student *p, int count)
{
    double top1;
    int add = 0;
    for (int i = 0; i < count; i++)
    {
        add += p[i].score;
    }
    top1 = (double)add / (double)count;
    return top1;
}

int main()
{
    student stu[N];
    string id;
    int score, total = 0;
    double aver;
    cin >> id;
    while ((id != "0") && total < N)
    {
        cin >> score;
        stu[total].Set(id, score);
        total++;
        cin >> id;
    }
    aver = average(stu, total);
    cout << aver;
    return 0;
}