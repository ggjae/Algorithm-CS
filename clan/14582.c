#include <stdio.h>
int main(){
    int flag = 0;
    int suma = 0;
    int sumb = 0;
    int a[10];
    int b[10];
    for(int i=0;i<9;i++){
        scanf("%d",&a[i]);
    }for(int i=0;i<9;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<9;i++){
        suma += a[i];
        if(suma > sumb){
            flag = 1;
        } 
        sumb += b[i];
    }
    if (sumb > suma && flag == 1){
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}