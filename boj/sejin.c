#include <stdio.h>

int gcd1(int a, int b)
{
    int x,y;
    if (a>=b){
        x = a, y = b;
    }
    else{
        x = b, y = a;
    }
    int tmp;
    while (y != 0)
    {
        tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

int lcm1(int a, int b)
{
    int gcd = gcd1(a, b);
    int n1, n2;
    n1 = a/gcd, n2 = b/gcd;
    int lcm = gcd * n1 * n2;
    return lcm;
}

void main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans1 = gcd1(a,b);
    int ans2 = lcm1(a,b);
    printf("%d\n", ans1);
    printf("%d", ans2);
}