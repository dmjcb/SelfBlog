#include<iostream>
using namespace std;
int main(){
    int a[5]={1,5,2,3,8};
    int min1 =a[0];
    int index1,index2;
    index1 = 0;
    for(int i =1;i<5;i++){
        if(a[i]<min1){
            min1 = a[i];
            index1 =i;
        }
    }
    if(index1==0){
        index2=1;
    }
    else{
        index2 = 0;
    }
    int min2 = a[index2]; 
    for(int i =0;i<5;i++){
        if(i!=index1&&a[i]<min2){
            min2 = a[i];
        }
    }
    cout<<min1<<" "<<min2<<endl;
}
