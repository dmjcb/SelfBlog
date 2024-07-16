/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:36:23
 */
#include<bits/stdc++.h>
using namespace std;
class Student {
    public:
        Student() {}
        void inputValue() {
            cin>>name>>num;
        }
        void ouputValue() {
            cout<<name<<" "<<num<<endl;
        }
        ~Student() {}
    private:
        string name;
        int  num;
};

void inputValue(vector< Student> &v) {
    class Student stu;
    int temp;
    cout<<"??????????????????:";
    cin>>temp;
    for(int i=0; i<temp; i++) {
        cout<<"???????"<<i+1<<"????????";
        stu.inputValue();
        v.push_back(stu);
    }
}

void ouputValue(vector< Student> &v) {
    for(vector< Student>::iterator it=v.begin(); it!=v.end(); it++) {
        it->ouputValue();
    }
}


int main() {
    //????????????
    vector<class Student> value;
    inputValue(value);
    ouputValue(value);
    return 0;
}
