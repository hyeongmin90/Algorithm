#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    int a,i,b;
    
    scanf("%d", &a);
    b = 0;
    for (i = 1; i <= a; i++) {
       
        b += i;
    }
    printf("%d", b);

    return 0;
}
