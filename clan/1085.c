#include <stdio.h>
int main() {
	int n[4];
    int d = 0;
    for(int i =0;i<4;i++){
        scanf("%d",&n[i]);
    }
	d = n[2] - n[0];
    if(d>(n[3]-n[1])){
        d = n[3] - n[1];
    }if(d > n[0]){
        d = n[0];
    }if(d > n[1]){
        d = n[1];
    }
	printf("%d",d);
	return 0;
}
