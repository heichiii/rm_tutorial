#include <stdio.h>
#include <stdlib.h>


// 比较函数：整型升序排序
int compare_int_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
    //return (*(int*)b - *(int*)a); //降序
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int count = sizeof(arr) / sizeof(arr[0]);  // 计算数组元素个数
    
    // 升序排序
    qsort(arr, count, sizeof(int), compare_int_asc);
    
    printf("升序排序结果: ");
    for(int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}