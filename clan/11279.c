#include <stdio.h>

#define MAX_ELEMENT 100001

int key;

int heap[MAX_ELEMENT];
int heap_size = 0;
void insert_max_heap(int item)
{
    int i;
    heap_size += 1;
    i = heap_size;
    while((i != 1) && (item > heap[i/2])){
        heap[i] = heap[i/2];
        i /=2;
    }
    heap[i] = item;
}

int delete_max_heap()
{
    int parent, child;
    int item, temp;
    item = heap[1];
    temp = heap[(heap_size)--];
    parent = 1;
    child = 2;  
    while(child <= heap_size){
        if((child < heap_size) && (heap[child]) < (heap[child+1]))
            child++;
        if(temp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *=2;
    }
    heap[parent] = temp;

    return item;

}

int main()

{
    heap_size = 0;
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a == 0){
            if(heap_size == 0){
                printf("0\n");
            } else {
                printf("%d\n",delete_max_heap());
            }
        } else {
            insert_max_heap(a);
        }
    }
    return 0;
}
