#include <stdio.h>
int main()
{
    int c;
    int n = 0; // n==1´οԳֿո
    while ((c = getchar()) != EOF)
    {
        // ǰǿո
        if (c != ' ')
        {
            // ´γһո
            n = 1;
            putchar(c);
        }
        // ǵһγֵĿո
        else if (c == ' ' && n == 1)
        {
            putchar(c);
            // һǿո
            n = 0;
        }
    }
    return 0;
}
