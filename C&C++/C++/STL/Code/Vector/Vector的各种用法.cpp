/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-08 21:24:12
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//沥遍1  迭代器法
template <typename T>
void showvector(vector<T> v) {
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it<<" ";
    }
    cout << endl;
}


int main() {
    vector<string> v6 = { "hi","my","name","is","lee" };
    v6.resize(3);                    //重新调整vector容量大小
    cout<<"重新调整vector容量大小的v6:";
    showvector(v6);
    vector<string> v11 = {"HELLO","sa","wdasdas","sdaAAA"};
    v11.erase(v11.begin()+2,v11.end()-1);  //删除之间的元素，其他元素前移
    showvector(v11);                       //HELLO sa wdasdas"
    vector<int> v5 = { 1,2,3,4,5 };        //列表初始化,注意使用的是花括号
    cout <<"v5的第一个元素: "<< v5.front() << endl;       //访问第一个元素
    cout <<"v5的最后一个元素: "<<v5.back() << endl;       //访问最后一个元素
    cout<<"v5:";
    showvector(v5);
    v5.pop_back();                   //删除最后一个元素
    cout<<"删除最后一个元素后的v5:";
    showvector(v5);
    v5.push_back(6);                 //加入一个元素并把它放在最后
    cout<<"加入一个元素并把它放在最后的v5:";
    showvector(v5);
    v5.insert(v5.begin()+1,9);       //在第二个位置插入新元素
    cout<<"在第二个位置插入新元素9的v5:";
    showvector(v5);
    v5.erase(v5.begin() + 3);        //删除第四个元素
    cout<<"删除第四个元素的v5:";
    showvector(v5);
    v5.insert(v5.begin() + 1, 7,8);  //连续插入7个8
    cout<<"连续插入7个8后的v5:";
    showvector(v5);
    v5.clear();                      //清除所有内容
    cout<<"连清除所有内容后的v5:";
    showvector(v5);

    system("pause");
    return 0;
}
