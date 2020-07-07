#include <stdio.h>

void merge(int data[][2], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[100001][2]; // 새 배열
    while(i<=q && j<=r) {
        if(data[i][1] < data[j][1]){
            tmp[k][0] = data[i][0];
            tmp[k][1] = data[i][1];
            k++;
            i++;
        }
        else if (data[i][1] == data[j][1]){
            if(data[i][0] < data[j][0]){
                tmp[k][0] = data[i][0];
                tmp[k][1] = data[i][1];
                k++;
                i++;
            } else {
                tmp[k][0] = data[j][0];
                tmp[k][1] = data[j][1];
                k++;
                j++;
            }
            
        }
        else {
            tmp[k][0] = data[j][0];
            tmp[k][1] = data[j][1];
            k++;
            j++;
        }
    }
    while(i<=q){
        tmp[k][0] = data[i][0];
        tmp[k][1] = data[i][1];
        k++;
        i++;
    }
    while(j<=r){
        tmp[k][0] = data[j][0];
        tmp[k][1] = data[k][1];
        k++;
        j++;
    }
    for(int a = p; a<=r; a++){
        data[a][0] = tmp[a][0];
        data[a][1] = tmp[a][1];
    }
}

void mergeSort(int data[][2], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}

int main(){
    int n=0, size=0, value=0;
    int con[100001][2];
    int count = 0;
    int clock = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&con[i][0], &con[i][1]);
    }
    mergeSort(con,0,n-1);
    for(int i=0;i<n;i++){
        if(con[i][0] >= clock){
            clock = con[i][1];
            count++;
        }
    }
    printf("%d",count);
    return 0;
}