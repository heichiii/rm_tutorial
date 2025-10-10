#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40, e = 50, f = 60, g = 70, h = 80;
    int arr[2][4] = {{a, b, c, d}, 
                     {e, f, g, h}};
    // 创建一个包含8个int指针的数组
    int (*p1)[4] = arr;
    
    // p2 指向整个这个数组
    int*(*p2)[4] = &p1;
    
    // 访问方式：
    printf("第一个元素的值: %d\n", *(*p2)[0]);  // 输出10
    printf("第二个元素的值: %d\n", *(*p2)[1]);  // 输出20
    
    // 也可以这样理解：
    int* (*ptr_to_array)[4] = &arr;
    
    return 0;
}