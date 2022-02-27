#include <stdio.h>
#include <stdlib.h>

#define PACK(size, alloc) ((size) | (alloc))
const int SIZE = 5;

int main(){
    int arr[SIZE]; // valid
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", arr+i);
    }
    printf("Num arr:\n");
    for (int j = 0; j < SIZE; ++j) {
        printf("%d", arr[j]);
    }
    printf("\n");

    int* ptr = (int*)malloc(4);
    int val = 1;
    (*(unsigned int *)(ptr)) = val;
    (*(unsigned int *)(ptr)) = PACK(2,1);
    printf("%p, %p, %u\n", ptr, &ptr, *ptr);

    return 0;
}