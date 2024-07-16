#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ofstream outfile;      // ն--ڴ--ı
    outfile.open("2.txt"); //() ļ
    if (!outfile)
        cout << "error" << endl;

    string str;
    int t1;
    int i = 0;
    while (cin >> t1)
    { // ոȡհ׷
        if (i != 0 && i % 3 == 0)
            outfile << "\n";
        outfile << t1 << " ";
        i++;
    }

    outfile.close();
    return 0;
}
