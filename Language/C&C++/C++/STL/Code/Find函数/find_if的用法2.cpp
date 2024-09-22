/*
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-10 02:06:36
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-22 01:42:45
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

class Student {
    public:
        Student() {}
        Student(string iname, float iscore):name(iname),score(iscore) {}
        ~Student() {}

        string name;
        float score;
};

class StudentAdapter:public unary_function<Student,bool> {
    private:
        string name;
    public:
        explicit StudentAdapter(string iname):name(iname) {}
        // 重载()运算符
        bool operator()(const Student& s) {
            return s.name == name;
        }
};

int main() {
    vector<Student> v = {Student("A",89.1), Student("B",89.1), Student("C",89.1)};

    string str = "";

    auto it = std::find_if(v.begin(),v.end(),StudentAdapter(str));

    if(it != v.end()) {
        cout<<it->name<<" "<<it->score<<endl;
    }

    system("pause");
    return 0;
}

