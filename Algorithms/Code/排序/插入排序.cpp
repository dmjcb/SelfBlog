/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:05:34
 */
#include<iostream>
#define LEN sizeof(a)/sizeof(a[0])
using namespace std;
int main() {
    int a[]= {12,2,16,30,28,10,16,20,6,18};
    int i,j,temp;
    int c = 0,b = 0;
    //循环从第2个元素开始
    for(i=1; i<LEN; i++) {
        //前一个元素比后一个元素大 
        if(a[i-1] > a[i]) {
            c++;
            temp=a[i];
            //从前一个元素位置开始,若未到表头且当前位置元素大于待插入元素temp 
            for(j = i-1; j >= 0 && temp < a[j]; j--) {
                //所有元素依次向后移动 
                a[j+1] = a[j];
                b++;
            }
            //此处就是为插入留出的空(退出循环时j会多减1)
            //cout<<"插入位置为"<<j+1<<endl; 
            a[j+1] = temp;
            for(int i = 0 ; i<LEN ;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"查找次数"<<c<<endl;
    cout<<"移动次数"<<b<<endl;
    for(i=0; i<LEN; i++) {
        cout<<a[i]<<"  ";
    }
    return 0;
}
