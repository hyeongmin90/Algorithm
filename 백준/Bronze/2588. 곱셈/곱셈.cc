#include <iostream>

using namespace std;

int main()
{
    long long int a, b,c, q, w, e;
    scanf("%lld %lld", &a,&b);
    

    c = b;
    q = c / 100;
    c %= 100;

    w = c / 10;
    
    e = c % 10;

    printf("%lld\n%lld\n%lld\n%lld\n",a*e,a*w,a*q,a*b);
    

    return 0;
}
