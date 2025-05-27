#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e;
    scanf("%d %d", &a,&b);
    scanf("%d", &c);

    if ((b + c) < 60) {
        b += c;
    }
    else {
        d = (b + c) / 60;
        b = (b + c) % 60;
        
        if ((a + d) >= 24)
            a = (a + d) - 24;
        else a += d;
    }


    printf("%d %d", a, b);
    return 0;
}
