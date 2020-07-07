#include <stdio.h>

char arr[2187][2187];
void blank(int x, int y, int n){
    if(n == 1){
        arr[y][x] = ' ';
    } else {
        blank(x + n/3, y + n/3, n/3);
    }
}
void star(int x, int y, int n) {
	if (n == 1) {
		arr[y][x] = '*';
	}
	else {
		star(x, y, n / 3);                         // 1.1
		star(x + n / 3, y, n / 3);                 // 1.2
		star(x + n / 3 * 2, y, n / 3);             // 1.3

		star(x, y + n / 3, n / 3);                 // 2.1
        blank(x + n/3, y + n/3, n/3);
		star(x + n / 3 * 2, y + n / 3, n / 3);     // 2.3

		star(x, y + n / 3 * 2, n / 3);             // 3.1
		star(x + n / 3, y + n / 3 * 2, n / 3);     // 3.2
		star(x + n / 3 * 2, y + n / 3 * 2, n / 3); // 3.3
	}
}
int main(void) {
	int size;

	scanf("%d", &size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            arr[i][j] = ' ';
        }
    }
	star(0, 0, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

