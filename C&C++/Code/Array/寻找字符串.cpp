#include <iostream>
using namespace std;
int main() {
    int i, j, a, pos;
    a = 0, pos = 0;
    char str1[20] = {0};
    char str2[10] = {0};
    gets(str1);
    gets(str2);
    for (i = 0; i < 19 && str1[i] != '\0'; i++) {
        if (str1[i] == str2[0]) {
            a = 0;
            for (j = 0; str2[j] != '\0'; j++) {
                if (str1[i + j] == str2[j]) {
                    a = 1;
                    pos = i + 1;
                } else {
                    a = 0;
                    break;
                }
            }
            if (a == 1)
                printf("%d\n", pos);
        }
    }
    return 1;
}
