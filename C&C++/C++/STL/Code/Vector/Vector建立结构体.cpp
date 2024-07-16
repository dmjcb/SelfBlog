#include <bits/stdc++.h>
using namespace std;
typedef struct Student
{
    string name;
    int num;
} Student;

void inputValue(vector<Student> &v)
{
    Student stu;
    int temp;
    cout << "Ҫӵ:";
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        cin >> stu.name >> stu.num;
        v.push_back(stu);
    }
}

void ouputValue(vector<Student> &v)
{
    for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->name << " " << it->num << endl;
    }
}

int main(int argc, char *args[])
{
    // һṹ
    vector<Student> value;
    inputValue(value);
    ouputValue(value);
    return 0;
}
