#include <stdio.h>
#define M_PI       3.14159265358979323846

int main(){
    int n;
    double a;
    double b;
    scanf("%d",&n);
    a = M_PI * n * n;
    b = n * n * 2;
    printf("%6f\n", a);
    printf("%6f",b);
    return 0;
}