#include <stdio.h>
#include <string.h>
int main() {
	double a[1001];
    double max = 0;    
    double aver = 0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
        if(a[i]>max){
            max = a[i];
        }
    }
    for(int i=0;i<n;i++){
        aver = aver + ((a[i]/max) * 100);
    }
    printf("%lf",aver/n);
    return 0;
}