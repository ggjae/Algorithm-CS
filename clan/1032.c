#include <stdio.h>
#include <string.h>
int main() {
	char q[51][51];
    char a[51];
	int sumc = 0;
    int n;
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",q[i]);
    }
    strcpy(a, q[0]);
    int len = strlen(a);
    for(int i =0;i<len;i++){
        for(int j=0;j<n;j++){
            if(a[i] != q[j][i]){
                a[i] = '?';
            }
        }
    }
	printf("%s",a);
	return 0;
}
