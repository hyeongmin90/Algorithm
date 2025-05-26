#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    scanf("%d %d", &a,&b);
    
    if (b >= 45)
        b -= 45;
    else {
        b = 60 - (45 - b);
        if (a != 0)
            a -= 1;
        else a = 23;
    }
    printf("%d %d", a, b);
    return 0;
}
