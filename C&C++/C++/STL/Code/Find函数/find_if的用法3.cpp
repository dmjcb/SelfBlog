#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

class Student
{
public:
    Student() {}
    Student(string iname, float iscore) : name(iname), score(iscore) {}
    ~Student() {}

    string name;
    float score;
};

class StudentAdapter : public unary_function<Student, bool>
{
private:
    float score;

public:
    explicit StudentAdapter(float isore) : score(isore) {}
    //()
    bool operator()(const Student &student)
    {
        return (student.score == score);
    }
};

int main()
{
    vector<Student> v;
    vector<Student>::iterator it;
    Student stu1("lanzhihui", 89.1);
    Student stu2("wangdan", 89.2);
    Student stu3("wangqian", 89.3);
    v.push_back(stu1);
    v.push_back(stu2);
    v.push_back(stu3);

    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << it->name << " " << it->score << endl;
    }
    cout << endl;

    // ʵfind_if
    cout << "ɼ";
    float s;
    cin >> s;
    it = find_if(v.begin(), v.end(), StudentAdapter(s));

    if (it != v.end())
    {
        cout << "ҵ" << endl;
        cout << it->name << " " << it->score << endl;
    }

    system("pause");
    return 0;
}
