#include <stdio.h>

typedef struct {
    int a;
    int b;
} Stu;

Stu getStu(int x, int y) {
    Stu result;
    result.a = x;
    result.b = y;
    return result;
}

int main() {
    int a = 2, b = 3;
    Stu test = getStu(a, b);
    printf("%d %d\n", test.a, test.b);
    return 0;
}

