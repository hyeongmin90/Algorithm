#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    int a,i;
    scanf("%d", &a);
    for (i = 1; i <= 9; i++)
        printf("%d * %d = %d\n", a, i, a * i);


    return 0;
}
