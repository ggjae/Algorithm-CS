#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* s1, const void* s2)
{
    if(strlen(s1)<strlen(s2)){
        return -1;
    }
    else if(strlen(s1) == strlen(s2)){
        return strcmp((char *)s1, (char *)s2);
    } else {
        return 1;
    }
	
}

int main() {
    char word[20001][51];
    int n,minlength;
    minlength = 51;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",word[i]);
    }
    qsort(word, n, sizeof(word[0]),compare);
    for (int i = 0; i < n; i++){
        if(strcmp(word[i],word[i+1]) == 0){
            continue;
        } else{
            printf("%s\n", word[i]);
        }
    }
		
    return 0;
}
