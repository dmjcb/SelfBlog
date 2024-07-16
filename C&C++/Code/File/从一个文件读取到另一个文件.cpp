#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    ifstream myfile("2.txt");
    ofstream outfile("3.txt", ofstream::app);
    string temp;
    if (!myfile.is_open())
    {
        cout << "δɹļ" << endl;
    }
    while (getline(myfile, temp))
    {
        outfile << temp;
        cout << temp << endl;
    }
    myfile.close();
    return 0;
}
