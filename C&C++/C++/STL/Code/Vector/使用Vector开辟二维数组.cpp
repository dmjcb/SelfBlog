/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:37:06
 */
#include<iostream>
#include<vector>
using namespace std;
/*
二维向量的输入问题：
不像二维数组那样，可以直接对arr[i][j]进行循环赋值。在
vector<vector<int>>中，因为vector是一个容器，最外层的
vector容器中放着更小的vector，而里层的vector里面放的是
int型的数字。所以我们首先要对里层的vector容器赋值，再
把里层的vector作为元素插入到外层的vector中。
代码如下：
*/
int main() {
    vector<vector<int> >test;
    vector<int> v;
    int n,m,temp;
    cout<<"输入两个维度：";
    cin>>n>>m;
    test.clear();
    //输入
    for(int i = 0; i<n; i++) {
        //每次记得clear,以便存放下一组对里层的vector容器的赋值
        v.clear();
        for(int j = 0; j<m; j++) {
            cin>>temp;
            v.push_back(temp);
        }
        //把内层插好的一行插入外层中
        test.push_back(v);
    }
    //输出
    cout<<"数组为："<<endl;
    /*
    
    for(vector<vector<int> >::iterator it = test.begin();it!=test.end();it++){
        for(vector<int>::iterator jt=v.begin();jt!=v.end();jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }

}

/*
    int X,Y,i,j;
    cout<<"输入一二维的大小:";
    cin>>X>>Y;
    vector< vector<int> > a(X,vector<int>(Y));
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
        cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
*/
