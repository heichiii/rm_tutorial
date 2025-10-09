#include <stdio.h>
#include <stdlib.h>

int global_var = 50; // 定义并初始化全局变量

void modify_global(void) 
{
    global_var = 200; // 修改全局变量
}

int main() 
{
    printf("修改前全局变量: %d\n", global_var);  // 50
    modify_global();
    printf("修改后全局变量: %d\n", global_var);  // 200
    return 0;
}