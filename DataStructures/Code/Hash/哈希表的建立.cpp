#include<stdio.h>
#include<iostream>
#include<malloc.h>
//哈希表表长
#define HASH_TABLE_LENGTH 50
//人名最大个数
#define NAME_MAX_TOTAL 30
//除数
#define M 47
using namespace std;
typedef struct {
    //用户的名字
    string name;
    //该名字所对应的关键字
    int keyword;
} NameList ;
 

typedef struct {
    NameList nameUnit;
    //查找次数
    int LookupsNumber;
} HashTable ;

void initializeNameList(NameList nameUnit[]) {
    nameUnit[0].name = "Addison";
    nameUnit[1].name = "Albert";
    nameUnit[2].name = "Alfred";
    nameUnit[3].name = "Barton";
    nameUnit[4].name = "August";
    nameUnit[5].name = "Charles";
    nameUnit[6].name = "Paul";
    nameUnit[7].name = "Georg";
    nameUnit[8].name = "Michael";
    nameUnit[9].name = "Elizabeth";
    nameUnit[10].name = "Kate";
    nameUnit[11].name = "Sarah";
    nameUnit[12].name = "Tiffany";
    nameUnit[13].name = "Nancy";
    nameUnit[14].name = "Thomas";
    nameUnit[15].name = "Jack";
    nameUnit[16].name = "Clark";
    nameUnit[17].name = "Johnson";
    nameUnit[18].name = "Tayler";
    nameUnit[19].name = "Hugo";
    nameUnit[20].name = "Gino";
    nameUnit[21].name = "Gavin";
    nameUnit[22].name = "Garfield";
    nameUnit[23].name = "Frank";
    nameUnit[24].name = "Bob";
    nameUnit[25].name = "Anthony";
    nameUnit[26].name = "Alva";
    nameUnit[27].name = "Jesse";
    nameUnit[28].name = "Isaac";
    nameUnit[29].name = "Harrison";
    for(int i = 0 ; i<NAME_MAX_TOTAL ; i++) {
        //sum代表该人名字各字符的ASCLL码值之和
        int sum = 0;
        for(int j = 0 ; j< nameUnit[i].name.size() ; j++) {
            sum += nameUnit[i].name[j];
        }
        //更新关键字
        nameUnit[i].keyword = sum;
    }
}

//建立哈希表 , m为散列函数中的被除数
void creatHashTable(HashTable hashUnit[], NameList nameUnit[]) {
    //哈希表初始化
    for(int i = 0 ; i < HASH_TABLE_LENGTH ; i++) {
        hashUnit[i].nameUnit.name = "";
        hashUnit[i].nameUnit.keyword = 0;
        hashUnit[i].LookupsNumber = 0;
    }

    //构建哈希表
    //遍历每一个姓名单元,将它们插入到哈希表上去
    for(int  i = 0 ; i<NAME_MAX_TOTAL ; i++) {
        //initialAddress代表该姓名单元最初储存地址,其值为姓名单元的关键码keyword % m
        int initialAddress = nameUnit[i].keyword % M;
        //ultimaAddress代表其最终储存地址,初始时两地址相等
        int ultimaAddress =  initialAddress;
        //如果哈希表上该最初地址上的查找次数为0,说明该位置并未插入关键码
        if(hashUnit[initialAddress].LookupsNumber == 0) {
            //将该姓名单元的关键码插入哈希表
            hashUnit[initialAddress].nameUnit.keyword = nameUnit[i].keyword;
            //更新哈希表上该位置的姓名
            hashUnit[initialAddress].nameUnit.name = nameUnit[i].name;
            //该关键码的查找次数为1
            hashUnit[initialAddress].LookupsNumber = 1;
        }
        //否则说明发生了"冲突"
        else {
            ////线性探测法解决冲突,sum代表总查找次数
            int sum = 0;
            //当最终位置上的关键码不为零时继续探查
            do {
                ultimaAddress = (ultimaAddress + 1) % HASH_TABLE_LENGTH;
                sum++;
            } while(hashUnit[ultimaAddress].nameUnit.keyword != 0);
            //找到插入位置之后,更新哈希表上的关键字名字
            hashUnit[ultimaAddress].nameUnit.keyword = nameUnit[i].keyword;
            hashUnit[ultimaAddress].nameUnit.name =  nameUnit[i].name;
            //更新查找次数
            hashUnit[ultimaAddress].LookupsNumber = sum + 1;
        }
    }
}

//计算ASL值
double averageSearchLength(HashTable hashUnit[]) {
    double sum = 0;
    for(int i = 0 ; i<HASH_TABLE_LENGTH ; i++) {
        //累加查找次数不为0的项
        if(hashUnit[i].LookupsNumber != 0) {
            sum += hashUnit[i].LookupsNumber;
        }
    }
    return sum/NAME_MAX_TOTAL;
}

void disPlay(HashTable hashUnit[]) {
    cout << "序号" << "\t" << "关键字" << "\t\t" <<
         "搜索次数" << "\t" << "H(key)" << "\t\t" << "姓名" << endl;
    for (int i = 0; i<HASH_TABLE_LENGTH; i++) {
        cout << i << "\t" << hashUnit[i].nameUnit.keyword << "\t\t" << hashUnit[i].LookupsNumber << "\t\t"
             << (hashUnit[i].nameUnit.keyword) % M << "\t\t" << hashUnit[i].nameUnit.name << endl;
    }
}


int main() {
    
    HashTable hashUnit[HASH_TABLE_LENGTH];
    NameList nameUnit[30]; 
    initializeNameList(nameUnit);
    creatHashTable(hashUnit,nameUnit);
    disPlay(hashUnit);
    cout<<averageSearchLength(hashUnit)<<endl;
}
