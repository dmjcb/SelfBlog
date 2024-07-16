#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char *s1 = "1234567890";
    char *s2 = "32";
    int length = strcspn(s1,s2);
    cout<<length<<endl;
    return 0;
}
