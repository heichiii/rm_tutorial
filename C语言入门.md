# C语言入门

*参考资料：《C Primer Plus（Stephen Prata）》、《C程序设计语言 (Brian W. Kernighan, Dennis M. Ritchie) 》、[翁恺C语言_](https://www.bilibili.com/video/BV1dr4y1n7vA?spm_id_from=333.788.videopod.episodes&vd_source=4fc959a02ef946a334065d8f36a22190&p=2)*、[尚硅谷C语言零基础入门教程（宋红康c语言程序设计精讲，含C语言考研真题）_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Bh4y1q7Nt/?spm_id_from=333.337.search-card.all.click&vd_source=4fc959a02ef946a334065d8f36a22190)、[C 语言教程 | 菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)

**前置课程：C语言环境配置**

# 1.前言

## 了解计算机语言

### 解释什么是计算机语言

人类世界老板给员工下命令用的是人类听得懂的语言，如汉语英语，人给计算机下命令则是用的计算机认识的计算机语言。

计算机计算：CPU、寄存器、内存

### 计算机语言历史

**机器语言->**

```
0001100100010010
控制部分1        控制部分2       数据1      数据2
0001（算数运算）  1001（加法）    0001（1）  0010（2）
0010（逻辑运算）  1010（逻辑与）   0001（1）  0000（0） 

```

<img src="https://ts2.tc.mm.bing.net/th/id/OIP-C.03-8B5QemgHFMe6BnicY8gHaDM?rs=1&pid=ImgDetMain&o=7&rm=3" alt="【芯论语】从存储器的发展历程，看芯片对信息社会的支撑作用。 - 技术阅读 - 半导体技术" style="zoom:200%;" /> 

**汇编语言->**

```
ADD AX, BX 
```

  汇编语言：将AX和BX 中的数值相加，并且存在AX中

**高级语言：编译器、解释器->**

```
c=a+b;
```



## C语言能干什么、特点

**C语言特点：**

1.简洁高效

2.接近底层，贴近硬件，适合嵌入式开发

3.有高效的数据操控能力，如指针

4.可移植程度高

5.生成程序执行效率高

6.社区资源丰富，拥有成熟的编译器生态

![image-20250921011540281](./C语言入门.assets/image-20250921011540281.png) 

**C语言能干什么：**

1.系统软件开发，如Windows，Linux

2.应用软件开发, Adobe系列软件

3.嵌入式开发, 智能家居、机器人

4.游戏开发

<img src="https://www.w3schools.cn/wp-content/uploads/linux/linux.png" alt="Linux 教程" style="zoom:80%;" /> <img src="https://vebaike.com/uploads/202307/1688823233EEqD3Xzv.png" alt="Adobe Photoshop - 环球百科" style="zoom:150%;" /> 





## C语言历史、C标准

 <img src="https://img-blog.csdnimg.cn/img_convert/176dd1c3106047969cd26a013b478bae.png" alt="C语言程序设计入门-萌新篇_c程序设计基础-CSDN博客" style="zoom:80%;" /> ![ISO体系认证 - 东莞市安华检测技术有限公司](https://ts1.tc.mm.bing.net/th/id/R-C.7b2d811b5326c41b50ce0f8c1b7cf22e?rik=yr956ja8GV6%2bEg&riu=http%3a%2f%2fwww.anhua-lab.com%2fupfiles%2f202206%2f15%2fa0811525eac7dda51.jpg&ehk=SSA9uAqwUhAfM%2ffjMeZV3chz5nbDoGLP%2b6q83QUMnL8%3d&risl=&pid=ImgRaw&r=0)

### 1. K&R C (1978) - “经典C”

这是C语言的“非标准化”时期，由Brian Kernighan和Dennis Ritchie在《The C Programming Language》第一版中描述。它构成了C语言的基础，但缺乏现代标准的许多特性。

### 2. C89 / ANSI C 和 C90 / ISO C - **第一个官方标准**

这个版本**标准化**了C语言，消除了不同编译器之间的歧义和差异，是C语言普及的关键。

- **核心变化：**
  - **函数原型：** 引入了现代的函数声明方式，可以指定参数类型（`int func(int a, char b);`），增强了类型检查。
  - **`void` 和 `enum` 关键字：** 引入了`void`类型（用于表示无返回值函数和通用指针）和枚举类型（`enum`）。
  - **`const` 和 `volatile` 关键字：** 提供了定义常量和易失变量的能力，帮助编译器进行优化。
  - **标准库：** 定义了第一个标准库头文件（如 `<stdio.h>`, `<stdlib.h>`, `<string.h>` 等），统一了I/O、内存分配、字符串操作等函数。
  - **预处理器的增强：** 标准化了 `#elif`, `#error`, `#pragma` 等指令。

**C90和C89在技术上几乎没有区别，只是由不同组织（ANSI和ISO）发布。**

------

### 3. C99 - **重大现代化更新**

这个版本引入了许多使C语言更现代化、更强大、更易于使用的特性。

- **核心变化：**
  - **单行注释：** 引入了C++风格的 `//` 单行注释。
  - **变量声明不再限于块开头：** 可以在代码块的任何地方声明变量（类似于C++）。
  - **新的数据类型：**
    - `_Bool`: 布尔类型（需包含 `<stdbool.h>` 来使用 `bool`, `true`, `false`)。
    - `long long int` 和 `unsigned long long int`: 提供更宽的整数类型。
    - `_Complex` 和 `_Imaginary`: 支持复数和虚数运算（需包含 `<complex.h>`）。
  - **可变长度数组 (VLAs)：** 允许数组的长度在运行时决定。
  - **柔性数组成员 (Flexible Array Member)：** 允许结构体的最后一个成员是一个未指定大小的数组，用于动态内存分配。
  - **指定初始化器 (Designated Initializers)：** 允许通过指定下标或成员名来初始化数组和结构体的特定元素（如 `int a[10] = { [0] = 1, [9] = 2 };`）。
  - **复合字面量 (Compound Literals)：** 允许创建无名（匿名）的数组或结构体对象（如 `(int []){1, 2, 3}`）。
  - **`inline` 关键字：** 建议编译器将函数内联展开，以提升性能。
  - **`restrict` 指针：** 给编译器一个保证，表明该指针是访问其所指向数据的唯一方式，从而进行激进优化。

------

### 4. C11 - **专注于安全性和并发**

这个版本的重点是增加对多线程的支持和提高语言的安全性。

- **核心变化：**
  - **多线程支持：** 在标准库中引入了 `<threads.h>` 头文件，提供了线程创建/管理（`thrd_t`）、互斥锁（`mtx_t`）、条件变量（`cnd_t`）等支持。**这是C11最重要的特性之一。**
  - **泛型宏：** 引入了 `_Generic` 关键字，允许根据表达式的类型在编译时选择不同的代码段，实现了类似函数重载的功能。
  - **安全性增强函数：** 在 `<stdio.h>`, `<string.h>` 等库中引入了一系列带 `_s` 后缀的函数（如 `scanf_s`, `printf_s`, `strcpy_s`），旨在防止缓冲区溢出。但它们的接受度不如预期。
  - **匿名结构和联合：** 允许在结构体内定义无名嵌套的结构或联合，方便成员访问。
  - **快速退出：** 引入了 `_Exit()` 和 `quick_exit()` 函数，提供比 `exit()` 更快速的程序终止方式。
  - **`_Noreturn` 函数说明符：** 指明一个函数不会返回给调用者（如 `exit()` 函数）。

# 2.第一个C程序：hello world

- *如何进行“hello world”？*

## 逐行解释

**例程一：hello**

```c
#include <stdio.h> //""<>

int main() //main函数，程序的唯一入口
{
    printf("Hello, World!\n");
    return 0;
}
/*
    * 这是一个简单的C语言程序，输出"Hello, World!"到控制台。
    * 该程序使用了标准输入输出库stdio.h，并在main函数中调用printf函数来打印字符串。
    * 程序以return 0;结束，表示程序成功执行完毕。
*/
```

基础语法：

- **关键字（Keywords）**
- **标识符（Identifiers）**
- **常量（Constants）**
- **字符串字面量（String Literals）**
- **运算符（Operators）**
- **分隔符（Separators）**

## 编译（构建）

[C语言的编译过程详解 - 知乎](https://zhuanlan.zhihu.com/p/558783902)

![img](https://pic3.zhimg.com/v2-5ff07356a424fa03da6e93840b330cc8_r.jpg) 

![img](https://pica.zhimg.com/v2-f45de959011fda57a26d5dadbe46a20a_r.jpg) 

### GCC 编译流程与常用命令速查表

| 阶段           | 命令示例                         | 核心选项                                     | 作用与说明                                                   |
| :------------- | :------------------------------- | :------------------------------------------- | :----------------------------------------------------------- |
| **编译全流程** | `gcc hello.c -o hello`           | `-o <输出文件名>`                            | **最常用命令**：一步完成预处理、编译、汇编、链接，直接生成可执行文件。 |
| **分步编译**   |                                  |                                              |                                                              |
| 1. **预处理**  | `gcc -E hello.c -o hello.i`      | `-E`                                         | 执行预处理，展开宏和头文件，生成 `.i` 文件。用于调试宏定义。 |
| 2. **编译**    | `gcc -S hello.i -o hello.s`      | `-S`                                         | 将预处理后的代码编译成汇编代码，生成 `.s` 文件。             |
| 3. **汇编**    | `gcc -c hello.s -o hello.o`      | `-c`                                         | 将汇编代码汇编成机器码，生成目标文件 `.o`（或 `.obj`）。     |
| 4. **链接**    | `gcc hello.o -o hello`           | (无)                                         | 将目标文件与库文件链接，生成最终的可执行文件。               |
| **常用选项**   |                                  |                                              |                                                              |
| **调试信息**   | `gcc -g main.c -o main`          | `-g`                                         | 在可执行文件中加入**调试信息**（如 GDB 使用），便于调试。    |
| **优化级别**   | `gcc -O2 main.c -o main`         | `-O0`（默认）, `-O1`, `-O2`, `-O3`           | 设置编译优化级别。`-O2` 常用在发布版本，在优化与编译时间间取得平衡。 |
| **警告选项**   | `gcc -Wall -Wextra main.c`       | `-Wall`, `-Wextra`, `-Werror`                | **强烈推荐使用**： `-Wall`：开启大多数常用警告。 `-Wextra`：提供更多警告。 `-Werror`：将所有警告视为错误。 |
| **包含头文件** | `gcc -I./include main.c`         | `-I<目录>`                                   | 指定额外的**头文件**搜索目录。                               |
| **链接库文件** | `gcc main.c -lm -L./lib -lmylib` | `-l<库名>`, `-L<目录>`                       | **链接库**： `-lmath` 链接 `libmath.a` 或 `libmath.so`。 `-L` 指定额外的**库文件**搜索目录。 |
| **定义宏**     | `gcc -DDEBUG main.c`             | `-D<宏名>` 或 `-D<宏名>=值`                  | 在命令行中定义预处理器宏，例如 `-DDEBUG` 等效于在代码中写 `#define DEBUG`。 |
| **标准版本**   | `gcc -std=c11 main.c`            | `-std=c89`, `-c99`, `-c11`, `-c17`, `-gnu99` | 指定遵循的 C 语言                                            |





***

预处理指令

头文件

C标准库

main函数

注释

# 3.变量、加减乘除，输入输出

- *怎么计算1+1？*

**例程二：格式化输出**

```c
#include <stdio.h>
int main() 
{
    printf("1+1=%d", 1+1);//decimal
    return 0;
}
```

- *有没有更好的方式计算1+1？*

**例程三：加法计算器**

```c
#include <stdio.h>
int main() 
{
    printf("please enter two numbers:\n");
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("The sum of %d and %d is %d\n", a, b, a + b);
    return 0;
}

```



***

变量：数据类型 变量名;  （范围、变量名规则、占用内存大小、格式化输入/输出）

运算符初步

printf、scanf

关键字

表达式

语句

数据类型：int



# 4.更多数据类型，更多运算符，常量

- *小数如何表示？*

**例程四：计算圆的面积**

```c
#include <stdio.h>
#define PI 3.14159
// const PI=3.14159
int main() 
{
    float radius, area;
    printf("Enter the radius of the circle:\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    printf("Area of the circle: %.2f\n", area);
    return 0;
}

```

- *字符如何表示？*

**例程五：grades**

```c
#include <stdio.h>
int main()
{
    char letter;
    printf("Enter the letter:\n");
    scanf("%c",&letter);
    printf("The letter is %c\n",letter);
    char pattern[10] = "circle";
  //char *pattern = "circle";
    printf("%s\n",pattern);
    return 0;
}
```



- *整数乘浮点数会怎么样？*
- *变量与常量的区别？*

***



类型转换

常量

数据类型：float、char



# 5.数组，字符串



- *如何定义数组和使用数组*

**例程六：存储五位同学的成绩并根据需求调用**

```c
#include <stdio.h>
int main()
{
    //注：若定义时不赋值，则必须输入数组大小
    int grade[]={88,89,73,99,91};
    // int grade[5];
    // grade[0]=88;
    // grade[1]=89;
    // grade[2]=73;
    // grade[3]=99;
    // grade[4]=91;
    int n;
    printf("Enter the number of student:");
    scanf("%d",&n);
    printf("The grade of student %d is:%d",n,grade[n-1]);
    return 0;
}

```

- *如何输入字符串？*

**例程七：greet**

```c
#include <stdio.h>
int main() 
{
    printf("What's your name?\n");
    char name[50];
    scanf("%49s", name); // Read a string input safely
    printf("Hello, %s!\n", name);
}
```

- *如何处理字符串？*

**例程八：字符串的长度，拼接，比较**

```c
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "hello";
    char str2[] = "world";
    printf("%d  %d\n",strlen(str1),strlen(str2));

    char result[50];
    strcpy(result,str1);	//将str1复制粘贴到result
    strcat(result,",  ");	//拼接后面的变量到result后
    strcat(result,str2);	//strcat会自动处理\0
    printf("%s\n",result);
    printf("\0%s\n",result);//认识\0的作用

    char str3[] = "apple";
    char str4[] = "banana";
    
    int end = strcmp(str3,str4);	//根据ascii码一个一个比较
    if(end > 0)						//若str3大于str4则返回正数
    {
        printf("%s more than %s\n",str3,str4);
    }
    else if(end < 0)				//若str3小于str4则返回负数
    {
        printf("%s less than %s\n",str3,str4);
    }
    else							//若完全相同则返回0
    {
        printf("%s equal to %s\n",str3,str4);
    }
    return 0;
}
```





数组

字符串输入与输出

字符串基本操作

strcpy

strcat

# 6.函数、分支、调试

- *每次计算面积都要写一遍式子吗？*
- 能不能一个程序既计算圆的面积又计算正方形面积？

**例程九：计算圆的面积和正方形面积**

```c
#include <stdio.h>
int main() 
{
    int flag;
    printf("Enter 1 for circle area, 2 for square area:\n");
    scanf("%d", &flag);
    if (flag == 1)
    {
        float radius, area;
        printf("Enter the radius of the circle:\n");
        scanf("%f", &radius);
        area = 3.14159 * radius * radius;
        printf("Area of the circle: %.2f\n", area);
    }
    else if (flag == 2)
    {
        float side, area;
        printf("Enter the side length of the square:\n");
        scanf("%f", &side);
        area = side * side;
        printf("Area of the square: %.2f\n", area);
    }
    else
    {
        printf("Invalid option.\n");
    }
    return 0;
}
```

- *普通函数能传递参数，main能不能？*

**例程十：更好用的加法计算器**

注：此例程需要在终端运行时同时传入两个整数参数

如：.\test.exe  10  20

```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
    return 0;
} 
```



函数

分支

ASCII

终端运行

# 7.循环

- *如果有好多个图形的面积需要计算，有没有更友好的写法？*

**例程十一：循环计算多个面积**

```c
#include <stdio.h>
int main() 
{
    float radius[10], area[10];
    for(int i = 0; i < 10; i++) 
    {
        printf("Enter the radius of circle %d:\n", i + 1);
        scanf("%f", &radius[i]);
        area[i] = 3.14159 * radius[i] * radius[i];
    }
    for(int i = 0; i < 10; i++) {
        printf("Area of circle %d: %.2f\n", i + 1, area[i]);
    }
    return 0;
}

```

- *如果一开始并不知道我要计算几个面积怎么办？*

**例程十二：自定义计算面积数**

```c
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
float SquareMeasure(int radius)
{
    return PI*radius*radius;
}
int main(int count,char *argv[])
{
    if(count != 2)
    {
        printf("Usage:%s <num>",argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    int radius[num];
    for(int i=num;i>0;i--)	//注意此时i在循环中的变化
    {						//根据i以及使用需求决定下列循环中使用i时
        printf("Enter the radius of circle %d:  ",6-i);
        scanf("%d",&radius[5-i]);
    }
    for(int i=0;i<num;i++)
    {
        printf("Area of the circle %d: %.2f\n",i+1,SquareMeasure(radius[i]));
    }
    return 0;
}
```



数组

循环

函数传参与返回值

动态申请内存

代码规范

# 8.字符串

- *如何输入字符串？*

**例程十三：greet**

```c
#include <stdio.h>
int main() 
{
    printf("What's your name?\n");
    char name[50];
    scanf("%49s", name); // Read a string input safely
    printf("Hello, %s!\n", name);
}
```

- *如何处理字符串？*

**例程十四：字符串的长度，拼接，比较**

```c
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "hello";
    char str2[10] = "world";
    printf("%d  %d\n",strlen(str1),strlen(str2));

    char result[50];
    strcpy(result,str1);	//将str1复制粘贴到result
    strcat(result,",  ");	//拼接后面的变量到result后
    strcat(result,str2);	//strcat会自动处理\0
    printf("%s\n",result);
    printf("\0%s\n",result);//认识\0的作用

    char str3[] = "apple";
    char str4[] = "banana";
    
    int end = strcmp(str3,str4);	//根据ascii码一个一个比较
    if(end > 0)						//若str3大于str4则返回正数
    {
        printf("%s more than %s\n",str3,str4);
    }
    else if(end < 0)				//若str3小于str4则返回负数
    {
        printf("%s less than %s\n",str3,str4);
    }
    else							//若完全相同则返回0
    {
        printf("%s equal to %s\n",str3,str4);
    }
    return 0;
}
```







字符串输入与输出

字符串基本操作

strcpy

strcat

# 9.结构体

- *怎么将不同类型数据集成到一个变量中

**例程十五：储存学生信息并打印**

```c
#include <stdio.h>
typedef struct
{
    char Name[50];
    int Age;
    char Level;
    float Grade;
}StudentInformation;
/*  定义了一个名为StudentInformation的变量类型
    被这个类型定义的变量有四个元素，
    Name[50],Age,Level,Grade
    其中Name[50]和Level是字符变量，
    Age是整型变量，Grade是浮点型变量     */
int main()
{
    StudentInformation str[5];
    //定义了StudentInformation类型的数组
    printf("Enter the information(Name  Age  Level  Grade):\n");
    for(int i=0;i<5;i++)
    {
        //调用结构体变量的规则：
        scanf("%s %d %c %f",
            &str[i].Name,   
            &str[i].Age,
            &str[i].Level,
            &str[i].Grade);//提高代码可读性
    }

    for(int i=0;i<5;i++)
    {
        printf("The information of student %d is:\n",i+1);
        printf("Name:%s    Age:%d    Level:%c    Grade:%.2f\n",
                str[i].Name,
                str[i].Age,
                str[i].Level,
                str[i].Grade);
    }

    return 0;
}
```







结构体

结构体定义

代码规范与可读性

# 10.指针、地址



# 11.数组深入



# 12.指针传参



# 13.函数指针



