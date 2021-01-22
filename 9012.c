#include <stdio.h>
char a[1000000][51];
int flag = 0;
int main(){
    int b,n;
    scanf("%d",&n);
    while(getchar() != '\n');
    for(int i=0;i<n;i++){
        int counta = 0;
        int realcounta = 0;
        int realcountb = 0;
        int countb = 0;
        for(int j =0;j<50;j++){
            scanf("%c",&a[i][j]);
            if(a[i][j] == '\n'){
                if(counta == countb && realcounta == realcountb){
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
                break;
            }
            if(a[i][j] == '('){
                flag = 1;
                counta++;
                realcounta++;
            } if (counta == countb){
                flag = 0;
            } if(a[i][j] == ')' && flag == 1){
                countb++;
                realcountb++;
            } if(a[i][j] == ')' && flag == 0){
                realcountb++;
            }
        }
    }
    return 0;
}