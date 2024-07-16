#include<iostream>
using namespace std;
int main() {
    int a,min,max,i,j,sum;
    bool b=false;
    cin>>a;
    max=a/2;
    min=a/4;
    for(i=0; i<=a; i+=2) {
        for(j=0; j<=a; j+=4) {
            if(i+j==a) {
                b=true;
                if(i<j) {
                    sum=i/2+j/4;
                    if(sum<min) {
                        min=sum;
                    }
                } else if(i>=j) {
                    sum=i/2+j/4;
                    if(sum>max) {
                        max=sum;
                    }
                }
            }
        }
    }
    if(b==false) {
        cout<<"0 0"<<endl;
    } else {
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
