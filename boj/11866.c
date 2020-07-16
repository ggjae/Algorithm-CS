#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, m;
    int *seq, t = 0;
    int *josephus, q = 0;
    int count = 0;
 
    scanf("%d %d",&n,&m);
    seq = (int *)malloc(sizeof(int)*n);
    josephus = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n;i++) {
        seq[i] = i+1;
    }
 
    while (q < n) {
        if(seq[t]!= 0) count++;
    
        if (count == m) {
            count = 0;
            josephus[q++] = seq[t];
            seq[t] = 0;
        }
        t = (t+1)%n;
    }
    printf("<");
    for (int i = 0; i < q;i++) {
        if(i<q-1)    printf("%d, ",josephus[i]);
        else printf("%d>\n", josephus[i]);
    }
 
    return 0;
}
