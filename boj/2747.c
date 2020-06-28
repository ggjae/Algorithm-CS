#include <stdio.h>
int main(){
    unsigned long long int n;
    scanf("%lld",&n);
    if (n <= 1)
        printf("%lld",n);
    else{
        unsigned long long int acc = 1;
        unsigned long long int prev = 0;
        while (n-- > 1) {
            unsigned long long int temp = acc;
            acc += prev;
            prev = temp;
        }
        printf("%lld",acc);
    }
    return 0;
}