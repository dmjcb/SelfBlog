#include<iostream>
using namespace std;
int main() {
    int strcmp(char *p1,char *p2);
    string str1,str2;
    char *p1,*p2;
    cin>>str1;
    cin>>str2;
    p1=&str1[0];
    p2=&str2[0];
    cout<<strcmp(p1,p2)<<endl;
}

int strcmp(char *p1,char *p2) {
    int i=0;
    while(*(p1+i)==*(p2+i)) {
        //两个字符串完全相等
        if(*(p1+i++)=='\0') {
            return 0;
        }
    }
    return (*(p1+i)-*(p2+i));
}
