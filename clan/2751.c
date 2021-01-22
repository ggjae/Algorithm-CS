#include <stdio.h>
#include <stdlib.h>

// 오름차순으로 정렬할 때 사용하는 비교함수
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    int* arr;
    arr = (int*) malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    // 정렬 후
    for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
    free(arr);
    return 0;
}