#include <stdio.h>
int main(){
    int a,b;
    int flag;
    int sum=0;
    int fla=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        flag = 0;
        for(int j=2;j<i;j++){
            if(i%j == 0){
                flag = 1;
            }
        }
        if(fla == 0 && flag == 0 && i != 1){
            sum += i;
            fla = i;
        }
        else if(flag == 0 && i != 1){
            sum += i;
        }
    }
    if(sum == 0){
        printf("-1");
    }else {
        printf("%d\n",sum);
        printf("%d",fla);
    }

}