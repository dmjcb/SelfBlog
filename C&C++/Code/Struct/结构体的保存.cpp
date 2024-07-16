#include <bits/stdc++.h>
#define SIZE 3
using namespace std;
struct Stu
{
    char name[20];
    long num;
    int age;
} stu[SIZE];
void saveFile()
{
    FILE *fp;
    if ((fp = fopen("stu.txt", "wb")) == NULL)
    {
        cout << "cannot open file" << endl;
        exit(0);
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (fwrite(&stu[i], sizeof(struct Stu), 1, fp) != 1)
        {
            cout << "file write error" << endl;
        }
    }
    fclose(fp);
}
int main()
{
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> stu[i].name >> stu[i].num >> stu[i].age;
    }
    saveFile();
    return 0;
}
