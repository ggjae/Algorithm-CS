#include <stdio.h>
int main(){
    int n;
    char num_a_[1000];
    char num_b_[1000];
    char result[1001];
    scanf("%s",num_a_);
    scanf("%s",num_b_);
    sprintf_s(num_a_, sizeof(num_a_), "%0999s", num_a);
    sprintf_s(num_b_, sizeof(num_b_), "%0999s", num_b);
    printf("%s\n", num_a_);
    printf("%s\n", num_b_);
    printf("%lld",a[n]);
    return 0;
}